//
// FireworksEffect - Free for all use from Davepl
//
// Fireworks Effect for Fourth of July

public class FireworksEffect : LEDEffect
{
	// Each particle in the particle system remembers its color, 
	// birth time, postion, velocity, etc.  If you are not using DateTime,
	// all you need in its place is a fractional number of seconds elapsed, which is
	// all I use it for.  So timer()/1000.0 or whatever should suffice as well.

	public class Particle
	{
		public CRGB _starColor;
		public DateTime _birthTime;
		public DateTime _lastUpdate;
		public double _velocity;
		public double _position;

		public static Random _rand = new Random();

		public Particle(CRGB starColor, double pos, double maxSpeed)
		{
			_position = pos;
			_velocity = _rand.NextDouble() * maxSpeed * 2 - maxSpeed;
			_starColor = starColor;
			_birthTime = DateTime.UtcNow;
			_lastUpdate = DateTime.UtcNow;
		}

		public double Age
		{
			get
			{
				return (DateTime.UtcNow - _birthTime).TotalSeconds;
			}
		}

			// As the particle ages we actively fade its color and slow its speed

				public void Update()
			{
				double deltaTime = (DateTime.UtcNow - _lastUpdate).TotalSeconds;
				_position += _velocity * deltaTime;
				_lastUpdate = DateTime.UtcNow;

				_velocity -= (2 * _velocity * deltaTime);

				_starColor = _starColor.fadeToBlackBy((float)_rand.NextDouble() * 0.1f);
			}
	}

	// A Palette256 is just a way of picking a random color from the rainbow.  
	// If you can provide a random color, you're set... this is just the 
	// easiest mechanism I had handy.

	protected Palette256 _Palette = new Palette256(Palette256.Rainbow);

	protected bool       Blend = true;
	protected double     MaxSpeed = 375.0f;        // Max velocity
	protected double     NewParticleProbability = 0.01f;         // Odds of new particle
	protected double     ParticlePreignitonTime = 0.0f;          // How long to "wink"
	protected double     ParticleIgnition = 0.2f;          // How long to "flash"
	protected double     ParticleHoldTime = 0.00f;         // Main lifecycle time
	protected double     ParticleFadeTime = 2.0f;          // Fade out time
	protected double     ParticleSize = 0.00f;         // Size of the particle

	protected Queue<Particle> _Particles = new Queue<Particle>();   // FIFO particles

	private static Random _random = new Random();

	// All drawing is done in Render, which produces one 
	// frame by calling the draw methods on the supplied
	// graphics interface.  As long as you support "Draw 
	// a pixel" you should be able to make it work with
	// whatever mechanism to plot pixels that you're using...

	protected override void Render(ILEDGraphics graphics)
	{
		// Randomly create some new stars this frame; the number we create is tied 
		// to the size of the display so that the display size can change and 
		// the "effect density" will stay the same

		for (int iPass = 0; iPass < graphics.DotCount / 50; iPass++)
		{
			if (_random.NextDouble() < NewParticleProbability)
			{
				// Pick a random color and location.  
				// If you don't have FastLED palettes, all you need to do
				// here is generate a random color.

				uint iStartPos = (uint)(_random.NextDouble() * graphics.DotCount);
				CRGB color =
					_Palette.ColorFromPalette((byte)_random.Next(0, 255), 1.0f, false);
				int c = _random.Next(10, 50);
				double multiplier = _random.NextDouble() * 3;

				for (int i = 1; i < c; i++)
				{
					Particle particle = new Particle(color, iStartPos, MaxSpeed *
						_random.NextDouble() * multiplier);
					_Particles.Enqueue(particle);
				}
			}
		}

		// In the degenerate case of particles not aging out for some reason, 
		// we need to set a pseudo-realistic upper bound, and the very number of     
		// possible pixels seems like a reasonable one

		while (_Particles.Count > graphics.DotCount)
			_Particles.Dequeue();

		// Start out with an empty canvas

		graphics.FillSolid(CRGB.Black);

		foreach(Particle star in _Particles)
		{
			star.Update();

			CRGB c = new CRGB(star._starColor);

			// If the star is brand new, it flashes white briefly.  
			// Otherwise it just fades over time.

			double fade = 0.0f;
			if (star.Age > ParticlePreignitonTime && star.Age <
				ParticleIgnition + ParticlePreignitonTime)
			{
				c = CRGB.White;
			}
			else
			{
				// Figure out how much to fade and shrink the star based on 
				// its age relative to its lifetime

				double age = star.Age;
				if (age < ParticlePreignitonTime)
					fade = 1.0 - (age / ParticlePreignitonTime);
				else
				{
					age -= ParticlePreignitonTime;

					if (age < ParticleHoldTime + ParticleIgnition)
						fade = 0.0f;                  // Just born
					else if (age > ParticleHoldTime + ParticleIgnition + ParticleFadeTime)
						fade = 1.0f;                  // Black hole, all faded out
					else
					{
						age -= (ParticleHoldTime + ParticleIgnition);
						fade = (age / ParticleFadeTime);  // Fading star
					}
				}
				c = c.fadeToBlackBy((float)fade);
			}
			ParticleSize = (1 - fade) * 5;

			// Because I support antialiasing and partial pixels, this takes a
			// non-integer number of pixels to draw.  But if you just made it
			// plot 'ParticleSize' pixels in int form, you'd be 99% of the way there

			graphics.DrawPixels(star._position, (uint)ParticleSize, c);

		}

		// Remove any particles who have completed their lifespan

		while (_Particles.Count > 0 && _Particles.Peek().Age >
			ParticleHoldTime + ParticleIgnition + ParticleFadeTime)
		{
			_Particles.Dequeue();
		}
	}
}
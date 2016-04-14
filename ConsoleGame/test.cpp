
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

///////////////////////////////
///////////////////////////////

const int   screenSize_X = 640;
const int   screenSize_Y = 480;

///////////////////////////////
///////////////////////////////
// Function to load the image into our texture and sprite so we can draw it
void loadImage(const char* pathname, sf::Texture& texture, sf::Sprite& sprite)
{
	texture.loadFromFile(pathname);     // load it from the file
	sprite.setTexture(texture);         // put that texture in our sprite
	sprite.setTextureRect(sf::IntRect(0, 0, screenSize_X, screenSize_Y));    // the rectangle of the texture to use for this sprite
}

///////////////////////////////
///////////////////////////////
// Normal entry point
void test()
{
	// Create our window
	sf::RenderWindow window(
		sf::VideoMode(screenSize_X, screenSize_Y),       // size of the client area we want
		"Display an Image"                              // The text to appear on the window title
		);

	// load our image
	sf::Texture     texture;        // the texture which will contain our pixel data
	sf::Sprite      sprite;         // the sprite which will actually draw it
	loadImage("image.bmp", texture, sprite);

	// Set FPS so this draws at 60 FPS (note:  I didn't do this for the WinAPI version because it'd be too hard for such
	//  a small example)
	window.setFramerateLimit(60);

	bool program_running = true;        // true until the user wants to quit
	while (program_running)
	{
		// Do the event pump -- same idea as with Windows... look for events and process them
		sf::Event evt;
		while (window.pollEvent(evt))      // while there are any events to process...
		{
			// process them. But we're only interested in the closed event
			if (evt.type == sf::Event::EventType::Closed)        // is this a close event?
				program_running = false;                        // indicate that we want the window to close
		}

		// now that events are processed... draw our image
		window.draw(sprite);        // just draw it to the back buffer
		window.display();           // and display it so the back buffer moves to the front
	}
}
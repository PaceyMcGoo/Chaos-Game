// Include important C++ libraries here
#include <sstream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game", Style::Default);

	Clock clock;
	RectangleShape shape_drawn;
	shape_drawn.setSize(sf::Vector2f(1,1));

	bool paused = true;

	// Draw some text

	Text messageText;


	// We need to choose a font
	Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");

	// Set the font to our message
	messageText.setFont(font);


	// Assign the actual message
	messageText.setString("Click four points");



	messageText.setCharacterSize(50);

	//Choose a color
	messageText.setFillColor(Color::White);


	// Position the text
	FloatRect textRect = messageText.getLocalBounds();
	messageText.setOrigin(textRect.left +
		textRect.width / 2.0f,textRect.top + textRect.height / 2.0f);
	messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

	vector<Vector2f> vectices; /*use pushback*/
	vector<Vector2f> points;
	Vector2f clicked;

	while (window.isOpen())
	{

		Event event;

		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if(event.mouseButton.button == sf::Event::MouseButtonPressed)
			{
				if()
				{	
					cout << "Mouse x: " << event.mouseButton.x << endl;
					cout << "Mouse y: " << event.mouseButton.y << endl;
					clicked.x = event.mouseButton.x;
					clicked.y = event.mouseButton.y;
				}
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		//start the game

		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			//paused = false;

		}

		// Clear everything from the last frame
		window.clear();


		/* Draw the scene*/
		window.draw(messageText);
		shape_drawn.setPosition(0,0);
		window.draw(shape_drawn);

		// Show everything we just drew
		window.display();


	}

	return 0;
}

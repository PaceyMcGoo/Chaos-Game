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

	RectangleShape shape_drawn;
	shape_drawn.setSize(sf::Vector2f(1,1));

	// Text
	Text messageText;
	// Font
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
	messageText.setPosition(1920 / 2.0f, 100 / 2.0f);

	//Vectors
	int vertex = 0;
	vector<Vector2f> vertices; /*use pushback*/
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
			//mouse input
			if(event.type == sf::Event::MouseButtonPressed && points.size() <= 0)
			{
				if(event.mouseButton.button == sf::Mouse::Left)
				{	

					clicked.x = event.mouseButton.x;
					clicked.y = event.mouseButton.y;

					//adds to vertices if it's iterated less than 4 times
					if(vertices.size() < 3)
					{
						vertices.push_back(clicked);

						cout << "Mouse x: " << event.mouseButton.x << endl;
						cout << "Mouse y: " << event.mouseButton.y << endl;

						cout << "SIZE: " << vertices.size() << endl;
					}
					else //adds to points if it's more than 3
					{
						points.push_back(clicked);
						cout << "Points X: " << points.at(0).x << endl<< "Points Y: " << points.at(0).y << endl;
					}
				}
			}
		}

		//close the game
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}


		// Clear everything from the last frame
		window.clear();

		/* Draw the scene*/

		//DRAWS VERTEX
		if(vertices.size() >= 3 && points.size() >= 1)
		{
			for (int counter = 0; counter < vertices.size(); counter++)
			{
				shape_drawn.setPosition(vertices.at(counter).x,vertices.at(counter).y);
				window.draw(shape_drawn);
			}

			//DRAWS POINTS
			for (int counter = 0; counter < points.size(); counter++)
			{
				shape_drawn.setPosition(points.at(counter).x, points.at(counter).y);
				window.draw(shape_drawn);
			}
		}
		else if (vertices.size() >= 0) // DRAWS VERTEX UNTIL IT REACHES THE SIZE OF 3
		{
			for (int counter = 0; counter < vertices.size(); counter++)
			{
				shape_drawn.setPosition(vertices.at(counter).x, vertices.at(counter).y);
				window.draw(shape_drawn);

			}
			window.draw(messageText);
		}


		// Show everything we just drew
		window.display();


	}

	return 0;
}

// Include important C++ libraries here
#include <sstream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


using namespace sf;
using namespace std;

vector<Vector2f> Adds_Points(vector<Vector2f>, vector<Vector2f>);

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
			//adds midpoint to points
			points = Adds_Points(vertices, points);
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

vector<Vector2f> Adds_Points(vector<Vector2f>vertices, vector<Vector2f>points)
{
	vector <Vector2f> new_vertices = vertices;
	vector <Vector2f> new_points = points;
	Vector2f mid_Point;
	int counter = 0;

	do {

		//makes seed
		srand((int)time(0));
		int rand_vertice = (rand() % 3);
		int rand_point = (rand() % (new_points.size()));

		//Picks intial points from vectors
		Vector2f picked_point = new_points.at(rand_point);
		Vector2f picked_vertice = new_vertices.at(rand_vertice);

		//Picks mid point
		mid_Point.x = (picked_point.x + picked_vertice.x) / 2.0;
		mid_Point.y = (picked_point.y + picked_vertice.y) / 2.0;

		if (find(new_points.begin(), new_points.end(), mid_Point) == new_points.end())
		{
			counter++;
			new_points.push_back(mid_Point);
		}
	} while (counter == 10);
	
	return new_points;
}

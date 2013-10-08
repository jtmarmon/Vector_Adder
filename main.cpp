#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "vector.h"
#include <SFML\Window\Mouse.hpp>
#define xMax 800
#define yMax 600
#define xMid 400
#define yMid 300
#define vectorWidth 2
#define vectorScaler 6
#define vectorDisplacement 1
typedef sf::Color COLOR;
typedef sf::RectangleShape LINE;
struct point
{
	float x;
	float y;
};
void loadMenu()
{
	std::cout << "bitchezZ" << std::endl;
};
int main()
{
	Vector::numVectors = 0;
	Vector::degreeMode = true;
	Vector BLANKVECTOR;
	Vector a(22,45);
	a.setLine(createLine(a), BLANKVECTOR);
	Vector b(34, 60);
	b.setLine(createLine(b,a),a);
	Vector c = a+b;
	c.setLine(createLine(c), BLANKVECTOR);


	sf::Vector2i toggleLocation(200,50);
	sf::RectangleShape toggle((sf::Vector2f)toggleLocation);
	toggle.setFillColor(sf::Color::Yellow);
	sf::RenderWindow window(sf::VideoMode(xMax, yMax), "FUNSICZ");
	sf::Font font;
	if (!font.loadFromFile("tnr.ttf"))
		return EXIT_FAILURE;
	sf::Mouse mouse;
	// Start the `main loop
	bool toggleComponents = false;
	int i=0;
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::Closed)
				window.close();
			if(event.type==event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && V2i_inRange(sf::Mouse::getPosition(window), toggleLocation, 200, 50))
			{
				i++;
				std::cout << "dicks  " << i <<std::endl;
				if(toggleComponents)
					toggleComponents = false;
				else
					toggleComponents = true;
			}
			if(event.type==event.KeyReleased && event.key.code == sf::Keyboard::Escape)
				loadMenu();
		}
		// Clear screen
		window.clear();
		
		
		if(toggleComponents)
		{
			
			window.draw(a.getCXL());
			window.draw(a.getCYL());
			window.draw(b.getCXL());
			window.draw(b.getCYL());
			window.draw(c.getCXL());
			window.draw(c.getCYL());
		}
		window.draw(a.getLine());
		window.draw(b.getLine());
		window.draw(c.getLine());
		window.draw(toggle);
	
		// Draw the string
		//window.draw(text);
		
		//window.draw(b_line);
		// Update the window
		window.display();
	}

return EXIT_SUCCESS;
}

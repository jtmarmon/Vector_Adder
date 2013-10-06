#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "vector.h"
#include <SFML\Window\Mouse.hpp>
#define xMax 800
#define yMax 600
#define xMid 400
#define yMid 300
#define vectorWidth 3
#define vectorScaler 6
typedef sf::Color COLOR;
typedef sf::RectangleShape LINE;
struct point
{
	float x;
	float y;
};

int main()
{
	Vector::degreeMode = true;
	Vector BLANKVECTOR;
	Vector a(22,12);
	Vector b(34, 60);
	Vector c = a+b;
	c.setLine(createLine(c), BLANKVECTOR);
	a.setLine(createLine(a), BLANKVECTOR);
	b.setLine(createLine(b,a),a);


	sf::Vector2i toggleLocation(50,50);
	sf::RectangleShape toggle((sf::Vector2f)toggleLocation);
	toggle.setFillColor(sf::Color::Cyan);
	sf::RenderWindow window(sf::VideoMode(xMax, yMax), "SFML window");
	sf::Font font;
	if (!font.loadFromFile("tnr.ttf"))
		return EXIT_FAILURE;
	sf::Text text("Welcome to \"Head Douche-Dickwad's\" vector addition program", font, 30);
	sf::Mouse mouse;
	// Start the `main loop
	bool toggleComponents = false;
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::Closed)
			window.close();
		}
		// Clear screen
		window.clear();
		window.pollEvent(event);
		if(event.type==event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && V2i_inRange(sf::Mouse::getPosition(window), toggleLocation, 50, 50))
		{
			if(toggleComponents)
				toggleComponents = false;
			else
				toggleComponents = true;
		}
		if(toggleComponents)
		{
			std::cout << "dicks"<<std::endl;
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
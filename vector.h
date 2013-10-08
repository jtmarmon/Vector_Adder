#include <cstdlib>
#include <SFML\Graphics.hpp>
typedef sf::RectangleShape LINE;
typedef sf::Color COLOR;

class Vector
{

	float magnitude;
	float angle;
	float Cx; //x-component vector
	float Cy;//y-componeny vector
	LINE line;
	LINE cxl;
	LINE cyl;
public:
	static bool degreeMode; 
	static int numVectors;
//	static void setDegreeMode(bool);
	//static bool getDegreeMode();
	Vector();
	Vector(float m,float a);

	LINE getLine();
	void setLine(LINE, Vector);
	void setLineColor(COLOR);
	void setCXL(LINE);
	void setCYL(LINE);
	LINE getCXL();
	LINE getCYL();
	float getMagnitude();
	void setMagnitude(float);

	float getAngle(); //angles are either positive or negative north of east 
	void setAngle(float);

	float getCX();
	void setCX(float);

	float getCY();
	void setCY(float);

	void draw();
	Vector operator+(Vector &rhs);
	//Vector operator-(Vector &rhs);
	void operator=(Vector&rhs);

	Vector getCXV();
	Vector getCYV();
	LINE getCXVL(); // component x vector line
	LINE getCYVL(); //component y vector line
};
LINE createLine(Vector &v);
LINE createLine(Vector &v, float absX, float absY);
LINE createLine(Vector &v, Vector& lastVector);
bool V2i_inRange(sf::Vector2i, sf::Vector2i,  int xRange, int yRange);
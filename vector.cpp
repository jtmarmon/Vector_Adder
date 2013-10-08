#include <iostream>
#include "vector.h"
#include <math.h>
#include <SFML\Graphics.hpp>
typedef sf::Color COLOR;
typedef sf::RectangleShape LINE;
#define PI 3.14159265
#define xMax 800
#define yMax 600
#define xMid 400
#define yMid 300
#define vectorWidth 2
#define vectorScaler 6
#define vectorDisplacement 1
//*************SET/GET FUNCTIONS**************
float Vector::getMagnitude()
{
	return magnitude;
};
void Vector::setMagnitude(float in)
{
	magnitude=in;
};
LINE Vector::getLine()
{
	return line;
};
void Vector::setLine(LINE lineIn, Vector LV /*last vector */)
{
	line = lineIn;


	cxl = LINE(sf::Vector2f(vectorWidth, vectorScaler*this->getCX()));
	cxl.setPosition(xMid+vectorScaler*LV.getCX(), yMid-vectorScaler*LV.getCY()+(vectorDisplacement*numVectors));
	cxl.rotate(270);
	cxl.setFillColor(sf::Color::Red);

	
	cyl = LINE(sf::Vector2f(vectorWidth, vectorScaler*this->getCY()));
	cyl.setPosition(xMid+vectorScaler*(this->getCX()+LV.getCX()) + (vectorDisplacement*numVectors), yMid-vectorScaler*LV.getCY());
	cyl.rotate(180);
	cyl.setFillColor(sf::Color::Red);

	std::cout << numVectors << std::endl;
};
void Vector::setLineColor(COLOR cIn)
{
	line.setFillColor(cIn);
};

float Vector::getAngle() //angles are either positive or negative north of east 
{
	return angle;
}
void Vector::setAngle(float in)
{
	angle=in;
};


float Vector::getCX()
{
	return Cx;
};
void Vector::setCX(float in)
{
	Cx=in;
};


float Vector::getCY()
{
	return Cy;
};
void Vector::setCY(float in)
{
	Cy=in;
};

Vector Vector::getCXV()//component x vector
{
	float temp = this->getCX();
	return Vector(temp, 0);
};

Vector Vector::getCYV() //component y vector 
{
	float temp = this->getCY();
	return Vector(temp, 90);
};
void Vector::setCXL(LINE lineIn) // component x vector line
{
	
};
void Vector::setCYL(LINE lineIn) //component y vector line
{
};
LINE Vector::getCXL()
{
	return cxl;
};
LINE Vector::getCYL()
{
	return cyl;
};
//*************MISCELLANEOUS************
bool Vector::degreeMode;
int Vector::numVectors;
//*************CONSTRUCTORS***************
Vector::Vector():magnitude(0),angle(0),Cx(0),Cy(0){ };
Vector::Vector(float m,float a):magnitude(m),angle(a)
{
	numVectors++;
	//initialize components
	if(Vector::degreeMode)
	{
		Cy = m*sin(PI*a/180);
		Cx = Cy/tan(PI*a/180);
	}
	else
	{
		Cy = m*sin(a);
		Cx = Cy/tan(a);
	}

};
//*******************OVERLOADED OPERATORS**************
Vector Vector::operator+(Vector &rhs)
{
	float RCX/* resultant x-component*/ = this->getCX()+rhs.getCX();
	
	float RCY/*resultant y-component*/ = this->getCY() + rhs.getCY();	
	float rMag = sqrt(RCX*RCX + RCY*RCY);//resultant magnitude equals square root of magnitude1^2 + magnitude2^2
	using namespace std;
	float rAng;
	if(Vector::degreeMode)
		rAng = atan(RCY/RCX)*180/PI;
	else
		rAng = atan(RCY/RCX);
	return Vector(rMag,rAng);
};
void Vector::operator=(Vector &rhs)
{
	this->setMagnitude(rhs.getMagnitude());
	this->setAngle(rhs.getAngle());
};
LINE createLine(Vector &v)
{
	LINE line(sf::Vector2f(vectorWidth, v.getMagnitude()*vectorScaler));
	line.setPosition(xMid,yMid); //TODO: fix positioning in function
	line.rotate(270-v.getAngle());
	return line;
};
LINE createLine(Vector &v, float absX, float absY)
{
	LINE line(sf::Vector2f(vectorWidth, v.getMagnitude()*vectorScaler));
	line.setPosition(absX,absY); //TODO: fix positioning in function
	line.rotate(270-v.getAngle());
	return line;
};
LINE createLine(Vector &v, Vector& lastVector /*vector being used as a starting point*/)
{
	LINE line(sf::Vector2f(vectorWidth, v.getMagnitude()*vectorScaler));
	line.setPosition(xMid+vectorScaler*lastVector.getCX(),yMid-vectorScaler*lastVector.getCY()); //TODO: fix positioning in function
	line.rotate(270-v.getAngle());
	return line;
};
bool V2i_inRange(sf::Vector2i a, sf::Vector2i b,  int xRange, int yRange)
{
	if(b.x<=a.x || b.y <=a.y)
		return false;
	else if(b.x-xRange <=a.x && b.y-yRange<=a.y)
		return true;
	else
		return false;
};
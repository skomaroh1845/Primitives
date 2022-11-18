#include "DrawingObject.h"
#include <glut.h>
 
// T = Vector2D

class rectangle :public DrawingObject {
protected:
	double sideSizeX, sideSizeY;
	T topLeft, topRight, bottomLeft, bottomRight;
	T top, left, right, bottom;
public:
	rectangle();  // init a square with the center in (0, 0) and 1 length side  
	rectangle(const T& center, double sideSizeX, double sideSizeY, float red = 1, float green = 1, float blue = 1);
	rectangle(const rectangle& P);

	void changeSize(double sideSizeX, double sideSizeY);
	void rotate(double angle) override;
	void moveBy(double x, double y) override;
	void moveTo(double x, double y) override;
	void print() const override;
};

class line :public DrawingObject { // vectors point the begin and the end of line
protected:
	T end1, end2; // ends of line
	float width;
public:
	line();
	line(const T& v1, const T& v2, float width = 1, float red = 1, float green = 1, float blue = 1);
	line(const line& L);

	void rotate(double angle) override;  // turn around end1
	void moveBy(double x, double y) override;
	void moveTo(double x, double y) override;  // move end1 to this coordinates
	void print() const override;
};

class triangle:public DrawingObject {
private:
	T v1, v2, v3;  // vertices of triangle
protected:
	double l12, l23, l31;  // lenght of sides
public:
	triangle();
	triangle(const T& v1, const T& v2, const T& v3, float red = 1, float green = 1, float blue = 1);
	triangle(const T& center, double size = 1, float red = 1, float green = 1, float blue = 1);  // equilateral triangle, size is a distance between center and vertex
	triangle(const triangle& Tr);

	void changeSizeAlongAxis(double sizeX, double sizeY);  // 0 if don't want to scale along this axis
	void rotate(double angle) override;
	void moveBy(double x, double y) override;
	void moveTo(double x, double y) override;
	void print() const override;

private:
	double max_minus_min(double a, double b, double c) const {
		using std::max, std::min;
		return max(a, max(b, c) ) - min( a, min(b, c) );
	}
};

class circle:public DrawingObject {
private:
	bool isFull;
	double angle1 = 0, angle2 = 0;
protected:
	double R;
public:
	circle(); 
	circle(const T& center, float R = 1, float red = 1, float green = 1, float blue = 1);
	circle(const circle& C);

	void changeR(double R);
	void rotate(double angle) override;
	void moveBy(double x, double y) override;
	void moveTo(double x, double y) override;
	void setSector(double angle1, double angle2);
	void print() const override;
	void print(double angle, double angle2 = 0) const;
};

class leaf:public DrawingObject {
private:
	double angle = 0;
protected:
	double size;
public:
	leaf();
	leaf(const T& v, double size = 1, float red = 1, float green = 1, float blue = 1);
	leaf(const leaf& F);

	void rotate(double angle) override;
	void moveBy(double x, double y) override;
	void moveTo(double x, double y) override;
	void print() const override;
}; 
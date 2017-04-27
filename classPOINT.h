#include <cstdio>
#include <iostream>

using namespace std;

class Point
{
private:
	int x,
		y,
		z;
public:
	Point(){x=y=z=0;};
	Point (int x1, int y1, int z1);
	Point & operator = (const Point & b);
	Point operator + (const Point & b);
	friend ostream& operator << (ostream& os, const Point & b);	
};


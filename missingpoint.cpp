// C++ program to find missing point of a 
// parallelogram 
#include <bits/stdc++.h> 
using namespace std; 

// struct to represent a co-ordinate point 
struct Point { 
	float x, y; 
	Point() 
	{ 
		x = y = 0; 
	} 
	Point(float a, float b) 
	{ 
		x = a, y = b; 
	} 
}; 

// given a source point, slope(m) of line 
// passing through it this function calculates 
// and return two points at a distance l away 
// from the source 
pair<Point, Point> findPoints(Point source, 
							float m, float l) 
{ 
	Point a, b; 

	// slope is 0 
	if (m == 0) { 
		a.x = source.x + l; 
		a.y = source.y; 

		b.x = source.x - l; 
		b.y = source.y; 
	} 

	// slope if infinity 
	else if (m == std::numeric_limits<float>::max()) { 
		a.x = source.x; 
		a.y = source.y + l; 

		b.x = source.x; 
		b.y = source.y - l; 
	} 

	// normal case 
	else { 
		float dx = (l / sqrt(1 + (m * m))); 
		float dy = m * dx; 
		a.x = source.x + dx, a.y = source.y + dy; 
		b.x = source.x - dx, b.y = source.y - dy; 
	} 

	return pair<Point, Point>(a, b); 
} 

// given two points, this function calculates 
// the slope of the line/ passing through the 
// points 
float findSlope(Point p, Point q) 
{ 
	if (p.y == q.y) 
		return 0; 
	if (p.x == q.x) 
		return std::numeric_limits<float>::max(); 
	return (q.y - p.y) / (q.x - p.x); 
} 

// calculates the distance between two points 
float findDistance(Point p, Point q) 
{ 
	return sqrt(pow((q.x - p.x), 2) + pow((q.y - p.y), 2)); 
} 

// given three points, it prints a point such 
// that a parallelogram is formed 
void findMissingPoint(Point a, Point b, Point c) 
{ 
	// calculate points originating from a 
	pair<Point, Point> d = findPoints(a, findSlope(b, c), 
									findDistance(b, c)); 

	// now check which of the two points satisfy 
	// the conditions 
	if (findDistance(d.first, c) == findDistance(a, b)) 
		cout << d.first.x << ", " << d.first.y << endl; 
	else
		cout << d.second.x << ", " << d.second.y << endl; 
} 

// Driver code 
int main() 
{ 
	findMissingPoint(Point(1, 0), Point(1, 1), Point(0, 1)); 
	findMissingPoint(Point(5, 0), Point(1, 1), Point(2, 5)); 
	return 0; 
} 

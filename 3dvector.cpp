#include <iostream>
#include <vector>
#include <cmath>

class vector3d {

	public:
		double x, y, z;

		vector3d();
		vector3d(double a, double b, double c);
		vector3d(const vector3d& v);

		vector3d operator +(vector3d v);
		vector3d operator -(vector3d v);
		vector3d operator *(double s);
		vector3d operator /(double s);
		vector3d operator =(vector3d v);

		vector3d dot(vector3d v);
		vector3d cross(vector3d v);

		double magnitude();
		void normalize();
		void display();
	
};


vector3d::vector3d() : x(0.0), y(0.0), z(0.0) {}
vector3d::vector3d(double a, double b, double c) : x(a), y(b), z(c) {}
vector3d::vector3d(const vector3d& v) : x(v.x), y(v.y), z(v.z) {}

vector3d vector3d::operator + (vector3d v) {
	return vector3d(x + v.x, y + v.y, z + v.z);
}

vector3d vector3d::operator - (vector3d v) {
	return vector3d(x - v.x, y - v.y, z - v.z);
}

vector3d vector3d::operator * (double s) {
	return vector3d(s * x, s * y, s * z);
}

vector3d vector3d::operator / (double s) {
	return vector3d(x / s, y / s, z / s);
}

vector3d vector3d::dot(vector3d v) {
	
	return vector3d(x * v.x , y * v.y, z * v.z);
}

vector3d vector3d::cross(vector3d v) {
	return vector3d((y * v.z - z * v.y), (z * v.x - x * v.z), (x * v.y - y * v.x));
} 

double vector3d::magnitude() {
	return std::sqrt(x * x + y * y + z * z);
}

void vector3d::normalize() {
	x = x / magnitude();
	y = y / magnitude();
	z = z / magnitude();
}

void vector3d::display() {
	std::cout << x << ", " << y << ", " << z << std::endl; 
}

int main() {

	vector3d v1(1, 2, 3);
	vector3d v2(2.5, 5, 9);
	vector3d v3(v1);
	
	v2.display();
	v3.display();
	
	vector3d v4 = v2;

	vector3d cross = v1.cross(v2);
	vector3d dot = v1.dot(v2);

	dot.display();
	cross.display();
}

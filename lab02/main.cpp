#include <iostream>
#include <locale>
#include <memory>
#include "task.h"
#include "t-container.h"
#include "shapes.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	// cout << LAB_TASK << endl;
	Shape* circle = new Circle(3);
	Shape* parallelogram = new Parallelogram(3, 5, M_PI/2);
	Shape* trapezium = new Trapezoid(3, 5, 4, 6);
	Shape* newCircle = new Circle(4);
	Container<Shape> cont;

	cout << parallelogram->getPerimeter() << endl;
	
	
	cont.push(circle);
	cont.push(parallelogram);
	cont.push(trapezium);
	cout << "Pushed 3 shapes into container" << endl;

	cout << "Container size: " << cont.size() << endl;

	cout << "0 index element area using get(): " << cont.get(0)->getArea() << endl;

	cont.insert(newCircle, 1);
	cout << "New circle inserted after index 1, area of it: " << cont.get(2)->getArea() << endl;
	cout << "Size of container: " << cont.size() << endl;

	Shape* removedShape = cont.remove(2);
	cout << "Removed element at index 2 (new circle), are of it: " << removedShape->getArea() << endl;
	cout << "Size of container: " << cont.size() << endl;

	cout << "Last element perimeter: " << cont[cont.size() - 1]->getPerimeter() << endl;
	Shape* poppedShape = cont.pop();
	cout << "Shape popped from container, perimeter of it: " << poppedShape->getPerimeter() << endl;
	cout << "Size of container: " << cont.size() << endl;

	return 0;
}
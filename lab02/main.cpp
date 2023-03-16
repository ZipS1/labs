#include <iostream>
#include <locale>
#include "task.h"
#include "t-container.h"
#include "shapes.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	// cout << LAB_TASK << endl;
	Shape* circle = new Circle(3);
	
	Container<Shape> cont;

	return 0;
}
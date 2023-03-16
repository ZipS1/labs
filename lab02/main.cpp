#include <iostream>
#include <locale>
#include <memory>
#include "menu.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << LAB_TASK << endl;

	Container<Shape> cont;
	int choice = runMenu(cont);
	while (choice != Exit)
		choice = runMenu(cont);
	


	return 0;
}
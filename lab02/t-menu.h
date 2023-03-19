#pragma once
#include <string>
#include <iostream>
#include "t-container.h"
#include "shapes.h"

using namespace std;

#pragma region Texts
const string LAB_TASK = "Общие требования : в начале программы вывести задание;\n\
в процессе работы выводить подсказки пользователю\n\
(что ему нужно ввести, чтобы продолжить выполнение программы).\n\
После работы программы вся динамически выделенная память должна быть освобождена.\n\
Класс коллекция должна иметь методы для изменения количества хранимых объектов :\n\
добавление в конец, вставка, усечение, удаление из середины.\n\
При обращении к элементам с несуществующим индексом или\n\
при некорректном изменении количества должно выбрасываться исключение.\n\
Взаимодействие с пользователем организовать в виде простого меню,\n\
обеспечивающего возможность переопределения исходных данных и завершение работы программы.\n\
15. Написать программу, в которой описана иерархия классов : геометрические фигуры\n\
(круг, параллелепипед, трапеция).Описать шаблонный класс для хранения массива\n\
указателей на объекты произвольного класса, в шаблонном классе перегрузить операцию «[]».\n\
Продемонстрировать работу операторов и использование шаблонного класса с различными классами.\n";

const string MENU_ITEMS = "1 - Добавить...\n\
2 - Выбрать...\n\
3 - Удалить...\n\
4 - Выход\n";

const string FIGURE_ITEMS = "1 - Круг\n\
2 - Параллелограм\n\
3 - Трапеция\n";

const string UPDATE_ITEMS = "1 - по индексу\n\
2 - в конец\n";
#pragma endregion

enum MainMenuItem { Add = 1, Select, Remove, Exit, TopMMItem };
enum FigureItem { CircleItem = 1, ParallelogramItem, TrapezoidItem, TopFigureItem };
enum ContainerUpdateItem { AtIndex = 1, AtEnd, TopUpdateItem };

int getUserChoiceOf(const string text, int itemsAmount)
{
	int choice = -1;
	
	while (choice < 1 || choice > itemsAmount)
	{
		cout << text << "Выбор - ";
		cin >> choice;
		cout << endl;
	}
	
	return choice;
}

size_t getUserIndex(size_t size = SIZE_MAX)
{
	int index = -1;
	while (index < 0 || index >= size)
	{
		cout << "Введите индекс: ";
		cin >> index;
		cout << endl;
	}
	
	return index;
}

Shape* getUserShape()
{
	Shape* shape = nullptr;
	int figureChoice = getUserChoiceOf(FIGURE_ITEMS, TopFigureItem - 1);
	switch (figureChoice)
	{
	case CircleItem:
		cout << "Введите радиус: ";
		double radius;
		cin >> radius;
		shape = new Circle(radius);
		break;
	case ParallelogramItem:
		cout << "Введите основание, высоту и угол: ";
		double base, height, angle;
		cin >> base >> height >> angle;
		shape = new Parallelogram(base, height, angle);
		break;
	case TrapezoidItem:
		cout << "Введите нижнее, верхнее основания, правую и левую стороны: ";
		double botbase, topbase, right, left;
		cin >> botbase >> topbase >> right >> left;
		shape = new Trapezoid(topbase, botbase, right, left);
		break;
	}

	return shape;
}

template <typename T>
void runAddMenu(Container<T>& cont)
{
	T inp;
	cout << "Введите новый элемент: ";
	cin >> inp;
	T* item = &inp;
	cout << "Добавить..." << endl;
	int choice = getUserChoiceOf(UPDATE_ITEMS, TopUpdateItem - 1);
	switch (choice)
	{
	case AtIndex:
		cont.insert(item, getUserIndex());
		break;
	case AtEnd:
		cont.push(item);
		break;
	}
}

void runAddMenu(Container<Shape>& cont)
{
	Shape* shape = getUserShape();
	cout << "Добавить..." << endl;
	int choice = getUserChoiceOf(UPDATE_ITEMS, TopUpdateItem - 1);
	switch (choice)
	{
	case AtIndex:
		cont.insert(shape, getUserIndex());
		break;
	case AtEnd:
		cont.push(shape);
		break;
	}
}

template <typename T>
void runSelectionMenu(Container<T>& cont)
{
	cout << "Выбрать...";
	size_t index = getUserIndex(cont.size());
	cout << "Элемент" << cont[index] << endl;
}

void runSelectionMenu(Container<Shape>& cont)
{
	cout << "Выбрать..." << endl;
	size_t index = getUserIndex(cont.size());
	cout << "Площадь: " << cont[index]->getArea() << endl;
	cout << "Периметр: " << cont[index]->getPerimeter() << endl;
	cout << endl;
}

template <class T>
void runRemoveMenu(Container<T>& cont)
{
	cout << "Удалить..." << endl;
	int choice = getUserChoiceOf(UPDATE_ITEMS, TopUpdateItem - 1);
	switch (choice)
	{
	case AtIndex:
		cont.remove(getUserIndex());
		break;
	case AtEnd:
		cont.pop();
		break;
	}
}

template <class T>
int runMenu(Container<T>& cont)
{
	cout << "Текущий размер контейнера: " << cont.size() << endl;
	int choice = getUserChoiceOf(MENU_ITEMS, TopMMItem - 1);

	switch (choice)
	{
	case Add:
		runAddMenu(cont);
		break;
	case Select:
		runSelectionMenu(cont);
		break;
	case Remove:
		runRemoveMenu(cont);
		break;
	case Exit:
		break;
	}

	return choice;
}
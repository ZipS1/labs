#pragma once
#include <string>
#include <iostream>
#include "t-container.h"
#include "shapes.h"

using namespace std;

#pragma region Texts
const string LAB_TASK = "����� ���������� : � ������ ��������� ������� �������;\n\
� �������� ������ �������� ��������� ������������\n\
(��� ��� ����� ������, ����� ���������� ���������� ���������).\n\
����� ������ ��������� ��� ����������� ���������� ������ ������ ���� �����������.\n\
����� ��������� ������ ����� ������ ��� ��������� ���������� �������� �������� :\n\
���������� � �����, �������, ��������, �������� �� ��������.\n\
��� ��������� � ��������� � �������������� �������� ���\n\
��� ������������ ��������� ���������� ������ ������������� ����������.\n\
�������������� � ������������� ������������ � ���� �������� ����,\n\
��������������� ����������� ��������������� �������� ������ � ���������� ������ ���������.\n\
15. �������� ���������, � ������� ������� �������� ������� : �������������� ������\n\
(����, ��������������, ��������).������� ��������� ����� ��� �������� �������\n\
���������� �� ������� ������������� ������, � ��������� ������ ����������� �������� �[]�.\n\
������������������ ������ ���������� � ������������� ���������� ������ � ���������� ��������.\n";

const string MENU_ITEMS = "1 - ��������...\n\
2 - �������...\n\
3 - �������...\n\
4 - �����\n";

const string FIGURE_ITEMS = "1 - ����\n\
2 - �������������\n\
3 - ��������\n";

const string UPDATE_ITEMS = "1 - �� �������\n\
2 - � �����\n";
#pragma endregion

enum MainMenuItem { Add = 1, Select, Remove, Exit, TopMMItem };
enum FigureItem { CircleItem = 1, ParallelogramItem, TrapezoidItem, TopFigureItem };
enum ContainerUpdateItem { AtIndex = 1, AtEnd, TopUpdateItem };

int getUserChoiceOf(const string text, int itemsAmount)
{
	int choice = -1;
	
	while (choice < 1 || choice > itemsAmount)
	{
		cout << text << "����� - ";
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
		cout << "������� ������: ";
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
		cout << "������� ������: ";
		double radius;
		cin >> radius;
		shape = new Circle(radius);
		break;
	case ParallelogramItem:
		cout << "������� ���������, ������ � ����: ";
		double base, height, angle;
		cin >> base >> height >> angle;
		shape = new Parallelogram(base, height, angle);
		break;
	case TrapezoidItem:
		cout << "������� ������, ������� ���������, ������ � ����� �������: ";
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
	cout << "������� ����� �������: ";
	cin >> inp;
	T* item = &inp;
	cout << "��������..." << endl;
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
	cout << "��������..." << endl;
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
	cout << "�������...";
	size_t index = getUserIndex(cont.size());
	cout << "�������" << cont[index] << endl;
}

void runSelectionMenu(Container<Shape>& cont)
{
	cout << "�������..." << endl;
	size_t index = getUserIndex(cont.size());
	cout << "�������: " << cont[index]->getArea() << endl;
	cout << "��������: " << cont[index]->getPerimeter() << endl;
	cout << endl;
}

template <class T>
void runRemoveMenu(Container<T>& cont)
{
	cout << "�������..." << endl;
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
	cout << "������� ������ ����������: " << cont.size() << endl;
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
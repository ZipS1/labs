#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include "ticket.h"

using namespace std;


const vector<string> MENU_ITEMS = { "Add...", "Remove...", "Select by flight num and date...", "Select all...", "Exit..." };

enum { Add = 1, Remove, SelectSpec, SelectAll, Exit };

void outputItems(const vector<string> items)
{
	for (size_t i = 1; i <= items.size(); i++)
		cout << i << " - " << items[i - 1] << endl;
}

int getUserChoiceOf(vector<string> items)
{
	int choice = -1;

	while (choice < 1 || choice > items.size())
	{
		outputItems(items);
		cout << "Choice - ";
		cin >> choice;
		cout << endl;
	}

	return choice;
}

void runAddMenu(stack<Ticket>& cont)
{
	Ticket newTicket;

	cout << "Enter destination: ";
	string destination;
	cin >> destination;
	newTicket.destination = destination;

	cout << "Enter flight number: ";
	string flightNumber;
	cin >> flightNumber;
	newTicket.flightNumber = flightNumber;

	cout << "Enter passenger name: ";
	string name;
	cin >> name;
	newTicket.passengerName = name;

	cout << "Enter flight date: ";
	string date;
	cin >> date;
	newTicket.date = date;

	cout << endl;

	cont.push(newTicket);
}

void outputTicket(Ticket ticket)
{
	cout << "Destination: ";
	cout << ticket.destination << endl;

	cout << "Flight number: ";
	cout << ticket.flightNumber << endl;

	cout << "Passenger name: ";
	cout << ticket.passengerName << endl;

	cout << "Flight date: ";
	cout << ticket.date << endl;
	
	cout << endl;
}

void RunSelectionMenu(stack<Ticket> cont)
{
	cout << "Enter flight number: ";
	string flightNumber;
	cin >> flightNumber;

	cout << "Enter flight date: ";
	string date;
	cin >> date;

	cout << endl;

	for (size_t i = 0; i < cont.size(); i++)
	{
		Ticket ticket = cont.top();
		cont.pop();
		if (ticket.flightNumber == flightNumber && ticket.date == date)
			outputTicket(ticket);
	}
}

void selectAll(stack<Ticket> cont)
{
	for (size_t i = 0; i < cont.size(); i++)
	{
		Ticket ticket = cont.top();
		cont.pop();
		outputTicket(ticket);
	}
	 
	cout << endl;
}

int runMenu(stack<Ticket> &cont)
{
	int choice = getUserChoiceOf(MENU_ITEMS);

	switch (choice)
	{
	case Add:
		runAddMenu(cont);
		break;
	case Remove:
		cont.pop();
		break;
	case SelectSpec:
		RunSelectionMenu(cont);
		break;
	case SelectAll:
		selectAll(cont);
		break;
	case Exit:
		break;
	}

	return choice;
}
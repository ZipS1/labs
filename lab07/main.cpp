#include "menu.h"

using namespace std;

int main()
{
	stack<Ticket> cont;
	int choice = runMenu(cont);
	while (choice != Exit)
		choice = runMenu(cont);
}
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include<deque>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<ctime>
#include"donor.h"
#include"recipient.h"
using namespace std;

int main()
{
	donor d;
	recipient r;
	char choice;
	char option;
	bool yes = false;
	cout << "\n\n                                                    **************** WELCOME TO THE BLOOD BANK *********************\n\n\n";
	while (!yes)
	{
		cout << "press 1 if U R a Donor , 2 if U R a recipient\n";
		cin >> choice;
		switch (choice)
		{
		case '1':

			cout << "\npress 1 to regester , 2 to login\n";
			cin >> option;
			if (option == '1')
			{
				d.clear();
				d.donorRegester();
				d.saveDonor();
			}
			else if (option == '2')
			{
				yes = d.login();
				d.clear();
			}
			else
				cout << "sorry , invalid choice\n";
			break;

		case '2':
			
			cout << "\npress 1 to regester , 2 to login\n";
			cin >> option;
			if (option == '1')
			{
				r.clear();
				r.recipientRegester();
				r.saveRecipient();
			}
			else if (option == '2')
			{
				yes = r.login();
				r.clear();
			}
			else
				cout << "sorry , invalid choice\n";
			break;

		default:
			cout << "sorry , invalid choice\n";
			break;
		}
	}

	char operation;

	switch (choice)
	{
	case '1':
		cout << "\nchoose your operation\n\n1.donation\n2.update your data\n3.delete account\n4.exit\n";
		cin >> operation;
		while (true)
		{
			if (operation == '1')
			{
				d.donation();
			}
			else if (operation == '2')
			{
				d.update();
			}
			else if (operation == '3')
			{
				d.deleteacc();
				d.saveAndClose();
				break;
			}
			else if (operation == '4')
			{
				d.saveAndClose();
				break;
			}
			else
				cout << "invalid operation\n";
			cout << "\nchoose your operation\n\n1.donation\n2.update your data\n3.delete account\n4.exit\n";
			cin >> operation;
		}
		break;

	case '2':
		cout << "\nchoose your operation\n\n1.update your data\n2.search for a blood type\n3.all blood data\n4.request blood\n5.delete account\n6.exit\n";
		cin >> operation;
		while (true)
		{
			if (operation == '1')
			{
				r.update();
			}
			else if (operation == '2')
			{
				r.search();
			}
			else if (operation == '3')
			{
				r.displayBloodData();
			}
			else if (operation == '4')
			{
				r.reqestBlood();
			}
			else if (operation == '5')
			{
				r.deleteacc();
				r.saveAndClose();
				break;
			}
			else if (operation == '6')
			{
				r.saveAndClose();
				break;
			}
			else
				cout << "invalid operation\n";
			cout << "\nchoose your operation\n\n1.update your data\n2.search for a blood type\n3.all blood data\n4.request blood\n5.delete account\n6.exit\n";
			cin >> operation;
		}
		break;

	default:
		cout << "sorry , invalid choice\n";
		break;
	}
	cout << "thanks for visiting us :)";
	return 0;
}
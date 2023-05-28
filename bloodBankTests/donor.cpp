#include "Donor.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<set>
#include<deque>
#include<map>
#include<ctime>
using namespace std;

donor d;

donor::donor()
{
	ifstream getDonors("donors.txt");
	if (getDonors.fail())
		cout << "failed to open the file\n";
	while (getDonors >> id >> name >> user >> pass >> age >> gender >> bloodType >> lastDonationDate)
	{
		d.age = age;
		d.bloodType = bloodType;
		d.gender = gender;
		d.id = id;
		d.name = name;
		d.pass = pass;
		d.user = user;
		d.lastDonationDate = lastDonationDate;
		v.push_back(d);
	}
	getDonors.close();
	double q;
	ifstream getbloodA("A.txt");
	while (getbloodA >> q)
	{
		A.push_back(q);
	}
	getbloodA.close();
	ifstream getbloodB("B.txt");
	while (getbloodB >> q)
	{
		B.push_back(q);
	}
	getbloodB.close();
	ifstream getbloodAB("AB.txt");
	while (getbloodAB >> q)
	{
		AB.push_back(q);
	}
	getbloodAB.close();
	ifstream getbloodO("O.txt");
	while (getbloodO >> q)
	{
		O.push_back(q);
	}
	getbloodO.close();
}


void donor::donorRegester()
{
	cout << "enter your age : ";
	cin >> d.age;
	if (d.age < 17 || d.age>60)
	{
		cout << "your age must be from 17 to 60\n";
		return;
	}
	char ill;
	cout << "do you suffer from any disease (blood pressure disorders, thyroid disease, diabetes, cancer, heart disorders, hepatitis) 'y' for yes , 'n' for no : ";
	cin >> ill;
	if (ill == 'y' || ill == 'Y')
	{
		cout << "sorry , you can not donate safely\n";
		return;
	}
	cout << "\nyou are safe to donate :)\n\n";
	bool checkID = true;
	cout << "id : ";
	cin >> d.id;
	while (checkID)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (d.id == v[i].id)
			{
				checkID = false;
				break;
			}
		}
		if (!checkID)
		{
			cout << "sorry this id already exists , try again\n";
			cout << "id : ";
			cin >> d.id;
			checkID = true;
		}
		else
			break;
	}
	cout << "name : ";
	cin >> d.name;
	bool checkuser = true;
	cout << "username : ";
	cin >> d.user;
	while (checkuser)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (d.user == v[i].user)
			{
				checkuser = false;
				break;
			}
		}
		if (!checkuser)
		{
			cout << "sorry this username already exists , try again\n";
			cout << "username : ";
			cin >> d.user;
			checkuser = true;
		}
		else
			break;
	}
	cout << "strong password : ";
	d.pass = hidepassword();
	cout << "\ngender (m for male , f for female) : ";
	cin >> d.gender;
	while (d.gender != 'm' && d.gender != 'f')
	{
		cout << "\ninvalid gender :( try again\n";
		cin >> d.gender;
	}
	cout << "blood type (A or B or AB or O) : ";
	cin >> d.bloodType;
	while (d.bloodType != "A" && d.bloodType != "a" && d.bloodType != "B" && d.bloodType != "b" && d.bloodType != "AB" && d.bloodType != "ab" && d.bloodType != "O" && d.bloodType != "o")
	{
		cout << "\ninvalid blood type :( try again\n";
		cin >> d.bloodType;
	}
	d.lastDonationDate = 0;
	v.push_back(d);
	system("cls");
	cout << "thanks...your email is saved\n\n";
}


bool donor::login()
{
	bool success = false;
	string username, password;
	cout << "username: ";
	cin >> username;
	cout << "password: ";
	password = hidepassword();
	for (int i = 0; i < v.size(); i++)
		if (v[i].user == username && v[i].pass == password)
		{
			success = true;
			index = i;
		}
	if (success)
	{
		system("cls");
		cout << "\nlogin successfuly\n\nwelcom " << v[index].name << "\n";
	}
	else if (!success)
		cout << "\nwrong emial or password \n \n";
	return success;
}


void donor::clear()
{
	ofstream clearDonors("donors.txt", ios::trunc);
	clearDonors.clear();
	clearDonors.close();
	ofstream clearBloodA("A.txt", ios::trunc);
	clearBloodA.clear();
	clearBloodA.close();
	ofstream clearBloodB("B.txt", ios::trunc);
	clearBloodB.clear();
	clearBloodB.close();
	ofstream clearBloodAB("AB.txt", ios::trunc);
	clearBloodAB.clear();
	clearBloodAB.close();
	ofstream clearBloodO("O.txt", ios::trunc);
	clearBloodO.clear();
	clearBloodO.close();
}


string donor::hidepassword()
{
	string result;
	char c;
	c = _getch();
	while (c != '\r')
	{
		if (c == '\b')
		{
			if (result.length())
			{
				cout << "\b \b";
				result.erase(result.end() - 1);
			}
		}
		else
		{
			cout << "*";
			result.push_back(c);
		}
		c = _getch();
	}
	return result;
}


void donor::donation()
{
	time_t currentTime;
	currentTime = time(NULL);
	if (currentTime - v[index].lastDonationDate < 7776000)
	{
		cout << "sorry you can donate only once every three months (you have : "<< (v[index].lastDonationDate-currentTime+7776000)/60/60/24<<" days left\n";
	}
	else
	{
		double donation;
		cout << "you can donate:\n1: 0.45 L\n2: 0.5 L\n";
		cin >> donation;
		if (donation != 0.45 && donation != 0.5)
		{
			cout << "sorry you can only donate by these quantities\n";
		}
		else
		{
			if (v[index].bloodType == "a" || v[index].bloodType == "A")
			{
				A.push_back(donation);
			}
			if (v[index].bloodType == "b" || v[index].bloodType == "B")
			{
				B.push_back(donation);
			}
			if (v[index].bloodType == "ab" || v[index].bloodType == "AB")
			{
				AB.push_back(donation);
			}
			if (v[index].bloodType == "o" || v[index].bloodType == "O")
			{
				O.push_back(donation);
			}
			system("cls");
			cout << "thanks for your donation :)\n";
			v[index].lastDonationDate = currentTime;
		}
	}
}

void donor::update()
{
	char update;
	cout << "what do you want to update?\n1.username\n2.password\n";
	cin >> update;
	if (update == '1')
	{
		cout << "ok " << v[index].name << ", your new username : ";
		cin >> d.user;
		bool checkuser = true;
		while (checkuser)
		{
			for (int i = 0; i < v.size(); i++)
			{
				if (d.user == v[i].user)
				{
					checkuser = false;
					break;
				}
			}
			if (!checkuser)
			{
				cout << "sorry this username already exists , try again\n";
				cout << "your new username : ";
				cin >> d.user;
				checkuser = true;
			}
			else
			{
				v[index].user = d.user;
				system("cls");
				cout << "username updated\n";
				break;
			}
		}
	}
	else if (update == '2')
	{
		cout << "ok " << v[index].name << ", your new password : ";
		v[index].pass = hidepassword();
		system("cls");
		cout << "password updated\n";
	}
	else
		cout << "invalid choice\n";
}

void donor::deleteacc()
{
	v.erase(v.begin() + index);
	system("cls");
	cout << "account deleted successfully\n";
}


void donor::saveAndClose()
{

	ofstream savedonor("donors.txt", ios::app);
	if (savedonor.fail())
		cout << "failed to open the file\n";
	for (int i = 0; i < v.size(); i++)
	{
		savedonor << v[i].id << " " << v[i].name << " " << v[i].user << " " << v[i].pass << " " << v[i].age << " " << v[i].gender << " " << v[i].bloodType << " " << v[i].lastDonationDate << "\n";
	}
	savedonor.close();
	ofstream savebloodA("A.txt", ios::app);
	while (!A.empty())
	{
		savebloodA << A.front() << " ";
		A.pop_front();
	}
	savebloodA.close();
	ofstream savebloodB("B.txt", ios::app);
	while (!B.empty())
	{
		savebloodB << B.front() << " ";
		B.pop_front();
	}
	savebloodB.close();
	ofstream savebloodAB("AB.txt", ios::app);
	while (!AB.empty())
	{
		savebloodAB << AB.front() << " ";
		AB.pop_front();
	}
	savebloodAB.close();
	ofstream savebloodO("O.txt", ios::app);
	while (!O.empty())
	{
		savebloodO << O.front() << " ";
		O.pop_front();
	}
	savebloodO.close();
}


void donor::saveDonor()
{
	ofstream savedonor("donors.txt", ios::app);
	if (savedonor.fail())
		cout << "failed to open the file\n";
	for (int i = 0; i < v.size(); i++)
	{
		savedonor << v[i].id << " " << v[i].name << " " << v[i].user << " " << v[i].pass << " " << v[i].age << " " << v[i].gender << " " << v[i].bloodType << " " << v[i].lastDonationDate << "\n";
	}
	savedonor.close();
}
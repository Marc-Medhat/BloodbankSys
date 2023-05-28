#include "recipient.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<ctime>

using namespace std;

recipient r;

recipient::recipient()
{
	deque<float> a;
	deque<float> b;
	deque<float> ab;
	deque<float> o;
	double q;
	totalA = 0;
	totalB = 0;
	totalAB = 0;
	totalO = 0;

	ifstream getRecipients("recipients.txt");
	if (getRecipients.fail())
		cout << "failed to open the file\n";
	while (getRecipients >> id >> name >> user >> pass >> age >> gender >> bloodType >> hospital >> doctor)
	{
		r.age = age;
		r.bloodType = bloodType;
		r.gender = gender;
		r.id = id;
		r.name = name;
		r.pass = pass;
		r.user = user;
		r.doctor = doctor;
		r.hospital = hospital;
		v.push_back(r);
	}
	getRecipients.close();

	ifstream getbloodA("A.txt");
	while (getbloodA >> q)
	{
		a.push_back(q);
	}
	getbloodA.close();
	ifstream getbloodB("B.txt");
	while (getbloodB >> q)
	{
		b.push_back(q);
	}
	getbloodB.close();
	ifstream getbloodAB("AB.txt");
	while (getbloodAB >> q)
	{
		ab.push_back(q);
	}
	getbloodAB.close();
	ifstream getbloodO("O.txt");
	while (getbloodO >> q)
	{
		o.push_back(q);
	}
	getbloodO.close();
	while (!a.empty())
	{
		A.push_back(a.front());
		totalA += a.front();
		a.pop_front();
	}
	while (!b.empty())
	{
		B.push_back(b.front());
		totalB += b.front();
		b.pop_front();
	}
	while (!ab.empty())
	{
		AB.push_back(ab.front());
		totalAB += ab.front();
		ab.pop_front();
	}
	while (!o.empty())
	{
		O.push_back(o.front());
		totalO += o.front();
		o.pop_front();
	}
}

void recipient::recipientRegester()
{
	bool checkID = true;
	cout << "id : ";
	cin >> r.id;
	while (checkID)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (r.id == v[i].id)
			{
				checkID = false;
				break;
			}
		}
		if (!checkID)
		{
			cout << "sorry this id already exists , try again\n";
			cout << "id : ";
			cin >> r.id;
			checkID = true;
		}
		else
			break;
	}
	cout << "name : ";
	cin >> r.name;
	cout << "age : ";
	cin >> r.age;
	bool checkuser = true;
	cout << "username : ";
	cin >> r.user;
	while (checkuser)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (r.user == v[i].user)
			{
				checkuser = false;
				break;
			}
		}
		if (!checkuser)
		{
			cout << "sorry this username already exists , try again\n";
			cout << "username : ";
			cin >> r.user;
			checkuser = true;
		}
		else
			break;
	}
	cout << "strong password : ";
	r.pass = hidepassword();
	cout << "\ngender (m for male , f for female) : ";
	cin >> r.gender;
	while (r.gender != 'm' && r.gender != 'f')
	{
		cout << "\ninvalid gender :( try again\n";
		cin >> r.gender;
	}
	cout << "blood type (A or B or AB or O) : ";
	cin >> r.bloodType;
	while (r.bloodType != "A" && r.bloodType != "a" && r.bloodType != "B" && r.bloodType != "b" && r.bloodType != "AB" && r.bloodType != "ab" && r.bloodType != "O" && r.bloodType != "o")
	{
		cout << "\ninvalid blood type :( try again\n";
		cin >> r.bloodType;
	}
	cout << "hospital : ";
	cin >> r.hospital;
	cout << "doctor of the case : ";
	cin >> r.doctor;
	v.push_back(r);
	system("cls");
	cout << "thanks...your email is saved\n\n";
}


bool recipient::login()
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


void recipient::clear()
{
	ofstream clearRecipient("recipients.txt", ios::trunc);
	clearRecipient.clear();
	clearRecipient.close();
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


string recipient::hidepassword()
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


void recipient::update()
{
	char update;
	cout << "what do you want to update?\n1.username\n2.password\n3.hospital\n4.doctor of the case\n";
	cin >> update;
	if (update == '1')
	{
		cout << "ok " << v[index].name << ", your new username : ";
		cin >> r.user;
		bool checkuser = true;
		while (checkuser)
		{
			for (int i = 0; i < v.size(); i++)
			{
				if (r.user == v[i].user)
				{
					checkuser = false;
					break;
				}
			}
			if (!checkuser)
			{
				cout << "sorry this username already exists , try again\n";
				cout << "your new username : ";
				cin >> r.user;
				checkuser = true;
			}
			else
			{
				v[index].user = r.user;
				system("cls");
				cout << "username updated\n";
				break;
			}
		}
	}
	else if (update == '2')
	{
		cout << "ok " << v[index].name << ", your new password : ";
		cin >> v[index].pass;
		system("cls");
		cout << "password updated\n";
	}
	else if (update == '3')
	{
		cout << "ok " << v[index].name << ", your new hospital : ";
		cin >> v[index].hospital;
		system("cls");
		cout << "hospital updated\n";
	}
	else if (update == '4')
	{
		cout << "ok " << v[index].name << ", your new doctor : ";
		cin >> v[index].doctor;
		system("cls");
		cout << "your new doctor's name updated\n";
	}
	else
		cout << "invalid choice\n";
}


void recipient::displayBloodData()
{
	cout << "blood type A : " << totalA << " L\n";
	cout << "blood type B : " << totalB << " L\n";
	cout << "blood type AB : " << totalAB << " L\n";
	cout << "blood type O : " << totalO << " L\n";
}


void recipient::search()
{
	cout << "enter a blood type : ";
	cin >> r.bloodType;
	if (r.bloodType == "A" || r.bloodType == "a")
	{
		if (totalA > 0)
		{
			cout << "blood type A is available ( total = " << totalA << ")\n";
		}
		else
			cout << "this blood type is not available :(\n";
	}
	else if (r.bloodType == "B" || r.bloodType == "b")
	{
		if (totalB > 0)
		{
			cout << "blood type B is available ( total = " << totalB << ")\n";
		}
		else
			cout << "this blood type is not available :(\n";
	}
	else if (r.bloodType == "AB" || r.bloodType == "ab")
	{
		if (totalAB > 0)
		{
			cout << "blood type AB is available ( total = " << totalAB << ")\n";
		}
		else
			cout << "this blood type is not available :(\n";
	}
	else if (r.bloodType == "O" || r.bloodType == "o")
	{
		if (totalO > 0)
		{
			cout << "blood type O is available ( total = " << totalO << ")\n";
		}
		else
			cout << "this blood type is not available :(\n";
	}
	else
		cout << "invalid blood type\n";
}



void recipient::reqestBlood()
{
	string blood;
	double quantity;
	double q = 0;
	cout << "requested blood type : ";
	cin >> blood;
	if (blood != "A" && blood != "a" && blood != "B" && blood != "b" && blood != "AB" && blood != "ab" && blood != "O" && blood != "o")
	{
		cout << "invalid blood type\n";
	}
	else
	{
		cout << "requested quantity : ";
		cin >> quantity;
		if (blood == "A" || blood == "a")
		{
			if (totalA == quantity)
			{
				totalA = 0;
				while (!A.empty())
				{
					A.pop_front();
				}
				cout << "requested blood will be transported to " << v[index].hospital << " hospital\n";
			}
			else if (totalA > quantity)
			{
				totalA -= quantity;
				while (quantity > 0)
				{
					q = A.front();
					if (quantity > q)
					{
						quantity = quantity - q;
						A.pop_front();
					}
					else if (q > quantity)
					{
						A.pop_front();
						q = q - quantity;
						A.push_front(q);
						quantity = 0;
					}
					else
					{
						A.pop_front();
						break;
					}
				}
				cout << "requested blood will be transported to " << v[index].hospital << " hospital\n";
			}
			else
			{
				cout << "sorry , we dont have this amount\n";
			}
		}
		else if (blood == "B" || blood == "b")
		{
			if (totalB == quantity)
			{
				totalB = 0;
				while (!B.empty())
				{
					B.pop_front();
				}
				cout << "requested blood will be transported to " << v[index].hospital << " hospital\n";
			}
			else if (totalB > quantity)
			{
				totalB -= quantity;
				while (quantity > 0)
				{
					q = B.front();
					if (quantity > q)
					{
						quantity = quantity - q;
						B.pop_front();
					}
					else if (q > quantity)
					{
						B.pop_front();
						q = q - quantity;
						B.push_front(q);
						quantity = 0;
					}
					else
					{
						B.pop_front();
						break;
					}
				}
				cout << "requested blood will be transported to " << v[index].hospital << " hospital\n";
			}
			else
			{
				cout << "sorry , we dont have this amount\n";
			}
		}
		else if (blood == "AB" || blood == "ab")
		{
			if (totalAB == quantity)
			{
				totalAB = 0;
				while (!AB.empty())
				{
					AB.pop_front();
				}
				cout << "requested blood will be transported to " << v[index].hospital << " hospital\n";
			}
			else if (totalAB > quantity)
			{
				totalAB -= quantity;
				while (quantity > 0)
				{
					q = AB.front();
					if (quantity > q)
					{
						quantity = quantity - q;
						AB.pop_front();
					}
					else if (q > quantity)
					{
						AB.pop_front();
						q = q - quantity;
						AB.push_front(q);
						quantity = 0;
					}
					else
					{
						AB.pop_front();
						break;
					}
				}
				cout << "requested blood will be transported to " << v[index].hospital << " hospital\n";
			}
			else
			{
				cout << "sorry , we dont have this amount\n";
			}
		}
		else if (blood == "O" || blood == "o")
		{
			if (totalO == quantity)
			{
				totalO = 0;
				while (!O.empty())
				{
					O.pop_front();
				}
				cout << "requested blood will be transported to " << v[index].hospital << " hospital\n";
			}
			else if (totalO > quantity)
			{
				totalO -= quantity;
				while (quantity > 0)
				{
					q = O.front();
					if (quantity > q)
					{
						quantity = quantity - q;
						O.pop_front();
					}
					else if (q > quantity)
					{
						O.pop_front();
						q = q - quantity;
						O.push_front(q);
						quantity = 0;
					}
					else
					{
						O.pop_front();
						break;
					}
				}
				cout << "requested blood will be transported to " << v[index].hospital << " hospital\n";
			}
			else
			{
				cout << "sorry , we dont have this amount\n";
			}
		}
	}
}


void recipient::deleteacc()
{
	v.erase(v.begin() + index);
	system("cls");
	cout << "account deleted successfully\n";
}


void recipient::saveAndClose()
{
	
	ofstream saverecipient("recipients.txt", ios::app);
	if (saverecipient.fail())
		cout << "failed to open the file\n";
	for (int i = 0; i < v.size(); i++)
	{
		saverecipient << v[i].id << " " << v[i].name << " " << v[i].user << " " << v[i].pass << " " << v[i].age << " " << v[i].gender << " " << v[i].bloodType << " " << v[i].hospital << " " << v[i].doctor << "\n";
	}
	saverecipient.close();
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


void recipient::saveRecipient()
{
	ofstream saverecipient("recipients.txt", ios::app);
	if (saverecipient.fail())
		cout << "failed to open the file\n";
	for (int i = 0; i < v.size(); i++)
	{
		saverecipient << v[i].id << " " << v[i].name << " " << v[i].user << " " << v[i].pass << " " << v[i].age << " " << v[i].gender << " " << v[i].bloodType << " " << v[i].hospital << " " << v[i].doctor << "\n";
	}
	saverecipient.close();
}

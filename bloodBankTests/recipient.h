#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<deque>
#include<ctime>
using namespace std;

class recipient
{
private:
	int id;
	string name;
	string user;
	string pass;
	int age;
	char gender;
	string bloodType;
	string hospital;
	string doctor;
	int index = 0;
	vector<recipient>v;
	deque<float> A;
	deque<float> B;
	deque<float> AB;
	deque<float> O;
	double totalA;
	double totalB;
	double totalAB;
	double totalO;

public:
	recipient();
	void recipientRegester();
	bool login();
	void clear();
	void deleteacc();
	string hidepassword();
	void update();
	void search();
	void displayBloodData();
	void reqestBlood();
	void saveAndClose();
	void saveRecipient();
};
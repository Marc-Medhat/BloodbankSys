#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<ctime>
using namespace std;
class donor
{
private:
    int age;
    int id;
    string name;
    string user;
    string pass;
    char gender;
    string bloodType;
    time_t lastDonationDate = 0;
    int index = 0;
    vector<donor>v;
    deque<double> A;
    deque<double> B;
    deque<double> AB;
    deque<double> O;
    
public:
    donor();
    void donorRegester();
    bool login();
    string hidepassword();
    void clear();
    void deleteacc();
    void donation();
    void update();
    void saveAndClose();
    void saveDonor();
};
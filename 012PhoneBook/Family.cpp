#include "Person.h"
#include "Family.h"
#include <ctime>
#include <time.h>
#include <stdlib.h>
using std::cout;
using std::endl;
using std::istringstream;

Family::Family(string& firstName, string& lastName, int& phoneNumber, string& birthday)
	:Person(firstName,lastName,phoneNumber)
{
	this->birthday = birthday;
}

void Family::setBirthday(string& birthday){
	this->birthday = birthday;
}

string Family::getBirthday(){
	return birthday;
}

//METHOD ���� : ���ϰ� ���� ��¥�� ����� d-Day ����ϱ�
//**�Ѵ��� 31�Ϸ� �����ؼ� ���, �� �� �� 372�Ϸ� ����**
int Family::dDay(){

	time_t now = time(0);
	tm *ltm = localtime(&now);
	int presentMonth = ltm->tm_mon+1;
	int presentDay = ltm->tm_mday;

	string month = birthday.substr(2,2);
	string day = birthday.substr(4,2);
	int birthMonth = std::stoi(month);
    int birthDay = std::stoi(day);
    int difference = 0;

    //CASE1 : ���� ��¥�� birthday�� ���� ���
	if(birthMonth==presentMonth && birthDay==presentDay)
		difference=0;
	//CASE2 : birthday�� ���� ���� �� �� ���
	else if((birthMonth>presentMonth)||((birthMonth==presentMonth)&&(birthDay>presentDay))){
		difference = (birthMonth-presentMonth)*31+birthDay-presentDay;
	} 
	//CASE3 : birthday�� ��������, ������ ���
	else{
		difference = 372 - ((presentMonth-birthMonth)*31 + presentDay - birthDay);
	}

	return difference;
}	


void Family::print(){
	if(getLastName()=="No Last Name")
		cout << getFirstName() << "_";
	else
		cout << getFirstName() << " " << getLastName() << "_";
	cout << printPhoneNumber() << "_";
	cout << getBirthday() << "_";
	cout << dDay() << endl;
}

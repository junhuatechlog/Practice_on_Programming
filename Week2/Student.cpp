#define _CRT_SECURE_NO_DEPRECATE
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <iostream>
/*#include <string.h>
#include <stdio.h>
#include <stdlib.h>*/
using namespace std;

class Student{
	char name[30];
	unsigned int age;
	char sID[30];
	unsigned int ScoreArr[4];
public:
	Student(char *_name, int _age, char *_sID, unsigned int s1, unsigned int s2, unsigned int s3, unsigned int s4);
	void printStudent(void);
	unsigned int getAvgScore();

};

Student::Student(char *_name, int _age, char *_sID, unsigned int s1, unsigned int s2, unsigned int s3, unsigned int s4){
	strcpy(name, _name);
	strcpy(sID, _sID);
	age = _age;
	ScoreArr[0] = s1;
	ScoreArr[1] = s2;
	ScoreArr[2] = s3;
	ScoreArr[3] = s4;
}

unsigned int Student::getAvgScore(){
	return (ScoreArr[0] + ScoreArr[1] + ScoreArr[2] + ScoreArr[3]) / 4;
}

void Student::printStudent(void){
	cout << name << "," << age << "," << sID << "," << getAvgScore() << endl;
}

void printHelp(void){

	cout << "Help: input a student's name, age, id, score1, score2, score3, score41" << endl;
	cout << "Example: WangJunhua,69,61392064,50,60,70,80" << endl;
}

int main(int argc, char * argv[]){
	char name[30] = "";
	unsigned int age;
	char *p = NULL;
	char sID[30] = "";
	unsigned int arr[4] = {};
	char data[30] = {};
    char buff[128] =""; 


    printHelp();

    scanf("%s", buff);

	sscanf(buff, "%[^,]", name);
	p = buff + strlen(name) + 1;
	sscanf(p, "%[^,]", data);
	age = atoi(data);
	p += strlen(data) + 1;
	sscanf(p, "%[^,]", sID);
	p += strlen(sID) + 1;
	sscanf(p, "%[^,]", data);
	arr[0] = atoi(data);
	p += strlen(data) + 1;
	sscanf(p, "%[^,]", data);
	arr[1] = atoi(data);
	p += strlen(data) + 1;
	sscanf(p, "%[^,]", data);
	arr[2] = atoi(data);
	p += strlen(data) + 1;
	sscanf(p, "%[^,]", data);
	arr[3] = atoi(data);

	/*
	cout << name << endl;
	cout << age << endl;
	cout << sID << endl;
	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	cout << arr[3] << endl; */

	Student *pStudent = new Student(name, age, sID, arr[0], arr[1], arr[2], arr[3]);
	pStudent->printStudent();
	return 0;
}

/*
sscanf(s, format "%[^,]", ...);
http://hi.baidu.com/lonten/item/a13f436000faa72668105bc1
*/


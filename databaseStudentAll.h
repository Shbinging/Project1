#pragma once
#include"diag.h"
class databaseStudentAll
{
	//ѧ��������������ά��
	//�ļ�Ϊstudent.txt
public:
	databaseStudentAll();
	//�ļ�����
	int readFromFile(string path = "student.txt");
	bool writeToFile(string path = "student.txt");
	string pathBase;
};

extern databaseStudentAll dataStuAll;

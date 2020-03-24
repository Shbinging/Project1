#pragma once
#include"diag.h"
class databaseStudentAll
{
	//学生名单及其密码维护
	//文件为student.txt
public:
	databaseStudentAll();
	//文件操作
	int readFromFile(string path = "student.txt");
	bool writeToFile(string path = "student.txt");
	string pathBase;
};

extern databaseStudentAll dataStuAll;

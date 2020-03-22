#pragma once
#include"diag.h"
#include"databaseStudentAll.h"
class userStu
{
public:
	bool checkpassword(string name, string password);
	bool isStuWordInList(stuWordNode tmp);
	void addStuWord(string name, string password);
private:
	databaseStudentAll dataStuAll;
};


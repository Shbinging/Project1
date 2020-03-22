#pragma once
#include"diag.h"
class databaseStudentAll
{
public:
	databaseStudentAll();
	int readFromFile(string path);
	bool writeToFile(string path);

	vector<stuWordNode>& getStuWordList();
	bool isStuInStuWordList(stuWordNode);
	stuWordNode getStuWord(stuWordNode);
	
	void addStuWord(stuWordNode);
	
	vector<stuWordNode> stuWordList;
	string pathBase;
};

extern databaseStudentAll dataStuAll;

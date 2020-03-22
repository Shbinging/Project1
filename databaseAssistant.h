#pragma once
#include"diag.h"


class databaseAssistant
{
public:
	databaseAssistant();
	int countAssistant(assistNode tmp);
	bool isStuInAssistList(assistNode tmp);
	void addStuInAssistList(assistNode tmp);
	assistNode& getAssistNode(assistNode tmp);
	void delCourseInAssistList(assistNode tmp);
	int readFromFile(string path);
	bool writeToFile(string path);
	vector<assistNode> assistList;
	bool isCourseInAssistList(assistNode tmp);
	assistNode assist;
private:
	string pathBase;
};
extern databaseAssistant dataAssi;

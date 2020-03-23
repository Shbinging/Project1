#pragma once
#include"diag.h"
class databaseStudentAll
{
	//学生名单及其密码维护
	//文件为student.txt
public:
	databaseStudentAll();
	//文件操作
	int readFromFile(string path);
	bool writeToFile(string path);

	void addStuWord(stuWordNode);//增加一个学生及其密码

	vector<stuWordNode>& getStuWordList();//查询全部学生名单
	bool isStuInStuWordList(stuWordNode);//查询某个学生是否存在
	stuWordNode getStuWord(stuWordNode);//查询某个学生的密码
	
	
	
	vector<stuWordNode> stuWordList;//表
	string pathBase;
};

extern databaseStudentAll dataStuAll;

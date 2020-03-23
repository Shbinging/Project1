#pragma once
#include"diag.h"


class databaseAssistant
{
public:
	databaseAssistant();//初始化助教文件
	//文件部分的读写 文件为assistant.txt
	int readFromFile(string path);
	bool writeToFile(string path);

	int countAssistant(assistNode tmp);//统计某个学生报名助教的次数 传入参数 stuId
	bool isStuInAssistList(assistNode tmp);//查询某个学生是否在某个课程中当助教 传入参数courseId stuId

	void addStuInAssistList(assistNode tmp);//在某个课程增加一个学生 传入参数 courseId stuId
	assistNode& getAssistNode(assistNode tmp);//查询某个课程的学生名单 返回参数 assistNode
	
	bool isCourseInAssistList(assistNode tmp);//查询某个课程是否有助教 传入参数 courseId
	void delCourseInAssistList(assistNode tmp);//删除某个课程以及该课程全部助教 传入参数courseId

	vector<assistNode> assistList;//表(所有assistNode组成的一列)
	assistNode assist;//assistNode
private:
	string pathBase;//文件路径
};

extern databaseAssistant dataAssi;

#pragma once
#include"diag.h"
#include"databaseStudentAll.h"
#include"databaseStudentX.h"
#include"databaseCurrentCourse.h"
#include"databaseAssistant.h"
#include"databaseCourseAll.h"
#include"agori.h"
class userStu
{
public:
	bool checkpassword(string name, string password);
	void setpath(string path);//初始化
	bool isStuWordInList(stuWordNode tmp);
	void addStuWord(string name, string password);
	
	vector<string>& getStuCourseList();
	int addCourse(CourseNode);
	int delCourse(CourseNode);
	int beAssistant(assistNode);//要求自己当助教
	int addAssistant(assistNode tmp, string st);//申请别人当自己的助教
	
	bool isCourseAssistExsist(assistNode);
	int isCourseAssistHaveChosen(assistNode);
	vector<string>& getAssistNode(assistNode);
	CourseNode getCourse(CourseNode tmp);
	string userName;
	
	bool isAssistError();//判断有没有该学生的助教退课 1有 0无
	vector<string> getAssistError();//获取该学生退课的助教名单
	pair<int, int> getProAndNonePro();//获取剩余专业课非专业课要求

	void close();
private:
	int assistantSum, proSum, nonProSum, courseSum;
	//当助教门数， 专业课数， 非专业课数， 课程数
	//在初始化时查表统计，之后在学生操作过程中直接计数
};


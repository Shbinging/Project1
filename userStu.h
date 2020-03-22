#pragma once
#include"diag.h"
#include"databaseStudentAll.h"
#include"databaseStudentX.h"
#include"databaseCurrentCourse.h"
#include"databaseAssistant.h"
class userStu
{
public:
	bool checkpassword(string name, string password);
	void setpath(string path);
	bool isStuWordInList(stuWordNode tmp);
	void addStuWord(string name, string password);
	
	vector<stuCourseNode>& getStuCourseList();
	int addCourse(CourseNode);
	int delCourse(CourseNode);

	bool isCourseAssistExsist(assistNode);
	int isCourseAssistHaveChosen(assistNode);
	int beAssistant(assistNode);//要求自己当助教
	int addAssistant(assistNode& tmp, string st);//申请别人当自己的助教
	assistNode& getAssistNode(assistNode);
	CourseNode getCourse(CourseNode tmp);
	string userName;

private:
	int assistantSum;

};


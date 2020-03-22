#pragma once
#include"diag.h"
class databaseStudentX
{
public:
	int readFromFile(string path);
	bool writeToFile(string path);

	vector<stuCourseNode>& getStuCourseList();
	bool isCourseInStuCourseList(CourseNode);
	stuCourseNode getStuCourse(stuCourseNode);

	void addStuCourse(stuCourseNode);
	void delStuCourse(stuCourseNode);
	void addAssistant(assistNode);
	bool isCourseAssistantFull(stuCourseNode tmp);
	void setpath(string st);
	vector<stuCourseNode> stuCourseList;
	string pathBase;
	
};

extern databaseStudentX dataStuX;;
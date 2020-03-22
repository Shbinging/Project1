#pragma once
#include"diag.h"
#include"databaseStudentAll.h"
#include"databaseStudentX.h"
#include"databaseCurrentCourse.h"
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
	CourseNode getCourse(CourseNode tmp);
private:

};


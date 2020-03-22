#pragma once
#include"diag.h"
#include"databaseCurrentCourse.h"

class userAdmin
{
public:
	bool checkPassword(string, string);
	int addStuFromFile(string);
	int addCourse(CourseNode);
	int delCourse(int);
	int editCourse(CourseNode);
	bool isCourseInList(CourseNode);
	vector<CourseNode>& getCourseList();
	CourseNode getCourse(CourseNode);
//private:
	//databaseCurrentCourse dataCourse;
};
extern vector<CourseNode>CourseList;


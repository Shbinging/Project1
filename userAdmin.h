#pragma once
#include"diag.h"
#include"databaseCurrentCourse.h"

class userAdmin
{
public:
	bool checkPassword(string);
	int addStuFromFile(string);
	int addCourse(CourseNode);
	int delCourse(int);
	bool isCourseInList(CourseNode);
	vector<CourseNode>& getCourseList();
	CourseNode getCourse();
private:
	databaseCurrentCourse dataCourse;
};
extern vector<CourseNode>CourseList;


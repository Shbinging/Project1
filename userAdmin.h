#pragma once
#include"diag.h"
#define testUi
class userAdmin
{
public:
	bool checkPassword(string);
	int addStuFromFile(string);
	int addCourse(CourseNode);
	int delCourse(CourseNode);
	vector<CourseNode>& getCourseList();
	CourseNode getCourse();
};
extern vector<CourseNode>CourseList;


#pragma once
#include"diag.h"
#include"databaseFileOpt.h"
class databaseCurrentCourse :
	public databaseFileOpt
{
public:
	databaseCurrentCourse();
	void uploadCourseList(string);
	void addCourse(CourseNode);
	void delCourse(CourseNode);
	bool isCourseInlist(CourseNode);
	vector<CourseNode>& getCourseList();
	CourseNode getCourse(CourseNode);
	vector<CourseNode>CourseList;
private:
	int courseSum;
	string path;
};


#pragma once
#include"diag.h"
class databaseCurrentCourse
{
public:
	databaseCurrentCourse();
	bool isFileExsist(string path);
	int readFromFile(string path);
	bool writeToFile(string path);

	void addCourse(CourseNode);
	void delCourse(CourseNode);
	void editCourse(CourseNode);

	bool isCourseInlist(CourseNode);
	vector<CourseNode>& getCourseList();
	CourseNode getCourse(CourseNode);
	vector<CourseNode>CourseList;
	string pathBase;
private:
	int courseSum;
};

extern databaseCurrentCourse dataCourse;
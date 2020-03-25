#pragma once
#include"diag.h"
#include"databaseCurrentCourse.h"
#include"databaseAssistant.h"
#include"databaseCourseAll.h"
#include"ADEQ.h"
#include"agori.h"
class userAdmin
{
public:
	userAdmin(){
	}
	bool checkPassword(string, string);
	int addStuFromFile(string);
	int addCourse(CourseNode);
	int delCourse(int);
	int editCourse(CourseNode);
	bool isCourseInList(CourseNode);
	courseStuNode getCourseStuList(int id);
	vector<string>& getCourseList();
	CourseNode getCourse(CourseNode);
	assistNode getAssistNode(int courseId);
	void close();
//private:
	//databaseCurrentCourse dataCourse;
};
//extern vector<CourseNode>CourseList;



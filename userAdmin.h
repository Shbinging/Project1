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
		dataCourseStu.init();
	}
	bool checkPassword(string, string);
	int addStuFromFile(string);
	int addCourse(CourseNode);
	int delCourse(int);
	int editCourse(CourseNode);
	bool isCourseInList(CourseNode);
	courseStuNode getCourseStuList(int id);
	vector<string>& getCourseList();//这个要改！！！
	CourseNode getCourse(CourseNode);
	assistNode getAssistNode(int courseId);
//private:
	//databaseCurrentCourse dataCourse;
};
//extern vector<CourseNode>CourseList;



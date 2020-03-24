#pragma once
#include"diag.h"
class databaseCurrentCourse
{
	//负责维护课程的具体信息
	//文件+增删改查 文件为current_course.txt
public:
	databaseCurrentCourse();
	//文件操作
	bool isFileExsist(string path = "current_course.txt");
	int readFromFile(string path = "current_course.txt");
	bool writeToFile(string path = "current_course.txt");

	/*
	void addCourse(CourseNode);//增加一门课程信息
	void delCourse(CourseNode);//删除一门课程信息
	void editCourse(CourseNode);//改变某门课程的某个信息 以courseId/CourseName作为关键字，改变其他

	bool isCourseInlist(CourseNode);//查询某门课程是否存在
	vector<CourseNode>& getCourseList();//获取所有课程列表
	CourseNode getCourse(CourseNode);//获取某项课程信息

	vector<CourseNode>CourseList;
	*/
	string pathBase;
private:
	int courseSum;
};

extern databaseCurrentCourse dataCourse;
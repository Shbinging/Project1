#pragma once
#include"diag.h"
class databaseStudentX
{
	//本表维护某个学生的课程和助教信息
	//维护（学生，课程-该课程助教）关系
	//基本功能 增删改查 + 文件
public:
	//文件功能
	int readFromFile(string path);
	bool writeToFile(string path);
	void setpath(string st);//设置学生文件路径，注意st要加文件的后缀名！！！

	vector<stuCourseNode>& getStuCourseList();//获取学生的所有选课信息
	bool isCourseInStuCourseList(CourseNode);//查询学生是否选了某项课 参数 CourseId
	/*bool isCourseAssistantFull(stuCourseNode tmp);*/
	stuCourseNode getStuCourse(stuCourseNode);//获取学生的某门课的助教信息 参数 courseId

	void addStuCourse(stuCourseNode);//学生增加一门课
	void delStuCourse(stuCourseNode);//学生减少一门课
	void addAssistant(assistNode);//学生修改助教 参数 courseId Assistname
	
	vector<stuCourseNode> stuCourseList;
	string pathBase;
	
};

extern databaseStudentX dataStuX;;
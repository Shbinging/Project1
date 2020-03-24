#pragma once
#include"diag.h"
#include"databaseStudentAll.h"
#include"databaseCurrentCourse.h"
#include"databaseStudentX.h"
class databaseCourseAll
{
	//本表维护每个课程中所选学生的名字
	//维护（课程， 学生）关系
public:
	//databaseCourseAll();
	//int len();
	void init();//初始化统计
	/*
	void addStuInCourseX(int id, string name);//在某个课程中增加学生
	void addCourseXInGraph(int id);//增加一项课程

	void delCourseXInGraph(int id);//删除一项课程
	void delStuInCourseX(int id, string name);//删除某个课程中的某个学生
	
	pair<int, int> findStuInCourseX(int id, string name);//查询在某个课程中学生位置 -1没找到，返回位置
	bool isStuInCourseX(int id, string name);//查询某个学生是否选择某项课程
	courseStuNode& getListInCourseX(int id);//获取某个课程的学生名单
	int findCourseXInGraph(int id);
	bool isCourseXInGraph(int id);//查询该课程是否在表中
	
	vector<courseStuNode> courseStuList;
	courseStuNode courseStuListNode;
	*/
};

extern databaseCourseAll dataCourseStu;
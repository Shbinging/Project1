#pragma once
#include"diag.h"
#include"databaseStudentAll.h"
#include"databaseCurrentCourse.h"
#include"databaseStudentX.h"
class databaseCourseAll
{
public:
	databaseCourseAll();

	void addStuInCourseX(int id, string name);
	int len();
	pair<int, int> findStuInCourseX(int id, string name);//-1û�ҵ�������λ��
	bool isStuInCourseX(int id, string name);//find����
	void delStuInCourseX(int id, string name);
	const courseStuNode& getListInCourseX(int id);

	void addCourseXInGraph(int id);
	int findCourseXInGraph(int id);
	bool isCourseXInGraph(int id);
	void delCourseXInGraph(int id);
	vector<courseStuNode> courseStuList;
	courseStuNode courseStuListNode;
};

extern databaseCourseAll dataCourseStu;
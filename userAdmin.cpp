#include "userAdmin.h"


bool userAdmin::checkPassword(string)
{
	return false;
}

int userAdmin::addStuFromFile(string)
{
	return 0;
}

int userAdmin::addCourse(CourseNode tmp)
{
	if (dataCourse.isCourseInlist(tmp)) return 1;
	dataCourse.addCourse(tmp);
	return 0;
}

int userAdmin::delCourse(int id)
{
	if (dataCourse.isCourseInlist(CourseNode(id))){
		CourseNode tmp = dataCourse.getCourse(CourseNode(id));
		if (tmp.CourseSel != 0) return 2;
		else{
			dataCourse.delCourse(CourseNode(id));
			return 0;
		}
	}
	else return 1;
}

bool userAdmin::isCourseInList(CourseNode)
{
	return false;
}

vector<CourseNode>& userAdmin::getCourseList()
{
#ifdef testUi
	//dataCourse.addCourse(CourseNode("123", "123", 0, 0, "×¨Òµ¿Î"));
#endif
	return dataCourse.getCourseList();
}

CourseNode userAdmin::getCourse()
{
#ifdef testUi
	CourseNode tmp(0);
	return tmp;
#endif
}

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

int userAdmin::editCourse(CourseNode curCourse)
{
	CourseNode oriCourse = dataCourse.getCourse(CourseNode(curCourse.CourseId));
	if (curCourse.CourseName != ""){
		dataCourse.editCourse(curCourse);
		return 0;
	}
	else if (curCourse.CourseCap != -1){
		if (oriCourse.CourseSel > curCourse.CourseCap) return 1;
		else{
			dataCourse.editCourse(curCourse);
			return 0;
		}
	}
	else return 1;
}

bool userAdmin::isCourseInList(CourseNode tmp)
{
	return dataCourse.isCourseInlist(tmp);
}

vector<CourseNode>& userAdmin::getCourseList()
{
#ifdef testUi
	//dataCourse.addCourse(CourseNode("123", "123", 0, 0, "×¨Òµ¿Î"));
#endif
	return dataCourse.getCourseList();
}

CourseNode userAdmin::getCourse(CourseNode tmp)
{
	return dataCourse.getCourse(tmp);
}

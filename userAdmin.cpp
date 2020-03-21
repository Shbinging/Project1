#include "userAdmin.h"


int userAdmin::addStuFromFile(string)
{
	return 0;
}

vector<CourseNode>& userAdmin::getCourseList()
{
#ifdef testUi
	CourseList.clear();
	CourseList.push_back(CourseNode("123", "123", 0, 0));
	return CourseList;
#endif
}

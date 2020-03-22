#include "databaseCurrentCourse.h"

void databaseCurrentCourse::uploadCourseList(string)
{
}

void databaseCurrentCourse::addCourse(CourseNode tmp)
{
	tmp.CourseId = ++courseSum;
	CourseList.push_back(tmp);
}

void databaseCurrentCourse::delCourse(CourseNode tmp)
{
	For(i, 0, int(CourseList.size()) - 1){
		if (CourseList[i].CourseId == tmp.CourseId || CourseList[i].CourseName == tmp.CourseName){
			CourseList.erase(CourseList.begin() + i);
			break;
		}
	}
}

void databaseCurrentCourse::editCourse(CourseNode tmp)
{
	For(i, 0, int(CourseList.size()) - 1){
		if (CourseList[i].CourseId == tmp.CourseId){
			if (tmp.CourseName != "") CourseList[i].CourseName = tmp.CourseName;
			if (tmp.CourseCap != -1) CourseList[i].CourseCap = tmp.CourseCap;
		}
	}
}

bool databaseCurrentCourse::isCourseInlist(CourseNode tmp)
{
	For(i, 0, int (CourseList.size()) - 1){
		if (CourseList[i].CourseId == tmp.CourseId || CourseList[i].CourseName == tmp.CourseName) return 1;
	}
	return 0;
}

vector<CourseNode>& databaseCurrentCourse::getCourseList()
{
	return CourseList;
}

CourseNode databaseCurrentCourse::getCourse(CourseNode tmp)
{
	For(i, 0, int(CourseList.size()) - 1){
		if (CourseList[i].CourseId == tmp.CourseId || CourseList[i].CourseName == tmp.CourseName) return CourseList[i];
	}
}

databaseCurrentCourse::databaseCurrentCourse(){
	string path = "current_course.txt";
	uploadCourseList(path);
	if (CourseList.empty()) courseSum = 0;
	else courseSum = CourseList[CourseList.size() - 1].CourseId;
}
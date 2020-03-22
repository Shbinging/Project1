#include "userStu.h"
#include"diag.h"
bool userStu::checkpassword(string name, string password)
{
	if (!dataStuAll.isStuInStuWordList(stuWordNode(name))) return 0;
	stuWordNode tmp = dataStuAll.getStuWord(stuWordNode(name));
	if (password == tmp.stuPassword) return 1;
	else return 0;
}

void userStu::setpath(string path)
{
	dataStuX.setpath(path);
}

bool userStu::isStuWordInList(stuWordNode tmp)
{
	return dataStuAll.isStuInStuWordList(tmp);
}

void userStu::addStuWord(string name, string password)
{
	dataStuAll.addStuWord(stuWordNode(name, password));
}

vector<stuCourseNode>& userStu::getStuCourseList()
{
	return dataStuX.getStuCourseList();
}

int userStu::addCourse(CourseNode tmp)
{
	if (dataStuX.isCourseInStuCourseList(tmp)) return 1;
	else{
		CourseNode tmp1 = dataCourse.getCourse(tmp);
		if (tmp1.CourseSel + 1 > tmp1.CourseCap) return 2;
		tmp1.CourseSel++;
		dataCourse.editCourse(tmp1);
		dataStuX.addStuCourse(stuCourseNode(tmp.CourseId));
		return 0;
	}

}

int userStu::delCourse(CourseNode tmp)
{
	if (!dataStuX.isCourseInStuCourseList(tmp)) return 1;
	else{
		CourseNode tmp1 = dataCourse.getCourse(tmp);
		tmp1.CourseSel--;
		dataCourse.editCourse(tmp1);
		dataStuX.delStuCourse(stuCourseNode(tmp.CourseId));
		return 0;
	}
}

CourseNode userStu::getCourse(CourseNode tmp)
{
	return dataCourse.getCourse(tmp);
}

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
	assistantSum = dataAssi.countAssistant(assistNode(path)); 
	userName = path;
	dataStuX.setpath(path+".txt");
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
		dataCourseStu.addStuInCourseX(tmp.CourseId, userName);
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
		dataCourseStu.delStuInCourseX(tmp.CourseId, userName);
		//删除助教名单中该学生！
		return 0;
	}
}

bool userStu::isCourseAssistExsist(assistNode tmp)
{
	return dataAssi.isCourseInAssistList(tmp);
}

int userStu::isCourseAssistHaveChosen(assistNode tmp)
{
	if (!dataStuX.isCourseInStuCourseList(CourseNode(tmp.courseId))) return 2;
	stuCourseNode a = dataStuX.getStuCourse(stuCourseNode(tmp.courseId));
	if (a.assistant == "Null") return 0;
	else return 1;
}

int userStu::beAssistant(assistNode tmp)
{
	if (!dataCourse.isCourseInlist(CourseNode(tmp.courseId))) return 3;
	if (dataAssi.countAssistant(tmp) >= 2) return 2;
	if (dataAssi.isStuInAssistList(tmp)) return 1;
	dataAssi.addStuInAssistList(tmp);
	return 0;
}

int userStu::addAssistant(assistNode& tmp, string st)
{
	if (st == userName) return 2;
	if (!dataAssi.isStuInAssistList(assistNode(tmp.courseId, st))) return 1;
	dataStuX.addAssistant(assistNode(tmp.courseId, st));
	return 0;
}

assistNode& userStu::getAssistNode(assistNode tmp)
{
	return dataAssi.getAssistNode(tmp);
}

CourseNode userStu::getCourse(CourseNode tmp)
{
	return dataCourse.getCourse(tmp);
}

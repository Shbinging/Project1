#include "userAdmin.h"

bool userAdmin::checkPassword(string name, string password)
{
	return ((name == "Admin") && (password == "admin"));
}

int userAdmin::addStuFromFile(string path)
{
	if (path == dataCourse.pathBase){
		return dataCourse.readFromFile(path);
	}
	else{
		if (dataCourse.isFileExsist(dataCourse.pathBase)) return 2;
		else return dataCourse.readFromFile(path);
	}
}

int userAdmin::addCourse(CourseNode tmp)
{
	if (pCourse.queryHasKey(tmp.CourseName, 1)) return 1;
	tmp.CourseId = atoi(pCourse.queryLastKey()) + 1;
	string stId = to_string(tmp.CourseId);
	pCourse.addKey(stId);
	pCourse.add(stId, 1, tmp.CourseName);
	pCourse.add(stId, 2, tmp.CourseTeacher);
	pCourse.add(stId, 3, to_string(tmp.CourseCap));
	pCourse.add(stId, 4, to_string(tmp.CourseSel));
	pCourse.add(stId, 5, (tmp.CourseType == 0) ? "专业课" : "非专业课");
	return 0;
}

int userAdmin::delCourse(int id)
{
	string stId = to_string(id);
	if (!pCourse.queryHasKey(stId)) return 1;
	if (!pCourse.queryHas(stId, 4, "0")) return 2;
	pCourse.delKey(stId);
	return 0;
}

int userAdmin::editCourse(CourseNode curCourse)
{
	string stId = to_string(curCourse.CourseId);
	if (!pCourse.queryHasKey(stId)) return 1;
	if (curCourse.CourseTeacher != ""){
		pCourse.edit(stId, 2, curCourse.CourseTeacher);
		return 0;
	}
	else if (curCourse.CourseCap != -1){
		int sel = atoi(pCourse.query(stId, 4)[0]);
		if (sel > curCourse.CourseCap) return 1;
		else{
			pCourse.edit(stId, 3, to_string(curCourse.CourseCap));
			return 0;
		}
	}
	else return 1;
}

bool userAdmin::isCourseInList(CourseNode tmp)
{
	return pCourse.queryHasKey(to_string(tmp.CourseId));
}

courseStuNode userAdmin::getCourseStuList(int id)
{
	return courseStuNode(id, pCourse.query(to_string(id), 6));
}

vector<string>& userAdmin::getCourseList()
{
	return pCourse.queryKeyList();
}

CourseNode userAdmin::getCourse(CourseNode tmp)//id or name
{
	string stId;
	if (tmp.CourseId != -1){
		stId = to_string(tmp.CourseId);
	}
	else{
		stId = pCourse.query(tmp.CourseName, 0, 1)[0];
	}
	CourseNode newCourse;
	newCourse.CourseId = atoi(stId);
	newCourse.CourseName = pCourse.query(stId, 1)[0];
	newCourse.CourseTeacher = pCourse.query(stId, 2)[0];
	newCourse.CourseCap = atoi(pCourse.query(stId, 3)[0]);
	newCourse.CourseSel = atoi(pCourse.query(stId, 4)[0]);
	newCourse.CourseType = (pCourse.query(stId, 5)[0] == "专业课") ? 0 : 1;
	return newCourse;
}

assistNode userAdmin::getAssistNode(int courseId)
{
	if (!pCourse.queryHas(to_string(courseId), 7, "NULL"))
		return assistNode(courseId, pCourse.query(to_string(courseId), 7));
	else return assistNode();
}

void userAdmin::close()
{
	dataCourse.writeToFile();
	dataStuAll.writeToFile();
	dataAssi.writeToFile();
}

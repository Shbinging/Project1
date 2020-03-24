#include "userStu.h"
#include"diag.h"
#include"ADEQ.h"
bool userStu::checkpassword(string name, string password)
{
	if (!pStuPass.queryHasKey(name)) return 0;//无此用户
	if (password == pStuPass.query(name, 1)[0]) return 1;
	else return 0;
}

void userStu::setpath(string path)//init()
{
	dataStuX.setpath(path + ".txt");
	vector<string>& courseList = pStuCourse.queryKeyList();
	assistantSum = 0;
	proSum = 0;
	nonProSum = 0;
	For(i, 0, int(courseList.size()) - 1){
		if (pCourse.queryHas(courseList[i], 7, path)) assistantSum++;
		if (pCourse.queryHas(courseList[i], 5, "专业课")) proSum++;
		if (pCourse.queryHas(courseList[i], 5, "非专业课")) nonProSum++;
	}
	userName = path;
}

bool userStu::isStuWordInList(stuWordNode tmp)
{
	return pStuPass.queryHasKey(tmp.stuName);
}

void userStu::addStuWord(string name, string password)
{
	pStuPass.addKey(name);
	pStuPass.add(name, 1, password);
}

vector<string>& userStu::getStuCourseList()
{
	return pStuCourse.queryKeyList();
}

int userStu::addCourse(CourseNode tmp)//id
{
	if (!pCourse.queryHasKey(to_string(tmp.CourseId))) return 3;
	if (pStuCourse.queryHasKey(to_string(tmp.CourseId))) return 1;
	else{
		string stId = to_string(tmp.CourseId);
		int sel = atoi(pCourse.query(stId, 4)[0]);
		int cap = atoi(pCourse.query(stId, 3)[0]);
		if (sel + 1 > cap) return 2;
		sel++;
		pCourse.edit(stId, 4, to_string(sel));
		pCourse.add(stId, 6, userName);
		pStuCourse.addKey(stId);
		pStuCourse.add(stId, 1, "Null");
		if (pCourse.queryHas(stId, 5, "专业课")) proSum++;
		if (pCourse.queryHas(stId, 5, "非专业课")) nonProSum++;
		pStuCourse.keySort();
		return 0;
}

}

int userStu::delCourse(CourseNode tmp)
{
	if (!pStuCourse.queryHasKey(to_string(tmp.CourseId))) return 1;
	else{
		string stId = to_string(tmp.CourseId);
		int sel = atoi(pCourse.query(stId, 4)[0]);
		sel--;
		pCourse.edit(stId, 4, to_string(sel));
		pCourse.del(stId, 6, userName);//删除助教名单中该学生！
		pStuCourse.delKey(stId);
		if (pCourse.queryHas(stId, 7, userName)){
			pCourse.del(stId, 7, userName);
			assistantSum--;
		}
		if (pCourse.queryHas(stId, 5, "专业课")) proSum--;
		if (pCourse.queryHas(stId, 5, "非专业课")) nonProSum--;
		pStuCourse.keySort();
		return 0;
	}
}

bool userStu::isCourseAssistExsist(assistNode tmp)
{
	return !pCourse.queryHas(to_string(tmp.courseId), 7, "NULL");
}

int userStu::isCourseAssistHaveChosen(assistNode tmp)
{
	string stId = to_string(tmp.courseId);
	if (!pStuCourse.queryHasKey(stId)) return 2;//没选这门课
	if (pStuCourse.queryHas(stId, 1, "Null")|| pStuCourse.queryHas(stId, 1, "Wait")) return 0;
	else return 1;//已经选择助教
}

int userStu::beAssistant(assistNode tmp)
{
	string stId = to_string(tmp.courseId);
	if (!pStuCourse.queryHasKey(stId)) return 3;
	if (assistantSum >= 2) return 2;
	if (pCourse.queryHas(stId, 7, userName)) return 1;
	pCourse.add(stId, 7, userName);
	return 0;
}

int userStu::addAssistant(assistNode tmp, string st)
{
	string stId = to_string(tmp.courseId);
	if (st == userName) return 2;
	if (!pCourse.queryHas(stId, 7, st)) return 1;
	pStuCourse.edit(stId, 1, st);
	return 0;
}

vector<string>& userStu::getAssistNode(assistNode tmp)//获取课程助教名单
{
	return pCourse.query(to_string(tmp.courseId), 7);
}

CourseNode userStu::getCourse(CourseNode tmp)
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

bool userStu::isAssistError()
{
	vector<string> st = getAssistError();
	if (st.empty()) return 0;
	else return 1;
}

vector<string> userStu::getAssistError()
{
	vector<string> st;
	vector<string>& courseList = pStuCourse.queryKeyList();
	For(i, 0, int(courseList.size()) - 1){
		if (!pStuCourse.queryHas(courseList[i], 1, "Null")|| pStuCourse.queryHas(courseList[i], 1, "Wait")){
			string assistName = pStuCourse.query(courseList[i], 1)[0];
			if (!pCourse.queryHas(courseList[i], 7, assistName)){ 
				st.push_back(courseList[i]); 
				pStuCourse.edit(courseList[i], 1, "Wait");
			}
		}
	}
	return st;
}



pair<int, int> userStu::getProAndNonePro()
{
	return make_pair(max(0, 4 - proSum), max(0, 2 - nonProSum));
}

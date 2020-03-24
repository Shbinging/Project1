#include "databaseCurrentCourse.h"
#include"agori.h"
#include"ADEQ.h"

databaseCurrentCourse::databaseCurrentCourse()
{
	pathBase = "current_course.txt";
}

bool databaseCurrentCourse::isFileExsist(string path){
	ifstream fin(path);
	if (!fin.is_open()){
		return 0;
	}
	else{
		return 1;
		fin.close();
	}
}

int databaseCurrentCourse::readFromFile(string path)
{
	ifstream fin(path);
	if (!fin.is_open()){
		return 1;
	}
	int id, cap, sel;
	string name, tea, type;
	fin >> id >> name >> tea >> cap >> sel >> type;
	while (!fin.eof()){
		if (!pCourse.queryHasKey(to_string(id))){
			string stId = to_string(id);
			pCourse.addKey(stId);
			pCourse.add(stId, 1, name);
			pCourse.add(stId, 2, tea);
			pCourse.add(stId, 3, to_string(cap));
			pCourse.add(stId, 4, to_string(sel));
			pCourse.add(stId, 5, type);
		}
		fin >> id >> name >> tea >> cap >> sel >> type;
	}
	fin.close();
	writeToFile(pathBase);
	return 0;
}

bool databaseCurrentCourse::writeToFile(string path)
{
	ofstream fout(path);
	if (!fout.is_open()){
		return 1;
	}
	else{
		For(i, 0, int(pCourse.graph.size()) - 1){
			fout << str_toStringId(atoi(pCourse.graph[i][0][0])) << "\t" << pCourse.graph[i][1][0] << "\t" << pCourse.graph[i][2][0] << "\t" << pCourse.graph[i][3][0] << "\t" << pCourse.graph[i][4][0] << "\t" << pCourse.graph[i][5][0] << endl;
		}
		fout.close();
		return 0;
	}
}
/*
void databaseCurrentCourse::addCourse(CourseNode tmp)
{
	tmp.CourseId = ++courseSum;
	CourseList.push_back(tmp);
	writeToFile(pathBase);
}

void databaseCurrentCourse::delCourse(CourseNode tmp)
{
	For(i, 0, int(CourseList.size()) - 1){
		if (CourseList[i].CourseId == tmp.CourseId || CourseList[i].CourseName == tmp.CourseName){
			CourseList.erase(CourseList.begin() + i);
			break;
		}
	}
	writeToFile(pathBase);
}

void databaseCurrentCourse::editCourse(CourseNode tmp)
{
	For(i, 0, int(CourseList.size()) - 1){
		if (CourseList[i].CourseId == tmp.CourseId){
			if (tmp.CourseName != "")CourseList[i].CourseName = tmp.CourseName;
			if (tmp.CourseCap != -1) CourseList[i].CourseCap = tmp.CourseCap;
			if (tmp.CourseSel != -1) CourseList[i].CourseSel = tmp.CourseSel;
		}
	}
	writeToFile(pathBase);
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
	pathBase = "current_course.txt";
	readFromFile(pathBase);
	if (CourseList.empty()) courseSum = 0;
	else courseSum = CourseList[CourseList.size() - 1].CourseId;
}
*/
databaseCurrentCourse dataCourse;
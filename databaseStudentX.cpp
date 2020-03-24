#include "databaseStudentX.h"
#include"diag.h"
#include"agori.h"
#include"ADEQ.h"
int databaseStudentX::readFromFile()
{
	pStuCourse.clear();
	ifstream fin(pathBase);
	if (!fin.is_open()){
		return 1;
	}
	else{
		int id;
		string st;
		fin >> id >> st;
		while (!fin.eof()){
			string stId = to_string(id);
			if (!pStuCourse.queryHasKey(stId)){
				pStuCourse.addKey(stId);
				pStuCourse.add(stId, 1, st);
			}
			fin >> id >> st;
		}
		fin.close();
		return 0;
	}

}

bool databaseStudentX::writeToFile()
{
	ofstream fout(pathBase);
	if (!fout.is_open()){
		return 1;
	}
	else{
		For(i, 0, int(pStuCourse.graph.size()) - 1){
			fout << str_toStringId(atoi(pStuCourse.graph[i][0][0])) << "\t" << pStuCourse.graph[i][1][0] << endl;
		}
		fout.close();
		return 0;
	}
}
/*
vector<stuCourseNode>& databaseStudentX::getStuCourseList()
{
	return stuCourseList;
}

bool databaseStudentX::isCourseInStuCourseList(CourseNode tmp)
{
	For(i, 0, int(stuCourseList.size()) - 1){
		if (tmp.CourseId == stuCourseList[i].courseId) return 1;
	}
	return 0;
}

stuCourseNode databaseStudentX::getStuCourse(stuCourseNode tmp)
{
	For(i, 0, int(stuCourseList.size()) - 1){
		if (tmp.courseId == stuCourseList[i].courseId) return stuCourseList[i];
	}
}

void databaseStudentX::addStuCourse(stuCourseNode tmp)
{
	stuCourseList.push_back(tmp);
	writeToFile(pathBase);
}

void databaseStudentX::delStuCourse(stuCourseNode tmp)
{
	For(i, 0, int(stuCourseList.size()) - 1){
		if (tmp.courseId == stuCourseList[i].courseId){
			stuCourseList.erase(stuCourseList.begin() + i);
			break;
		}
	}
	writeToFile(pathBase);
}

void databaseStudentX::addAssistant(assistNode tmp)
{
	For(i, 0, int(stuCourseList.size()) - 1){
		if (tmp.courseId == stuCourseList[i].courseId) stuCourseList[i].assistant = tmp.list[0];
	}
	writeToFile(pathBase);
}

/*
bool databaseStudentX::isCourseAssistantFull(stuCourseNode tmp)
{
	For(i, 0, int(stuCourseList.size()) - 1){
		if (tmp.courseId == stuCourseList[i].courseId) return (!(stuCourseList[i].assistant == "Null"));
	}
}
*/

void databaseStudentX::setpath(string st){
	pathBase = st;
	readFromFile();
}

databaseStudentX dataStuX;
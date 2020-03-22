#include "databaseStudentX.h"
#include"diag.h"
#include"agori.h"
int databaseStudentX::readFromFile(string path)
{
	stuCourseList.clear();
	ifstream fin(path);
	if (!fin.is_open()){
		return 1;
	}
	else{
		int id;
		string st;
		while (!fin.eof()){
			fin >> id >> st;
			if (!stuCourseList.empty()){
				if (stuCourseList.back().courseId != id) stuCourseList.push_back(stuCourseNode(id, st));
			}
			else stuCourseList.push_back(stuCourseNode(id, st));
		}
		fin.close();
		return 0;
	}

}

bool databaseStudentX::writeToFile(string path)
{
	ofstream fout(path);
	if (!fout.is_open()){
		return 1;
	}
	else{
		For(i, 0, int(stuCourseList.size()) - 1){
			stuCourseNode tmp = stuCourseList[i];
			fout << str_toStringId(tmp.courseId) << "\t" << tmp.assistant << endl;
		}
		fout.close();
		return 0;
	}
}

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

bool databaseStudentX::isCourseAssistantFull(stuCourseNode tmp)
{
	For(i, 0, int(stuCourseList.size()) - 1){
		if (tmp.courseId == stuCourseList[i].courseId) return (!(stuCourseList[i].assistant == "Null"));
	}
}

void databaseStudentX::setpath(string st){
	pathBase = st;
	readFromFile(pathBase);
}

databaseStudentX dataStuX;
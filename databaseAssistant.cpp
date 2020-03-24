#include "databaseAssistant.h"
#include"agori.h"
#include"ADEQ.h"
int databaseAssistant::readFromFile(string path)
{
	ifstream fin(path);
	if (!fin.is_open()){
		return 1;
	}
	else{
		int id;
		string st;
		fin >> id >> st;
		while (!fin.eof()){
			vector<string> a = str_Split(st, ',');
			string stId = to_string(id);
			if (pCourse.graph[pCourse.findKey(stId)][7].empty()) pCourse.add(stId, 7, a);
			fin >> id >> st;
		}
		fin.close();
		return 0;
	}
}

bool databaseAssistant::writeToFile(string path)
{
	ofstream fout(path);
	if (!fout.is_open()){
		return 1;
	}
	else{
		For(i, 0, int(pCourse.graph.size()) - 1){
			if (!pCourse.graph[i][7].empty()){
				fout << str_toStringId(atoi(pCourse.graph[i][0][0])) << "\t";
				vector<string>& a = pCourse.query(pCourse.graph[i][0][0], 7);
				fout << a[0];
				For(j, 1, int(a.size()) - 1)
					fout << "," << a[j];
				fout << endl;
			}
		}
		fout.close();
		return 0;
	}
}

databaseAssistant dataAssi;
/*
bool databaseAssistant::isCourseInAssistList(assistNode tmp)
{
	For(i, 0, int(assistList.size()) - 1){
		assistNode& b = assistList[i];
		if (b.courseId == tmp.courseId){
			return 1;
		}
	}
	return 0;
}

databaseAssistant::databaseAssistant(){
	pathBase = "assistant.txt";
	readFromFile(pathBase);
}

int databaseAssistant::countAssistant(assistNode tmp){//统计一个人的当助教数目（初始化）
	int s = 0;
	For(i, 0, int(assistList.size()) - 1){
		assistNode& b = assistList[i];
		For(j, 0, int(b.list.size()) - 1){
			if (tmp.list[0] == b.list[j]){
				s++;
				break;
			}
		}
	}
	return s;
}

bool databaseAssistant::isStuInAssistList(assistNode tmp){
	For(i, 0, int(assistList.size()) - 1){
		assistNode& b = assistList[i];
		if (b.courseId == tmp.courseId){
			For(j, 0, int(b.list.size()) - 1){
				if (tmp.list[0] == b.list[j]) return 1;
			}
		}
	}
	return 0;
}

void databaseAssistant::addStuInAssistList(assistNode tmp){
	bool f = 0;
	For(i, 0, int(assistList.size()) - 1){
		assistNode& b = assistList[i];
		
		if (b.courseId == tmp.courseId){
			b.list.push_back(tmp.list[0]);
			f = 1;
		}
	}
	if (!f){
		assistList.push_back(tmp);
	}
	writeToFile(pathBase);
}

assistNode& databaseAssistant::getAssistNode(assistNode tmp){
	For(i, 0, int(assistList.size()) - 1){
		assistNode& b = assistList[i];
		if (b.courseId == tmp.courseId){
			assist = assistList[i];
			return assist;
			break;
		}
	}
}

void databaseAssistant::delCourseInAssistList(assistNode tmp){
	For(i, 0, int(assistList.size()) - 1){
		assistNode b = assistList[i];
		if (b.courseId == tmp.courseId){
			assistList.erase(assistList.begin() + i);
			break;
		}
	}
	writeToFile(pathBase);
}
*/

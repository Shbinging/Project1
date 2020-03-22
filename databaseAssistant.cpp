#include "databaseAssistant.h"
#include"agori.h"
int databaseAssistant::readFromFile(string path)
{
	assistList.clear();
	ifstream fin(path);
	if (!fin.is_open()){
		return 1;
	}
	else{
		int id;
		string st;
		while (!fin.eof()){
			fin >> id >> st;
			vector<string> a = str_Split(st, ',');
			assistNode tmp = assistNode(id);
			For(i, 0, int(a.size()) - 1){
				tmp.list.push_back(a[i]);
			}
			if (assistList.empty()) assistList.push_back(tmp);
			else if (assistList.back().courseId != id)
				assistList.push_back(tmp);
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
		For(i, 0, int(assistList.size()) - 1){
			assistNode& tmp = assistList[i];
			fout << str_toStringId(tmp.courseId) << "\t";
			fout << tmp.list[0];
			For(i, 1, int(tmp.list.size()) - 1)
				fout << "," << tmp.list[i];
			fout << endl;
		}
		fout.close();
		return 0;
	}
}

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

databaseAssistant dataAssi;
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

databaseCurrentCourse dataCourse;
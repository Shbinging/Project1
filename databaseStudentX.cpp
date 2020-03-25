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


void databaseStudentX::setpath(string st){
	pathBase = st;
	readFromFile();
}

databaseStudentX dataStuX;
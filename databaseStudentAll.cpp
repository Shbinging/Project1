#include "databaseStudentAll.h"
#include"diag.h"
#include"ADEQ.h"
#include"agori.h"
databaseStudentAll::databaseStudentAll(){
	pathBase = "student.txt";
}

int databaseStudentAll::readFromFile(string path){
	ifstream fin(path);
	if (!fin.is_open()){
		return 1;
	}
	else{
		string st;
		fin >> st;
		while (!fin.eof()){
			
			vector<string> a = str_Split(st, ',');
			if (!pStuPass.queryHasKey(a[0])){
				pStuPass.addKey(a[0]);
				
				pStuPass.add(a[0], 1, a[1]);
			}
			fin >> st;
		}
		fin.close();
		return 0;
	}
}

bool databaseStudentAll::writeToFile(string path)
{
	ofstream fout(path);
	if (!fout.is_open()){
		return 1;
	}
	else{
		For(i, 0, int(pStuPass.graph.size()) - 1){
			fout << pStuPass.graph[i][0][0] << "," << pStuPass.graph[i][1][0] << endl;
		}
		fout.close();
		return 0;
	}
}

databaseStudentAll dataStuAll;

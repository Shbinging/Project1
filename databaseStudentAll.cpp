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
/*
vector<stuWordNode>& databaseStudentAll::getStuWordList()
{
	return stuWordList;
}

bool databaseStudentAll::isStuInStuWordList(stuWordNode tmp)
{
	For(i, 0, int(stuWordList.size()) - 1){
		if (stuWordList[i].stuName == tmp.stuName) return 1;
	}
	return 0;
}

stuWordNode databaseStudentAll::getStuWord(stuWordNode tmp)
{
	For(i, 0, int(stuWordList.size()) - 1){
		if (stuWordList[i].stuName == tmp.stuName) return stuWordList[i];
	}
}

void databaseStudentAll::addStuWord(stuWordNode tmp)
{
	stuWordList.push_back(tmp);
	writeToFile(pathBase);
}
*/
databaseStudentAll dataStuAll;

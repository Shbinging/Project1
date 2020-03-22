#include "databaseStudentAll.h"
#include"diag.h"
#include"agori.h"
databaseStudentAll::databaseStudentAll(){
	pathBase = "student.txt";
	readFromFile(pathBase);
	
}

int databaseStudentAll::readFromFile(string path){
	stuWordList.clear();
	ifstream fin(path);
	if (!fin.is_open()){
		return 1;
	}
	else{
		string st;
		
		while (!fin.eof()){
			fin >> st;
			vector<string> a = str_Split(st, ',');
			if (stuWordList.empty()) stuWordList.push_back(stuWordNode(a[0], a[1]));
			else{
				if (stuWordList.back().stuName != a[1])
					stuWordList.push_back(stuWordNode(a[0], a[1]));
			}
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
		For(i, 0, int(stuWordList.size()) - 1){
			stuWordNode tmp = stuWordList[i];
			fout << tmp.stuName << "," << tmp.stuPassword << endl;
		}
		fout.close();
		return 0;
	}
}

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

databaseStudentAll dataStuAll;
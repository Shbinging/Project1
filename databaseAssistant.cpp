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
			For(i, 0, int(a.size()) - 1){
				string key = stId + a[i];
				if (!pAssistMem.queryHasKey(key)) pAssistMem.addKey(key);
			}
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

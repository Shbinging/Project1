#include"agori.h"
#include"diag.h"

vector<string> str_Split(string st, char cha){
	vector<string> a;
	a.clear();
	st += cha;
	string str = "";
	For(i, 0, int(st.length()) - 1){
		if (st[i] != cha){
			str += st[i];
		}
		else{
			a.push_back(str);
			str = "";
		}
	}
	return a;
}


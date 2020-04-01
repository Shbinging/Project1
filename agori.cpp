#include"agori.h"
#include"diag.h"

vector<string> str_Split(string st, char cha){
	vector<string> a;
	st += cha;
	string str;
	str.clear();
	For(i, 0, int(st.length()) - 1){
		if (st[i] != cha){
			str += st[i];
		}
		else{
			string s;
			s.push_back(cha);
			if (st != s) a.push_back(str);
			str.clear();
		}
	}
	return a;
}

string str_toStringId(int tmp){
	string id = to_string(tmp);
	if (id.length() == 1) id = "00" + id;
	else if (id.length() == 2) id = "0" + id;
	return id;
}
bool str_isNum(string tmp){
	For(i, 0, int(tmp.length()) - 1){
		if (tmp[i] < '0' || tmp[i] > '9') return 0;
	}
	return 1;
}

int atoi(string st){
	int s = 0;
	For(i, 0, int(st.length()) - 1){
		if (st[i] < '0' || st[i]>'9') return -1;
		else s = s * 10 + st[i] - '0';
	}
	return s;
}
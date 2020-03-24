#pragma once
#include"diag.h"
class ADEQ
{
public:
	ADEQ(int l);//����
	vector<vector<vector<string>>> graph;
	vector<string> KeyList;
	void clear();

	int findKey(string key, int opt = 0);
	void addKey(string key);
	void add(string key, int opt, string word, int change = 0);//Ĭ��������Ϊkey
	void add(string key, int opt, vector<string> word, int change = 0);

	void delKey(string key);
	void del(string key, int opt, string word, int change = 0);

	void editKey(string key, string newKey);
	void edit(string key, int opt, string newWord, int change = 0);

	bool queryHasKey(string key, int change = 0);
	bool queryHas(string key, int opt, string word, int change = 0);//Null��ѯ������������Ԫ���Ƿ����
	string queryLastKey();
	vector<string>& query(string key, int opt, int change = 0);
	vector<string>& queryKeyList();
	//0 1
private:
	int L;//��������
};

extern ADEQ pCourse;
extern ADEQ pStuCourse;
extern ADEQ pStuPass;

extern enum  {StuName, Password} lStuPass;
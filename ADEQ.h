#pragma once
#include"diag.h"
class ADEQ
{
public:
	vector<vector<vector<string>>> graph;
	int findKey(string key);
	void addKey(string key);
	void add(string key, int opt, string word);//key ���� ����

	
	void delKey(string key);
	void del(string key, int opt, string word);

	void editKey(string key, string newKey);
	void edit(string key, int opt, string newWord);//�ı䵥����

	bool queryHasKey(string key);//0 1
	bool queryHas(string key, int opt, string word);
	vector<string>& query(string key, int opt);
};
#include "ADEQ.h"

ADEQ::ADEQ(int l):L(l)
{
	KeyList.clear();
	graph.clear();
}

void ADEQ::clear(){
	KeyList.clear();
	graph.clear();
}
int ADEQ::findKey(string key, int opt){
	For(i, 0, int(graph.size()) - 1){
		if (graph[i][opt][0] == key) return i;
	}
	return -1;
}

void ADEQ::addKey(string key)
{
	vector<string> a;
	vector<vector<string>> b;
	a.push_back(key);
	b.push_back(a);
	graph.push_back(b);
	For(j, 1, L){
		vector<string> c;
		c.clear();
		graph[graph.size() - 1].push_back(c);
	}
}

void ADEQ::add(string key, int opt, string word, int change)
{
	int loc = findKey(key, change);
	graph[loc][opt].push_back(word);
}

void ADEQ::add(string key, int opt, vector<string> word, int change)
{
	int loc = findKey(key, change);
	graph[loc][opt].assign(word.begin(), word.end());
}

void ADEQ::delKey(string key)
{
	int loc = findKey(key);
	graph.erase(graph.begin() + loc);
}

void ADEQ::del(string key, int opt, string word, int change)
{
	int loc = findKey(key, change);
	graph[loc][opt].erase(remove(graph[loc][opt].begin(), graph[loc][opt].end(), word), graph[loc][opt].end());
}

void ADEQ::editKey(string key, string newKey)
{
	int loc = findKey(key);
	graph[loc][0][0] = newKey;
}

void ADEQ::edit(string key, int opt, string newWord, int change)
{
	int loc = findKey(key, change);
	graph[loc][opt][0] = newWord;
}

bool ADEQ::queryHasKey(string key, int change)
{
	int loc = findKey(key, change);
	if (loc == -1) return 0;
	else return 1;
}

bool ADEQ::queryHas(string key, int opt, string word, int change)
{
	int loc = findKey(key, change);
	if (word == "NULL" && graph[loc][opt].empty()) return 1;
	For(i, 0, int(graph[loc][opt].size()) - 1){
		if (graph[loc][opt][i] == word) return 1;
	}
	return 0;
}

string ADEQ::queryLastKey()
{
	if (!graph.empty()) return graph[graph.size() - 1][0][0];
}

vector<string>& ADEQ::query(string key, int opt, int change)
{
	int loc = findKey(key, change);
	return graph[loc][opt];
}

vector<string>& ADEQ::queryKeyList()
{
	KeyList.clear();
	For(i, 0, int(graph.size()) - 1)
		KeyList.push_back(graph[i][0][0]);
	return KeyList;
}

ADEQ pCourse(8);
ADEQ pStuCourse(2);
ADEQ pStuPass(2);

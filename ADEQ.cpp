#include "ADEQ.h"

int ADEQ::findKey(string key){
	For(i, 0, int(graph.size()) - 1){
		if (graph[i][0][0] == key) return i;
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
}

void ADEQ::add(string key, int opt, string word)
{
	int loc = findKey(key);
	graph[loc][opt].push_back(word);
}

void ADEQ::delKey(string key)
{
	int loc = findKey(key);
	graph.erase(graph.begin() + loc);
}

void ADEQ::del(string key, int opt, string word)
{
	int loc = findKey(key);
	graph[loc][opt].erase(remove(graph[loc][opt].begin(), graph[loc][opt].end(), word), graph[loc][opt].end());
}

void ADEQ::editKey(string key, string newKey)
{
	int loc = findKey(key);
	graph[loc][0][0] = newKey;
}

void ADEQ::edit(string key, int opt, string newWord)
{
	int loc = findKey(key);
	graph[loc][opt][0] = newWord;
}

bool ADEQ::queryHasKey(string key)
{
	int loc = findKey(key);
	if (loc == -1) return 0;
	else return 1;
}

bool ADEQ::queryHas(string key, int opt, string word)
{
	int loc = findKey(key);
	For(i, 0, int(graph[loc][opt].size()) - 1){
		if (graph[loc][opt][i] == word) return 1;
	}
	return 0;
}

vector<string>& ADEQ::query(string key, int opt)
{
	int loc = findKey(key);
	return graph[loc][opt];
}

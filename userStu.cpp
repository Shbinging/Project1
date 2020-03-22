#include "userStu.h"
#include"diag.h"
bool userStu::checkpassword(string name, string password)
{
	if (!dataStuAll.isStuInStuWordList(stuWordNode(name))) return 0;
	stuWordNode tmp = dataStuAll.getStuWord(stuWordNode(name));
	if (password == tmp.stuPassword) return 1;
	else return 0;
}

bool userStu::isStuWordInList(stuWordNode tmp)
{
	return dataStuAll.isStuInStuWordList(tmp);
}

void userStu::addStuWord(string name, string password)
{
	dataStuAll.addStuWord(stuWordNode(name, password));
}

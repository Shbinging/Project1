#include "databaseCourseAll.h"


databaseCourseAll::databaseCourseAll()
{
	courseStuList.clear();
}

void databaseCourseAll::init()
{
	vector<CourseNode>& courseIdList = dataCourse.getCourseList();
	int n = int(courseIdList.size()) - 1;
	For(i, 0, n) addCourseXInGraph(courseIdList[i].CourseId);
	vector<stuWordNode>& stuNameList = dataStuAll.getStuWordList();
	For(i, 0, int(stuNameList.size()) - 1){
		dataStuX.setpath(stuNameList[i].stuName + ".txt");
		vector<stuCourseNode>& stuCourseList = dataStuX.getStuCourseList();
		For(j, 0, int(stuCourseList.size()) - 1){
			addStuInCourseX(stuCourseList[j].courseId, stuNameList[i].stuName);
		}
	}
	/*For(i, 0, len() - 1){
		if (!courseStuList[i].list.empty())
			cout << courseStuList[i].courseId << " " << courseStuList[i].list[0] <<endl;
	}*/
}
void databaseCourseAll::addStuInCourseX(int id, string name)
{
	int n = len();
	int loc = findCourseXInGraph(id);
	courseStuList[loc].list.push_back(name);
}

int databaseCourseAll::len(){
	return int(courseStuList.size());
}

pair<int, int> databaseCourseAll::findStuInCourseX(int id, string name)
{
	int x = findCourseXInGraph(id);
	if (x == -1) return make_pair(-1, -1);
	else{
		For(j, 0, int(courseStuList[x].list.size()) - 1){
			if (courseStuList[x].list[j] == name)
				return make_pair(x, j);
		}
		return make_pair(-1, -1);
	}
}

bool databaseCourseAll::isStuInCourseX(int id, string name)
{
	if (findStuInCourseX(id, name) == make_pair(-1, -1)) return 0;
	else return 1;
}

void databaseCourseAll::delStuInCourseX(int id, string name)
{
	pair<int, int> loc = findStuInCourseX(id, name);
	courseStuList[loc.first].list.erase(courseStuList[loc.first].list.begin() + loc.second);
}

courseStuNode& databaseCourseAll::getListInCourseX(int id)
{
	int loc = findCourseXInGraph(id);
	courseStuListNode = courseStuList[loc];
	return courseStuListNode;
}

void databaseCourseAll::addCourseXInGraph(int id)
{
	courseStuList.push_back(courseStuNode(id));
}

int databaseCourseAll::findCourseXInGraph(int id)
{
	int n = len();
	For(i, 0, n - 1){
		if (courseStuList[i].courseId == id){
			return i;
		}
	}
	return -1;
}

bool databaseCourseAll::isCourseXInGraph(int id)
{
	int loc = findCourseXInGraph(id);
	if (loc == -1) return 0;
	else return 1;
}

void databaseCourseAll::delCourseXInGraph(int id)
{
	int loc = findCourseXInGraph(id);
	courseStuList.erase(courseStuList.begin() + loc);
}
databaseCourseAll dataCourseStu;
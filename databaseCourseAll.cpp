#include "databaseCourseAll.h"
#include"ADEQ.h"

void databaseCourseAll::init()
{
	For(i, 0, int(pStuPass.graph.size()) - 1){
		string stuName = pStuPass.graph[i][0][0];
		dataStuX.setpath(stuName + ".txt");
		For(j, 0, int(pStuCourse.graph.size()) - 1){
			pCourse.add(pStuCourse.graph[j][0][0], 6, stuName);
		}
	}
}

databaseCourseAll dataCourseStu;
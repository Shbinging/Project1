#include"ui.h"
#include"diag.h"
int CourseSum = 0;//这两个变量应该在baseCourse的文件中定义
vector<CourseNode>CourseList;
int main(){
	UI* a = new UI;
	a->cmdUi();
	return 0;
}
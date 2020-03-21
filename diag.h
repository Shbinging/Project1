#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<vector>

#define For(i, l, r) for(int i = l; i <= r; i++)
using namespace std;

extern int CourseSum;

struct CourseNode{
	// id name teacher cap sel type
	CourseNode(string name, string teacher, int cap, bool type){
		CourseId = ++CourseSum;
		CourseType = type;
		CourseName = name;
		CourseTeacher = teacher;
		CourseCap = cap;
		CourseSel = 0;
	}
	int CourseId, CourseCap, CourseSel;
	string CourseName, CourseTeacher;
	bool CourseType;//0专业课 1非专业课
};

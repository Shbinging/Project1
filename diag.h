#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<fstream>
#include <utility>

#define DEBUG
#define testUi
//#define DEBUG

#define For(i, l, r) for(int i = l; i <= r; i++)
using namespace std;

struct CourseNode{
	CourseNode(){
		CourseId = 0;
		CourseName = "";
		CourseTeacher = "";
		CourseCap = -1;
		CourseSel = -1;
		CourseType = -1;
	}
	CourseNode(int id){
		CourseId = id;
		CourseName = "";
		CourseTeacher = "";
		CourseCap = -1;
		CourseSel = -1;
		CourseType = -1;
	}
	CourseNode(string name){
		CourseName = name;
		CourseId = 0;
		CourseTeacher = "";
		CourseCap = -1;
		CourseSel = -1;
		CourseType = -1;
	}
	// id name teacher cap sel type
	CourseNode(string name, string teacher, int cap, int sel, string type, int id = 0){
		CourseId = id;
		CourseName = name;
		CourseTeacher = teacher;
		CourseCap = cap;
		CourseSel = sel;
		if (type == "专业课") CourseType = 0;
		else CourseType = 1;
	}
	int CourseId, CourseCap, CourseSel, CourseType;//0专业课 1非专业课
	string CourseName, CourseTeacher;
};
//extern vector<CourseNode>CourseList;

struct stuWordNode{
	stuWordNode(string name, string password=""){
		stuName = name;
		stuPassword = password;
	}
	string stuName, stuPassword;
};

struct stuCourseNode{
	stuCourseNode(int id, string st = "Null"){
		courseId = id;
		assistant = st;
	}
	int courseId;
	string assistant;
};

struct assistNode{
	assistNode(){
		courseId = 0;
		if (!list.empty()) list.clear();
	}
	assistNode(int id, string st){
		courseId = id;
		if (!list.empty()) list.clear();
		list.push_back(st);
}
	assistNode(string st){
		courseId = 0;
		if (!list.empty()) list.clear();
		list.push_back(st);
	}
	assistNode(int id){
		courseId = id;
		if (!list.empty()) list.clear();
	}
	assistNode(const assistNode& tmp){
		courseId = tmp.courseId;
		list.assign(tmp.list.begin(), tmp.list.end());
	}
	int courseId;
	vector<string> list;
};

struct courseStuNode{
	courseStuNode(){
		courseId = -1;
		list.clear();
	}
	courseStuNode(int id){
		list.clear();
		courseId = id;
	}
	courseStuNode(int id, string st){
		courseId = id;
		list.clear();
		list.push_back(st);
	}
	courseStuNode(const courseStuNode& tmp){
		courseId = tmp.courseId;
		list.assign(tmp.list.begin(), tmp.list.end());
	}
	int courseId;
	vector<string> list;
};
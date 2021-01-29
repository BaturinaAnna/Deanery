#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;

class Group;
class Student
{
private:
	int id;
	string fio;
	Group* group;
	vector<int>marks;

public:
	Student(int, string);
	string get_fio();
	int get_id();
	vector<int> get_marks();
	Group* get_group();
	void set_group(Group*);
	void set_mark(int);
	float average_mark();
};

#endif

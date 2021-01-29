#ifndef GROUP_H
#define GROUP_H

#include "Student.h"
#include <vector>
#include <string>
using namespace std;

class Group
{
private:
	string title;
	string spec;
	vector<Student*> students;
	Student* head;

public:
	Group(string, string);
	void add_student(Student*);
	void election_head();
	Student* find_student_fio(string);
	Student* find_student_id(int);
	vector<Student*> get_students();
	float average_mark();
	void delete_student(Student*);
	string get_title();
	Student* get_head();
	string get_spec();
};

#endif
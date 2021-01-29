#ifndef DEANERY_H
#define DEANERY_H

#include "Group.h"

class Deanery
{
private:
	vector<Group*> groups;

public:
	void make_student(int, string, Group*);
	Group* make_group(string, string);
	void add_mark(Group *, string, int);
	float get_average_mark_student(Group *, string);
	float get_average_mark_group(Group*);
	void change_group_for_student(string, Group*, Group*);
	void poor_grades(Group*);
	void save_new_data();
	void make_head(Group*);
	void print_data();
};

#endif

#include "Group.h"
#include <random>

Group::Group(string group_title, string specialization)
{
	title = group_title;
	spec = specialization;

}

void Group::add_student(Student* new_student)
{
	students.push_back(new_student);
}

void Group::election_head()
{
	int i = rand() % students.size();
	head = students[i];
}


Student* Group::find_student_fio(string student_fio)
{
	for (auto stud : students)
	{
		if (stud->get_fio() == student_fio)
			return stud;
	}
}

Student* Group::find_student_id(int student_id)
{
	for (auto stud : students)
	{
		if (stud->get_id() == student_id)
			return stud;
	}
}

float Group::average_mark()
{
	float sum = 0;
	for (auto stud : students)
		sum += stud->average_mark();
	return sum / students.size();
}


void Group::delete_student(Student* student)
{
	int i, j;
	i = 0;
	j = -1;
	for (auto stud : students)
	{
		i++;
		if (stud == student)
			j = i;
	}
	students.erase(students.begin() + j - 1);
}

string Group::get_title()
{
	return title;
}

vector<Student*> Group::get_students()
{
	return students;
}


Student * Group::get_head()
{
	return head;
}

string Group::get_spec()
{
	return spec;
}
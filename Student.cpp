#include "Student.h"

Student::Student(int personal_id, string student_fio)
{
	id = personal_id;
	fio = student_fio;
}

void Student::set_mark(int mark)
{
	marks.push_back(mark);
}

float Student::average_mark()
{
	float sum = 0;
	for (auto i : marks)
		sum += i;
	return sum / marks.size();
}


string Student::get_fio()
{
	return fio;
}

int Student::get_id()
{
	return id;
}

void Student::set_group(Group* gr)
{
	group = gr;
}


Group* Student::get_group()
{
	return group;
}


vector<int> Student::get_marks()
{
	return marks;
}
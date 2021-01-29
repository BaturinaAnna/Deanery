#include "Deanery.h"
#include <fstream>
#include <iostream>
#include <sstream>

void Deanery::make_student(int id_stud, string name, Group* group)
{
	Student *stud = new Student(id_stud, name);
	group->add_student(stud);
}


Group* Deanery::make_group(string name, string specialization)
{
	Group* new_group = new Group(name, specialization);
	groups.push_back(new_group);
	return new_group;
}


void Deanery::add_mark(Group * gr, string stud, int mark)
{
	Student* st = gr->find_student_fio(stud);
	st->set_mark(mark);
}

float Deanery::get_average_mark_student(Group* gr, string stud)
{
	Student* st = gr->find_student_fio(stud);
	return st->average_mark();
}

float Deanery::get_average_mark_group(Group* group)
{
	return group->average_mark();
}

void Deanery::change_group_for_student(string st, Group* prev_gr, Group * new_gr)
{
	Student* stud = prev_gr->find_student_fio(st);
	prev_gr->delete_student(stud);
	stud->set_group(new_gr);
	new_gr->add_student(stud);
}

void Deanery::poor_grades(Group* group)
{
	for (auto stud : group->get_students())
	{
		if (stud->average_mark() < 4.0)
			group->delete_student(stud);
	}
}

void Deanery::save_new_data()
{
	ofstream file("Deanery.txt");
	for (auto group : groups)
	{
		file << "SPECIALIZATION:  " << group->get_spec() << endl;
		file << "TITLE:  " << group->get_title() << endl;
		file << "STUDENTS: " << endl;
		file << "HEAD:  " << (group->get_head())->get_fio() << endl;
		file << "------------------------------------------" << endl;
		for (auto stud : group->get_students())
		{
			file << "	ID:  " << stud->get_id() << endl;
			file << "	FIO:  " << stud->get_fio() << endl;
			file << "	AVERAGE MARK:  " << stud->average_mark() << endl;
			file << "	MARKS:  ";
			for (auto mark : stud->get_marks())
				file << mark << " ";
			file << endl;
			file << "------------------------------------------" << endl;
		}
		file << "====================================" << endl;
	}
}

void Deanery::make_head(Group* group)
{
	group->election_head();
}

void Deanery::print_data()
{
	for (auto group : groups)
	{
		cout << "SPECIALIZATION:  " << group->get_spec() << endl;
		cout << "TITLE:  " << group->get_title() << endl;
		cout << "STUDENTS: " << endl;
		cout << "HEAD:  " << (group->get_head())->get_fio() << endl;
		cout << "------------------------------------------" << endl;
		for (auto stud : group->get_students())
		{
			cout << "	ID:  " << stud->get_id() << endl;
			cout << "	FIO:  " << stud->get_fio() << endl;
			cout << "	AVERAGE MARK:  " << stud->average_mark() << endl;
			cout << "	MARKS:  ";
			for (auto mark : stud->get_marks())
				cout << mark << " ";
			cout << endl;
			cout << "------------------------------------------" << endl;
		}
		cout << "====================================" << endl;
	}
}
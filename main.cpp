#include "Deanery.h"
#include "Group.h"
#include "Student.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string& s, char delimiter)
{
	vector<string> Tokens;
	string Token;
	istringstream TokenStream(s);
	while (getline(TokenStream, Token, delimiter))
		Tokens.push_back(Token);
	return Tokens;
}

int main()
{
	system("chcp 1251");

	Deanery HSE;

	Group* PMI1 = HSE.make_group("20-PMI-1", "Прикладная математика и информатика");
	Group* PMI2 = HSE.make_group("20-PMI-2", "Прикладная математика и информатика");
	Group* PI1 = HSE.make_group("20-PI-1", "Программная инженерия");
	Group* PI2 = HSE.make_group("20-PI-2", "Программная инженерия");
	Group* BI1 = HSE.make_group("20-BI-1", "Бизнес-информатика");
	Group* BI2 = HSE.make_group("20-BI-2", "Бизнес-информатика");
	Group* FM1 = HSE.make_group("20-FM-1", "Фундаментальная математика");
	Group* FM2 = HSE.make_group("20-FM-2", "Фундаментальная математика");	

	ifstream file("students_with_groups.txt");

	int id = 1, j;
	while (!file.eof())
	{
		string buf;
		getline(file, buf, '\n');
		vector<string> data = split(buf, ':');
		if (data[1] == "20-PMI-1")
		{
			HSE.make_student(id, data[0], PMI1);
			for (int i = 0; i < 10; i++)
				HSE.add_mark(PMI1, data[0], rand() % 10);
		}
		if (data[1] == "20-PMI-2")
		{
			HSE.make_student(id, data[0], PMI2);
			for (int i = 0; i < 10; i++)
				HSE.add_mark(PMI2, data[0], rand() % 10);
		}
		if (data[1] == "20-PI-1")
		{
			HSE.make_student(id, data[0], PI1);
			for (int i = 0; i < 10; i++)
				HSE.add_mark(PI1, data[0], rand() % 10);
		}
		if (data[1] == "20-PI-2")
		{
			HSE.make_student(id, data[0], PI2);
			for (int i = 0; i < 10; i++)
				HSE.add_mark(PI2, data[0], rand() % 10);
		}
		if (data[1] == "20-BI-1")
		{
			HSE.make_student(id, data[0], BI1);
			for (int i = 0; i < 10; i++)
				HSE.add_mark(BI1, data[0], rand() % 10);
		}
		if (data[1] == "20-BI-2")
		{
			HSE.make_student(id, data[0], BI2);
			for (int i = 0; i < 10; i++)
				HSE.add_mark(BI2, data[0], rand() % 10);
		}
		if (data[1] == "20-FM-1")
		{
			HSE.make_student(id, data[0], FM1);
			for (int i = 0; i < 10; i++)
				HSE.add_mark(FM1, data[0], rand() % 10);
		}
		if (data[1] == "20-FM-2")
		{
			HSE.make_student(id, data[0], FM2);
			for (int i = 0; i < 10; i++)
				HSE.add_mark(FM2, data[0], rand() % 10);
		}
		id += 1;
	}

	// set heads
	HSE.make_head(PMI1);
	HSE.make_head(PMI2);
	HSE.make_head(PI1);
	HSE.make_head(PI2);
	HSE.make_head(BI1);
	HSE.make_head(BI2);
	HSE.make_head(FM1);
	HSE.make_head(FM2);

	cout << HSE.get_average_mark_student(PMI1, "Клемент Лукьян Натанович") << endl;
	cout << HSE.get_average_mark_student(PMI2, "Холопов Авдей Брониславович") << endl;
	cout << HSE.get_average_mark_student(PI1, "Ягофаров Игорь Остапович") << endl;
	cout << HSE.get_average_mark_student(PI2, "Корнейчук Евгения Евгениевна") << endl;

	cout << HSE.get_average_mark_group(PMI1) << endl;
	cout << HSE.get_average_mark_group(PMI2) << endl;
	cout << HSE.get_average_mark_group(PI1) << endl;
	cout << HSE.get_average_mark_group(PI2) << endl;
	cout << HSE.get_average_mark_group(BI1) << endl;
	cout << HSE.get_average_mark_group(BI2) << endl;
	cout << HSE.get_average_mark_group(FM1) << endl;
	cout << HSE.get_average_mark_group(FM2) << endl;

	HSE.change_group_for_student("Корнейчук Евгения Евгениевна", PI2, FM1);

	HSE.poor_grades(PMI1);
	HSE.poor_grades(PMI2);
	HSE.poor_grades(PI1);
	HSE.poor_grades(PI2);
	HSE.poor_grades(BI1);
	HSE.poor_grades(BI2);
	HSE.poor_grades(FM1);
	HSE.poor_grades(FM2);
	
	//print in console and save in file
	HSE.print_data();
	HSE.save_new_data();

	return 0;
}
		







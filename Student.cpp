// Student.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class MOG {
	string subject;
	int grade;
public:
	void set_subject(string subject)
	{
		this->subject = subject;
	}
	string get_subject()
	{
		return this->subject;
	}

	void set_grade(int grade)
	{
		this->grade = grade;
	}
	int get_grade()
	{
		return this->grade;
	}
};

class PersonalData {
	string passportId;
	string socialId;
	string address;
	string phone;
	string birthday;

public:
	PersonalData(string ps, string sc, string ad, string ph, string bd)
	{
		passportId = ps;
		socialId = sc;
		address = ad;
		phone = ph;
		birthday = bd;
	}
};

class Payment {
	
public:
	string* xerox_of_receipts;

	Payment() { xerox_of_receipts = new string[4]; }
	~Payment() { delete[] xerox_of_receipts; }
};

class Student {
	string name;
	string surname;
	string patronymic;

	string year_of_addmission;
	PersonalData* pers_data;
	MOG* mogs;
	bool free_or_payed; // true = free, false = payed
	Payment payment;

public:
	Student() {};
	Student(string n, string sn, string pn, bool fp, string yoa, string ps, string sc, string ad, string ph, string bd)
	{
		this->name = n;
		this->surname = sn;
		this->patronymic = pn;
		this->year_of_addmission = yoa;
		this->free_or_payed = fp;

		this->mogs = new MOG[25];
		this->pers_data = new PersonalData(ps, sc, ad, ph, bd);
	}
	~Student()
	{
		delete[] mogs;
		delete pers_data;
	}
	
	void change_MOG(string subject, int grade)
	{
		for (int i = 0; i < 25; i++)
		{
			if (mogs[i].get_subject() == subject)
				mogs[i].set_grade(grade);
		}
	}

	void set_free_or_payed(bool fop)
	{
		this->free_or_payed = fop;
	}
	bool get_free_or_payed()
	{
		return this->free_or_payed;
	}

};

int main()
{
	Student student;
	return 0;
}


#pragma once

#include "bibliotekos.h"

class Studentas {
private:
	deque<int> balai;
public:
	string pavarde;
	string vardas;
	double egzaminas;

	Studentas();
	Studentas(string, string, deque<int>, double);
	Studentas(const Studentas& p1);
	~Studentas();
	double GetFinal();
	int Menu();
	void DeleteGrades();
	void PrintMedian();
	void PrintFile();
	friend istream& operator >>(istream& input, Studentas& x);
	friend ostream& operator <<(ostream& output, const Studentas& x);
};


int wordnum(string);

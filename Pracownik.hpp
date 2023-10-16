#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include<iostream>
#include <string>
#include "RandomNameGenerator.hpp"

using namespace std;


class Pracownik {
public:
	Pracownik():wynagrodzenie(0) {
		imie = get_random_name();
	};
	virtual ~Pracownik() {};

	string getImie() { return imie; };
	double getWynagrodzenie() { return wynagrodzenie; };
	void setWynagrodzenie(double w) { wynagrodzenie = w; };
	virtual void print() = 0;// { cout << "Pracownik: " << getImie() << " zarabia " << getWynagrodzenie() << endl; };

protected:
	string imie;
	double wynagrodzenie;

};




#endif 
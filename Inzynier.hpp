#ifndef INZYNIER_H
#define INZYNIER_H

#include<iostream>
#include<string>
#include"Pracownik.hpp"
#include"RandomWydzialGenerator.hpp"
using namespace std;


double CI = 300.0;
class Inzynier:public Pracownik
{
public:
	Inzynier(){
		wydzial = get_random_wydzial();
		wynagrodzenie = 6000.0;		
	};
	virtual ~Inzynier() {};
	const static double CI;
	

	void setWydzial(string w) { wydzial = w; };
	string getWydzial() { return wydzial; };
	virtual void print() {
		cout << "Inzynier: " << getImie() << " skonczyl Wydzial " << getWydzial() << " i zarabia " << getWynagrodzenie()<<"." << endl;
	};
private:
	string wydzial;
};

#endif
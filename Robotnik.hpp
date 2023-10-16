#ifndef ROBOTNIK_H
#define ROBOTNIK_H

#include<iostream>
#include<string>
#include <stdlib.h> // niezbêdne dla funkcji srand i rand
#include <time.h> // niezbêdne dla funkcji time

#include"Pracownik.hpp"
using namespace std;

int CR = 3;


class Robotnik :public Pracownik
{
public:
	Robotnik() {
		
		but = (rand() % 10) + 35;
		wynagrodzenie = 3000;
	};
	virtual ~Robotnik() {};
	static int CR;
	

	void setBut(double w) { but = w; };
	double getBut() { return but; };
	virtual void print() {
		cout << "Robotnik: " << getImie() << " o rozmiarze buta " << getBut() << " i zarabia " << getWynagrodzenie()<<"." << endl;
	};
private:
	double but;
};

#endif
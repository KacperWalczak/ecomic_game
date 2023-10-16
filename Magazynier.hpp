#ifndef MAGAZYNIER_H
#define MAGAZYNIER_H

#include<iostream>
#include<string>
#include <stdlib.h> // niezbêdne dla funkcji srand i rand
#include <time.h> // niezbêdne dla funkcji time
#include"Pracownik.hpp"
using namespace std;


int CMag = 3;

class Magazynier :public Pracownik
{
public:
	Magazynier() {
		
		wozek = (rand() % 2);
		wynagrodzenie = 4000;
	};
	virtual ~Magazynier() {};
	static int CMag;
	

	void setWozek(bool w) { wozek = w; };
	bool getWozek() { return wozek; };
	virtual void print() {
		cout << "Magazynier: " << getImie() << (wozek ? " obsluguje wozek i":" nie obsluguje wozka i") << " zarabia " << getWynagrodzenie()<<"." << endl;
	};
private:
	bool wozek;
};

#endif
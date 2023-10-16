#ifndef MARKETER_H
#define MARKETER_H

#include<iostream>
#include<string>
#include <stdlib.h> // niezbêdne dla funkcji srand i rand
#include <time.h> // niezbêdne dla funkcji time
#include"Pracownik.hpp"
using namespace std;


int CMkt = 3;

class Marketer :public Pracownik
{
public:
	Marketer() {
		
		followers = (rand() % 500000) + 100000;;
		wynagrodzenie = 5000;
	};
	virtual ~Marketer() {};
	const static int CMkt;
	

	void setFollowers(int w) { followers = w; };
	int getFollowers() { return followers; };
	virtual void print() {
		cout << "Marketer: " << getImie() << " ma "<<getFollowers() << " followersow i zarabia " << getWynagrodzenie()<<"." << endl;
	};
private:
	int followers;
};

#endif
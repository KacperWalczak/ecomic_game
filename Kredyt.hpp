#ifndef KREDYT_H
#define KREDYT_H

#include<iostream>

using namespace std;
int X=12;


class Kredyt {
public:
	Kredyt() {};
	Kredyt(double kwota, int i) :pozostaleRaty(i) {
		dlug = kwota + kwota * oprocentowanie * (double)pozostaleRaty;
		rata = dlug / (double)pozostaleRaty;
		cout << "Zaciagniety zostal kredyt na kwote " << kwota << ". Kwota do splaty wynosi: " << dlug <<". Ilosc rat wynosi: "<<pozostaleRaty<<"." << endl;
		cout << endl;
	};
	~Kredyt() {};

	static int X;

	int getPozostaleRaty() { return pozostaleRaty; };
	int getMaksRat() { return X; };
	void setPozostaleRaty(int w) { pozostaleRaty = w; };
	double getRata() { return rata; };
	double getDlug() { return dlug; };
	void splacRate() {
		pozostaleRaty--;
		dlug -= rata;
	};

private:
	int pozostaleRaty;
	double dlug;
	double rata;
	double oprocentowanie=0.01;
};

#endif
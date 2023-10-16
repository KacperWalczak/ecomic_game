#ifndef FIRMA_H
#define FIRMA_H

#include <iostream>
#include "Pracownik.hpp"
#include "Inzynier.hpp"
#include "Magazynier.hpp"
#include "Marketer.hpp"
#include "Robotnik.hpp"
#include "Kredyt.hpp"

using namespace std;

double M = 2.0;


class Firma {
public:
	Firma() {
		pracownicy.push_back(new Inzynier());
		pracownicy.push_back(new Magazynier());
		pracownicy.push_back(new Marketer());
		pracownicy.push_back(new Robotnik());
		stanKonta = 300000.0;
		//cout << "Pracownicy poczatkwoi zatrudnieni!" << endl;
	};
	~Firma() {
		for (int i = 0; i < pracownicy.size(); ++i) {
			delete pracownicy[i];
			//cout << "Pracownik skasowany destruktorem!" << endl;
		};
	};
	
	static double M;
	double	getStanKonta () const { return stanKonta; };
	void	setStanKonta (double w) { stanKonta = w; };
	double	zaplacWynagrodzenia() {
		double wynagrodzenia=0;
		for (int i = 0; i < pracownicy.size(); ++i) {
			wynagrodzenia += pracownicy[i]->getWynagrodzenie();
		};
		//cout << "Zaplacono wynagrodzenia!" << endl;
		return wynagrodzenia;
	};
	void drukujPracownikow() {
		cout << "Lista zatrudnionych pracownikow:" << endl;
		for (int i = 0; i < pracownicy.size(); ++i) {
			pracownicy[i]->print();
		};
	};

	double wartoscFirmy() {
		if ((N + 1) == historiaPrzychodow.size()) {
			historiaPrzychodow.erase(historiaPrzychodow.begin());
		};
		double srednia = 0.0;
		if (historiaPrzychodow.size() > 0) {
			for (int i = 0; i < historiaPrzychodow.size(); ++i) {
				srednia = srednia + historiaPrzychodow[i];
			};
			srednia = srednia / historiaPrzychodow.size();
		};
		return srednia;
	};

	void zatrudnijInzyniera() {
		pracownicy.push_back( new Inzynier());
		iloscInzynierow++;
	};
	void zatrudnijMagazyniera() {
		pracownicy.push_back(new Magazynier());
		iloscMagazynierow++;
	};
	void zatrudnijMarketera() {
		pracownicy.push_back(new Marketer());
		iloscMarketerow++;
	};
	void zatrudnijRobotnika() {
		pracownicy.push_back(new Robotnik());
		iloscRobotnikow++;
	};

	void wezKredyt(double k, int ilosc_rat) {
		Kredyt wzietyKredyt(k, ilosc_rat);
		kredyty.push_back(wzietyKredyt);
		setStanKonta(getStanKonta()+k);
	};
	double obliczRaty() {
		double wysokoscRat=0;
		for (int i = 0; i < kredyty.size(); ++i) {
			if (kredyty[i].getPozostaleRaty()>0) {
				wysokoscRat = wysokoscRat + kredyty[i].getRata();
			};
		};
		return wysokoscRat;
	};
	double obliczZaciagnietyDlug() {
		double dlugCalkowity = 0;
		for (int i = 0; i < kredyty.size(); ++i) {
			if (kredyty[i].getPozostaleRaty() > 0) {
				dlugCalkowity = dlugCalkowity + kredyty[i].getDlug();
			};
		};
		return dlugCalkowity;
	};

	double obliczPrzychod()const {
		double cena = CI*(double)iloscInzynierow;
		int pojemnosc_mag = iloscMagazynierow * CMag;
		int popyt = iloscMarketerow * CMkt;
		int teoret_produkcja = iloscRobotnikow * CR;
		int fakt_produkcja=0;
		if (teoret_produkcja > pojemnosc_mag) {
			fakt_produkcja = pojemnosc_mag;
		}
		else {
			fakt_produkcja = teoret_produkcja;
		};
		int liczba_sprzedanych = 0;
		if (popyt > fakt_produkcja) {
			liczba_sprzedanych = fakt_produkcja;
		}
		else {
			liczba_sprzedanych = popyt;
		};
		double przychod = cena * (double)liczba_sprzedanych;
		return przychod;
	};
	double obliczDochod() {
		double dochod=obliczPrzychod()-zaplacWynagrodzenia()-obliczRaty();
		return dochod;
	};
	void zamkniecieMiesiaca() {
		for (int i = 0; i < kredyty.size(); ++i) {
			if (kredyty[i].getPozostaleRaty() > 0) {
				kredyty[i].setPozostaleRaty(kredyty[i].getPozostaleRaty() - 1);
			};
		};
		historiaPrzychodow.push_back(obliczPrzychod());
		setStanKonta(getStanKonta() + obliczDochod());
	};
	void get_pozostale_raty() { cout << kredyty[0].getPozostaleRaty() << endl; };
	void stanFirmy() {
		cout << "STAN FIRMY:" << endl;
		cout << "Stan konta wynosi: " << getStanKonta()<<"." << endl;
		cout <<	"Wartosc firmy wynosi: "<<wartoscFirmy()<<"." << endl;;
		cout << "Ilosc zaciagnietych kredytow wynosi: " << kredyty.size() << endl;
		drukujPracownikow();
		cout << endl;
	};
private:
	int N = 12;
	double stanKonta;
	int iloscKredytow;
	vector<Kredyt> kredyty;
	int iloscInzynierow=1;
	int iloscMagazynierow = 1;
	int iloscMarketerow = 1;
	int iloscRobotnikow = 1;
	vector <Pracownik*> pracownicy;
	vector <double> historiaPrzychodow;
	
	
};

#endif
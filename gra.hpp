
#include <iostream>
#include<vector>
#include<string>
#include "RandomNameGenerator.hpp"
#include "Pracownik.hpp"
#include "Inzynier.hpp"
#include "Magazynier.hpp"
#include "Marketer.hpp"
#include "Robotnik.hpp"
#include "Kredyt.hpp"
#include "Firma.hpp"

using namespace std;


void graj() {

    bool stan = 1;
    double celGry = 60000.0;
    Firma b;
    cout << "Mozliwe do wykonania akcje:" << endl;
    cout << "lp - wylistuj pracownikow" << endl;
    cout << "zinz - zatrudnij inz." << endl;
    cout << "zmag - zatrudnij mag." << endl;
    cout << "zmkt - zatrudnij mark." << endl;
    cout << "zrob - zatrudnij rob." << endl;
    cout << "kred - wez kredyt (w nastêpnym kroku podaj kwote i czas splaty)" << endl;
    cout << "kt - zakoncz ture i wyswietl stan firmy na poczatku nastepnego miesiaca" << endl;
    cout << endl;
    b.stanFirmy();
    while (stan = 1)
    {
        string komenda;
        cin >> komenda;
        if (komenda == "lp") { b.drukujPracownikow(); }
        else if (komenda == "zinz") { b.zatrudnijInzyniera(); }
        else if (komenda == "zmag") { b.zatrudnijMagazyniera(); }
        else if (komenda == "zmkt") { b.zatrudnijMarketera(); }
        else if (komenda == "zrob") { b.zatrudnijRobotnika(); }
        else if (komenda == "kred")
        {
            double w = 0.0;
            int j = 0;
            cin >> w;
            while ((w + b.obliczZaciagnietyDlug()) > (b.wartoscFirmy() * M)) {
                cout << "Za duze zadluzenie Firmy, podaj wartosc kredytu mniejsza od " << (b.wartoscFirmy() * M - b.obliczZaciagnietyDlug()) << "." << endl;
                cin >> w;
            };
            cin >> j;
            while (j > X) {
                cout << "Za dlugi okres splaty, podaj wartosc mniejsza lub rowna " << X << " miesiecy!" << endl;
                cin >> j;
            };
            b.wezKredyt(w, j);
        }
        else if (komenda == "kt") {
            b.zamkniecieMiesiaca();
            double t = b.getStanKonta();
            if (t < 0) { stan = 0; };
            if (t > celGry) { stan = -1; };
            if (stan == 0)
            {
                cout << "Przegrales! Stan konta ujemny!" << endl;
                break;
            };
            if (stan == -1)
            {
                cout << "Wygrales! Stan konta osiagnal osiagnal kwote " << t << " czyli wiecej niz cel gry wynoszacy" << celGry << "!!!" << endl;
                break;
            };
            b.stanFirmy();
        }
        else
        {
            cout << "Wpisana nieprawodlowa komenda!!!!" << endl;
        };
    };
};
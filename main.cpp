
#include <iostream>
#include <vector>
#include <string>
#include "RandomNameGenerator.hpp"
#include "Pracownik.hpp"
#include "Inzynier.hpp"
#include "Magazynier.hpp"
#include "Marketer.hpp"
#include "Robotnik.hpp"
#include "Kredyt.hpp"
#include "Firma.hpp"
#include "gra.hpp"
#include <stdlib.h> // niezbędne dla funkcji srand i rand
#include <time.h> // niezbędne dla funkcji time


using namespace std;
int main()
{ 
    srand(time(NULL));
    graj();
    return 0;
};


#include "funkcje.h"
#include <iostream>

int main(int argc, char** argv)
{
  int a1;
  int b1;
  int a2;
  int b2;
  char opcja;
  
  if ( ! ustaw_parametry(argc, argv, a1, b1, a2, b2, opcja) ) {
  std::cout<<"BLAD\n";
  return -1;
  }
  
  
  
  if (opcja == 'A')
  {
    std::cout<<"A) \n";
    liczba l1 = utworz(1,1);
    l1.wypisz();
    liczba l2 = utworz(a1,1);
    l2.wypisz();
    liczba l3 = utworz(a1,b1);
    l3.wypisz();
    liczba l4 = utworz(a2,b2);
    l4.wypisz();
  }


std::cout<<"B) \n";


liczba l1 = redukcja(1,1);
l1.wartosc();
liczba l2 = redukcja(a1,1);
l2.wartosc();
liczba l3 = redukcja(a1,b1);
l3.wartosc();
liczba l4 = redukcja(a2,b2);
l4.wartosc();

}

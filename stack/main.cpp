
#include <iostream>

#include "stos.h"

int main(int argc, char *argv[]) {
  
   
    
    int max = 0;
    std::cout << "Podaj maksymalny rozmiar stosu: ";
    std::cin >> max;
    
    Stos<int> stos(max);
    

    int x = 0;
    do {
      std::cout << "Wpisz liczbe do dodania na stos: ";
      std::cin >> x;
    } while( stos.dodaj(x) );
    
    std::cout << "stos: " << stos << std::endl;

    
    std::cout << "usuniety element: " << stos.usun() << std::endl;
    
    std::cout << "stos: " << stos << std::endl;


    std::cout << "najmniejsza wartosc na stosie: " << stos.najmniejsza() << std::endl;
    
    std::cout << "najwieksza wartosc na stosie:  " << stos.najwieksza() << std::endl;
    
   
    std::cout << stos.liczba_mniejszych_od(max) << " liczb na stosie jest mniejszych od  " << max << std::endl;
    
    
    if( ! stos.wszystkie_mniejsze_od(max) ) std::cout << "nie ";
    std::cout << " wszystkie liczby na stosie sa mniejsze od  " << max << std::endl;

    
    stos.usun_elementy_mniejsze_od( max );
    std::cout << "stos: " << stos << std::endl;


    stos.przestaw_elementy_losowo();
    std::cout << "stos: " << stos << std::endl;
    
    
   
    stos.sortuj_rosnaco();
    std::cout << "stos: " << stos << std::endl;
    
 
    stos.sortuj_malejaco();
    std::cout << "stos: " << stos << std::endl;

    return 0;
}


#include <iostream>
#include <cmath>
#include <ctime>
#include <functional>

#include "funkcje.h"

int main(int argc, char *argv[]) {
  
    std::cout << "Calkowanie numeryczne metoda Monte Carlo.\n";
    
   
    auto N = 2; // N>1, liczba testowanych punktow
    char nazwa_funkcji = 'f'; // tylko 'f' lub 'g'
    bool uzyj_int = false; // czy pracowac na typie int, 't' lub 'n'
    auto a = 0.0; // a>=0, dolna granica calkowania
    auto b = 100.0; // b>a, gorna granica calkowania

    
  
    
    /* ustawienie parametrow i wypisanie ich lub pomocy jesli 
     * parametry nieprawidlowe lub ich brak
     */
    if ( ! ustaw_parametry(argc, argv, N, nazwa_funkcji, uzyj_int, a, b) ) {
        wyswietl_pomoc();
        return 1;
    }
    
    /* uzycie przeladowanej (ew. takze szablonowej) funkcji wypisz */
     wypisz("# Parametry:");
     wypisz("# nazwa_funkcji = ", nazwa_funkcji);
     wypisz("# a = ", a);
     wypisz("# b = ", b);
     wypisz("# N = ", N);
     wypisz("# uzyj_int = ", uzyj_int);
     wypisz("#");



    /*
     *    f(x) = sqrt(x)
     *    g(x) = x*x
     */
  auto f = [] (double x){return sqrt(x);} ;
  auto g = [] (double x){return x*x;} ;
    
     std::function<double(double)> funkcja;
     if(nazwa_funkcji == 'f') {
         funkcja = f;
     } else if(nazwa_funkcji == 'g') {
         funkcja = g;
     }
   
     wypisz("# Wartosci funkcji na koncach przedzialu");
     wypisz("# funkcja(a) = ", funkcja(a) );
     wypisz("# funkcja(b) = ", funkcja(b) );
     wypisz("#");
    
    
 
    
    /* jesli N<20, wypisac tabele wartosci funkcji dla x = a, a+dx, ..., b,
     *   gdzie dx = (b-a)/N
     */
    if(N < 20) {
        wypisz(nazwa_funkcji, funkcja, a, b, N);
    }
    /* oraz przetestowac funkcje losujace int lub double z zadanego przedzialu
     *     (przydadza sie potem w obliczeniach Monte Carlo)
     */
    srand((unsigned)time(NULL));
    if(N < 20) {
         wypisz("### test losowych wartosci z przedzialu [a;b]");
        for(int i=0; i<N; ++i) {
             if(uzyj_int) {
                 wypisz("int: ", losuj( (int)a, (int)b) );
             } else {
                 wypisz("double: ", losuj(a, b) );
             }
         }
    }

    
   
    std::cout << "#\n# Koniec\n";
        
    return 0;
}

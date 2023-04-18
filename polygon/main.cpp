#include <iostream>
#include <list>
#include "funkcje.h"
#include <time.h>


int main()
{

srand(time(NULL));
Wielokat w;



for(int i=0;i<5;i++){
    std::pair<double, double> v(1.0*rand()/RAND_MAX*10,1.0*rand()/RAND_MAX*10);
    w.dodaj(v);
}
std::cout<<w;

    std::pair<double, double> pros1 (0,0);
    std::pair<double, double> pros2 (2,1);
    Prostokat p(pros1,pros2);

    std::pair<double, double> troj1 (1,1);
    std::pair<double, double> troj2 (0,1);
    std::pair<double, double> troj3 (1,0);

    Trojkat t(troj1,troj2,troj3);
    
    std::cout<<"PROSTOKAT: \n"<<p;
    std::cout<<"TROJKAT: \n"<<t;
    


std::pair<double, double> pkt2  = wierzcholek(p,3);
std::cout<<"\nPunkt 3 dla p: ";
std::cout<<pkt2.first<<' '<<pkt2.second<<"\n";

std::pair<double, double> pkt1  = wierzcholek(t,6);
std::cout<<"\nPunkt 6 dla t: ";
std::cout<<pkt1.first<<' '<<pkt1.second<<"\n";

std::cout<<"\nNOWE WIERZCHOLKI\n";
wczytaj(t);
std::cout<<t;
return 0;
}







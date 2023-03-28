#include <iostream>
#include "funkcje.h"

int ustaw_parametry(int argc,char** argv,int &a1,int &b1,int &a2, int &b2,char &opcja)
{
  if (argc==6)
  {
    a1 = atoi(argv[1]);
    b1 = atoi(argv[2]);
    a2 = atoi(argv[3]);
    b2 = atoi(argv[4]);
    opcja = argv[5][0];
    
    return 1;
  }
  else
  {
    return 0;
  }

}

liczba::liczba(int ll=1,int mm=1)
{
  l=ll;
  m=mm;
}

void liczba::wypisz()
{
  std::cout<<l<<"/"<<m<<"\n";
}

liczba utworz(int L,int M)
{
    liczba a(L,M);
   
    return a;
}


double liczba::wartosc()
{
  return l/m;
}
liczba redukcja(int l,int m)
{
   int r;
   if(m != 0)
   {
      
      r = l%m;
      l = m;
      m = r;
      std::cout<<r<<"\n";
   } 
}

void liczba::zamiana()
{
    std::cout<<m<<"/"<<l<<"\n";
}















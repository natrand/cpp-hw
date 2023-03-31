#include "funkcje.h"
#include <iostream>
#include <cmath>

int main(int argc,char** argv)
{
    
    
    double u0=4*M_PI*pow(10,-7);
    
    int N;
    double x,y,z,I1,I2,L,a;
    
    
  if ( ! ustaw_parametry(argc, argv, x,y,z,I1,I2,L,a,N) ) {
  std::cout<<"BLAD\n";
  return -1;
  }
    Wektor B;
    Wektor u(x,y,z);
    Wektor v(I1,I2,a);
    

  std::cout<<"dlugosc u: "<<u.dlugosc()<<"\n";
  std::cout<<"dlugosc v: "<<v.dlugosc()<<"\n";
  std::cout<<"u+v: "<<u+v<<"\n";
  std::cout<<"u-v: "<<u-v<<"\n";
  std::cout<<"N*u: "<<N*u<<"\n";
  std::cout<<"u x v: "<<u.X(v)<<"\n";
  
  
  Wektor *dl = new Wektor [2*N];
  Wektor *r = new Wektor [2*N];
  double dL = L/N;
  
  
  Wektor a1(dL,0,0);
  Wektor a2(0,dL,0);
  

  double k = 0.1*L;
  
  for(int i;i<L;i++)
  {
    Wektor t(0,0,k);
    for (int j;j<L;j++)
    {
    dl[j] = a1;
    dl[N+j] = a2;
    
 
    Wektor b1(L/2 - j*dL, a/2, 0);
    Wektor b2(-L/2, L/2 - j*dL, 0);
    r[j] = t-b1;
    r[N+j] = t - b2;
 
   
   
    }
  }
    
    delete [] dl;
    delete [] r;
    
    return 0;
} 

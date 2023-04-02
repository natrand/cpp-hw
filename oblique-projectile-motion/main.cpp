#include <iostream>
#include "funkcje.h"
#include <cmath>

int main(int argc, char *argv[])
{

  
  double g=9.8;
  int m=1;
  int N=0;
  double dt=0;
  double v0=0;
  double alpha=0;
  double b=0;
  
  parametry(argc,argv,&N,&dt,&v0,&alpha,&b);
  wypisz_parametry(argc,N,dt,v0,alpha,b);
  
  
std::cout<<"\n# i t[i] x[i] y[i] vx[i] vy[i] v[i]"<<"\n";
  
double* t;
double *x;
double  *y;
double  *vy;
double  *vx;
double  *v;

t = alokuj(N);
x  = alokuj(N);
y = alokuj(N);
vx = alokuj(N);
vy = alokuj(N);
v = alokuj(N);

wypelnij_czas(N,t,dt);
wypelnij_x(N,x);


if (argc==5)
{
  for (int i=0;i<N;i++)
  {
    x[i]=v0*t[i]*cos(alpha);
    y[i]=v0*t[i]*sin(alpha)-g*t[i]*t[i]/2;
    vx[i]=v0;
    vy[i]=v0-g*t[i];
    v[i]=sqrt((vx[i]*vx[i])+(vy[i]*vy[i]));
  }

}
wypisz_tab(&N,t,x,y,vx,vy,v);


if(argc==6)
{
  if(*b==0)
  {
    x[0]=0;
    y[0]=0;
    vx[0]=v0;
    vy[0]=v0;
    v[0]=sqrt((v0*v0)+(v0*v0));
    int Fx=0;
    double Fy=g;
    for(int i=0;i<N-1;i++)
    {
      x[i+1]=x[i]+vx[i]*dt;
      y[i+1]=y[i]+vy[i]*dt;

      vx[i+1]=vx[i]+(Fx/m)*dt;
      vy[i+1]=vy[i]+(Fy/m)*dt;

      v[i+1]=sqrt((vx[i+1]*vx[i+1])+(vy[i+1]*vy[i+1]));
    }
    wypisz(&N,t,x,y,vx,vy,v);
  }
 
}

zwolnij(t);
zwolnij(x);
zwolnij(y);
zwolnij(vx);
zwolnij(vy);
zwolnij(v);

}

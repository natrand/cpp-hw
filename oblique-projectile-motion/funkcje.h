void parametry(int argc, char **argv, int* N, double *dt, double *v0, double *alpha, double *b)
{
  
    *N=atof(argv[1]);
    *dt=atof(argv[2]);
    *v0=atof(argv[3]);
    *alpha=atof(argv[4]);
    if(argc==6)
  {
    *b=atof(argv[5]);
    
  }
 
   
}
int wypisz_parametry(int argc,int N,double dt,double v0, double alpha, double b)
{

  std::cout<<"N= "<<N<<"\ndt= "<<dt<<"\nv0= "<<v0<<"\nalpha= "<<alpha;
  if (argc == 6)
  {
			std::cout << "\nb = " << b <<"\n";
	}
		else 
		{
			std::cout << "\nb = (bez oporu)" <<"\n";
}
 
  return 0;
}
void instrukcja_obslugi()
{
  std::cout<<"zle parametry";
}

double* alokuj(int N)
{
  double *tab;
  tab = new double[N];
  return tab;
}

void wypelnij_czas(int N,double *tab,double dt)
{
  for(int i=0;i<N;i++)
  {
    tab[i]=i*(dt);
  }
}
void wypelnij_x(int N,double *tab)
{
  for(int i=0;i<N;i++)
  {
    tab[i]=0;
  }
}
void wypisz(double *tab, int N)
{
 for(int i=0;i<N;i++)
 {
   std::cout<<i<<" "<<tab[i]<<"\n";
 }
}

void zwolnij(double* tab)
{
 delete [] tab;
}
void wypisz_tab(int *N,  double*t, double*x, double *y,double *vx, double *vy, double *v)
{
   for (int i=0; i<*N; i++)
    {
        std::cout<<i<<"\t"<<t[i]<<"\t"<<x[i]<<"\t"<<y[i]<<"\t"<<vx[i]<<"\t"<<vy[i]<<"\t"<<v[i]<<std::endl;
    }

}











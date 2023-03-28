int ustaw_parametry(int argc,char** argv,int &N,char &nazwa_funkcji,bool &uzyj_int,double &a,double &b)
{
  if (argc != 6)
  {
    return 0;
  }
  nazwa_funkcji = argv[2][0];
  if (nazwa_funkcji != 'f' && nazwa_funkcji != 'g')
  {
    return 0;
  }
  N = atoi(argv[1]);
  if(N<1)
  {
    return 0;
  }
  char precision = argv[3][0];
  if(precision == 't')
  {
    uzyj_int = true;
  }
  else if(precision == 'n')
  {
    uzyj_int = false;
  }
  a = atoi(argv[4]);
  b = atoi(argv[5]);
  if(a < 0 )
  {
    return 0;
  }
  if(b<a)
  {  
    return 0;
  }
  
  return 1;
}

void wyswietl_pomoc()
{
  std::cout<<"Program nalezy uruchamiac za pomoca: \n./lab N nazwa uzyj_int a b\ngdzie:\nN - liczba punktow do losowania (N > 1)\nnazwa - nazwa funkcji, 'f' lub 'g'\nuzyj_int - czy uzyc typu int, 't' (tak) lub 'n' (nie)\na - dolna granica calkowania (a >= 0)\nb - gorna granica calkowania (b > a)\n";
}


void wypisz(std::string x)
{
    std::cout<<x<<"\n";
}

void wypisz(std::string x,int N)
{
  std::cout<<x;
  std::cout<<N<<"\n";
}
void wypisz(std::string x,char nazwa_funkcji)
{
  std::cout<<x;
  std::cout<<nazwa_funkcji<<"\n";
}
void wypisz(std::string x,bool uzyj_int)
{
  std::cout<<x;
  std::cout<<uzyj_int<<"\n";
}
void wypisz(std::string x,double a)
{
    std::cout<<x;
    std::cout<<a<<"\n";
}

void wypisz(char nazwa_funkcji,std::function<double(double)> f,double a,double b,int N)
{
 double dx;
 dx = (b-a)/N;
 std::cout<<"### x 	  g(x)"<<"\n";
 double x =0;
 double F =0;
    for (int i=0; i<N+1; i++)
    {
        x = dx*i;
        F = f(x);
        std::cout<<x<<"\t"<<F<<"\n";
    }
}

int losuj(double a, double b)
{
  return 1.0*rand()/RAND_MAX*(b-a) + a;
}

struct wynik
{
  int y_min;
  int y_max;
  int trafienia;
  double calka_monte_carlo;
  double calka_analitycznie;
  double blad;
  double blad_wzgledny_proc;
  
};












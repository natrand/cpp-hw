#include <iostream>
#include <cmath>


template <class T>
class Ciag{
public:
    T *tab;
    int N;
    Ciag(int N0,int START){
        N=N0;
        tab = new T [N0];
        for(int i = 0; i<N0; i++)
        {
            tab[i] = START+i;
        }
    }
    ~Ciag(){ delete[] tab; }
    
    
    T& operator [] (int i) {
        
        return tab[i];
    }
    

    
    
    Ciag(const Ciag& d){
        N=d.N;
        tab = new T [N];
        for(int i=0;i<N;i++)
        {
            tab[i] = d.tab[i];
            
        }
            
    }
    Ciag& operator = (Ciag& d){
        delete []tab;
        N = d.N;
        tab = new T [N];
        for (int i = 0; i<N; i++)
            tab[i] = d.tab[i];
        return *this;
    }
   
   Ciag(Ciag&& d){
        N = d.N;
        tab = new T [N];
        for(int i = 0; i<N; i++)
            tab[i] = d.tab[i];
        delete []d.tab;
        d.tab = nullptr;
        d.N = 0;
    }

    T& operator () (int i){
        return tab[i];
   }
   
};   



template <class T>
std::ostream& operator<<(std::ostream& ostr, const Ciag<T>& d){
    ostr<<"[ ";
    for(int i = 0; i<d.N; i++)
    ostr << (T)d.tab[i]<<" ";
    ostr<<" ]";
    return ostr;
}
    






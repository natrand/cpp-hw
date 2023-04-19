#include <iostream>
#include <vector>
#include<algorithm>

template<class T>
class Stos{
public:
   unsigned int max_size;
    std::vector<T> w;

    Stos(unsigned int max): max_size{max}{}
    bool dodaj(T);
    T usun();
    T najmniejsza();
    T najwieksza();
    int liczba_mniejszych_od(T);
    bool wszystkie_mniejsze_od(T);
    void usun_elementy_mniejsze_od(T);
    void przestaw_elementy_losowo();
    void sortuj_malejaco();
    void sortuj_rosnaco();
};

template<class T>
bool Stos<T>::dodaj(T a){
    if(w.size()< max_size){
    w.push_back(a);
    if(w.size()==max_size){return 0;}
    return 1;
    
    
  }   
    
return 0;
}

template<class T>
T Stos<T>::usun(){
    T b = w[max_size-1];
    w.pop_back();
return b;
}

template<class T>
std::ostream& operator<< (std::ostream& ostr, const Stos<T>& s){
    for_each(s.w.begin(), s.w.end(), [&](T i){ostr<<i<<' ';});
return ostr;
}

template<class T>
T Stos<T>::najwieksza(){
    return *max_element(w.begin(), w.end());
}

template<class T>
T Stos<T>::najmniejsza(){
    return *min_element(w.begin(), w.end());
}

template<class T>
int Stos<T>::liczba_mniejszych_od(T a){
    return count_if(w.begin(), w.end(), [=](T i){return i<a;} );
}

template<class T>
bool Stos<T>::wszystkie_mniejsze_od(T a){
    return all_of(w.begin(), w.end(), [=](T i){return i<a;});
}

template<class T>
void Stos<T>::usun_elementy_mniejsze_od(T a){
    w.erase(std::remove_if(w.begin(), w.end(),[=](T i){return i<a;}), w.end());
}

template<class T>
void Stos<T>::przestaw_elementy_losowo(){
    random_shuffle(w.begin(), w.end());
}

template<class T>
void Stos<T>::sortuj_malejaco(){
    sort(w.rbegin(),w.rend());
   
}

template<class T>
void Stos<T>::sortuj_rosnaco(){
    sort(w.begin(),w.end());
   
}







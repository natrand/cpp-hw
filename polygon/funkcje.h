#include <iostream>
#include<list>


class Wielokat{
protected: 
    std::list<std::pair<double,double>> pkt;
public:
    void dodaj(std::pair<double,double> p){
    pkt.push_back(p);
    }
    friend std::ostream& operator << (std::ostream& , const Wielokat&);
    
    int rozm()const{return pkt.size();}
    
    std::pair<double, double> c (int i)const{
    int j = 0;
     for(auto a:pkt){
        if(j == i) {
            return a;
        }
        j++;
     }
    }
    void zamien(int i, double x, double y){
        int j = 0;
    for(auto& a:pkt){
        if(j == i){
        a.first = x;
        a.second = y;
        }
        j++;
        }
    }
};


std::ostream& operator<< (std::ostream& ostr, const Wielokat& w){
    for(auto i:w.pkt)
        ostr<<"("<<i.first<<";"<<i.second<<")"<<std::endl; 
return ostr;
}


class Prostokat: public Wielokat{
public:
    Prostokat(std::pair<double,double> p1,std::pair<double,double> p2){
    dodaj(p1);
    dodaj(p2);
    std::pair<double, double> prawy_dolny (p2.first, p1.second);
    std::pair<double, double> lewy_gorny (p1.first, p2.second);
    dodaj(lewy_gorny);
    dodaj(prawy_dolny);
    }

};

class Trojkat: public Wielokat{
public:
    Trojkat(std::pair<double,double> p1,std::pair<double,double> p2,std::pair<double,double> p3){
    dodaj(p1);
    dodaj(p2);
    dodaj(p3);
    }
    
};


std::pair<double,double> wierzcholek(const Wielokat& x,int i){
    if(i>x.rozm()){
        std::cout<<"Wierzcholek nie istnieje\n"<<"Liczba wierzcholkow: "<<x.rozm();
        std::pair<double,double> z(0,0);
        return z;
    }
    return x.c(i);
}

void wczytaj(Wielokat& x){
    std::cout<<"\nWpisac nowe pary wspolrzednych dla "<<x.rozm()<<" wierzcholkow: \n";
    for(int i = 0; i< x.rozm(); i++){
    double x1,y1;
    std::cin >> x1;
    std::cin >> y1;
    x.zamien(i,x1,y1);
    }
}

   
  
  






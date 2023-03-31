#include <iostream>
#include <cmath>

int ustaw_parametry(int argc,char** argv,double &x,double &y,double &z,double &I1,double &I2,double &L,double &a,  int& N)
{
  if(argc==9)
  {
    x=atof(argv[1]);
    y=atof(argv[2]);
    z=atof(argv[3]);
    I1=atof(argv[4]);
    I2=atof(argv[5]);
    L=atof(argv[6]);
    a=atof(argv[7]);
    N=atoi(argv[8]);
    return 1;
  }
  else
  {
    return 0;
  }
}


class Wektor{
    double x;
    double y;
    double z;
public:
    Wektor(): x{},y{},z{} {}
    Wektor(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
    }
    
    double dlugosc(){
    return sqrt(x*x+y*y+z*z);
    }
    
    friend std::ostream& operator<<(std::ostream& ,const Wektor&);
    friend Wektor operator*(const Wektor&, const Wektor&);
    friend Wektor operator+ (const Wektor&, const Wektor &);
    friend Wektor operator- (const Wektor&, const Wektor &);

    friend Wektor operator* (double, const Wektor &);
    
   
    Wektor X(const Wektor&b){
    double l = y*b.z - z*b.y;
    double m = b.x*z - b.z*x ;
    double n = x*b.y - b.x*y;
    
    return Wektor(l,m,n);
}

};



std::ostream& operator<<(std::ostream& ostr,const Wektor& a){
    ostr<<"["<<a.x<<" ; "<<a.y<<" ; "<<a.z<<"]";
    return ostr;
}





Wektor operator+ (const Wektor& a,const Wektor &b){
    double l = a.x + b.x;
    double m = a.y + b.y;
    double n = a.z + b.z;
    return Wektor (l,m,n);
}

Wektor operator- (const Wektor& a,const Wektor &b){
    double l = a.x - b.x;
    double m = a.y - b.y;
    double n = a.z - b.z;
    return Wektor (l,m,n);
}

Wektor operator* (double a,const Wektor &b){
    double l = a*b.x;
    double m = a*b.y;
    double n = a*b.z;
    return Wektor (l,m,n);
}



























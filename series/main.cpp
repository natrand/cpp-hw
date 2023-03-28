#include <iostream>
#include "Ciag.h"

int main(int argc, char *argv[]) {
	
	if(argc != 3) {
		std::cerr << "Program nalezy uruchamiac poleceniem:" << std::endl;
		std::cerr << "  " << argv[0] << " N START" << std::endl;
		return 1;
	}
	int N = atoi( argv[1] );
	if(N<2) N=2;
	int START = atoi( argv[2] );
	if(START<32) START=32;


 	Ciag<char> litery(N, START);
	Ciag<char> * napis = new Ciag<char>(N, START);
 	Ciag<int> liczby(N, START);

	std::cout << "litery = " << litery << std::endl; 
 	std::cout << "litery.tab[0] = " << *(litery.tab) << " litery.tab[N-1] = " << *(litery.tab+litery.N-1) << std::endl;
 	std::cout << "napis = " << *napis << std::endl;
 	std::cout << "liczby = " << liczby << std::endl;

	liczby[0] = 99;
 	liczby[1] = 33;
 	std::cout << "liczby = " << liczby << std::endl;
	


 	Ciag<int> nowe_liczby(liczby);
	liczby.tab[0] = 7;
 	nowe_liczby[0] = 8;
	std::cout << "liczby = " << liczby << std::endl;
 	std::cout << "nowe_liczby = " << nowe_liczby << std::endl;
	
 	Ciag<char> nowe_litery( *napis );
 	nowe_litery[nowe_litery.N-1] = '*';
 	std::cout << "nowe_litery = " << nowe_litery << std::endl;
	
 	liczby = nowe_liczby;
	liczby[1] = 9;
 	nowe_liczby.tab[1] = 10;
 	std::cout << "liczby = " << liczby << std::endl;
 	std::cout << "nowe_liczby = " << nowe_liczby << std::endl;
	
 	Ciag<char> inny_napis(2*N, START+32);
 	std::cout << "inny_napis = " << inny_napis << std::endl;
 	inny_napis = litery;
 	std::cout << "inny_napis = " << inny_napis << std::endl;
	

	
 	std::cout << "litery = " << litery << std::endl;
 	std::cout << "liczby = " << liczby << std::endl;
	
 	Ciag<char> litery_2(std::move(litery));
 	Ciag<int> liczby_2(std::move(liczby));
	
	std::cout << "litery = " << litery << std::endl;
 	std::cout << "liczby = " << liczby << std::endl;
 	std::cout << "litery_2 = " << litery_2 << std::endl;
 	std::cout << "liczby_2 = " << liczby_2 << std::endl;


 	delete napis;
}

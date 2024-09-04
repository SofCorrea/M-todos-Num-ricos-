//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define E 2.718281828

//using namespace std;

double f(double m);

// TERMINAR: COMPROBAR SI FUNCIONA
// CAMBIAR A, B Y TOL

int main(int argc, char *argv[]) {
	double error=1, c=0, a=60, b=70, tol=pow(10,-4); // tol=1e-4
	
	if(f(a)* f(b)>0){
		printf("\nLa funcion no cambia de signo");
		return 0;
	}
	
	do{
		c=(a+b)/2;
		
		if(f(a)*f(c)>0){ // dentro del intervalo de a y c: no se encuentra la raiz
			a=c;
		}else{
			if(f(a)*f(c)<0){ // se sabe que esta dentro de ese intervalo la raiz
				b=c;
			}else{ //si f(a)*f(c) es igual a 0: encuentra la raiz, la raiz es ...
				printf("\nLa raiz es: %lf ",  c);
				return 1;
			}
		}
		
		error=(b-a)/2;
		
	} while(error>tol);
	
	printf("\nLa raiz es: %lf ",  c);
	printf("\nError: %lf", error);
	
	return 2;
}


double f(double m){
	return  ((9.81*m/14)*(1-pow(E,(((-14)/m)*7))) - 35) ;
}

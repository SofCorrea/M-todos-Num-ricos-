#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

double f(double x);

int main(int argc, char *argv[]) {
	double error=1, c=0, a=0, b=1, tol=pow(10,-4); // tol=1e-4
	
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

double f(double x){
	return -2+7*x-5*pow(x,2)+6*pow(x,3); // (base, indice o potencia)
}

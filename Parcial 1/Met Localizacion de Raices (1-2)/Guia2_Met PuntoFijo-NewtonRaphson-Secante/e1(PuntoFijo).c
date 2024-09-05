#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

double g(double x);

int main(int argc, char *argv[]) {
	double x_v=-1, tol=pow(10,-12), error=1, x_n=0; // x_viejo lo elegis vos por donde empezar,  punto de partida
	int it=0;
	
	do{
		it++;
		
		x_n = g(x_v);
		
		if(abs(((g(x_v+0.01)-g(x_v))/0.01))>1){ // d(g(x)) > 1 : no cumple -> no converge
			
			printf("No se cumple el criterio de convergencia");
			return 1;
		}
		
		error = abs(x_n-x_v);
		x_v = x_n;
		
	} while(error>tol && it<10000);
	
	printf("Raiz: %lf", x_n);
	printf("\nError: %lf", error);
	printf("\nIteraciones: %d", it);
	
	return 0;
}
double g(double x){
	return pow(x,5)+3*pow(x,3)-2*pow(x,2)+2;
}

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

double f(double x);

int main(int argc, char *argv[]) {
	double a = 1, b = 3, tol = 1e-10, c = 0;
	
	if(f(a)*f(b) > 0){
		printf("La funcion no cambia de signo");
		return 1;
	}else{
		double error = (b-a)/2;
		
		do{
			c = (a+b)/2;
			
			if(f(a)*f(c) > 0){
				a = c;
			}else{
				if(f(a)*f(c) < 0){
					b = c;
				}else{
					printf("La raiz es: %lf\n", c);
					return 2;
				}
			}
			
			error = (b-a)/2;
			
		} while(error > tol);
		
		printf("La raiz es %lf\n", c);
		printf("El error aproximado es: %lf", error);
		return 3;
	}
	
	return 0;
}

double f(double x){
	return (2*x-4);
}

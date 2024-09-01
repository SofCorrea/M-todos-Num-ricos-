#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

double f(double x);

int main(int argc, char *argv[]) {
	double a = 0, b = 2, tol = pow(10,-5), c = 0, cv = 0;
	int cont = 0;
	
	if(f(a)*f(b) > 0){
		printf("Cambie los valores de a o b");
		return 1;
	}else{
		double error = 1;
		
		do{
			cv = c;
			cont++;
			c = (a*f(b)-b*f(a))/(f(b)-f(a));
			
			if(f(a)*f(c) > 0){
				a = c;
			}else{
				if(f(a)*f(c) < 0){
					b = c;
				}else{
					printf("La raiz es: %lf\n", c);
					printf("Interaciones: %d\n", cont);
					return 2;
				}
			}
			
			error = abs(c-cv);
			
		} while(error > tol);
		
		printf("La raiz es %lf\n", c);
		printf("El error aproximado es: %lf\n", error);
		printf("Interaciones: %d\n", cont);
		return 3;
	}
	
	return 0;
}

double f(double x){
	return pow(x,10)-1;
}
	

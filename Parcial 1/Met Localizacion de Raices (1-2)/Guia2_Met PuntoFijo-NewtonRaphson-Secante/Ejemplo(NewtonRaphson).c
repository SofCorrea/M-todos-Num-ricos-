#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//using namespace std;

double f(double x);
double f_Prima(double x);

int main(int argc, char *argv[]) {
	double xViejo=0, xNuevo=0, error=1, tol=0;
	int it=0;
	
	printf("Ingrese la tolerancia\n"); 
	scanf(" %lf", &tol);
	
	printf("Ingrese el punto inicial\n"); 
	scanf(" %lf", &xViejo);
	
	do{
		tol++;

		
		if(abs(f_Prima(xViejo) < pow(10, -5))){
			printf("\n\nDerivada demasiado chica.");
			return 1;
		}else{
			
			xNuevo = xViejo - (f(xViejo) / f_Prima(xViejo));
			
			error = abs(xNuevo-xViejo);
			
			xViejo = xNuevo;
			
		}
		
	} while(error > tol || it < 10000);

	printf("\n\n\nLa raiz de f es: %.10lf", xNuevo);
	printf("\nEl valor del error en la raiz es de: %.10lf", error);
	printf("\nTomo %d iteraciones", it);
	
	return 0;
}
double f(double x){
	return pow(x, 2) - 4;
}

double f_Prima(double x){
	return 2*x;
}

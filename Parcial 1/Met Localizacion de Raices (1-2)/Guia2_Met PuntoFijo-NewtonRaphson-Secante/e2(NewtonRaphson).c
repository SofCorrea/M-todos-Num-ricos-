#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x);
double f_prima(double x);

// using namespace std;

// TERMINARLOOOOOOO

int main(int argc, char *argv[]) {
	double xViejo=-1, xNuevo=0, error=1, tol=0; // xViejo = punto inicial
	int it=0;
	
	do{
		it++;
		
		if(abs(f_prima(xNuevo)) < pow(10,-10)){
			printf("\nDerivada demasiado grande");
			return 0;
			
		}else{
			
			xNuevo = xViejo - (f(xViejo)/f_prima(xViejo));
			
			error = abs(xNuevo - xViejo);
		
			xViejo = xNuevo;
		}
		
		
		
	} while(error>tol && it<=10000);
	
	
	if(f(xNuevo < tol)){
		
		printf("\n\n\nLa raiz de f es: %.10lf", xNuevo);
		printf("\nEl valor del error en la raiz es de: %.10lf", error);
		printf("\nTomo %d iteraciones", it);
		
	}
	return 0;
}

double f(double x){
	return pow(x,2.3) - 1;
}

double f_prima(double x){
	
}

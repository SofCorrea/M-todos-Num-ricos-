//#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//using namespace std;

int main(int argc, char *argv[]) {
	double a[3][3]={{2,-1,3},{3,0,1},{-1,1,1}};
	double b[3]={9,6,4};
	double x[3], sum=0;
	double factor=0;
	
	int i=0,j=0,k=0,p=0,l=0,m=0;
	
	int prod=1, swap=0;
	
	// Triangulacion
	
	for(i=0; i<2; i++){
		
		for(j=i+1; j<3; j++){
			p=i;
			
			//
			if(abs(a[i][i])<10e-5){
				
				for(l=i+1; l<3;l++){
					if(abs(a[l][i])>abs(a[i][i])){
						p=l;
					}
				}
				
				for(m=0; m<3; m++){
					swap=a[p][m];
					a[p][m]=a[i][m];
					a[i][m]=swap;
				}
				
				swap=b[p];
				b[p]=b[i];
				b[i]=swap;
			}
			//
			
			factor = -(a[j][i]/a[i][i]);
			
			for(k=i; k<3; k++){
				
				a[j][k] = factor*a[i][k]+a[j][k]; // corrobora si es 0 el pivoteo parcial
				
			}
			
			b[j] = factor*b[i]+ b[j];
		}
	}
	
	
	// Chequeamos det(A) = ?
	
	for(i=0; i<3; i++){
		prod = prod * a[i][i];
	}
	
	if(prod == 0){ // det(A) = 0
		printf("\nEl sistema no tiene solucion unica.");
		return 1;
	}
	
	// Retrosustitucion
	
	x[2] = b[2] / a[2][2];
	
	for(i=2; i>-1; i--){ // decrementa
		sum = b[i];
		
		for(int j=i+1; j<3; j++){
			sum = sum - a[i][j] * x[j];
		}
		
		sum = sum / a[i][i];
		
		x[i] = sum;
		
	}
	
	for(i=0; i<3; i++){
		printf("%lf\t", x[i]);
		
	}
	/*
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%.2lf\t", a[i][j]);
		}
		printf("\n");
	}
	*/
	return 0;
}


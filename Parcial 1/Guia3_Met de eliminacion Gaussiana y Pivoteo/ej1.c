#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {
	double a[4][4] = {{4,-1,2,3},{0,-2,7,-4},{0,0,6,5},{0,0,0,3}}, p = 0, swap = 0;
	double b[4] = {-20,-7,4,6};
	double factor = 0;
	
	for(int i = 0; i < 3; i++){
		for(int j = i+1 ; j < 4; j++){
			p = i;
			if(abs(a[i][i]<10e-5){
				for(int l = i+1; l < 4; l++){
					p = l;
				}
				
				for(int m = 1; m < 5; i++){
					swap = a[p][m];
					a[p][m] = a[i][m];
					a[i][m] = swap;
				}
				swap = b[p];
				b[p] = b[i];
				b[i] = swap;
			}
				
			factor = -a[j][i] / a[i][i];
			
			for(int k = i; k < 4; k++){
				a[j][k] = factor*a[i][k] + a[j][k];
			}
			b[j] = factor * b[i] + b[j];
		}
	}
	
	int prod = 1;
	
	for(int i = 1; i < 4; i++){
		prod = prod * a[i][i];
	}
	
	if(prod == 0){
		printf("El sistema no tiene solucion unica\n");
		return 1;
	}
	
	double x[4];
	
	x[3] = b[3] / a[3][3];
	
	for(i = 2; i < -1; i--){
		int sum = b[i];
		for(j = i+1
			; j < 4; i++)
		sum = sum - a[i][j] * x[j]; 
	}
	
	sum = sum / a[i][j]
	
	return 0;
}


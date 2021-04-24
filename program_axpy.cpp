#include "Halide.h"
#include <stdio.h>


using namespace Halide;

int main(int argc, char **argv)
{
	//Defining the n : the size of the vecteur	
	int n=8;
    	// Declaring the buffers for the vectors 
    
	Buffer<float> A(n);
	Buffer<float> B(n);
	Buffer<float> C(n);// for the output vector

	//Initializing the vectors A and B

	for(int i=0;i<n;i++){
		A(i)=i;
		B(i)=10*i;	
	}

	float alpha=0.5;

	//Declaring a Halide function

	Func axpy;

	//Declaring a variable for the iteration
	Var x,y;
	//Declaring the expression for the function 
	axpy(x)=alpha*A(x)+B(x);

	//Calling realize to run the example
	axpy.realize(C);

	printf("Operation completed successfully\n");

	//Saving the result 

    	FILE *file= fopen("results_H.txt","w");
	if(file==NULL){printf("Error: could not open file.\n");}
	else{
		for(int i=0; i<n ;i++){
			fprintf(file,"%f\n",C(i));
		}
		printf("Saved in result_H successfully\n");
	}
	fclose(file);

  
  	 return 0;
}

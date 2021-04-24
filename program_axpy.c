#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    
   	//Defining the n : the size of the vecteur	
	int n=8;
    	// Declaring the buffers for the vectors 
    
	float A[n];
	float B[n];
	float C[n];// for the output vector

	//Initializing the vectors A and B

	for(int i=0;i<n;i++){
		A[i]=i;
		B[i]=10*i;	
	}
   
    	float alpha = 0.5;
	
	for(int i=0;i<n;i++){
		C[i]=alpha*A[i]+B[i];
	}
   	FILE *file= fopen("results_C.txt","w");
	if(file==NULL){printf("Error: could not open file.\n");}
	else{
		for(int i=0; i<n ;i++){
			fprintf(file,"%f\n",C[i]);
		}
		printf("Saved in result_C successfully\n");
	}
 
     
    	fclose(file);
    return 0;
}

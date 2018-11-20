/*
   Assignment 1
   
   Objective: calculate the factorial of a
   number N in terms of each prime number 
   times their factor occurs in N!.
   
   
   Name: Jingchao Wu
   
*/

#include<stdio.h>
/* function prototype */
 int find_prime_count(int,int);
 int find_next_prime(int);
 int is_prime(int);
 

/* main program function */ 
int main(void)
{
	int n=1;
	int prime;
	int factor;
	int count;
	//open a txt file named input.txt
	FILE *fp;
	fp = fopen("input.txt", "r"); 
	while(!feof(fp))
{
	fscanf(fp,"%d",&n);	// input the number from input.txt file
	
	 if(n>0)
    {
	  	
		
	  printf("\n%d! = ", n);
	  //initilize prime to 2
	  prime=2;
	  
	   while(prime<=n){
		   count=0;
		   //find all prime number with all their factors
		   for(factor = n; factor > 1; factor--)    {
			   if(prime<=factor){
			   
					count += find_prime_count(factor,prime);  //find the count of current prime number
					
					}
			}
		
		   
	     //print out the formula sets
		  if (prime == 2)
                printf(" (%d^%d)", prime, count);
            else
                printf("*(%d^%d)", prime, count);
	    
	 
		
		//find the next prime number
		 prime = find_next_prime(prime);
		
		
	   }
		printf("\n");
        
	}
 }	 
	return 0;
}


 //Determine the count of given prime number
 // INPUT: a positive integer num and a prime number
 // OUTPUT: counts of prime occur in number 
  int find_prime_count(int num, int prime){
	  int primeFreq=0;
	while(num%prime==0)
	{
		primeFreq += 1;
		num /= prime;
		
	}
	 
	 return primeFreq;
	 
	
  }
  
  //Determine the next prime number of given number
  //INPUT: a positive prime integer a
 // OUTPUT: prime number > a
 int find_next_prime(int a){
	 int b=a+1;
	 for(;;)
	 {
		 if(is_prime(b)==1) return b;
		 else b++ ;
			 }
 }
 
 //Determine whether a given number is prime or not
 //INPUT: a positive integer n
 //OUTPUT: 1 for n is prime, 0 for otherwise
 int is_prime(int n){
	 int i;
	 int j=0;
	 for(i=2;i<n;i++){
		 j = n % i;
		 if(j==0) return 0;
	 }
	 
	 return 1;
	 
  }
 
 
 
 
 
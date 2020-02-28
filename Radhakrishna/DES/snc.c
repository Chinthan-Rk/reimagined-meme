#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <time.h>

int next;

int isPrime(int n)  
{  
    // Corner cases  
    if (n <= 1)  return 0;  
    if (n <= 3)  return 1;  
    
    // This is checked so that we can skip   
    // middle five numbers in below loop  
    if (n%2 == 0 || n%3 == 0) return 0;  
    
    for (int i=5; i*i<=n; i=i+6)  
        if (n%i == 0 || n%(i+2) == 0)  
           return 0;  
    
    return 1;  
}  

int nextPrime()
{
	if (next <= 1) 
        return 2; 
  
    int prime = next; 
    int found = 0; 
  
    // Loop continuously until isPrime returns 
    // true for a number greater than next

    while (!found) { 
        prime++; 
  
        if (isPrime(prime)) 
            found = 1; 
    } 
  
    return prime;
}

int beforePrime()
{
	if (next <= 2) 
        return 2; 
  
    int prime = next; 
    int found = 0; 
  
    // Loop continuously until isPrime returns 
    // true for a number lesser than next 
    while (!found) { 
        prime--; 
  
        if (isPrime(prime)) 
            found = 1; 
    } 
  
    return prime;
}



int main()
{
	int n;
	printf("Enter n :");
	scanf("%d", &n);

	int carry[5],modArray[5];
	next = n;


	// for (int a = 0; a < 5; a++)
	// 	carry[a]=0;
		
	// for (int a = 0; a < 5; a++)
	// 	printf("%d  ", carry[a]);

	for(int a =2 ;a<5;a++)
		{
			carry[a]=nextPrime();
			next = carry[a];
		}
	next = n;

	for(int a=1;a>=0;a--)
	{
		carry[a] = beforePrime();
		next = carry[a];
	}
	
	printf("\nNext = %d \n",next);
	for (int a = 0; a < 5; a++)
		printf("%d  ", carry[a]);


    int rangeSize = pow(2,n);

    srand(time(0));   
    int randNum = 14;//rand()%rangeSize;
    printf("\n");
    for(int i=0;i<5;i++)
    {
        modArray[i] = randNum%carry[i];
        printf("%d ",modArray[i]);
    }



    

	return 0;
}

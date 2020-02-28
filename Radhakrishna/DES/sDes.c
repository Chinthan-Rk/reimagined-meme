#include<stdio.h>

int *keyGeneration(int key[],int P10[],int P8[])
{
    //XOR 10bit key with P10

    int temp1[10];

    for(int i=0;i<10;i++)
    temp1[i] = key[i] ^ P10[i];

    //split temp1 by 5bits and left shift
}

int main()
{

    int key[10];
    int P10[10] ={
                    3,5,2,7,4,10,1,9,8,6
                 };

    int P8 = {
                6,3,7,4,8,5,10,9
             };

    printf("Enter the 10bit key : ");
    for(int i=0;i<10;i++)
    scanf("%d",key[i]);

    int *keys = keyGeneration(key,P10,P8);


}
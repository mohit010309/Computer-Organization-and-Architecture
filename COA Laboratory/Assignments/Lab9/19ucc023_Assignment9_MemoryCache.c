//Name= Mohit Akhouri
//Roll no= 19ucc023
//Assignment 9 -Memory_Cache
//COA LAB Friday batch ( 9-11 am )
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void binary(int x);
void binary(int x) //function to convert a integer 'x' to binary
{
    int arr[100];
    int i=0;
    while(x!=0)
    {
        arr[i]=x%2;
        x=x/2;
        i++;
    }
    int j;
    for(j=i-1;j>=0;j--)
    {
        printf("%d",arr[j]);
    }
    printf("\n");
}
void main()
{
    //defining given information below
	int totalWords=8192;
	int wordSize=16;
	int totalCache=1024;
	int cblocks=64;

	float CacheBlocks = totalCache/cblocks;
	float WordBits=log(cblocks)/log(2);
	float BlockBits=log(CacheBlocks)/log(2);
    float TagBits=(log(totalWords)/log(2))-BlockBits-WordBits;

    //First part starts here
	printf("No. of blocks in cache are : %.0f\n", CacheBlocks);
	printf("No. of bits required for words is : %.0f\n", WordBits);
	printf("No. of bits required for blocks is : %.0f\n", BlockBits);
	printf("No. of bits for tag is : %.0f\n", TagBits);

	//second part begins here
	int input;
	printf("Enter memory address : ");
	scanf("%d",&input);
	printf("Equivalent binary value of %d is : ",input);
	binary(input);

	int x=((input%(int)(CacheBlocks))*2-1)+(input%2)-1;
	int y=input%(int)CacheBlocks;

	//printing information obtained in binary form
	printf("Word is given by : ");
	binary(x);
	printf("Block is given by : ");
	binary(y);

}


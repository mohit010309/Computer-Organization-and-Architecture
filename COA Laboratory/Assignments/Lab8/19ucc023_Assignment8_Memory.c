//Name         = Mohit Akhouri
//Roll no      = 19ucc023
//Assignment 8 = Memory.c
//Subject      = COA Lab
//Lab Batch    = Friday Batch ( 9-11 am)

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void binaryConverter(int x); //for converting decimal number x to binary by appending 0's
void CacheBinary(int x); // for converting decimal number x to binary without appending 0's
void MemoryAddressOrganization(int Memory_Address,int AddressSpace,int Cache_Blocks); // for printing memory information
void CacheBinary(int x)
{
	int arr[100],i=0;
	while(x!=0)
    {
        arr[i]=x%2;
        x=x/2;
        i++;
    }
    i=i-1;
    printf("Binary value is : ");
    while(i>=0)
    {
        printf("%d",arr[i]);
        i--;
    }
    printf("\n");
}
void binaryConverter(int x)
{
    int arr[10];
    int i,j;
    for(i=0;i<10;i++)
        arr[i]=0;
    i=9;
    while(x!=0)
    {
        arr[i]=x%2;
        x=x/2;
        i--;
    }
    //printing the binary form of the decimal number
    for(i=0;i<10;i++)
        printf("%d",arr[i]);
    printf("\n");

}
void MemoryAddressOrganization(int Memory_Address,int AddressSpace,int Cache_Blocks)
{
    printf("Enter memory address (Integer format) : ");
	scanf("%d", &Memory_Address);
	binaryConverter(Memory_Address);
	printf("Details of memory organization is : \n");
	printf("Main memory block is: %d\n", Memory_Address/AddressSpace);
	printf("Cache memory block is: %d\n", Memory_Address%Cache_Blocks);
	printf("Word is given by: ");
	CacheBinary(((Memory_Address%Cache_Blocks)*2-1)+(Memory_Address%2)-1);
	printf("Block is given by: ");
	CacheBinary((Memory_Address%Cache_Blocks));
	printf("\n");
}
void main()
{

    /*binaryConverter(3);
    CacheBinary(10);*/
	int AddressSpace = 16384;
	int WordSize = 16;
	int CacheAddressSpace = 2048;
	int cacheWordsBlock = 64;
	int BytesPerWord = AddressSpace / 8;

	int Cache_bytesPerBlock = (cacheWordsBlock * WordSize)/8;
	int Offset = log(Cache_bytesPerBlock)/log(2);
	int Set_Size = log(AddressSpace)/log(2);
	int Cache_Blocks = CacheAddressSpace/cacheWordsBlock;
	int tagSize = Set_Size - (log(Cache_Blocks)/log(2)) - (log(cacheWordsBlock)/log(2));

	int Memory_Address;
	float wordsBits=log(cacheWordsBlock)/log(2);
	float blockBits=log(Cache_Blocks)/log(2);

	printf("\n");
	printf("No. of blocks in the cache are : %d\n", Cache_Blocks);
	printf("No. of bits required for words is : %.0f\n", wordsBits);
	printf("Number of bits required for block is: %.0f\n", blockBits);
	printf("Number of bits required for tag is: %d\n", tagSize);

	MemoryAddressOrganization(Memory_Address,AddressSpace,Cache_Blocks);
	printf("\n");

}


#include <stdio.h>
#include <stdlib.h>
//Name = Mohit Akhouri
//Roll no = 19ucc023
//Lab = Friday ( 9-11am)
//Assignment 7 - Pipeline
int checkHazard(int i1[],int i2[],int a,int b);
void main()
{
    //4 bit register, 3 bit opcode
    //LOAD=000 SUB=001 AND=010
    //R1=0001, R2=0010, R3=0011, R8=1000

    int i1[]={0,0,0, 0,0,0,0, 0,0,0,1, 0,0,1,0};
    int i2[]={0,0,1, 0,0,1,1, 0,0,1,0, 0,0,1,0};
    int i3[]={1,1,1, 0,0,0,0, 0,0,0,0, 0,0,0,0};
    int i4[]={0,1,0, 0,0,1,0, 0,0,1,1, 1,0,0,0};
    if(checkHazard(i1,i2,1,2))
    {
        printf("Type of hazard = Read after write ( RAW )\n");
        printf("Caused due to instruction 1 and 2\n");
        printf("Caused due to register R2 ( 0010 )\n");
    }
    else if(!checkHazard(i2,i3,2,3))
    {
        printf("\nData hazard due to instruction 2 and 3\n");
    }
    else if(checkHazard(i3,i4,3,4))
    {
        printf("\nData hazard due to instruction 3 and 4");
    }
}
int checkHazard(int i1[],int i2[],int a,int b)
{
    int i;
    if(a==1 && b==2)//for checking instruction 1 and 2
    {
        for(i=11;i<15;i++)
        {
            if(i1[i]!=i2[i-4])
                return 0;
        }
        return 1;
    }
    else if(a==2 && b==3)//for checking instruction 2 and 3
    {
        for(i=0;i<15;i++)
        {
            if(i2[i]!=0)
                return 0;
        }
        return 1;
    }
    else if(a==3 && b==4)//for checking instruction 3 and 4
    {
        int f1=0,f2=0,f3=0;
        for(i=3;i<7;i++)//checking the first register for hazard
        {
            if(i1[i]!=i2[i])
                f1=1;
        }
        for(i=7;i<11;i++)//checking the second register for hazard
        {
            if(i1[i]!=i2[i])
            {
                f2=1;
            }
        }
        for(i=11;i<15;i++)//checking the third register for hazard
        {
            if(i1[i]!=i2[i])
                f3=1;
        }
        if(f1==1 && f2==1 && f3==1)
            return 0;
        else
            return 1;
    }
}

#include<stdio.h>
void main()
{
    int a,b,ch;
    printf("enter the two number:");
    scanf("%d%d",&a,&b);
    printf("\n1. +");
    printf("\n2. -");
    printf("\n3. *");
    printf("\n4. /");
    printf("\nenter the choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
       printf("result=%d",a+b);
       break;
      case 2:
       printf("result=%d",a-b);
       break;
      case 3:
       printf("result=%d",a*b);
       break;
      case 4:
       printf("result=%d",a/b);
       break;
      default:
       printf("invalid choice");
    }
}       

    
     
#include<stdio.h>
#include"stack.h"
int max=5;
int buff[20];
int top=-1;
int main()
{
int val;
while(1)
{
int ch;
printf("Enter choice: 1.push 2.pop\n");
scanf("%d",&ch);
switch(ch)
{
	case 1:
		printf("enter value:\n");
		scanf("%d",&val);
		push(val);
		break;
	case 2:
		printf(" Poped: %d\n",pop());
		break;
	default:
		printf("enter corresct choice!\n");
		break;
}
}

return 0;
}

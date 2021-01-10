extern int buff[20];
extern int top;
int pop(void)
{
//stack underflow
 if(top==-1)
{
	printf("Stack underflow");
	return -1;
}

int a=buff[top--];
return a;
}

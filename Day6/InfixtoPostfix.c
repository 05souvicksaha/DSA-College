#include<stdio.h>
#include<ctype.h>

typedef struct conversion
{
	char a[40];
	int  top;
}stack;

void push(stack*,char);

char pop(stack*);

void convert(char[],char[]);

int priority(char);

int main()
{
	char infix[40],postfix[40];
	printf("\nENTER INFIX EXPRESSION\n");
	scanf("%s",infix);
	convert(infix,postfix); //call convert function
	printf("\nPOSTFIX EXPRESSION \n%s\n",postfix);
	return 0;
}

void convert(char in[40],char post[40])
{
	char opr;
	stack s1;
	int j=0,i;
	s1.top=-1;
	for(i=0;in[i]!='\0';i++)
	{
		if(isalpha(in[i]))
			post[j++]=in[i];
		if(in[i]=='(')
			push(&s1,in[i]);
		if(in[i]=='+'||in[i]=='-'||in[i]=='/'||in[i]=='*' || in[i] == '^')
		{
			if(s1.top!=-1)
			{
				opr=pop(&s1);
			    while(priority(opr)>=priority(in[i])) //call priority function
			    {
					post[j++]=opr;
					opr=pop(&s1);
				}
				push(&s1,opr);
				push(&s1,in[i]);
			}
			else
				push(&s1,in[i]);
		}
		if(in[i]==')')
		{
			opr=pop(&s1);
			while(opr!='(')
			{
				post[j++]=opr;
				opr=pop(&s1);
			}
		}
	}
	while(s1.top!=-1)
		post[j++]=pop(&s1);
	post[j]='\0';
}

int priority(char c)
{
	if(c=='~' || c== '^')
		return 3;
	if(c=='*'||c=='/')
		return 2;
	if(c=='+'||c=='-')
		return 1;
	else
		return 0;
}

void push(stack *s,char opr)
{
	//push element into stack
	s->top++;
	s->a[s->top]=opr;
}

char pop(stack *s)
{
	//pop element from stack
	if (s->top==-1)
	{
		return 0;
    }
    else
    {
		char data=s->a[s->top--];
		return data;
    }
}

/*

OUTPUTS:
-------------------------------
ENTER INFIX EXPRESSION
(A+(B*C))/(C-(D*B))

POSTFIX EXPRESSION
ABC*+CDB*-/
--------------------------------
ENTER INFIX EXPRESSION
A+B-(C*D/E)

POSTFIX EXPRESSION
AB+CD*E/-
--------------------------------
ENTER INFIX EXPRESSION
A+(B*C-(D/E^F)*G)*H

POSTFIX EXPRESSION
try to check
--------------------------------
*/

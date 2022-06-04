#### Rules for Infix to Prefix using stack DS 
1. Reverse infix expression & swap ‘(‘ to ”)’ & ‘)’ to ”(‘
2. Scan Expression from Left to Right
3. Print OPERANDs as the arrive
4. If OPERATOR arrives & Stack is empty, PUSH to stack
5. IF incoming OPERATOR has HIGHER precedence than the TOP of the Stack, PUSH it on stack
6. IF incoming OPERATOR has EQUAL precedence with TOP of Stack && incoming OPERATOR is ‘^’,  POP & PRINT TOP of Stack. 
   Then test the incoming OPERATOR against the NEW TOP of stack.
7. IF incoming OPERATOR has EQUAL precedence  with TOP of Stack, PUSH it on Stack.
8. IF incoming OPERATOR has LOWER precedence than the TOP of the Stack, then POP and PRINT the TOP. 
   Then test the incoming OPERATOR against the NEW TOP of stack.
9.  At the end of Expression, POP & PRINT all OPERATORS from the stack
10. IF incoming SYMBOL is ‘(‘ PUSH it onto Stack.
11. IF incoming SYMBOL is ‘)’ POP the stack & PRINT  OPERATORs till ‘(‘ is found or Stack Empty.  POP out that ‘(‘ from stack
12. IF TOP of stack is ‘(‘ PUSH OPERATOR on Stack
13. At the end Reverse output string again.

![image](https://user-images.githubusercontent.com/95578805/171982158-71d6a8ce-8d5f-4ccd-8e5f-aeb2717b8176.png)
![image](https://user-images.githubusercontent.com/95578805/171982170-c2d8d419-fb31-45ea-b8f5-803b2127e881.png)

```

#define SIZE 50            /* Size of Stack */
#include<string.h>
#include <ctype.h>
char s[SIZE];
int top=-1;       /* Global declarations */

push(char elem)
{                       /* Function for PUSH operation */
    s[++top]=elem;
}

char pop()
{                      /* Function for POP operation */
    return(s[top--]);
}

int pr(char elem)
{                 /* Function for precedence */
    switch(elem)
    {
    case '#': return 0;
    case ')': return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 3;
    }
}
void reverse(char *exp){

    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}
main()
{                         /* Main Program */
    char infx[50]="((a/b)+c)-(d+(e*f))",prfx[50],ch,elem;
    int i=0,k=0;
    printf("\n\nRead the Infix Expression ? ");
    push('#');
    reverse(infx);
    while( (ch=infx[i++]) != '\0')
    {
        if( ch == ')') push(ch);
        else
            if(isalnum(ch)) prfx[k++]=ch;
            else
                if( ch == '(')
                {
                    while( s[top] != ')')
                        prfx[k++]=pop();
                    elem=pop(); /* Remove ) */
                }
                else
                {       /* Operator */
                    while( pr(s[top]) >= pr(ch) )
                        prfx[k++]=pop();
                    push(ch);
                }
    }
    while( s[top] != '#')     /* Pop from stack till empty */
        prfx[k++]=pop();
    prfx[k]='\0';          /* Make prfx as valid string */
    
        reverse(infx); 
        reverse(prfx);
        
    printf("\n\nGiven Infix Expn: %s  Prefix Expn: %s\n",infx,prfx);
}

```

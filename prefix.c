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
        reverse(infx);    reverse(prfx);
    printf("\n\nGiven Infix Expn: %s  Prefix Expn: %s\n",infx,prfx);
}
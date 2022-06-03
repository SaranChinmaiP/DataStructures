#### Infix to Postfix Conversion
Assume the infix expression is a string of tokens delimited by spaces. The operator tokens are *, /, +, and -, along with the left and right parentheses, ( and ). The operand tokens are the single-character identifiers A, B, C, and so on. The following steps will produce a string of tokens in postfix order.
```
Create an empty stack called opstack for keeping operators. Create an empty list for output.

Convert the input infix string to a list by using the string method split.

Scan the token list from left to right
  1.  If the token is an operand, append it to the end of the output list.
  2.  If the token is a left parenthesis, push it on the opstack.
  3.  If the token is a right parenthesis, pop the opstack until the corresponding left parenthesis is
      removed. Append each operator to the end of the output list.
  4.  If the token is an operator, *, /, +, or -, push it on the opstack. However, 
      first remove any operators already on the opstack that have higher or equal precedence and append them to the output list.

      When the input expression has been completely processed, check the opstack. 
      Any operators still on the stack can be removed and appended to the end of the output list.
    
```
![image](https://user-images.githubusercontent.com/95578805/171882607-8c175dad-fe50-4ddf-a8b6-795cc54a8512.png)

##### Example
```
1. Infix expression  : A+(B*C-(D/E^F)*G)*H
   Postfix Expression: ABC*DEF^/G*-H*+
  
2. Infix expression  : (3^2*5)/(3*2-3)+5
   Postfix Expression: 32^5*32*3-/5+

```

#### Program in C 
```
#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
}

```

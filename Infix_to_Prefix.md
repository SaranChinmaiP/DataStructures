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

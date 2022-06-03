#### Infix to Postfix Conversion
Assume the infix expression is a string of tokens delimited by spaces. The operator tokens are *, /, +, and -, along with the left and right parentheses, ( and ). The operand tokens are the single-character identifiers A, B, C, and so on. The following steps will produce a string of tokens in postfix order.
<code>
Create an empty stack called opstack for keeping operators. Create an empty list for output.

Convert the input infix string to a list by using the string method split.

Scan the token list from left to right
  1.  If the token is an operand, append it to the end of the output list.
  2.  If the token is a left parenthesis, push it on the opstack.
  3.  If the token is a right parenthesis, pop the opstack until the corresponding left parenthesis is removed. Append each operator to the end of the output list.
  4.  If the token is an operator, *, /, +, or -, push it on the opstack. However, first remove any operators already on the opstack that have higher or equal precedence and append them to the output list.

When the input expression has been completely processed, check the opstack. Any operators still on the stack can be removed and appended to the end of the output list.
</code>

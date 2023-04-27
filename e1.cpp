#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<ctype.h>
#include<fstream>
using namespace std;

string arr[] = { "void", "using", "namespace", "int", "include", "iostream", "std", "main",
"cin", "cout", "return", "float", "double", "string" };

bool
isKeyword (string a)
{
  for (int i = 0; i < 14; i++)
    {
      if (arr[i] == a)
	{
	  return true;
	}
    }
  return false;
}

int main() 
{ 

	fstream file; 
	string s, filename; 

	filename = "./add"; 

	file.open(filename.c_str()); 

	while (file >> s) 
	{
        if (s == "+" || s == "-" || s == "" || s == "/" || s == "^" || s == "&&" || s == "||" || s == "=" || s == "==" || s == "&" || s == "|" || s == "%" || s == "++" || s == "--" || s == "+=" || s == "-=" || s == "/=" || s == "=" || s == "%=")
	    {
	      cout << s << " is an operator\n";
	      s = "";
	    }
	  else if (isKeyword (s))
	    {
	      cout << s << " is a keyword\n";
	      s = "";
	    }
	  else if (s == "(" || s == "{" || s == "[" || s == ")" || s == "}" || s == "]" || s == "<" || s == ">" || s == "()" || s == ";" || s == "<<" || s == ">>" || s == "," || s == "#")
	    {
	      cout << s << " is a symbol\n";
	      s = "";

	    }
	  else if (s == "\n" || s == " " || s == "")
	    {
	      s = "";

	    }
	  else if (isdigit (s[0]))
	    {
	      int x = 0;
	      if (!isdigit (s[x++]))
		{
		  continue;
		}
	      else
		{
		  cout << s << " is a constant\n";
		  s = "";
		}
	    }
	  else
	    {
	      cout << s << " is an identifier\n";
	      s = "";
	    } 
	} 

	return 0; 
} 

/*
Input

#include <stdio.h>

int main ( )

{
    int x = 6 ;
    int y = 4 ;
    x = x + y ;
    printf("%d", x);
    return 0;
}

Output

#include is an identifier
<stdio.h> is an identifier
int is a keyword
main is a keyword
( is a symbol
) is a symbol
{ is a symbol
int is a keyword
x is an identifier
= is an operator
6 is a constant
; is a symbol
int is a keyword
y is an identifier
= is an operator
4 is a constant
; is a symbol
x is an identifier
= is an operator
x is an identifier
+ is an operator
y is an identifier
; is a symbol
printf("%d", is an identifier
x); is an identifier
return is a keyword
0; is a constant
} is a symbol

*/







#include <iostream>
#include <iomanip>

// LinkStack implementation (not provided in the code)
#include "atink.h"

void pranethesisChecker(char *exp);
char getMatchingSymbol(char ch);

int main()
{
    char charExpression[80];
    std::cout << "\nEnter any expression\n\n";
    std::cin.getline(charExpression, 80);
    pranethesisChecker(charExpression);
    return 0;
}

void pranethesisChecker(char *exp)
{
    char ch;
    LinkStack<char> charStack;

    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            charStack.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (charStack.isEmpty())
            {
                std::cout << "\nError: No matching open symbol";
                return;
            }
            else
            {
                ch = charStack.pop();
                if (ch != getMatchingSymbol(exp[i]))
                {
                    std::cout << "\nError: Incorrect nesting of symbols";
                    return;
                }
            }
        }
        i++;
    }

    if (!charStack.isEmpty())
    {
        std::cout << "\nError: Missing closing symbol(s)";
        return;
    }
    else
    {
        std::cout << "\nInput Expression is OK";
    }
}

char getMatchingSymbol(char ch)
{
    char matchingChar;
    switch (ch)
    {
    case ')':
        matchingChar = '(';
        break;
    case '}':
        matchingChar = '{';
        break;
    case ']':
        matchingChar = '[';
        break;
    default:
        matchingChar = '\0';
        break;
    }
    return matchingChar;
}


// C++ Program to remove the character left to a '+' using stack ADT

#include <iostream>
#include <string.h>
#include "stack_ll.h"
using namespace std;

string pop_plus(string);

int main()
{
    char input[100];
    printf("Enter input string: ");
    scanf("%s", input);

    string result = pop_plus(input);
    printf("%s", result.c_str());
}

string pop_plus(string input)
{
    Stack stack;
    string output;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] != '+')
        {
            stack.push(input[i]);
        }
        else
        {
            stack.pop();
        }
    }
    while (stack.peek() != '\0')
    {
        output += stack.pop();
    }
    int num = output.length();
    for (int i = 0; i < num / 2; i++)
    {
        char temp = output[i];
        output[i] = output[num - i - 1];
        output[num - i - 1] = temp;
    }
    return output;
}

// Time Complexity = O(n)

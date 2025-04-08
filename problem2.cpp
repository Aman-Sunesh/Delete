#include <iostream>
#include <stack>

using namespace std;

bool arePair(char opening, char closing) 
{
    if (opening == '(' && closing == ')') 
    {
        return true;
    } 

    else if (opening == '{' && closing == '}') 
    {
        return true;
    } 
    
    else if (opening == '[' && closing == ']') 
    {
        return true;
    }
    
    return false;
}

int braces(const char* A) 
{
    stack<char> s;
    int count = 0;

    for (int i = 0; A[i] != '\0'; i++) 
    {
        char ch = A[i];

        if (ch == ')' || ch == ']' || ch == '}') 
        {
            bool hasOperator = false;

            // Check inside the brackets
            while (!s.empty() && !arePair(s.top(), ch)) 
            {
                char top = s.top();
                s.pop();

                if (top == '+' || top == '-' || top == '*' || top == '/')
                    hasOperator = true;
            }

            // If stack is empty before finding a matching opening bracket
            if (s.empty()) 
            {
                return -1; 
            }

            s.pop(); // Pop the matching opening bracket

            if (!hasOperator) 
            {
                count++;
            }

        }
        
        else 
        {
            s.push(ch);
        }
    }

    return (count > 0) ? 1 : 0;
}

int main() {
    const char* A = "((a+b))";        
    const char* B = "(a+(a+b))";    
    const char* C = "((a*b)+(c+d))";    
    const char* D = "(a)";            
    const char* E = "((a)+(b))";     

    cout << braces(A) << endl; 
    cout << braces(B) << endl; 
    cout << braces(C) << endl; 
    cout << braces(D) << endl; 
    cout << braces(E) << endl; 

    return 0;
}

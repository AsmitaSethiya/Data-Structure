#include<iostream>
#include<string.h>
#include<stack>

using namespace std;

bool isBalanced(string s)
{
    stack<char> st;
    
    int len = s.size();
    
    bool ans = true;
    
    for(int i = 0; i < len; i++)
    {
        if(s[i] == '(' or s[i] == '{' or s[i] == '[')
        {
            st.push(s[i]);
        }
        else if(s[i] == ')')
        {
            if(!st.empty() and st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if(s[i] == ']')
        {
            if(!st.empty() and st.top() == '[')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if(s[i] == '}')
        {
            if(!st.empty() and st.top() == '{')
            {
               st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    
    if(!st.empty())
    {
        return false;
    }
    else
    {
        return ans;
    }
}


int main()
{
    string s = "{[()]}}";
    
    if(isBalanced(s))
    {
        cout<<"Parenthesis is Balanced";
    }
    else
    {
        cout<<"Parenthesis is unbalanced";
    }
    
    return 0;
}

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (st.empty())
        {
            st.push(ch);
        }
        else if (st.top() == '(' && ch == ')' || st.top() == '[' && ch == ']' || st.top() == '{' && ch == '}')
        {
            st.pop();
        }
        else
        {
            st.push(ch);
        }
    }
    if (st.empty())
    {
        return true;
    }
    return false;
}
int main(int argc, char const *argv[])
{

    string str = "[(])";

    cout << isValid(str);

    return 0;
}

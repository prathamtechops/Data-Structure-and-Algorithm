#include <iostream>
using namespace std;

class Stack
{
    int top;
    int *array;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        array = new int[size];
    }
    void push(int data)
    {
        if (size - top > 1)
            array[++top] = data;
        else
            cout << "Stack Overflow" << endl;
    }
    void pop()
    {
        if (top >= 0)
            top--;
        else
            cout << "Stack Undifiend: " << endl;
    }
    void peek()
    {
        cout << array[top];
    }
};

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
        else if (st.top() == '(' && ch == ')' ||
                 st.top() == '[' && ch == ']' ||
                 st.top() == '{' && ch == '}')
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
    Stack s(4);
    s.push(1);
    s.peek();
    s.push(2);
    s.push(2);
    s.push(2);
    s.push(2);

    return 0;
}
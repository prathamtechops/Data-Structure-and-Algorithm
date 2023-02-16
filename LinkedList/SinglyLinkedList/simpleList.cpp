#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main(int argc, char const *argv[])
{
    node *head = new node();
    head->data = 0;
    head->next = NULL;

    node *second = new node();
    second->data = 1;
    second->next = NULL;

    head->next = second;

    node *third = new node();
    third->data = 2;
    third->next = NULL;

    second->next = third;

    print(head);

    return 0;
}
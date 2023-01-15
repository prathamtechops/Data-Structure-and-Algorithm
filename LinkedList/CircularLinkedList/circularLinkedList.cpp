#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(node *&tail, int data)
{
    node *newNode = new node(data);
    if (!tail)
    {
        tail = newNode;
        tail->next = tail;
        return;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

void insertAtTail(node *&tail, int data)
{
    node *newNode = new node(data);
    if (!tail)
    {
        tail = newNode;
        tail->next = tail;
        return;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void delateNode(node *&tail)
{
    node *temp = tail->next;
    tail = tail->next->next;
    delete temp;
}

int main(int argc, char const *argv[])
{

    return 0;
}
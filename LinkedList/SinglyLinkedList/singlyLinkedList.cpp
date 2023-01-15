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
void insertAtHead(node *&head, node *&tail, int data)
{
    node *temp = new node(data);
    if (!head)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
void insertAtTail(node *&head, node *&tail, int data)
{
    node *temp = new node(data);
    if (!tail)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
void insertAtPosition(node *&head, node *&tail, int data, int pos)
{
    node *newNode = new node(data);
    if (pos == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    node *prev = NULL;
    node *cur = head;
    int count = 1;
    while (pos > count)
    {
        prev = cur;
        cur = cur->next;
        count++;
    }
    if (cur->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }
    prev->next = newNode;
    newNode->next = cur;
}

void deleteNode(node *&head, node *&tail, int pos)
{
    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        node *prev = NULL;
        node *cur = head;
        int count = 1;
        while (pos > count)
        {
            prev = cur;
            cur = cur->next;
            count++;
        }
        if (cur->next == NULL)
        {
            prev->next = cur->next;
            tail = prev;
        }
        else
        {
            prev->next = cur->next;
        }
        delete cur;
    }
}

void print(node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main(int argc, char const *argv[])
{

    node *node1 = new node(1);
    node *head = node1;
    node *tail = node1;
    insertAtTail(head, tail, 5);
    insertAtHead(head, tail, 0);
    insertAtPosition(head, tail, 4, 2);
    insertAtPosition(head, tail, 10, 4);
    print(head);

    return 0;
}
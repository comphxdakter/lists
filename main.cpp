#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node **head,int data)
{
    Node *tmp = new Node;
    tmp->data = data;
    tmp->next = (*head);
    (*head) = tmp;
}

int pop(Node **head)
{
    Node *prev = nullptr;
    int val;
    if(head == nullptr)
    {
        exit(-1);
    }
    prev = (*head);
    val = prev->data;
    (*head) = (*head)->next;
    delete(prev);
    return val;
}

Node *getNth(Node *head,int n)
{
    int counter = 0;
    while(head!=nullptr && counter < n)
    {
        head = head->next;
        counter++;
    }
    return head;
}
Node *getLast(Node *head)
{
    if(head == nullptr)
    {
        return nullptr;
    }
    while(head->next)
    {
        head=head->next;
    }
    return head;
}
void show(const Node *head)
{
    while(head!=nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

void pushBack(Node *head,int data)
{
    Node *last = getLast(head);
    Node *tmp = new Node;
    tmp->data = data;
    tmp->next = nullptr;
    last->next = tmp;
}

Node *getLasByOne(Node *head)
{
    if(head == nullptr)
    {
        exit(-2);
    }
    if(head->next==nullptr)
    {
        return nullptr;
    }
    while(head->next->next)
    {
        head = head->next;
    }
    return head;
}

void popBack(Node **head)
{
    Node *lastbn = nullptr;
    if(!head)
    {
        exit(-1);
    }
    if(!(*head))
    {
        exit(-1);
    }
    lastbn = getLasByOne(*head);
    if(lastbn==nullptr)
    {
        delete(*head);
        *head = nullptr;
    } else{
        delete(lastbn->next);
        lastbn->next = nullptr;
    }
}

int main() {
    Node *head=nullptr;
    pushBack(head,10);
    pushBack(head,2);
    pushBack(head,3);
    show(head);
    return 0;
}

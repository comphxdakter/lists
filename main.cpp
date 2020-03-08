#include <iostream>
#include <list>
#include <ctime>
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
        cout << head->data << "->";
        head = head->next;
    }
    cout << "nullptr\n";
}

Node /***/pushBack(Node **head,int data)
{

//    Node *last = getLast(head);
//    Node *tmp = new Node;
//    tmp->next = nullptr;
//    tmp->data = data;
//    last->next = tmp;

//    Node *newel = new Node;
//    newel->data = data;
//    newel->next = nullptr;
//    if(head==nullptr)return newel;
//    Node *temp = head;
//    while(temp->next)
//    {
//        temp=temp->next;
//    }
//    temp->next=newel;
//    return head;
    Node *last = getLast(*head);
    Node *tmp = new Node;
    tmp->data = data;
    tmp->next = nullptr;
    if(last == nullptr)
    {
        *head = tmp;
    }
    else
    {
        last->next = tmp;
    }
}
Node *getLastButOne(Node *head)
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
    lastbn = getLastButOne(*head);
    if(lastbn==nullptr)
    {
        delete(*head);
        *head = nullptr;
    } else{
        delete(lastbn->next);
        lastbn->next = nullptr;
    }
}
void insert(Node *head,unsigned n,int data)
{
    unsigned i = 0;
    Node *tmp = nullptr;
    while(i<n && head->next)
    {
        head=head->next;
        i++;
    }
    tmp=new Node;
    tmp->data=data;
    if(head->next)
    {
        tmp->next = head->next;
    }else{
        tmp->next = tmp;
    }
    head->next=tmp;
}
int main() {
//    srand(time(nullptr));
//    list<int> mylist;
//    for (int i = 0; i < 10; ++i) {
//        mylist.push_back(rand()%10);
//    }
//    mylist.sort();
//    int i = 0;
//    for(auto it = mylist.begin();it!=mylist.end();++it,i++)
//    {
//        cout << "list<" << i << ">" << *it << endl;
//    }

//    Node *head=nullptr;
//    head=pushBack(head,12);
//    head=pushBack(head,11);
//    head=pushBack(head,10);
//    show(head);
    Node *hued=nullptr;
    push(&hued,12);
    push(&hued,11);
    push(&hued,10);
    show(hued);
    Node *head=nullptr;
    pushBack(&head,12);
    pushBack(&head,11);
    pushBack(&head,10);
    insert(head,1,9999);
    show(head);
    return 0;
}
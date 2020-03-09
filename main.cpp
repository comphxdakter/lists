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
void /***/pushBack(Node **head,int data)
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
int deleteNth(Node **head,int n)
{
    if(n==0)
    {
        return pop(head);
    } else
    {
        Node *prev = getNth(*head,n-1);
        Node *elm = prev->next;
        int data = elm->data;
        prev->next=elm->next;
        delete(elm);
        return data;
    }
}
void deleteList(Node **head)
{
    while ((*head)->next)
        {
        pop(head);
        *head = (*head)->next;
    }
    delete(*head);
}
void fromArray(Node **head,int *arr,size_t size)
{
    size_t i = size - 1;
    if(arr==nullptr || size==0)
    {
        return;
    }
    do
    {
        push(head,arr[i]);
    }while(i--!=0);
}
int length(const Node *head)
{
    int n = 0;
    while(head)
    {
        head=head->next;
        n++;
    }
    return n;
}
int *toArray(const Node *head)
{
    int leng = length(head);
    int *values = new int [leng];
    while(head)
    {
        values[--leng] = head->data;
        head = head->next;
    }
    return values;
}

void merge(Node *a, Node *b, Node **c) {
    Node tmp;
    *c = nullptr;
    if (a == nullptr) {
        *c = b;
        return;
    }
    if (b == nullptr) {
        *c = a;
        return;
    }
    if (a->data < b->data) {
        *c = a;
        a = a->next;
    } else {
        *c = b;
        b = b->next;
    }
    tmp.next = *c;
    while (a && b) {
        if (a->data < b->data) {
            (*c)->next = a;
            a = a->next;
        } else {
            (*c)->next = b;
            b = b->next;
        }
        (*c) = (*c)->next;
    }
    if (a) {
        while (a) {
            (*c)->next = a;
            (*c) = (*c)->next;
            a = a->next;
        }
    }
    if (b) {
        while (b) {
            (*c)->next = b;
            (*c) = (*c)->next;
            b = b->next;
        }
    }
    *c = tmp.next;
}
void split(Node *src, Node **low, Node **high) {
    Node *fast = nullptr;
    Node *slow = nullptr;

    if (src == nullptr || src->next == nullptr) {
        (*low) = src;
        (*high) = nullptr;
        return;
    }

    slow = src;
    fast = src->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    (*low) = src;
    (*high) = slow->next;
    slow->next = nullptr;
}
void mergeSort(Node **head) {
    Node *low  = nullptr;
    Node *high = nullptr;
    if ((*head == nullptr) || ((*head)->next == nullptr)) {
        return;
    }
    split(*head, &low, &high);
    mergeSort(&low);
    mergeSort(&high);
    merge(low, high, head);
}
int main() {
    srand(time(nullptr));
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
    deleteList(&hued);
    Node *head=nullptr;
    for (int i = 0; i < 10; ++i) {
        pushBack(&head,rand()%10);
    }
    show(head);
    insert(head,8,9999);
    show(head);
    deleteNth(&head,2);
    show(head);
    Node *newList = nullptr;
    int arr[]={1,2,3,4,5,6,7,0,0,0,1};
    fromArray(&newList,arr,11);
    show(newList);
    Node *toArr = nullptr;
    push(&toArr,110);
    push(&toArr,111);
    push(&toArr,101);
    int *ARR = toArray(toArr);
    for (int j = 0; j < length(toArr); ++j) {
        cout << ARR[j] << " ";
    }
    Node *merged = nullptr;
    cout << endl;
    Node *test1 = nullptr;
    pushBack(&test1,1);
    pushBack(&test1,5);
    pushBack(&test1,2);
    pushBack(&test1,3);
    Node *test2 = nullptr;
    pushBack(&test2,1111);
    pushBack(&test2,1011);
    pushBack(&test2,1010);
    pushBack(&test2,1001);
    merge(test1,test2,&merged);
    show(merged);
    mergeSort(&merged);
    show(merged);
    return 0;
}
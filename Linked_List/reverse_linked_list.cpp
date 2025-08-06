#include<iostream>
using namespace std;
struct Node{
    int data;
    Node * next;
    Node(int val): data(val), next(nullptr){}
};
Node * reverseLinkedList(Node * head){
    Node * curr = head;
    Node * prev = nullptr;
    while(curr != nullptr){
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void printList(Node * head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main(){
    Node * head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    cout << "Original Linked List: " << endl;
    printList(head);
    head = reverseLinkedList(head);
    cout << "Reversed Linked List: " << endl;
    printList(head);
    return 0;
}

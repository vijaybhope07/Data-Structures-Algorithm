#include<iostream>
using namespace std;
struct Node{
    int data;
    Node * next;
    Node(int val) : data(val), next(nullptr) {}
};
bool isCircularLinkedList(Node * head){
    // if linked list is empty
    if(head == nullptr){
        return true;
    }
    // if one node is present 
    Node * temp = head->next;
    while(temp != nullptr && temp != head){
        temp = temp->next;
    }
    if(temp == head){
        return true;
    }
    return false;
}
int main(){
    Node * head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = head;
    if(isCircularLinkedList(head)){
        cout << "Linked List is circular in Nature " << endl;
    }
    else{
        cout << "Linked list is not circular in nature " << endl;
    }
    return 0;
}
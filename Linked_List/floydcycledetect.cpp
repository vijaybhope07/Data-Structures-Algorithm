#include<iostream>
using namespace std;
struct Node{
    int data;
    Node * next;
    Node(int val) : data(val), next(nullptr) {}
};
Node * floydDetectLoop(Node* head){
    if(head == nullptr){
        return nullptr;
    }
    Node * slow = head;
    Node * fast = head;
    while(slow != nullptr && fast != nullptr){
        fast = fast->next;
        if(fast != nullptr){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast){
            return slow;
        }
    }
    return nullptr;
}
int main(){
    Node * head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next;
    Node * loop = floydDetectLoop(head);
    if(loop != nullptr){
        cout << "We detect a loop in the linked list. " << endl;
    }
    else{
        cout << "We do not detect a loop in a linked list. " << endl;
    }
    return 0;
}
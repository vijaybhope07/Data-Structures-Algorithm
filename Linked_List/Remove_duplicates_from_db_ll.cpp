#include<iostream>
using namespace std;
struct Node{
    int data;
    Node * next;
    Node(int val): data(val), next(nullptr){}
};
Node* removeDuplicates(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node * current = head;
    while(current != NULL){
        if(current->next != NULL && current->data == current->next->data){
            Node * nextNode = current->next->next;
            Node * nodetodelete = current->next;
            delete nodetodelete;
            current->next = nextNode;
        }
        else{
            current = current->next;
        }
    }
    return head;
}
void printList(Node * head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    Node * head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(4);
    cout << "Original Linked List: ";
    printList(head);
    head = removeDuplicates(head);
    cout << "Linked List After Removing Duplicates: ";
    printList(head);
    return 0;
}
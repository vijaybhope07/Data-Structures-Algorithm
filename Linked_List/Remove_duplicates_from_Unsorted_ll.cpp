#include<iostream>
using namespace std;
struct Node{
    int data;
    Node * next;
    Node(int val): data(val), next(nullptr) {}
};
Node * removeDuplicates(Node * head){
    if(head == NULL){
        return NULL;
    }
    Node * current = head;
    while(current != NULL){
        Node * runner = current; // Use a runner to iterate from current->next
        while(runner->next != NULL){ // Iterate until the second to last node
            if(runner->next->data == current->data){ // Check the next node's data
                Node * nodetodelete = runner->next;
                runner->next = runner->next->next;
                delete nodetodelete;
            }
            else{
                runner = runner->next;
            }
        }
        current = current->next; 
    }
    return head;
}
void printList(Node * head){
    Node * curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main(){
    Node * head = new Node(5);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(5);
    cout << "Original Linked List: ";
    printList(head);
    head = removeDuplicates(head);
    cout << "Linked List After Removing Duplicates: ";
    printList(head);
    return 0;
}
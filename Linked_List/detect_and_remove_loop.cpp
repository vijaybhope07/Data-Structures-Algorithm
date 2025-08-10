#include<iostream>
using namespace std;
struct Node{
    int data;
    Node * next;
    Node(int val): data(val), next(nullptr) {}
};
Node* floydDetectLoop(Node* head) {
    if(head == NULL)
        return NULL;
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast !=NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;
        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}
Node* getStartingNode(Node* head) {
    if(head == NULL) 
        return NULL;
    Node* intersection = floydDetectLoop(head);
    if(intersection == NULL)
        return NULL;
    Node* slow = head;
    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  
    return slow;
}
Node *removeLoop(Node *head)
{
    if( head == NULL)
        return NULL;
    Node* startOfLoop = getStartingNode(head);
    if(startOfLoop == NULL)
        return head;
    Node* temp = startOfLoop;
    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 
    temp -> next = NULL;
    return head;
}
int main(){
    Node * head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next; // Creating a loop for testing
    cout << "Original Linked List (with loop): ";
    Node* temp = head;
    for(int i = 0; i < 7; ++i) { // Print a few nodes to show the loop
        if(temp == nullptr) break;
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "..." << endl;
    Node* loopStart = getStartingNode(head);
    if(loopStart != nullptr){
        cout << "Loop starts at node with data: " << loopStart->data << endl;
    } else {
        cout << "No loop detected." << endl;
    }
    head = removeLoop(head);
    cout << "Linked List after removing loop: ";
    temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}
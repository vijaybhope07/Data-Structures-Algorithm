#include<iostream>
using namespace std;
struct Node{
    int data;
    Node * next;
    Node(int val): data(val), next(nullptr) {}
};
Node * sortList(Node * head){
    int countzero = 0;
    int countone = 0;
    int counttwo = 0;
    Node * temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            countzero++;
        }
        if(temp->data == 1){
            countone++;
        }
        if(temp->data == 2){
            counttwo++;
        }
        temp = temp->next;
    }
    temp = head;
    while(countzero > 0){
            temp->data = 0;
            countzero--;
            temp = temp->next;
    }
    while(countone > 0){
            temp->data = 1;
            countone--;
            temp = temp->next;
    }
    while(counttwo > 0){
            temp->data = 2;
            counttwo--;
    }
    return head;
}
void printlist(Node * head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    Node * head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    cout << "Original Linked List: ";
    printlist(head);
    head = sortList(head);
    cout << "Sorted Linked List: ";
    printlist(head);
    return 0;
}
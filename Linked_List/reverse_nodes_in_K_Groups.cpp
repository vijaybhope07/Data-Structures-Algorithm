// C++ Program to reverse the nodes of a linked list in k groups 
// Leetcode number: 25 (Asked by Microsoft, Amazon, Facebook, etc.)
#include<iostream>
using namespace std;
struct ListNode {
    int data;
    ListNode *next;
    ListNode(int val) : data(val),next(nullptr) {}
};
int getLength(ListNode *head, int k){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count ;
}
ListNode* reverseKGroup(ListNode* head, int k){
    if(head == NULL){
        return NULL;
    }
    int length = getLength(head, k);
    if(length < k){
        return head;
    }
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* forward = NULL;
    int count = 0;
    while(curr != NULL && count < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    head->next = reverseKGroup(forward,k);
    return prev;
}
void printList(ListNode* head){
    while(head){
        cout << head->data <<" ";
        head = head->next;
    }
    cout << endl;
}
int main(){
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    cout << "Original Linked List: " << endl;
    printList(head);
    int k = 3;
    head = reverseKGroup(head, k);
    cout << "Reversed Linked List in K Groups: " << endl;
    printList(head);
    return 0;
}
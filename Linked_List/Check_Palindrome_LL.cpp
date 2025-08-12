#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node * next;
    Node(int val) : data(val), next(nullptr) {}
};
bool checkPalindrome(vector<int>& arr){
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    while(start <= end){
        if(arr[start] != arr[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
bool isPalindrome(Node * head){
    vector<int> arr;
    Node * temp = head;
    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return checkPalindrome(arr);
}
void printList(Node * head){
    Node * current = head;
    while(current != NULL){
        cout << current->data ;
        current = current->next;
    }
    cout << endl;
}
int main(){
    Node * head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);
    if(isPalindrome(head)){
        cout << "The Given Linked List is a Palindrome. " << endl;
    }
    else{
        cout << "The Given Linked List is not a Palindrome. " << endl;
    }
    return 0;
}
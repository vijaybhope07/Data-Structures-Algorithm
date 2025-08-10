#include<iostream>
using namespace std;
#include<map>
#include<vector>
struct Node{
    int data;
    Node * next;
    Node(int val) : data(val), next(nullptr) {}
};
bool detectLoop(Node * head){
    if(head == nullptr){
        return false;
    }
    map<Node*, bool> visited;
    Node * temp = head;
    while(temp != nullptr){
        if(visited[temp] == true){
            return true;
        }
        visited[temp] = temp->next;
        temp = temp->next;
    }
    return false;
}
int main(){
    Node * head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    head->next->next->next->next = head->next;
    if(detectLoop(head)){
        cout << "We detect a loop in the linked list. " << endl;
    }
    else{
        cout << "We do not detect a loop in a linked list " << endl;
    }
    return 0;
}
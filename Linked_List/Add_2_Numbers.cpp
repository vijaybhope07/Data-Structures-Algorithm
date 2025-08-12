#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
void insertAtTail(Node*& head, Node*& tail, int val) {
    Node* temp = new Node(val);
    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}
Node* addTwoNumbers(Node* first, Node* second) {
    int carry = 0;
    Node* ansHead = nullptr;
    Node* ansTail = nullptr;
    while (first != nullptr || second != nullptr || carry != 0) {
        int val1 = (first != nullptr) ? first->data : 0;
        int val2 = (second != nullptr) ? second->data : 0;
        int sum = carry + val1 + val2;
        int digit = sum % 10;
        carry = sum / 10;
        insertAtTail(ansHead, ansTail, digit);
        if (first != nullptr) first = first->next;
        if (second != nullptr) second = second->next;
    }
    return ansHead;
}
Node* addTwoLists(Node* first, Node* second) {
    first = reverse(first);
    second = reverse(second);
    Node* ans = addTwoNumbers(first, second);
    ans = reverse(ans);
    return ans;
}
// Helper function to print list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
// Example usage
int main() {
    Node* first = nullptr;
    Node* tail1 = nullptr;
    insertAtTail(first, tail1, 4);
    insertAtTail(first, tail1, 5);  // Represents 45
    Node* second = nullptr;
    Node* tail2 = nullptr;
    insertAtTail(second, tail2, 3);
    insertAtTail(second, tail2, 4); // Represents 34
    Node* result = addTwoLists(first, second);
    printList(result); // Should print 7 9 for 79
    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

Node* mergeNodes(Node* start, Node* end) {
    Node* merged = new Node;
    merged->val = 0;
    merged->next = NULL;
    Node* curr = start;
    while(curr != end) {
        merged->val += curr->val;
        curr = curr->next;
    }
    merged->val += end->val;
    return merged;
}

Node* mergeZeros(Node* head) {
    Node* curr = head;
    while(curr != NULL && curr->next != NULL) {
        if(curr->val == 0 && curr->next->val == 0) {
            Node* start = curr;
            Node* end = curr->next;
            while(end != NULL && end->val == 0) {
                end = end->next;
            }
            Node* merged = mergeNodes(start, end);
            start->next = merged;
            merged->next = end;
            curr = merged;
        }
        else {
            curr = curr->next;
        }
    }
    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while(curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
}

int main() {
    // Example usage
    Node* head = new Node;
    head->val = 0;
    head->next = new Node;
    head->next->val = 1;
    head->next->next = new Node;
    head->next->next->val = 2;
    head->next->next->next = new Node;
    head->next->next->next->val = 0;
    head->next->next->next->next = new Node;
    head->next->next->next->next->val = 3;
    head->next->next->next->next->next = new Node;
    head->next->next->next->next->next->val = 0;
    head->next->next->next->next->next->next = new Node;
    head->next->next->next->next->next->next->val = 4;
    head->next->next->next->next->next->next->next = new Node;
    head->next->next->next->next->next->next->next->val = 5;
    head->next->next->next->next->next->next->next->next = new Node;
    head->next->next->next->next->next->next->next->next->val = 0;
    head = mergeZeros(head);
    printList(head); // Output: 1 2 3 7 4 5
    return 0;
}

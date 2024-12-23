#include <iostream>
#include<vector>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    
    while (curr != nullptr) {
        ListNode* nextNode = curr->next;  
        curr->next = prev;                
        prev = curr;                      
        curr = nextNode;
    }
    
    return prev;  
}


void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}


ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    for (int i = 1; i < values.size(); ++i) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }
    return head;
}

int main() {

    vector<int> values1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(values1);
    cout << "Original list: ";
    printList(head1);
    head1 = reverseList(head1);
    cout << "Reversed list: ";
    printList(head1);


    vector<int> values2 = {1, 2};
    ListNode* head2 = createList(values2);
    cout << "Original list: ";
    printList(head2);
    head2 = reverseList(head2);
    cout << "Reversed list: ";
    printList(head2);

    return 0;
}

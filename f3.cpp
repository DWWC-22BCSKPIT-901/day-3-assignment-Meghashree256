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


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);  
    ListNode* current = dummyHead;  
    int carry = 0;

    
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;  
        }
        
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;  
        current->next = new ListNode(sum % 10);  
        current = current->next;  
    }

    return dummyHead->next;
}


void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}


ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
  
    vector<int> values1 = {2, 4, 3};  
    vector<int> values2 = {5, 6, 4};  
    ListNode* l1 = createList(values1);
    ListNode* l2 = createList(values2);
    
    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);
    
    ListNode* result = addTwoNumbers(l1, l2);
    cout << "Result: ";
    printList(result);  


    vector<int> values3 = {0};  
    vector<int> values4 = {0};  
    ListNode* l3 = createList(values3);
    ListNode* l4 = createList(values4);
    
    cout << "List 3: ";
    printList(l3);
    cout << "List 4: ";
    printList(l4);
    
    result = addTwoNumbers(l3, l4);
    cout << "Result: ";
    printList(result);  


    vector<int> values5 = {9, 9, 9, 9, 9, 9, 9};  
    vector<int> values6 = {9, 9, 9, 9};  
    ListNode* l5 = createList(values5);
    ListNode* l6 = createList(values6);
    
    cout << "List 5: ";
    printList(l5);
    cout << "List 6: ";
    printList(l6);
    
    result = addTwoNumbers(l5, l6);
    cout << "Result: ";
    printList(result);  

    return 0;
}

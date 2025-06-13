#include <iostream>
using namespace std;


// Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution{
    public:
        ListNode* reverseList(ListNode* head){
            ListNode* curr = head;
            ListNode* prev = nullptr;
            while(curr != nullptr){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            return prev;
        }
};

void printList(ListNode* head){
    ListNode* curr = head;
    while (curr != nullptr){
        cout<<curr->val;
        if (curr->next) cout<<"->";
        curr = curr->next;
    }
    cout<<endl;
}

int main(){
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    
    cout<<"Orginal Linked List: ";
    printList(head);

    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    cout<<"Reversed Linked List: ";
    printList(reversedHead);


    return 0;
}
#include<bits/stdc++.h>
using namespace std;    

class ListNode {
    public:
        int val;
        ListNode* next; 
        ListNode(int val) {
            this->val = val;
            this->next = NULL;
        }
};


class ListNodeCreator {
    public:
        // Removed the unused vector parameter
        ListNode* create() {
            int n, values; 
            cout << "Enter number of nodes: ";
            cin >> n;
            
            if(n <= 0) return NULL;

            cout << "Enter " << n << " node values: " << endl;
            cin >> values;

            ListNode* head = new ListNode(values);
            ListNode* tail = head;

            for(int i = 1; i < n; i++){
                cin >> values;
                tail->next = new ListNode(values);
                tail = tail->next;
            }

            return head;
        }
};

class Solution {
    public:
        ListNode* insertionSortList(ListNode* head) {
            if(!head || !head->next) {
                return head; 
            }

            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode* lst = head; // last sorted
            ListNode* cur = head->next;

            while(cur){
                if(lst->val <= cur->val){
                    lst = lst->next;
                }
                else {
                    ListNode* prev = dummy;

                    // Find the spot to insert
                    while(prev->next->val < cur->val){
                        prev = prev->next;
                    }
                    
                    // Logic: Pluck 'cur' out and move it after 'prev'
                    lst->next = cur->next;
                    cur->next = prev->next;
                    prev->next = cur;
                }
                // 'lst' hasn't changed position, so 'cur' is always lst->next
                cur = lst->next;
            }
            
            ListNode* sortedHead = dummy->next;
            delete dummy; 
            return sortedHead;
        }
};

void printList(ListNode* head) {
    ListNode* current = head;
    while(current) {
        cout << current->val << (current->next ? " -> " : "");
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    ListNodeCreator creator;
    // Call create() without the unused vector
    ListNode* head = creator.create();       
    
    if(!head) {
        cout << "List is empty!" << endl;
        return 0;
    }

    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* sortedHead = sol.insertionSortList(head);

    cout << "Sorted List:   ";
    printList(sortedHead);

    // // Optional: Clean up list memory
    // while(sortedHead) {
    //     ListNode* temp = sortedHead;
    //     sortedHead = sortedHead->next;
    //     delete temp;
    // }

    return 0;
}
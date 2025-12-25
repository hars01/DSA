//leetcode 1721: Swapping Nodes in a Linked List
//Decription: You are given the head of a linked list, and an integer k.
//Return the head of the linked list after swapping the values of the k-th node from the

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

// Approach: Two pointer approach
// Find the k-th node from the start and k-th node from the end
//time complexity: O(n)
//space complexity: O(1)
class Solution {
    public:
        ListNode* swapNodes(ListNode* head, int k) {
            if(!head || !head->next) {
                return head; 
            }

            ListNode* first = head;
            ListNode* second = head;
            ListNode* current = head;

            // Move first to the k-th node
            for(int i = 1; i < k; i++) {
                current = current->next;
            }

            first=current;

            // Move current to the end, and second to the (n-k+1)-th node
            while(current->next) {
                current = current->next;
                second = second->next;
            }

           
                int temp = first->val;
                first->val = second->val;
                second->val = temp;

            return head;
        }
};

class ListNodeCreator {
    public:
        ListNode* create(int n, vector<int>& values) {
            
            if(n <= 0) return NULL;

            ListNode* head = new ListNode(values[0]);
            ListNode* tail = head;

            for(int i = 1; i < n; i++){
                tail->next = new ListNode(values[i]);
                tail = tail->next;
            }

            return head;
        }
};

int main() {
    cout << "Enter number of nodes: ";
    int n;
    cin >> n;
    if(n <= 0) {
        cout << "The list is empty." << endl;
        return 0;
    }
    cout << "Enter " << n << " node values: " << endl;
    vector<int> values(n);
    for(int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    ListNodeCreator creator;
    ListNode* head = creator.create(n, values);
    

    cout << "Enter the value of k: ";
    int k;
    cin >> k;


    Solution sol;
    ListNode* modifiedHead = sol.swapNodes(head, k);

    // Print the modified list
    ListNode* current = modifiedHead;
    while(current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
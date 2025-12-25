// Leetcode Problem Link: https://leetcode.com/problems/merge-in-between-linked-lists/
// Preoblem Description: You are given two linked lists: list1 and list2 of sizes n and m respectively.
// Remove list1's nodes from index a to b, and put list2 in their place
#include <bits/stdc++.h>
using namespace std;


// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};


// Merge In Between Linked Lists
// Time Complexity: O(n + m) where n and m are the lengths of list1
// Space Complexity: O(1)
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prevA = list1;
        // Move to node just before index 'a'
        for (int i = 0; i < a-1; i++) {
            prevA = prevA->next;
        }

        // Move to node at index 'b'
        ListNode* afterB = prevA;
        for (int i = 0; i <= b - a + 1; i++) {
            afterB = afterB->next;
        }

        // Connect prevA to list2
        prevA->next = list2;

        // Move to end of list2
        ListNode* tail2 = list2;
        while (tail2->next != NULL) {
            tail2 = tail2->next;
        }

        // Connect end of list2 to afterB
        tail2->next = afterB;

        return list1;
    }
};


// Utility function to create a linked list from vector
ListNode* createList(vector<int> arr) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}


// Utility function to print a linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}


int main() {
    // Input
    int n;
    cout << "Enter number of nodes in list1: ";
    cin >> n;
    vector<int> list1_vals(n);
    cout << "Enter values for list1: ";
    for (int i = 0; i < n; i++) {
        cin >> list1_vals[i];
    }

    int m;
    cout << "Enter number of nodes in list2: ";
    cin >> m;
    vector<int> list2_vals(m);
    cout << "Enter values for list2: ";
    for (int i = 0; i < m; i++) {
        cin >> list2_vals[i];
    }

    int a, b;
    cout << "Enter indices a and b: ";
    cin >> a >> b;


    // Create linked lists
    ListNode* list1 = createList(list1_vals);
    ListNode* list2 = createList(list2_vals);

    // Solution
    Solution sol;
    ListNode* result = sol.mergeInBetween(list1, a, b, list2);

    // Output
    cout << "Result List: ";
    printList(result);

    return 0;
}

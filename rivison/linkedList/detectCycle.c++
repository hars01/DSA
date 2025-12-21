#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) {
        val = value;
        next = nullptr;
    }
};

class Solution { 
public: 
    //Detect Cycle in a Linked List using Floyd’s Cycle-Finding Algorithm
    //Time Complexity: O(n)
    //Space Complexity: O(1)
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return false; // No cycle if list is empty or has only one node
        }

        ListNode* slow = head;       // Moves one step at a time
        ListNode* fast = head->next; // Moves two steps at a time

        while(fast != NULL && fast->next != NULL) {
            if(slow == fast) {
                return true; // Cycle detected
            }
            slow = slow->next;           // Move slow pointer by one
            fast = fast->next->next;     // Move fast pointer by two
        }

        return false; // No cycle found
    }
};

int main() {
    // Example usage:

    ListNode* head;
    cout << "Creating a linked list with a cycle for testing..." << endl;
    cout << "Enter number of nodes: ";
    int n;
    cin >> n;
    vector<ListNode*> nodes;
    for(int i = 0; i < n; i++) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        nodes.push_back(new ListNode(value));
        if(i > 0) {
            nodes[i - 1]->next = nodes[i];
        }
    }
    head = nodes[0];
    cout << "Enter the position (0-indexed) to create a cycle (-1 for no cycle): ";
    int pos;
    cin >> pos;
    if(pos >= 0 && pos < n) {
        nodes[n - 1]->next = nodes[pos]; // Creating a cycle
    }

    

    Solution solution;
    if(solution.hasCycle(head)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    // Clean up memory (not shown here due to cycle)
    return 0;
}

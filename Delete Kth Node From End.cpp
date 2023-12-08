/*
    Time Complexity:O(N)
    Space Compexity:O(1)

    Where N is the total nodes in Linked List
*/
Node *removeKthNode(Node *head, int K) {
    
    if (head == NULL || K == 0) {
        return head;
    }

    Node *slow = head;
    Node *fast = head;

    for (int i = 0; i < K; i++) {

        // If head is the Kth node from end of Linked List.
        if (fast->next == NULL) {
            Node *next = head->next;
            head->next = NULL;
            head = next;

            return head;
        }

        else {
            fast = fast->next;
        }

    }

    // Moving both slow and fast pointer with same speed.
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // Removing the Kth node from end of Linked List.
    slow->next = slow->next->next;

    return head;

}

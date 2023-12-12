/*
    Time Complexity: O(N + M)
    Space Complexity: O(1)

    where 'N' and 'M' are the number of nodes in both lists respectively.
*/

// Function to count the number of nodes in the list.
int countDigits(Node<int> *head) {
    int c = 0;
    while (head) {
        head = head->next;
        c++;
    }
    return c;
}

// Function to reverse the list.
Node<int> *reverseList(Node<int> *head) {
    Node<int> *prev = NULL, *curr = head, *nextNode;
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node<int> *addTwoLists(Node<int> *first, Node<int> *second) {
    // Reverse both lists for simplicity.
    first = reverseList(first);
    second = reverseList(second);

    // Assign list with more digits to first list.
    if (countDigits(first) < countDigits(second)) {
        Node<int> *temp = first;
        first = second;
        second = temp;
    }

    int carry = 0;
    Node<int> *head = first;

    // Iterate and add the nodes till second list doesn't reach end.
    while (second != NULL) {
        first->data += second->data + carry;
        carry = first->data / 10;
        first->data %= 10;

        // If the list ends but a carry remains.
        if (first->next == NULL && carry) {
            Node<int> *newNode = new Node<int>(carry);
            first->next = newNode;
            first = first->next;
            carry = 0;
            break;
        }
        first = first->next;
        second = second->next;
    }

    // If there are more digits left to process in first list.
    while (first != NULL) {
        first->data += carry;
        carry = first->data / 10;
        first->data %= 10;
        // If the list ends but a carry remains.
        if (first->next == NULL && carry) {
            Node<int> *newNode = new Node<int>(carry);
            first->next = newNode;
            break;
        }
        first = first->next;
    }

    // Reverse the list to get the final number.
    head = reverseList(head);

    // Return the answer list obtained after adding two lists.
    return head;
}

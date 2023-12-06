/*
     Time Complexity: O(N)
    Space Complexity: O(1)

    where ‘N’ is the number of nodes in the list.
*/

Node *removeLoop(Node *head)
{
    if (head == nullptr || head->next == nullptr){
        return head;
    }

    // Slow Pointer - This will be incremented by 1 Nodes.
    Node *slow = head;

    // Fast Pointer  - This will be incremented by 2 Nodes
    Node *fast = head;

    while (true){

        // We reached the end of the List and haven't found any Cycle
        if (fast == nullptr || fast->next == nullptr){
            return head;
        }

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast){
            break;
        }
    }

    // Cycle Found.
    fast = head;

    // start will point the starting node of cycle.
    Node *start = nullptr;

    while (fast != slow){

        fast = fast->next;
        slow = slow->next;
    }

    start = slow;

    // Finding the previous node of 'start'.
    Node *cur = start;

    while (true){

        if (cur->next == start){

            cur->next = nullptr;
            return head;
        }

        cur = cur->next;
    }

}

/*
    Time Complexity:O(N)
    Space Complexity:O(1)

    Where N is the total nodes in Linked List
*/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{

    // Creating node for remembering previous node in Linked List.
    LinkedListNode<int> *prev = NULL;

    // Creating temporory node.
    LinkedListNode<int> *current = head;

    while (current != NULL) 
    {
        LinkedListNode<int> *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;

    }

    // Return reverse Linked List.
    return prev;
}

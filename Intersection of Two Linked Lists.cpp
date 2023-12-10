/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    where 'N' is the maximum length of linked list.
*/


int length(Node *head)
{
    int length = 0;
    Node *tmp = head;

    while (tmp != NULL)
    {
        tmp = tmp->next;
        length++;
    }

    return length;
}

Node* findIntersection(Node *firstHead, Node *secondHead)
{

    // Get the length of both list.
    int firstListLength = length(firstHead), secondListLength = length(secondHead);

    // Move headA and headB to the same start point.
    while (firstListLength > secondListLength)
    {
        firstHead = firstHead->next;
        firstListLength--;
    }

    while (firstListLength < secondListLength)
    {
        secondHead = secondHead->next;
        secondListLength--;
    }

    // Find the intersection until end.
    while (firstHead != secondHead)
    {
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }

    return firstHead;
}

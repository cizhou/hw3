#include "llrec.h"




//*********************************************
// Provide your implementation of llpivot below
//*********************************************

/* Write a recursive function to split the elements of a singly-linked list into two output lists, 
 * one containing the elements less than or equal to a given number, 
 * the other containing the elements larger than the number. 
 * You must MAINTAIN the relative ordering of items from the original list when you split them into the two output lists. 
 * The original list should not be preserved. Your function must be recursive - you will get NO credit for an iterative solution. 
 * It must also run in O(n), where n is the length of the input list (and can be done with only one pass/traversal through the list).
 */

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    // assume that smaller and larger are not equal to null?
    if (head == nullptr) 
    {
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    Node* temp = head->next;
    head->next = nullptr;

    if (head->val <= pivot)             // less than or equal to
    {
        smaller = head;
        llpivot(temp, smaller->next, larger, pivot);
    } else                              // greater than
    {
        larger = head;   
        llpivot(temp, smaller, larger->next, pivot);
    }

    head = nullptr; // Ensure the original list is destroyed
}
To solve the problem of detecting a cycle in a singly linked list, we need an efficient approach that avoids using extra space and operates in linear time. Here is the thought process and steps taken to arrive at the solution using Floyd's Tortoise and Hare algorithm:

## Understanding the Problem

A singly linked list can potentially have a cycle, meaning that following the next pointers can lead us back to a previously visited node, forming a loop. Our goal is to determine if such a cycle exists.

## Approach to Solve the Problem

1. Identify an Efficient Algorithm:

   - A brute force approach might involve using additional data structures like a hash table to keep track of visited nodes, but this would use extra space.
   - Floyd's Tortoise and Hare algorithm provides a space-efficient solution with a simple concept: using two pointers that traverse the list at different speeds.

2. Floyd's Tortoise and Hare Algorithm:

   - Two Pointers: Use two pointers, slow and fast. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time.
   - Detecting a Cycle: If there is no cycle, the fast pointer will eventually reach the end of the list (NULL). If there is a cycle, the fast pointer will eventually meet the slow pointer within the cycle.

## Implementation Steps

1. Initialize Pointers:
   - Start both slow and fast pointers at the head of the list.
2. Traverse the List:
   - Move the slow pointer by one step and the fast pointer by two steps in each iteration.
   - Check if slow and fast pointers meet at some node.
3. Check for Cycle:

- If the pointers meet, a cycle exists. Return 1.
- If the fast pointer reaches the end (NULL), there is no cycle. Return 0.

## Code Implementation

Here is the implementation of the solution in C:

    #include "lists.h"

    /\*\*

    - check_cycle - checks if a singly linked list has a cycle in it
    - @list: pointer to the head of the list
    -
    - Return: 0 if there is no cycle, 1 if there is a cycle
    */
    int check_cycle(listint_t *list)
    {
    listint_t *slow = list;
    listint_t *fast = list;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return 1;
        }

        return 0;

    }

## Explanation of the Code

- Initialization: Both slow and fast pointers are initialized to the head of the list.
- Loop: The loop continues as long as fast and fast->next are not NULL.
  - slow moves one step forward: slow = slow->next.
  - fast moves two steps forward: fast = fast->next->next.
  - If slow meets fast, there is a cycle (return 1).
- No Cycle: If the loop exits without the pointers meeting, the list has no cycle (return 0).

## Benefits of This Approach

- Time Complexity: O(n), where n is the number of nodes in the list. Both pointers traverse the list at most once.
- Space Complexity: O(1), since only two pointers are used, regardless of the list size.

## Final Thoughts

This method is efficient and leverages the characteristics of linked lists and pointer manipulation to detect cycles without additional memory overhead. It exemplifies a classic algorithmic solution that is both elegant and practical.

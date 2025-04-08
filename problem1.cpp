#include <iostream>

using namespace std;

class Node 
{
public:
    int value;
    Node* next;
    Node(int x) : value(x), next(nullptr) {}
};

// Rearranges the list such that even numbers come before odd numbers,
// preserving the relative order within both groups.
Node* rearrangeEvenOdd(Node* head) 
{
    Node* evenStart = nullptr; // Head of even sublist
    Node* evenEnd = nullptr;   // Tail of even sublist
    Node* oddStart = nullptr;  // Head of odd sublist
    Node* oddEnd = nullptr;    // Tail of odd sublist
    Node* current;

    // Traverse the list and partition nodes into even and odd lists
    for (current = head; current != nullptr; current = current->next)
    {
        int value = current->value;

        if (value % 2 == 0)  // Even node
        {
            if (evenStart != nullptr)
            {
                evenEnd->next = current;
                evenEnd = evenEnd->next;
            }
            else
            {
                evenStart = current;
                evenEnd = evenStart;
            }
        }
        else  // Odd node
        {
            if (oddStart != nullptr)
            {
                oddEnd->next = current;
                oddEnd = oddEnd->next;
            }
            else 
            {
                oddStart = current;
                oddEnd = oddStart;
            }
        }
    }

    // If either even or odd list is empty, return original head
    if (!oddStart || !evenStart)
    {
        return head;
    }
     
    // Combine even and odd lists
    evenEnd->next = oddStart;
    oddEnd->next = nullptr;
     
    // Update head to the start of the even list
    head = evenStart;
    return head;
}


void printList(Node* head) 
{
    Node* current = head;

    while (current != nullptr) 
    {
        cout << current->value << "->";
        current = current->next;
    }

    cout << "NULL" << endl;
}

void push_back(Node*& head, int val) 
{
    Node* newNode = new Node(val);

    if (!head) 
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) 
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

int main() {
    Node* head = nullptr;

    // Example input: 17->15->8->12->10->5->4->1->7->6->NULL
    int values[] = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    for (int val : values) 
    {
        push_back(head, val);
    }

    cout << "Original List:" << endl;
    printList(head);

    head = rearrangeEvenOdd(head);

    cout << "Rearranged List:" << endl;
    printList(head);

    return 0;
}
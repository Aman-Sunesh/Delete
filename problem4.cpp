#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node (int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

bool checkPalindrome(Node* head)
{
    if (head == nullptr)  // An empty list is considered a palindrome.
        return true;
    
    Node* end = head;

    // Move 'end' pointer to the last node.
    while (end->next != nullptr)
    {
        end = end->next;
    }

    Node* left = head;
    Node* right = end;

    // Compare corresponding pairs until pointers meet or pass each other.
    while (left != right && right->next != left)
    {
        if (left->data != right->data)
        {
            return false;
        }
        left = left->next;
        right = right->prev;
    }
    
    return true;
}


void push_back(Node*& head, int value)
{
    Node* newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* current = head;

    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

void print(Node* head)
{
    Node* current = head;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

int main()
{
    Node* head = nullptr;

    push_back(head, 10);
    push_back(head, 20);
    push_back(head, 30);
    push_back(head, 20);
    push_back(head, 10);

    bool flag = checkPalindrome(head);

    if (flag == true)
    {
        cout << "True" << endl;
    }

    else
    {
        cout << "False" << endl;
    }

    return 0;
}
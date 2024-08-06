#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};
class LinkedList
{
private:
    int length;
    Node *head;
    Node *tail;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    };
    void PrintList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
    void getHead()
    {
        cout << "Head: " << head->value << endl;
    }
    void getTail()
    {
        cout << "Tail: " << tail->value << endl;
    }
    void getLength()
    {
        cout << "Length: " << length << endl;
    }
    // this is a function for appending items to the end of the list
    void append(int value)
    {
        Node *newNode = new Node(value);

        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
    // the below function is for deleting the last node in each of the three cases
    void deleteLast()
        {
            // if the linked list is empty
            Node* temp = head;
            Node* pre = head;
            if (length == 0)
            {
                return;
            }
            while(temp->next)
            {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
            length--;
            if (length == 0)
            {
                head = nullptr;
                tail = nullptr;
            }
            delete temp;
        }
    // this is the default deconstructor
    ~LinkedList()
    {
       Node* temp = head;
       while(head)
       {
        head = head->next;
        delete head;
        temp = head;
       }
    }
};
int main()
{
    LinkedList* myLinkedList = new LinkedList(4);

    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();

    myLinkedList->PrintList(); 
}
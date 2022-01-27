#include <iostream>

class Node
{
public:
    int item;
    Node *next;
    Node *prev;
    Node();
    Node(int);
};

class DoublyLinkedList
{
private:
    int size;
    Node *head;
    Node *tail;

public:
    DoublyLinkedList();
    void insertFront(int);
    void insertAtPosition(int, int);
    void insertBack(int);
    void deleteNode(int);
    void checkNodeEmpty(int);
    void display();
};

Node::Node() : item(0), next(NULL), prev(NULL) {}
Node::Node(int itm) : item(itm), next(NULL), prev(NULL) {}
DoublyLinkedList::DoublyLinkedList() : size(0), head(NULL), tail(NULL) {}

void DoublyLinkedList::insertFront(int itm)
{

    Node *temp = new Node(itm);

    if (temp == NULL)
    {
        std::cout << "Memory not allocated";
    }
    else
    {
        if (head == NULL)
        { //put value to head if null
            head = tail = temp;
        }
        else
        {
            temp->next = head; //linking of nodes
            head->prev = temp;

            head = temp;
        }
        size++;
    }
    return;
}

void DoublyLinkedList::insertBack(int itm)
{
    Node *temp = new Node(itm);
    if (temp == NULL)
    {
        std::cout << "Memmory not allocated";
    }
    else
    {
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            temp->prev = tail;
            tail->next = temp;

            tail = temp;
        }
        size++;
    }
    return;
}

void DoublyLinkedList::insertAtPosition(int pos, int itm)
{
    Node *temp = new Node(itm);

    if (temp == NULL)
    {
        std::cout << "Memmory not allocated";
    }
    else if (pos == 0 || pos > size)
    { //if not inside the list
        std::cout << "Invalid position. The position must be within the list.";
    }
    else
    {
        if (head == NULL)
        {
            head = tail = temp;
        }
        else if (pos == 1)
        {
            insertFront(itm);
        }
        else
        {
            Node *tempHead = head;
            for (; pos > 1; pos--)
            { //traverse to position that is given
                tempHead = tempHead->next;
            }

            Node *before = tempHead->prev; //linking of nodes
            temp->next = tempHead;
            tempHead->prev = temp;

            temp->prev = before;
            before->next = temp;
        }
        size++;
    }
    return;
}

void DoublyLinkedList::deleteNode(int pos)
{
    if (head == NULL)
    { //if head is null
        std::cout << "Nothing to delete. List is empty.\n";
    }
    else if (pos > size || pos == 0)
    { //if not in the list
        std::cout << "Invalid position. It must be within the list. \n";
    }
    else
    {
        Node *tempHead = head;

        for (; pos > 1; pos--)
        { //traverse to position to be deleted
            tempHead = tempHead->next;
        }
        Node *nodeToDelete = tempHead;
        Node *beforeNode = tempHead->prev;
        Node *afterNode = tempHead->next;

        if (beforeNode == NULL)
        { //delete front
            afterNode->prev = NULL;
            head = afterNode;
        }
        else if (afterNode == NULL)
        { //delete last
            beforeNode->next = NULL;
        }
        else
        { //delete middle
            beforeNode->next = afterNode;
            afterNode->prev = beforeNode;
        }
        size--;
        delete nodeToDelete;
    }
    return;
}

void DoublyLinkedList::checkNodeEmpty(int pos)
{

    if (head == NULL)
        std::cout << "List is empty.\n";

    else if (pos == 0 || pos > size)
        std::cout << "Invalid Input. It must be within the list.\n";

    else
    {
        Node *tempHead = head;
        for (; pos > 0; pos--)
        { //traverse to the position to be check
            tempHead = tempHead->next;
        }
        if (tempHead != NULL)
            std::cout << "Node is not empty"; //if not empty
        else
            std::cout << "Node is empty.";
    }
}

void DoublyLinkedList::display()
{
    Node *tempHead = head;
    while (tempHead != NULL)
    { //printing the previous address, data, and next address;
        std::cout << tempHead->prev << " " << tempHead->item << " " << tempHead->next << std::endl;
        tempHead = tempHead->next;
    }
}

int main()
{
    DoublyLinkedList doubly;
    int num, choice, position = 0;

    std::cout << "1.Insert Node At Front"
              << "\n2.Insert Node At the Position"
              << "\n3.Insert Node At Last"
              << "\n4.Delete A Node At Position"
              << "\n5.Check node if empty "
              << "\n6.Quit";
    do
    {
        std::cout << "\nEnter your choice of the above cases: ";
        std::cin >> choice;

        switch (choice) //the cases
        {
        case 1:
            std::cout << "Enter number: ";
            std::cin >> num;
            doubly.insertFront(num);
            break;
        case 2:
            std::cout << "Position: ";
            std::cin >> position;
            std::cout << "Enter number: ";
            std::cin >> num;

            doubly.insertAtPosition(position, num);
            break;
        case 3:
            std::cout << "Enter number: ";
            std::cin >> num;
            doubly.insertBack(num);
            break;
        case 4:
            std::cout << "Position: ";
            std::cin >> num;
            doubly.deleteNode(num);
            break;
        case 5:
            std::cout << "Position: ";
            std::cin >> position;
            doubly.checkNodeEmpty(position);
            break;
        case 6:
            return 0;
        default:
            std::cout << "Not in the choices.\n ";
            break;
        }
        std::cout << std::endl;
        doubly.display();

    } while (true);

    return 0;
}
#include <iostream>

class Node
{
public:
    int item;
    Node *next;
    Node();
    Node(int);
};

class List
{
protected:
    int size;
    Node *head;
    Node *tail;

public:
    List();
    void insertFront(int);
    void deleteFront();
    Node *findTheNode(int);
    int findTheData(int);
    bool isEmpty();
};

class Stack : List
{
public:
    void push(int);
    void pop();
    void display();
    void findNode(int);
    void findData(int);
    void stackIsEmpty();
};

Node::Node() : item(0), next(NULL) {}
Node::Node(int itm) : item(itm), next(NULL) {}
List::List() : size(0), head(NULL), tail(NULL) {}

//List
void List::insertFront(int itm)
{
    Node *temp = new Node(itm);

    if (temp == NULL)
        std::cout << "Memory not allocated" << std::endl;
    else
    { //linking of nodes. inserting at front.
        temp->next = head;
        head = temp;

        size++;
    }
    return;
}

void List::deleteFront()
{
    Node *temp = head; //deletion of nodes. deleting at front.
    head = temp->next;
    delete temp;
    size--;
    return;
}

int List::findTheData(int itm)
{ //the user will give what item/data to find
    Node *tempHead = head;

    while (tempHead != NULL)
    {
        if (tempHead->item == itm)
        { //return the data if found
            return tempHead->item;
        }
        tempHead = tempHead->next;
    }
    return NULL; //return NULL if data is not found
}

Node *List::findTheNode(int pos)
{
    Node *tempHead = head;

    if (pos == 0 || pos > size)
        return NULL; //return NULL if position given is not within the list

    for (; pos > 1; pos--)
    { //iterate until to the position given
        tempHead = tempHead->next;
    }

    return tempHead; //return the position, position 1 is covered with this too
}

bool List::isEmpty()
{
    if (head == NULL)
        return true; //if head is NULL the return true. Otherwise, false.
    return false;
}

//Stack
void Stack::pop()
{
    if (size == 0)
        std::cout << "\nNothing to delete. List is empty." << std::endl;
    else
        deleteFront();
}

void Stack::push(int x)
{
    insertFront(x);
}

void Stack::display()
{
    if (head == NULL)
        stackIsEmpty(); //f head is NULL then nothing to delete
    else
    {
        Node *temp = head;

        std::cout << "\nThe list: ";

        while (temp != NULL)
        {
            std::cout << temp->item << " "; //iterating anf printing the values in the list
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

void Stack::findData(int itm)
{

    if (head != NULL)
    { //if list is not empty
        int num = findTheData(itm);
        if (num == 0)
            std::cout << "\nData is not found!" << std::endl; //if the return value of the findTheData fuc is 0 then data is not found
        else
            std::cout << "\nData is found! Data: " << num << std::endl; //otherwise, it is found
    }
    else
        stackIsEmpty(); //condition if stack is empty
}

void Stack::findNode(int pos)
{
    if (head != NULL) //if list is not empty
    {
        Node *theNode = findTheNode(pos);
        if (theNode == NULL)
            std::cout << "\nInvalid input. It must be within the list. " << std::endl; //if the return value of findTheNode func is NULL print that text
        else
            std::cout << "\nNode data: " << theNode->item << "\n"; //otherwise print the value in the given position
    }
    else
        stackIsEmpty();
}

void Stack::stackIsEmpty()
{
    if (isEmpty())
        std::cout << "\nThe list is empty." << std::endl;
    else
        std::cout << "\nThe list is not empty. " << std::endl;
}

int main()
{
    Stack stack;
    int choice, position, num = 0;

    std::cout << "1. Push \n2. Pop \n3. Display \n4. Find Data \n5. Find Node \n6. Check if stack is empty \n7. Quit\n";

    do
    {
        std::cout << "\nChoice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Number: ";
            std::cin >> choice;
            stack.push(choice);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.display();
            break;
        case 4:
            std::cout << "Find data: ";
            std::cin >> num;
            stack.findData(num);
            break;
        case 5:
            std::cout << "Position: ";
            std::cin >> position;
            stack.findNode(position);
            break;
        case 6:
            stack.stackIsEmpty();
            break;
        case 7:
            return 0;
        default:
            std::cout << "Invalid choice. ";
            break;
        }
    } while (true);
}
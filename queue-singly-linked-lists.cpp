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
public:
    int size;
    Node *front, *rear;
    List();
    bool empty();
    void frontt();
    bool search(int);
    void insertBack(int);
    bool deleteFront();
    void display();
};

class Queue
{
private:
    List list;

public:
    bool empty();
    void front();
    bool search(int);
    void push_back(int);
    bool pop_front();
    void display();
};

int main()
{
    Queue que;
    int choice;

    std::cout << "1.push_back\n2.pop_front\n3.front\n4.check if empty\n5.Search data\n6.Quit" << std::endl;

    do
    {
        std::cout << "Enter Choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Value: ";
            std::cin >> choice;
            que.push_back(choice);
            que.display();
            break;
        case 2:
            que.pop_front();
            que.display();
            break;
        case 3:
            que.front();
            que.display();
            break;
        case 4:
            if (que.empty())
                std::cout << "List is empty" << std::endl;
            else
                std::cout << "List is not empty " << std::endl;
            break;
        case 5:
            std::cout << "Data: ";
            std::cin >> choice;
            que.search(choice);
            break;
        case 6:
            return 0;
        default:
            std::cout << "Invalid Choice." << std::endl;
            break;
        }
    } while (true);
}

Node::Node() : item(0), next(NULL) {}
Node::Node(int itm) : item(itm), next(NULL) {}
List::List() : size(0), front(NULL), rear(NULL) {}

bool Queue::empty()
{ //wrapper function for empty, front, push, pop, and display
    return list.empty();
}

void Queue::front()
{
    return list.frontt();
}

void Queue::push_back(int itm)
{
    return list.insertBack(itm);
}

bool Queue::pop_front()
{
    return list.deleteFront();
}
bool Queue::search(int dta)
{
    if (empty())
        display();
    else
        return list.search(dta);
}
void Queue::display()
{
    try
    {
        if (empty())
            throw 0;
        return list.display();
    }
    catch (int ex)
    {
        std::cout << "Underflow" << std::endl; //throw underflow if list is empty
    }
}

bool List::empty()
{ //return true if empty
    if (size == 0)
        return true;
    return false;
}

void List::frontt()
{
    if (empty())
        return;
    else
        std::cout << "Front: " << front->item << std::endl; //printing the front data
}

void List::insertBack(int itm)
{
    Node *temp = new Node(itm);
    if (empty())
        front = rear = temp; //inserting at back
    else
    {
        rear->next = temp; //linking of nodes
        rear = temp;
    }
    size++;
}

bool List::deleteFront()
{
    if (empty())
        return true;

    --size;
    Node *del = front; //make temp node
    front = del->next; //the next node will be the front

    std::cout << "Pop item: " << del->item << std::endl;

    delete del; //deleting the tmep node

    return false;
}

bool List::search(int dta)
{

    Node *temp = front;
    bool dataExist = false;

    while (temp != NULL)
    {
        if (temp->item == dta)
        { //return the data if found
            std::cout << "Data Found: " << temp->item << std::endl;
            return dataExist = true;
        }
        temp = temp->next;
    }
    if (!dataExist)
    {
        std::cout << "Data does not exist." << std::endl;
    }
}

void List::display()
{
    Node *temp = front;
    while (temp != NULL)
    { //displaying the data
        std::cout << temp->item << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
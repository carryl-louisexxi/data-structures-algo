#include <iostream>

class Node
{
public:
    int item;
    Node *prev;
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
    int sizee() const;
    bool empty() const;
    void frontt() const;
    void back() const;
    void enqueue(int);
    void dequeue();
    void display();
};

class Queue
{
private:
    List list;

public:
    int sizee() const;
    bool empty() const;
    void frontt() const;
    void back() const;
    void enqueue(int);
    void dequeue();
    void display();
};

int main()
{
    Queue que;
    int choice;

    std::cout << "1.enqueue\n2.dequeue\n3.front\n4.back\n5.size\n6.check if empty\n7.Quit\n"
              << std::endl;
    std::cout << "*Show front of QUEUE\n*Show size QUEUE\n*Ask QUEUE if empty or not\n"
              << std::endl;
    do
    {
        std::cout << "Enter Choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enqueue value: ";
            std::cin >> choice;
            que.enqueue(choice);
            que.display();
            break;
        case 2:
            que.dequeue();
            que.display();
            break;
        case 3:
            que.frontt();
            break;
        case 4:
            que.back();
            break;
        case 5:
            std::cout << "Size: " << que.sizee() << std::endl;
            break;
        case 6:
            if (que.empty())
                std::cout << "The queue is empty" << std::endl;
            else
                std::cout << "The queue is not empty" << std::endl;
            break;
        case 7:
            return 0;
        default:
            std::cout << "Invalid Choice.";
            break;
        }
    } while (true);
}

//C O N S T R U C T O R S

Node::Node() : item(0), prev(NULL), next(NULL) {}
Node::Node(int itm) : item(itm), prev(NULL), next(NULL) {}
List::List() : size(0), front(NULL), rear(NULL) {}

//Q U E U E :	W R A P P E R	F U N C T I O N S

int Queue::sizee() const
{
    return list.sizee();
}

bool Queue::empty() const
{
    return list.empty();
}

void Queue::frontt() const
{
    return list.frontt();
}

void Queue::back() const
{
    return list.back();
}

void Queue::enqueue(int itm)
{
    return list.enqueue(itm);
}

void Queue::dequeue()
{
    return list.dequeue();
}

void Queue::display()
{
    return list.display();
}

//L I S T	F U N C T I O N S

int List::sizee() const
{
    if (empty())
        return 0;
    return size;
}
bool List::empty() const
{
    if (size == 0)
        return true;
    return false;
}

void List::frontt() const
{
    if (empty())
        std::cout << "UNDERFLOW!" << std::endl; //if asking for front and it is empty then underflow
    else
        std::cout << "Front: " << front->item << std::endl; //printing value at front
}

void List::back() const
{
    if (empty())
        std::cout << "UNDERFLOW!" << std::endl; //if asking for rear and it is empty then underflow
    else
        std::cout << "Rear: " << rear->item << std::endl; //printing value at back
}

void List::enqueue(int itm)
{
    Node *temp = new Node(itm);
    if (temp == NULL)
    {
        std::cout << "Memory not allocated" << std::endl; //if allocated value for the temp is NULL then raise a "Memmory not allocated warning"
    }
    else if (empty())
        front = rear = temp; //if the list is empty then push the value at front and rear
    else
    {
        rear->next = temp; //set temp to be the next of rear
        temp->prev = rear; //set rear to be the previous of temp
        rear = temp;       //set temp as rear
    }
    size++;
}

void List::dequeue()
{
    if (empty())
    {
        std::cout << "UNDERFLOW!" << std::endl; //if empty then raise "underflow warning"
    }
    else
    {
        Node *del = front;                                       //set del node as front
        front = del->next;                                       //the next of del will be front
        std::cout << "Dequeue item: " << del->item << std::endl; //printing the value of del: the value to be pop
        if (front != NULL)
        {
            front->prev = NULL; //if front is not NULL then set the prev of front to NULL
        }
        delete del; //delete the del
        size--;
    }
    return;
}

void List::display()
{ //printing the value
    if (empty())
        return;
    std::cout << "Output" << std::endl;
    Node *temp = front;
    while (temp != NULL)
    {
        std::cout << temp->item << std::endl;
        temp = temp->next;
    }
}
#include <iostream>
#define MAX 5

class Array
{
public:
    int size;
    int front;
    int rear;
    int *array;
    Array();
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
    Array arr;

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
    Queue deq;
    int choice;

    std::cout << "The maximum size of Queue is 5.\n1.enqueue\n2.dequeue\n3.front\n4.back\n5.size\n6.check if empty\n7.Quit\n"
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
            deq.enqueue(choice);
            deq.display();
            break;
        case 2:
            deq.dequeue();
            deq.display();
            break;
        case 3:
            deq.frontt();
            break;
        case 4:
            deq.back();
            break;
        case 5:
            std::cout << "Size: " << deq.sizee() << std::endl;
            break;
        case 6:
            if (deq.empty())
                std::cout << "The queue is empty." << std::endl;
            else
                std::cout << "The queue is not empty." << std::endl;
            break;
        case 7:
            return 0;
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
        }
    } while (true);
}

Array::Array() : size(0), front(-1), rear(-1), array(new int[MAX]) {}

// W R A P P E R	 F U N C T I O N S

int Queue::sizee() const
{
    return arr.sizee();
}

bool Queue::empty() const
{
    return arr.empty();
}

void Queue::frontt() const
{
    return arr.frontt();
}

void Queue::back() const
{
    return arr.back();
}

void Queue::enqueue(int dta)
{
    return arr.enqueue(dta);
}

void Queue::dequeue()
{
    return arr.dequeue();
}
void Queue::display()
{
    return arr.display();
}

// A R R A Y	F U N C T I O N S

int Array::sizee() const
{
    if (empty())
        return 0;
    return size; //return size
}

bool Array::empty() const
{
    if (front == -1)
        return true; //if front is -1 (empty) return true
    return false;
}

void Array::frontt() const
{
    if (empty())
        std::cout << "UNDERFLOW!" << std::endl;
    else
        std::cout << "Front: " << array[front] << std::endl; //print the value in front
}

void Array::back() const
{
    if (empty())
        std::cout << "UNDERFLOW!" << std::endl;
    else
        std::cout << "Back: " << array[rear] << std::endl; //print the value in front
}

void Array::enqueue(int data)
{
    if ((rear + 1) % MAX == front) //if list is full then OVERFLOW
    {
        std::cout << "OVERFLOW!" << std::endl;
        return;
    }
    else if (empty())
    {
        front = rear = 0; //set front and rear to 0 if empty and put the pushed value at that index in the array
        array[rear] = data;
    }
    else
    {
        rear = (rear + 1) % MAX; //mathematical expression for finding the next index and put the pushed value at that index
        array[rear] = data;
    }
    size++;
}

void Array::dequeue()
{
    if (empty())
    {
        std::cout << "UNDERFLOW!" << std::endl;
    }
    else if (front == rear)
    {
        std::cout << "Dequeque Item: " << array[front] << std::endl; //if front is now in the rear (last index) then print the element to be dequeue and set front and rear to -1
        front = rear = -1;
    }
    else
    {
        std::cout << "Dequeue Item: " << array[front] << std::endl; //print the value to be dequeue
        front = (front + 1) % MAX;                                  //mathematical expression for setting front to next index
    }
    size--;
}

void Array::display()
{
    if (empty())
        return; //printing the list
    std::cout << "Output" << std::endl;

    int i;
    for (i = front; i != rear; i = (i + 1) % MAX)
    {
        std::cout << array[i] << std::endl;
    }
    std::cout << array[i] << std::endl;
}

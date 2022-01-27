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
    bool empty() const;
    void frontt() const;
    int data(int);
    void push(int);
    void pop();
    void display();
};

class Queue
{
private:
    Array arr;

public:
    bool empty() const;
    void frontt() const;
    void search(int);
    void push(int);
    void pop();
    void display();
};

int main()
{
    Queue que;
    int choice;

    std::cout << "The Maximum size of Array is 5.\n1.Push\n2.Pop\n3.Front\n4.Search\n5.Check if empty\n6.Quit" << std::endl;

    do
    {
        std::cout << "Enter Choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Value: ";
            std::cin >> choice;
            que.push(choice);
            que.display();
            break;
        case 2:
            que.pop();
            que.display();
            break;
        case 3:
            que.frontt();
            break;
        case 4:
            std::cout << "Index: ";
            std::cin >> choice;
            que.search(choice);
            break;
        case 5:
            if (que.empty())
                std::cout << "Array is empty." << std::endl;
            else
                std::cout << "Array is not empty." << std::endl;
            break;
        case 6:
            return 0;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    } while (true);
}

Array::Array() : size(0), front(-1), rear(-1), array(new int[MAX]) {}

bool Queue::empty() const
{
    return arr.empty();
}

void Queue::frontt() const
{
    return arr.frontt();
}

void Queue::search(int index)
{
    if (arr.empty())
        display(); //if the list is empty proceed to the display() func
    else if (index >= 0 && index < arr.size)
        std::cout << "Found: " << arr.data(index) << std::endl; //print if the not and if the index given is within the list
    else
        std::cout << "Index out of bound." << std::endl; //else the index given is out of bound
}

void Queue::push(int dta)
{
    return arr.push(dta); //proceed to the array class push function
}

void Queue::pop()
{
    return arr.pop(); //proceed to the array class pop function
}
void Queue::display()
{
    try
    {
        if (empty())
            throw 0;
        return arr.display(); //proceed to the array class display function
    }
    catch (int ex)
    {
        std::cout << "Underflow" << std::endl; //throw underflow if array is empty
    }
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
        std::cout << "Underflow " << std::endl;
    else
        std::cout << "Front: " << array[front] << std::endl; //print the value in front
}

int Array::data(int index)
{
    int i = front;
    if (i == 0 && index == 0)
        return array[index];           //if index and front is 0 then return the element at that index
    int currIndex = (i + index) % MAX; //mathematical expression for finding the index given
    return array[currIndex];
}

void Array::push(int data)
{
    if ((rear + 1) % MAX == front) //if list is full then OVERFLOW
    {
        std::cout << "OVERFLOW!" << std::endl;
        return;
    }
    else if (empty())
    {
        front = rear = 0; //set front and rear to 0 if empty and put the pushed value to that index
        array[rear] = data;
    }
    else
    {
        rear = (rear + 1) % MAX; //mathematical expression for finding the next index and put the pushed value to that index
        array[rear] = data;
    }
    size++;
}

void Array::pop()
{
    if (empty())
    {
        return;
    }
    else if (front == rear)
    {
        std::cout << "Pop Item: " << array[front] << std::endl; //if front is now in the rear (last index) then print the element to be pop and set them to -1
        front = rear = -1;
    }
    else
    {
        std::cout << "Pop Item: " << array[front] << std::endl; //print the value to be pop
        front = (front + 1) % MAX;                              //mathematical expression for setting front to next index
    }
    size--;
}

void Array::display()
{
    if (empty())
        std::cout << "List is empty."; //printing the list
    else
    {
        int i;
        for (i = front; i != rear; i = (i + 1) % MAX)
        {
            std::cout << array[i] << " ";
        }
        std::cout << array[i];
    }
    std::cout << std::endl;
}
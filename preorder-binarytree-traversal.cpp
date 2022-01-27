#include <iostream>
#include <queue>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node();
    Node(int);
};

class BinaryTree
{
private:
    Node *root;
    Node *createNewNode(int);

public:
    BinaryTree();
    Node *&getRoot();
    void insert(Node *&, int);
    void PreOrderTraversal(Node *);
};

int main()
{
    BinaryTree bin;
    int choice;

    std::cout << "----EXAMPLE BINARY TREE ILLUSTRATION----" << std::endl;

    std::cout << "\t\t\t14\n";
    std::cout << "\t\t17\t\t13\n";
    std::cout << "\t10\t      12  18\t\t8\n\n";
    std::cout << "Expected Pre-Order Traversal Output: 14 17 10 12 13 18 8 \n"
              << std::endl;

    std::cout << "1.Input(LEFT TO RIGHT)\n2.Display(PREODER TRAVERSAL)\n3.Quit\n"
              << std::endl;
    std::cout << "Input : 14 17 13 10 12 18 8" << std::endl;

    do
    {
        std::cout << "\nEnter choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Data: ";
            std::cin >> choice;
            bin.insert(bin.getRoot(), choice);
            break;
        case 2:
            std::cout << "Binary tree (PREODER TRAVERSAL): ";
            bin.PreOrderTraversal(bin.getRoot());
            std::cout << std::endl;
            break;
        case 3:
            return 0;
        default:
            std::cout << "Invalid choice";
            break;
        }
    } while (true);
}

Node::Node() : data(0), left(NULL), right(NULL) {}
Node::Node(int data) : data(data), left(NULL), right(NULL) {}
BinaryTree::BinaryTree() : root(NULL) {}

Node *&BinaryTree::getRoot()
{ //return the root of binary tree
    return root;
}

Node *BinaryTree::createNewNode(int data)
{ //create new node
    Node *temp = new Node(data);
    return temp;
}

void BinaryTree::insert(Node *&root, int data)
{ //insertion from left to right

    std::queue<Node *> queue;

    if (root == NULL)
    { //if root is null then insert the new node at root and return
        root = createNewNode(data);
        return;
    }
    queue.push(root);

    while (!queue.empty()) //while queue is not empty then;
    {
        Node *curr = queue.front(); //store the value at front of queue to a pointer to Node namely curr

        if (curr->left == NULL) //if the left child of curr is empty then
        {
            curr->left = createNewNode(data); //create a new node and put the address of it in the left child
            return;
        }
        else
            queue.push(curr->left);

        if (curr->right == NULL)
        { //same goes in here but it should be at right
            curr->right = createNewNode(data);
            return;
        }
        else
            queue.push(curr->right);
        queue.pop();
    }
}

void BinaryTree::PreOrderTraversal(Node *root)
{ //pre order traversal using recursion
    if (root != NULL)
    {
        std::cout << root->data << " ";
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}
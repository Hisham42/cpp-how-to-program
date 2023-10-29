#ifndef LIST_H
#define LIST_H

#include "Node.h"

template<typename T>
class List : private Node<T>
{
private:
    Node<T>* firstNode;
    Node<T>* lastNode;

    Node<T>* recSearchHelper(Node<T>*& n, T value) {
        
        if (n->value == value)
        {
            return n;
        }

        if (n->nextNode != nullptr)
        {
            recSearchHelper(n->nextNode, value);
            return nullptr;
        }
        
        return nullptr;
        
    }

    void recPrintHelper(Node<T>* n) {

        if (n->nextNode != nullptr)
        {
            recPrintHelper(n->nextNode);
        }

        std::cout << n->value << " ";
        
    }

    
public:
    List(T c)
    : firstNode(new Node<T>(c)), lastNode(firstNode) {}

    List()
    : firstNode(new Node<T>(T())), lastNode(firstNode) {}

    ~List() {
        Node<T>* temp = firstNode;
        Node<T>* current;
        while (temp != nullptr)
        {
            current = temp;
            temp = temp->nextNode;
            delete current;
        }
        
    }

    void insert(T c) {

        if (isempty()) {
            firstNode->value = c;
        }
        else {
            Node<T>* insertedNode = new Node<T>(c);
            insertedNode->nextNode = nullptr;
            lastNode->nextNode = insertedNode;
            lastNode = insertedNode;
        }
    }

    void inserAt(int place, T value) {
        
        Node<T>* newNode = new Node<T>(value); // create a pointer to carry the new Value
        Node<T>* prevTemp = firstNode; // create a temp PTR points to the first value
        int currentPlace = 0; // the initial place for the first node

        while (prevTemp != nullptr) // as long as temp != null move forward until you reach the place
        {
            if (currentPlace == place - 1) // if we reached the prev insertion place
            {

                break; // quit the loop
            }
            
            prevTemp = prevTemp->nextNode; // move forward
            currentPlace++;
        }

        if (currentPlace != place - 1)
        {
            delete newNode;
            std::cerr << "Invalid Insertion Place" << std::endl;
        }
        else
        {
            Node<T>* nxtTemp = prevTemp->nextNode;
            prevTemp->nextNode = newNode; // now the new node will point to temp.next
            newNode->nextNode = nxtTemp; // then
        }
    }

    void deleteAt(int place) {
        Node<T>* prevTemp = firstNode; // create a temp PTR points to the first value
        int currentPlace = 0; // the initial place for the first node

        while (prevTemp != nullptr) // as long as temp != null move forward until you reach the place
        {
            if (currentPlace == place - 1) // if we reached the prev insertion place
            {
                break; // quit the loop
            }
            prevTemp = prevTemp->nextNode; // move forward
            currentPlace++;
        }
        if (currentPlace != place - 1)
        {
            std::cerr << "Invalid Deletion Place" << std::endl;
        }
        else {
            Node<T>* target = prevTemp->nextNode;
            prevTemp->nextNode = target->nextNode;
            delete target;
        }
    }

    bool isempty() {

        if (firstNode == lastNode && firstNode->value == '\0')
        {
            return true;
        }
        else
            return false;
        
    }

    void print() {

        if (!isempty())
        {
            Node<T>* currentPtr = firstNode;

            while (currentPtr != nullptr)
            {
                std::cout << currentPtr->value << " ";
                currentPtr = currentPtr->nextNode;
            }
            std::cout << std::endl;
            
        }
        else
        {
            std::cout << "List is empty" << std::endl;
        }
        
    }

    void recPrint() {
        recPrintHelper(firstNode);
    }
   
    Node<T>* recSearch(T value) {
        return recSearchHelper(firstNode, value);
        
    }

    friend List<T> concatenate(const List<T>& l1, const List<T>& l2) {
        List<T> l3;

        //copy l1
        Node<T>* temp{nullptr};
        char c;
        temp = l1.firstNode;
        while (temp!= nullptr)
        {
            c = temp->value;
            l3.insertChar(c);
            temp = temp->nextNode;
        }
        temp = l2.firstNode;
        while (temp!= nullptr)
        {
            c = temp->value;
            l3.insertChar(c);
            temp = temp->nextNode;
        }
        
        return l3;
        
    }

    //function spilt, takes int indicating the split point
    //and a list to manipulate
    //it will retrun a new list with the remaing nodes
    friend List<T> split(int splittingPoint, List<T>& li) {
        //check if the splitting point is valid or not
        List splittedList;

        Node<T>* tempPtr = li.firstNode;
        Node<T>* newLast;
        int counter{1};

        while (splittingPoint != counter)
        {   
            newLast = tempPtr;
            tempPtr = tempPtr->nextNode;
            counter++;
        }

        
        Node<T>* assistant = tempPtr;

        while (tempPtr != nullptr)
        {
            char c = tempPtr->value;
            splittedList.insertChar(c);
            tempPtr = tempPtr->nextNode;
        }

        tempPtr = newLast;
        
        li.lastNode = newLast;
        return splittedList;
        
        
    }

    friend List<T> reverse(List<T>& li) {

        List<T> newList; // create an empty list
        Node<T>* ptr{nullptr}; // create a Ptr
        ptr = li.firstNode; // assign ptr to the targetted list

        reverseHelper(ptr, newList); // recursive function to insert reverse

        return newList;
        
    }

    bool reverseHelper(Node<T>* ptr, List<T>& newList) {

        // base
        if (ptr->nextNode == nullptr)
            {   
                newList.insertChar(ptr->value);         
                return true;
            }
        // recursive function
        if (reverseHelper(ptr->nextNode, newList))
        {
            newList.insertChar(ptr->value);
            return true;
        }

        return false;
    }

    // insert at back using first PTR only

    void insertAtBack(T value) {
        Node<T>* backPtr = firstNode;
        while (backPtr->nextNode != nullptr)
        {
            backPtr = backPtr->nextNode;
        }
        
        Node<T>* newNode = new Node<T>(value);
        backPtr->nextNode = newNode;
        newNode->nextNode = nullptr;
    }



};


#endif
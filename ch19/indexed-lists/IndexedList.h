#ifndef INDEXEDLIST_H
#define INDEXEDLIST_H

#include <iostream>
#include "IndexNode.h"

class IndexedList : private IndexNode
{
private:
    IndexNode* base;

    IndexNode* indexCheck(char c) {
        if (base != nullptr)
        {
            IndexNode* temp = base;

            while (temp != nullptr)
            {
                if (temp->indexValue == c)
                {
                    return temp;
                }
                temp = temp->nextIndex;
            }
            return nullptr;
        }
        else
            return nullptr;

    }

public:

    IndexedList() : base(nullptr) {

    };

    ~IndexedList() {
        IndexNode* tempIndex = base;
        IndexNode* currentIndex = tempIndex;
        Node* tempNode = nullptr;
        Node* currentNode = nullptr;
        while (tempIndex != nullptr)
        {
            tempNode = tempIndex->indexFirstNode;
            currentNode = tempNode;
            while (tempNode != nullptr)
            {
                currentNode = tempNode;
                tempNode = tempNode->nextNode;
                delete currentNode;
                currentNode = nullptr;

            }
            
            currentIndex = tempIndex;
            tempIndex = tempIndex->nextIndex;
            delete currentIndex;

            
        }
        
    }

    void insertInIndexedList(std::string value) {

        char index = value[0];
        
        // check for existing index if found then insert if not then create
        if (indexCheck(index) != nullptr) {
            IndexNode* indexPtr = indexCheck(index);

            if (indexPtr->indexFirstNode != nullptr)
            {
                Node* temp = indexPtr->indexFirstNode;
                Node* curr{temp};
            
                while (temp != nullptr)
                {
                    curr = temp;
                    temp = temp->nextNode;
                }

                curr->nextNode = new Node();
                curr->nextNode->nodeValue = value; 
            }
            else
            {
                indexPtr->indexFirstNode = new Node();
                indexPtr->indexFirstNode->nodeValue = value;
            }
            
            
        }
        else {
            IndexNode* tempIndexNode = new IndexNode();
            tempIndexNode->indexValue = index;
            tempIndexNode->indexFirstNode = new Node();
            tempIndexNode->indexFirstNode->nodeValue = value;

            if (base != nullptr)
            {
                IndexNode* temp = base;
                IndexNode* tempLast{temp};

                while (temp != nullptr)
                {
                    tempLast = temp;
                    temp = temp->nextIndex;
                }

                tempLast->nextIndex = tempIndexNode;
            }
            else {
                base = tempIndexNode;
            }
            
        }

        // if found then insert the value

        // if not then create a new index and insert the value
    }

    void deleteFromIndexedList (std::string value) {
        // if value exists, then find it and delete it
        Node* targettedValue{nullptr};
        IndexNode* targettedIndex{nullptr};
        if (searchHelper(value, targettedValue, targettedIndex))
        {
            if (targettedValue == targettedIndex->indexFirstNode)
            {
                targettedValue = targettedValue->nextNode;
                delete indexFirstNode;
                indexFirstNode = targettedValue;
                
            }
            else
            {
                Node* prev = targettedIndex->indexFirstNode;
                while (prev->nextNode != targettedValue)
                {
                    prev = prev->nextNode;
                }
                prev->nextNode = targettedValue->nextNode;
                delete targettedValue;

            }
            
        }
        
        else
        {
            std::cout << "Value is not in the List" << std::endl;
        }
        // else Value is not in the list
    }
    
    bool searchHelper(std::string value, Node*& target, IndexNode*& targetIndex) {
        // if found return true else return false
        char index = value[0];

        IndexNode* tempIndex = base;
        while (tempIndex->indexValue != index && tempIndex != nullptr)
        {
            tempIndex = tempIndex->nextIndex;
        }
        
        if (tempIndex->indexValue == index)
        {
            targetIndex = tempIndex;
            target = tempIndex->indexFirstNode;
            while (target->nodeValue != value && target->nextNode != nullptr)
            {
                target = target->nextNode;
            }
 
        }
        if (target->nodeValue == value)
        {
            return true;
        }
        else
            return false;
        


    }

    void searchIndexedList(std::string value) {
        Node* targettedValue{nullptr};
        IndexNode* targettedIndex{nullptr};
        if (searchHelper(value, targettedValue, targettedIndex))
        {
            std::cout << value << " exists!" << std::endl;
        }
        else
            std::cout << value << " cannot be found!" << std::endl;

    }


    
};

#endif
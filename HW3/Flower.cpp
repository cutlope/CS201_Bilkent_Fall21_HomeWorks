//Abdullah Riaz
//22001296
//Section: 01

using namespace std;
#include <iostream>
#include <string>
#include "Flower.h"
#include <cstddef>

Flower::Flower()
{
    this->size = 0;
    this->head = NULL;
}

Flower::Flower(string flowerName)
{
    this->size = 0;
    this->head = NULL;
    this->flowerName = flowerName;
}

Flower::Flower(const Flower &aFlower)
{
    if (aFlower.head == NULL)
    {
        this->flowerName = aFlower.getName();
        this->head = NULL;
        this->size = 0;
    }
    else
    {
        FeatureNode *newPtr = NULL;
        FeatureNode *ptr = aFlower.head;
        for (; ptr != NULL; ptr = ptr->next)
        {
            FeatureNode *newNode = new FeatureNode;
            newNode->feature = ptr->feature;
            newNode->next = newPtr;
            newPtr = newNode;
        }
        this->flowerName = aFlower.getName();
        this->head = newPtr;
        this->size = aFlower.size;
    }
}

Flower::~Flower()
{
    FeatureNode *ptr = head;
    while (ptr != NULL)
    {
        //hold the next pointer
        FeatureNode *temp = ptr->next;
        delete ptr;
        ptr = temp;
    }
}

bool Flower::isEmpty() const
{
    return (size == 0);
}

int Flower::getLength() const
{
    return size;
}

bool Flower::add(string feature)
{
    //check if the feature is already in the list
    FeatureNode *ptr = head;

    //duplicate feature check
    for (FeatureNode *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->feature == feature)
        {
            return false;
        }
    }

    //add the feature to the list
    FeatureNode *newPtr = new FeatureNode;
    newPtr->feature = feature;

    //if the list is empty
    if (head == NULL)
    {
        head = newPtr;
        newPtr->next = NULL;
        size++;
        return true;
    }
    else
    {
        FeatureNode *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newPtr;
        newPtr->next = NULL;
        size++;
        sort();
        return true;
    }
}

bool Flower::remove(string feature)
{

    for (FeatureNode *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->feature == feature)
        {
            //if the feature is the first node
            if (ptr == head)
            {
                head = head->next;
                delete ptr;
                size--;
                return true;
            }
            else
            {
                FeatureNode *temp = head;
                while (temp->next != ptr)
                {
                    temp = temp->next;
                }
                temp->next = ptr->next;
                delete ptr;
                size--;
                return true;
            }
        }
    }

    //if feature doesnt exist
    return false;
}

string Flower::printFlower() const
{

    string output = "";
    for (FeatureNode *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        output += ptr->feature + ", ";
    }
    if (output == "") //if empty
    {
        output = "No features";
    }
    return output;
}

void Flower::setName(string flowerName)
{
    this->flowerName = flowerName;
}

string Flower::getName() const
{
    return flowerName;
}

bool Flower::doesFeatureExist(string feature) const
{
    if (head == NULL)
    {
        return false;
    }
    else
    {
        for (FeatureNode *ptr = head; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->feature == feature)
            {
                return true;
            }
        }
    }
}

void Flower::sort()
{
    for (FeatureNode *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        for (FeatureNode *ptr2 = ptr->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            if (ptr->feature > ptr2->feature)
            {
                string temp = ptr->feature;
                ptr->feature = ptr2->feature;
                ptr2->feature = temp;
            }
        }
    }
}

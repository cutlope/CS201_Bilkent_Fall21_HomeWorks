//Abdullah Riaz
//22001296
//Section: 01

using namespace std;
#include <iostream>
#include <string>
#include "FlowerList.h"
#include <cstddef>

FlowerList::FlowerList()
{
    head = NULL;
    size = 0;
}

FlowerList::FlowerList(const FlowerList &other)
{
    head = NULL;
    size = 0;
    FlowerNode *temp = other.head;
    while (temp != NULL)
    {
        add(temp->f.getName());
        temp = temp->next;
    }
}

FlowerList::~FlowerList()
{
    FlowerNode *temp = head;
    while (temp != NULL)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}

bool FlowerList::isEmpty() const
{
    return (size == 0);
}

int FlowerList::getLength() const
{
    return size;
}

bool FlowerList::retrieve(string Flowername, Flower &flower) const
{
    FlowerNode *temp = head;
    while (temp != NULL)
    {
        if (temp->f.getName() == Flowername)
        {
            flower = temp->f;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool FlowerList::add(string flowerName)
{
    if (head == NULL)
    {
        FlowerNode *temp = new FlowerNode;
        temp->f.setName(flowerName);
        temp->next = NULL;
        head = temp;
        size++;
        return true;
    }

    else
    {
        //Duplicate Check
        FlowerNode *temp = head;
        while (temp->next != NULL)
        {
            if (temp->f.getName() == flowerName)
            {
                cout << flowerName << " cannot be added as it already exists in the library" << endl;
                return false;
            }
            temp = temp->next;
        }

        //Check last item
        if (temp->f.getName() == flowerName)
        {
            cout << flowerName << " cannot be added as it already exists in the library" << endl;
            return false;
        }

        if (head == NULL || head->f.getName() > flowerName)
        {
            FlowerNode *temp = new FlowerNode;
            temp->f.setName(flowerName);
            temp->next = head;
            head = temp;
            size++;
            return true;
        }

        else
        {

            //Add new item sorted
            FlowerNode *temp2 = head;
            while (temp2->next != NULL && temp2->next->f.getName() < flowerName)
            {
                temp2 = temp2->next;
            }
            FlowerNode *temp3 = new FlowerNode;
            temp3->f.setName(flowerName);
            temp3->next = temp2->next;
            temp2->next = temp3;
            size++;
            return true;
        }
    }
}

bool FlowerList::addFeature(string flowerName, string feature)
{
    for (FlowerNode *cur = head; cur != NULL; cur = cur->next)
    {
        if (cur->f.getName() == flowerName)
        {
            //Warning Message in case the feature already exists.
            if (!(cur->f.add(feature)))
            {
                cout << feature << " already exists in " << flowerName << endl;
                return false;
            }
            else
            {
                return true;
            }
        }
    }

    cout << flowerName << " does not exist in the library" << endl;
    return false;
}

bool FlowerList::remove(string flowerName)
{
    if (head == NULL)
    {
        cout << flowerName << "Operation could not be completed as he Library is completely empty" << endl;
        return false;
    }

    for (FlowerNode *cur = head; cur != NULL; cur = cur->next)
    {
        if (cur->f.getName() == flowerName)
        {
            //Cheking if the flower is the first node
            if (cur == head)
            {
                head = head->next;
                delete cur;
                size--;
                return true;
            }
            else
            {
                FlowerNode *temp = head;
                while (temp->next != cur)
                {
                    temp = temp->next;
                }
                temp->next = cur->next;
                delete cur;
                size--;
                return true;
            }
        }
    }

    cout << flowerName << " cannot be removed because it's not in the library" << endl;
    return false;
}

bool FlowerList::removeFeature(string flowerName, string feature)
{
    if (head == NULL)
    {
        cout << feature << " does not exist in " << flowerName << endl;
        return false;
    }

    for (FlowerNode *cur = head; cur != NULL; cur = cur->next)
    {
        if (cur->f.getName() == flowerName)
        {

            if (!(cur->f.remove(feature)))
            {
                cout << feature << " does not exist in " << flowerName << endl;
                return false;
            }
            else
            {
                return true;
            }
        }
    }

    cout << flowerName << " does not exist in the library" << endl;
    return false;
}

//Prints all the flowers in the library
void FlowerList::print() const
{
    if (head == NULL)
    {
        cout << "The library is empty" << endl;
    }

    //loop through the list of flowers
    for (FlowerNode *cur = head; cur != NULL; cur = cur->next)
    {
        cout << cur->f.getName() << ": ";
        cout << cur->f.printFlower() << endl;
    }
}

//Prints the specified flower
bool FlowerList::print(string flowerName) const
{

    for (FlowerNode *cur = head; cur != NULL; cur = cur->next)
    {
        if (cur->f.getName() == flowerName)
        {
            cout << flowerName << ": ";
            cout << cur->f.printFlower() << endl;
            return true;
        }
    }
    return false;
}

void FlowerList::findFeature(string feature) const
{

    for (int i = 0; i < feature.length(); i++)
        feature[i] = tolower(feature[i]);

    bool isEmpty = true;
    cout << feature << " flowers: ";
    for (FlowerNode *cur = head; cur != NULL; cur = cur->next)
    {
        if (cur->f.doesFeatureExist(feature))
        {
            cout << cur->f.getName() << ", ";
            isEmpty = false;
        }
    }
    if (isEmpty)
    {
        cout << "no such flowers in library" << endl;
    }
    cout << endl;
}

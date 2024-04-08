#ifndef FOODLIST_H
#define FOODLIST_H

#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int day, month, year;

public:
    Date(int d = 1, int m = 1, int y = 1970);
    void read();
    void write() const;
};
template <typename T>
class Node;

template <typename T>
class FoodList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int count;

public:
    FoodList() : head(nullptr), tail(nullptr), count(0) {}
    ~FoodList()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current->data;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    void sortedInsert(T *newFood)
    {
        Node<T> *newNode = new Node<T>(newFood);
        if (head == nullptr || head->data->Name >= newFood->Name)
        {
            newNode->next = head;
            if (head != nullptr)
            {
                head->prev = newNode;
            }
            head = newNode;
            if (tail == nullptr)
            {
                tail = newNode;
            }
        }
        else
        {
            Node<T> *current = head;
            while (current->next != nullptr && current->next->data->Name < newFood->Name)
            {
                current = current->next;
            }
            newNode->next = current->next;
            if (current->next != nullptr)
            {
                newNode->next->prev = newNode;
            }
            else
            {
                tail = newNode;
            }
            current->next = newNode;
            newNode->prev = current;
        }
        count++;
    }

    T *search(const std::string &name)
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            if (current->data->Name == name)
            {
                return current->data;
            }
            current = current->next;
        }
        return nullptr;
    }

    void deleteItem(const std::string &name)
    {
        if (count == 0)
        {
            cout << "Database Empty";
        }
        else
        {
            int chk = 0;
            Node<T> *current = head;
            while (current != nullptr)
            {
                if (current->data->Name == name)
                {
                    chk += 1;
                    if (current->prev)
                    {
                        current->prev->next = current->next;
                    }
                    else
                    {
                        head = current->next;
                    }
                    if (current->next)
                    {
                        current->next->prev = current->prev;
                    }
                    else
                    {
                        tail = current->prev;
                    }
                    delete current->data;
                    delete current;
                    count--;
                    return;
                }
                current = current->next;
            }
            if (chk == 0)
            {
                cout << "Item not found" << endl;
            }
        }
    }

    void display() const
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            current->data->write();
            current = current->next;
            cout << '\n';
        }
    }

    void clear()
    {
        if (head == nullptr)
        {
            cout << "List was empty." << endl;
            return;
        }
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current->data;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        count = 0;
        cout << "List cleared." << std::endl;
    }

    bool empty() const
    {
        return head == nullptr;
    }

    int count_num() const
    {
        return count;
    }

    bool is_sorted() const
    {
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }

        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            if (temp->data->Name > temp->next->data->Name)
            {
                return false; // Found two adjacent elements out of order
            }
            temp = temp->next;
        }
        return true; // All elements are in the correct order
    }
};

template <typename T>
class Node
{
    friend class FoodList<T>;

public:
    T *data;
    Node<T> *prev;
    Node<T> *next;
    Node(T *food) : data(food) {}
};

class Food
{
    friend class FoodList<Food>;

protected:
    int ID, quantity;
    string Name;
    Date expiryDate;

public:
    Food(int id = 0, std::string name = "", int qty = 0, Date expiry = Date());
    virtual void read();
    virtual void write() const;
};
class dryStorage : public Food
{
private:
    int lightSens;

public:
    dryStorage(int id = 0, std::string name = "", int qty = 0, Date expiry = Date(), int lightSens = 0);
    void read();
    void write() const;
};

class canned : public Food
{
private:
    float canSize;

public:
    canned(int id = 0, std::string name = "", int qty = 0, Date expiry = Date(), float canSize = 0);
    void read();
    void write() const;
};

class frozen : public Food
{
private:
    float minTemp;

public:
    frozen(int id = 0, std::string name = "", int qty = 0, Date expiry = Date(), float minTemp = 0);
    void read();
    void write() const;
};

class refrigerated : public Food
{
private:
    int maxTemp;

public:
    refrigerated(int id = 0, std::string name = "", int qty = 0, Date expiry = Date(), float maxTemp = 0);
    void read();
    void write() const;
};
#endif //_FOODLIST_H_

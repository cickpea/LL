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

class Food
{
    friend class FoodList;

protected:
    int ID, quantity;
    string Name;
    Date expiryDate;

public:
    Food(int id = 0, std::string name = "", int qty = 0, Date expiry = Date());
    void read();
    void write() const;
};

class Node
{
    friend class FoodList;

private:
    Food *data;
    Node *prev;
    Node *next;

public:
    Node(Food *food);
};

class FoodList
{
private:
    Node *head;
    Node *tail;

public:
    FoodList();
    ~FoodList();
    void sortedInsert(Food *newFood);
    Food *search(const std::string &name);
    void deleteItem(const std::string &name);
    void display() const;
    int count() const;
    void clear();
    bool empty() const;
};

#endif // FOODLIST_H
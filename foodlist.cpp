
#include "foodlist.h"

using namespace std;

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

void Date::read()
{
    char slash;
    cout << "Enter the Expiry Date (d/m/y): ";
    cin >> day >> slash >> month >> slash >> year;
}

void Date::write() const
{
    std::cout << day << "/" << month << "/" << year;
}

Food::Food(int id, std::string name, int qty, Date expiry)
    : ID(id), Name(name), quantity(qty), expiryDate(expiry) {}

void Food::read()
{
    cout << "     " << endl;
    cout << "Enter ID: ";
    cin >> ID;
    // std::cin.ignore();
    cout << "Enter Name: ";
    cin >> Name;
    cout << "Enter Quantity: ";
    cin >> quantity;
    expiryDate.read();
}

void Food::write() const
{
    cout << "ID: " << ID << "\t Name: " << Name << "\t Quantity: " << quantity << "\t Expiry Date: ";
    expiryDate.write();
    cout << "\t";
    // std::cout << std::endl;
}

Node::Node(Food *food) : data(food), prev(NULL), next(NULL) {}

FoodList::FoodList() : head(NULL), tail(NULL) {}

FoodList::~FoodList()
{ // This is a desctructor, good practice to include this, can remove if required
    clear();
}

void FoodList::sortedInsert(Food *newFood)
{
    Node *newNode = new Node(newFood);
    if (head == NULL || head->data->Name >= newFood->Name)
    {
        newNode->next = head;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == NULL)
        {
            tail = newNode;
        }
    }
    else
    {
        Node *current = head;
        while (current->next != NULL && current->next->data->Name < newFood->Name)
        {
            current = current->next;
        }
        newNode->next = current->next;
        if (current->next != NULL)
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
}

Food *FoodList::search(const std::string &name)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data->Name == name)
        {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

void FoodList::deleteItem(const std::string &name)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data->Name == name)
        {
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
            return;
        }
        current = current->next;
    }
}

void FoodList::display() const
{
    Node *current = head;
    while (current != NULL)
    {
        current->data->write();
        current = current->next;
        cout << '\n';
    }
}

void FoodList::clear()
{
    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;
        delete current->data;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
}

bool FoodList::empty() const
{
    return head == NULL;
}

int FoodList::count() const
{
    int itemCount = 0;
    Node *current = head;
    while (current != NULL)
    {
        itemCount++;
        current = current->next;
    }
    return itemCount;
}

dryStorage::dryStorage(int id, std::string name, int qty, Date expiry, int lightSens) : Food(id, name, qty, expiry), lightSens(lightSens)
{
}

void dryStorage::read()
{
    Food::read();
    cout << "Enter Product Light Sensitivity:";
    cin >> lightSens;
}

void dryStorage::write() const
{
    Food::write();
    cout << "Light Sensitivity: " << lightSens;
}

canned::canned(int id, std::string name, int qty, Date expiry, float canSize) : Food(id,name,qty,expiry), canSize(canSize)
{
}

void canned::read()
{
    Food::read();
    cout << "Enter Can size: ";
    cin >> canSize;
}

void canned::write() const
{
    Food::write();
    cout << "Can size: " << canSize;
}

frozen::frozen(int id, std::string name, int qty, Date expiry, float minTemp) : Food(id, name, qty, expiry), minTemp(minTemp)
{
}

void frozen::read()
{
    Food::read();
    cout << "Enter minimum storage temperature:";
    cin >> minTemp;
}

void frozen::write() const
{
    Food::write();
    cout << "Minimum storage temperature: " << minTemp;
}

refrigerated::refrigerated(int id, std::string name, int qty, Date expiry, float maxTemp) : Food(id, name, qty, expiry), maxTemp(maxTemp)
{
}

void refrigerated::read()
{
    Food::read();
    cout << "Enter maximum storage temperature:";
    cin >> maxTemp;
}

void refrigerated::write() const
{
    Food::write();
    cout << "Maximum storage temperature: " << maxTemp;
}
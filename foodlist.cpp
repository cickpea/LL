
#include "foodlist.h"

using namespace std;

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

void Date::read() {
    char slash;
    cin >> day >> slash >> month >> slash >> year;
}

void Date::write() const {
    std::cout << day << "/" << month << "/" << year;
}

Food::Food(int id, std::string name, int qty, Date expiry)
    : ID(id), Name(name), quantity(qty), expiryDate(expiry) {}

void Food::read() {
    cout << "     " << endl;
    cout << "Enter ID: ";
    cin >> ID;
    // std::cin.ignore();
    cout << "Enter Name: ";
    cin >> Name;
    cout << "Enter Quantity: ";
    cin >> quantity;
    cout << "Enter the Expiry Date: ";
    expiryDate.read();
}

void Food::write() const {
    cout << "ID: " << ID << ", Name: " << Name << ", Quantity: " << quantity << ", Expiry Date: ";
    expiryDate.write();
    std::cout << std::endl;
}

Node::Node(Food* food) : data(food), prev(NULL), next(NULL) {}

FoodList::FoodList() : head(NULL), tail(NULL) {}

FoodList::~FoodList() { // This is a desctructor, good practice to include this, can remove if required
    clear();
}

void FoodList::sortedInsert(Food* newFood) {
    Node* newNode = new Node(newFood);
    if (head == NULL || head->data->Name >= newFood->Name) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == NULL) {
            tail = newNode;
        }
    }
    else {
        Node* current = head;
        while (current->next != NULL && current->next->data->Name < newFood->Name) {
            current = current->next;
        }
        newNode->next = current->next;
        if (current->next != NULL) {
            newNode->next->prev = newNode;
        }
        else {
            tail = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

Food* FoodList::search(const std::string& name) {
    Node* current = head;
    while (current != NULL) {
        if (current->data->Name == name) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

void FoodList::deleteItem(const std::string& name) {
    Node* current = head;
    while (current != NULL) {
        if (current->data->Name == name) {
            if (current->prev) {
                current->prev->next = current->next;
            }
            else {
                head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            else {
                tail = current->prev;
            }
            delete current->data;
            delete current;
            return;
        }
        current = current->next;
    }
}

void FoodList::display() const {
    Node* current = head;
    while (current != NULL) {
        current->data->write();
        current = current->next;
    }
}

void FoodList::clear() {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        delete current->data;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
}

bool FoodList::empty() const {
    return head == NULL;
}

int FoodList::count() const{
    int itemCount = 0;
    Node* current = head;
    while (current != NULL) {
        itemCount++;
        current = current->next;
    }
    return itemCount;
}
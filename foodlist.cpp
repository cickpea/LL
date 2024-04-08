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
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, Name);
    cout << "Enter Quantity: ";
    cin >> quantity;
    expiryDate.read();
}

void Food::write() const
{
    cout << "ID: " << ID << "\t Name: " << Name << "\t Quantity: " << quantity << "\t Expiry Date: ";
    expiryDate.write();
    cout << "\t";
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

canned::canned(int id, std::string name, int qty, Date expiry, float canSize) : Food(id, name, qty, expiry), canSize(canSize)
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
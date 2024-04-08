#include "foodlist.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    FoodList<Food> myList;
    Food* newFood;
    char choice;

    while (true)
    {
        cout << "    " << endl;
        cout << "'a': add " << endl;
        cout << "'s': search" << endl;
        cout << "'p': print" << endl;
        cout << "'d': delete" << endl;
        cout << "'e': check for empty" << endl;
        cout << "'h': Check if the list is sorted" << endl;
        cout << "'n': size or count" << endl;
        cout << "'c': clear the structure entirely" << endl;
        cout << "'q': quit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        // std::cin.ignore();

        if (choice == 'q')
        {
            myList.clear();
            break;
        }

        switch (choice)
        {
        case 'a':
        {
            cout << "'d': Dry Storage\n'c': Canned\n'f': Frozen\n'r': Refrigerated\nChoose type: ";
            cin >> choice;
            switch (choice)
            {
            case 'd':
            {
                newFood = new dryStorage();
                break;
            }
            case 'c':
            {
                newFood = new canned();
                break;
            }
            case 'f':
            {
                newFood = new frozen();
                break;
            }
            case 'r':
            {
                newFood = new refrigerated();
                break;
            }
            }
            newFood->read();
            myList.sortedInsert(newFood);
            cout << "Item added and sorted." << std::endl;
            break;
        }
        case 's':
        {
            string searchName;
            cout << "Enter the name of the food item to search: ";
            cin >> searchName;
            Food* foundItem = myList.search(searchName);
            if (foundItem != NULL)
            {
                cout << "\nFood item found:" << std::endl;
                foundItem->write();
            }
            else
            {
                cout << "\nFood item not found." << std::endl;
            }
            break;
        }
        case 'p':
        {
            cout << "\nFood items in the list:" << std::endl;
            myList.display();
            break;
        }
        case 'd':
        {
            string deleteName;
            cout << "Enter the name of the food item to delete: ";
            cin >> deleteName;
            myList.deleteItem(deleteName);
            break;
        }
        case 'e':
        {
            if (myList.empty())
            {
                cout << "List is empty." << std::endl;
            }
            else
            {
                cout << "List is not empty." << std::endl;
            }
            break;
        }
        case 'h':
        {
            bool chk = myList.is_sorted();
            if (chk) {
                cout << "List Sorted.\n";
            }
            else {
                cout << "List Not Sorted.\n";
            }
        }
        case 'n':
        {
            cout << "The count is " << myList.count_num() << std::endl;
            break;
        }
        case 'c':
        {
            myList.clear();
            cout << "List cleared." << std::endl;
            break;
        }
        default:
            cout << "\nInvalid choice." << std::endl;
            break;
        }
    }

    return 0;
}
#include <iostream>
#include <chrono>
#include <thread>
#include "PharmacyClass.cpp"

using namespace std;
int main()
{
    int barcode;
    string name;
    int quantity;
    double price;
    int oldbarcode;
    int AddChoice;
    char UserChoice;

    PharmacyClass PharmacyList;


    while (true)
    {
        cout << "Pharmacy Management System" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Add an item." << endl;
        cout << "2. Remove an item." << endl;
        cout << "3. Modify an item." << endl;
        cout << "4. Auto check the pharmacy inventory." << endl;
        cout << "5. Find an item." << endl;
        cout << "6. Generate a bill." << endl;
        cout << "7. Quit!" << endl;
        cout << "--------------------------" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
           cout << "Add an item.\n--------------------------" << endl;
           cout << "1. Add a new first item." << endl;
           cout << "2. Add a new last item." << endl;
           cout << "3. Add a new item before an existed item." << endl;
           cout << "4. Quit!" << endl;
           cout << "--------------------------" << endl;
           cout << "Code Contributors :\n1 - Ahmed Samir  Ibrahem El Sayed\n2 - Mohamed Nadim Mohamed Mohamed" << endl;
           cout << "Enter your choice: ";
            cin >> AddChoice;
            switch (AddChoice)
            {
            case 1:
            {
                cout << "Enter the barcode of the item to add: ";
                cin >> barcode;
                cout << "Enter the name of the item: ";
                cin >> name;
                cout << "Enter the quantity of the item: ";
                cin >> quantity;
                cout << "Enter the price of the item: ";
                cin >> price;
                PharmacyList.InsertFirst(barcode, name, quantity, price);
                cout << endl;
                break;

            }
            break;
            case 2:
            {
                cout << "Enter the barcode of the item to add: ";
                cin >> barcode;
                cout << "Enter the name of the item: ";
                cin >> name;
                cout << "Enter the quantity of the item: ";
                cin >> quantity;
                cout << "Enter the price of the item: ";
                cin >> price;
                PharmacyList.InsertLast(barcode, name, quantity, price);
                cout << endl;
                break;
            }
            break;
            case 3:
            {
                cout << "Enter the barcode of the existed item you want to add before: ";
                cin >> oldbarcode;
                //PharmacyList.InsertBefore(OldBarcode, NewBarcode, Name, Quantity, Price)
                cout << "Enter the barcode of the item to add: ";
                cin >> barcode;
                cout << "Enter the name of the item: ";
                cin >> name;
                cout << "Enter the quantity of the item: ";
                cin >> quantity;
                cout << "Enter the price of the item: ";
                cin >> price;
                PharmacyList.InsertBefore(oldbarcode, barcode, name, quantity, price);
                cout << endl;
                break;
            }
            break;
            case 4:
            {
                cout << "\n\n";
                break;
            }
            break;
            default:
            {
                cout << "Invalid choice.\n\n" << endl;
                break;
            }
            break;
            }
        }
        break;
        case 2:
        {
            if (PharmacyList.IsEmpty())
            {
                cout << "Pharmacy list is empty ,there are no items to be deleted.\n\n";
            }
            else if (PharmacyList.IsExist(barcode) == true)
            {
                cout << "Enter the barcode of the item you want to delete: ";
                cin >> barcode;
                cout << "Are you sure you want to delete this item? (y/n)\n";
                cin >> UserChoice;
                if (UserChoice == 'y' || UserChoice == 'Y')
                {
                    PharmacyList.DeleteItem(barcode);
                    
                    break;
                }
                else if (UserChoice == 'n' || UserChoice == 'N')
                {
                    cout << "The item has not been deleted.\n\n";
                    break;
                }
                else
                {
                    cout << "Invalid choice.\n" << endl;
                    break;
                }
                break;
            }
            else
            {
                cout << "\nThe barcode (" << barcode << ") is not found\n" << endl;
                break;
            }
            ;break;
        }
        break;
        case 3: 
        {
            if (PharmacyList.IsEmpty())
            {
                cout << "Pharmacy list is empty ,there are no items to be modified.\n\n";
                break;
            }
            cout << "Enter the barcode of the item to modify: ";
            cin >> barcode;
            if (PharmacyList.IsExist(barcode) == true)
            {
                cout << "Enter the name of the item to modify: ";
                cin >> name;
                cout << "Enter the new quantity of the item: ";
                cin >> quantity;
                cout << "Enter the new price of the item: ";
                cin >> price;
                PharmacyList.Modify(barcode, name, quantity, price);
                cout << "\n\n";
                break;
            }
            else
            {
                cout << "The barcode (" << barcode << ") is not found\n\n" << endl;
                break;
            }
        }
        break;
        
        case 4: 
        {
            if (PharmacyList.IsEmpty())
            {
                cout << "Pharmacy list is empty, there are no items to check.\n\n";
                break;
            }
            else
            {
                PharmacyList.AutoCheck();
                break;
            }
        }
        break;

        case 5: 
        {
            cout << "Enter the barcode of the item to find: ";
            cin >> barcode;
            PharmacyList.IsFound(barcode);
            break;
        }
              break;
        case 6: 
        {
            PharmacyList.Print();
            break;
        }
              break;
        case 7: 
        {
            cout << "Are you sure you want to quit? (y/n)\n";
            cin >> UserChoice;
            if (UserChoice == 'y' || UserChoice == 'Y')
            {
                cout << "\n\n";
                return 0;
            }
            else
            {
                cout << "\n\n";
                break;
            }
        }
              
        default: 
        {
            cout << "Invalid choice.\n\n" << endl;
            break;
        }
        }

    }
    return 0;
}



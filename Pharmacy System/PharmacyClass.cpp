#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

/*
Code Contributors :
  1- Ahmed Samir  Ibrahem El Sayed
  2- Mohamed Nadim Mohamed Mohamed
  */



//The components of each node (Class)
class node                  
{
public:
    int barcode;
    string name;
    int quantity;
    double price;
    node* next;
    node* prev;
};

//The Pharmacy list functions (Double linked list class)
class PharmacyClass    
{
private:
    node* Header;
    int Counter = 0;
public:
    //Default Constructor
    PharmacyClass()          
    {
        Header = NULL;
    }

    //Is the Pharmacy list empty? (Function)
    bool IsEmpty()         
    {
        return (Header == NULL);
    }

    //Does the item with the given barcode exist? (Function)
    bool IsExist(int barcode)
    {
        node* temp = Header;
        while (temp != NULL)
        {
            if (temp->barcode == barcode)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    //Insert a new first node to the front of the Double Linked List (Function)
    void InsertFirst(int Barcode, string Name, int Quantity, double Price)
    {
        node* newnodeptr = new node;
        newnodeptr->prev = NULL;
        newnodeptr->barcode = Barcode;
        newnodeptr->name = Name;
        newnodeptr->quantity = Quantity;
        newnodeptr->price = Price;
        newnodeptr->next = Header;
        if (Header != NULL) Header->prev = newnodeptr;
        Header = newnodeptr;
        Counter++;
    }

    //Insert a new last node to the end of the Double Linked List (Function)
    void InsertLast(int Barcode, string Name, int Quantity, double Price)
    {
        if (IsEmpty())
        {
            InsertFirst(Barcode, Name, Quantity, Price);
            return;
        }

        node* newnodeptr = new node;
        node* lastptr = Header;
        while (lastptr->next != NULL) lastptr = lastptr->next;

        newnodeptr->prev = lastptr;
        newnodeptr->barcode = Barcode;
        newnodeptr->name = Name;
        newnodeptr->quantity = Quantity;
        newnodeptr->price = Price;
        newnodeptr->next = NULL;
        lastptr->next = newnodeptr;
        Counter++;
    }

    //Insert an item before another existed item
    void InsertBefore(int OldBarcode, int NewBarcode, string Name, int Quantity, double Price)
    {
        if (IsEmpty())
        {
            cout << "The list is empty; the new item was not inserted.\\n\\n";
            return;
        }

        node* current = Header;
        while (current != NULL && current->barcode != OldBarcode) current = current->next;
        if (current == NULL)
        {
            cout << "The reference barcode " << OldBarcode << " was not found.\\n\\n";
            return;
        }
        if (IsExist(NewBarcode))
        {
            cout << "An item with barcode " << NewBarcode << " already exists.\\n\\n";
            return;
        }

        node* newnodeptr = new node;
        newnodeptr->barcode = NewBarcode;
        newnodeptr->name = Name;
        newnodeptr->quantity = Quantity;
        newnodeptr->price = Price;
        newnodeptr->next = current;
        newnodeptr->prev = current->prev;

        if (current->prev != NULL) current->prev->next = newnodeptr;
        else Header = newnodeptr;
        current->prev = newnodeptr;
        Counter++;
    }

    //Delete a node of the Double Linked List (Function)
    void DeleteItem(int barcode)
    {
        node* current = Header;
        while (current != NULL && current->barcode != barcode) current = current->next;
        if (current == NULL)
        {
            cout << "Item is not found.\\n\\n";
            return;
        }

        if (current->prev != NULL) current->prev->next = current->next;
        else Header = current->next;
        if (current->next != NULL) current->next->prev = current->prev;

        delete current;
        Counter--;
    }

    // Modify an item
    void Modify(int barcode, string name, int quantity, double price)
    {
        node* temp = Header;
        while (temp != NULL)
        {
            if (temp->barcode == barcode)
            {
                temp->name = name;
                temp->quantity = quantity;
                temp->price = price;
                return;
            }
            temp = temp->next;
        }
        cout << "barcode:" << barcode << " not found" << ".\n";
    }

    // Auto check the pharmacy inventory
    void AutoCheck()
    {
        bool lowStockFound = false;
        cout << "Checking the pharmacy inventory\\n";
        node* temp = Header;
        cout << "Please wait ";
        for (int loading = 0; loading < 15; loading++)
        {
            cout << ".";
            this_thread::sleep_for(std::chrono::milliseconds(250));
        }
        cout << endl;

        while (temp != NULL)
        {
            if (temp->quantity <= 15)
            {
                lowStockFound = true;
                cout << "Low stock alert for " << temp->name << ".\\n\\n";
            }
            temp = temp->next;
        }
        if (!lowStockFound)
            cout << "There is no low stock for any items in the pharmacy.\\n" << endl;
    }

    // Find the memory location of an item in the pharmacy list
    void IsFound(int barcode)
    {
        node* temp = Header;
        while (temp != NULL)
        {
            if (temp->barcode == barcode)
            {
                cout << "\nThe barcode (" << barcode << ") is found at location " << temp << endl << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "\nThe barcode (" << barcode << ") is not found\n" << endl;
    }

    // Print all the data of all the items in the pharmacy list
    void Print()
    {
        if (IsEmpty())
        {
            cout << "There is no bill. The pharmacy list is empty\n";
        }
        else
        {
            node* temp = Header;
            cout << "\nThe items in the bill are :\n";
            cout << "---------------------------\n";
            while (temp != NULL)
            {
                cout << "Barcode: " << temp->barcode << "\tName: " << temp->name << "\tQuantity: "
                     << temp->quantity << "\tPrice: " << temp->price << endl;
                temp = temp->next;
            }
            cout << endl << endl;

        }
    }
};






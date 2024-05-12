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
        if (IsEmpty())                        
        {
            newnodeptr->next = NULL;
            Header = newnodeptr;
        }
        else
        {
            newnodeptr->next = Header;
            Header = newnodeptr;
        }
        Counter++;
    }

    //Insert a new last node to the end of the Double Linked List (Function)
    void InsertLast(int Barcode, string Name, int Quantity, double Price)          
    {
        if (IsEmpty())     //Check if the the PharmacyClass is empty
        {
            InsertFirst(Barcode, Name, Quantity, Price);
        }
        else
        {
            node* newnodeptr = new node;
            node* lastptr;
            lastptr = Header;
            while (lastptr->next != NULL)
            {
                lastptr = lastptr->next;
            }
            newnodeptr->prev = lastptr;
            newnodeptr->barcode = Barcode;
            newnodeptr->name = Name;
            newnodeptr->quantity = Quantity;
            newnodeptr->price = Price;
            newnodeptr->next = NULL;
            lastptr->next = newnodeptr;
        }
        Counter++;
    }

    //Insert an item before another existed item
    void InsertBefore(int OldBarcode, int NewBarcode, string Name, int Quantity, double Price)
    {
        if (IsEmpty())
        {
            InsertFirst(NewBarcode, Name, Quantity, Price);
        }
        else
        {
            node* newnodeptr = new node;
            newnodeptr->barcode = NewBarcode;
            newnodeptr->name = Name;
            newnodeptr->quantity = Quantity;
            newnodeptr->price = Price;
            node* temp = Header;
            while (temp != NULL && temp->next->barcode != OldBarcode)
            {
                temp = temp->next;
            }
            newnodeptr->next = temp->next;
            temp->next = newnodeptr;
            newnodeptr->prev = temp;
            Counter++;
        }
    }
    
    //Delete a node of the Double Linked List (Function)
    void DeleteItem(int barcode)
    {
        if (IsExist(barcode == true))
        {
            if (Header->barcode == barcode)
            {
                node* deleteptr = Header;
                Header = Header->next;
                delete deleteptr;
                Header->prev = NULL;
            }
            else
            {
                node* deleteptr = Header;
                node* temp = NULL;
                while (deleteptr->barcode != barcode)
                {
                    temp = deleteptr;
                    deleteptr = deleteptr->next;
                }
                temp->next = deleteptr->next;
                deleteptr->prev = temp;
                delete deleteptr;
                Counter--;
            }

        }
        else
        {
            cout << "Item is not found\n\n"; 
        }
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
        int Validation = 0;
        int Loading = 0;
        cout << "Checking the pharmacy inventory\n";
        node* temp = Header;
        std::cout << "Please wait ";
        for (Loading = 0; Loading < 15; Loading++)
        {
            cout << ".";
            this_thread::sleep_for(std::chrono::milliseconds(250));
        }
        cout << endl;   
        while (temp != NULL)
        {
            if (temp->quantity <= 15)
            {
                Validation = 1;
                cout << "Low stock alert for " << temp->name << ".\n\n";
            }
            else
            {
                Validation = 0;
            }

            temp = temp->next;
        }
        if (Validation == 0)
        {
            cout << "There is no low stock for any items in the pharmacy.\n" << endl;
        }
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






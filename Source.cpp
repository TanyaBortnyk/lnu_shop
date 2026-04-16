#include <iostream>
#include <fstream>
#include "Order.h"
#include <windows.h>
using namespace std;

int main()
{
    Order order;
    int choice;

    do
    {
        cout << "\n=========================\n";
        cout << "      STORE SILPO\n";
        cout << "=========================\n";

        cout << "1 Add product\n";
        cout << "2 Remove product\n";
        cout << "3 Change quantity\n";
        cout << "4 Show order\n";
        cout << "5 Set date\n";
        cout << "6 Set status\n";
        cout << "7 Set payment\n";
        cout << "8 Apply promo code\n";
        cout << "9 Save file\n";
        cout << "0 Exit\n";

        cin >> choice;
        if (choice == 1)
        {
            int type;
            cout << "\n========================\n";
            cout << "ADD PRODUCT MENU\n";
            cout << "========================\n";
            cout << "1. Add from catalog\n";
            cout << "2. Add custom product\n";
            cout << "Choose: ";
            cin >> type;

            if (type == 1)
            {
                ifstream file("products.txt");

                int id;
                double price;
                string name, cat;

                cout << "\n--- AVAILABLE PRODUCTS ---\n";

                while (file >> id >> name >> price >> cat)
                {
                    cout << id << " " << name << " | "
                        << price << " grn | " << cat << endl;
                }

                file.close();

                int x, q;
                cout << "\nEnter product ID: ";
                cin >> x;

                cout << "Quantity: ";
                cin >> q;

                ifstream file2("products.txt");

                while (file2 >> id >> name >> price >> cat)
                {
                    if (id == x)
                    {
                        Product p(id, name, price, cat);
                        order.addProduct(p, q);
                        break;
                    }
                }

                file2.close();
            }
            else if (type == 2)
            {
                int id, q;
                string name, cat;
                double price;

                cout << "\nEnter custom product:\n";

                cout << "ID: ";
                cin >> id;

                cout << "Name: ";
                cin >> name;

                cout << "Price: ";
                cin >> price;

                cout << "Category: ";
                cin >> cat;

                cout << "Quantity: ";
                cin >> q;

                Product p(id, name, price, cat);
                order.addProduct(p, q);

                cout << "Custom product added!\n";
            }
        }

        if (choice == 2)
        {
            int id;
            cin >> id;
            order.removeProduct(id);
        }

        if (choice == 3)
        {
            int id, q;
            cin >> id >> q;
            order.changeQuantity(id, q);
        }

        if (choice == 4)
        {
            order.showOrder();
        }

        if (choice == 5)
        {
            string d;
            cin >> d;
            order.setDate(d);
        }

        if (choice == 6)
        {
            int x;
            cout << "0 Waiting\n1 Processing\n2 Delivered\n3 Cancelled\n";
            cin >> x;
            order.setStatus((Status)x);
        }

        if (choice == 7)
        {
            int x;
            cout << "0 Card\n1 Cash\n";
            cin >> x;
            order.setPayment((Payment)x);
        }

        if (choice == 8)
        {
            string code;
            cout << "Enter code: ";
            cin >> code;
            order.applyPromo(code);
        }

        if (choice == 9)
        {
            order.saveToFile("orders.json");
        }

    } while (choice != 0);
    
    cout << "Payment successful \n ";
    cout << "\a";
    return 0;
}
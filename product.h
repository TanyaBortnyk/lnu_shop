#pragma once
#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    int id;
    string name;
    double price;
    string category;

public:
    Product();
    Product(int id, string name, double price, string category);

    int getId() const;
    string getName() const;
    double getPrice() const;
    string getCategory() const;

    void show() const;
};
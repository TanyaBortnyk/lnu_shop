#include "product.h"

Product::Product()
{
    id = 0;
    name = "";
    price = 0;
    category = "";
}

Product::Product(int id, string name, double price, string category)
{
    this->id = id;
    this->name = name;
    this->price = price;
    this->category = category;
}

int Product::getId() const { return id; }
string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
string Product::getCategory() const { return category; }

void Product::show() const
{
    cout << id << ". "
        << name
        << " | "
        << price
        << " grn | "
        << category << endl;
}
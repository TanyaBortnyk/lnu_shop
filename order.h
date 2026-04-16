#pragma once
#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
#include "product.h"
using json = nlohmann::json;
using namespace std;

enum Status
{
    Waiting,
    Processing,
    Delivered,
    Cancelled
};

enum Payment
{
    Card,
    Cash
};

class Order
{
private:
    vector<Product> products;
    vector<int> quantity;

    string date;
    Status status;
    Payment payment;
    double discount;

public:
    Order();

    void addProduct(Product p, int q);
    void removeProduct(int id);
    void changeQuantity(int id, int q);

    void setDate(string d);
    void setStatus(Status s);
    void setPayment(Payment p);

    void applyPromo(string code);

    double getTotal() const;

    void showOrder() const;

    void saveToFile(string fileName);
    void loadFromFile(string fileName);
};
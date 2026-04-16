#include "order.h"
Order::Order()
{
    date = "No date";
    status = Waiting;
    payment = Cash;
    discount = 0;
}

void Order::addProduct(Product p, int q)
{
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].getId() == p.getId())
        {
            quantity[i] += q;
            return;
        }
    }

    products.push_back(p);
    quantity.push_back(q);
}

void Order::removeProduct(int id)
{
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].getId() == id)
        {
            products.erase(products.begin() + i);
            quantity.erase(quantity.begin() + i);
            return;
        }
    }
}

void Order::changeQuantity(int id, int q)
{
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].getId() == id)
        {
            quantity[i] = q;
            return;
        }
    }
}

void Order::setDate(string d)
{
    date = d;
}

void Order::setStatus(Status s)
{
    status = s;
}

void Order::setPayment(Payment p)
{
    payment = p;
}

void Order::applyPromo(string code)
{
    if (code == "SAVE10")
        discount = 0.10;
    else if (code == "SAVE20")
        discount = 0.20;
    else if (code == "PET5")
        discount = 0.05;
    else
        discount = 0;
}

double Order::getTotal() const
{
    double sum = 0;

    for (int i = 0; i < products.size(); i++)
        sum += products[i].getPrice() * quantity[i];

    sum = sum - sum * discount;

    return sum;
}

void Order::showOrder() const
{
    cout << "\n=========================\n";
    cout << "      STORE SILPO\n";
    cout << "=========================\n";

    cout << "Date: " << date << endl;

    cout << "Status: ";
    if (status == Waiting) cout << "Waiting\n";
    if (status == Processing) cout << "Processing\n";
    if (status == Delivered) cout << "Delivered\n";
    if (status == Cancelled) cout << "Cancelled\n";

    cout << "Payment: ";
    if (payment == Card) cout << "Card\n";
    else cout << "Cash\n";

    cout << "\nProducts:\n";

    for (int i = 0; i < products.size(); i++)
    {
        products[i].show();
        cout << "Quantity: " << quantity[i] << endl;
    }

    cout << "\nTotal: " << getTotal() << " grn\n";
}
void Order::saveToFile(string fileName)
{
    json j;

    j["date"] = date;
    j["discount"] = discount;
    j["total"] = getTotal();

    for (int i = 0; i < products.size(); i++)
    {
        json item;

        item["id"] = products[i].getId();
        item["name"] = products[i].getName();
        item["price"] = products[i].getPrice();
        item["category"] = products[i].getCategory();
        item["quantity"] = quantity[i];

        j["items"].push_back(item);
    }

    ofstream file(fileName);
    file << j.dump(4);
}
void Order::loadFromFile(string fileName)
{
    ifstream file(fileName);

    json j;
    file >> j;

    products.clear();
    quantity.clear();

    date = j["date"];
    discount = j["discount"];

    for (auto& item : j["items"])
    {
        Product p(
            item["id"],
            item["name"],
            item["price"],
            item["category"]
        );

        products.push_back(p);
        quantity.push_back(item["quantity"]);
    }
}
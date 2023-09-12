#pragma once
#ifndef UNTITLED_SALEITEM_H
#define UNTITLED_SALEITEM_H
#endif //UNTITLED_SALEITEM_H
#include <vector>



class SaleItem{
private:
    int code;
    double price;
public:
    SaleItem(int c, double p);
    int getCode();
    double getPrice();
    void setDiscountedPrice(double new_p);
};

class Sale{
private:
    std::vector<SaleItem> elems;
public:
    Sale();
    void addSale(SaleItem si);
    std::vector<SaleItem> getItems();
};

class Discount{
public:
    virtual double calc(Sale &s) = 0;
};

class ItemDiscount: public Discount{
private:
    int saleCode;
    int discountPercentage;
public:
    ItemDiscount(int code, int percentage);
    double calc(Sale &s);
};

class SumDiscount: public Discount{
private:
    std::vector<Discount*> discounts;
public:
    SumDiscount();
    void add(Discount &d);
    double calc(Sale &s);
};
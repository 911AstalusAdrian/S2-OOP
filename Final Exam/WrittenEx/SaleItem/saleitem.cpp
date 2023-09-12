#include "saleitem.h"

SaleItem::SaleItem(int c, double p): code(c), price(p) {}

int SaleItem::getCode() {
    return code;
}

double SaleItem::getPrice() {
    return price;
}

void SaleItem::setDiscountedPrice(double new_p) {
    this->price = new_p;
}

Sale::Sale() = default;

void Sale::addSale(SaleItem si) {
    this->elems.push_back(si);
}

std::vector<SaleItem> Sale::getItems() {
    return this->elems;
}


ItemDiscount::ItemDiscount(int code, int percentage): saleCode(code), discountPercentage(percentage) {}

double ItemDiscount::calc(Sale &s) {
    double totalDiscount = 0;
    for(auto item: s.getItems()){
        if(item.getCode() == saleCode){
            double itemPrice = item.getPrice();
            double discount = itemPrice * discountPercentage / 100;
            item.setDiscountedPrice(itemPrice-discount);
            totalDiscount += discount;
        }
    }
    return totalDiscount;
}

void SumDiscount::add(Discount &d) {
    discounts.push_back(&d);
}

double SumDiscount::calc(Sale &s) {
    double totalSaleDiscount = 0;
    for (auto d: discounts){
        double eachDiscount = d->calc(s);
        totalSaleDiscount += eachDiscount;
    }
    return totalSaleDiscount;
}

SumDiscount::SumDiscount() = default;
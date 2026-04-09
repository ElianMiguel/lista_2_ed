#include "Transaction.hpp"

Transaction::Transaction(int buy_order_ID, int sell_order_ID, float price) : buy_order_ID(buy_order_ID), sell_order_ID(sell_order_ID), price(price) {}

Transaction::~Transaction() {}

int Transaction::getBuyID() {
    return buy_order_ID;
}

int Transaction::getSellID() {
    return sell_order_ID;
}

float Transaction::getPrice() {
    return price;
}
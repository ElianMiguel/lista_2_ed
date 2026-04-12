#include <iostream>
#include "OrderBook.hpp"

NodeOrder::NodeOrder(Order order){
    this->order = order;
    this->next = nullptr;
}

NodeTransaction::NodeTransaction(Transaction transaction){
    this->transaction = transaction;
    this->next = nullptr;
}


// Funções da classe BuyList
BuyList::BuyList(){
    this->head = head;
    this->size = 0;
}

int BuyList::getSize() const{
    return this->size;
}

void BuyList::insertEnd(Order order){
    NodeOrder* newNode = new NodeOrder(order);

    if (head == nullptr) {
        head = newNode;
    } else {
        NodeOrder* temp = temp;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    size++;
}

void BuyList::remove(Order order){
    if (head == nullptr) return;

    if (head->order.getID() == order.getID()) {
        NodeOrder* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    NodeOrder* current = head;
    while (current->next != nullptr && current->next->order.getID() != order.getID()) {
        current = current->next;
    }

    if (current->next == nullptr) return;

    NodeOrder* temp = current->next;
    current->next = current->next->next;
    delete temp;
    size--;
}

bool BuyList::search(Order order) const{
    NodeOrder* current = head;

    while (current != nullptr) {
        if (current->order.getID() == order.getID()) return true;
        current = current->next;
    }

    return false;
}

void BuyList::printList(){
    NodeOrder* current = head;

    if (current == nullptr) {
        std::cout << "(empty)" << std::endl;
        return;
    }

    while (current != nullptr) {
        std::cout << "[" << current->order.getID() << "|" 
        << current->order.getPrice() << "|" << current->order.getTimestamp()
        << "]" << std::endl;

        current = current->next;
    }
}




// Funções da classe SellList
SellList::SellList(){
    this->head = head;
    this->size = 0;
}

int SellList::getSize() const{
    return this->size;
}

void SellList::insertEnd(Order order){
    NodeOrder* newNode = new NodeOrder(order);

    if (head == nullptr) {
        head = newNode;
    } else {
        NodeOrder* temp = temp;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    size++;
}

void SellList::remove(Order order){
    if (head == nullptr) return;

    if (head->order.getID() == order.getID()) {
        NodeOrder* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    NodeOrder* current = head;
    while (current->next != nullptr && current->next->order.getID() != order.getID()) {
        current = current->next;
    }

    if (current->next == nullptr) return;

    NodeOrder* temp = current->next;
    current->next = current->next->next;
    delete temp;
    size--;
}

bool SellList::search(Order order) const{
    NodeOrder* current = head;

    while (current != nullptr) {
        if (current->order.getID() == order.getID()) return true;
        current = current->next;
    }

    return false;
}

void SellList::printList(){
    NodeOrder* current = head;

    if (current == nullptr) {
        std::cout << "(empty)" << std::endl;
        return;
    }

    while (current != nullptr) {
        std::cout << "[" << current->order.getID() << "|" 
        << current->order.getPrice() << "|" << current->order.getTimestamp()
        << "]" << std::endl;

        current = current->next;
    }
}

// Funções da classe TransactionList
TransactionList::TransactionList(){
    this->head = head;
    this->size = size;
}

int TransactionList::getSize() const{
    return this->size;
}

void TransactionList::insertEnd(Transaction transaction){
    NodeTransaction* newNode = new NodeTransaction(transaction);

    if (head == nullptr) {
        head = newNode;
    } else {
        NodeTransaction* temp = temp;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    size++;
}

void TransactionList::remove(Transaction transaction){
    if (head == nullptr) return;

    if (head->transaction.getTransactionID() == transaction.getTransactionID()) {
        NodeTransaction* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    NodeTransaction* current = head;
    while (current->next != nullptr && current->next->transaction.getTransactionID() != transaction.getTransactionID()) {
        current = current->next;
    }

    if (current->next == nullptr) return;

    NodeTransaction* temp = current->next;
    current->next = current->next->next;
    delete temp;
    size--;
}

bool TransactionList::search(Transaction transaction) const{
    NodeTransaction* current = head;

    while (current != nullptr) {
        if (current->transaction.getTransactionID() == transaction.getTransactionID()) return true;
        current = current->next;
    }

    return false;
}

void TransactionList::printList(){
    NodeTransaction* current = head;

    if (current == nullptr) {
        std::cout << "(empty)" << std::endl;
        return;
    }

    while (current != nullptr) {
        std::cout << "[" << current->transaction.getBuyID() << "|" 
        << current->transaction.getSellID() << "|" << current->transaction.getPrice()
        << current->transaction.getTransactionID() << "]" << std::endl;

        current = current->next;
    }
}


// Funções da classe OrderBook
OrderBook::OrderBook(){
    this->buyList = new BuyList();
    this->sellList = new SellList();
    this->transactionList = new TransactionList();
}

OrderBook::~OrderBook(){
    if (this->buyList != nullptr) {
        delete this->buyList;
        this->buyList = nullptr;
    }

    if (this->sellList != nullptr) {
        delete this->sellList;
        this->sellList = nullptr;
    }

    if (this->transactionList != nullptr) {
        delete this->transactionList;
        this->transactionList = nullptr;
    }

}

bool submit(Order order){
    if (order.getType() == 'B') {

    }
    else if (order.getType() == 'S') {

    }
    return false;
}
bool cancel(int id){
    return false;
}

Order* getBuyOrders(int* n){
    return nullptr;
}
Order* getSellOrders(int* n){
    return nullptr;
}
Transaction* getTransactions(int* n){
    return nullptr;
}

void printBuyOrders(){}
void printSellOrders(){}
void printTransactions(){}
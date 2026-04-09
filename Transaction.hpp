class Transaction {
private:
    int buy_order_ID;
    int sell_order_ID;
    float price;

public:
    Transaction() {
        buy_order_ID = 0;
        sell_order_ID = 0;
        price = 0.0f;
    };
    Transaction(int buy_order_ID, int sell_order_ID, float price);
    ~Transaction();

    int getBuyID();
    int getSellID();
    float getPrice();
};
#include<iostream>      
#include<vector>       
#include<deque>        
#include<list>         
#include<set>          
#include<map>          
#include<string>       
#include<ctime>        
#include<unordered_map> 
#include<unordered_set> // Include heder file library

using namespace std;    // Use the standard namespace

// Struct to represent a product
struct Product {
    int productID;       // Product ID
    string name;         // Product name
    string categories;   // Product category
};

// Struct to represent an order
struct Order {
    int orderId;         // Order ID
    int productId;       // Product ID in the order
    int quantity;        // Quantity of the product ordered
    string customerID;   // Customer ID
    time_t orderDate;    // Order date and time
};

// Function to display products
void displayProducts(const vector<Product>& products) {
    cout << "Products:" << endl;
    for (const auto& product : products) {
        cout << "ID: " << product.productID << ", Name: " << product.name 
             << ", Category: " << product.categories << endl;
    }
}

// Function to display customers
void displayCustomers(const unordered_map<string, string>& customerData) {
    cout << "Customers:" << endl;
    for (const auto& customer : customerData) {
        cout << "ID: " << customer.first << ", Name: " << customer.second << endl;
    }
}

// Function to display orders
void displayOrders(const list<Order>& orderHistory) {
    cout << "Orders:" << endl;
    for (const auto& order : orderHistory) {
        cout << "Order ID: " << order.orderId << ", Product ID: " << order.productId 
             << ", Quantity: " << order.quantity << ", Customer ID: " << order.customerID 
             << ", Order Date: " << ctime(&order.orderDate);
    }
}

int main() {
    // Initialize a vector of products
    vector<Product> products = {
        {101, "Laptop", "Electronics"},
        {102, "SmartPhone", "Electronics"},
        {103, "Coffee Maker", "Kitchen"},
        {104, "Blender", "Kitchen"},
        {105, "Desk Lamp", "Home"}
    };

    // Initialize a deque of recent customers
    deque<string> recentCustomers = {"c001", "c002", "c003"};

    // Add new customers to the deque
    recentCustomers.push_back("c004");   // Add to the back
    recentCustomers.push_front("c005");  // Add to the front

    // Initialize a list of order history
    list<Order> orderHistory;

    time_t now = time(0);    // Get the current time

    // Add orders to the order history
    orderHistory.push_back({1, 101, 1, "c001", now});
    orderHistory.push_back({2, 102, 2, "c002", now});
    orderHistory.push_back({3, 103, 1, "c003", now});

    // Initialize a set of product categories
    set<string> categories;

    // Populate the set with categories from the products
    for (const auto& product : products) {
        categories.insert(product.categories);
    }

    // Initialize a map for product stock
    map<int, int> productStock = {
        {101, 10},
        {102, 30},
        {103, 33},
        {104, 4},
        {105, 40}
    };

    // Initialize a multimap for customer orders
    multimap<string, Order> customerOrder;

    // Populate the multimap with orders
    for (const auto& order: orderHistory) {
        customerOrder.insert({order.customerID, order});
    }

    // Initialize an unordered map for customer data
    unordered_map<string, string> customerData = {
        {"c001", "Bob"},
        {"c002", "Alice"},
        {"c003", "Riya"},
        {"c004", "Vidya"},
        {"c005", "Max"}
    };

    // Initialize an unordered set for unique product IDs
    unordered_set<int> uniqueProductID;

    // Populate the unordered set with product IDs
    for (const auto& product: products) {
        uniqueProductID.insert(product.productID);
    }

    // Display all products, customers, and orders
    displayProducts(products);
    displayCustomers(customerData);
    displayOrders(orderHistory);

    // Adding a new order
    int newOrderID = 4;
    int newProductID;
    int newQuantity;
    string newCustomerID;

    cout << "Enter new order details:" << endl;
    cout << "Product ID: ";
    cin >> newProductID;   // Get new product ID from user
    cout << "Quantity: ";
    cin >> newQuantity;    // Get new quantity from user
    cout << "Customer ID: ";
    cin >> newCustomerID;  // Get new customer ID from user

    // Add the new order to the order history
    orderHistory.push_back({newOrderID, newProductID, newQuantity, newCustomerID, time(0)});

    // Display updated orders
    displayOrders(orderHistory);

    return 0;
}

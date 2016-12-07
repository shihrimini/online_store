/********************************************************************
* Project 9.b
* Author: Joseph Shih
* Description: It's the implementation file of Customer class.
* A Customer object represents a customer with a name and account ID.  
* Customers must be members of the Store to make a purchase.  
* Premium members get free shipping.
********************************************************************/
#include "Customer.hpp"
using std::string;
using std::vector;

/************************************************
* Constructor: It takes three values
* to initialize the Customer's name, account ID, 
* and whether the customer is a premium member
************************************************/

Customer::Customer(string n, string a, bool pm){
	name = n;
	accountID = a;
	premiumMember = pm;
};

/************************************************
* get methods for data member
************************************************/
string Customer::getAccountID(){
	return accountID;
};

vector<string> Customer::getCart(){
	return cart;
};

bool Customer::isPremiumMember(){
	return premiumMember;
};


/************************************************
* adds the product ID code to the Customer's cart
************************************************/
void Customer::addProductToCart(string ProductIDToAdd){
	cart.push_back(ProductIDToAdd);
};

void Customer::emptyCart(){
	cart.clear();
};
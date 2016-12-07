/********************************************************************
* Project 9.b
* Author: Joseph Shih
* Description: It's the implementation file of Product class
* A Product object represents a product with an ID code, title, 
* description, price and quantity available.
********************************************************************/
#include "Product.hpp"
using std::string;

/************************************************
* Constructor: it takes as parameters five values 
* to initialize the Product's idCode, title, description, 
* price, and quantity available.
************************************************/
Product::Product(string id, string t, string d, double p, int qa){
	idCode = id;
    title = t;
    description = d;
    price = p;
    quantityAvailable = qa;
};


/************************************************
* get methods for each data member
************************************************/
string Product::getIdCode(){
	return idCode;
}

string Product::getTitle(){
	return title;
}

string Product::getDescription(){
	return description;
}

double Product::getPrice(){
	return price;
}

int Product::getQuantityAvailable(){
	return quantityAvailable;
}

void Product::decreaseQuantity(){
	quantityAvailable--;
}


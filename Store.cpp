/********************************************************************
* Project 9.b
* Author: Joseph Shih
* Description: It's the implementation file of Store class.
* A Store object represents a store, which has some number of products 
* in its inventory and some number of customers as members.
********************************************************************/
#include "Store.hpp"
#include <cstdlib> // NULL
#include <locale> // std::toupper, std::tolower
#include <iostream>

using std::string;
using std::toupper;
using std::tolower;
using std::locale;
using std::cout;
using std::endl;
using std::vector;

/************************************************
* adds a product to the inventory
************************************************/
void Store::addProduct(Product* p){
	inventory.push_back(p);
};


/************************************************
* adds a customer to the members
************************************************/
void Store::addMember(Customer* c){
	members.push_back(c);
};

/************************************************
* The func returns product with matching ID.  
* Returns NULL if no matching ID is found.
************************************************/
Product* Store::getProductFromID(string productID){
	for(unsigned i= 0; i<inventory.size(); i++){
		if(inventory[i]->getIdCode() == productID)
			return inventory[i];
	}
	return NULL;
};

/************************************************
* The func returns product with matching ID.  
* Returns NULL if no matching ID is found
************************************************/
Customer* Store::getMemberFromID(string memberID){
	for(unsigned i = 0; i< members.size(); i++){
		if(members[i]->getAccountID() == memberID)
			return members[i];
	}
	return NULL;
};

/************************************************
* The func prints out a product's title, ID code, 
* price and description, for its title or 
* description contains the search string.  
* The first letter of the search string is case-insensitive.
************************************************/
void Store::productSearch(std::string str){
	//make key case-insensitive
	locale loc;
	char firstChar;
	if(isupper(str[0])) firstChar = tolower(str[0], loc);
	else firstChar = toupper(str[0], loc);
	
	//an alternate keyword for searching
	//if str is "Wood", the alternate would be "wood"
	//if str is "wood", then alternate str would be "Wood"
	string alternateStr = firstChar + str.substr(1, str.length()-1); 

	bool found = false;
	vector<int> productMatched;
	
	//iterate through inventory to see if the product exists
	for(int i=0; i<inventory.size(); i++){
		if(inventory[i]->getTitle().find(str) != -1 ||
			inventory[i]->getTitle().find(alternateStr) != -1 ||
			inventory[i]->getDescription().find(str) != -1 ||
			inventory[i]->getDescription().find(alternateStr) != -1
			){
				found = true;
				productMatched.push_back(i);
			}
	}
	//print the info if found
	if(found){
		//iterate through the vector and print out relevant info
		for(int i = 0; i < productMatched.size(); i++){
			int index = productMatched[i];
			cout << inventory[index]->getTitle() << endl;
			cout << "ID code: " << inventory[index]->getIdCode() << endl;
			cout << "Price: " << inventory[index]->getPrice() << endl;
			cout << inventory[index]->getDescription() << endl;	
			cout << endl;
		}
	}
};


/************************************************
* If pIDand mID are found and the product is available, 
* the member's addProductToCart method is called.
*
* The same product can be added multiple times.
*
* It presents messages indicating when product is unavailable,
* customer not exist, or product out of stock.
************************************************/
void Store::addProductToMemberCart(string pID, string mID){
	Customer *theCustomer = this->getMemberFromID(mID);
	Product *theProduct = this->getProductFromID(pID);
	bool customerFound = false;
	bool productFound = false;

	if(!theProduct)cout << "Product #" << pID <<" not found." << endl;
	else customerFound = true;
	
	if(!theCustomer) cout << "Member #" << mID <<" not found." << endl;
	else productFound = true;

	// Only when customer and product both exist
	// then the function checks if product is still available
	// otherwise shows that the product is out of stock
	if (customerFound && productFound){
		if(theProduct->getQuantityAvailable() > 0) 
			theCustomer->addProductToCart(pID);
		else 
			cout << "Sorry, product #" << pID << " is currently out of stock." << endl;
	};
};


/************************************************
* It prints out the title and price for each product in the cart 
* and decreases the available quantity of that product by 1.
* Shipping cost: $0 for premium members, 
* 7% of the cart cost for normal members
************************************************/

void Store::checkOutMember(string mID){
	Customer *theCustomer = this->getMemberFromID(mID);
	
	//when the member isn't found
	if(!theCustomer) cout << "Member #" << mID << " not found." << endl;
	else
	{

			//if no item in the cart 
			if(theCustomer->getCart().empty()) cout << "There are no items in the cart." << endl;
			else{

					string pID, itemName;
					double itemCost, shipping, total, subtotal = 0.0;
					int itemQuantity = 0;

					//iterate through every item in the cart
					for(unsigned i = 0; i < theCustomer->getCart().size(); i++){
						
						//get each item's ID
						pID = (theCustomer->getCart())[i];
						Product *theProduct = this->getProductFromID(pID);

						//get item's name and quantity
						itemName = theProduct->getTitle();
						itemQuantity = theProduct->getQuantityAvailable();
						
						//to check wether the item is available
						//the item might be sold out between when it had been added to cart 
						//and when the customer checked out the item.
						if(itemQuantity < 1){
							cout << "Sorry, product #" << pID << ", \"" << itemName << "\" is no logner available." << endl;
						}else{
							//if it's still available
							//calculate the subtotal and deduct 1 from the quantity of the item
							itemCost = theProduct->getPrice();
							cout << itemName << " - $" << itemCost << endl;
							subtotal += itemCost;
							theProduct->decreaseQuantity();
						}

					}
					cout << "Subtotal: $" << subtotal << endl;

					//see if the customer is premium member,
					//if it is then free shipping is included.
					if(theCustomer->isPremiumMember()) shipping = 0;
					else shipping = subtotal * 0.07;


					cout << "Shipping Cost: $" << shipping << endl;
					total = subtotal + shipping;
					cout << "Total: $" << total << endl;

					//empty the customer's cart 
					theCustomer->emptyCart();
			}
	}
};



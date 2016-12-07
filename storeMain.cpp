/****************************************************************
* Author: Joseph Shih
* Description: this is the test file for store class
* Initialize a store with 1 premium customer and 1 regular customer.
* Premiun customer enjoys discount on shipping.
****************************************************************/
#include "Store.hpp"
#include <iostream>
using namespace std;

int main(){

	cout << "..........Store Class testing........." << endl;
	Store summerMarket;

	Product p1("A01", "Ronaldo", "Lengedary Striker", 99.99, 1);
	cout << "Ronaldo....initialized" << endl;
	Product p2("A02", "Isco", "Attacking Midfielder", 39.99, 1);
	cout << "Isco.......initialized" << endl;


	cout << "Customer Class testing..." << endl;
	Customer c1("Real Madrid", "C01", true);
	cout << "Real Madrid....initialized" << endl;
	Customer c2("Man Utd", "C02", false);
	cout << "Man Utd........initialized" << endl;

	Product* pPtr1 = &p1;
	Product* pPtr2 = &p2;
	Customer* cPtr1 = &c1;
	Customer* cPtr2 = &c2;

	summerMarket.addProduct(pPtr1);
	summerMarket.addProduct(pPtr2);
	summerMarket.addMember(cPtr1);
	summerMarket.addMember(cPtr2);

	cout << "adding RM and MU to store......." << endl;
	cout << "adding Isco and CR7 to store...." << endl;

	Product p3("A03", "Bale", "Worldclass Winger", 89.99, 1);
	cout << "Bale.......initialized" << endl;

	Product p4("A04", "Sergio Ramos", "Best Center Back", 59.99, 1);
	cout << "Ramos.......initialized" << endl;

	Product p5("A05", "Pogba", "Flop Midfielder", 109.99, 1);
	cout << "Pogba.......initialized" << endl;

	Product p6("A06", "Mata", "Experienced Midfielder", 29.99, 0);
	cout << "Mata..initialized..but out of stock." << endl;

	Product *pPtr3 = &p3;
	Product *pPtr4 = &p4;
	Product *pPtr5 = &p5;
	Product *pPtr6 = &p6;

	summerMarket.addProduct(pPtr3);
	summerMarket.addProduct(pPtr4);
	summerMarket.addProduct(pPtr5);
	summerMarket.addProduct(pPtr6);

	cout << endl;
	
	//Man U add Pogba to cart
	cout << "adding Pogba to Man Utd Cart......" << endl;
	summerMarket.addProductToMemberCart("A05", "C02");


	cout << "adding Mata to Man Utd Cart......" << endl;
	summerMarket.addProductToMemberCart("A06", "C02");

	cout << endl;

	summerMarket.addProductToMemberCart("A01", "C01");
	summerMarket.addProductToMemberCart("A02", "C01");
	summerMarket.addProductToMemberCart("A03", "C01");
	summerMarket.addProductToMemberCart("A04", "C01");
	
	cout << "productSearch method...." << endl;
	cout << "Search for midfielder..." << endl;
	cout << "should print out Isco, Pogba and Mata" << endl;
	summerMarket.productSearch("midfielder");

	cout << endl;
	cout << "Search for GK..........." << endl;
	summerMarket.productSearch("GK");

	cout << endl;

	cout << "addProductToMemberCart.." << endl;
	cout << "adding non-exist product" << endl;
	summerMarket.addProductToMemberCart("A04", "K01");

	cout << "adding non-exist client" << endl;
	summerMarket.addProductToMemberCart("G04", "C01");

	cout << "adding non-exist client and product" << endl;
	summerMarket.addProductToMemberCart("G04", "K01");
	cout << "...............................done" << endl;

	//R.Madrid add Pogba to cart
	summerMarket.addProductToMemberCart("A05", "C01");	
	

	//Man U check out first
	summerMarket.checkOutMember("C02");
	cout << endl;

	//Pogba is no longer available.
	summerMarket.checkOutMember("C01");


	//Check out with empty Cart.
	summerMarket.checkOutMember("C02");

	//Check out a customer who does not exist
	summerMarket.checkOutMember("C03");
	return 0;
}
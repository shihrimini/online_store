all: store

store: Product.o Customer.o Store.o storeMain.o
	g++ -g Product.o Customer.o Store.o storeMain.o -o store

storeMain.o: storeMain.cpp Store.hpp Customer.hpp Product.hpp
	g++ -c storeMain.cpp

Store.o: Store.cpp Store.hpp Customer.hpp Product.hpp
	g++ -c Store.cpp

Customer.o: Customer.cpp Customer.hpp Product.hpp
	g++ -c Customer.cpp

Product.o: Product.cpp Product.hpp
	g++ -c Product.cpp

clean:
	rm -f *.o
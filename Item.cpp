// header file includes
#include "Item.h"
#include <iostream>
using namespace std;
#include <new>
#include <cstring>
namespace oop244{
	bool Item::allocate(int size){
		
		deallocate();
		_name = new (nothrow) char[size];
		return _name != (char*)0;
	}
	void Item::deallocate(){

		if (_name){
			delete[] _name;
			_name = (char*)0;
		}
	}

	// constructors 
	Item::Item( const char* upc, const char* name, double price, int qtyNeeded, bool taxed){
		strncpy(_upc, upc, MAX_UPC_LEN);
		allocate(strlen(name) + 1);
		strcpy(_name, name);
		_quantity = 0;
		_qtyNeeded = qtyNeeded;
		_price = price;
		if (!taxed){
			_taxed = true;
		}
		else{
			_taxed = taxed;
		}
		

	}
	Item::Item(const Item& Item){
		_name = (char*)0;
		strncpy(_upc, Item._upc, MAX_UPC_LEN);
		if (Item._name && allocate(strlen(Item._name) + 1)){
			strcpy(_name, Item._name);
		}
		_quantity = Item._quantity;
		_qtyNeeded = Item._qtyNeeded;
		_price = Item._price;
		_taxed = Item._taxed;
		

	}

	// operator=
	Item& Item::operator=(const Item& Item){

		if (this != &Item){
			strncpy(_upc, Item._upc, MAX_UPC_LEN);
			allocate(strlen(Item._name) + 1);
			strcpy(_name, Item._name);
			_quantity = Item._quantity;
			_qtyNeeded = Item._qtyNeeded;
			_taxed = Item._taxed;
			_price = Item._price;
		}

		return *this;

	}
	
	// setters
	void Item::upc(char upc[]){
		strncpy(_upc, upc, MAX_UPC_LEN);
	}
	void Item::name(char* name){
		allocate(strlen(name) + 1);
		strcpy(_name, name);
	}
	void Item::price(double price){
		_price = price;
	}
	void Item::taxed(bool taxed){
		_taxed = taxed;
	}
	void Item::quantity(int quantity){
		_quantity = quantity;
	}
	void Item::qtyNeeded(int qtyNeeded){
		_qtyNeeded = qtyNeeded;
	}

	// getters

	const char* Item::upc()const{
		return _upc;
	}
	const char* Item::name()const{
		return _name;
	}
	double Item::price()const{
		return _price;
	}
	bool Item::taxed()const{
		return _taxed;
	}
	int Item::quantity()const{
		return _quantity;
	}
	int Item::qtyNeeded()const{
		return _qtyNeeded;
	}
	double Item::cost()const{
		if (_taxed == false){
			return _price;
		}
		
			return (_price + (_price * TAX));
		
	}

  // member operator overloads 
	bool Item::operator==(const char * upc)const{

		if (_upc == upc){
			return true;
		}
		return false;
	}
	int Item::operator+=(int quantity){
		return (_quantity + quantity);
	}

  // non-member operator overload
	double operator+=(double& d, const Item& I){
		return ((I.price() * I.quantity()) + d);
	}


  // destructor
	Item::~Item(){
		deallocate();
	}
}

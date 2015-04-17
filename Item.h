#ifndef __244_ITEM__
#define __244_ITEM__

// header file includes
#include "Streamable.h"
#include "general.h"

namespace oop244{

  class Item: public Streamable{
  private:
	  char _upc[MAX_UPC_LEN + 1];
	  char* _name;
	  double _price;
	  bool _taxed;
	  int _quantity;
	  int _qtyNeeded;

  public:
	  bool allocate(int size);
	  void deallocate();
	 // constructors
	  Item( const char*,const char*, double, int, bool=true);
	  Item(const Item& Item);
	  Item& operator=(const Item& item);

    // destructor
	  ~Item();

    // setters
	  void upc(char[]);
	  void name(char*);
	  void price(double);
	  void taxed(bool);
	  void quantity(int);
	  void qtyNeeded(int);

    // getters

	  const char* upc()const;
	  const char* name()const;
	  double price()const;
	  bool taxed()const;
	  int quantity()const;
	  int qtyNeeded()const;
	  double cost()const;

    // operators
	  bool operator==(const char *)const;
	  int operator+=(int);
	  

  };
  // Non-member operator overload prototype
  double operator+=(double& d, const Item& I);
}


#endif
#include "Streamable.h"
#include <fstream>
#include <iostream>
using namespace std;

namespace oop244{

	std::fstream& Streamable::store(std::fstream& f)const{

		return f;
	}
	std::fstream& Streamable::load(std::fstream& f){

		return f;
	}
	std::ostream& Streamable::display(std::ostream& os, bool linear)const{

		return os;
	}
	std::istream& Streamable::conInput(std::istream& is){

		return is;
	}
	// destructor:

	Streamable::~Streamable(){

	}

	// Non-member operator overload implementation for cin and cout:


	std::ostream& operator<<(std::ostream& ostr, const Streamable& S){
		return S.display(ostr, true);
	}
	std::istream& operator>>(std::istream& istr, Streamable& S){
		return S.conInput(istr);
	}


}
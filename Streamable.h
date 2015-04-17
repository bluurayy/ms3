#ifndef __244__Streamable__
#define __244__Streamable__
// hearfile includes:
#include <iostream>
#include <fstream>
namespace oop244{
	class Streamable{
	public:
		// pure virutal methods:

		virtual std::fstream& store(std::fstream& f)const;
		virtual std::fstream& load(std::fstream& f);
		virtual std::ostream& display(std::ostream& os, bool linear)const;
		virtual std::istream& conInput(std::istream& is);

		// virutal destructor:
		virtual ~Streamable();
	};

	// non-member operator overloads

	std::ostream& operator<<(std::ostream& ostr, const Streamable& S);
	std::istream& operator>>(std::istream& istr, Streamable& S);

}
#endif

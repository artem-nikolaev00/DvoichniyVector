#include "pch.h"
#ifndef _VEKTOR_
#define _VEKTOR_
#include <iostream>

namespace Prog3_1 {
	class Vector {
	private:
		int n = 0;
		char* ar = nullptr;
	public:
		Vector();
		Vector(int a);
		Vector(const char* string);
		Vector(const Vector&, int);
		Vector(const Vector&);
		Vector(Vector&& );
		~Vector();


		Vector operator ()(const Vector&);
		Vector operator |(const Vector&);
		Vector operator &(const Vector&);
		Vector operator ^(const Vector&);
		Vector operator ~();
		Vector &operator =(const Vector&);
		Vector &operator =(Vector &&);
		char* getar();
		char getel(int i) { return ar[i]; }
		int getlen() const { return n; }
		std::ostream & operator <<(std::ostream&) const;
	};
}
#endif

#include "pch.h"
#include "../DvoichniyVectorDynamic/DvoichniyVector.h"

namespace Prog3_1 {
	Vector::Vector()
	{
		n = 0;
		ar = nullptr;
	}

	Vector::Vector(int number)
	{
		int top = 0;
		if (number < 0)
			throw std::exception("impossible value!");
		else {
			char bit;
			n = 32;
			ar = new char[n];
			
			for (int i = 0; i < n; ++i) {
				bit = (char)(number & 1) + '0';
					ar[top++] = bit;
				number >>= 1;
			}
		}
	}

	Vector::Vector(const char * string)
	{
		int str_size = strlen(string);
		n = str_size;
		ar = new char[n];
		for (int i = 0; i < n; i++) {
			if (((char)(string[i]) != '0') && ((char)(string[i]) != '1'))
				throw std::exception("invaled value! Repeat pls");
		}
		for (int i = 0; i < n; i++) {
			ar[i] = string[i];
		}
	}


	Vector::Vector(const Vector& op, int newlen)
	{
		n = newlen;
		ar = new char[n];
		if (newlen == op.n) {
			for (int i = 0; i < op.n; i++) {
				ar[i] = op.ar[i];
			}
		}
		else
		{
			for (int i = 0; i < op.n; i++) {
				ar[i] = op.ar[i];
			}
			if (op.n < newlen) {
				int top = op.n;
				do {
					ar[top++] = '0';
				} while (top != newlen);
			}
		}
	}

	Vector::Vector(const Vector& st):  n(st.n)
	{
		ar = new char[n];
		for (int i = 0; i < n; ++i)
			ar[i] = st.ar[i];
	}

	Vector::Vector(Vector &&st) : n(st.n), ar(st.ar)
	{
		st.ar = nullptr;
	}


	Vector::~Vector()
	{
		if (ar) {
			delete ar;
		}
	}

	Vector  Vector::operator |(const Vector& op1)
	{
		if ((n == 0) || (op1.n == 0))
			throw std::exception("one of vectors is empty!");
		Vector v2;
		v2.n = n;
		v2.ar = new char[n];
		for (int i = 0; i < n; i++) {
			v2.ar[i] = ar[i] | op1.ar[i];
		}
		return v2;
	}

	Vector  Vector::operator &(const Vector& op1)
	{
		if ((n == 0) || (op1.n == 0))
			throw std::exception("one of vectors is empty!");
		Vector v2;
		v2.n = n;
		v2.ar = new char[n];
		for (int i = 0; i < n; i++) {
			v2.ar[i] = ar[i] & op1.ar[i];
		}
		return v2;
	}

	Vector  Vector::operator ^(const Vector& op1)
	{
		if ((n == 0) || (op1.n == 0))
			throw std::exception("one of vectors is empty!");
		Vector v2;
		v2.n = n;
		v2.ar = new char[n];
		for (int i = 0; i < n; i++) {
			v2.ar[i] = ((char)(ar[i] ^ op1.ar[i])) - 208;
		}
		return v2;
	}

	Vector Vector::operator ~()
	{
		Vector v1;
		v1.n = n;
		v1.ar = new char[n];
		for (int i = 0; i < n; i++) {
			v1.ar[i] = ~((char)(ar[i])) - 158;
		}
		return v1;
	}



	Vector Vector::operator()(const Vector& op1)
	{
		int i, topbegin, topend, j = 0;
		if (n == 0)
			throw std::exception("Stack is empty!");

		for (i = 0; i < n; i++)
		{
			if (ar[i] == '1')
			{
				topbegin = i;
				topend = i;
				break;
			}
		}

		for (i = i + 1; i < n; i++)
		{
			if (ar[i] == '1')
				topend = i;
		}

		Vector v1;
		v1.n = topend - topbegin + 1;
		v1.ar = new char[n];
		for (i = topbegin; i <= topend; i++) {
			v1.ar[j++] = ar[i];
		}


		return v1;
	}

	Vector & Vector::operator =(const Vector &st)
	{
		if (this != &st) {
			n = st.n;
			delete[] ar;
			ar = new char[n];
			for (int i = 0; i < n; ++i)
				ar[i] = st.ar[i];
		}
		return *this;
	}

	Vector & Vector::operator =(Vector &&st)
	{
		int tmp = n;
		n = st.n;
		st.n = tmp;
		char *ptr = ar;
		ar = st.ar;
		st.ar = ptr;
		return *this;
	}

	std::ostream & Vector::operator<<(std::ostream &s) const
	{
		if (n == 0)
			s << "Stack is empty";
		else
			for (int i = n - 1; i >= 0; --i)
				s << ar[i] << ' ';
		s << std::endl;
		return s;
	}

	char* Vector::getar() {
		char* arr = new char[n];
		for (int i = 0; i < n; i++) {
			arr[i] = ar[i];
		}
		return arr;
	}
}
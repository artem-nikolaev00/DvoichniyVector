#include "../DvoichniyVectorDynamic/DvoichniyVector.h"
#include "stdio.h"

char *getstr()
{
	char *ptr = (char *)malloc(1);
	char buf[81];
	int n, len = 0;
	*ptr = '\0';
	do {
		n = scanf("%80[^\n]", buf);
		//EOF
		if (n < 0) {
			free(ptr);
			ptr = NULL;
			continue;
		}
		//ERROR
		if (n == 0)
			scanf("%*c");
		else {
			len += strlen(buf);
			ptr = (char *)realloc(ptr, len + 1);
			strcat(ptr, buf);
		}
	} while (n > 0);
	return ptr;
}

using namespace Prog3_1;


int main()
{
	Vector st;
	try {
		st = Vector(213);
	}
	catch (const std::exception &msg)
	{
		std::cout << msg.what() << std::endl;
	}
	char* str;
	int fl;
	int k, q;
	int newn = 0;
	std::cout << "Current size = " << st.getlen() << "; In stack : \n";
	st << (std::cout);

	Vector newst;
	std::cout << "Enter the second vector" << std::endl;
	do {
		fl = 0;
		str = getstr();
		try {
			newst = Vector(str);
		}
		catch (const std::exception &msg)
		{
			std::cout << msg.what() << std::endl;
			fl = 1;
		}
	} while (fl != 0);
	std::cout << "First vector:" << std::endl;
	st << (std::cout);
	std::cout << "Second vector:" << std::endl;
	std::cout << "Current size = " << newst.getlen() << "; In stack : \n";
	newst << (std::cout);
	int n1 = st.getlen(), n2 = newst.getlen();
	int n = n1 > n2 ? n1 : n2;
	Vector v1(st, n), v2(newst, n);
	Vector resultst;
	int fl1 = 1;
	while (fl1) {
		std::cout << "Enter operation: 1.OR, 2.AND, 3.XOR, 4.addition, 5.withoutzero or press ctrl+Z to quit:" << std::endl;
		std::cin >> q;
		if (std::cin.good()) {
			if (q == 1) {
				try {
					std::cout << "Logical OR" << std::endl;
					resultst = v1 | v2;
					std::cout << "Current size = " << resultst.getlen() << "; In stack : \n";
					resultst << (std::cout);
				}
				catch (const std::exception &msg)
				{
					std::cout << msg.what() << std::endl;
				}

			}
			else if (q == 2) {
				try {
					std::cout << "Logical AND" << std::endl;
					resultst = v1 & v2;
					std::cout << "Current size = " << resultst.getlen() << "; In stack : \n";
					resultst << (std::cout);
				}
				catch (const std::exception &msg)
				{
					std::cout << msg.what() << std::endl;
				}

			}
			else if (q == 3) {
				try {
					std::cout << "Logical XOR" << std::endl;
					resultst = v1 ^ v2;
					std::cout << "Current size = " << resultst.getlen() << "; In stack : \n";
					resultst << (std::cout);
				}
				catch (const std::exception &msg)
				{
					std::cout << msg.what() << std::endl;
				}
			}
			else if (q == 4) {
				try {
					std::cout << "Logical ADDITION" << std::endl;
					resultst = ~st;
					std::cout << "Current size = " << resultst.getlen() << "; In stack : \n";
					resultst << (std::cout);
				}
				catch (const std::exception &msg)
				{
					std::cout << msg.what() << std::endl;
				}
			}
			else if (q == 5) {
				try {
					std::cout << "Vector without zero" << std::endl;
					resultst = st(st);
					std::cout << "Current size = " << resultst.getlen() << "; In stack : \n";
					resultst << (std::cout);
				}
				catch (const std::exception &msg)
				{
					std::cout << msg.what() << std::endl;
				}
			}
			else
				std::cout << "Repeat pls" << std::endl;
		}
		else
			fl1 = 0;

	}



	return 0;
}
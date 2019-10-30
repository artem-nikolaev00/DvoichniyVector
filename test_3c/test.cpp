#include "pch.h"
#include "..\DvoichniyVectorDynamic\DvoichniyVector.h"
#include "..\DvoichniyVectorDynamic\DvoichniyVectorDynamic.cpp"
#include "stdio.h"


TEST(DvoichniyVectorConstructor, Default) {
	Prog3_1::Vector v1;
	ASSERT_EQ(0, v1.getlen());
}

TEST(DvoichniyVectorConstructor, InitConstructors) {

	Prog3_1::Vector v2(50);
	ASSERT_EQ(32, v2.getlen());
	ASSERT_EQ('0', v2.getel(0));

	Prog3_1::Vector v3("1010101110");
	ASSERT_EQ(10, v3.getlen());
	ASSERT_EQ('0', v2.getel(0));

	Prog3_1::Vector v4(v3);
	ASSERT_EQ(10, v3.getlen());
	ASSERT_EQ('0', v2.getel(0));

}

TEST(DvoichniyVectorConstructor, exeptions) {
	ASSERT_ANY_THROW(Prog3_1::Vector("1120"));
	ASSERT_ANY_THROW(Prog3_1::Vector(-1));
}

TEST(DvoichniyVectorMethods, Parametrs1) {
	Prog3_1::Vector v1("01010"), v2("11111"), v3;
	v3 = v1 | v2;
	ASSERT_EQ(5, v3.getlen());
	char* str = v3.getar();
	EXPECT_TRUE(stricmp("11111", str));
}

TEST(DvoichniyVectorMethods, Parametrs2) {
	Prog3_1::Vector v1("01010"), v2("11111"), v3;
	v3 = v1 & v2;
	ASSERT_EQ(5, v3.getlen());
	char* str = v3.getar();
	EXPECT_TRUE(stricmp("01010", str));
}

TEST(DvoichniyVectorMethods, Parametrs3) {
	Prog3_1::Vector v1("01010"), v2("11111"), v3;
	v3 = v1 ^ v2;
	ASSERT_EQ(5, v3.getlen());
	char* str = v3.getar();
	EXPECT_TRUE(stricmp("10101", str));
}

TEST(DvoichniyVectorMethods, Parametrs4) {
	Prog3_1::Vector v1("01010"), v3;
	v3 = ~v1;
	ASSERT_EQ(5, v3.getlen());
	char* str = v3.getar();
	EXPECT_TRUE(stricmp("10101", str));
}

TEST(DvoichniyVectorMethods, Parametrs5) {
	Prog3_1::Vector v1("01010"), v3;
	v3 = v1(v1);
	ASSERT_EQ(3, v3.getlen());
	char* str = v3.getar();
	EXPECT_TRUE(stricmp("101", str));
}



int tmain() {
	return RUN_ALL_TESTS();
}
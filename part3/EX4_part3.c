
#include "EX4_part3.h"
#include <stdio.h>
int main()
{
	testMyClass1();
	testDerived();
	testDerived2();
	return 0;
}

void testMyClass1()
{
	int y=2;
	myClass myClass;
	myClass.function=add;
	myClass.m_x=5;
	printf("m_x= %d\n",myClass.m_x);
	fflush(stdout);
	myClass.function(&myClass,y);
	printf("y=%d\n",y);
	printf("after add m_x= %d\n\n\n",myClass.m_x);
	fflush(stdout);
}

void add(myClass* myClass,int y)
{
	myClass->m_x += y;
}

void add2(myClass* myClass,int y)
{
	myClass->m_x=myClass->m_x^y;
}

void testDerived()
{
	int y=1;
	Derived Derived;
	Derived.myClass.m_x=1;
	Derived.myClass.function=add2;
	printf("m_x= %d\n",Derived.myClass.m_x);
	fflush(stdout);
	printf("y=%d\n",y);
	Derived.myClass.function(&Derived.myClass,y);
	printf("after xor m_x= %d\n\n\n",Derived.myClass.m_x);
	fflush(stdout);
}

void add3(myClass* myClass,int y)
{
	Derived2* D2=(Derived2*)(myClass);
	add(&D2->myClass,y);
	D2->m_y=y;
	
}

void testDerived2()
{
	int y=3;
	Derived2 Derived2;
	Derived2.myClass.m_x=6;
	Derived2.myClass.function=add3;
	printf("m_x= %d\ny=%d\n",Derived2.myClass.m_x,y);
	fflush(stdout);
	Derived2.myClass.function((myClass*)&Derived2,y);
	printf("after add3 m_x= %d\nm_y=%d\n\n\n",Derived2.myClass.m_x,Derived2.m_y);
	fflush(stdout);
	
}

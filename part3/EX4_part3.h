#include <stdbool.h>
typedef struct myClass{int m_x; void(*function)(struct myClass* myClass,int m_y);} myClass;
typedef struct Derived{myClass myClass;} Derived;
typedef struct Derived2 {int m_y; myClass myClass;}Derived2;
void add(myClass* myClass,int m_y);
void testMyClass1();
void add2(myClass* myClass,int m_y);
void testDerived();
void add3(myClass* myClass,int m_y);
void testDerived2();

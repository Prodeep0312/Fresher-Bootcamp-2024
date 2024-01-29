#include <iostream>
#include <iomanip>
using namespace std;
int var = 0;
namespace Special { int var = 100; }
int main()
{
   int var = 10;
   cout << setw(10) << var; // local block scope
   {
   	int var = 20;
   	cout << setw(10) << var << endl; // local block scope
   	{
   		++var;
   		cout << setw(10) << var; // local block scope
   		cout << setw(10) << ++ ::var; // global scope
   		cout << setw(10) << Special::var * 2 // Special namespace scope
   			<< endl;
   	}
   	cout << setw(10) << var - ::var; // local block scope - global scope
   }
   cout << setw(10) << var << endl; // local block scope
   return 0;
}


/*
-------------------------------

OUTPUT:

10      20
      	21      1     200
	20      10	


-----------------------------------
	*/

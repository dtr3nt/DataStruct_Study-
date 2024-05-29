#include "utility.h"
#include "Stack.h"

int main()
/*
Pre:   The user supplies an integer n and n decimal numbers.
Post:  The numbers are printed in reverse order.
Uses:  The STL class stack and its methods
*/

{
   int n;
   Stack_entry item;
   Stack numbers;  //  declares and initializes a stack of numbers

   cout << " Type in an integer n followed by n decimal numbers." << endl
        << " The numbers will be printed in reverse order." << endl;
   cin  >> n;

   for (int i = 0; i < n; i++) {
      cin >> item;
      numbers.push(item);
   }

   cout << endl << endl;
   while (!numbers.empty()) {
      Stack_entry n;
      numbers.top(n);
      cout << n << " ";
      numbers.pop();
   }
   cout << endl;
}
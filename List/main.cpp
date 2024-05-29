#include "utility.h"
#include "Node.h"
#include "List.h"

int main() {    
   List<char> l;
   l.insert(0, 'c');
   l.insert(1, 'f');

   //uncomment below once double_insert is implemented 
   l.double_insert(1, 'd', 'e');
   l.double_insert(l.size(), 'g', 'h');
   l.double_insert(0, 'a', 'b');

   for (int i = 0; i < l.size(); i++) {
      char x;
      l.retrieve(i, x);
      cout << i << ": " << x << endl;
   }
}
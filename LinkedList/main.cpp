#include "utility.h"
#include "Node.h"
#include "List.h"
#include "Sortable_list.h"

int main(){
	clock_t start, finish;
   double elapsed_time;

   string input = "";
   bool exit_now = false;
   Sortable_list<int> sl, sl2;
   while(!exit_now){
      cout << endl;
      cout << "***********************" << endl;
      cout << "Menu:" << endl;
      cout << "1. Import List from File" << endl;
      cout << "2. Linked Selection Sort" << endl;
      cout << "p. Print the Original List" << endl;
      cout << "s. Print the Sorted List" << endl;
      cout << "x. Exit" << endl;
      cout << "***********************" << endl;

      getline(cin, input);

      if(input == "1"){
         cout << endl << "Enter List File Name:" << endl;
         getline(cin, input);
         ifstream insertion_file;
         insertion_file.open(input.c_str());
         if(!insertion_file.fail()){
            sl.clear();
            int cnt = 0;
            while(getline(insertion_file, input)){
               sl.insert(0, string_to_int(input));
               cnt++;
            }
            //sl.print();
            sl2 = sl;
         } else
            cout << "Invalid file name." << endl;
      }
      else if(input == "2"){
         sl2 = sl;
         start = clock();
         sl2.selection_sort();
         finish = clock();
         elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
         cout << "Time (in seconds): " << elapsed_time << endl;
      }
      else if(input == "p")
         sl.print();
      else if(input == "s")
         sl2.print();
      else if(input == "x")
         exit_now = true;
   }
}

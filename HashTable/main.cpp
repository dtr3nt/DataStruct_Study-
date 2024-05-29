#include "utility.h"
#include "List.h"
#include "Ordered_list.h"
#include "Linked_list.h"
#include "searches.h"
#include "Hash_table.h"

#define REPEAT_FACTOR 1000

int main(){
   clock_t start, finish;
   double elapsed_time;

   string input = "";
   bool exit_now = false;
   Ordered_list<string> ol;
   Hash_table ht1 = Hash_table(200003);
   Hash_table ht2 = Hash_table(50021);

   string search_key;
   int position = 0;

   string result = "";
   Error_code code;

   while(!exit_now){
      cout << endl;
      cout << "***********************" << endl;
      cout << "Menu:" << endl;
      cout << "1. Import List from File" << endl;
      cout << "2. Search for a key" << endl;
      cout << "x. Exit" << endl;
      cout << "***********************" << endl;

      getline(cin, input);

      if(input == "1"){
         cout << endl << "Enter List File Name:" << endl;
         getline(cin, input);
         ifstream insertion_file;
         insertion_file.open(input.c_str());
         if(!insertion_file.fail()){
            ol.clear();
            int cnt = 0;
            while(getline(insertion_file, input)){
               input = rtrim(input); 
               ol.insert(cnt, input);
               ht1.insert(input);
               ht2.insert(input);
               cnt++;
               if(cnt%10000==0) {
                  cout << cnt << " entries imported." <<endl;
               }
            }
         } else
            cout << "Invalid file name." << endl;
      }
      else if(input == "2"){
         cout << endl;
         cout << "Enter a string for search:" << endl;
         getline(cin, input);
         search_key = lpad(input, max_key_length, "0");
         start = clock();
         for(int i = 0; i < REPEAT_FACTOR; i++) code = sequential_search<string, string>(ol, search_key, position);
         finish = clock();
         elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
         cout << endl << "Sequential Search" << endl;
         if (code == success)
            cout << "    String " << search_key << " is found at Position " << position << "." << endl;
         else
            cout << "    String " << search_key << " is not found." << endl;
         cout << "    Time: " << elapsed_time << " seconds" << endl;

         start = clock();
         for(int i = 0; i < REPEAT_FACTOR; i++) code = binary_search(ol, search_key, position);
         finish = clock();
         elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
         cout << endl << "Binary Search" << endl;
         if (code == success)
            cout << "    String " << search_key << " is found at Position " << position << "." << endl;
         else
            cout << "    String " << search_key << " is not found." << endl;
         cout << "    Time: " << elapsed_time << " seconds" << endl;

         start = clock();
         for(int i = 0; i < REPEAT_FACTOR; i++) code = ht1.retrieve(search_key, result);
         finish = clock();
         elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
         cout << endl << "Hash Table 1 (Size = 200003) " << endl;
         if (code == success)
            cout << "    String " << search_key << " is found in the hash table." << endl;
         else
            cout << "    String " << search_key << " is not found." << endl;
         cout << "    Time: " << elapsed_time << " seconds" << endl;

         start = clock();
         for(int i = 0; i < REPEAT_FACTOR; i++) code = ht2.retrieve(search_key, result);
         finish = clock();
         elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
         cout << endl << "Hash Table 2 (Size = 50021) " << endl;
         if (code == success)
            cout << "    String " << search_key << " is found in the hash table." << endl;
         else
            cout << "    String " << search_key << " is not found." << endl;
         cout << "    Time: " << elapsed_time << " seconds" << endl;
      }
      else if(input == "x")
         exit_now = true;
   }
}
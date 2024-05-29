#include "utility.h"
#include "Binary_node.h"
#include "Binary_tree.h"
#include "Search_tree.h"


void print_entry(int &entry) {
    cout << entry << " ";
}

int main(){
   string input = "";
   bool exit_now = false;
   Search_tree<int> stree;
   while(!exit_now){
      cout << endl;
      cout << "***********************" << endl;
      cout << "Menu:" << endl;
      cout << "1. Insert from File" << endl;
      cout << "2. Print keys in preorder using recursive preorder traversal" << endl;
      cout << "3. Print keys in preorder using non-recursive preorder traversal" << endl;
      cout << "4. Print keys in inorder using recursive inorder traversal" << endl;
      cout << "5. Print keys in inorder using non-recursive inorder traversal" << endl;
      cout << "6. Print keys in inorder using recursive postorder traversal" << endl;
      cout << "7. Print keys in inorder using non-recursive postorder traversal" << endl;
      cout << "c. Clear tree" << endl;
      cout << "p. Print tree" << endl;
      cout << "h. Print tree height" << endl;
      cout << "s. Print tree size" << endl;
      cout << "l. Print number of leaves" << endl;
      cout << "x. Exit" << endl;
      cout << "***********************" << endl;

      getline(cin, input);

      if(input == "1"){
         cout << endl << "Enter Insertion File Name:" << endl;
         getline(cin, input);
         ifstream insertion_file;
         insertion_file.open(input.c_str());
         if(!insertion_file.fail()){
            while(getline(insertion_file, input)){
               int input_num = string_to_int(input);
               stree.insert(input_num);
            }
            stree.print();
         } else
            cout << "Invalid file name." << endl;
      }
      else if(input == "2"){
          cout << endl;
          stree.preorder(print_entry);
          cout << endl;
      }
      else if(input == "3"){
          cout << endl;
          stree.nonrecursive_preorder(print_entry);
          cout << endl;
      }
      else if(input == "4"){
          cout << endl;
          stree.inorder(print_entry);
          cout << endl;
      }
      else if(input == "5"){
          cout << endl;
          stree.nonrecursive_inorder(print_entry);
          cout << endl;
      }
      else if(input == "6"){
          cout << endl;
          stree.postorder(print_entry);
          cout << endl;
      }
      else if(input == "7"){
          cout << endl;
          stree.nonrecursive_postorder(print_entry);
          cout << endl;
      }
      else if (input == "c")
         stree.clear();
      else if (input == "p")
         stree.print();
      else if (input == "h")
         cout << endl << "The height of the binary tree is " << stree.height() << endl;
      else if (input == "s")
         cout << endl << "The size (node count) of the binary tree is " << stree.size() << endl;
      else if (input == "l") {
         cout << endl << "The number of leaves (leaf count) of the binary tree is " << stree.leaf_count() << endl;
      }
      else if(input == "x")
         exit_now = true;
   }
}
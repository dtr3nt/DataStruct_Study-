const int max_key_length = 6;

class Hash_table {
public:
   Hash_table(int h_size);
   void clear();
   Error_code insert(const string &new_entry);
   Error_code retrieve(const string &target, string &found) const;
   Error_code remove(const string &target, string &found);
private:
   int hash(const string &target) const;

   int hash_size; //  a prime number of appropriate size
   Linked_list<string> *table; // table is actaully a dynamic array of linked 
                               // lists.  Refer to the implementation of the 
                               // constructor for more details.
};
#include "utility.h"
#include "List.h"
#include "Ordered_list.h"
#include "Linked_list.h"
#include "searches.h"
#include "Hash_table.h"

Hash_table::Hash_table(int h_size)
{
   hash_size = h_size;
   table = new Linked_list<string>[h_size];
}
 
void Hash_table::clear()
{
   for (int i = 0; i < hash_size; i++)
      table[i].clear();
}
 
Error_code Hash_table::insert(const string &new_entry)
/* 
Post: If the Hash_table is full, a code of overflow is returned. If the 
table already contains a string that equals new_entry, a code of 
duplicate_error is returned.  Otherwise, the string new_entry is inserted
into the Hash_table and a code of success is returned.
*/
{
   // implement insert here
   int position;
   int probe = hash(new_entry);
   if (sequential_search(table[probe], new_entry, position) != success)
      return table[probe].insert(position, new_entry);
   return duplicate_error;
}
 
Error_code Hash_table::remove(const string &target, string &found)
/* 
Post: If the Hash_table is empty, a code of underflow is returned.
If the table contains no item with a key of target,
a code of not_found is returned.  Otherwise: The Record with
this key is deleted from the Hash_table
and success is returned.
*/
{
   int position;
   int probe = hash(target);
   if (sequential_search(table[probe], target, position) != success)
      return not_present;
   return table[probe].remove(position, found);
}
 
Error_code Hash_table::retrieve(const string &target, string &found) const
/* 
Post: If the table contains no string that equals target, a code of 
not_found is returned.  Otherwise, the found string is placed into 
found.  A code of success is then returned.
*/
{
   // implement retrieve here
   int position;
   int probe = hash(target);
   if (sequential_search(table[probe], target, position) != success)
      return not_present;
   return table[probe].retrieve(position, found);
}

int Hash_table::hash(const string &target) const
/* 
Post: target has been hashed, returning a value between 0 and hash_size -1.
Uses: Methods for the class Key.
*/
{
   int value = 0;
   for (int position = 0; position < max_key_length; position++)
      value = 10 * value + target[position];
   value %= hash_size;
   if (value < 0) value += hash_size;
   return value;
}


template <class Record>
class Sortable_list:public List<Record> {
public:
   void selection_sort();
protected: 
   //  Add prototypes for auxiliary functions here
   void min_node(Node<Record>* start_node, Node<Record>* start_node_prev, 
      Node<Record>* &min_node, Node<Record>* &min_node_prev);

   void swap(Node<Record>* start_node, Node<Record>* start_node_prev, 
      Node<Record>* min_node, Node<Record>* min_node_prev);
};


template <class Record>
void Sortable_list<Record>::selection_sort()
/*
Post: The entries of the Sortable_list have been rearranged so that
      the keys in all the entries are sorted into nondecreasing order.
*/
{
   // check to see if the list has at least two nodes. The list needs to be
   // sorted only if it has at least two nodes.
   if (this->head != NULL && this->head->next != NULL) { 
      // add a dummy node at the beginning of the list
      Node<Record> dummy(-1, this->head); // -1 to indicate it's a dummy
      Node<Record>* dummy_ptr = &dummy;

      // In each iteration of the while loop, find the node with the smallest
      // value in the sublist that starts from current, and then swap the smallest
      // node with current.
      Node<Record>* prev = dummy_ptr;
      Node<Record>* current = this->head; // note that prev->next == current
      while (current->next != NULL) {
         // find the node with the smallest value in the sublist that starts
         // from current
         Node<Record> *min_prev, *min;
         min_node(current, prev, min, min_prev);

         // swap current and min if they are not the same node
         if (current != min) {
            cout << "BEFORE SWAP" << endl;
            cout << "SP: " << prev->entry << " S: " << current->entry << " minP: " << min_prev->entry << " min: " << min->entry << endl;
            swap(current, prev, min, min_prev);
         }

         prev = prev->next;
         current = prev->next;
      }

      this->head = dummy_ptr->next; // reset the head just in case
   }
}

template <class Record>
void Sortable_list<Record>::min_node(Node<Record>* start_node, 
   Node<Record>* start_node_prev, Node<Record>* &min_node, 
   Node<Record>* &min_node_prev) 
/*
Pre:  start_node points to the first node of the sublist in which the
      method searches for the node with the smallest value.
      start_node_prev points to the node that immediately precedes 
      start_node.  In other words, start_node_prev->next == start_node.  
      min_node and min_node_prev are output parameters.
Post: min_node points to the node with the smallest value in the sublist 
      that starts from start_node.  
      min_node_prev points to the node that immediately precedes
      min_node.  In other words, min_node_prev->next == min_node. 
*/
{
   // temporarily set the first node of the sublist as the min_node
   min_node = start_node;
   min_node_prev = start_node_prev;
   // go through the rest of the sublist to find the minimum
   Node<Record>* prev_node = start_node;
   Node<Record>* cur_node = start_node->next;
   while (cur_node != NULL) {
       // Complete the body of the while loop here.  Add code below.
      if (cur_node->entry < min_node->entry)
      {
         min_node = cur_node;
         min_node_prev = prev_node;
      }
      prev_node = cur_node;
      cur_node = cur_node->next;
   }
   cout << "AFTER minFind" << endl;
   cout << "SP: " << start_node_prev->entry << " S: " << start_node->entry << " minP: " << min_node_prev->entry << " min: " << min_node->entry << endl << endl;
}

template <class Record>
void Sortable_list<Record>::swap(Node<Record>* start_node, 
   Node<Record>* start_node_prev, Node<Record>* min_node,
   Node<Record>* min_node_prev) 
/*
Post: The linked list is re-arranged such that start_node and min_node are
      swapped in the linked list. 
*/
{
   Node<Record>* tmp;
   Node<Record> test;
   // use the if statement here to distinguish the two cases
   if (start_node != min_node_prev) {
      // case 1: start_node and min_node_prev are not the same node.
      // Add code below.
      test = *start_node;
      tmp = start_node->next;
      start_node->next = min_node->next;
      min_node->next = tmp;
      tmp = start_node_prev->next;
      start_node_prev->next = min_node_prev->next;
      min_node_prev->next = tmp;
   }
   else {
      // case 2: start_node and min_node_prev are the same node.
      // Add code below.2
      tmp = start_node->next;
      start_node->next = min_node->next;
      min_node->next = start_node_prev->next;
      start_node_prev->next = tmp;
   }
}
// You need to write this entire file.
#include "sequence3.h"
#include <cstdlib>
#include <cassert>


data_structures_assignment3::sequence::sequence() {

    head_ptr= NULL;
    tail_ptr= NULL;
    cursor= NULL;
    pre_cursor= NULL;
    many_nodes = 0;



}

data_structures_assignment3::sequence::sequence(const data_structures_assignment3::sequence &source) {


    list_copy(source.head_ptr, head_ptr, tail_ptr);
    many_nodes = source.many_nodes;


    node *a = source.head_ptr;
    node *b = head_ptr;
    cursor = nullptr;
    pre_cursor = nullptr;
    while (a != nullptr) {
        if ( a == source.pre_cursor) {
            pre_cursor = b;
        }
        if (a == source.cursor){
            cursor = b;
        }
        a = a->link();
        b = b->link();
    }


}

data_structures_assignment3::sequence::~sequence() {

   list_clear(head_ptr);
   many_nodes = 0;



}

void data_structures_assignment3::sequence::start() {
    // start from the

    cursor = head_ptr;
    pre_cursor= NULL;



}

void data_structures_assignment3::sequence::advance() {

    assert(is_item());
    // if there is an current item the cursor becomes pre_cursor ,and next item of cursor becomes cursor

    pre_cursor=cursor;
    cursor= cursor->link();



}

void data_structures_assignment3::sequence::insert(const data_structures_assignment3::sequence::value_type &entry) {
 // if there is no current item the entry should be inserted at the front//

 if (!is_item()){
        // if there is no current items. we should insert the entry before the current item, after the pre-cursor
        if (many_nodes == 0)
        {
            list_head_insert(head_ptr, entry);
            tail_ptr = head_ptr;
            pre_cursor= NULL;
            cursor= head_ptr;
        }
            // otherwise, we're just inserting to the beginning

        else // if we have a sequence but no current item, we should insert item at the front
        {
            list_head_insert(head_ptr, entry);
            pre_cursor = NULL;
            cursor = head_ptr;
        }

    }

else{

    // if there is a current items. we should insert the entry before the current item, after the pre-cursor//

    if(cursor==head_ptr){
        // current item is at the head pointer
        list_head_insert(head_ptr,entry);
        cursor=head_ptr;
        pre_cursor=NULL;

           }

    else {

        list_insert(pre_cursor,entry);
        cursor=pre_cursor->link(); //pre_cursor remains same.only updating current by the previous positon of pre/-cursor//


         }

     }

++many_nodes; // updating the many_nodes/ count of nodes by one




}

void data_structures_assignment3::sequence::attach(const data_structures_assignment3::sequence::value_type &entry) {




if(is_item()){

        if(cursor == tail_ptr){

            list_insert(cursor, entry);
            pre_cursor=cursor;
            cursor= cursor->link();
            tail_ptr = cursor;

          }
        else   {

            list_insert(cursor, entry);
            pre_cursor=cursor;
            cursor= cursor->link();
    }

}
else
    {
          if(many_nodes==0){
             // when there is no current items and there is no element in linked list, first we have to create the node and then make a cursor;
                list_head_insert(head_ptr,entry);
                cursor=head_ptr;
                pre_cursor=NULL;
                tail_ptr = head_ptr;

                    }

         else {
           // when there is no current items but there is items in linked list. then we have to attach the entry at the end of the list

               list_insert(tail_ptr,entry);

               pre_cursor=tail_ptr;
               cursor=tail_ptr->link();
               tail_ptr = tail_ptr->link();

            }
    }



++many_nodes;

}

void data_structures_assignment3::sequence::remove_current() {

    assert(is_item());
    if (cursor == head_ptr) {
        cursor = head_ptr->link();
        if(head_ptr == tail_ptr){
            tail_ptr = nullptr;
        }
        list_head_remove(head_ptr) ;
    }
    else if(cursor == tail_ptr){
        // if the cursor is in tail_ptr
        list_remove(pre_cursor);
        tail_ptr = pre_cursor;
        cursor = NULL;
    }

    else {
        list_remove(pre_cursor);
        cursor = pre_cursor->link(); // pre_cursor remains same. cursor becomes the newly inserted node.
    }
    --many_nodes;

}

void data_structures_assignment3::sequence::operator=(const data_structures_assignment3::sequence &source) {



    if(this == &source) {
        return;
    }

         list_clear(head_ptr);


         list_copy(source.head_ptr, head_ptr, tail_ptr);
         many_nodes= source.many_nodes;

    node *a = source.head_ptr;
    node *b = head_ptr;
    cursor = nullptr;
    pre_cursor = nullptr;
    while (a != nullptr) {
        if ( a == source.pre_cursor) {
            pre_cursor = b;
        }
        if (a == source.cursor){
            cursor = b;
        }
        a = a->link();
        b = b->link();
    }







}



size_t data_structures_assignment3::sequence::size() const {

// size is how many items the linked list have

    return many_nodes;
}

bool data_structures_assignment3::sequence::is_item() const {

   return (cursor != NULL);



}

data_structures_assignment3::sequence::value_type data_structures_assignment3::sequence::current() const {

 assert(is_item());


return cursor->data();


}


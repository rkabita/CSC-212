#include "node.h"
#include <cassert>
#include <cstdlib>

using namespace std;

namespace data_structures_assignment_extra {
    size_t list_length(const node *head_ptr) {
        const node *cursor;
        size_t answer;

        answer = 0;
        for (cursor = head_ptr; cursor != nullptr; cursor = cursor->link())
            ++answer;

        return answer;
    }

    void list_head_insert(node *&head_ptr, const node::value_type &entry) {
        head_ptr = new node(entry, head_ptr);
    }

    void list_insert(node *previous_ptr, const node::value_type &entry) {
        node *insert_ptr;

        insert_ptr = new node(entry, previous_ptr->link());
        previous_ptr->set_link(insert_ptr);
    }

    node *list_search(node *head_ptr, const node::value_type &target) {
        node *cursor;

        for (cursor = head_ptr; cursor != nullptr; cursor = cursor->link())
            if (target == cursor->data())
                return cursor;
        return nullptr;
    }

    const node *list_search(const node *head_ptr, const node::value_type &target) {
        const node *cursor;

        for (cursor = head_ptr; cursor != nullptr; cursor = cursor->link())
            if (target == cursor->data())
                return cursor;
        return nullptr;
    }

    node *list_locate(node *head_ptr, size_t position) {
        node *cursor;
        size_t i;

        assert (0 < position);
        cursor = head_ptr;
        for (i = 1; (i < position) && (cursor != nullptr); i++)
            cursor = cursor->link();
        return cursor;
    }

    const node *list_locate(const node *head_ptr, size_t position) {
        const node *cursor;
        size_t i;

        assert (0 < position);
        cursor = head_ptr;
        for (i = 1; (i < position) && (cursor != nullptr); i++)
            cursor = cursor->link();
        return cursor;
    }

    void list_head_remove(node *&head_ptr) {
        node *remove_ptr;

        remove_ptr = head_ptr;
        head_ptr = head_ptr->link();
        delete remove_ptr;
    }

    void list_remove(node *previous_ptr) {
        node *remove_ptr;

        remove_ptr = previous_ptr->link();
        previous_ptr->set_link(remove_ptr->link());
        delete remove_ptr;
    }

    void list_clear(node *&head_ptr) {
        while (head_ptr != nullptr)
            list_head_remove(head_ptr);
    }

    void list_copy(const node *source_ptr, node *&head_ptr, node *&tail_ptr) {
        head_ptr = nullptr;
        tail_ptr = nullptr;

        if (source_ptr == nullptr)
            return;

        list_head_insert(head_ptr, source_ptr->data());
        tail_ptr = head_ptr;

        source_ptr = source_ptr->link();
        while (source_ptr != nullptr) {
            list_insert(tail_ptr, source_ptr->data());
            tail_ptr = tail_ptr->link();
            source_ptr = source_ptr->link();
        }
    }


    /* node* every_other(node*& head_ptr1, node*& head_ptr2){
           if(head_ptr1==nullptr){
               return;
           }
           // even numbered position are in  head_ptr1
           const node* cursor;
           cursor=head_ptr1->link();


           list_insert(head_ptr2, cursor->data());
           // odd numbered positions are in head_ptr2. so the first one is in head_ptr 2

           cursor=cursor->link();
           list_remove(head_ptr1);
           every_other(cursor, head_ptr2->link());


           delete cursor;



       }

   */



    void list_every_other(node *&head_ptr1, node *&head_ptr2) {
        // STUDENT WORK
        node *cursor;

        if (head_ptr1 == nullptr || head_ptr1->link()==nullptr) {
            return;
        }

        else {

            cursor =head_ptr1->link();

            if(head_ptr2 == nullptr) {

                list_head_insert(head_ptr2, cursor->data());

            }
             else {
                list_insert(head_ptr2, cursor->data());

             }

          if( head_ptr1->link() != nullptr){ list_remove(head_ptr1); }

            list_every_other(cursor->link(), head_ptr2->link());




        }




     /*   if (head_ptr1 == nullptr || head_ptr1->link()==nullptr) {
            return;
        }
        // even numbered position are in  head_ptr1

          cursor= head_ptr1->link();


             if( head_ptr2 == nullptr  ){

             list_head_insert(head_ptr2, cursor->data());

             }


         else if ( head_ptr2 != nullptr) {

            list_insert(head_ptr2, cursor->data());
            // odd numbered positions are in head_ptr2. so the first one is in head_ptr 2
        }


       if(head_ptr1->link() != nullptr) {
           list_remove(head_ptr1);
       }

            list_every_other(cursor->link(), head_ptr2->link());

      */


    }

}



#include "sequence2.h"
#include "assert.h"
#include <algorithm>
#include <iostream>
using std::copy;


namespace data_structures_assignment_3
{


    sequence::sequence(sequence::size_type initial_capacity) {
   data = new value_type[initial_capacity];
   capacity = initial_capacity;
   used = 0;
   current_item = 0;

    }

    sequence::sequence(const sequence &source) {

   data = new value_type[source.capacity];
   capacity= source.capacity;
   used = source.used;
   current_item = source.current_item;
   copy(source.data, source.data+used, data);

   /*
   for(int i= 0; i < used; i++){
       data[i]=source.data[i];

   }
    */





    }

    sequence::~sequence() {

      delete [] data;


    }

    void sequence::start() {

        current_item =0;


    }

    void sequence::advance() {

     assert(is_item());
      current_item++;



    }



    void sequence::insert(const sequence::value_type &entry) {
    if (used == capacity){
        resize (capacity+10);
    }
    if (!is_item() ){
        current_item = 0;

    }
    for( size_t i = used ; i> current_item ; i--){

        data[i]= data[i-1];
    }

     data[current_item] = entry;
     used+=1;



    }

    void sequence::attach(const sequence::value_type &entry) {

 if (used == capacity){
     resize(capacity+10);
 }

 if(!is_item()){
     current_item = used;
 }
 else {
    current_item++;
     for (size_t i = used; i > current_item; i--) {
         data[i] = data[i - 1];

     }
 }

        data[current_item]= entry;
     used++;

    }

    void sequence::remove_current() {
     assert(is_item());

     for( size_type i = current_item ; i < used; i++){
         data[i]= data[i+1];

     }
     used--;


    }

    void sequence::resize(sequence::size_type new_capacity) {

        if (new_capacity < capacity) {
            {
                if (used > new_capacity)
                    return;
            }

            value_type *new_data;
            capacity = new_capacity;
            new_data = new value_type[new_capacity];

            copy(data, data + used, new_data);
            delete[] data;
            data = new_data;
        }




    }

    void sequence::operator=(const sequence &source) {

        if (this == &source) {
            return;
        }

        else {
            value_type *new_data;

            if (capacity != source.capacity) {
                new_data = new value_type[source.capacity];
                delete[] data;
                data = new_data;
                capacity = source.capacity;
            }

            used = source.used;

            copy(source.data, source.data + used, data);

            current_item = source.current_item;
        }

    }


    sequence::size_type sequence::size() const {

        return used;

    }

    bool sequence::is_item() const {

       if (current_item< used)
        {
            return true;
        }
        else

            return false;



    }

    sequence::value_type sequence::current() const {

        assert(is_item());
        return data[current_item];

    }


}






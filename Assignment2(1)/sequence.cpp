// You must add all the code for this file.
#include <cstdlib>
#include<cassert>
#include <iostream>
#include "sequence.h"

namespace data_structures_assignment_1 {


    void sequence::start() {

        // if the sequence is empty, then there is no current item
        if (used > 0)
            current_index = 0;
        // it not then there is no current item
    }

    void sequence::advance() {

        //
        assert(is_item());
        current_index++;

    }

    void sequence::insert(const value_type &entry) {

// if the current item is null
        assert(size() < CAPACITY);

        if (!is_item()) {
            current_index = 0;
        }
        // now transfer the data to right by one.

        for (size_t i = used; i > current_index ; i--) {
            data[i] = data[i - 1];
        }

        data[current_index] = entry;
        used++;

    }

    void sequence::attach(const value_type &entry) {

        assert(size() < CAPACITY);

        if (!is_item()) {
            current_index = used;


        }

        else {
            current_index++;
            for (size_t i = used; i > current_index; i--) {

                data[i] = data[i - 1];
            }

        }
        data[current_index] = entry;
        used++;


    }

    void sequence::remove_current() {
        assert(is_item());

        for (size_t i = current_index; i < used; i++){

            data[i ] = data[i+1];
        }
      used--;
    }

    sequence::sequence() {
        used = 0;
    }

    sequence::size_type sequence::size() const {
        return used;
    }

    bool sequence::is_item() const {
        if (current_index < used) {
            return true;
        }


        else
            return false;
    }

    sequence::value_type sequence::current() const {
        assert(is_item());
        return data[current_index];

    }


}
#include <algorithm>
#include <cassert>
#include "bag.h"

using std::copy;

namespace data_structures_assignment_extra
{
    bag::size_type bag::erase(const value_type& target)
    {
        size_type index = 0;
        size_type many_removed = 0;

        while (index < used)
        {
            if (data[index] == target)
            {
                --used;
                data[index] = data[used];
                ++many_removed;
            }
            else
                ++index;
        }

        return many_removed;
    }

    bool bag::erase_one(const value_type& target)
    {
        size_type index;
        index = 0;
        while ((index < used) && (data[index] != target))
            ++index;

        if (index == used)
            return false;
        --used;
        data[index] = data[used];
        return true;
    }

    void bag::insert(const value_type& entry)
    {
        assert(size() < CAPACITY);
        data[used] = entry;
        ++used;
    }

    void bag::operator+=(const bag& addend)
    {
        assert(size() + addend.size() <= CAPACITY);

        copy(addend.data, addend.data + addend.used, data + used);
        used += addend.used;
    }

    bag::size_type bag::count(const value_type& target) const
    {
        size_type answer;
        size_type i;

        answer = 0;
        for (i = 0; i < used; ++i)
            if (target == data[i])
                ++answer;
        return answer;
    }

    bag operator+(const bag& b1, const bag& b2)
    {
        bag answer;

        assert(b1.size() + b2.size() <= bag::CAPACITY);

        answer += b1;
        answer += b2;
        return answer;
    }

    bag intersection(bag b1, bag b2)
    {
        // STUDENT WORK
        std::sort(b1.data, b1.data + b1.used);
        std::sort(b2.data, b2.data + b2.used);

        int size1 = b1.used, size2 = b2.used;

        //for(int i = 0;i < size1; i++)
        //{
        //    std::cout<<b1.data[i]<<" ";
        //}
        //std::cout<<std::endl;

        //        for(int i = 0;i < size2; i++)
        //{
        //    std::cout<<b2.data[i]<<" ";
        //}
        //std::cout<<std::endl;

        bag b3;
        int i = 0,j = 0;

        while(i<size1 && j< size2)
        {
            if(b1.data[i] == b2.data[j])
            {
                b3.insert(b1.data[i]);
                i++;
                j++;
            }
            else if(b1.data[i] < b2.data[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return b3;









        // return bag(); // This line is incorrect, but allows compiling. Delete it and write your own.
    }

    bag disjunctive_union(bag b1, bag b2)
    {
        std::sort(b1.data, b1.data + b1.used);
        std::sort(b2.data, b2.data + b2.used);

        int size1 = b1.used, size2 = b2.used;

        bag b3;
        int i = 0,j = 0;

        while(i<size1 || j< size2)
        {
            if(i < size1 && j < size2)
            {
                if(b1.data[i] == b2.data[j])
                {
                    i++;
                    j++;
                }
                else if(b1.data[i] < b2.data[j])
                {
                    b3.insert(b1.data[i]);
                    i++;
                }
                else
                {
                    b3.insert(b2.data[j]);
                    j++;
                }
            }
            else if(i < size1)
            {
                b3.insert(b1.data[i]);
                i++;
            }
            else if(j < size2)
            {
                b3.insert(b2.data[j]);
                j++;
            }
        }

        return b3;
    }









        // STUDENT WORK
      //  return bag(); // This line is incorrect, but allows compiling. Delete it and write your own.
}

// FILE: sequence_exam.cpp
//
// Each function of this program tests part of the sequence class, returning
// some number of points to indicate how much of the test was passed.
// A description and result of each test is printed to cout.
//
// Maximum number of points awarded by this program is determined by the
// constants POINTS[1], POINTS[2]... 

#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "sequence.h"  // With value_type defined as double

// Descriptions and points for each of the tests:
const size_t MANY_TESTS = 3;
const int POINTS[MANY_TESTS + 1] = {
        80, // Total points for all tests.
        40,  // Test 1 points
        20,  // Test 2 points
        20   // Test 3 points
};
const char DESCRIPTION[MANY_TESTS + 1][256] = {
        "Testing insert, attach, and the constant member functions",
        "Testing situations where the cursor goes off the sequence",
        "Testing remove_current"
};


// **************************************************************************
// bool test_basic(const sequence& test, sequence::size_type s, bool has_cursor)
//   Postcondition: A return value of true indicates:
//     a. test.size() is s, and
//     b. test.is_item() is has_cursor.
//   Otherwise the return value is false.
//   In either case, a description of the test result is printed to cout.
// **************************************************************************
bool test_basic(const data_structures_assignment_1::sequence &test, data_structures_assignment_1::sequence::size_type s,
                bool has_cursor)
{
    bool answer;

    std::cout << "Testing that size() returns " << s << " ... ";
    std::cout.flush();
    answer = (test.size() == s);
    std::cout << (answer ? "Passed." : "Failed.") << std::endl;

    if (answer)
    {
        std::cout << "Testing that is_item() returns ";
        std::cout << (has_cursor ? "true" : "false") << " ... ";
        std::cout.flush();
        answer = (test.is_item() == has_cursor);
        std::cout << (answer ? "Passed." : "Failed.") << std::endl;
    }

    return answer;
}


// **************************************************************************
// bool test_items(sequence& test, sequence::size_type s, sequence::size_type i, double items[])
//   The function determines if the test sequence has the correct items
//   Precondition: The size of the items array is at least s.
//   Postcondition: A return value of true indicates that test.current()
//   is equal to items[i], and after test.advance() the result of
//   test.current() is items[i+1], and so on through items[s-1].
//   At this point, one more advance takes the cursor off the sequence.
//   If any of this fails, the return value is false.
//   NOTE: The test sequence has been changed by advancing its cursor.
// **************************************************************************
bool test_items(data_structures_assignment_1::sequence &test, data_structures_assignment_1::sequence::size_type s,
                data_structures_assignment_1::sequence::size_type i, double items[])
{
    bool answer = true;

    std::cout << "The cursor should be at item [" << i << "]" << " of the sequence\n";
    std::cout << "(counting the first item as [0]). I will advance the cursor\n";
    std::cout << "to the end of the sequence, checking that each item is correct...";
    std::cout.flush();
    while ((i < s) && test.is_item() && (test.current() == items[i]))
    {
        i++;
        test.advance();
    }

    if ((i != s) && !test.is_item())
    {   // The test.is_item( ) function returns false too soon.
        std::cout << "\n    Cursor fell off the sequence too soon." << std::endl;
        answer = false;
    }
    else if (i != s)
    {   // The test.current( ) function returned a wrong value.
        std::cout << "\n    The item [" << i << "] should be " << items[i] << ",\n";
        std::cout << "    but it was " << test.current() << " instead.\n";
        answer = false;
    }
    else if (test.is_item())
    {   // The test.is_item( ) function returns true after moving off the sequence.
        std::cout << "\n    The cursor was moved off the sequence,";
        std::cout << " but is_item still returns true." << std::endl;
        answer = false;
    }

    std::cout << (answer ? "Passed." : "Failed.") << std::endl;
    return answer;
}


// **************************************************************************
// bool correct(sequence test, sequence::size_type s, sequence::size_type cursor_spot, double items[])
//   This function determines if the sequence (test) is "correct" according to
//   these requirements:
//   a. it has exactly s items.
//   b. the items (starting at the front) are equal to
//      double[0] ... double[size-1]
//   c. if cursor_spot < size, then test's cursor must be at
//      the location given by cursor_spot.
//   d. if cursor_spot >= size, then test must not have a cursor.
// NOTE: The function also moves the cursor off the sequence.
// **************************************************************************
bool correct(data_structures_assignment_1::sequence &test, data_structures_assignment_1::sequence::size_type size,
             data_structures_assignment_1::sequence::size_type cursor_spot, double items[])
{
    bool has_cursor = (cursor_spot < size);

    // Check the sequence's size and whether it has a cursor.
    if (!test_basic(test, size, has_cursor))
    {
        std::cout << "Basic test of size() or is_item() failed." << std::endl << std::endl;
        return false;
    }

    // If there is a cursor, check the items from cursor to end of the sequence.
    if (has_cursor && !test_items(test, size, cursor_spot, items))
    {
        std::cout << "Test of the sequence's items failed." << std::endl << std::endl;
        return false;
    }

    // Restart the cursor at the front of the sequence and test items again.
    std::cout << "I'll call start() and look at the items one more time..." << std::endl;
    test.start();
    if (has_cursor && !test_items(test, size, 0, items))
    {
        std::cout << "Test of the sequence's items failed." << std::endl << std::endl;
        return false;
    }

    // If the code reaches here, then all tests have been passed.
    std::cout << "All tests passed for this sequence." << std::endl << std::endl;
    return true;
}


// **************************************************************************
// int test1( )
//   Performs some basic tests of insert, attach, and the constant member
//   functions. Returns POINTS[1] if the tests are passed. Otherwise returns 0.
// **************************************************************************
int test1()
{
    data_structures_assignment_1::sequence empty;  // An empty sequence
    data_structures_assignment_1::sequence test1;  // A sequence to add items to
    double items1[4] = {5, 10, 20, 30};  // These 4 items are put in a sequence
    double items2[4] = {10, 15, 20, 30}; // These are put in another sequence

    // Test that the empty sequence is really empty
    std::cout << "Starting with an empty sequence." << std::endl;
    if (!correct(empty, 0, 0, items1)) return 0;

    // Test the attach function to add something to an empty sequence
    std::cout << "I am now using attach to put 10 into an empty sequence." << std::endl;
    test1.attach(10);
    if (!correct(test1, 1, 0, items2)) return 0;

    // Test the insert function to add something to an empty sequence
    std::cout << "I am now using insert to put 10 into an empty sequence." << std::endl;
    test1 = empty;
    test1.insert(10);
    if (!correct(test1, 1, 0, items2)) return 0;

    // Test the insert function to add an item at the front of a sequence
    std::cout << "I am now using attach to put 10,20,30 in an empty sequence.\n";
    std::cout << "Then I move the cursor to the start and insert 5." << std::endl;
    test1 = empty;
    test1.attach(10);
    test1.attach(20);
    test1.attach(30);
    test1.start();
    test1.insert(5);
    if (!correct(test1, 4, 0, items1)) return 0;

    // Test the insert function to add an item in the middle of a sequence
    std::cout << "I am now using attach to put 10,20,30 in an empty sequence.\n";
    std::cout << "Then I move the cursor to the start, advance once, ";
    std::cout << "and insert 15." << std::endl;
    test1 = empty;
    test1.attach(10);
    test1.attach(20);
    test1.attach(30);
    test1.start();
    test1.advance();
    test1.insert(15);
    if (!correct(test1, 4, 1, items2)) return 0;

    // Test the attach function to add an item in the middle of a sequence
    std::cout << "I am now using attach to put 10,20,30 in an empty sequence.\n";
    std::cout << "Then I move the cursor to the start and attach 15 ";
    std::cout << "after the 10." << std::endl;
    test1 = empty;
    test1.attach(10);
    test1.attach(20);
    test1.attach(30);
    test1.start();
    test1.attach(15);
    if (!correct(test1, 4, 1, items2)) return 0;

    // All tests have been passed
    std::cout << "All tests of this first function have been passed." << std::endl;
    return POINTS[1];
}


// **************************************************************************
// int test2( )
//   Performs a test to ensure that the cursor can correctly be run off the end
//   of the sequence. Also tests that attach/insert work correctly when there is
//   no cursor. Returns POINTS[2] if the tests are passed. Otherwise returns 0.
// **************************************************************************
int test2()
{
    data_structures_assignment_1::sequence test;
    data_structures_assignment_1::sequence::size_type i;

    // Put three items in the sequence
    std::cout << "Using attach to put 20 and 30 in the sequence, and then calling\n";
    std::cout << "advance, so that is_item should return false ... ";
    std::cout.flush();
    test.attach(20);
    test.attach(30);
    test.advance();
    if (test.is_item())
    {
        std::cout << "failed." << std::endl;
        return 0;
    }
    std::cout << "passed." << std::endl;

    // Insert 10 at the front and run the cursor off the end again
    std::cout << "Inserting 10, which should go at the sequence's front." << std::endl;
    std::cout << "Then calling advance three times to run cursor off the sequence ...";
    std::cout.flush();
    test.insert(10);
    test.advance(); // advance to the 20
    test.advance(); // advance to the 30
    test.advance(); // advance right off the sequence
    if (test.is_item())
    {
        std::cout << " failed." << std::endl;
        return false;
    }
    std::cout << " passed." << std::endl;

    // Attach more items until the sequence becomes full.
    // Note that the first attach should attach to the end of the sequence.
    std::cout << "Calling attach to put the numbers 40, 50, 60 ...";
    std::cout << data_structures_assignment_1::sequence::CAPACITY * 10 << " at the sequence's end." << std::endl;
    for (i = 4; i <= data_structures_assignment_1::sequence::CAPACITY; i++)
        test.attach(i * 10);

    // Test that the sequence is correctly filled.
    std::cout << "Now I will test that the sequence has 10, 20, 30, ...";
    std::cout << data_structures_assignment_1::sequence::CAPACITY * 10 << "." << std::endl;
    test.start();
    for (i = 1; i <= data_structures_assignment_1::sequence::CAPACITY; i++)
    {
        if ((!test.is_item()) || test.current() != i * 10)
        {
            std::cout << "    Test failed to find " << i * 10 << std::endl;
            return 0;
        }
        test.advance();
    }
    if (test.is_item())
    {
        std::cout << "    There are too many items on the sequence." << std::endl;
        return false;
    }

    // All tests passed
    std::cout << "All tests of this second function have been passed." << std::endl;
    return POINTS[2];
}


// **************************************************************************
// int test3( )
//   Performs basic tests for the remove_current function.
//   Returns POINTS[3] if the tests are passed. Returns POINTS[3] / 4 if almost
//   all the tests are passed. Otherwise returns 0.
// **************************************************************************
int test3()
{
    // In the next declarations, I am declaring a sequence called test.
    // Both before and after the sequence, I declare a small array of characters,
    // and I put the character 'x' into each spot of these arrays.
    // Later, if I notice that one of the x's has been changed, or if
    // I notice an 'x' inside of the sequence, then the most
    // likely reason was that one of the sequence's member functions accessed
    // the sequence's array outside of its legal indexes.
    char prefix[4] = {'x', 'x', 'x', 'x'};
    data_structures_assignment_1::sequence test;
    char suffix[4] = {'x', 'x', 'x', 'x'};

    // Within this function, I create several different sequences using the
    // items in these arrays:
    double items1[1] = {30};
    double items2[2] = {10, 30};
    double items3[3] = {10, 20, 30};

    data_structures_assignment_1::sequence::size_type i;       // for-loop control variable
    char *char_ptr; // Variable to loop at each character in a sequence's memory

    // Build a sequence with three items 10, 20, 30, and remove the middle,
    // and last and then first.
    std::cout << "Using attach to build a sequence with 10,30." << std::endl;
    test.attach(10);
    test.attach(30);
    std::cout << "Insert a 20 before the 30, so entire sequence is 10,20,30." << std::endl;
    test.insert(20);
    if (!correct(test, 3, 1, items3)) return 0;
    std::cout << "Remove the 20, so entire sequence is now 10,30." << std::endl;
    test.start();
    test.advance();
    test.remove_current();
    if (!correct(test, 2, 1, items2)) return 0;
    std::cout << "Remove the 30, so entire sequence is now just 10 with no cursor.";
    std::cout << std::endl;
    test.start();
    test.advance();
    test.remove_current();
    if (!correct(test, 1, 1, items2)) return 0;
    std::cout << "Set the cursor to the start and remove the 10." << std::endl;
    test.start();
    test.remove_current();
    if (!correct(test, 0, 0, items2)) return 0;

    // Build a sequence with three items 10, 20, 30, and remove the middle,
    // and then first and then last.
    std::cout << "Using attach to build another sequence with 10,30." << std::endl;
    test.attach(10);
    test.attach(30);
    std::cout << "Insert a 20 before the 30, so entire sequence is 10,20,30." << std::endl;
    test.insert(20);
    if (!correct(test, 3, 1, items3)) return 0;
    std::cout << "Remove the 20, so entire sequence is now 10,30." << std::endl;
    test.start();
    test.advance();
    test.remove_current();
    if (!correct(test, 2, 1, items2)) return 0;
    std::cout << "Set the cursor to the start and remove the 10," << std::endl;
    std::cout << "so the sequence should now contain just 30." << std::endl;
    test.start();
    test.remove_current();
    if (!correct(test, 1, 0, items1)) return 0;
    std::cout << "Remove the 30 from the sequence, resulting in an empty sequence." << std::endl;
    test.start();
    test.remove_current();
    if (!correct(test, 0, 0, items1)) return 0;

    // Build a sequence with three items 10, 20, 30, and remove the first.
    std::cout << "Build a new sequence by inserting 30, 10, 20 (so the sequence\n";
    std::cout << "is 20, then 10, then 30). Then remove the 20." << std::endl;
    test.insert(30);
    test.insert(10);
    test.insert(20);
    test.remove_current();
    if (!correct(test, 2, 0, items2)) return 0;
    test.start();
    test.remove_current();
    test.remove_current();

    // Just for fun, fill up the sequence, and empty it!
    std::cout << "Just for fun, I'll empty the sequence then fill it up, then\n";
    std::cout << "empty it again. During this process, I'll try to determine\n";
    std::cout << "whether any of the sequence's member functions access the\n";
    std::cout << "array outside of its legal indexes." << std::endl;
    for (i = 0; i < data_structures_assignment_1::sequence::CAPACITY; i++)
        test.insert(0);
    for (i = 0; i < data_structures_assignment_1::sequence::CAPACITY; i++)
        test.remove_current();

    // Make sure that the character 'x' didn't somehow get into the sequence,
    // as that would indicate that the sequence member functions are
    // copying data from before or after the sequence into the sequence.
    char_ptr = (char *) &test;
    for (i = 0; i < sizeof(data_structures_assignment_1::sequence); i++)
        if (char_ptr[i] == 'x')
        {
            std::cout << "Illegal array access detected." << std::endl;
            return POINTS[3] / 4;
        }

    // Make sure that the prefix and suffix arrays still have four
    // x's each. Otherwise one of the sequence operations wrote outside of
    // the legal boundaries of its array.
    for (i = 0; i < 4; i++)
        if ((suffix[i] != 'x') || (prefix[i] != 'x'))
        {
            std::cout << "Illegal array access detected." << std::endl;
            return POINTS[3] / 4;
        }

    // All tests passed
    std::cout << "All tests of this third function have been passed." << std::endl;
    return POINTS[3];
}


int run_a_test(int number, const char message[], int test_function(), int max)
{
    int result;

    std::cout << std::endl << "START OF TEST " << number << ":" << std::endl;
    std::cout << message << " (" << max << " points)." << std::endl;
    result = test_function();
    if (result > 0)
    {
        std::cout << "Test " << number << " got " << result << " points";
        std::cout << " out of a possible " << max << "." << std::endl;
    }
    else
        std::cout << "Test " << number << " failed." << std::endl;
    std::cout << "END OF TEST " << number << "." << std::endl << std::endl;

    return result;
}


// **************************************************************************
// int main( )
//   The main program calls all tests and prints the sum of all points
//   earned from the tests.
// **************************************************************************
int main()
{
    int sum = 0;


    std::cout << "Running " << DESCRIPTION[0] << std::endl;

    sum += run_a_test(1, DESCRIPTION[1], test1, POINTS[1]);
    sum += run_a_test(2, DESCRIPTION[2], test2, POINTS[2]);
    sum += run_a_test(3, DESCRIPTION[3], test3, POINTS[3]);

    std::cout << sum << " points out of the " << POINTS[0];
    std::cout << " points from this test program.\n";

    return EXIT_SUCCESS;

}

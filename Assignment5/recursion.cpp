#include <iostream>
#include "maze.h"

using std::ostream;
using namespace std;
using data_structures_assignment_5::maze;
using data_structures_assignment_5::maze_node;

void triangle(ostream& outs, unsigned int m, unsigned int n){
// Precondition: m <= n
// Postcondition: The function has printed a pattern of 2*(n-m+1) lines
// to the output stream outs. The first line contains m asterisks, the next
// line contains m+1 asterisks, and so on up to a line with n asterisks.
// Then the pattern is repeated backwards, going n back down to m.
/* Example output:
   triangle(cout, 3, 5) will print this to cout:
   ***
   ****
   *****
   *****
   ****
   ***
*/

    if(m>n)return; // base case. to stop the recursion.

    string p=""; // created a string to save time.

        for(int i=0;i< m;i++) {

          p+= "*";
        }

            cout<<p<<endl;

        triangle(cout,m+1,n); // call the function in the middle printing two lines

        cout<<p<<endl; // if I don't do this print out it just print every line only once. so it don't go backwords again.




}

int count_ways_to_step(int number_of_stepping_stones) {
// Precondition: number_of_stepping_stones > 0
// Postcondition: The number of ways to reach the final stepping stone using
// either a small step (moving 1 stepping stone) or a large step (moving 2 stepping
// stones) in any combination is returned.
// For 3 stepping stones there are 3 ways. For 4 stepping stones, there are 5 ways.

int k = number_of_stepping_stones;

if(k==1 || k==0){

    return 1;
}
else if(k==2)
    {
  return 2;
    }
    else {

int p1 = count_ways_to_step(k-2);
int p2 = count_ways_to_step(k-1);

  return p1+p2;
}

}



bool print_path_through_maze(const maze_node* maze_position)
// Postcondition: Prints the path through the maze, with 0s representing right
// turns and 1s representing left turns.
// You may print the path in reverse order (this will be easier).
// Hint: Use the return boolean to signify that the current path is the correct path.
{
    if(maze_position == nullptr){
        // if the pointer is NULL then return false. that means not the end point and no more nodes after that
        return false;
    }
    if(maze_position->is_finish()){
        // if the position is finish point then return true
        return true;

    }

   bool a = print_path_through_maze(maze_position->left());
// returns true if it finds a true and then point

   bool b = print_path_through_maze(maze_position->right());
//

    if(b) {
        cout << "0" << endl;
        return true;
    }

    if(a) {
        cout << "1" << endl;
        return true;
    }
    return false;


}

int main()
{
    // You can test your code by adding it here.
cout<<count_ways_to_step(3)<<endl;
    triangle(cout, 3, 5);
maze m1(0);
 print_path_through_maze(m1.get_start());


    return 0;
}
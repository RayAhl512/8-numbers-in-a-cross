//Rayan Ahlouche
#include <iostream>
#include <cmath>
using namespace std;

void nextColumn(int q[], int &c);  //we declare the functions in the beginning of program so it is able to call on each other
void nextRow(int q[], int &c);
void backtrack(int q[], int &c);
void print(int cross[], int c);
bool ok(int q[], int c);

bool ok(int q[], int c){   //the ok function is meant to check if placements are valid by passing all the tests
    for (int i = 0; i < c; i++)  //checks to see if number has already been placed 
    if (q[i] == q[c]) return false;
    static int hA[8][5] = { //helperArray
  		{-1},       // position 0; -1 is a sentinel value (to stop checking)
  		{0,-1},     // position 1 checks 0 (square 1 needs to check adjacent square 0)
  		{0,-1},     // position 2
  		{0,1,2,-1}, // position 3
  		{0,1,3,-1}, // position 4
  		{1,4,-1},   // position 5
  		{2,3,4,-1}, // position 6
  		{3,4,5,6,-1}// position 7
  	};
  for(int i = 0; hA[c][i] != -1; i++){ // in order to check the placemnt of boxes inside the helper array. a for loop is needed and will continue to count up until it reaches negative one
      if (abs(q[c] - q[hA[c][i]]) == 1) // c is the box number. i is the position of the inner array. I used the absolute value because i wanted less lines of code and because abs will find the absolute distance and i dont want the boxes being one number a part 
     return false; 
     
  } // for loop

    return true;
} // bool bracket 

void nextColumn (int q[], int &c) {
   c++;      // move on to the next column
   if (c == 8) print(q, c); //if column is equal to eight then print solution
   
     
     nextRow(q, c); // if not we place the variables in the nextrow function
}// next column bracket

void nextRow(int q[], int &c){
   q[c]++; //move to the next row
   if (q[c] > 8){ // that means the value is beyond the capacity thus meaning we have to reset the value and backtack 
       q[c] = 0; // reset the value
      backtrack(q, c); 
   } //if bracket
else if (ok(q, c)) { //
	nextColumn(q, c);	//since the value we are trying to place in square c is valid since bool ok returns true we can go to the next square
		
	}
	else {
		nextRow(q, c);//we need to try a new value in square c (i.e. go to the next row)
	}
    
} // nextRow bracket

void backtrack(int q[], int &c){ //pass the value of c by reference so it can be changed within the function
    c--; // goes back a column
    if (c == -1) {  //since it reaches -1 we cant go further back thus meaning we are done
        exit(0);   // return does not work due to being void
    } // done 
    nextRow(q, c);
}//backtrack bracket

void print(int q[], int c){
   static int sol = 0;
    cout << "Solution#" << ++sol << "\n"; // we use ++sol because we want the solution number to go up
    cout << "\n" << "   " << q[0] << " " << q[1] << endl;
    cout << " " <<  q[2] << " " << q[3] << " " << q[4] << " " << q[5] << endl; 
    cout << " " << "  " << q[6] << " " << q[7] << endl; 
    backtrack(q, c);
}// print bracket

int main() {
	int q[8] = {1, 1, 1, 1, 1, 1, 1, 1}, c = 0;
    q[0] = 1;
    nextColumn(q, c);
}
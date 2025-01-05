#include <iostream>
#include "lcs_header.h"
#include <string>
#include <vector>
#include <ctime>

//constructor
lcs::lcs(){}
//Part 1:
//Purpose: This function is to take in a matrix, C and iterate through it entirely while comparing the characters from the two strings
//If done correctly, the lcs length will be the bottom right value
//This method will not be used to actually return the lcs string itself, but rather will populate the matrix that is then fed to the backtrack method to return the lcs string
int lcs::lcs_it(int** C, string X, string Y, int m, int n){
  //these nested for loops will set matrix default values to 0
  for (int i = 0; i <= m; i++) 
    for (int j = 0; j <= n; j++) 
        C[i][j] = 0; //set C[i][j] equal to 0. Iterate through every location of the matrix

  //loop through m times starting from 1
  for (int i = 1; i <= m; i++) { 
      //loop through n times starting from 1
      for (int j = 1; j <= n; j++) {
          //check if the value on top and the value to left in matrix C are equal to each other 
           if (X[i-1] == Y[j-1]){
             //if so, add 1
            C[i][j] = C[i-1][j-1] + 1; 
           }
          else{
            //find max of the value to left and value above
            C[i][j] = max(C[i-1][j], C[i][j-1]);
          }
      }
  }
    // cout << C[1][0] << endl;
    return C[m][n]; //return lcs length, which is also the very bottom right max value of the matrix
}
//Purpose: This method takes in the matrix C and starts from the bottom right hand and backtracks its way in order to finally return the lcs string
//This method is not meant to return the length of lcs, but rather the string
string lcs::backtrack(int** C, string X, string Y, int m, int n){
  
  // return an empty string if the end of either sequence is reached
    if (m == 0 || n == 0) {
        return string("");
    }
 
    // if the last character of X and Y matches
    if (X[m - 1] == Y[n - 1])
    {
        //recursive call: 
        // append current character X[m-1] or Y[n-1] to lcs of substring X[0…m-2] and Y[0…n-2]
        return lcs::backtrack(C, X, Y, m - 1, n - 1) + X[m - 1];
    }
 
    // if a top cell > left cell then drop current character of string X and find lcs of substring X[0…m-2], Y[0…n-1]
    if (C[m - 1][n] > C[m][n - 1]) {
        return lcs::backtrack(C, X, Y, m - 1, n); //recursive call
    }
    else {
        //if left cell > top cell then drop the current character of string Y and find lcs of substring X[0…m-1],Y[0…n-2]
        return lcs::backtrack(C, X, Y, m, n - 1); //recursive call
    }
}

//PART 2: 
//In this section we're recreating the iterative function, but without passing in the matrix as a param. We're creating the matrix within the function. In addition, instead of using recursion to backtrack and find the lcs string, we're using recursion to return the length of the lcs
//These are the two functions that we will be testing and plotting in the analysis portion of the project
//This lcs_it_test function will be exactly the same except that we create the matrix C inside the function
int lcs::lcs_it_test(string X, string Y, int m, int n){
  //initialize matrix C
  //dimensions will be m+1 and n+1
  int **C=new int*[m+1];
  for (int i=0; i<m+1;++i) C[i]=new int [n+1];
  //nested for loop used for setting matrix C to default of 0
  for (int i = 0; i <= m; i++) 
    for (int j = 0; j <= n; j++) 
        C[i][j] = 0; //set C[i][j] equal to 0

  //loop that runs m times starting from 1
  for (int i = 1; i <= m; i++) { 
      //loop that runs n times starting from 1
      for (int j = 1; j <= n; j++) {
          //check if value to the left and value above are equal
           if (X[i-1] == Y[j-1]){
             //if so then add 1
            C[i][j] = C[i-1][j-1] + 1;
           }
          else{
            //else take the max of the upper and the left value
            C[i][j] = max(C[i-1][j], C[i][j-1]);
          }
      }
  }
    // cout << C[1][0] << endl;
    return C[m][n]; //return the lcs length which is the bottom right value of matrix C
}

//Purpose: this method is similar to the one above, excep that is does not use a matrix. It also does not return the lcs string. This function uses recursion to return the lcs length. 
int lcs::lcs_re(string X, string Y, int m, int n){
  if (m == 0 || n == 0) //base case
        return 0;
    //check if the left value is equal to the value above
    if (X[m-1] == Y[n-1]){
        //if so add 1 and do recursive call 
        return 1 + lcs::lcs_re(X, Y, m-1, n-1); //recursive call
    }
    else {
        //else get the max of two recursive branches
        //one of these branches does recursive call with n-1 and m while the other does recursive call with n and m-1
        return max(lcs::lcs_re(X, Y, m, n-1), lcs_re(X, Y, m-1, n));
    }
}

// string lcs::rnd_string(int length){
//   static const char chars[] =
// "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// int stringLength = sizeof(chars) - 1;

// string Str;
//     for(unsigned int i = 0; i < length; ++i)
//     {
//     Str += chars[rand() % stringLength];;

//     }
//     return Str;
// }


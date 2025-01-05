#include <iostream>
#include "lcs_header.h"
using namespace std;
#include <vector>
#include <string>
#include <stdlib.h>    
#include <time.h> 
#include <ctime>
#include <fstream>

//main method
//this main method will be used for driving the entire program
//We will be running the iterative & recursive functions for both 
//part 1 and part 2 from here
int main() {
  int start_s_it, stop_s_it, start_s_rec, stop_s_rec; //initializing vars for time keeping

  lcs lcs; //instantiating class object
  ifstream inFile;

  string X; string Y; //initializing X & Y string. Used for containing input file strings
  ifstream input("input.txt"); //using ifstream to read in input.txt
  getline(input, X); //setting string to X
  getline(input, Y); //setting string to Y
  
    //  string X = "ACCGTCTTAGCGATCAACACATTTAACAACGCGCCGCACCCCCCGTCAAACGAGCTTTTGGGCTCTTGTCCTTTTACAAGCTTCACGACGCATACAGCCTTGATCAACGGTTTGATCTGTCTCCCTTCAGCTGGCTTTAAAGGACATACATATGAAGGCCTTAATAAGGTCCGGGAACTCCACATATTCGGTACTGGGCAAACCCCATGAACCACCTCAACATGAAGAGTCCGAGGACTCTCACGATCCACCAATGCAGATCGGAACTGTGCGATCGCGTAATGAGCCGAGTACTTGGTTTGTGTTTAGGTTATGGGGGCCGGGAGCCGGTTCAATATAAGGAAGTAGTTGCAGATTAGTTGTTGCGAACGGTCATAAATTTGATGGGTAAACGTGAACTTAACAAACCGTGATAGCTAATCCTATGCATCCCTTACGTGGATCGACTCGAGTACCCAGGTGAACCGACTACTTGATAACCGGAAATCGCGGTATAAAAGCGCTCACGGTCAGGAGATATACCTCCAAGCAGTAGTCTTTCTGAGCCTAGAGTAGTAAATTACAGGGACGATGTCTTTTACCGAGGCAACATTTTATTGAGAATCACATGAGGCACAGGTAAAGGCGACATCACGATCGAGATCAACCCCTACTTGTTCAAAACATTGAGAACCAGCTCTGTTTTGGAACCTAGAAAGATAACGCATCCGCTTGATATTCCACGGCTTGTCCCTCTTGTGCGGTCCATCTATCGGAGTTTCCTCCGATACGACCCGCAATGTTTCCAGGCGTACGGTACTTTATGAATACACTCGCGCTGTAACCTGTTATGTGAAACACACACGACAGAGCTTCGCGTGGGCCCAGCGACCCGGTAATACTACATCACCGCACACGACCTCGAGCAGTCTTTGCCGGCGTCCGTAAGTAGTCTAAAGTTGTGTTGATGCTTGGGGTTAAAGCTAAATCGTCCGCAGAATACGACTCTCATCCCAAT";
    //  string Y = "ACCCGCACGCGCTTTGGTCTAGATTCTAGCTCCAACTTGCCTGCTAGATACTCTGTTAAAAGATGGTTTTACAACCCCCTCCTCTGTCCCTGGGGTATTATATAATACGTCGGATAGTCAGGTACAAATACAAGTGGGTGGGAATACTTTTCCTCGGATCCTAGACCACGGATTACTGCGTGGTTGACAAGAGTCGGCCCGGAGGGAAACGTGAAGGTTAGTGCAATTAAAGTCTCTAATGTGAAGCCTCCGCGAAGCGAGGAGTTTCTGAGATCGAGTACTATTTAGAGTTCGAAATCACGGCTTAACCTCACTGCCACGCATAACTTGCCGGCAATCCAGTTTTGCAACGATACTTAATTTGTGCAGCTCATCTTTGCTGTCCAGAAATAGAGCTAGTCGATCTCATCTTGCGGGTAGCCAGAAGTCCTACCGTCTCCTCCATGTAGCTTAAAAATTTCGGTGAGGATCAAAAATGATAAACGTGACAGGTAAGCTCCTACGTCTATCCTATGACCCCCGCGGCAGAATAGGTTGGTAGTGTTAGTGCGTGAGCTGGTAGAATAGAGCACACTTAGGGAAACGGGAACCGTTATGTAGGGCTGCGACACACAAAAAAGTGTTCGTTGGTAAGCTGCCTCTCCACTAAACAGGATTTCTCTGGATGATCCCATCGAAGCAAGTTACGCACCACGCCGAGGCGGACCCTGGTACTAGCTGCCCCCCCCTTTATGGGGCGCTCGTACATCAAGATGATCGCGGACTCAACCTGATTACGAGTTGTCCAAGTAGTCCAGGGTAAGAGAAACTGGAGAGA";


//Part 1:
  int m=X.size(); //initialize m as the size of string X
  int n=Y.size(); //initialize m as the size of string Y
  //Initialize matrix to use for LCS
  //This matrix will have dimensions of m+1 and n+1
  int **C=new int*[m+1];
  for (int i=0; i<m+1;++i) C[i]=new int [n+1];

  // int **lookup=new int*[m+1];
  // for (int i=0; i<m+1;++i) lookup[i]=new int [n+1];
  
  //Run the lcs_it function (see lcs.cpp for function description)
  //Set output to variable 'len'
  int len=lcs.lcs_it(C, X, Y, m, n);
  //Run the backtrack function (see lcs.cpp for function description)
  //Set output to variable 'final_lcs'
  string final_lcs = lcs.backtrack(C, X, Y, m, n);

  // int len_test = lcs.lcs_it_test(X, Y, m, n);
  // int lcs_re_test = lcs.lcs_re(X,Y,m,n);

  //Print out results for testing
  cout << "LCS String: " 
       << final_lcs 
       << endl 
       << "Length of LCS: "
       << len
       << endl;

  //Part 2: Testing the functions
  //In this section we take user inputs for both the iterative and recursive functions
  //iterative input max: 800 characters in string
  //recursive input max: 20 characters in string
  //the strings should be looped so that we run each character through each of the two functions from char 1 to char n
  //Iterative Method:
  //collect user input for iterative method
  int input_it; //initialize int variable for user input
  //Prompt user for their input
  cout << "Enter desired string length for iterative version: " << endl; // Type a number and press enter
  cin >> input_it; // Get user input for iterative function
  //while look to ensure that user input is between 0 and 800
  while(input_it<0 || input_it>800){
    cout<<"Please enter a value between 0 and 800: " <<endl;
    cin >> input_it;
  }
  //srand(time(0));
  // string X_test_it = lcs.rnd_string(input_it);
  // string Y_test_it = lcs.rnd_string(input_it);
  // int m_it = X_test_it.size();
  // int n_it = Y_test_it.size();
  // int m_it = input_it;
  // int n_it = input_it;

  //this for loop is used to feed one character at a time into the iterative function. Each character is appended to the previous one so taht the string grows to size of user input
  for(int i=1; i<input_it+1; i++){
    start_s_it =clock(); //start clock
    int result_it = lcs.lcs_it_test(X.substr(0,i), Y.substr(0,i), X.substr(0,i).size(), Y.substr(0,i).size());
    stop_s_it=clock(); //stop clock
    float timer_result = (stop_s_it-start_s_it)/double(CLOCKS_PER_SEC)*1000; //calculate run time
  // cout << timer_result << endl;
    cout << X.substr(0,i).size() << "," << timer_result << endl; 
    cout << "LCS length:" << result_it << endl;
    //print out string size for each iteration along with the run time for that particular string size

    // cout << "X string:" << X_test_it.substr(0,i) << endl << "Y string:" << Y_test_it.substr(0,i) << endl << "LCS length:" << result_it << endl;
  }
  

  //Recursive Method:
  //collect user input for recursive method
  int input_rec; //initialize var to hold user input
  //Prompt the user for their input
  cout << "Enter desired string length for recursive version: " << endl; // Type a number and press enter
  cin >> input_rec; // Get user input from the keyboard
  //while look to ensure that user input is between 0 and 20
  while(input_rec<0 || input_rec>20){
    cout<<"Please enter a value between 0 and 20: "<< endl;
    cin >> input_rec; //capture user input
  }
  // string X_test_rec = lcs.rnd_string(input_rec);
  // string Y_test_rec = lcs.rnd_string(input_rec);
  // int m_rec = input_rec;
  // int n_rec = input_rec;

  //this for loop is used to feed one character at a time into the iterative function. Each character is appended to the previous one so taht the string grows to size of user input
  for(int i=1; i<input_rec+1; i++){
    start_s_rec=clock(); //start clock
    // X_append_rec += X_test_rec[i];
    // Y_append_rec += Y_test_rec[i];
    int result_rec = lcs.lcs_re(X.substr(0,i), Y.substr(0,i), X.substr(0,i).size(), Y.substr(0,i).size());
    stop_s_rec=clock(); //stop clock
    // cout << "X string:" << X.substr(0,i) << endl << "Y string:" << Y.substr(0,i) << endl << "LCS length:" << result_rec << endl;
  float timer_result2 = (stop_s_rec-start_s_rec)/double(CLOCKS_PER_SEC)*1000; //calculate run time
    //print out string size for each iteration along with the run time for that particular string size
    cout << X.substr(0,i).size() << "," << timer_result2 << endl;
    cout << "LCS Length:" << result_rec << endl; 
  }


  return 0;
} 
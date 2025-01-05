#include <iostream>
using namespace std;
#include <string>
#include <vector>
//lcs class
//this header is used to set up public functions used in the body as well as private vars m and n
class lcs{
  public:
    //lcs(string X_, string Y_, int m_, int n_); //constructor
    lcs(); //constructor
    //lcs_it used to return lcs length with matrix
    int lcs_it(int **, string, string, int, int);
    //backtrack used to return lcs string by backtracking matrix
    string backtrack(int **, string, string, int, int);
    //lcs_it_test used to find lcs length, but does not take in matrix as param
    int lcs_it_test(string X, string Y, int m, int n);
    //lcs_re function used to return lcs length
    int lcs_re(string X, string Y, int m, int n);
    // string rnd_string(int length);
  private:
    int m; //m stores string X length
    int n; //n stores string Y length
};
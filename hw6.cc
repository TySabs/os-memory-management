/*********************************************************************
 * Name: Tyler Saballus
 * Date: 11/14/2018
 * Operating Systems 480 - Hutchins - Boley/Crumpton
 * Assignment 6 - Memory Management
 ***********************************************************************/

#include <iostream>
#include <fstream>
#include "memoryblock.h"

using std::cerr;
using std::endl;
using std::ifstream;

const int HOWOFTEN = 1;


/***********************************************************************
*
*                        Main Program
*
***********************************************************************/
int main(int argc, char *argv[]) {

  if (*argv[1] == 'B') {
    cerr << "B detected" << endl;
  } else if (*argv[1] == 'F') {
    cerr << "F detected" << endl;
  } else {
    cerr << "Error! invalid argument" << endl;
    exit(-1);
  }

  // Open the file
  ifstream infile;
  infile.open("./data6.txt");

  // Error check for file open error
  if (!infile) {
    cerr << "Unable to open file data6.txt";
    exit(1);
  }

  return 0;
}

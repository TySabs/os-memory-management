/*********************************************************************
 * Name: Tyler Saballus
 * Date: 11/14/2018
 * Operating Systems 480 - Hutchins - Boley/Crumpton
 * Assignment 6 - Memory Management
 ***********************************************************************/

#include <iostream>
#include "memoryblock.h"

using std::cerr;
using std::endl;

const int HOWOFTEN = 1;


/***********************************************************************
*
*                        Main Program
*
***********************************************************************/
int main(int argc, char *argv[]) {
  cerr << "Hello World!" << endl;

  cerr << "Simulation of Memory Management using the Best-Fit algorithm" << endl;

  MemoryBlock *b = new MemoryBlock();
  b->Hello();

  return 0;
}

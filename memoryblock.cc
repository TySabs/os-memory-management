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

MemoryBlock::MemoryBlock() {

}

void MemoryBlock::Hello() {
  cerr << "Hello from MemBlock!" << endl;
}

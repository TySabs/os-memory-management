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

MemoryBlock::MemoryBlock(int address, int _size) {
  startingAddress = address;
  size = _size;
}

MemoryBlock::MemoryBlock(int _size, string pid, string bid) {
  startingAddress = -1;
  size = _size;
  processId = pid;
  blockId = bid;
}

int MemoryBlock::getSize() {
  return size;
}

void MemoryBlock::setSize(int value) {
  size = value;
}

void MemoryBlock::printBlockInfo() {
  cerr << "Start Address = " << startingAddress << " ";
  cerr << "Size = " << size << endl;
}

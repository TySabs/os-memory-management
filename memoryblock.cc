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


/***********************************************************************
 * MemoryBlock constructor
 *
 * Arguments(0):
 *
 * Use: Creates a null memory block
 ***********************************************************************/
MemoryBlock::MemoryBlock() {}


/***********************************************************************
 * MemoryBlock constructor
 *
 * Arguments(2):
 *   1. address - starting address
 *   2. _size - size of the block
 *
 * Use: Creates a memory block without a process or block ID
 ***********************************************************************/
MemoryBlock::MemoryBlock(int address, int _size) {
  startAddress = address;
  size = _size;
}

/***********************************************************************
 * MemoryBlock constructor
 *
 * Arguments(3):
 *   1. _size - size of the block
 *   2. pid - process ID
 *   3. bid - block ID
 *
 * Use: Creates a memory block with a process and block ID
 ***********************************************************************/
MemoryBlock::MemoryBlock(int _size, string pid, string bid) {
  startAddress = -1;
  size = _size;
  processId = pid;
  blockId = bid;
}

/***********************************************************************
 * MemoryBlock.getSize method
 *
 * Arguments(0):
 *
 * Returns: the block's size
 *
 * Use: gets the block size
 ***********************************************************************/
int MemoryBlock::getSize() {
  return size;
}

/***********************************************************************
 * MemoryBlock.setSize method
 *
 * Arguments(1):
 *  1. value - the new size value
 *
 * Returns: void
 *
 * Use: sets the block size
 ***********************************************************************/
void MemoryBlock::setSize(int value) {
  size = value;
}

/***********************************************************************
 * MemoryBlock.getStartAddress method
 *
 * Arguments(0):
 *
 * Returns: the block's starting address
 *
 * Use: gets the block's starting address
 ***********************************************************************/
int MemoryBlock::getStartAddress() {
  return startAddress;
}

/***********************************************************************
 * MemoryBlock.setStartingAddress method
 *
 * Arguments(1):
 *  1. value - the new starting address
 *
 * Returns: void
 *
 * Use: sets the block's starting address
 ***********************************************************************/
void MemoryBlock::setStartAddress(int value) {
  startAddress = value;
}

/***********************************************************************
 * MemoryBlock.getProcessId method
 *
 * Arguments(0):
 *
 * Returns: the block's processID
 *
 * Use: gets the block's process ID
 ***********************************************************************/
string MemoryBlock::getProcessId() {
  return processId;
}

/***********************************************************************
 * MemoryBlock.printBlockInfo method
 *
 * Arguments(0):
 *
 * Returns: void
 *
 * Use: prints the block info including address and size
 ***********************************************************************/
void MemoryBlock::printBlockInfo() {
  cerr << "Start Address = " << startAddress << " ";
  cerr << "Size = " << size << endl;
}

/***********************************************************************
 * MemoryBlock.printUsageInfo method
 *
 * Arguments(0):
 *
 * Returns: void
 *
 * Use: prints the usage info including address, size, processId, and blockId
 ***********************************************************************/
void MemoryBlock::printUsageInfo() {
  cerr << "Start address = " << startAddress << " ";
  cerr << "Size = " << size << " ";
  cerr << "Process ID = " << processId << " ";
  cerr << "Block ID = " << blockId << endl;
}

/***********************************************************************
 * MemoryBlock.printProcessInfo method
 *
 * Arguments(0):
 *
 * Returns: void
 *
 * Use: prints the process info including size, processId, and blockId
 ***********************************************************************/
void MemoryBlock::printProcessInfo() {
  cerr << "Transaction: request to load process " << processId;
  cerr << ", block ID " << blockId;
  cerr << " using " << size << " bytes" << endl;
}

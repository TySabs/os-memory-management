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
  startAddress = address;
  size = _size;
}

MemoryBlock::MemoryBlock(int _size, string pid, string bid) {
  startAddress = -1;
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

int MemoryBlock::getStartAddress() {
  return startAddress;
}

void MemoryBlock::setStartAddress(int value) {
  startAddress = value;
}

string MemoryBlock::getProcessId() {
  return processId;
}

void MemoryBlock::printBlockInfo() {
  cerr << "Start Address = " << startAddress << " ";
  cerr << "Size = " << size << endl;
}

void MemoryBlock::printUsageInfo() {
  cerr << "Start address = " << startAddress << " ";
  cerr << "Size = " << size << " ";
  cerr << "Process ID = " << processId << " ";
  cerr << "Block ID = " << blockId << endl;
}

void MemoryBlock::printProcessInfo() {
  cerr << "Transaction: request to load process " << processId;
  cerr << ", block ID " << blockId;
  cerr << " using " << size << " bytes" << endl;
}

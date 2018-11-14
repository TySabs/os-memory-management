/*********************************************************************
 * Name: Tyler Saballus
 * Date: 11/14/2018
 * Operating Systems 480 - Hutchins - Boley/Crumpton
 * Assignment 6 - Memory Management
 ***********************************************************************/

#include <iostream>
#include <fstream>
#include <list>
#include "memoryblock.h"

using std::cerr;
using std::endl;
using std::list;
using std::ifstream;

const int HOWOFTEN = 1;
const int ONE_MB = 1024 * 1024;

void printAvailableBlocks(list<MemoryBlock> availableBlocks) {
  cerr << "List of available blocks" << endl;

  int totalSize = 0;
  for (MemoryBlock mb : availableBlocks) {
    mb.printBlockInfo();
    totalSize += mb.getSize();
  }

  cerr << "Total size of the list = " << totalSize << endl << endl;
}

void allocateMemory(list<MemoryBlock> &availableBlocks, MemoryBlock processBlock) {

  list<MemoryBlock>::iterator it;
  for (it = availableBlocks.begin(); it != availableBlocks.end(); it++) {
    if (processBlock.getSize() < it->getSize()) {
      cerr << "Found a block of size " << it->getSize() << endl;
      int newSize = it->getSize() - processBlock.getSize();
      it->setSize(newSize);
      cerr << "Success in allocating a block" << endl << endl;
      break;
    }
  }
}


/***********************************************************************
*
*                        Main Program
*
***********************************************************************/
int main(int argc, char *argv[]) {
  // Error check for no argument
  if (argv[1] == NULL) {
    cerr << "Error! Please Enter 'B' or 'F' as an argument" << endl;
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

  list<MemoryBlock> InUse, Avail;
  InUse = list<MemoryBlock>();
  Avail = list<MemoryBlock>();

  MemoryBlock block1, block2, block3, block4, block5;

  const int size1 = 1 * ONE_MB,
            size2 = 2 * ONE_MB,
            size3 = 2 * ONE_MB,
            size4 = 4 * ONE_MB,
            size5 = 4 * ONE_MB;

  int blockIterator = 3 * ONE_MB;

  block1 = MemoryBlock((blockIterator), size1);
  blockIterator += size1;

  block2 = MemoryBlock((blockIterator), size2);
  blockIterator += size2;

  block3 = MemoryBlock((blockIterator), size3);
  blockIterator += size3;

  block4 = MemoryBlock((blockIterator), size4);
  blockIterator += size4;

  block5 = MemoryBlock((blockIterator), size5);

  Avail.push_back(block1);
  Avail.push_back(block2);
  Avail.push_back(block3);
  Avail.push_back(block4);
  Avail.push_back(block5);


  if (*argv[1] == 'B') {
    cerr << "B detected" << endl;
    printAvailableBlocks(Avail);
  } else if (*argv[1] == 'F') {
    cerr << "Simulation of Memory Management using the First-Fit algorithm" << endl << endl;
    cerr << "Beginning of the run" << endl << endl;
    printAvailableBlocks(Avail);

    char transactionType;
    string pid, bid;
    int pSize;
    infile >> transactionType;

    if (transactionType == 'L') {
      infile >> pid;
      infile >> pSize;
      infile >> bid;

      cerr << "Transaction: request to load process " << pid << ", block ID " << bid
            << " using " << pSize << " bytes" << endl << endl;

      MemoryBlock newBlock = MemoryBlock(pSize, pid, bid);

      allocateMemory(Avail, newBlock);
      printAvailableBlocks(Avail);

    }

  } else {
    cerr << "Error! invalid argument" << endl;
    exit(-1);
  }


  return 0;
}

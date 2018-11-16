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

const int ONE_MB = 1024 * 1024;

/***********************************************************************
 * printAvailableBlocks function
 *
 * Arguments(1):
 *   1. availableBlocks - list of available blocks
 *
 * Returns: void
 *
 * Use: Prints the contents of the Avail list
 ***********************************************************************/
void printAvailableBlocks(list<MemoryBlock> &availableBlocks) {
  cerr << "List of available blocks" << endl;

  int totalSize = 0;
  list<MemoryBlock>::iterator it;
  for (it = availableBlocks.begin(); it != availableBlocks.end(); it++) {
    it->printBlockInfo();
    totalSize += it->getSize();
  }

  cerr << "Total size of the list = " << totalSize << endl << endl;
} // end printAvailableBlocks


/***********************************************************************
 * printBlocksInUse function
 *
 * Arguments(1):
 *   1. inUseBlocks - list of blocks being used
 *
 * Returns: void
 *
 * Use: Prints the contents of the InUse list
 ***********************************************************************/
void printBlocksInUse(list<MemoryBlock> &inUseBlocks) {
  cerr << "List of blocks in use" << endl;
  int totalSize = 0;

  // Check if inUse is empty, otherwise print its contents and add to total
  if (inUseBlocks.size() <= 0) {
    cerr << "(none)" << endl;
  } else {
    list<MemoryBlock>::iterator it;
    for (it = inUseBlocks.begin(); it != inUseBlocks.end(); it++) {
      it->printBlockInfo();
      totalSize += it->getSize();
    }
  } // end else

  cerr << "Total Size of the list = " << totalSize << endl << endl;
} // end printBlocksInUse

/***********************************************************************
 * allocateMemory function
 *
 * Arguments(2):
 *   1. availableBlocks - list of available blocks
 *   2. processBlock - block to be allocated
 *
 * Returns: void
 *
 * Use: allocates a block of a memory in the available blocks list
 ***********************************************************************/
bool allocateMemory(list<MemoryBlock> &availableBlocks, MemoryBlock &processBlock) {
  processBlock.printProcessInfo();

  list<MemoryBlock>::iterator it;
  for (it = availableBlocks.begin(); it != availableBlocks.end(); it++) {
    if (processBlock.getSize() < it->getSize()) {
      cerr << "Found a block of size " << it->getSize() << endl;

      // Set process's starting address
      processBlock.setStartAddress(it->getStartAddress());

      // Resize existing block of memory
      int newSize = it->getSize() - processBlock.getSize();
      it->setSize(newSize);

      // Set the starting address of resized block of memory
      int newAddress = it->getStartAddress() + processBlock.getSize();
      it->setStartAddress(newAddress);
      cerr << "Success in allocating a block" << endl << endl;
      return true;
    }
  } // end for loop

  return false;
} // end allocateMemory


/***********************************************************************
 * deallocateMemory function
 *
 * Arguments(2):
 *   1. availableBlocks - list of available blocks
 *   2. terminateBlock - block to be allocated
 *
 * Returns: void
 *
 * Use: allocates a block of a memory in the available blocks list
 ***********************************************************************/
void deallocateMemory(list<MemoryBlock> &availableBlocks, MemoryBlock &terminateBlock) {
  int blockOffset = terminateBlock.getStartAddress() + terminateBlock.getSize();

  list<MemoryBlock>::iterator it, it2;
  bool isNotFirstLoop = false;
  for (it = availableBlocks.begin(); it != availableBlocks.end(); it++) {
    // If block is the block below terminated block, delete  merge and terminated block
    if (it->getStartAddress() == blockOffset) {
      cerr << "Merging two blocks at " << terminateBlock.getStartAddress();
      cerr << " and " << it->getStartAddress() << endl;

      // Set merged block's address
      it->setStartAddress(terminateBlock.getStartAddress());

      // Set merged block's size
      int newSize = it->getSize() + terminateBlock.getSize();
      it->setSize(newSize);
    }

    // If last block's ending matches this block's starting, merge the two blocks
    if (isNotFirstLoop && it2->getStartAddress() + it2->getSize() == it->getStartAddress()) {
      int newSize = it->getSize() + it2->getSize();

      // Check to make sure newSize is less than 4MB
      if (newSize < 4 * ONE_MB) {
        cerr << "Merging two blocks at " << it2->getStartAddress();
        cerr << " and " << it->getStartAddress() << endl;

        // Set starting address and size to former's address and merged size
        it->setStartAddress(it2->getStartAddress());
        it->setSize(newSize);

        availableBlocks.erase(it);
      } // end if less than 4MB
    } // end if matched

    isNotFirstLoop = true; // prevents fault
    it2 = it;
  } // end for loop

  cerr << endl;
} // end deallocateMemory


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

  // Instantiate starting memory blocks
  block1 = MemoryBlock((blockIterator), size1);
  blockIterator += size1;

  block2 = MemoryBlock((blockIterator), size2);
  blockIterator += size2;

  block3 = MemoryBlock((blockIterator), size3);
  blockIterator += size3;

  block4 = MemoryBlock((blockIterator), size4);
  blockIterator += size4;

  block5 = MemoryBlock((blockIterator), size5);

  // Add memory blocks to Avail list
  Avail.push_back(block1);
  Avail.push_back(block2);
  Avail.push_back(block3);
  Avail.push_back(block4);
  Avail.push_back(block5);

  // This program only uses First-Fit algorithm
  if (*argv[1] == 'F' || 'B') {
    cerr << "Simulation of Memory Management using the First-Fit algorithm" << endl << endl;
    cerr << "Beginning of the run" << endl << endl;
    printAvailableBlocks(Avail);
    printBlocksInUse(InUse);

    char transactionType;
    string pid, bid, endLine;
    int pSize;
    MemoryBlock newBlock;
    bool success;

    // Prime read
    infile >> transactionType;

    // Loop through the file's contents
    while (infile && transactionType != '?') {
      list<MemoryBlock>::iterator removeIterator;

      switch (transactionType) {
        case 'L':
        case 'A':
          infile >> pid;
          infile >> pSize;
          infile >> bid;

          newBlock = MemoryBlock(pSize, pid, bid);

          success = allocateMemory(Avail, newBlock);
          if (success) { InUse.push_back(newBlock); }

          printAvailableBlocks(Avail);
          printBlocksInUse(InUse);
          break;
        case 'D':
        case 'T':
          infile >> pid;

          if (transactionType == 'D') { infile >> pSize; }

          cerr << "Transaction: request to terminate process " << pid << endl;

          for (removeIterator = InUse.begin(); removeIterator != InUse.end(); removeIterator++) {
            if (pid == removeIterator->getProcessId()) {
              deallocateMemory(Avail, *removeIterator);
              InUse.erase(removeIterator);
              cerr << "Success in terminating a process" << endl << endl;
              break;
            }
          } // end for loop

          break;
        case '?':
          cerr << endl << "Terminating program." << endl << endl;
          return 0;
          break;
        default:
          cerr << "Unhandled Char" << endl;
          break;
      } // end switch

      infile >> transactionType;
    } // end while loop

  } else {
    cerr << "Error! invalid argument" << endl;
    exit(-1);
  }


  return 0;
} // end main

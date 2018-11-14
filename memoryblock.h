#ifndef MEMORYBLOCK_H
  #define MEMORYBLOCK_H

  /*********************************************************************
   * Name: Tyler Saballus
   * Date: 11/14/2018
   * Operating Systems 480 - Hutchins - Boley/Crumpton
   * Assignment 6 - Memory Management
   ***********************************************************************/

  #include <string>
  using std::string;

  class MemoryBlock {
    private:
      int startingAddress;
      int size;
      string processId;
      string blockId;

    public:
      MemoryBlock();
      MemoryBlock(int, int);
      MemoryBlock(int, string, string);
      void printBlockInfo();

      int getSize();
      void setSize(int);
  };

#endif

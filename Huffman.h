#ifndef HUFFMAN_H
#define HUFFMAN_H

// ---------- INCLUDES ------------------------------------------------------------------
#include <map>
#include <vector>
#include <string>
#include "Node.h"

// ---------- HUFFMAN CLASS -------------------------------------------------------------
class Huffman {
private:
    /*
    DATAFILE:
    BYTE    0xHF
    BYTE    PADDING OFFSET
    CHAR*   DATA
    
    TABLEFILE:
    BYTE    0xHF
    
        per entry:
        CHAR ch
        CHAR paddingOffset
        int  data
    */
    
    // ---------- STRUCTS ---------------------------------------------------------------
    struct DataFile {
        char  magicNumber;
        char  paddingOffset;
        char* data;
    };
    
    struct TableEntry{
        char data;
        char size;
        int  bits;
    };
    
    struct TableFile {
        char magicNumber;
        int  tableSize;
        std::vector<TableEntry> data;
    };

    // ---------- VARIABLES -------------------------------------------------------------
    Node*       tree;
    DataFile*   datafile;
    TableFile*  tablefile;
    std::string decodedResult;
    std::vector<std::pair<int, int>>        encodedResult;
    std::map<char, std::pair<int, int>>*    encodingMap;
    std::map<char, int>*                    frequencies;

    // ---------- PRIVATE FUNCTIONS -----------------------------------------------------
    std::map<char, int>*                getFrequencies(char* data, int size);
    std::vector<std::pair<int, int>>    buildEncodedResult(char* data, int size);
    DataFile*   createDataFile(std::vector<std::pair<int, int>>& v);
    TableFile*  createTableFile(std::map<char, std::pair<int, int>>& m);
    DataFile*   readDataFile(ifstream* file);
    TableFile*  readTableFile(ifstream* file);
    void        writeDataFile(ofstream* file);
    void        writeDataFile(ofstream* file);
    void        Sort(std::vector<Node*>& v);
    void        buildTree();
    void        showTree();
    void        showIntVector(std::vector<int>& v);
    
public:
    // ---------- PUBLIC FUNCTIONS ------------------------------------------------------
    Huffman();
    ~Huffman();
    void encode(std::string filename);
    void decode(std::string data_filename, std::string table_filename);
};

#endif
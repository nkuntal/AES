/*
 * Cipher.hpp
 * The structure of Cipher class
 */ 

#ifndef Cipher_hpp
#define Cipher_hpp

#include "stdio.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "stdlib.h"
#include "fstream"
#include "iterator"
#include "State.hpp"
#include "Block.hpp"

class Cipher{
    private:
        /* Enc/Dec variables-methods */
        const static uint8_t sbox[16][16];
        const static uint8_t sboxInv[16][16];
        uint8_t** aesKeyExp;
        uint8_t** macKeyExp;

        uint8_t xTime(uint8_t st);
        uint8_t gFMultiply(uint8_t matrixValue, uint8_t st);
        void shiftColumnsByOne(uint8_t** st, int* row, bool leftDir);
        void shiftColumnsByTwo(uint8_t** st, int* row);
        void RotWord(uint8_t* w);
        void Rcon(int c, uint8_t* ch);
        void subWord(uint8_t* wd);
        void generateKey(uint8_t* buff, int _Nk);
        void keyExpansion(uint8_t* key, uint8_t** keyExpanded);
        void addRoudKey(int round, uint8_t** w, uint8_t** st);
        void subBytes(uint8_t** st);
        void shiftRows(uint8_t** st);
        void mixColumns(uint8_t** st, uint8_t** tmp);
        void encrypt(Sequence* input, uint8_t** key);
        void decrypt(Sequence* input, uint8_t** key);
        void invMixColumns(uint8_t** st, uint8_t** s2);
        void invShiftRows(uint8_t** st);
        void invSubBytes(uint8_t** st);
        
        /* Utilities */
        Block* inputBlock;
        int Nk, Nr, mssgLength;
        string* textPath;
        string home, aesKeyPath, macKeyPath;

        bool authenticateSequences(Sequence* first, Sequence* second);
        bool fileExists(const string* fileName);
        int getKeySize(string* aesKey, string* macKey);
        Sequence CBC_MAC(Block block, bool encrypting, bool padding);
        void cryptoDir();
        void getKey(bool encrypt, string* keyPath, uint8_t*** keyExpanded);
        void getMessageLength(uint8_t** s, bool encrypting, bool padding);
        void readText(vector<uint8_t>* inpVct);
        void removePadding(Sequence* lastPlainText);
        void setBlockRoundCombinations(int* keyLength, bool setKeyPath);
        void writePlainText();
        void writeCipherText(Sequence* tag);

    public:
        Cipher(string* _textPath, int* keyLength, bool padding, bool encrypt);
        Cipher(string* _textPath, string* _aesKeyPath, string* _macKeyPath, bool padding, bool encrypt);
        Cipher(string* _textPath, string* _aesKeyPath, string* _macKeyPath, int* keyLength, bool padding, bool encrypt);         
        ~Cipher();  
        void CBC_encrypt();
        void CBC_decrypt();
        void OFB_encrypt();
        void OFB_decrypt();
};

#endif /* Cipher_hpp */

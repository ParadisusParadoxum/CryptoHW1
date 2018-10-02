//
//  Encryptor.cpp
//  ClassicalEncryption
//
//  Created by 周政耀 on 2018/10/1.
//  Copyright © 2018年 周政耀. All rights reserved.
//

#include "Encryptor.h"
#include <algorithm>
#include <set>

#include <cmath>

using std::set;


struct Pair{
    int m,n;
};

string Encryptor::Caesar(string plainText, int key){
    string cipherText = "";
    for(int i=0;i<plainText.length();++i)
        cipherText+= (plainText[i]-'a'+key)%26 + 'a';
    return cipherText;
}

string Encryptor::Monoalphabetic(string plainText, string key){
    string cipherText = "";
    for(int i=0;i<plainText.length();++i)
        cipherText += key[plainText[i]-'a'];
    return cipherText;
}

string Encryptor::Playfair(string plainText, string key){
    const string alphabet = "abcdefghiklmnopqrstuvwxyz";
    string cipherText = "", playfairMatrix = "";
    // preprocess  (note: i=j)
    for(int i=0;i<plainText.length();++i)
        if(plainText[i] == 'j')
            plainText[i]='i';
    for(int i=0;i<key.length();++i)
        if(key[i] == 'j')
            key[i] = 'i';
    // create playfair matrix
    set<char> s; // to check repeat
    key += alphabet;
    for(int i=0;i<key.length();++i){
        size_t size = s.size();
        s.insert(key[i]);
        if(s.size() > size)
            playfairMatrix += key[i];
    }
    // create map to locate
    vector<Pair> locator(26);
    for(int m=0;m<5;++m){
        for(int n=0;n<5;++n){
            locator[playfairMatrix[m*5+n]-'a']=Pair{m,n};
        }
    }
    
    
    // encrypt
    for(int i=0;i<plainText.length();i+=2){
        //
        Pair locA = locator[plainText[i]-'a'],locB;
        if(i+1 >= plainText.length()){
            locB = locator['x'-'a'];
        }else if (plainText[i] == plainText[i+1]){
            locB = locator['x'-'a'];
            i-=1;
        }else{
            locB = locator[plainText[i+1] -'a'];
        }
        if(locA.m == locB.m){
            // same row
            cipherText += playfairMatrix[locA.m * 5 + (locA.n +1)%5];
            cipherText += playfairMatrix[locB.m * 5 + (locB.n +1)%5];
        }else if(locA.n == locB.n){
            // same column
            cipherText += playfairMatrix[((locA.m + 1)%5) * 5 + locA.n];
            cipherText += playfairMatrix[((locB.m + 1)%5) * 5 + locB.n];
        }else{
            cipherText += playfairMatrix[locA.m * 5 + locB.n];
            cipherText += playfairMatrix[locB.m * 5 + locA.n];
        }
    }
    return cipherText;
}

string Encryptor::Vernam(string plainText, string key){
    string cipherText = "";
    // auto-key
    key += plainText;
    // encrypt
    
    for(int i=0;i<plainText.length();++i){
        cipherText += 'a' + ((plainText[i]-'a')^(key[i]-'a'));
    }
    
    return cipherText;
}

string Encryptor::RowTrans(string plainText, string key){
    string cipherText ="";
    vector<int> colIdx(key.length());
    for(int i=0;i<key.length();++i){
        colIdx[key[i]-'1'] = i;
    }
    for(int i=0;i<key.length();++i){
        int loc = colIdx[i];
        while(loc < plainText.length()){
            cipherText+= plainText[loc];
            loc += key.length();
        }
    }
    return cipherText;
}

string Encryptor::Product(string plainText, vector<int> key){
    string cipherText = "";
    // padding
    while( plainText.length() % key.size() != 0)
        plainText += 'x';
    for(int i=0;i<plainText.length();++i){
        int block = i/key.size(), num = i%key.size();
        cipherText += plainText[key.size()*block + key[num]-1];
    }
    
    return cipherText;
}

string Encryptor::Enc(string method, string text, int key){
    if(method == "Caesar")
        return this->Caesar(text, key);
    
    return "Method not existed";
}

string Encryptor::Enc(string method, string text, string key){
    if(method == "Monoalphabetic")
        return this->Monoalphabetic(text, key);
    else if (method == "Playfair")
        return this->Playfair(text, key);
    else if (method == "Vernam")
        return this->Vernam(text, key);
    else if (method == "RowTrans")
        return this->RowTrans(text, key);
    return "Method not existed";
}

string Encryptor::Enc(string method, string text, vector<int> key){
    if(method == "Product")
        return this->Product(text, key);
    
    return "Method not existed";
}

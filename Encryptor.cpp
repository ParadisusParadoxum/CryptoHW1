//
//  Encryptor.cpp
//  ClassicalEncryption
//
//  Created by 周政耀 on 2018/10/1.
//  Copyright © 2018年 周政耀. All rights reserved.
//

#include "Encryptor.h"
#include <algorithm>

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
    string cipherText = "";
    
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
    
    return "Method not existed";
}

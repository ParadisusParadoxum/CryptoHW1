//
//  Encryptor.h
//  ClassicalEncryption
//
//  Created by 周政耀 on 2018/10/1.
//  Copyright © 2018年 周政耀. All rights reserved.
//

#ifndef Encryptor_h
#define Encryptor_h


#endif /* Encryptor_h */
#include <string>
#include <vector>
using std::string;
using std::vector;

class Encryptor{
public:
    Encryptor(){}
    string Enc(string, string, int);
    string Enc(string, string, string);
    string Enc(string, string, vector<int>);
private:
    string Caesar(string, int);
    string Monoalphabetic(string, string);
    string Playfair(string, string);
    string Vernam(string, string);
    string RowTrans(string, string);
    string Product(string, vector<int>);
    
};
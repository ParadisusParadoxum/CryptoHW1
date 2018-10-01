//
//  main.cpp
//  ClassicalEncryption
//
//  Created by 周政耀 on 2018/10/1.
//  Copyright © 2018年 周政耀. All rights reserved.
//

#include <iostream>
#include "Encryptor.h"
using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    // insert code here...
    Encryptor encryptor;
    string plainText = "keepgoingnevergiveup";
    cout << encryptor.Enc("Caesar", plainText, 7) << endl;
    cout << encryptor.Enc("Monoalphabetic", plainText, "qwertyuiopasdfghjklzxcvbnm") << endl;
    
    return 0;
}

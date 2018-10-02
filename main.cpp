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
    Encryptor encryptor;
    string plainText = "keepgoingnevergiveup";
    cout << encryptor.Enc("Caesar", plainText, 7) << endl;
    cout << encryptor.Enc("Monoalphabetic", plainText, "qwertyuiopasdfghjklzxcvbnm") << endl;
    cout << encryptor.Enc("Playfair","hidethegoldinthetreestump","playfairexample") << endl;
    
    cout << encryptor.Enc("Vernam","helo","xmcl") << endl;
    cout << encryptor.Enc("RowTrans", "wearediscoveredfleeatonce", "632415") << endl;
    return 0;
}

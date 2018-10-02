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
    /*
    string plainText = "keepgoingnevergiveup";
    cout << encryptor.Enc("Caesar", plainText, 7) << endl;
    cout << encryptor.Enc("Monoalphabetic", plainText, "qwertyuiopasdfghjklzxcvbnm") << endl;
    cout << encryptor.Enc("Playfair","hidethegoldinthetreestump","playfairexample") << endl;
    
    cout << encryptor.Enc("Vernam","helo","xmcl") << endl;
    cout << encryptor.Enc("RowTrans", "wearediscoveredfleeatonce", "632415") << endl;*/
    
    vector<int> key = {15,11,19,18,16,3,7,14,2,20,4,12,9,6,1,5,17,13,10,8};
    cout << encryptor.Enc("Product", "thestrengthofthispig", key) << endl;
    return 0;
}

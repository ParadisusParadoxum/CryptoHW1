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
using std::cin;
using std::endl;

int main(int argc, const char * argv[]) {
    Encryptor encryptor;
    string cmd,plainText;
    int method,iKey,key_size;
    string sKey;
    vector<int> aKey;
    cout << "E)Encrypt\n";
    cout << "D)Decrypt\n";
    while(cin >> cmd){
        if(cmd == "E"){
            cout << "1) Caesar Cipher\n";
            cout << "2) Monoalphabetic Cipher\n";
            cout << "3) Playfair Cipher\n";
            cout << "4) Vernam Cipher\n";
            cout << "5) Transposition Cipher\n";
            cout << "6) Product Cipher\n";
            cin >> method;
            
            switch (method) {
                case 1:
                    
                    cin >> plainText >> iKey;
                    cout << encryptor.Enc("Caesar", plainText, iKey) << endl;
                    break;
                case 2:
                    cin  >> plainText >> sKey;
                    cout << encryptor.Enc("Monoalphabetic",plainText,sKey)<< endl;
                    break;
                case 3:
                    cin  >> plainText >> sKey;
                    cout << encryptor.Enc("Playfair",plainText,sKey)<< endl;
                    break;
                case 4:
                    cin  >> plainText >> sKey;
                    cout << encryptor.Enc("Vernam",plainText,sKey)<< endl;
                    break;
                case 5:
                    cin  >> plainText >> sKey;
                    cout << encryptor.Enc("RowTrans",plainText,sKey)<< endl;
                    break;
                case 6:
                    cin >> plainText >> key_size;
                    aKey.resize(key_size);
                    for(int i=0;i<key_size;++i)
                        cin >> aKey[i];
                    cout << encryptor.Enc("Product", plainText,aKey)<< endl;
                default:
                    cout << "Wrong input\n";
                    break;
            }
            
        }else if(cmd == "D"){
            // you code here
        }else{
            cout << "exit\n";
            break;
        }
        cout << "E)Encrypt\n";
        cout << "D)Decrypt\n";
    }
    return 0;
}

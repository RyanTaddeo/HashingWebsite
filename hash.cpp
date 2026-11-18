//opening comment

#include "hash.h"

#include <string>

using namespace std;



//tentative hashing

int HashScheme::hashMsg(string plaintext, string privateKey){
    int result =0;
    //add the squares of the ascii values of each character in the plaintext

    for(int i =0; i < plaintext.length(); i++){
        int temp = static_cast<int>(plaintext[i]);
        temp = temp*temp;
        result += temp;
    }


    //add the squares of the ascii value of each char in the key
    for(int i =0; i < privateKey.length(); i++){
        int temp = static_cast<int>(privateKey[i]);
        temp *= temp;
        result += temp;
    }


    //mod it by 1066
    result %= 1066;

    return result;
}
        
HashScheme::HashScheme(){}

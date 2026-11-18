//opening comment

#include "message.h"
#include "hash.h"
#include <string>

using namespace std;

void Message::setPlaintext(string newPlaintext){
    body = newPlaintext;
}
void  Message::setId(int newID){
    publicID=newID;
}
string  Message::getBody(){
    return body;
}
int  Message::getHash(){
    return hash;
}
int  Message::getId(){
    return publicID;
}
 Message::Message(string plaintext, int publicKey, string privateKey){
    body = plaintext;
    publicID = publicKey;

    HashScheme scheme;

    hash = scheme.hashMsg(plaintext, privateKey);
}

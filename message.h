// OPENING COMMENT

#ifndef MESSAGE_H
#define MESSAGE_H

#include "hash.h"
#include <string>

using namespace std;

class Message {

    private:
        string body;
        int hash;
        int publicID;
        //IMPLEMENT MESSAGE HERE


    public:
        void setPlaintext(string newPlaintext); 
        void setId(int newID);
        string getBody();
        int getHash();
        int getId();
        Message(string plaintext, int publicKey, string privateKey);
};



#endif
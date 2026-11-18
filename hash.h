//

#ifndef HASH_H
#define HASH_H

#include <string>
using namespace std;

class HashScheme {
    private:
        

    public:
        int hashMsg(string plaintext, string privateKey);
        
        HashScheme();

};


#endif
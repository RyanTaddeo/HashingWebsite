//OPENING COMMENT

#include "hash.h"
#include "message.h"
#include <iostream>
#include <string>


using namespace std;

string key(int ID);
Message user(int id);
Message adversay(Message input);
void reciever(Message input);


int main(){

    int id =0;
    
    do{
        cout<<"Which user(1-10) will be sending the message?"<<endl;
        cin>>id;
        if(!(id>=1) || !(id<=10)){
            cout<<"Error: Invalid User ID, try again."<<endl;
        }
    }while(!(id>=1) || !(id<=10));
    
    reciever(adversay(user(id)));
    //I love this one line. There's beauty in it
    //three separate function calls in a single line, each one the input for the next



    return 0;
}

string key(int ID){
    string arr[10]= {"ABCD1234", "B234", "4321", "6767", "2480", "PQrs", "Private Key", "Placeholder1234", "9th thing here", "final privatekey"};
    //returns the private key for this ID

    return arr[ID-1];
}

Message user(int id){
    cout<<"Hello user " << id<<", your secret key is: "<<key(id)<<endl;
    cout<<"Please enter your message:"<<endl;
    cin.ignore();
    string plaintext;
    getline(cin, plaintext);

    Message send(plaintext, id, key(id));

    return send;
}

Message adversay(Message input){

    cout<<"The Adversary has intercepted the message"<<endl;
    char choice;
    do{
        cout<<"Hello Adversary, would you like to view the message? (y/n)"<<endl;
        
        cin >> choice;

        // Convert input to lowercase so 'Y' and 'y' act the same
        choice = tolower(static_cast<unsigned char>(choice));

        if((choice != 'y')&&(choice != 'n')){
            cout<<"Invalid input, try again."<<endl;
        }
    
    }while(choice != 'y' && choice != 'n');

    if(choice == 'n'){
        return input;
    }else{

        cout<<"Message body: "<<input.getBody()<<endl;
        cout<<"Sender ID: "<<input.getId()<<endl;
        char decision;
        do{
            cout<<"Would you like to change the body (1), the ID (2), or neither (n)?"<<endl;
            cin >> decision;
            decision = tolower(static_cast<unsigned char>(decision));

            if((decision!='1') && (decision!='2') && (decision!='n')){
                cout<<"Invalid input, try again."<<endl;
            }
        }while(decision!='1' && decision!='2' && decision!='n');

        if(decision == 'n'){
            return input;
        }

        if (decision=='1'){
            cout<<"Enter new message body: "<<endl;

            cin.ignore();
            string plaintext;
            getline(cin, plaintext);

            input.setPlaintext(plaintext);
            return input;
        }

        if (decision=='2'){
            cout<<"Enter new message ID: "<<endl;
            int id;
            cin>>id;

            input.setId(id);
            return input;
        }

        //return input;
    }

    return input;
}

void reciever(Message input){

    HashScheme scheme;
    cout<<"RECIEVER HAS RECIEVED A MESSAGE, BEGINNING AUTHENTICATION"<<endl;



    int verify = scheme.hashMsg(input.getBody(), key(input.getId()));

    if (input.getHash()!=verify){
        cout<<"MESSAGE DID NOT PASS AUTHENTICATION! CONTENTS DISCARDED!"<<endl;
        return;
    }

    cout << "AUTHENTICATION PASSED"<<endl;
    cout<<"MESSAGE BODY: "<< input.getBody()<<endl;
    cout<<"CORESPONDING HASH: "<< input.getHash()<<endl;
    cout<<"SENDER ID: "<< input.getId()<<endl;
}
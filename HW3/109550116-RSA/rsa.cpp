#include <iostream>
#include <cryptopp/rsa.h>
#include <cryptopp/osrng.h>
#include <cryptopp/integer.h>
#include <cryptopp/modarith.h>
#include <string>
#include <sstream>
#include <stdio.h>
#include <fstream>
using namespace std;
using namespace CryptoPP;
int main(){

    Integer n("0xc963f963d93559ff"), e("0x11");
    //cout<<n<<"\n";
    RSA::PublicKey pubKey;
    pubKey.Initialize(n, e);
    string message = "ElGamal";
    Integer m((const byte *)message.data(), message.size());
    Integer c = pubKey.ApplyFunction(m);
    //cout << "c: " << hex << c << endl;

    Integer n1("0x04823f9fe38141d93f1244be161b20f"), e1("0x11");
    RSA::PublicKey pubKey1;
    pubKey1.Initialize(n1, e1);
    string message1 = "Hello World!";
    Integer m1((const byte *)message1.data(), message1.size());
    Integer c1 = pubKey1.ApplyFunction(m1);
    cout << "c: " << hex << c1 << endl;

    Integer n2("0x9711ea5183d50d6a91114f1d7574cd52621b35499b4d3563ec95406a994099c9"), e2("0x10001");
    RSA::PublicKey pubKey2;
    pubKey2.Initialize(n2, e2);
    string message2 = "RSA is public key.";
    Integer m2((const byte *)message2.data(), message2.size());
    Integer c2 = pubKey2.ApplyFunction(m2);
    cout << "c: " << hex << c2 << endl;

    AutoSeededRandomPool prng;
    //53a0a95b089cf23adb5cc73f076fa55h;
    Integer j("0xc4b361851de35f080d3ca7352cbf372d"), e3("0x1d35"), d3("0x53a0a95b089cf23adb5cc73f0700000"),df;
    ModularArithmetic ma(j);
    Integer n5("0x10");
    long int h=16*16*16*16*16;
        for (int i=0;i<h;i++){
            //RSA::PrivateKey privKey;
            //privKey.Initialize(j, e3, d3);
            Integer temp = e3*(d3+i);

            Integer r =ma.Exponentiate(n5, temp);
            if(r==n5){
                df=d3+i;
                cout<<"private key :"<<d3+i<<endl;
                break;
            }
            
    }
    RSA::PrivateKey privKey;
    privKey.Initialize(j, e3, df);
    Integer l("0xa02d51d0e87efe1defc19f3ee899c31d");
    Integer r = privKey.CalculateInverse(prng, l);
    //cout <<"r:" << hex << r << endl;
    string recovered;
    size_t req = r.MinEncodedSize();
    recovered.resize(req);
    r.Encode((byte *) &recovered[0], recovered.size());
    cout << "recovered: " << recovered << endl;	
            

    
/*Integer n6("0xbeaadb3d839f3b5f"), e6("0x11"), d6("0x21a5ae37b9959db9");
AutoSeededRandomPool prng6;

RSA::PrivateKey privKey6;
privKey6.Initialize(n6, e6, d6);

/////////////////////////////////////////////////////////

Integer c6(0x3f47c32e8e17e291), r6;
string recovered6;

// Decrypt
r6 = privKey6.CalculateInverse(prng6, c6);
cout <<"r:" << hex << r6 << endl;

// Round trip the message
size_t req6 = r6.MinEncodedSize();
recovered6.resize(req6);
r6.Encode((byte *)recovered6.data(), recovered6.size());

cout <<"recovered:" << recovered6 << endl;*/
        

}
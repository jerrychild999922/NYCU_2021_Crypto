#include <iostream>
#include <fstream>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/algparam.h>

using namespace std;

// http://www.cryptopp.com/
// sudo apt-get install libcrypto++-dev
// $ g++ main.cpp -lcryptopp

int main (){
    ofstream myfile1;
    myfile1.open("aes-out.txt", ios_base::trunc);
    myfile1.close();

    CryptoPP::byte key[ CryptoPP::AES::DEFAULT_KEYLENGTH ], iv[ CryptoPP::AES::BLOCKSIZE ];
    memset( key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH );
    // let key = 00000000000....
    memset( iv, 0x00, CryptoPP::AES::BLOCKSIZE );
    // let iv = 0000000000...

    string plaintext = "AES is the US block cipher standard.";
    string ciphertext1;
    string ciphertext2;
    string ciphertext3;
    string ciphertext4;


    char tmpIV[] = "0000000000000000";
    char tmpK[] = "keyis84932731830";
        
        for (int j = 0; j < CryptoPP::AES::DEFAULT_KEYLENGTH; ++j)
        {
                key[j] = tmpK[j];

        }


        for (int i = 0; i < CryptoPP::AES::BLOCKSIZE; ++i)
        {
            iv[i] = tmpIV[i];
        }
        //===============================CTB==================================//
        CryptoPP::AES::Encryption en(key,CryptoPP::AES::DEFAULT_KEYLENGTH);
        CryptoPP::CFB_Mode_ExternalCipher::Encryption cfb(en,iv,4);

        CryptoPP::StringSource ss1( plaintext, true,
        new CryptoPP::StreamTransformationFilter( cfb,
            new CryptoPP::StringSink( ciphertext1 ),
            CryptoPP::BlockPaddingSchemeDef::NO_PADDING
            ) 
        ); 

        myfile1.open("aes-out.txt", ios_base::app);
        for( int i = 0; i < ciphertext1.size(); i++ ) {
            myfile1 << hex << (0xFF & static_cast<CryptoPP::byte>(ciphertext1[i])) << " ";
        }
        //cout << endl << endl;
        myfile1<<endl;
        myfile1.close();
        //========================================================================//


        //==================================CBC 0=================================//
        CryptoPP::CBC_Mode< CryptoPP::AES >::Encryption enc2;
        enc2.SetKeyWithIV( key, CryptoPP::AES::DEFAULT_KEYLENGTH, iv, CryptoPP::AES::BLOCKSIZE );

        CryptoPP::StringSource ss( plaintext, true,
        new CryptoPP::StreamTransformationFilter( enc2,
            new CryptoPP::StringSink( ciphertext2 ),
            CryptoPP::BlockPaddingSchemeDef::ZEROS_PADDING
            ) 
        );

        myfile1.open("aes-out.txt", ios_base::app);
        for( int i = 0; i < ciphertext2.size(); i++ ) {
            myfile1 << hex << (0xFF & static_cast<CryptoPP::byte>(ciphertext2[i])) << " ";
        }
        //cout << endl << endl;
        myfile1<<endl;
        myfile1.close();
        //========================================================================//


        //==================================CBC 9=================================//
        for (int i = 0; i < CryptoPP::AES::BLOCKSIZE; ++i)
        {
            iv[i] = '9';
        }
        CryptoPP::CBC_Mode< CryptoPP::AES >::Encryption enc3;
        enc3.SetKeyWithIV( key, CryptoPP::AES::DEFAULT_KEYLENGTH, iv, CryptoPP::AES::BLOCKSIZE );

        CryptoPP::StringSource ss3( plaintext, true,
        new CryptoPP::StreamTransformationFilter( enc3,
            new CryptoPP::StringSink( ciphertext3 ),
            CryptoPP::BlockPaddingSchemeDef::PKCS_PADDING
            ) 
        );

        myfile1.open("aes-out.txt", ios_base::app);
        for( int i = 0; i < ciphertext3.size(); i++ ) {
            myfile1 << hex << (0xFF & static_cast<CryptoPP::byte>(ciphertext3[i])) << " ";
        }
        //cout << endl << endl;
        myfile1<<endl;
        myfile1.close();
        //========================================================================//


        //===============================ECB==================================//
        CryptoPP::ECB_Mode< CryptoPP::AES >::Encryption enc4;
        enc4.SetKey( key, CryptoPP::AES::DEFAULT_KEYLENGTH);

        CryptoPP::StringSource ss4( plaintext, true,
        new CryptoPP::StreamTransformationFilter( enc4,
            new CryptoPP::StringSink( ciphertext4 ),
            CryptoPP::BlockPaddingSchemeDef::PKCS_PADDING
            ) 
        ); 

        myfile1.open("aes-out.txt", ios_base::app);
        for( int i = 0; i < ciphertext4.size(); i++ ) {
            myfile1 << hex << (0xFF & static_cast<CryptoPP::byte>(ciphertext4[i])) << " ";
        }
        //cout << endl << endl;
        myfile1<<endl;
        myfile1.close();
        //========================================================================//
        

        return 0;
        
}
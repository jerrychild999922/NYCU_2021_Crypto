#include <iostream>
#include <cryptopp/sha.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>

#include <string>
#include <sstream>
using namespace std;
using namespace CryptoPP;
HexEncoder encoder(new FileSink(std::cout));

/*std::string SHA256HashString(std::string aString){
    std::string digest;
    CryptoPP::SHA256 hash;

    CryptoPP::StringSource foo(aString, true,
    new CryptoPP::HashFilter(hash,
      new CryptoPP::Base64Encoder (
         new CryptoPP::StringSink(digest))));

    return digest;
}*/
string change(string a){
    string fin;
    for(int i=0;i<a.length()/2;i++){
        int ans=0;
        string temp1=a.substr(2*i,2);
        if(temp1[0]>='0'&&temp1[0]<='9'){
            ans+=(temp1[0]-'0')*16;
        }
        else{
            ans+=(temp1[0]-'A'+10)*16;
        }
        if(temp1[1]>='0'&&temp1[1]<='9'){
            ans+=temp1[1]-'0';
        }
        else{
            ans+=temp1[1]-'A'+10;
        }
        string c;
        c[0]=ans;
        fin=fin+c[0];
        //cout<<fin<<"\n";
    }
    
    return fin;
}
//EC649CC214F866F01A6A319AAB3CC1DDDF3BFF61A431013E10BD68C210272413 already run 109550116's value
int main(){
    string source, value, value1,value2,id;
    SHA256 hash;
    id="109550116";

    StringSource ss3( id, true ,
                    new HashFilter( hash, 
                    new HexEncoder( 
                        new StringSink( value2 )
                    ) // HexEncoder
                    ) // HashFilter
                ); // StringSource






    source=value2+"00000000";
    string a=change(source);

    StringSource ss( a, true ,
                    new HashFilter( hash, 
                    new HexEncoder( 
                        new StringSink( value )
                    ) // HexEncoder
                    ) // HashFilter
                ); // StringSource
    cout<<"0"<<"\n"<<value2<<"\n"<<"00000000"<<"\n"<<value<<"\n";



    string n0,n1,n2,n3,n4,n5,n6,n7,nonce,newhash;
   
    int ter=0;
    string u="0123456789ABCDEF";
    string k;

    for(int j=1;j<10;j++){
        k=k+"0";
        for(int i0=0;i0<16;i0++){
            n0=u[i0];
            for(int i1=0;i1<16;i1++){
                n1=u[i1];
                for(int i2=0;i2<16;i2++){
                    n2=u[i2]; 
                    for(int i3=0;i3<16;i3++){
                        n3=u[i3]; 
                        for(int i4=0;i4<16;i4++){
                            n4=u[i4]; 
                            for(int i5=0;i5<16;i5++){
                                n5=u[i5]; 

                                for(int i6=0;i6<16;i6++){
                                    n6=u[i6]; 
                                    for(int i7=0;i7<16;i7++){
                                        n7=u[i7]; 
                                        string tt=value+n0+n1+n2+n3+n4+n5+n6+n7;
                                        string tt1=change(tt);
                                        string check;
                                        StringSource ss1( tt1, true ,
                                        new HashFilter( hash, 
                                            new HexEncoder( 
                                                new StringSink( check )
                                                ) 
                                            ) 
                                        ); 
                                        if (check.substr(0,j)==k){
                                            nonce=n0+n1+n2+n3+n4+n5+n6+n7;
                                            newhash=check;
                                            ter=1;
                                            break;
                                        }

                                    }
                                    if(ter==1){
                                        break;
                                    }
                                }
                                if(ter==1){
                                    break;
                                }
                            }
                            if(ter==1){
                                break;
                            }
                        }
                        if(ter==1){
                            break;
                        }
                    }
                    if(ter==1){
                        break;
                    }
                }
                if(ter==1){
                    break;
                } 
            }
            if(ter==1){
                break;
            }
        }
        if(ter==0){
            cout<<"cant find.";
        }
        cout<<j<<"\n";
        cout<<value<<"\n";
        cout<<nonce<<"\n";
        cout<<newhash<<"\n";

        value=newhash;
        ter=0;

    }

}
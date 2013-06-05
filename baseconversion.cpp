#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int decimal_to_binary(int dec);
int binary_to_decimal(int bin);

int hex_to_decimal(string hex_in);
int hexCharToDec(char c); //helper function

string dec_to_hex(int dec);
char to_hex_ch(int hex_val); //helper function

int main()
{
    cout <<"dec to bin"<<endl;
    cout<<"dec 123 = bin " <<decimal_to_binary(123)<<endl;
    cout<<"bin to dec"<<endl;
    cout<<"bin 101101 = dec "<<binary_to_decimal(101101)<<endl;
    cout<<"dec to hex"<<endl;
    cout<<"dec 4567 = hex "<<dec_to_hex(4567)<<endl;
    cout<<"hex to dec"<<endl;
    cout<<"hex ABC1 = dec "<<hex_to_decimal("ABC1")<<endl;

    return 0;
}





int binary_to_decimal(int bin)
{
    int result=0;
    int multiplier=1;

    while(bin>0)
    {
        result+=bin%10*multiplier;
        multiplier*=2;
        bin/=10;
    }

    return result;
}

int decimal_to_binary(int dec)
{
    int result=0;
    int multiplier=1;

    while(dec>0)
    {
        result+=dec%2*multiplier;
        multiplier*=10;
        dec/=2;
    }

    return result;
}

string dec_to_hex(int dec)
{
    string hex = "";

    while (dec != 0)
    {
        int hex_val = dec%16;
        hex = to_hex_ch(hex_val)+ hex;
        dec /= 16;
    }
    return hex;

}

char to_hex_ch(int hex_val)
{
    if(hex_val>=0 && hex_val<=9 )
        return char(hex_val + '0');
    else
        return char(hex_val - 10) + 'A';
}




int hexCharToDec(char c)
{
    if(c >= 'A' && c <= 'F')
        return 10 + (c - 'A');
    else // 0 - 9
        return c - '0';
}


int hex_to_decimal(string hex_in)
{
    int dec = 0;

    for(unsigned int i = 0; i < hex_in.length(); i++)
    {
        char hexChar = hex_in[i];
        dec = dec * 16  + hexCharToDec(hexChar);
    }
    return dec;

}

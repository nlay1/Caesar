#include<iostream>
#include<fstream>
#include "Caesar.h"

const int shift = 3;

Caesar::Caesar()
{
    menu();
}

void Caesar::menu()
{
    std::cout << "What would you like to do?\n0-----decode\n1-----encode\n";
    unsigned short flag;
    std::cin >> flag;
    std::cout << "Enter the file name: ";
    std::string fname;
    std::cin >> fname;

    switch (flag)
    {
    case 0:
        decode(fname);
        break;
    case 1: 
        encode(fname);
        break;
    default:
        std::cout << "invalid number\n";
        break;
    } 

}

void Caesar::encode(std::string& fname)
{
    std::ifstream fin;
    fin.open(fname);
    std::ofstream fout;
    fout.open("decode.txt");

    while(fin)
    {
        std::string line; 
        getline(fin, line);
        for(char ch : line)
        {
            if(ch == ' ') continue;
            if(ch == '\n') fout << "\n";
            fout << (isupper(ch)) ? (char(int(ch+shift-65)%26 +65)) : 
            (char(int(ch + shift-97)%26 +97));
        }
    }
    fout.close();
    fin.close();
}

void Caesar::decode(std::string& fname)
{
    std::ifstream fin;
    fin.open(fname);
    std::ofstream fout;
    fout.open("encode.txt");

    while(fin)
    {
        std::string line; 
        getline(fin, line);
        for(char ch : line)
        {
            if(ch == ' ') continue;
            fout << (isupper(ch)) ? (char(int(ch - shift -65) % 26 + 65)) : 
            (char(int(ch - shift - 97) % 26 +97));
        }
    }
    fout.close();
    fin.close();
}
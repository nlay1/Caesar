#ifndef __CYPHER
#define __CYPHER

#include<string>

class Caesar
{
public:
    Caesar();
    Caesar(const Caesar& oth) = delete;
    Caesar& operator=(const Caesar& rhs) = delete;
private:
    void menu();
private:
    void encode(std::string&);
    void decode(std::string&);
};

#endif
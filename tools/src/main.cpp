#include <map>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>


int main(int argc, char *argv[])
{
    int diff = 'A' - 'a';
    char c[] = "HaB";
    std::transform(c, c+strlen(c), c, tolower);
    std::cout<<c;
    std::cout << pow(2,2)<< std::endl;
    std::string str;
    return 0;
}

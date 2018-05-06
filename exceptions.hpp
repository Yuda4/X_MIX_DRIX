#include <iostream>
using namespace std;
#include <exception>
#include <string>

class IllegalCoordinateException : public exception {
    int first;
    int second;
    public:
        const char* theCoordinate() const throw (){ return (to_string(first) + ',' +to_string(second) + '\n').c_str(); }
        void set_first(int first){ this-> first = first; }
        void set_second(int second){ this-> second = second; }
};

class IllegalCharException : public exception {
    char illegal;
    public:
        const char* theChar() const throw (){
            const char* c = &illegal;
            return c;
        }
        void set_illegal(char illegal){ this-> illegal = illegal; }
};

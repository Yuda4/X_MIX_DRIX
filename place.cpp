#include "place.hpp"

place :: place(){
    this-> sign = '.';
}

place :: place(char sign){
    if (sign != 'X' && sign != 'O' && sign != '.'){
        IllegalCharException ichar;
        ichar.set_illegal(sign);
        throw ichar; }
    this-> sign = sign;
}

place :: place(place& other){
    this-> sign = other.sign;
}
        
char place :: get_sign(){
    return this -> sign;
}
void place :: set_sign(char sign){
    if (sign != 'X' && sign != 'O' && sign != '.'){
        IllegalCharException ichar;
        ichar.set_illegal(sign);
        throw ichar; }
        this-> sign = sign;
}

place& place ::  operator= (char sign){
    this-> set_sign(sign);
    return *this;
}

place& place :: operator= (place& other){
    this->set_sign(other.get_sign());
    return *this;
}
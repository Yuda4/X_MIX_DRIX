#ifndef _PLACE_HPP
#define _PLACE_HPP
#include "exceptions.hpp"
#endif

class place{
    private:
        char sign;
    
    public:
        place();
        place(char);
        place(place&);

        char get_sign(void);
        void set_sign(char);
        place& operator= (char);
        place& operator= (place&);
        bool operator==(place) const;
        bool operator!=(place) const;
        bool operator==(const char&) const;
        bool operator!=(const char&) const;
        
        friend ostream& operator<<(ostream&, place&);
};

inline bool operator==(const char& nMember,place member){ return nMember == member.get_sign(); }
inline bool operator!=(const char& nMember,place member){ return nMember != member.get_sign();}

inline ostream& operator<<(ostream& os, place& plc){
	    os << plc.get_sign() << endl;
        return os;
    }
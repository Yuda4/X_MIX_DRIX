#include "exceptions.hpp"

class place{
    private:
        char sign;
    
    public:
        place();
        place(char);
        place(place&);

        char get_sign();
        void set_sign(char);
        place& operator= (char);
        place& operator= (place&);
        friend ostream& operator<<(ostream&, place&);
};

inline ostream& operator<<(ostream& os, place& plc){
	    os << plc.get_sign() << endl;
        return os;
    }
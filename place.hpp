#include "exceptions.cpp"

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
        bool operator==(place other) const;
        bool operator!=(place other) const;
        bool operator==(const char& ch) const;
        bool operator!=(const char& ch) const;
        
        friend ostream& operator<<(ostream&, place&);
};

inline bool operator==(const char& nMember,place member){ return nMember == member.get_sign(); }
inline bool operator!=(const char& nMember,place member){ return nMember != member.get_sign();}

inline ostream& operator<<(ostream& os, place& plc){
	    os << plc.get_sign() << endl;
        return os;
    }
// Write what you think would be the expect result of compiling and running the following algorithm:

class Alpha { 
public: 
    virtual int value() = 0; 
}; 
class Beta : public Alpha { 
public:
	int value(void) { 
		return 0;
	}
}; 
class Gama : public Beta  {
public:
	int value(void) { 
		return 1;
	}
}; 
class Epsilon { 
public: 
    virtual void print() const = 0; 
}; 
class Zeta : virtual public Epsilon { 
public: 
    void print() const
    { 
        cout << "1"; 
    } 
}; 
class Teta : virtual public Epsilon { 
public: 
    void print() const
    { 
        cout << "2"; 
    } 
}; 
class Kappa : public Zeta, Teta { 
public: 
    void print() const
    { 
        Teta::print(); 
    } 
};   
int main(void) 
{ 
    Alpha a; 
	cout << a.value(); 
	Beta* b = new Gama(); 
	cout << b->value(); 
    Kappa both; 
    Zeta one; 
    Teta two; 
    Epsilon* delta[3]; 
    delta[0] = &both; 
    delta[1] = &one; 
    delta[2] = &two; 
    for (int i = 0; i < 3; i++) 
        delta[i]->print(); 
    return 0; 
}
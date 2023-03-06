#include <iostream>
#include <vector>
class Perete{
private:
    int coor_x, coor_y;
public:
    explicit Perete( int coor_x_=0, int coor_y_=0) : coor_x{coor_x_}, coor_y{coor_y_} {
        std:: cout<<"constructor de initializere al clasei Perete\n";
    }
    Perete( const Perete& other ) : coor_x{other.coor_x}, coor_y{other.coor_y}{
        std:: cout<<"constructor de copiere al clasei Perete\n";
    }
    Perete& operator=(const Perete& other) {
        coor_x= other.coor_x;
        coor_y= other.coor_y;
        std :: cout<<"operator = de copiere al clasei Perete\n";
        return *this;
    }
    ~Perete(){
        std:: cout<<"Destructorul clasei Perete\n";
    }

    friend std :: ostream& operator<<(std::ostream& os, const Perete& perete){
        os<<"La coordonatele x= "<<perete.coor_x<<" si y= "<<perete.coor_y<<" este un perete\n";
        return os;
    }

};

class Tabla{
private:
    int dimensiune;
    std::vector <Perete> vec;
public:
    explicit Tabla( int dimensiune_=4, const std::vector <Perete>& vec_ = {Perete{1,2}, Perete{4,5}, Perete{1,3},Perete{6,5}} ) :
            dimensiune{dimensiune_}, vec{vec_}{
        std :: cout<<"Constructor de initializere al clasei Tabla\n";
    }
    Tabla( const Tabla& other ) : dimensiune{other.dimensiune}, vec{other.vec}{
        std :: cout<<"Constructor de copiere al clasei Tabla\n";
    }
    Tabla& operator=(const Tabla& other) {
        dimensiune= other.dimensiune;
        vec = other.vec;
        std :: cout<<"operator = de copiere al clasei Tabla\n";
        return *this;
    }
    ~Tabla(){
        std:: cout<<"Destructorul clasei Tabla\n";
    }
    friend std :: ostream& operator<<(std::ostream& os, const Tabla& tabla){
        os << "Tabla are dimensiunea:" << tabla.dimensiune<< " \n";
        return os;
    }
};


class Joc{
private:
    int nivel;
    int timer;
public:
    explicit Joc(  int nivel_=1, int timer_=0) :  nivel{nivel_}, timer(timer_){
        std:: cout<<"constructor de initializare al clasei Joc\n";
    }
    Joc ( const Joc& other ) :  nivel{other.nivel}, timer(other.timer){
        std:: cout<<"constructor de copiere al clasei Joc\n";
    }
    Joc& operator=(const Joc& other) {
        nivel = other.nivel;
        timer = other.timer;
        std :: cout<<"operator = de copiere al clasei Joc\n";
        return *this;
    }
    ~Joc(){
        std:: cout<<"Destructorul clasei Joc\n";
    }
    friend std :: ostream& operator<<(std::ostream& os, const Joc& joc) {
        os << "Nivelul jocului este " << joc.nivel << " iar timpul este: " << joc.timer << " \n";
        return os;
    }
};


int main()
{
    Tabla tabla;
    Joc joc;
    std:: cout<<tabla;
    std:: cout<<joc;
    return 0;
}



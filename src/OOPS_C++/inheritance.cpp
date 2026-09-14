//inheritance (one class acquiring the properties of another class)

//access modifiers
//public (access everywhere)
//private (only within the class)
//protected (within the class and derived classes)

//example
class Animal{
    public:
        string name;
        string species;

        Animal(){
            name = "";
            species = "";
        }

        Animal(string name,string species){
            this->name = name;
            this->species = species;
        }

        void sleep(){
            cout<< "Sleeping..."<<endl;
        }
};

class Dog : protected Animal{
    public: //we can access protected members of base class
    
        Dog(string name, string species): Animal(name,species){}
        void bark(){
            cout<< "Barking..."<<endl;
        }
};

class Cat : private Animal{
    public://we can access private members of base class

        Cat(string name, string species): Animal(name,species){}
        void meow(){
            cout<< "Meowing..."<<endl;
        }
};

int main(){ 
    Dog d1("Buddy","Canine");
    d1.sleep();
    d1.bark();

    Cat c1("Whiskers","Feline");
    c1.sleep();
    c1.meow();
    return 0;
}
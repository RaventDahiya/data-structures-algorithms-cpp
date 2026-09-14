//encapsulation (binding of data and functions used for hiding data from outside)

//example:-
class Student{
    private:
        string name;
        int roll_no;
        int age;
        bool is_enrolled;

    public://getter methods
        string get_name(){
            return name;
        }
        int get_roll_no(){
            return roll_no;
        }
        int get_age(){
            return age;
        }
        bool get_is_enrolled(){
            return is_enrolled;
        }

        //setter methods
        void set_name(string name){
            this -> name = name;
        }
        void set_roll_no(int roll_no){
            this -> roll_no = roll_no;
        }
        void set_age(int age){
            this -> age = age;
        }
        void set_is_enrolled(bool is_enrolled){
            this -> is_enrolled = is_enrolled;
        }
            
        Student( ){
            name = "Unknown";
            roll_no = 0;
            age = 0;
            is_enrolled = false;
        }

        Student(string name,int roll ,int age,bool is_enrolled){
            this -> name = name;
            this -> roll_no = roll;
            this -> age = age;
            this -> is_enrolled = is_enrolled;
        }

        void print_student_details(){
            cout<< name<<endl;
            cout<< roll_no<<endl;
            cout<< age<<endl;
            cout<< is_enrolled<<endl;
        }

        ~Student(){
            cout<< "Destructor called!"<<endl;
        }
    
};  
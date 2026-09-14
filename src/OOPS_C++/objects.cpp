#include <bits/stdc++.h>
using namespace std;

class Student{
    private:
        string name;
        int roll_no;
        int age;
        bool is_enrolled;

    public:
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
        //copy constructor
        Student(const Student &s){
            this -> name = s.name;
            this -> roll_no = s.roll_no;
            this -> age = s.age;
            this -> is_enrolled = s.is_enrolled;
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

int main(){
    Student s1("Yash", 21, 22, true);bnm
    s1.print_student_details();,

    Student s2("Yash", 21, 22, true);
    s2.print_student_details();

    Student s3("Yash", 21, 22, true);
    s3.print_student_details();

    Student s4("Yash", 21, 22, true);
    s4.print_student_details();

    Student s5("Yash", 21, 22, true);
    s5.print_student_details();
    
    //copy constructor call
    Student s6(s1);
    //or
    Student s7 = s1;
    s6.print_student_details();
    
    //dynamic allocation of objects
    Student *s8 = new Student();
    s8->print_student_details();
    delete s8; //destructor will be called manually.
    

    return 0;
}
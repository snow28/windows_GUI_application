#include <iostream>
#include <deque>
#include <list>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

int INDEX =1;


class Person{
private:
    string name;
    string surname;
    int age;
    char gender;
    string dateOfBirth;
public:
    Person(){}
    Person(string name, string surname , int age, char gender, string date){
        this->name = name;
        this->surname = surname;
        this->age = age;
        this->gender = gender;
        dateOfBirth = date;
    }

    string getInfoPerson(){
        stringstream ss;
        ss << age;
        string str = ss.str();
        string returnString = "Name : " + name + "; Surname : " + surname +  "; age : " + str + "; Gender : " + gender + "; Date of birth : " + dateOfBirth;
        return returnString;
    }
    string getName(){
        return name + " " + surname;
    }
};


class Employee : public Person{
private:
    string title;
    string function;
public:
    Employee(string name, string surname , int age, char gender, string date , string t , string f):Person(name,surname,age,gender,date){
        title = t;
        function = f;
    }
    string showInfo(){
        string personInfo = getInfoPerson();
        string employeeInfo = " ; Title : " + title + "; Function : " + function;
        return personInfo + employeeInfo;
    }

};


class Student: public Person{
private:
    int index;
    string direction;
public:
    Student(string name, string surname , int age, char gender, string date, string direction):Person(name,surname,age,gender,date){
        index = INDEX;
        this->direction = direction;
        INDEX++;
    }

    int getIndex(){
        return index;
    }
    string getInfo(){
        stringstream ss;
        ss << index;
        string str = ss.str();
        string parentInfo = getInfoPerson();
        return parentInfo + "||" + "Index : " + str + ". Direction : "+direction;
    }

};


class Course{
private:
    string name;
    deque<double> points;
    deque<int> listOfStudents;
    Employee *employee;
    int length;
public:
    Course(string name,  Employee *e){
        length = 0;
        this->name = name;
        this->points = points;
        this->employee = e;
    }
    void addStudent(Student s){
        length++;
        listOfStudents.push_back(s.getIndex());
        points.push_back(0);

    }
    string getName(){
        return name;
    }
    void showInfo(){
        cout<<"Name : " + name<<endl;
        for(int x=0;x<length; x++){
            stringstream mark,index;
            mark << points[x];
            index << listOfStudents[x] ;
            string markFinal = mark.str();
            string indexFinal = index.str();
            cout<< "Index : " + indexFinal + ". Mark : " + markFinal <<endl;
        }
    }

};

class Assessment{
private:
    Student *student;
    Course *course;
    double assessment;
public:
    Assessment(Student *s , Course *c){
        student=s;
        course=c;
        assessment=0;
    }
    Student* getStudent(){
        return student;
    }

    string getCourseName(){
        return course->getName();
    }

    double getAssessment(){
        return assessment;
    }

    int getIndex(){
        return student->getIndex();
    }

    void changeMark(double m){
        assessment = m;
    }

    string stringAssessment(){
        string studentInfo = student->getInfo();
        string courseInfo ="s";
        stringstream ss;
        ss << assessment;
        string str = ss.str();
        string tmp = "student:" + studentInfo + ". Course ";
        course->showInfo();
        return tmp;
    }

};


class EvList{
private:
    string deadline;
    int length;
public:
    deque<Assessment> listOfAssesment;

    EvList(string d){
        length = 0;
        deadline = d;
    }
    void addAssessment(Student *s, Course *c){
        length++;
        Assessment *a = new Assessment(s,c);
        listOfAssesment.push_back(*a);
    }
    int getLength(){
        return length;
    }

    void changeMark(int index , double mark , string courseName , int size){
        for(int x=0; x<size ; x++){
            if(listOfAssesment[x].getCourseName() == courseName && listOfAssesment[x].getIndex()){
                listOfAssesment[x].changeMark(mark);
            }
        }
    }

    Assessment getAssessment(int index){
        return listOfAssesment.at(index);
    }

    void showEvList(){
        for(int x=0; x < length; x++){
            string s = listOfAssesment.at(x).stringAssessment();
            cout<<s<<endl;
        }
    }

};


int main(){

    //                          STUDENTS
    Student *one = new Student("Dmytro","Kachailo", 20 , 'M' , "28.09.1997" , "Computer Science");
    Student *two = new Student("Anya","Herzab", 26 , 'M' , "28.01.1999" , "Biology");
    Student *three = new Student("Achmed","Blacker", 5 , 'M' , "08.10.1967" , "Computer Science");
    Student *four = new Student("Tomash","Occal", 19 , 'M' , "28.09.1997" , "Biology");
    Student *five = new Student("Lukash","Something", 20 , 'M' , "28.09.1997" , "Computer Science");

    Student *students[5]={one,two,three,four,five};


    //                    EMPLOYEE
    Employee *csEmployee = new Employee("John","Maccantry",73,'M',"22.05.1920" , "front-end" , "developer");
    Employee *bioEmployee = new Employee("Anit","Vanduver", 24 ,'F',"01.01.1320" , "medical" , "Biolog");


    //                     COURSES
    Course *ComputerScience = new Course("Computer Science" , csEmployee);
    Course *Biology = new Course("Biology",bioEmployee);
    Course *Logic = new Course("Logic"  , csEmployee);

    Course *courses[3]={ComputerScience,Biology,Logic};





    //                            Filling with data our objects
    for(int x=0;x<5;x++){
        courses[0]->addStudent(*students[x]);
        courses[1]->addStudent(*students[x]);
        courses[2]->addStudent(*students[x]);
    }


    EvList *evList = new EvList("25.06.2018");

    /*for(int x=0;x<5;x++){
        for(int z=3;x<3;z++){
            evList->addAssessment(&*students[x],&*courses[z]);
        }
    }*/

    evList->addAssessment(one,ComputerScience);
    evList->addAssessment(two,ComputerScience);
    evList->addAssessment(three,ComputerScience);
    evList->addAssessment(four,ComputerScience);
    evList->addAssessment(five,ComputerScience);

    evList->addAssessment(one,Biology);
    evList->addAssessment(two,Biology);
    evList->addAssessment(three,Biology);
    evList->addAssessment(four,Biology);
    evList->addAssessment(five,Biology);

    evList->addAssessment(one,Logic);
    evList->addAssessment(two,Logic);
    evList->addAssessment(three,Logic);
    evList->addAssessment(four,Logic);
    evList->addAssessment(five,Logic);

    //evList->showEvList();

    int trigger = 0;   //i will use this variable to loop our function
    srand (time(NULL)); // for random generating
    int numberOfStudents = 5;

    while(trigger == 0){
        cout<<"Input : S - student, E - employee"<<endl;
        char mode;
        cin>>mode;
        if(mode == 'S'){
            trigger=1;
            int studentIndex;
            cout<<"Enter student index:"<<endl;
            cin>>studentIndex;
            if( studentIndex <= numberOfStudents-1 &&  studentIndex >= 0){
                cout<<"Type M - for marks, Q - quit"<<endl;
                char value;
                cin>>value;
                if(value != 'M' && value != 'Q'){
                    cout<<"You entered wrong parameter!"<<endl<<endl;
                    trigger = 0;
                }else{
                    for(int x=0; x < evList->getLength(); x++){
                        if(evList->listOfAssesment.at(x).getStudent()->getIndex() == studentIndex){
                            string courseName =  evList->listOfAssesment.at(x).getCourseName();
                            double mark = evList->listOfAssesment.at(x).getAssessment();
                            stringstream m;
                            m<<mark;
                            string markFinal = m.str();
                            cout<<"Course name : " + courseName + ". Mark : " + markFinal<<endl<<endl;
                        }
                    }
                    trigger = 0;
                }
            }else{
                cout<<"You entered wrong index!"<<endl<<endl;
                trigger = 0;
            }
        }else if(mode == 'E'){
            cout<<"Enter 'c'->ComputerScience , 'b'->Biology"<<endl;
            char em;
            cin>>em;
            if(em == 'c'){
                cout<<"Hello Mr." + csEmployee->getName()<<endl;
                cout<<"Enter student ID to change his mark:"<<endl;
                int id;
                double mark;
                cin>>id;
                cout<<"Input mark:"<<endl;
                cin>>mark;
                cout<<"Choose course : 1-> 'Logic' , 2->'Computer Science'"<<endl;
                int course;
                cin>>course;
                if(course == 1){
                    evList->changeMark(id,mark,"Logic",15);
                }else if(course == 2){
                    evList->changeMark(id,mark,"Computer Science",15);
                }else{
                    cout<<"You entered wrong course number!"<<endl<<endl;
                    trigger=0;
                }
            }else if(em == 'b'){
                cout<<"Hello Mr." + bioEmployee->getName()<<endl;
                cout<<"Enter student ID to change his mark:"<<endl;
                int id;
                double mark;
                cin>>id;
                cout<<"Input mark:"<<endl;
                cin>>mark;
                evList->changeMark(id,mark,"Biology",15);
            }else{
                cout<<"You entered wrong employee name"<<endl<<endl;
                trigger = 0;
            }

            cout<<endl;
        }else{
            cout<<"You entered wrong letter"<<endl<<endl;
        }
    }


    return 0;
}

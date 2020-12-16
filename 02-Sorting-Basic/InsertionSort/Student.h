//
// Created by wzy on 2020/11/30.
//

#ifndef INSERTIONSORT_STUDENT_H
#define INSERTIONSORT_STUDENT_H

#include<iostream>
#include <string>

using namespace std;
struct Student{
    string name;
    int score;

    bool operator<(const Student& otherStudent){
        return (this->score != otherStudent.score)?
        (this->score > otherStudent.score):
        (this->name < otherStudent.name);
    }

    friend ostream& operator<<(ostream &os,const Student &student){
        os<<"Student : "<<student.name<<"  "<<student.score<<endl;
        return os;
    }

};

#endif //SELECTIONSORT_STUDENT_H

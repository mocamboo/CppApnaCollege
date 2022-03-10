#include <bits/stdc++.h>
using namespace std;

class student
{
    int roll;
    string name;
    int mathsMarks;
    int chemMarks;
    int phyMarks;

public:
    student(int roll, string name, int mm, int cm, int pm);
    student(student &s);

    void setRoll(int r);
    void setName(string s);
    void setMarks(int m, int c, int p);
    int getRoll();
    string getName();

    int totalMarks();
    string grade();
};
student::student(student &s)
{
    this->roll = s.roll;
    this->name = s.name;
    this->mathsMarks = s.mathsMarks;
    this->chemMarks = s.chemMarks;
    this->phyMarks = s.phyMarks;
}
void student::setMarks(int l, int c, int p)
{
    mathsMarks = l;
    chemMarks = c;
    phyMarks = p;
}

student::student(int roll, string name, int mm, int cm, int pm)
{
    setRoll(roll);
    setName(name);
    setMarks(mm, cm, pm);
}
int student::totalMarks()
{
    return (mathsMarks + chemMarks + phyMarks);
}
string student::grade()
{
    if (mathsMarks >= 90 && chemMarks >= 90 && phyMarks >= 90)
    {
        return "A+";
    }
    else if (mathsMarks >= 80 && chemMarks >= 80 && phyMarks >= 80)
    {
        return "A";
    }
    else if (mathsMarks >= 70 && chemMarks >= 70 && phyMarks >= 70)
    {
        return "B+";
    }
    else if (mathsMarks >= 60 && chemMarks >= 60 && phyMarks >= 60)
    {
        return "B";
    }
    else if (mathsMarks >= 50 && chemMarks >= 50 && phyMarks >= 50)
    {
        return "C+";
    }
    else if (mathsMarks >= 40 && chemMarks >= 40 && phyMarks >= 40)
    {
        return "C";
    }
    else
    {
        return "F";
    }
}

void student::setRoll(int r)
{
    roll = r;
}
void student::setName(string s)
{
    name = s;
}

int main()
{

    student s(27, "Shubham", 37, 97, 97);
    cout << s.grade() << endl;
    cout << s.totalMarks() << endl;

    return 0;
}
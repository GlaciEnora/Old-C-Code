#include <iostream>
#include <fstream>
using namespace std;

class Student
{
private:
    int roll_no;
    string name;

public:
    void getdata()
    {
        cout << "Enter roll no : ";
        cin >> roll_no;
        cout << "Enter name : ";
        cin >> name;
        cout << endl;
    }

    void display()
    {
        cout << endl
             << "Roll no : " << roll_no;
        cout << endl
             << "Name : " << name;
    }
};

int main()
{
    int offset = sizeof(Student) * 2;

    ofstream of("student.dat", ios::binary);

    if (!of)
    {
        cout << "Cannot open file!" << endl;

        return 1;
    }

    Student stu_w[3];

    for (int i = 0; i < 3; i++)
    {
        stu_w[i].getdata();
    }

    for (int i = 0; i < 3; i++)
    {
        of.write((char *)&stu_w[i], sizeof(Student));
    }

    of.close();

    if (!of.good())
    {
        cout << "Error occurred at writing time!" << endl;

        return 1;
    }

    ifstream ifs("student.dat", ios::binary);

    if (!ifs)
    {
        cout << "Cannot open file!" << endl;

        return 1;
    }

    Student stu_r;

    ifs.seekg(offset, ios_base::beg);
    ifs.read((char *)&stu_r, sizeof(Student));
    ifs.close();

    if (!ifs.good())
    {
        cout << "Error occurred at reading time!" << endl;

        return 1;
    }

    cout << "Student's Details :" << endl;

    stu_r.display();
    cout << endl;

    return 0;
}
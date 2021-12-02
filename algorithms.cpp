#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <cmath>


using namespace std;

class Student {

    private:
    int id;
    string firstName;
    string lastName;

    public:
    int getId() const { return id; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    Student(int id, string fn, string ln): id(id), firstName(fn), lastName(ln) {}

    bool operator< (const Student &s) const { return this->getId() < s.getId(); }

};


bool descendingById(Student s1, Student s2) {

    return s1.getId() > s2.getId();

}

bool descendingByLastName(Student s1, Student s2) {

    return s1.getLastName() > s2.getLastName();

}


void printStudentName(Student s) {

    cout << s.getFirstName() <<  " " << s.getLastName() << endl;

}


double integrate(double start, double end, function<double(double)> f) {

    int numIntervals = 1000;
    double result = 0;
    double deltaX = (end - start) / numIntervals;

    for (int i=0; i<numIntervals; i++) {
        double xLeft = start + i * deltaX;
        double nextArea = ((f(xLeft) + f(xLeft+ deltaX)) / 2) * deltaX;
        result += nextArea;
    }
    return result;

}


int main() 
{

    vector<Student> testStudents;
    testStudents.push_back( Student(10, "Bienve", "Velez"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(32, "Amanda", "Vazquez"));
    testStudents.push_back( Student(65, "Joshua", "Vazquez"));
    testStudents.push_back( Student(43, "Alejandra", "Munoz"));
    testStudents.push_back( Student(54, "Theo", "Puig"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(76, "Rey", "Cotto"));

    cout << "Hello World" << endl;

    sort(testStudents.begin(), testStudents.end());

    sort(testStudents.begin(), testStudents.end(),descendingById);

    sort(testStudents.begin(), testStudents.end(),descendingByLastName);

    sort(testStudents.begin(), testStudents.end(),
         [](Student s1, Student s2) { return s1.getLastName() < s2.getLastName(); });

    for_each(testStudents.begin(), testStudents.end(),printStudentName);

    for_each(testStudents.begin(), testStudents.end(), [](Student s) { cout << s.getFirstName() << endl; });

    vector<Student>::iterator pos = find_if(testStudents.begin(), testStudents.end(),
                                     [](Student s) { return (s.getFirstName()[0] == 'A'); });

    cout << "First student with firstname begining with B is: " << pos->getFirstName() << endl;

    pos = find_if(pos+1, testStudents.end(),
                                     [](Student s) { return (s.getFirstName()[0] == 'A'); });

    cout << "Integral of x^2 in [0,2] is: " << integrate(0,2,[](double x) { return x*x; }) << endl;

    cout << "Integral of e^(-x^2) in [0,2] is: " << integrate(0,2,[](double x) { return exp(-x*x); }) << endl;

}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person{
public:
    string name;
    int age;
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
};

bool cmp(const Person &a, const Person &b){
    return a.name < b.name;
}

int main(){
    vector<Person> v;
    v.push_back(Person("Ace", 22));
    v.push_back(Person("Luffy", 28));
    v.push_back(Person("Zoro", 26));
    v.push_back(Person("Robin", 25));
    v.push_back(Person("Brook", 40));
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
        cout << v[i].age  << ", " <<  v[i].name << endl;
}

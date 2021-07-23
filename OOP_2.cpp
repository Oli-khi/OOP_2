#include <iostream>
#include <string>
using namespace std;


class Person
{
//    /*
//    Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы переназначения имени, изменения возраста и веса. 
//Создать производный класс Student (студент), имеющий поле года обучения. Определить методы переназначения и увеличения этого значения. 
//Создать счетчик количества созданных студентов. В функции main() создать несколько студентов. По запросу вывести определенного человека.
//
//    */
private:
    string m_name;
    string m_sex;
    int m_age;
    double m_weight;
public:
    Person (string sex, int age, double weight, string name = "") : m_name(name), m_sex(sex), m_age(age), m_weight(weight)
    {
    }

    void SetName(string name)
    {
        m_name = name;
    }

    void SetAge(int age)
    {
        m_age = age;
    }

    void SetWeight(double weight)
    {
        m_weight = weight;
    }

    string GetName() {
        return m_name;
    }

    string GetSex() {
        return m_sex;
    }

    int GetAge() {
        return m_age;
    }

    double GetWeight() {
        return m_weight;
    }

};

class Student : public Person 
{
    int m_years;

    public:
    static int count;

    Student(string sex, int age, double weight, string name = "", int years = 0)
    : Person(sex, age, weight, name), m_years(years)
    {
        count++;
    }

    ~Student() {
        count--;
    }

    void SetYears(int years) {
        m_years = years;
    }

    int GetYears() {
        return m_years;
    }

    void Print() {
        cout << "Имя: " << GetName() << "\tВозраст: " << GetAge() << "\tГоды обучения: " << GetYears() << endl;
    }

};

int Student::count = 0;

class Fruit {
    
public:
    string m_name;
    string m_color;

    Fruit() 
    {}

    void setName(string name) {
        m_name = name;
    }

    void setColor(string color) {
        m_color = color;
    }

    string getName() {
        return m_name;
    }

    string getColor() {
        return m_color;
    }

};
class Apple : public Fruit {
public:
    Apple(string color = "")  {
        m_color = color;
        m_name = "Apple";
    }
};

class Banana : public Fruit {
public:
    Banana() {
        m_color = "Yellow";
        m_name = "Banana";
    }
};

class GrannySmith : public Apple {
public:
    GrannySmith() {
        m_color = "Green";
        m_name = "Granny Smith apple";
    }
};


int main()
{
    setlocale(LC_ALL, "rus");
   
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    

    Student Alex("M", 21, 77.4, "Александр Сергеевич", 3);
    Student Sam("M", 20, 60.4, "Сергей Витальевич", 3);
    Student Gregory("M", 23, 87.6, "Григорий Антонович", 3);
    Alex.Print();
    Sam.Print();
    Gregory.Print();
    
    cout << Student::count << endl;
    return 0;
}



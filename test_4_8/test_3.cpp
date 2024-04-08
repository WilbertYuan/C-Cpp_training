#include <iostream>  
#include <string>  

class Girl;

class Boy
{
private:
    std::string name;
    int age;
public:
    Boy(const std::string& n, int a) : name(n), age(a) {}
    ~Boy() {}
    void displayInfo()
    {
        std::cout << "Boy's name: " << name << ", age: " << age << std::endl;
    }
    //void VisitGirl(Girl& g);
    //friend class Girl;
    friend void VisitBoyGirl(Boy& b, Girl& g);
};

class Girl 
{
private:
    std::string name;
    int age;
public:
    //void VisitBoy(Boy& b)
    //{
    //    std::cout << "Boy's name: " << b.name << ", age: " << b.age << std::endl;
    //}
    Girl(const std::string& n, int a) : name(n), age(a) {}
    ~Girl() {}
    void displayInfo() 
    {
        std::cout << "Girl's name: " << name << ", age: " << age << std::endl;
    }
    //friend class Boy;
    friend void VisitBoyGirl(Boy& b, Girl& g);
};

//void Boy::VisitGirl(Girl& g)
//{
//    std::cout << "Girl's name: " << g.name << ", age: " << g.age << std::endl;
//}

void VisitBoyGirl(Boy& b, Girl& g)
{
    std::cout << "Girl's name: " << g.name << ", age: " << g.age << std::endl;
    std::cout << "Boy's name: " << b.name << ", age: " << b.age << std::endl;   
}

int main() 
{
    Girl girl("Alice", 18);
    Boy boy("Bob", 20);
    girl.displayInfo();
    boy.displayInfo();
    VisitBoyGirl(boy, girl);
    //girl.VisitBoy(boy);
    //boy.VisitGirl(girl);
    return 0;
}
#include <iostream>
#include <list>
#include <string>

struct student {
    int age;
    std::string name;

    student(int index, std::string hh) {
        age = index;
        name = hh;
    }
};

int main(void) {
    std::list<student*> oneList;
    
    // add
    for (size_t i = 0; i < 5; i++) {
        student* stu = new student(i, "Hello");
        oneList.push_back(stu);
    }
    std::cout<<"size: "<<oneList.size()<<std::endl;

    std::list<student*>::iterator it = oneList.begin();
    for (; it != oneList.end(); ++it) {
        std::cout<<"Index:"<<(*it)->age<<"; name: "<<(*it)->name<<std::endl;
    }

    // erase age is 3
    student* test = NULL;
    it = oneList.begin();
    for (; it != oneList.end(); ++it) {
        if (2 == (*it)->age) {
            test = *it;
            oneList.erase(it);
            break;
        }
    }
    std::cout << "找到的学生: "<<test->age<<":  "<<test->name << std::endl;
    delete test;

    // remove
    int layerCount = oneList.size();
    std::cout << "剩余的学生为:"<<layerCount << std::endl;
    for (int i = layerCount-1; i > 0; --i) {
        student* unit = oneList.back();
        oneList.pop_back();
        if(NULL != unit) {
             delete unit;
             unit = NULL;
        }
    }
    oneList.clear();
    std::cout<<"size: "<<oneList.size()<<std::endl;

    return 0;
}

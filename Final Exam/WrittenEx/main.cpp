#include <iostream>
#include "TemplatedStack/TStack.h"
#include "ToDoList/ToDo.h"
#include "CarList/carlist.h"
#include "SaleItem/saleitem.h"
#include "Hospital/hospital.h"
#include <assert.h>
#include "string.h"

void testStack()
{
    Stack<std::string> s{ 2 };
    assert(s.getMaxCapacity() == 2);
    try {
        s = s + "examination";
        s = s + "oop";
        s = s + "test";
    }
    catch (std::exception& e) {
        assert(strcmp(e.what(), "Stack is full!") == 0);
    }
    assert(s.pop() == "oop");
    assert(s.pop() == "examination");
}

void ToDoList()
{
    ToDo<Activity> todo{};
    Activity tiff{ "go to TIFF movie", "20:00" };
    todo += tiff;
    Activity project{ "present project assignment", "09.20" };
    todo += project;
    /// iterates through the activities and prints them as follows:
    /// Activity present project assignment will take place at 09.20.
    /// Activity go to TIFF movie will take place at 20.00.
    for (auto a : todo)
        std::cout << a << '\n';


    /// Prints the activities as follows:
    /// Activity go to TIFF movie will take place at 20.00.
    /// Activity present project assignment will take place at 09.20.
    todo.reversePrint(std::cout);
}

void function1() {
    List<Car, int> list1;
    try {
        list1.sortByFirstComponent();
        assert(false);
    }
    catch (std::runtime_error& e) { assert(strcmp(e.what(), "List is empty!") == 0);	}

    list1.add(Car{ "Audi", 20 }, 8);
    list1.add(Car{ "Volkswagen", 10 }, 9);
    list1.add(Car{ "Bentley", 300 }, 10);

    list1.sortByFirstComponent();
    list1.printReverse(std::cout); // prints: Bentley 300 -> 10; Audi 20 -> 8; Volkswagen 10 -> 9
    list1.sortBySecondComponent();
    list1.printReverse(std::cout); // prints: Bentley 300 -> 10; Volkswagen 10 -> 9; Audi 20 -> 8;
}

void testSales(){
    Sale *s = new Sale{};
    s->addSale(SaleItem{1234, 40.0});
    s->addSale(SaleItem{0231, 34.5});
    s->addSale(SaleItem{5656, 80.25});

    ItemDiscount *id1 = new ItemDiscount{1234, 10};
    ItemDiscount *id2 = new ItemDiscount{5656, 15};
    SumDiscount *sd = new SumDiscount{};
    sd->add(*id1);
    sd->add(*id2);

    std::cout<<sd->calc(*s);

    delete id1;
    delete id2;
    delete sd;
    delete s;
}

void testHospital(){
    Controller c;
    NeonatalUnit *hd = new NeonatalUnit{"yeao", 100, 10, 20, 8.9};
    Surgery *s = new Surgery{"UPU", 100, 300};
    c.addDepartment(hd);
    c.addDepartment(s);
    c.writeToFile("Hospital/hospitals.txt");

}

//int main() {
//    testStack();
//    ToDoList();
//    function1();
//    testSales();
//    testHospital();
//    return 0;
//}

#include <iostream>
#include "DynamicArray/dynamic_array.h"
#include "Repository/reopsitory.h"
#include "Service/service.h"
#include "UI/ui.h"
#include "dog.h"
#include "userService/userservice.h"
#include "Tests/testing.h"

int main(){
    DynamicArray<Dog> da = DynamicArray<Dog>(10);
    Repository repo = Repository(&da);
    Service service = Service(&repo);
    userService us = userService(&repo);
    UI ui = UI(&service, &us);
    test_all();
    ui.initialise();
    ui.start();
    return 0;
}
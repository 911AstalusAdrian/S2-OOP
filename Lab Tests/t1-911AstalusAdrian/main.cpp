#include "gene.h"
#include "Repo/repo.h"
#include "Service/service.h"
#include "Validate/validate.h"
#include "UI/ui.h"
#include <iostream>

int main(){
    Repository repo = Repository(10);
    Service service = Service(&repo);
    UI ui = UI(&service);
    tests();
    ui.start();
    return 0;
}
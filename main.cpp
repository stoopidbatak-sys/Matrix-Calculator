#include "config.h"
#include <iostream>
#include "Matrix_utilities.h"

int main() {
    MainMenu();

    int choice = InputChoice();
    Operations Task = InputEnum(choice);
    SwitchBody(Task);

    while (Task != Operations :: Exit) {
        std::cout<<"\n\n===Perform Another Task==="<<std::endl;
        Features();
        choice = InputChoice();
        Task = InputEnum(choice);
        SwitchBody(Task);
    }

    return 0;
}
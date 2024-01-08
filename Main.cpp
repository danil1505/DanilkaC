#include <windows.h>
#include "model.h"
#include "view.h"
#include "controller.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    Model model;
    View view;
    Controller controller(model, view);
    controller.processUserInput();

    return 0;
}

#include "DeleteLib/delete.h"
#include "AddLib/HelpersLib/addHelpers.h"
#include "HelpersLib/helpers.h"

int main() {
    add_val(50);
    add_val(25);
    add_val(12);
    add_val(89);
    add_val(65);
    add_val(23);
    add_val(1);
    add_val(3);
    add_val(2);
    add_val(90);
    add_val(78);
    add_val(32);
    add_val(22);
    add_val(24);
    add_val(45);

    print_tree();

    delete_val(1);
    delete_val(2);
    delete_val(3);
    delete_val(22);
    delete_val(12);
    delete_val(24);
    delete_val(23);
    delete_val(50);
    delete_val(25);
    delete_val(45);
    delete_val(32);
    delete_val(32);
    delete_val(22);
    delete_val(24);
    delete_val(45);

    print_tree();
    return 0;
}

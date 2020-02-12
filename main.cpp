
#include <iostream>

#include "library.h"

int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl;
    hello();

#if (USE_LOG == 3)
    std::cout << USE_LOG << std::endl;
    std::cout << "USE_LOG yes! " << std::endl;
#endif

#ifdef USE_FILTER
    std::cout << "USE_FILTER yes!" << std::endl;
#endif
//    system("pause");
    return 0;
}

#include <iostream>
int main()
{
    system("touch includer.cc");
    std::cout << "[system] `make a file called 'includer.cc'`" << std::endl;
    system("printf '#include \"tuaio.h\"\n#include \"main.spoon\" > includer.cc");
    std::cout << "[system] `Done!`" << std::endl;
    std::cout << std::endl;
    std::cout << "compiling.." << std::endl;
    system("cc includer.cc -o spoon_maked_file");
    std::cout << "Done!" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    system("./spoon_maked_file");
}
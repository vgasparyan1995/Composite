#include <iostream>

#include "FileSystem.h"

int main()
{
    auto file1 = new File();
    file1->set_size(10);
    
    auto file2 = new File();
    file2->set_size(23);

    auto file3 = new File();
    file3->set_size(10);

    auto dir1 = new Directory();
    dir1->add_child(file1);
    dir1->add_child(file2);

    auto dir2 = new Directory();
    dir2->add_child(file3);
    dir2->add_child(dir1);
    
    std::cout << "Dir1 size: " << dir1->size() << std::endl;
    std::cout << "Dir2 size: " << dir2->size() << std::endl;
}

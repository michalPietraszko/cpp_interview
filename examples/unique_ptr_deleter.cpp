#include <iostream>
#include <memory>
#include <array>

/**
 * Question: 
 * What is the size of std::unique_ptr? 
*/

int main()
{
    const auto noCaptureDeleter = [](auto* i) { std::cout << "deleting: " << *i << std::endl; delete i; };
    const auto bigCaptureDeleter = [ii=std::array<int, 100>()](auto* i) { 
        std::cout << "deleting: " << *i << std::endl; delete i; 
    };
    
    std::unique_ptr<int, decltype(noCaptureDeleter)> first(new int(5), noCaptureDeleter);
    std::cout << "Size of first: " << sizeof(first) << std::endl;
    
    std::unique_ptr<int, decltype(bigCaptureDeleter)> second(new int(10), bigCaptureDeleter);
    std::cout << "Size of second: " << sizeof(second) << std::endl;

    return 0;
}

/**
 * Output:
 * Size of first: 8
 * Size of second: 408
 * deleting: 10
 *  deleting: 5
*/
# Commons

This is a collection of commom libraries that I either used for some projects or never actually got to use but didn't wanted to waste the work I put into them.

# Libraries included:

## List.hpp
A simple library that reads the lines on a text file and stores them on a vector. I use it to read list files and find items inside it.

**Example**
```C++
#include <iostream>
#include "list.hpp"

int main(int argc, char const *argv[])
{
    //Check if arguments are valid
    if( argc != 2 )
    {
        std::cout << "Usage:" << argv[0] << " [filename]\n";
        return 1;
    }

    //Create a list instance with the file
    //included in the program's argument 
    ListFile list( argv[1] );
    if( list != ListFile::Status::OK )
    {
        //If the file can't be openned, tell us why
        std::cout << "Error: " << list.get_status_description() << ".\n";
        return 1; 
    }

    //List all of the items that start with "test"
    ListFile::List items = list["test"];
    for( std::string entry : items )
    {
        std::cout << entry << "\n";
    }

    return 0;
}
```
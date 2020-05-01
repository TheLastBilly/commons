#pragma once

#include <iostream>
#include <vector>
#include <fstream>

class PlayerList
{
public:
    enum Status
    {
        OK,
        FILE_NOT_FOUND,
        NO_FILE
    };

    typedef std::vector<std::string> List;

private:
    std::string file_name;
    List name_list;
    Status status;
    size_t list_size;

public:
    PlayerList( std::string file_name = "" );

    Status read( std::string file_name = "" );

    Status get_status() const;
    std::string get_status_description() const;

    List operator[]( const std::string &index ) const;
    std::string operator[]( size_t index ) const;

    bool operator==( Status status ) const;
    bool operator!=( Status status ) const;
    
    size_t size() const;
};
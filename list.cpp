#include "include/list.hpp"

ListFile::ListFile( std::string file_name ):
    file_name( file_name ),
    list_size(0)
{
    name_list.size();
    if(file_name == "")
        status = Status::NO_FILE;
    else
    {
        status = read( );
        list_size = name_list.size();
    }
}

ListFile::Status ListFile::read( std::string file_name )
{
    if(file_name == "")
        file_name = this->file_name;
    else
        this->file_name = file_name;
    
    std::ifstream file;
    file.open( file_name );
    if( !file.is_open() )
        return (status = Status::FILE_NOT_FOUND);
    
    name_list.clear();
    std::string line;
    while( std::getline(file, line, '\n'))
        name_list.push_back( line );

    file.close();
    return (status = Status::OK);
}

ListFile::Status ListFile::get_status() const
{
    return status;
}

std::string ListFile::get_status_description() const
{
    switch (status)
    {
    case Status::OK:
        return "OK";
    case Status::FILE_NOT_FOUND:
        return "File cannot be found";
    case Status::NO_FILE:
        return "No file specified";
    }
    return "Undefined state";
}

ListFile::List ListFile::operator[]( const std::string &index ) const
{
    size_t size = index.size();
    List list; 

    for( std::string name : name_list )
    {
        if( name.size() >= size && name.substr(0, size) == index ) 
            list.push_back( name );
    }

    return list;
}

std::string ListFile::operator[]( size_t index ) const
{
    if( index > name_list.size() - 1)
        return name_list.at(0);
    
    return name_list.at( index );
}

bool ListFile::operator==( ListFile::Status status ) const
{
    return this->status == status;
}
bool ListFile::operator!=( ListFile::Status status ) const
{
    return !(this->status == status);
}
size_t ListFile::size() const
{
    return list_size;
}
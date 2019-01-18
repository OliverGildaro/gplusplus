#pragma once

#include "document.h"

class xml_writer
{
private:
    
public:
    xml_writer();
    ~xml_writer();

    document create_document(const string_view&);
};
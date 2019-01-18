#include "xml_writer.h"

xml_writer::xml_writer()
{
}

xml_writer::~xml_writer()
{
}

document xml_writer::create_document(const string_view& doc_name)
{
    return document{doc_name};
}
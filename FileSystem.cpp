#include "FileSystem.h"

#include <algorithm>

File::File()
    : m_size(0)
{}

unsigned File::size() const
{
    return m_size;
}

bool File::is_dir() const
{
    return false;
}

void File::set_size(const unsigned s)
{
    m_size = s;
}

unsigned Directory::size() const
{
    auto size = 0U;
    std::for_each(m_children.begin(), m_children.end(), [&size] (FileBase* c) {
            size += c->size();
            });
    return size;
}

bool Directory::is_dir() const
{
    return true;
}

void Directory::add_child(FileBase* c)
{
    m_children.push_back(c);
}

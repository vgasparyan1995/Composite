#pragma once

#include <vector>

class FileBase
{
public:
    virtual unsigned size() const = 0;
    virtual bool is_dir() const = 0;
    virtual ~FileBase() {}
};

class File : public FileBase
{
public:
    File();
    virtual unsigned size() const override;
    virtual bool is_dir() const override;
    void set_size(const unsigned s);

private:
    unsigned m_size;
};

class Directory : public FileBase
{
public:
    virtual unsigned size() const override;
    virtual bool is_dir() const override;
    void add_child(FileBase* c);

private:
    std::vector<FileBase*> m_children;
};

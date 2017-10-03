#ifndef JSONPARSEERROR_H
#define JSONPARSEERROR_H

#include <stdexcept>

class JsonParseError : public std::logic_error
{
public:
    explicit JsonParseError(const std::string &what_arg);
};

#endif // JSONPARSEERROR_H

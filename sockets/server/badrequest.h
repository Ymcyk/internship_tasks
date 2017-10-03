#ifndef BADREQUEST_H
#define BADREQUEST_H

#include <stdexcept>

class BadRequest : public std::logic_error
{
public:
    explicit BadRequest(const std::string &what_arg);
};

#endif // BADREQUEST_H

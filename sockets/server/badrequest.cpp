#include "badrequest.h"

BadRequest::BadRequest(const std::string &what_arg)
    : std::logic_error(what_arg)
{

}

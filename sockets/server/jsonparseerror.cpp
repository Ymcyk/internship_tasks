#include "jsonparseerror.h"

JsonParseError::JsonParseError(const std::string &what_arg)
    : std::logic_error(what_arg)
{

}

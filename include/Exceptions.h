#ifndef INCLUDE_EXCEPTIONS_H_
#define INCLUDE_EXCEPTIONS_H_

#include <stdexcept>

/**
* Exception for an invalid parameter passed to a constructor or method.
*/
class illegalArgumentException: public std::runtime_error {
 public:
    /**
    * @param errMessage An error message.
    */
    explicit illegalArgumentException(const char* errMessage) :
        std::runtime_error(errMessage) {
    }
};

#endif  // INCLUDE_EXCEPTIONS_H_

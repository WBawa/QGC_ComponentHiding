#include "AccessTypeConfig.h"
#include <iostream>

//AccessType CURRENT_USER_ACCESS_TYPE = Basic;
//AccessType CURRENT_USER_ACCESS_TYPE = Expert;
AccessType CURRENT_USER_ACCESS_TYPE = Factory;

AccessType getInitialUserAccessType() {
    std::cout << "THIS IS A TEST LMAO" << std::endl;
    return CURRENT_USER_ACCESS_TYPE;
}

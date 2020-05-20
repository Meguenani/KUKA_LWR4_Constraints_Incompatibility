#include <iostream>
#include "boost/date_time/posix_time/posix_time.hpp" 

typedef boost::posix_time::ptime Time;

double get_time_in_µs(){

    Time t_1;
         t_1 = boost::posix_time::microsec_clock::local_time();

    double t = t_1;
    return t;
}


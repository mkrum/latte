#include <ops.h>

namespace utils {

  bool is_double(const char* str){
    char* endptr = 0;
    std::strtod(str, &endptr);
    if(*endptr != '\0' || endptr == str)
      return false;
    return true;
  }

  //atof is no-throw, add another check to make sure its reading a double value
  double string_to_double(std::string double_val) {
    assert(is_double(double_val.c_str()));
    return std::atof(double_val.c_str());
  }

}

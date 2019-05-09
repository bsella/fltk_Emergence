#pragma once
#include <string>

#ifndef EMERGENCE_PLUGIN
#define RELATIVE(path) (relative_path+ path).c_str()
#else
#define RELATIVE(path) (*relative_path+ path).c_str()
#endif
extern std::string relative_path;

#pragma once

#include <vector>
#include <string>

inline bool startWith(const std::string& str, const std::string& start);

inline bool endsWith(const std::string& str, const std::string& end);

inline bool contains(const std::string& str, const std::string& sub);

inline std::vector<std::string> split(const std::string& str, const std::string& delimiter);
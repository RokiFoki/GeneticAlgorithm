#ifndef UTIL_H
#define UTIL_H
#pragma once

#include <type_traits>

template <typename Derived, typename Base>
using Extends = typename std::enable_if<std::is_base_of<Base, Derived>::value>::type;

#define my_delete(x) { delete x; x = nullptr; }

#endif
#pragma once
#ifndef __DATA_TYPE_H__
#define __DATA_TYPE_H__

#include <variant>

using LiteralValue = std::variant<std::monostate, double, std::string, int, bool>;

#endif
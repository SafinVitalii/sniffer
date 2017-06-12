#include "filter.h"

Filter::Filter(std::string value) : value_(value)
{
}

void Filter::SetValue(std::string& value)
{
  value_ = value;
}

std::string Filter::GetValue()
{
  return value_;
}

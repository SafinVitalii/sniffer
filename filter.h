#ifndef FILTER_H
#define FILTER_H
#include <string>
class Filter
{
 public:
  Filter(std::string value);
  std::string GetValue();
  void SetValue(std::string&);

 private:
  std::string value_;
};

#endif // FILTER_H

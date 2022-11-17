#include "subsets.h"

// actual recursive function
template< typename T >
void subset_rec(std::vector<T> const &set, std::vector<T> data, unsigned level) 
{
  if (level >= set.size())
  {
    std::cout << "{ ";
    for (T iter : data)
    {
      std::cout << iter << ' ';
    }
    std::cout << '}' << std::endl;
    return;
  }

  data.push_back(set[level]);
  subset_rec(set, data, ++level);

  --level;

  data.pop_back();
  subset_rec(set, data, ++level);
}

// kickstart
template< typename T >
void subsets( std::vector<T> const& set)
{
  std::vector<T> data = {};
  subset_rec(set, data, 0);
}

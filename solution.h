#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <string>

using namespace std;
namespace sol1756
{
  class MRUQueue
  {
  private:
    vector<list<int>> buckets;

  public:
    MRUQueue(int n);
    int fetch(int k);
  };
}
#endif
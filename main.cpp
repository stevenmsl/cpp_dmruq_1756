#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1756;

/*
Input:
["MRUQueue", "fetch", "fetch", "fetch", "fetch"]
[[8], [3], [5], [2], [8]]
Output:
[null, 3, 6, 2, 2]
*/
tuple<int, vector<int>, vector<int>>
testFixture1()
{
  return make_tuple(8, vector<int>{3, 5, 2, 8}, vector<int>{3, 6, 2, 2});
}

void test1()
{
  auto f = testFixture1();
  auto q = MRUQueue(get<0>(f));

  auto input = get<1>(f);
  auto exp = get<2>(f);

  for (auto i = 0; i < input.size(); i++)
  {
    cout << "exepct to see " << to_string(exp[i]) << endl;
    cout << "result: " << to_string(q.fetch(input[i])) << endl;
  }
}

main()
{
  test1();
  return 0;
}
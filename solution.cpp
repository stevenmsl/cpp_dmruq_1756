#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>
using namespace sol1756;
using namespace std;

/*takeaways
  - to achieve O(sqrt(n)), we can use sqrt decomposition
  - you put the numbers into sqrt(n) buckets. Each
    bucket has sqrt(n) numbers: sqrt(n)xsqrt(n)=n
  - to fetch a number, find the bucket it's in first
    and that find the index it's in within that bucket
  - adjust the queue by updating the bucket from where
    the fetched number is originally located to the
    very last bucket
*/

MRUQueue::MRUQueue(int n) : buckets(ceil(sqrt(n)))
{
  /* put the numbers into sqrt(n) buckets
     - notice that the numbers start with
       1 not 0
  */
  int size = buckets.size();
  for (int i = 0; i < n; i++)
    buckets[i / size].emplace_back(i + 1);
}

int MRUQueue::fetch(int k)
{
  // 0-based
  --k;
  int s = size(buckets);

  /* which bucket */
  auto b = k / s;
  /* index within the bucket */
  auto idx = k % s;
  /* move to the index within the bucket */
  auto it = cbegin(buckets[b]);
  advance(it, idx);
  int val = *it;
  /*C++ note
    - it will be expensive to erare an item
      from a vector so we choose a list
  */
  buckets[b].erase(it);
  buckets[s - 1].emplace_back(val);

  /*adjust the queue from b to the very last bucket*/
  for (int i = b; i <= s - 2; i++)
  {
    /* move the first element of the next bucket
       to the back of this bucket
    */
    auto num = buckets[i + 1].front();
    buckets[i + 1].pop_front();
    buckets[i].emplace_back(num);
  }

  return val;
}
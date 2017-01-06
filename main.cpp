#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class solution {
public:
  int kthSmallest(const std::vector<std::vector<int>> & matrix, int k) {
    std::vector<int> nums;
    std::for_each(matrix.begin(), matrix.end(),
		  [&](const std::vector<int> & vec){
		    std::copy(vec.begin(), vec.end(), std::inserter(nums, nums.end()));
		  });

    std::nth_element(nums.begin(), nums.begin()+k-1, nums.end());
    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    return nums[k-1];
  }
};

int main() {
  std::vector<std::vector<int>> matrix{
    {1,5,9},
      {10,11,13},
	{12,13,15}
  };
  int kth = 8;
  

  solution soln;
  int kthSmall = soln.kthSmallest(matrix, kth);
  std::cout << "The " << kth << "-th smallest element is:\n"
	    << kthSmall << std::endl;
}

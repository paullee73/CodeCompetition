class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
        {
            return -1;
        }
        int low = 0;
        int high = nums.size() - 1;

        while (low < high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }

            // left side is properly ordered
            if (nums[low] <= nums[mid])
            {
                if (target >= nums[low] && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            // right side is properly ordered
            else
            {
                if (target > nums[mid] && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        if (nums[low] == target)
        {
            return low;
        }
        else
        {
            return -1;
        }
    }
};
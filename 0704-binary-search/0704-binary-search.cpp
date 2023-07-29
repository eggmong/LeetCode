class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int answer = -1;

        int min = 0;
        int max = nums.size() - 1;
        int center = 0;

        while (min <= max)
        {
            center = (min + max) / 2;

            if (nums[center] == target)
            {
                return center;
            }
            else if (nums[center] > target)
            {
                max = center - 1;
            }
            else
            {
                min = center + 1;
            }
        }

        return -1;
    }
};
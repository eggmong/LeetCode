class Solution {
public:
    int minPartitions(string n)
    {
        int maxNum = 0;
        
        for (int i = 0; i < n.size(); i++)
        {
            if (isdigit(n[i]) && (n[i] - 48) > maxNum)
            {
                maxNum = n[i] - 48;
            }
        }
        
        return maxNum;
    }
};
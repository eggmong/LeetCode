class Solution
{
public:
    int FindCharValue(const std::vector<std::pair<int, char>>& order, char value)
{
    for (const auto& entry : order)
    {
        if (entry.second == value)
        {
            return entry.first;
        }
    }

    return -1;
}

bool isIsomorphic(string s, string t)
{
    std::vector<std::pair<int, char>> sOrder;
    std::vector<std::pair<int, char>> tOrder;

    if (s.size() != t.size())
        return false;

    for (int i = 0; i < s.size(); i++)
    {
        auto it = FindCharValue(sOrder, s[i]);
        if (it != -1)
        {
            sOrder.emplace_back(it, s[i]);
        }
        else
        {
            sOrder.emplace_back(i, s[i]);
        }
    }

    for (int i = 0; i < t.size(); i++)
    {
        auto it = FindCharValue(tOrder, t[i]);
        if (it != -1)
        {
            tOrder.emplace_back(it, t[i]);
        }
        else
        {
            tOrder.emplace_back(i, t[i]);
        }
    }

    for (int i = 0; i < tOrder.size(); i++)
    {
        if (tOrder[i].first != sOrder[i].first)
            return false;
    }

    return true;
}
};
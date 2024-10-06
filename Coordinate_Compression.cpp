class CoordinateCompression{
    map<long long, int> mp;
    vector<int> rev;
    int cnt = 0;

    public:
        void insert(long long num)
        {
            mp[num] = 0;
        }

        void build()
        {
            for(auto &map : mp)
            {
                map.second=cnt++;
                rev.push_back(map.first);
            }
        }

        int index(long long num)
        {
            if(mp.find(num) != mp.end())return mp[num];
            else return -1;
        }

        int size()
        {
            return cnt;
        }

        int IndexOriginal(int ind)
        {
            if(ind < cnt)return rev[ind];
            return -1;
        }
};

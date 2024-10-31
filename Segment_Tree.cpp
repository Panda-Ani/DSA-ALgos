class segmentTree
{
    vector<int> SGT;
    vector<int> arr;
    int n;

    int left(int index)
    {
        return 2 * index;
    }

    int right(int index)
    {
        return 2 * index + 1;
    }

    int merge(int l, int r)
    {
        return l + r;
    }

    int default_val()
    {
        return 0;
    }

    void build(int start, int end, int index)
    {
        // O(n)
        // build(0,n-1,1,arr,SGT);
        if (start == end)
        {
            SGT[index] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        build(start, mid, left(index));
        build(mid + 1, end, right(index));
        SGT[index] = merge(SGT[left(index)], SGT[right(index)]);

        return;
    }

    void Update(int start, int end, int index, int pos, int val)
    {
        // O(logn)
        // update(0,n-1,1,SGT,2,5) pos is zero based index
        if (start == end)
        {
            SGT[index] = val;
            return;
        }

        int mid = (start + end) / 2;

        if (pos <= mid)
        {
            Update(start, mid, left(index), pos, val);
        }
        else
        {
            Update(mid + 1, end, right(index), pos, val);
        }
        SGT[index] = merge(SGT[left(index)], SGT[right(index)]);
        return;
    }

    int Query(int start, int end, int index, int l, int r)
    {
        // O(logn)
        // query(0,n-1,1,SGT,2,4) l and r are zero based index
        if (l <= start && r >= end)
        {
            return SGT[index];
        }

        if (r < start || l > end)
        {
            return default_val();
        }

        int mid = (start + end) / 2;

        int leftAns = Query(start, mid, left(index), l, r);
        int rightAns = Query(mid + 1, end, right(index), l, r);

        return merge(leftAns, rightAns);
    }

public:
    void init(int _n, vector<int> &a)
    {
        this->n = _n;
        SGT.resize(4 * n);
        arr = a;
        build(0, n - 1, 1);
    }

    void update(int pos, int val)
    {
        Update(0, n - 1, 1, pos, val);
    }

    int query(int l, int r)
    {
        return Query(0, n - 1, 1, l, r);
    }
};
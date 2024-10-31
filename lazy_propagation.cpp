class lazySegmentTree
{
    vector<int> SGT, lazy, arr;
    int n;

    int left(int index) { return 2 * index; }
    int right(int index) { return 2 * index + 1; }
    int merge(int l, int r) { return l + r; }
    int default_val() { return 0; }

    void push(int index, int st, int en)
    {
        if (lazy[index] != 0)
        {
            SGT[index] += (en - st + 1) * lazy[index];

            if (st != en)
            {
                lazy[left(index)] += lazy[index];
                lazy[right(index)] += lazy[index];
            }

            lazy[index] = 0;
        }
    }

    void Build(int start, int end, int index)
    {
        if (start == end)
        {
            SGT[index] = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        Build(start, mid, left(index));
        Build(mid + 1, end, right(index));
        SGT[index] = merge(SGT[left(index)], SGT[right(index)]);
    }

    void Update(int start, int end, int l, int r, int val, int index)
    {
        push(index, start, end);
        if (start > r || end < l)
            return;

        if (start >= l && end <= r)
        {
            lazy[index] += val;
            push(index, start, end);
            return;
        }

        int mid = (start + end) / 2;
        Update(start, mid, l, r, val, left(index));
        Update(mid + 1, end, l, r, val, right(index));
        SGT[index] = merge(SGT[left(index)], SGT[right(index)]);
    }

    int Query(int start, int end, int l, int r, int index)
    {
        push(index, start, end);
        if (l <= start && r >= end)
            return SGT[index];
        if (r < start || l > end)
            return default_val();

        int mid = (start + end) / 2;
        return merge(Query(start, mid, l, r, left(index)),
                     Query(mid + 1, end, l, r, right(index)));
    }

public:
    void build(int _n, vector<int> &a)
    {
        this->n = _n;
        SGT.resize(4 * n);
        lazy.resize(4 * n, 0);
        arr = a;
        Build(0, n - 1, 1);
    }

    void update(int l, int r, int val)
    {
        Update(0, n - 1, l, r, val, 1);
    }

    int query(int l, int r)
    {
        return Query(0, n - 1, l, r, 1);
    }
};
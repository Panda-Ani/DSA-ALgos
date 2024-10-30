int left(int index)
{
return 2*index;
}

int right(int index)
{
    return 2*index + 1;
}

int merge(int l, int r)
{
    return l + r;
}

int default_val()
{
    return 0;
}

void build(int start, int end, int index, vector<int> &arr, vector<int> &SGT)
{
    // O(n)
    // build(0,n-1,1,arr,SGT);
    if(start == end)
    {
        SGT[index] = arr[start];
        return;
    }

    int mid = (start + end)/2;

    build(start,mid,left(index),arr,SGT);
    build(mid+1,end,right(index),arr,SGT);
    SGT[index] = merge(SGT[left(index)],SGT[right(index)]);

    return;
}

void update(int start, int end, int index, vector<int> &SGT, int pos, int val)
{
    // O(logn)
    // update(0,n-1,1,SGT,2,5) pos is zero based index
    if(start == end)
    {
        SGT[index] = val;
        return;
    }

    int mid = (start + end)/2;

    if(pos <= mid)
    {
        update(start,mid,left(index),SGT,pos,val);
    }
    else
    {
        update(mid+1,end,right(index),SGT,pos,val);
    }
    SGT[index] = merge(SGT[left(index)],SGT[right(index)]);
    return;
}

int query(int start, int end, int index, vector<int> &SGT, int l, int r)
{
    // O(logn)
    // query(0,n-1,1,SGT,2,4) l and r are zero based index
    if(l <= start && r >= end)
    {
        return SGT[index];
    }

    if(r < start || l > end)
    {
        return default_val();
    }

    int mid = (start + end)/2;

    int leftAns = query(start,mid,left(index),SGT,l,r);
    int rightAns = query(mid+1,end,right(index),SGT,l,r);

    return merge(leftAns,rightAns);
}
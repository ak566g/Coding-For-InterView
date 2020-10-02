void lazy_update_incrementor(tree_attrs* tree, lazy_attrs* lazy, int start, int end, int left, int right, int current_position, int increment)
{
	if (start > end)
	{
		return;
	}
	if (lazy[current_position].incermentor != 0)
	{
		tree[current_position].sum_of_squares += (right-left + 1) * (lazy[current_position].incermentor * lazy[current_position].incermentor) + 2 * lazy[current_position].incermentor * tree[current_position].sum;
		tree[current_position].sum += (right-left + 1) * lazy[current_position].incermentor;
		if (start != end)
		{
			lazy[2 * current_position].incermentor += lazy[current_position].incermentor;
			lazy[2 * current_position + 1].incermentor += lazy[current_position].incermentor;
		}
		lazy[current_position].incermentor = 0;
	}
	if (lazy[current_position].setter != 0)
	{
		tree[current_position].sum = (right - left + 1) * (lazy[current_position].setter);
		if (start != end)
		{
			lazy[2 * current_position].setter = lazy[current_position].setter;
			lazy[2 * current_position + 1].setter = lazy[current_position].setter;
		}
		lazy[current_position].setter = 0;
	}
	//completely outside


	return;
}


void addInRange(int start, int end, int l, int r, int ti, int val)
{
    if(start>r|| end<l)
    {
        return;
    }
    
    if(lazy[ti].add!=0)
    {
        tree[ti].ss+= ((r-l+1)*(lazy[ti].add*lazy[ti].add) + 2 * tree[ti].s * lazy[ti].add);
        tree[ti].s+= (r-l+1)*lazy[ti].add;
        
        if(start!=end)
        {
            lazy[2*ti].add+=lazy[ti].add;
            lazy[2*ti+1].add+=lazy[ti].add;
        }
        
        lazy[ti].add=0;
    }
    
    if(lazy[ti].set!=0)
    {
        tree[ti].ss = (r-l+1)*lazy[ti].set*lazy[ti].set;
        tree[ti].s = (r-l+1)*lazy[ti].set;
        
        if(start!=end)
        {
            lazy[2*ti].set=lazy[ti].set;
            lazy[2*ti+1].set=lazy[ti].set;
        }
        
        lazy[ti].set=0;
    }
    
    
}

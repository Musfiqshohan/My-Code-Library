const int NX = 70 ;
 
Long dp[2][2][NX][NX];
int vis[2][2][NX][NX];
int lim , tt ;
vector < int > inp ;
 
Long DP( int pos , int isSmall ,int isStart, int value)
{
    if( pos == lim ) return value ;
    Long &ret = dp[isSmall][isStart][pos][value];
    int &v = vis[isSmall][isStart][pos][value];
    if( v == tt ) return ret ;
    v = tt ;
    int ses = isSmall ? 9 : inp[pos];
    int i ;
    ret = 0 ;
    if( !isStart )  // আগেই নাম্বার বসানো শুরু করে দিছি
    for ( i = 0 ; i <= ses ; i++ )
    {
        ret += DP( pos + 1 , isSmall | i < inp[pos] ,0, (i == 0) + value );
    }
    else
    {
         for ( i = 1 ; i <= ses ; i++ )
    {
        ret += DP( pos + 1 , isSmall | i < inp[pos] ,0, (i == 0) + value );
    }
    ret += DP( pos + 1 , 1 ,1, 0 );
    }
    return ret ;
}
 
Long Cal( Long x )
{
    if( x < 0 ) return 0 ;
    if( x <= 9 ) return 1 ;
    inp.clear();
    while( x )
    {
        inp.pb(x%10);
        x/=10;
    }
    reverse(inp.begin(),inp.end()); // সুবিধার জন্য রিভারস করে নিচ্ছি , এইটা করতেই হবে 
    lim = inp.size();
    tt++;
    return DP( 0 , 0 , 1 , 0 ) + 1; // শুধু ০ টা আলাদা এড করছি 
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
  // cout << fixed << setprecision(10) ;
 
     int cs , t = II ;
     for ( cs = 1 ; cs <= t ; cs++ )
     {
 
        Long n = LL , m = LL ;
        Long ans = Cal(m) - Cal(n-1);
        printf("Case %d: %lld\n",cs,ans);
     }
    return 0;
}


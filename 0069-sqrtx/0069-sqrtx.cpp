class Solution {
public:
    int mySqrt(int x) {
        int l=0;
        int r=x+1;
        
        while(l<r)
        {
            int m=(l+(r-l)/2);
            
            if(m*m>x) r= m;
            else l=m+1;
        }
        return l-1;
    }
};
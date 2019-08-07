	class Solution {
public:   
    
    double getSimpleresult (vector<int>& nums1, vector<int>& nums2, int m, int n) {
        if ((m+n)%2 == 1) {
                return  m<n?nums2[(m+n+1)/2 - m - 1]:nums1[(m+n+1)/2 - 1];
            } else {
                if (m == n) {
                    return ((double)(nums1[m-1] + nums2[0]))/2;
                }
                int resr = (m+n+1)/2 - m;
                int resr2 = (m+n+1)/2;
                return  m<n?((double)(nums2[resr]+nums2[resr-1]))/2 : ((double)(nums1[resr2]+nums1[resr2-1]))/2;
            }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();
        
        vector<int> longVec;
        vector<int> shortVec;
        if (m>n) {
            longVec = nums1;
            shortVec = nums2;
            int tempi = m;
            m = n;
            n = tempi;
        } else {
            longVec = nums2;
            shortVec = nums1;
        }
        if (m == 0) {
            if (n%2 == 1) {
                return longVec[(n+1)/2-1];
            } else {
                return ((double)(longVec[(n+1)/2]+longVec[(n+1)/2-1]))/2;
            }
        }
        if (shortVec[m-1] <= longVec[0]){
            return getSimpleresult(shortVec,longVec,m,n);
        } else if (longVec[n-1] <= shortVec[0]) {
            
            return getSimpleresult(longVec,shortVec,n,m);
        }
        int imin = 0;
        int imax = m;
        int halfsize = (m + n + 1)/2;
        int i = 0;
        int j = 0;
        int midr = 0;
        int midl = 0;
        while (imin <= imax) {
            i = (imin + imax) / 2;
            j = halfsize - i;

            if (i<imax&&shortVec[i] < longVec[j-1]) {
                imin = i+1;    
            } else if (i>imin&&shortVec[i-1] > longVec[j]) {
                imax = i-1;
            } else {
                if (i == 0) {
                    midl = longVec[j-1];
                } else if (j == 0) {
                    midl = shortVec[i-1];
                } else {
                    midl = shortVec[i-1] < longVec[j-1] ? longVec[j-1] : shortVec[i-1];
                }
                if ((m+n)%2 == 1) {
                    
                    return midl;
                    // midl = nums1[i-1] > nums2[j-1] ? nums1[i-1] : nums2[j-1];
                } else {
                    if (i == m) {
                        midr = longVec[j];
                    } else if (j == n) {
                        midr = shortVec[i];
                    } else {
                        midr = shortVec[i] < longVec[j] ? shortVec[i] : longVec[j];
                    }
                    return ((double)(midr + midl))/2;
                }
            }
            
        }
        
        return 0;
    }
};
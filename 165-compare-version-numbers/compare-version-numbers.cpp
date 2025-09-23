class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n = version1.size(), m = version2.size();

        while (i < n || j < m) {
            
            int start1 = i;
            while (i < n && version1[i] != '.') ++i;
            int end1 = i;
            
            while (start1 < end1 && version1[start1] == '0') ++start1;
            int len1 = end1 - start1;

           
            int start2 = j;
            while (j < m && version2[j] != '.') ++j;
            int end2 = j;
           
            while (start2 < end2 && version2[start2] == '0') ++start2;
            int len2 = end2 - start2;

            if (len1 != len2) return (len1 > len2) ? 1 : -1;

            for (int k = 0; k < len1; ++k) {
                char c1 = version1[start1 + k];
                char c2 = version2[start2 + k];
                if (c1 != c2) return (c1 > c2) ? 1 : -1;
            }

           
            if (i < n && version1[i] == '.') ++i;
            if (j < m && version2[j] == '.') ++j;
        }

        return 0;
    }
};
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    
    int charLen(int value)
    {
        int len = 0;
        while (value != 0)
        {
            len++;
            value /= 10;
        }
        return len;
    }

    
    int checkValidity(const string &message, int limit, int segments)
    {
        int charLenSoFar = 0;
        int msgLen = message.length();
        for (int i = 1; i <= segments; i++)
        {
            
            
            
            if (charLenSoFar >= msgLen)
            {
                return -1;
            }

            int formatLen = 3 + charLen(i) + charLen(segments); 
            int remLen = limit - formatLen;

            
            
            if (remLen <= 0)
            {
                return -1;
            }

            
            charLenSoFar += remLen;
        }

        
        
        if (charLenSoFar < msgLen)
        {
            return 1;
        }

        
        
        return 0;
    }

    vector<string> splitMessage(const string &message, int limit)
    {
        int left = 1;
        int right = message.length();
        int segments = INT_MAX;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int segmentValidity = checkValidity(message, limit, mid);

            if (segmentValidity == 0)
            {
                segments = min(segments, mid);
                right = mid - 1;
                left = 1;
            }
            
            else if (segmentValidity == -1)
            {
                right = mid - 1;
            }
            
            else
            {
                left = mid + 1;
            }
        }

        
        if (segments == INT_MAX)
        {
            return {};
        }
        else
        {
            
            return getFormattedStrings(message, limit, segments);
        }
    }

    
    vector<string> getFormattedStrings(const string &message, int limit, int segments)
    {
        vector<string> res(segments);
        int msgLen = message.length();
        int charLenSoFar = 0;

        for (int i = 1; i <= segments; i++)
        {
            string format = "<" + to_string(i) + "/" + to_string(segments) + ">";
            int remaining = limit - format.length();

            int startIdx = charLenSoFar;
            int endIdx = charLenSoFar + remaining;
            
            endIdx = min(msgLen, endIdx);

            res[i - 1] = message.substr(startIdx, endIdx - startIdx) + format;

            
            
            charLenSoFar += remaining;
        }

        return res;
    }
};

class Solution {
    private:
    map<string, string> encodeMap;
    map<string, string> decodeMap;
        string base = "http://tinyurl.com/";
    // Encodes a URL to a shortened URL.
    public:
    string encode(string longUrl) {
        if(!encodeMap.count(longUrl)){
            string shortUrl = base + to_string(encodeMap.size()+1);
            encodeMap[longUrl]=shortUrl;
            decodeMap[shortUrl]=longUrl;

        }
        return encodeMap[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decodeMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
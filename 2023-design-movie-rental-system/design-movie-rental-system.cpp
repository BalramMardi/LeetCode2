class MovieRentingSystem {
    // map (shop,movie) -> price
    unordered_map<long long,int> price;
    // movie -> set of (price, shop) for available copies
    unordered_map<int, set<pair<int,int>>> avail;
    // global set of rented: (price, shop, movie)
    set<tuple<int,int,int>> rented;

    inline long long keyOf(int shop, int movie) {
        return ( (long long)shop << 32 ) | (unsigned int)movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        // n not strictly necessary for internal structures; build from entries
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], p = e[2];
            long long k = keyOf(shop, movie);
            price[k] = p;
            avail[movie].insert({p, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        if (!avail.count(movie)) return ans;
        auto &s = avail[movie];
        for (auto it = s.begin(); it != s.end() && ans.size() < 5; ++it)
            ans.push_back(it->second);
        return ans;
    }

    void rent(int shop, int movie) {
        long long k = keyOf(shop, movie);
        int p = price[k];
        // remove from available and add to rented
        auto itmap = avail.find(movie);
        if (itmap != avail.end()) itmap->second.erase({p, shop});
        rented.insert({p, shop, movie});
    }

    void drop(int shop, int movie) {
        long long k = keyOf(shop, movie);
        int p = price[k];
        // remove from rented and add back to available
        rented.erase({p, shop, movie});
        avail[movie].insert({p, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for (auto it = rented.begin(); it != rented.end() && ans.size() < 5; ++it) {
            int p, shop, movie;
            tie(p, shop, movie) = *it;
            ans.push_back({shop, movie});
        }
        return ans;
    }
};
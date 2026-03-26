class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_set<string> avail;
        unordered_map<string, int> recToIdx;
        unordered_map<string, vector<string>> graph;

        for (string& supply : supplies) {
            avail.insert(supply);
        }

        for (int idx = 0; idx < recipes.size(); idx++) {
            recToIdx[recipes[idx]] = idx;
        }

        vector<int> inDegree(recipes.size(), 0);

        for (int i = 0; i < recipes.size(); i++) {
            for (string& ingredient : ingredients[i]) {
                if (!avail.count(ingredient)) {
                    graph[ingredient].push_back(recipes[i]);
                    inDegree[i]++;
                }
            }
        }

        queue<int> queue;
        for (int recipeIdx = 0; recipeIdx < recipes.size(); recipeIdx++) {
            if (inDegree[recipeIdx] == 0) {
                queue.push(recipeIdx);
            }
        }

        vector<string> createdRecipes;
        while (!queue.empty()) {
            int recipeIdx = queue.front();
            queue.pop();
            string recipe = recipes[recipeIdx];
            createdRecipes.push_back(recipe);

            if (!graph.count(recipe)) continue;

            for (string& dependentRecipe : graph[recipe]) {
                if (--inDegree[recToIdx[dependentRecipe]] == 0) {
                    queue.push(recToIdx[dependentRecipe]);
                }
            }
        }

        return createdRecipes;
    }
};
// https://leetcode.com/problems/longest-consecutive-sequence/description/
using GRAPH = map<int, int>;

void add_directed_edge(GRAPH& graph, int from, int to) {
    graph[from] = to;
}

int dfs(GRAPH& graph, int node) {
    int len = 1;

    while (graph.count(node)) {
        node = graph[node];
        ++len;
    }

    return len;
}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());

        if (nums_set.empty())
            return 0;

        GRAPH graph;

        for (int val : nums_set)
            if (nums_set.count(val + 1))
                add_directed_edge(graph, val, val + 1);

        int max_length = 1;

        for (const auto& [node, neighbour] : graph)
            if (!nums_set.count(node - 1))
                max_length = max(max_length, dfs(graph, node));

        return max_length;
    }
};

#include"graph-b.cpp"
void dfs_inv(size_t start, vector<bool> &visited, stack<int> &prev, adjacency_list g);

stack<int> dfs_start(adjacency_list graph);

void search(size_t v, vector<vector<int>> &matrix, stack<size_t> &stack);

vector<size_t> flery_start(adjacency_list g);

void cycle(adjacency_list graph);

void dfs1 (size_t v, vector<bool> &visited,vector<int> &order, vector<vector<pair<size_t, int>>> g);
 
void dfs2 (size_t v, vector<bool> &visited,vector<int> &component, vector<vector<pair<size_t, int>>> g);

void kosaraju(adjacency_list g);
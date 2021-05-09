#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <stack>
#include <set>
#include "graph.h"
using namespace std;

void dfs_inv(size_t start, vector<bool> &visited, stack<int> &prev, adjacency_list g)
{
    visited[start] = true;
    auto aList = g.get();
    for (auto i : aList[start])
    {
        if (!visited[i.first])
        {
            dfs_inv(i.first, visited, prev, g);
        }
    }
    prev.push(start);
}

stack<int> dfs_start(adjacency_list graph)
{
    size_t size = graph.get_quantity_vertex();
    vector<bool> visited(size, false);
    stack<int> temp;
    for (size_t i = 0; i < size; i++)
    {
        if (!visited[i])
            dfs_inv(i, visited, temp, graph);
    }
    return temp;
}

void search(size_t v, vector<vector<int>> &matrix, stack<size_t> &stack)
{
    for (size_t i = 0; i < matrix.size(); i++)
        if (matrix[v][i] != 0)
        {
            matrix[v][i] = matrix[i][v] = 0;
            search(i, matrix, stack);
        }
    stack.push(v);
}

stack<size_t> flery_start(adjacency_list g)
{
    stack<size_t> temp;
    auto matrix = g.toMatrix();
    search(0, matrix, temp);
    return temp;
}

void cycle(adjacency_list graph)
{
    auto g = graph.toMatrix();
    size_t n = graph.get_quantity_vertex();
    vector<int> deg(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            deg[i] += g[i][j];
    int first = 0;
    while (!deg[first])
        ++first;
    int v1 = -1, v2 = -1;
    bool bad = false;
    for (int i = 0; i < n; ++i)
        if (deg[i] & 1)
            if (v1 == -1)
                v1 = i;
            else if (v2 == -1)
                v2 = i;
            else
                bad = true;
    if (v1 != -1)
        ++g[v1][v2], ++g[v2][v1];
    stack<int> st;
    st.push(first);
    vector<int> res;
    while (!st.empty())
    {
        int v = st.top();
        int i;
        for (i = 0; i < n; ++i)
            if (g[v][i])
                break;
        if (i == n)
        {
            cout << "oh\n";
            res.push_back(v);
            st.pop();
        }
        else
        {
            --g[v][i];
            --g[i][v];
            if (g[v][i] < 0)
                break;
            st.push(i);
        }
    }
    if (v1 != -1)
        for (size_t i = 0; i + 1 < res.size(); ++i)
            if (res[i] == v1 && res[i + 1] == v2 || res[i] == v2 && res[i + 1] == v1)
            {
                vector<int> res2;
                for (size_t j = i + 1; j < res.size(); ++j)
                    res2.push_back(res[j]);
                for (size_t j = 1; j <= i; ++j)
                    res2.push_back(res[j]);
                res = res2;
                break;
            }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (g[i][j])
                bad = true;

    if (bad)
        puts("Нет эйлерова цикла");
    else
        for (size_t i = 0; i < res.size(); ++i)
            cout << res[i] + 1 << " ";
}

void dfs1 (size_t v, vector<bool> &visited,vector<int> &order, vector<vector<pair<size_t, int>>> g) {
	visited[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!visited[ g[v][i].first ])
			dfs1 (g[v][i].first, visited, order, g);
	order.push_back (v);
}
 
void dfs2 (size_t v, vector<bool> &visited,vector<int> &component, vector<vector<pair<size_t, int>>> g) {
	visited[v] = true;
	component.push_back (v);
	for (size_t i=0; i<g[v].size(); ++i)
		if (!visited[ g[v][i].first ])
			dfs1 (g[v][i].first, visited, component, g);
}
 

void kosaraju(adjacency_list g)
{
    auto aList = g.get();
    auto size = g.get_quantity_vertex();
    vector<vector<pair<size_t, int>>> tAList(
        size,
        vector<pair<size_t, int>>());
    for (size_t i = 0; i < aList.size(); i++)
    {
        for (size_t j = 0; j < aList[i].size(); j++)
        {
            tAList[aList[i][j].first].push_back(make_pair(i, aList[i][j].second));
        }
    }
    vector<int> order, component; 
    vector<bool> visited;
    visited.assign(size,false);
    for(size_t i = 0; i < size; i++){
        if(!visited[i])
            dfs1(i,visited,order,aList);
    }
    visited.assign(size,false);
    for(size_t i = 0; i < size; i++){
        int v = order[size-1-i];
        if(!visited[v]){
            dfs2(v,visited,component,tAList);
            for(auto i : component){
                cout << i << " ";
            }
            component.clear();
        }
    }
    cout << endl;

}
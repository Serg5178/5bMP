#include <vector>
#include <iostream>
#include <tuple>
using namespace std;

class adjacency_list
{
private:
    // Pair(вершина, вес)
    vector<vector<pair<size_t, int>>> aList;

public:
    adjacency_list(size_t size)
    {
        add_vertex(size);
    }
    adjacency_list() {}
    void add_edge(size_t out, pair<size_t, int> edge)
    {
        if (out < 0 or out >= aList.size())
        {
            return;
        }
        aList[out].push_back(edge);
    }
    void add_edge(tuple<size_t, size_t, int> edge)
    {
        if (std::get<0>(edge) < 0 || std::get<0>(edge) >= aList.size())
        {
            return;
        }
        aList[std::get<0>(edge)].push_back(make_pair(std::get<1>(edge), std::get<2>(edge)));
    }
    void del_edge(size_t out, size_t to)
    {
        for (auto i = aList[out].begin(); i != aList[out].end(); i++)
        {
            if ((*i).first == to)
            {
                aList[out].erase(i);
                break;
            }
        }
    }
    void add_vertex()
    {
        aList.push_back(vector<pair<size_t, int>>());
    }
    void add_vertex(size_t quantity)
    {
        for (size_t i = 0; i < quantity; i++)
        {
            aList.push_back(vector<pair<size_t, int>>());
        }
    }
    void print()
    {
        for (size_t i = 0; i < aList.size(); i++)
        {
            cout << i << " ";
            for (auto j : aList[i])
            {
                cout << "(" << j.first << "," << j.second << ") ";
            }
            cout << endl;
        }
    }
    //https://csacademy.com/app/graph_editor/
    void print_for_website()
    {
        std::cout << "print for https://csacademy.com/app/graph_editor/\n";
        for (size_t i = 0; i < aList.size(); i++)
        {
            for (auto j : aList[i])
            {
                cout << i << " " << j.first << " " << j.second << endl;
            }
        }
    }
    const vector<vector<pair<size_t, int>>> &get()
    {
        return aList;
    }

    size_t get_quantity_vertex()
    {
        return aList.size();
    }

    vector<vector<int>> toMatrix()
    {
        vector<vector<int>> matrix;
        for (size_t i = 0; i < aList.size(); i++)
        {
            matrix.push_back(vector<int>(aList.size(), 0));
        }
        for (size_t i = 0; i < aList.size(); i++)
        {
            for (size_t j = 0; j < aList[i].size(); j++)
            {
                matrix[i][aList[i][j].first] = aList[i][j].second;
            }
            matrix[i][i] = 0;
        }
        return matrix;
    }

    //vector[i] = (out, to, wight)
    vector<tuple<size_t, size_t, int>> get_edges()
    {
        vector<tuple<size_t, size_t, int>> temp;
        for (size_t i = 0; i < aList.size(); i++)
        {
            for (size_t j = 0; j < aList[i].size(); j++)
            {
                temp.push_back(make_tuple(i, aList[i][j].first, aList[i][j].second));
            }
        }
        return temp;
    }
};
#include <iostream>
#include <iomanip>
#include <stack>
#include"graph-b.h"
using namespace std;

int main()
{
    srand(time(NULL));
    adjacency_list graph;
    pair<size_t, int> edge_array[11] = {
        make_pair(0, 1), make_pair(0, 2), make_pair(0, 3),
        make_pair(0, 4), make_pair(2, 0), make_pair(3, 0),
        make_pair(2, 4), make_pair(3, 1), make_pair(3, 4),
        make_pair(4, 0), make_pair(4, 1)};
    graph.add_vertex(5);
    for (auto i : edge_array)
    {
        graph.add_edge(i.first, make_pair(i.second, 1 + rand() % 10));
    }
    cout << "Graph:\n";
    graph.print();
    graph.print_for_website();
    cout << "Алгоритм Тарьяна:\n";
    auto stack = dfs_start(graph);
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << "\n";
    cout << "Алгоритм Флери:\n";
    auto stack1 = flery_start(graph);
    if(stack1.empty()){
        cout << "Нет эйлерова цикла";
    } else {
        for(auto i : stack1){
            cout << i << " ";
        }
    }
    cout << "\n";
    cout << "Алгоритм на основе циклов:\n";
    cycle(graph);
    cout << "Алгоритм Косарайю:\n";
    kosaraju(graph);
    return 0;
}
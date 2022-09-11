#include <bits/stdc++.h>
using namespace std;

void dfs_topo_sort(map<int, vector<int>> graph, int u, vector<int> &visited_node, stack<int> &s)
{
    visited_node[u] = 1;

    for (auto x : graph[u])
    {
        // If the node is not visited, visit it
        if (visited_node[x] == 0)
            dfs_topo_sort(graph, x, visited_node, s); // recursive call
    }
    s.push(u);
}

void catch_loop(map<int, vector<int>> graph, stack<int> &s, vector<int> &topo_sort, bool is_char)
{

    unordered_map<int, int> pos;
    int in_deg = 0;

    while (!s.empty())
    {
        pos[s.top()] = in_deg;
        topo_sort.push_back(s.top());
        in_deg += 1;
        s.pop();
    }

    for (int i = 0; i < graph.size(); i++)
    {
        for (auto x : graph[i])
        {
            if (pos[i] > pos[x])
            {

                cout << "There is a cyclic loop in the graph\n";
                return;
            }
        }
    }

    // to check whether graph has character nodes
    for (int i = 0; i < topo_sort.size(); i++)
    {
        if (is_char == true)
        {
            cout << char('l' + topo_sort[i]) << "\n";
        }
        else
        {
            cout << topo_sort[i] << "\n";
        }
    }
    return;
}

void run_dfs(map<int, vector<int>> graph, bool is_char)
{

    vector<int> visited_node(graph.size() + 1, 0);
    stack<int> s;
    vector<int> topo_sort;

    for (const auto &key : graph)
    {
        if (visited_node[key.first] == 0)
        {
            dfs_topo_sort(graph, key.first, visited_node, s);
        }
    }
    catch_loop(graph, s, topo_sort, is_char);
}

int main()
{
    map<int, vector<int>> graph_1; // creating Graph 1 with just out going nodes at each vertex
    graph_1.insert(pair<int, vector<int>>(1, {2, 5, 6}));
    graph_1.insert(pair<int, vector<int>>(2, {3, 5, 7}));
    graph_1.insert(pair<int, vector<int>>(3, {4}));
    graph_1.insert(pair<int, vector<int>>(4, {5}));
    graph_1.insert(pair<int, vector<int>>(5, {7, 8}));
    graph_1.insert(pair<int, vector<int>>(6, {5, 8}));
    graph_1.insert(pair<int, vector<int>>(7, {4, 8}));
    graph_1.insert(pair<int, vector<int>>(8, {}));
    cout << "DFS Topological sort for Graph 1"
         << "\n";
    run_dfs(graph_1, false);
    cout << "\n";

    map<int, vector<int>> graph_2;
    map<char, int> m{
        {'m', 1},
        {'n', 2},
        {'o', 3},
        {'p', 4},
        {'q', 5},
        {'r', 6},
        {'s', 7},
        {'t', 8},
        {'u', 9},
        {'v', 10},
        {'w', 11},
        {'x', 12},
        {'y', 13},
        {'z', 14},
    };

    // creating Graph 2 with just out going nodes at each vertex
    // this has vertex in char

    graph_2.insert(pair<int, vector<int>>(m['m'], {m['r'], m['q'], m['x']}));
    graph_2.insert(pair<int, vector<int>>(m['n'], {m['q'], m['u'], m['o']}));
    graph_2.insert(pair<int, vector<int>>(m['o'], {m['r'], m['v'], m['s']}));
    graph_2.insert(pair<int, vector<int>>(m['p'], {m['o'], m['s'], m['z']}));
    graph_2.insert(pair<int, vector<int>>(m['q'], {m['t']}));
    graph_2.insert(pair<int, vector<int>>(m['r'], {m['u'], m['y']}));
    graph_2.insert(pair<int, vector<int>>(m['s'], {m['r']}));
    graph_2.insert(pair<int, vector<int>>(m['t'], {}));
    graph_2.insert(pair<int, vector<int>>(m['u'], {m['t']}));
    graph_2.insert(pair<int, vector<int>>(m['v'], {m['w'], m['x']}));
    graph_2.insert(pair<int, vector<int>>(m['w'], {m['z']}));
    graph_2.insert(pair<int, vector<int>>(m['x'], {}));
    graph_2.insert(pair<int, vector<int>>(m['y'], {m['v']}));
    graph_2.insert(pair<int, vector<int>>(m['z'], {}));

    cout << "DFS Topological sort for Graph 2"
         << "\n";
    run_dfs(graph_2, true);
}
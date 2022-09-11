#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

void BFS_Topo_sort(map<int, vector<int>> graph, bool is_char)
{
    vector<int> in_degree(graph.size() + 1, 0);
    queue<int> q;
    vector<int> outcome;

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            in_degree[graph[i][j]]++;
        }
    }

    for (int i = 1; i < in_degree.size(); i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    while (q.size() > 0)
    {
        int node = q.front();
        outcome.push_back(node);
        q.pop();

        for (int i = 0; i < graph[node].size(); i++)
        {
            int pstn = graph[node][i];
            --in_degree[pstn];
            if (in_degree[pstn] == 0)
            {
                q.push(pstn);
            }
        }
    }

    if (outcome.size() != graph.size() - 1)
    {
        cout << "Cyclic loop catched in the graph\n";
        return;
    }

    for (int m = 0; m < outcome.size(); m++)
    {
        if (is_char == true)
        {
            cout << char('l' + outcome[m]) << "\n";
        }
        else
        {
            cout << outcome[m] << "\n";
        }
    }
    return;
}

int main()
{
    // creating graph 1 with outgoing nodes
    map<int, vector<int>> graph_1;
    graph_1.insert(pair<int, vector<int>>(1, {2, 5, 6}));
    graph_1.insert(pair<int, vector<int>>(2, {3, 5, 7}));
    graph_1.insert(pair<int, vector<int>>(3, {4}));
    graph_1.insert(pair<int, vector<int>>(4, {5}));
    graph_1.insert(pair<int, vector<int>>(5, {7, 8}));
    graph_1.insert(pair<int, vector<int>>(6, {5, 8}));
    graph_1.insert(pair<int, vector<int>>(7, {4, 8}));
    graph_1.insert(pair<int, vector<int>>(8, {}));

    cout << "BFS topological sorting of Graph 1 is"
         << "\n";

    BFS_Topo_sort(graph_1, false);

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

    //creating graph 2 with outgoing nodes

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

    cout << "\n";
    cout << "BFS topological sorting of Graph 2 is"
         << "\n";
    BFS_Topo_sort(graph_2, true);
    return 0;
}
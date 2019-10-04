 #include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    unordered_map<T, list<pair<T, int>>> m;

public:
    void addEdge(T u, T v, int dist, bool bidir = true)
    {
        m[u].push_back(make_pair(v, dist));
        if (bidir)
        {
            m[v].push_back(make_pair(u, dist));
        }
    }

    void printAdj()
    {
        for (auto j : m)
        {
            cout << j.first << " -> ";
            //iterate over each list
            for (auto l : j.second)
            {
                cout << "(" << l.first << ") " << l.second;
            }
            cout << endl;
        }
    }

    //DijsktraSSP algorithm
    void disjstraSSP(T src)
    {
        unordered_map<T, int> dist;
        //set all distance to infinity
        for (auto j : m)
        {
            dist[j.first] = INT_MAX;
        }
        //make a set to find out a node with the minimum distance
        set<pair<int, T>> s;
        dist[src] = 0;
        s.insert(make_pair(0, src));

        while (!s.empty())
        {
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());
            //iterate over neighbour/children of the current node
            for (auto childpair : m[node])
            {
                if (nodeDist + childpair.second < dist[childpair.first])
                {
                    //in the set updataion of a particular is not possible we have to remove the old pair ,
                    //and insert the new pair to simulation updation
                    T dest = childpair.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    //insert the new pair
                    dist[dest] = nodeDist + childpair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }
        for (auto d : dist)
        {
            cout << d.first << " located at distance " << d.second << endl;
        }
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.disjstraSSP(1);
}

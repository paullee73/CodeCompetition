class Solution
{
  public:
    TreeNode *topSort(GraphNode *graph)
    {
        stack<Vertex *> stack;
        unordered_set<Vertex *> visited;
        for (Vertex x : graph.getAllVertices())
        {
            if (!visited.find(x))
            {
                topSortUtil(x, stack, visited);
            }
        }
    }

    void topSortUtil(Vertex vertex, stack<Vertex *> stack, unordered_set<Vertex *> visited)
    {
        visited.add(vertex);
        for (Vertex *child : vertex.children())
        {
            if (!visited.find(child))
            {
                topSortUtil(child, stack, visited);
            }
        }
        stack.push(vertex);
    }
};
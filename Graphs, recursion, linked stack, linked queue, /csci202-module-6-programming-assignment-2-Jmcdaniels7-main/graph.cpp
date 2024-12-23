#include "graph.h"
#include <regex>

bool graphType::isEmpty() const
{
    return gSize == 0;
}

void graphType::createGraph(std::string filename)
{
    std::ifstream file;
    std::string IP;
    int index;
    int vertex;
    int adjcentVertex;
    int count = 0;

    if (gSize != 0)
    {
        clearGraph();
    }

    file.open(filename);

    if (!file)
    {
        std::cout << "Unable to open file" << std::endl;
    }
    else
    {
        while (!file.eof())
        {
            getline(file, IP);

            std::regex IPstr {R"(^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$)"};

            if(std::regex_match(IP,IPstr))
            {
                //std::cout << "This is a IP address: " << IP << std::endl;

                IPs.push_back(IP);
                count++;

            }
            else
            {
                gSize = count;
                if (gSize > maxSize)
                {
                    delete[] graph;
                    maxSize = gSize;
                    graph = new unorderedLinkedList<int>[maxSize];
                }
                
                std::istringstream adjStr(IP);
                adjStr >> vertex;
                adjStr >> adjcentVertex;
                while (adjcentVertex != -999)
                {
                    graph[vertex].insert(adjcentVertex);
                    adjStr >> adjcentVertex;
                }
                
            }
            
        }
    }
}

void graphType::clearGraph()
{
    for (int i = 0; i < gSize; i++)
    {
        graph[i].destroyList();
    }
    gSize = 0;
}

std::string graphType::printGraph() const
{
    std::ostringstream out;
    for (int i = 0; i < gSize; i++)
    {
        out << i << " ";
        graph[i].print(out);
        out << std::endl;
    }
    out << std::endl;
    return out.str();
}

graphType::graphType(int size)
{
    maxSize = size;
    gSize = 0;
    graph = new unorderedLinkedList<int>[size];
}

graphType::~graphType()
{
    clearGraph();
    delete[] graph;
}

std::string graphType::depthFirstTraversal()
{
    bool *visited;
    visited = new bool[gSize];
    std::string out = "";
    for (int i = 0; i < gSize; i++)
        visited[i] = false;
    for (int i = 0; i < gSize; i++)
    {
        if (!visited[i])
            dft(i, visited, out);
    }
    delete[] visited;
    return out;
}

std::string graphType::dftAtVertex(int vertex)
{
    bool *visited;
    visited = new bool[gSize];
    for (int i = 0; i < gSize; i++)
        visited[i] = false;
    std::string out = "";
    dft(vertex, visited, out);
    delete[] visited;
    return out;
}

std::string graphType::breadthFirstTraversal()
{
    linkedQueue<int> queue;
    bool *visited;
    visited = new bool[gSize];
    for (int i = 0; i < gSize; i++)
        visited[i] = false;
    std::string out = "";
    linkedListIterator<int> graphIt;
    for (int i = 0; i < gSize; i++)
    {
        if (!visited[i])
        {
            queue.enqueue(i);
            visited[i] = true;
            out = out + " " + std::to_string(i) + " ";
            while (!queue.isEmptyQueue())
            {
                int u = queue.dequeue();
                for (graphIt = graph[u].begin(); graphIt != graph[u].end(); ++graphIt)
                {
                    int w = *graphIt;
                    if (!visited[w])
                    {
                        queue.enqueue(w);
                        visited[w] = true;
                        out = out + " " + std::to_string(w) + " ";
                    }
                }
            }
        }
    }
    delete[] visited;
    return out;
}

void graphType::dft(int v, bool visited[], std::string &output)
{
    visited[v] = true;
    output = output + " " + std::to_string(v) + " ";
    linkedListIterator<int> graphIt;
    for (graphIt = graph[v].begin(); graphIt != graph[v].end(); ++graphIt)
    {
        int w = *graphIt;
        if (!visited[w])
            dft(w, visited, output);
    }
}

bool graphType::connected(int start, int finish,bool visited[], linkedStack<int> &nodeStack)
{
    visited[start] = true;
    linkedListIterator<int> graphIt;
    for (graphIt = graph[start].begin(); graphIt != graph[start].end(); ++graphIt)
    {
        int v = *graphIt;
        if(!visited[v])
        {
            if (v == finish)
            {
                //while iterator equal to finish we returned true
                nodeStack.push(v);
                return true;
            }
            else
            {
                bool found = connected(v, finish, visited, nodeStack);

                if (found)
                {
                    nodeStack.push(v);
                    return found;
                }
            }
        }
    }
    //we return false if the path is stopped before reaching finish
    return false;
}

std::string graphType::findPath(std::string start, std::string finish)
{
    int s = -1;
    int f = -1;
    std::string c = " ";
    linkedStack<int> stack;
    linkedListIterator<int> graphIt;

    bool *visited;
    visited = new bool[gSize];

    for (int i = 0; i < IPs.size(); i++)
    {
        if (IPs[i] == start)
        {
            s = i;
        }
        if (IPs[i] == finish)
        {
            f = i;
        }
    }

    std::cout << "Finding path from " << start << " to " << finish << std::endl;

    if (s == -1 || f == -1)
    {
        return " No path was found from " + start + " to " + finish;
        
    }

    for(int i = 0; i < gSize; i++)
    {
        visited[i] = false;
    }

    // it seems like it is going through the adjanecny list correctly but
    // maybe not from 5 to 5 adjacency to 5
    // I tried fixing this with previous connected function
        
    // changed it back because connected seems to be needed
    if (connected(s, f, visited, stack))
    {
        stack.push(s);
        c = IPs[stack.pop()];

        while(!stack.isEmptyStack())
        {
            c += + "-->" + IPs[stack.pop()];

        }
    }
    else
    {
        c = " No path was found from " + start + " to " + finish;
    }

    delete[] visited;
    return c;
   
}

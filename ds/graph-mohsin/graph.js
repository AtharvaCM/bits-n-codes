const DefaultDict = require("./defaultDict");

class Graph {
  constructor(vertices) {
    // No of vertices
    this.v = vertices;
    // Default dictionary to store graph
    this.graph = new DefaultDict([]);
  }

  /**
   * Function to add an edge to graph
   * @param v
   * @param w
   */
  addEdge(v, w) {
    // Add w to v_s list
    this.graph[v].push(w);
    console.log("this.graph[v]: ", this.graph[v]);

    // Add v to w_S list
    this.graph[w].push(v);
    console.log("this.graph[w]: ", this.graph[w]);
  }

  /**
   * A recursive function that uses visited[] and parent to detect cycle in subgraph reachable from vertex v
   * @param v vertex to check
   * @param visited list of visited vertices
   * @param parent parent vertex
   */
  isCyclicUtil(v, visited, parent) {
    // Mark the current node as visited
    visited[v] = true;

    for (const i in this.graph[v]) {
      if (visited[i] === false) {
        if (this.isCyclicUtil(i, visited, v)) {
          return true;
        }
      } else if (parent !== i) {
        return true;
      }
    }

    return false;
  }

  /**
   * Returns true if the graph contains a cycle, else false
   * @returns {boolean}
   */
  isCyclic() {
    let visited = [];

    for (let i = 0; i < this.v; i++) {
      visited[i] = false;
    }

    for (let u = 0; u < this.v; u++) {
      // Dont recur for u if already visited
      if (!visited[u]) {
        if (this.isCyclicUtil(u, visited, -1)) {
          return true;
        }
      }
    }

    return false;
  }
}

module.exports = Graph;

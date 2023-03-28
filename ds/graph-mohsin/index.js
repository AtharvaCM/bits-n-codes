// User will enter n entities (e1, e2, ..., en)
// User will enter relationship between the entities (e1-e3, e2-e1, ...)
// Create an algorithm which will prevent user from entering a relationshiop which will form a cycle in the graph

const Graph = require("./graph");

const ENTITIES = ["e1", "e2", "e3", "e4"];

const getAvailableEntities = (entity) => {
  // path traversal logic to figure out valid paths
  return ENTITIES.filter((entity) => entity);
};

console.log("[+] Enter the relationships: ");

ENTITIES.map((entity) => {
  console.log(`[+] Select a realtionship for entity ${entity}`);
  console.log(`[+] Available entities: ${getAvailableEntities(entity)}`);
  console.log("-------------------------------------------------------------");
});

// Sample graph test
const g1 = new Graph(4);
g1.addEdge(1, 2);
g1.isCyclic();

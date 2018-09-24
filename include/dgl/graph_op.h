// Graph operations
#ifndef DGL_GRAPH_OP_H_
#define DGL_GRAPH_OP_H_

#include "graph.h"

namespace dgl {

class GraphOp {
 public:
  /*!
   * \brief Return a disjoint union of the input graphs.
   *
   * The new graph will include all the nodes/edges in the given graphs.
   * Nodes/Edges will be relabled by adding the cumsum of the previous graph sizes
   * in the given sequence order. For example, giving input [g1, g2, g3], where
   * they have 5, 6, 7 nodes respectively. Then node#2 of g2 will become node#7
   * in the result graph. Edge ids are re-assigned similarly.
   *
   * \param graphs A list of input graphs to be unioned.
   * \return the disjoint union of the graphs
   */
  static Graph DisjointUnion(std::vector<const Graph*> graphs);

  /*!
   * \brief Partition the graph into several subgraphs.
   *
   * The graph will be partitioned by the node ids. Edges between partitions
   * will be ignored. This requires the given number of partitions to evenly
   * divides the number of nodes in the graph.
   * 
   * \param num The number of partitions.
   * \return a list of partitioned graphs
   */
  static std::vector<Graph> PartitionByNum(const Graph* graph, size_t num);
};

}  // namespace dgl

#endif  // DGL_GRAPH_OP_H_

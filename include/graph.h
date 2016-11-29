#define GRAPH_H
#ifndef GRAPH_H

class Graph {
  public:
    Graph();
    void insert(Layer *);
    Matrix forward();
    Matrix backward( ERROR );
  private:
  
}

#endif

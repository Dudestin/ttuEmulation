#pragma once
#include <Eigen/Dense>
#include <concepts>
#include <memory>

#include "Object.hpp"

template <unsigned short N,unsigned short CompCapacity,typename CoordinateType>
/*
  Template Params Description
  unsigned short N - N-ary Tree Structure
  unsigned short CompCapacity - Compression Block Node Capacity
  floatType - Using Floating-Point Type
 */
class BVH{
  struct Node{
    char type_id : 2;
    char AABB_Bitmask : 6;
  };

  struct RootNode : Node{
    CoordinateType elem[6];
    struct Node* children[N];
  };

  template <unsigned short M> // Inherit M element from parent node
  struct InternalNode : Node{
    CoordinateType elem[M];
    struct Node* children[N];
  };

  template <unsigned short M> // Inherit M element from parent node
  struct LeafNode : Node{
    CoordinateType elem[M];
    Object* prim;
  };

  struct Compression_Block{
    unsigned short childOffset; // 0 ~ 65535
    struct Node nodes[CompCapacity];
  };

public:
  virtual void insertPrimitive(std::shared_ptr<Object> ptr, Eigen::Vector3f coord){ // return Primitive Id.
    
  }
  virtual void  deletePrimitive(unsigned int id){ // return success:0/failure:-1
    
  }
  unsigned int getPrimitiveCount(){ // return primitive count
    
  }
  unsigned int getCompressionBlockCount(){ // return Compression Block count

  }
};

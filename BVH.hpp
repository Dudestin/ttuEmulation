#pragma once
#include <Eigen/Dense>
#include <concepts>
#include <memory>

template <unsigned short N,unsigned short CompCapacity,typename PrimType,typename CoordinateType>
/*
  Template Params Description
  unsigned short N - N-ary Tree Structure
  unsigned short CompCapacity - Compression Block Node Capacity
  PrimType - Primitive Type
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
    PrimType* prim;
  };

  struct Compression_Block{
    unsigned short childOffset; // 0 ~ 65535
    struct Node nodes[CompCapacity];
  };

  std::shared_ptr<PrimType> Prim;

public:
  unsigned int insertPrimitive(std::shared_ptr<PrimType> prim, Eigen::Vector3f coord){ // return Primitive Id.
    
  }
  int deletePrimitive(unsigned int id){ // return success:0/failure:-1
    
  }
  unsigned int getPrimitiveCount(){ // return primitive count
    
  }
  unsigned int getCompressionBlockCount(){ // return Compression Block count

  }
};

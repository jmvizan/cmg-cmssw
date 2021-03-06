#ifndef TkDetLayers_DetGroupMerger_h
#define TkDetLayers_DetGroupMerger_h

#include "TrackingTools/DetLayers/interface/DetGroup.h"

#pragma GCC visibility push(hidden)
class DetGroupMerger {
public:

  static void orderAndMergeTwoLevels( const std::vector<DetGroup>& one,  
				      const std::vector<DetGroup>& two,
				      std::vector<DetGroup>& result,
				      int firstIndex, 
				      int firstCrossed);
  
  static void mergeTwoLevels( const std::vector<DetGroup>& one,  
			      const std::vector<DetGroup>& two,
			      std::vector<DetGroup>& result);
  
  static void addSameLevel( const std::vector<DetGroup>& gvec, std::vector<DetGroup>& result);
  
  static void doubleIndexSize( std::vector<DetGroup>& vec);
  
  static void incrementAndDoubleSize( std::vector<DetGroup>& vec);
  
};

#pragma GCC visibility pop
#endif

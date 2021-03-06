#ifndef GenericTransientTrackingRecHit_H
#define GenericTransientTrackingRecHit_H

#include "TrackingTools/TransientTrackingRecHit/interface/TransientTrackingRecHit.h"
#include "DataFormats/CLHEP/interface/AlgebraicObjects.h" 

class GenericTransientTrackingRecHit: public TransientTrackingRecHit{
public:
  typedef TrackingRecHit::Type Type;

  virtual ~GenericTransientTrackingRecHit() {delete trackingRecHit_;}

  virtual AlgebraicVector parameters() const {return trackingRecHit_->parameters();}
  virtual AlgebraicSymMatrix parametersError() const {return trackingRecHit_->parametersError();}
  virtual AlgebraicMatrix projectionMatrix() const {return trackingRecHit_->projectionMatrix();}
  virtual int dimension() const {return trackingRecHit_->dimension();}

  // virtual void getKfComponents( KfComponentsHolder & holder ) const { trackingRecHit_->getKfComponents(holder); }
  // NO, because someone might specialize parametersError, projectionMatrix or parameters in the transient rechit
  // and in fact this happens for alignment

  virtual LocalPoint localPosition() const {return trackingRecHit_->localPosition();}
  virtual LocalError localPositionError() const {return trackingRecHit_->localPositionError();}

  virtual bool canImproveWithTrack() const {return false;}

  virtual const TrackingRecHit * hit() const {return trackingRecHit_;}
  

  virtual std::vector<const TrackingRecHit*> recHits() const {
    return ((const TrackingRecHit *)(trackingRecHit_))->recHits();
  }
  virtual std::vector<TrackingRecHit*> recHits() {
    return trackingRecHit_->recHits();
  }

  static RecHitPointer build( const GeomDet * geom, const TrackingRecHit * rh) {
    return RecHitPointer( new GenericTransientTrackingRecHit( geom, *rh));
  }

protected:

  // private constructors enforce usage of builders
  GenericTransientTrackingRecHit(const GeomDet * geom, const TrackingRecHit& rh) :
    TransientTrackingRecHit(geom) {
    trackingRecHit_ = rh.clone();
  }

  /// for derived classes convenience, does not clone!
  GenericTransientTrackingRecHit(const GeomDet * geom, TrackingRecHit* rh) :
    TransientTrackingRecHit(geom,*rh), trackingRecHit_(rh) {}
  
  GenericTransientTrackingRecHit( const GenericTransientTrackingRecHit & other ) :
  TransientTrackingRecHit( other.det(),other) {
    trackingRecHit_ = other.hit()->clone();
  }
  
  TrackingRecHit * trackingRecHit_;
  
 private:
  
  // should not have assignment operator (?)
  GenericTransientTrackingRecHit & operator= (const GenericTransientTrackingRecHit & t) {
    trackingRecHit_ = t.hit()->clone();
    return *(this);
  }

  // hide the clone method for ReferenceCounted. Warning: this method is still 
  // accessible via the bas class TrackingRecHit interface!
   virtual GenericTransientTrackingRecHit * clone() const {
     return new GenericTransientTrackingRecHit(*this);
   }

};

#endif


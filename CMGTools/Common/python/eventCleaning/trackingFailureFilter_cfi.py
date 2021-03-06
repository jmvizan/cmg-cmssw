
import FWCore.ParameterSet.Config as cms

trackingFailureFilterCMG = cms.EDFilter(
  "TrackingFailureFilterCMG",
  # Steven was using AK5PFJets
  JetSource = cms.InputTag('pfJetsAK5'),
  TrackSource = cms.InputTag('generalTracks'),
  # Steven was using a collection of good vertices
  VertexSource = cms.InputTag('offlinePrimaryVertices'),
  DzTrVtxMax = cms.double(1),
  DxyTrVtxMax = cms.double(0.2),
  MinSumPtOverHT = cms.double(0.10),
  TaggingMode = cms.bool(True)
)

/**
   @file    TutCombineScen.h
   @ingroup TutCombineScen
   @brief   Combining scenarios from different region in single exp
   @author  Shrikant Vinchurkar
   @verbatim
    Revision:       $Revision$
    Revision date:  $Date$
    Committed by:   $Author$

    This file is part of the Periscope performance measurement tool.
    See http://www.lrr.in.tum.de/periscope for details.

    Copyright (c) 2005-2014, Technische Universitaet Muenchen, Germany
    See the COPYING file in the base directory of the package for details.
   @endverbatim
 */

/**
   @defgroup TutCombineScen Combining Scenarios
   @ingroup AutotunePlugins
 */

#ifndef TUTORIAL_PLUGIN_H_
#define TUTORIAL_PLUGIN_H_

#include "AutotunePlugin.h"

class TutCombineScen : public IPlugin {
    vector<TuningParameter*> tuningParameters;
    ISearchAlgorithm**       arrSearchAlgorithm;

    std::map<string, Region*>               code_region_candidates;
    std::map<int, double>                   localSearchPath;
    std::vector<std::pair<string, double> > regionExectimeMap;
    Region*                                 selected_region;
    int                                     noSigRegions;

public:
    void initialize( DriverContext*   context,
                     ScenarioPoolSet* pool_set );

    void startTuningStep( void );

    bool analysisRequired( StrategyRequest** strategy );

    void createScenarios( void );

    void prepareScenarios( void );

    void defineExperiment( int               numprocs,
                           bool&             analysisRequired,
                           StrategyRequest** strategy );

    bool restartRequired( string& env,
                          int&    np,
                          string& cmd,
                          bool&   instrumented );

    bool searchFinished( void );

    void finishTuningStep( void );

    bool tuningFinished( void );

    Advice* getAdvice( void );

    void finalize( void );

    void terminate( void );
};

#endif

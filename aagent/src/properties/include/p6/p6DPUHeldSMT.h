/**
   @file    p6DPUHeldSMT.h
   @ingroup Power6Properties
   @brief   Power6 specific property
   @author  Yury Oleynik
   @verbatim
    Revision:       $Revision$
    Revision date:  $Date$
    Committed by:   $Author$

    This file is part of the Periscope Tuning Framework.
    See http://www.lrr.in.tum.de/periscope for details.

    Copyright (c) 2005-2014, Technische Universitaet Muenchen, Germany
    See the COPYING file in the base directory of the package for details.
   @endverbatim
 */


#include "Property.h"
#include "PropertyID.h"


class p6DPUHeldSMT : public Property {
    friend class boost::serialization::access;
    template<class Archive>
    void serialize( Archive& ar, const unsigned int version ) {
        ar& boost::serialization::base_object<Property>( *this );
        ar& phaseCycles;
        ar& stallCycles;
        ar& importance;
        ar& threshold;
        ar& phaseContext;
    }
private:
    INT64    phaseCycles;
    INT64    stallCycles;
    double   importance;
    double   threshold;
    Context* phaseContext;

    p6DPUHeldSMT( void ); // should only be used for serialization

public:
    p6DPUHeldSMT( Context* ct,
                  Context* phaseCt );

    virtual ~p6DPUHeldSMT( void );

    bool condition( void ) const;

    double confidence( void ) const;

    double severity( void ) const;

    Gather_Required_Info_Type request_metrics( void );

    void evaluate( void );

    PropertyID id( void );

    std::string name( void );

    void print( void );

    std::string info( void );

    /**
     * @brief Additional XML property information
     */
    std::string toXMLExtra( void );

    Context* get_phaseContext( void );

    Property* clone( void );
};

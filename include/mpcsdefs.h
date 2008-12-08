/** ============================================================================
 *  @file   mpcsdefs.h
 *
 *  @path   $(DSPLINK)/gpp/inc/usr/
 *
 *  @desc   Global definitions for MPCS module.
 *
 *  @ver    1.60
 *  ============================================================================
 *  Copyright (c) 2002-2008, Texas Instruments Incorporated
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  
 *  *  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  
 *  *  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  
 *  *  Neither the name of Texas Instruments Incorporated nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 *  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *  Contact information for paper mail:
 *  Texas Instruments
 *  Post Office Box 655303
 *  Dallas, Texas 75265
 *  Contact information: 
 *  http://www-k.ext.ti.com/sc/technical-support/product-information-centers.htm?
 *  DCMP=TIHomeTracking&HQS=Other+OT+home_d_contact
 *  ============================================================================
 */


#if !defined (MPCSDEFS_H)
#define MPCSDEFS_H


/*  ----------------------------------- DSP/BIOS LINK Headers       */
#include <dsplink.h>
#include <archdefs.h>

#if defined (DDSP_PROFILE)
#include <profile.h>
#endif


#if defined (__cplusplus)
extern "C" {
#endif /* defined (__cplusplus) */


/** ============================================================================
 *  @const  MPCS_INVALID_ID
 *
 *  @desc   Invalid value for identifier(s) used by the MPCS component
 *  ============================================================================
 */
#define MPCS_INVALID_ID      (Uint32) -1l

/** ============================================================================
 *  @const  MPCS_RESV_LOCKNAME
 *
 *  @desc   Special reserved name prefix of the MPCS object(s) which are not
 *          stored in the entries table of the MPCS region.
 *  ============================================================================
 */
#define MPCS_RESV_LOCKNAME  "DSPLINK_MPCS_RESV"

/** ============================================================================
 *  @const  MPCS_RESV_LOCKNAMELEN
 *
 *  @desc   String length of the special reserved name prefix of the MPCS
 *          object(s) which are not stored in entries table of the MPCS region.
 *  ============================================================================
 */
#define MPCS_RESV_LOCKNAMELEN  17u


/** ============================================================================
 *  @name   MPCS_Attrs
 *
 *  @desc   This structure defines the attributes for creation of MPCS object.
 *
 *  @field  poolId
 *              ID of the pool used to allocate the MPCS object.
 *  ============================================================================
 */
typedef struct MPCS_Attrs_tag {
    Uint16  poolId ;
} MPCS_Attrs ;

/** ============================================================================
 *  @name   MPCS_ShObj
 *
 *  @desc   Forward declaration of MPCS_ShObj.
 *  ============================================================================
 */
typedef struct MPCS_ShObj_tag MPCS_ShObj ;

/** ============================================================================
 *  @name   MPCS_Object
 *
 *  @desc   Forward declaration of MPCS_Object.
 *  ============================================================================
 */
typedef struct MPCS_Object_tag MPCS_Object ;

/** ============================================================================
 *  @name   MPCS_Handle
 *
 *  @desc   Handle to the MPCS object.
 *  ============================================================================
 */
typedef Void * MPCS_Handle ;


/** ============================================================================
 *  @name   MPCS_ProcObj
 *
 *  @desc   This structure defines an object for a single processor used by the
 *          Multiprocessing Critical Section object.
 *
 *  @field  localLock
 *              Local lock to be used for protection on specific processor.
 *              The value stored also depends on the Operating System being used
 *  @field  flag
 *              Flags indicating whether the shared resource is being
 *              claimed by the processor.
 *  @field  freeObject
 *              Contains information about whether the object was allocated
 *              internally, and needs to be freed at the time of MPCS delete.
 *  @field  conflicts
 *              Number of conflicts happened in MPCS Enter.
 *              Defined only when profiling is enabled.
 *  @field  numCalls
 *              Number of calls made to MPCS Enter.
 *              Defined only when profiling is enabled.
 *  ============================================================================
 */
typedef struct MPCS_ProcObj_tag {
         Uint32  localLock ;
         Uint16  flag ;
         Uint16  freeObject ;
#if defined (DDSP_PROFILE)
         Uint16  conflicts ;
         Uint16  numCalls  ;
#endif
} MPCS_ProcObj ;

/** ============================================================================
 *  @name   MPCS_ShObj_tag
 *
 *  @desc   This structure defines the shared Multiprocessor Critical Section
 *          object, which is used for protecting a specific critical section
 *          between multiple processors. The memory for this object is
 *          accessible to the two processors using the MPCS object.
 *
 *  @field  gppMpcsObj
 *              MPCS object for the GPP processor.
 *  @field  gppPadding
 *              Padding for alignment, depending on the platform.
 *  @field  dspMpcsObj
 *              MPCS object for the DSP processor.
 *  @field  dspPadding
 *              Padding for alignment, depending on the platform.
 *  @field  turn
 *              Indicates the processor that owns the turn to enter the critical
 *              section.
 *  @field  padding
 *              Padding for alignment, depending on the platform.
 *  ============================================================================
 */
struct MPCS_ShObj_tag {
volatile MPCS_ProcObj    gppMpcsObj ;
         ADD_PADDING (gppPadding, MPCSOBJ_PROC_PADDING)
volatile MPCS_ProcObj    dspMpcsObj ;
         ADD_PADDING (dspPadding, MPCSOBJ_PROC_PADDING)

volatile Uint16          turn   ;
         ADD_PADDING (padding, MPCS_TURN_PADDING)
} ;

/** ============================================================================
 *  @name   MPCS_Entry
 *
 *  @desc   Global entry structure for an MPCS object. Every MPCS object in the
 *          system is identified through information present in the entry
 *          structure.
 *
 *  @field  ownerProcId
 *              ID of the processor that created the MPCS object.
 *  @field  poolId
 *              ID of the pool used to allocate the MPCS object.
 *  @field  physAddress
 *              Physical address of the MPCS object.
 *  @field  name
 *              Unique system wide name used for identifying the MPCS object.
 *  @field  padding
 *              Padding for alignment, depending on the platform.
 *  ============================================================================
 */
typedef struct MPCS_Entry_tag {
    Uint16       ownerProcId ;
    Uint16       poolId ;
    Pvoid        physAddress ;
    Char8        name [DSP_MAX_STRLEN] ;
    ADD_PADDING  (padding, MPCS_ENTRY_PADDING)
} MPCS_Entry ;

/** ============================================================================
 *  @name   MPCS_Ctrl
 *
 *  @desc   This structure defines the control structure required by the
 *          MPCS component. It contains information about all MPCS objects
 *          shared between the GPP and a specific DSP.
 *
 *  @field  isInitialized
 *              Indicates whether the MPCS region has been initialized.
 *  @field  dspId
 *              ID of the DSP with which the MPCS region is shared.
 *  @field  maxEntries
 *              Maximum number of MPCS instances supported by the MPCS.
 *  @field  ipsId
 *              ID of the IPS to be used (if any). A value of -1 indicates that
 *              no IPS is required by the MPCS.
 *  @field  ipsEventNo
 *              IPS Event number associated with MPCS (if any). A value of -1
 *              indicates that no IPS is required by the MPCS.
 *  @field  dspAddrEntry
 *              Pointer to array in DSP address space of MPCS objects that can
 *              be created.
 *  @field  padding
 *              Padding for alignment, depending on the platform.
 *  @field  lockObj
 *              MPCS lock object to provide mutually exclusive access to the
 *              MPCS region.
 *  ============================================================================
 */
typedef struct MPCS_Ctrl_tag {
    Uint32       isInitialized ;
    Uint32       dspId ;
    Uint32       maxEntries ;
    Uint32       ipsId ;
    Uint32       ipsEventNo ;
    MPCS_Entry * dspAddrEntry ;
    ADD_PADDING  (padding, MPCS_CTRL_PADDING)
    MPCS_ShObj   lockObj ;
} MPCS_Ctrl ;

/** ============================================================================
 *  @name   MPCS_MemInfo
 *
 *  @desc   Contains memory information for the MPCS component.
 *
 *  @field  procId
 *              ID of the processor with which the MPCS region is shared
 *  @field  physAddr
 *              Physical address of the memory region for RingIO
 *  @field  kernAddr
 *              Kernel address of the memory region for RingIO
 *  @field  userAddr
 *              User address of the memory region for RingIO
 *  @field  size
 *              Size of the memory region for RingIO
 *  ============================================================================
 */
typedef struct MPCS_MemInfo_tag {
    ProcessorId procId ;
    Uint32      physAddr ;
    Uint32      kernAddr ;
    Uint32      userAddr ;
    Uint32      size ;
} MPCS_MemInfo ;


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */


#endif /* if !defined (MPCSDEFS_H) */

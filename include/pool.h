/** ============================================================================
 *  @file   pool.h
 *
 *  @path   $(DSPLINK)/gpp/inc/usr/
 *
 *  @desc   Defines signature of POOL API Functions.
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


#if !defined (POOL_H)
#define POOL_H


/*  ----------------------------------- DSP/BIOS Link               */
#include <dsplink.h>
#include <pooldefs.h>


#if defined (__cplusplus)
extern "C" {
#endif



/** ============================================================================
 *  @func   POOL_open
 *
 *  @desc   This function opens a specific pool referenced by the pool Id
 *          provided.
 *
 *  @arg    poolId
 *              Pool Identification number.
 *  @arg    params
 *              POOL Open specific parameters.
 *
 *  @ret    DSP_SOK
 *              Operation completed successfully.
 *          DSP_SALREADYOPENED
 *              The specified POOL has already been opened.
 *          DSP_EACCESSDENIED
 *              Access to the DSP is denied.
 *          DSP_EINVALIDARG
 *              Invalid argument.
 *          DSP_EMEMORY
 *              Memory error.
 *          DSP_EFAIL
 *              General failure.
 *
 *  @enter  Pool ID must be less than maximum allowed value.
 *          PROC_attach has been successful.
 *
 *  @leave  None.
 *
 *  @see    POOL_close ()
 *  ============================================================================
 */
EXPORT_API
DSP_STATUS
POOL_open (IN PoolId poolId, IN Pvoid params) ;


/** ============================================================================
 *  @func   POOL_close
 *
 *  @desc   This function closes a specific pool whose pool id is provided.
 *
 *  @arg    poolId
 *              Pool Identification number.
 *
 *  @ret    DSP_SOK
 *              Operation completed successfully.
 *          DSP_SCLOSED
 *              The final process has closed the specified POOL.
 *          DSP_EINVALIDARG
 *              Invalid argument.
 *          DSP_EMEMORY
 *              Memory error.
 *          DSP_EACCESSDENIED
 *              The POOL was not opened.
 *          DSP_EFAIL
 *              General failure.
 *
 *  @enter  Pool ID must be less than maximum allowed value.
 *          All buffers allocated using POOL_alloc have been free'd using
 *          POOL_free.
 *
 *  @leave  None.
 *
 *  @see    POOL_open ()
 *  ============================================================================
 */
EXPORT_API
DSP_STATUS
POOL_close (IN PoolId poolId) ;


/** ============================================================================
 *  @func   POOL_alloc
 *
 *  @desc   This function allocates a buffer of the specified size from a pool.
 *
 *  @arg    poolId
 *              Pool Identification number.
 *  @arg    bufPtr
 *              Location to receive a pointer to the allocated buffer.
 *  @arg    size
 *              Size of buffer to be allocated.
 *
 *  @ret    DSP_SOK
 *              Operation completed successfully.
 *          DSP_EINVALIDARG
 *              Invalid argument.
 *          DSP_EMEMORY
 *              Memory error.
 *          DSP_EFAIL
 *              General failure.
 *
 *  @enter  Pool ID must be less than maximum allowed value.
 *          bufPtr must be a valid pointer.
 *          size must be greater than 0.
 *          POOL_open has been successful.
 *
 *  @leave  None.
 *
 *  @see    POOL_free ()
 *  ============================================================================
 */
EXPORT_API
DSP_STATUS
POOL_alloc (IN PoolId poolId, OUT Pvoid * bufPtr, IN Uint32 size) ;


/** ============================================================================
 *  @func   POOL_free
 *
 *  @desc   This function frees a buffer into the specified pool.
 *
 *  @arg    poolId
 *              Pool Identification number.
 *  @arg    buf
 *             Pointer to the buffer to be freed.
 *  @arg    size
 *              Size of buffer to be freed.
 *
 *  @ret    DSP_SOK
 *              Operation completed successfully.
 *          DSP_EINVALIDARG
 *              Invalid argument.
 *          DSP_EMEMORY
 *              Memory error.
 *          DSP_EFAIL
 *              General failure.
 *
 *  @enter  Pool ID must be less than maximum allowed value.
 *          buf must be a valid pointer.
 *          size must be greater than 0.
 *          POOL_alloc has been successful.
 *
 *  @leave  None.
 *
 *  @see    POOL_alloc ()
 *  ============================================================================
 */
EXPORT_API
DSP_STATUS
POOL_free (IN PoolId poolId, IN Pvoid buf, IN Uint32 size) ;


/** ============================================================================
 *  @func   POOL_translateAddr
 *
 *  @desc   This function translates addresses between two address spaces for a
 *          buffer that was allocated from the pool.
 *
 *  @arg    poolId
 *              Pool Identification number.
 *  @arg    dstAddr
 *             Location to receive the translated address.
 *  @arg    dstAddrType
 *             Type of address to be translated to.
 *  @arg    srcAddr
 *             Address of the buffer to be translated.
 *  @arg    srcAddrType
 *             Type of address of the buffer to be translated.
 *
 *  @ret    DSP_SOK
 *              Operation completed successfully.
 *          DSP_EINVALIDARG
 *              Invalid argument.
 *          DSP_ENOTFOUND
 *              Information about specified buffer was not available.
 *          DSP_EFAIL
 *              General failure.
 *
 *  @enter  Pool ID must be less than maximum allowed value.
 *          dstAddr must be a valid pointer.
 *          dstAddrType must be a valid address type.
 *          srcAddr must be a valid pointer.
 *          srcAddrType must be a valid address type.
 *
 *  @leave  None.
 *
 *  @see    None.
 *  ============================================================================
 */
EXPORT_API
DSP_STATUS
POOL_translateAddr (IN  PoolId           poolId,
                    OUT Pvoid *          dstAddr,
                    IN  AddrType         dstAddrType,
                    IN  Pvoid            srcAddr,
                    IN  AddrType         srcAddrType) ;


/** ============================================================================
 *  @func   POOL_getPoolId
 *
 *  @desc   This function gets the pool id of the buffer that was allocated from
 *          the pool.
 *
 *  @arg    procId
 *             Processor Identifier.
 *  @arg    addr
 *             Address of the buffer whose pool id has to be determined.
 *  @arg    addrType
 *             Type of address of the buffer whose pool id has to be determined.
 *  @arg    poolId
 *              Location to receive pool id number.
 *
 *  @ret    DSP_SOK
 *              Operation completed successfully.
 *          DSP_EINVALIDARG
 *              Invalid argument.
 *          DSP_ENOTFOUND
 *              Specified buffer was not present in any pools.
 *          DSP_EFAIL
 *              General failure.
 *
 *  @enter  addr must be a valid pointer.
 *          addrType must be a valid address type.
 *          poolId must be a valid pointer.
 *
 *  @leave  None.
 *
 *  @see    None.
 *  ============================================================================
 */
EXPORT_API
DSP_STATUS
POOL_getPoolId (IN  ProcessorId procId,
                IN  Pvoid     addr,
                IN  AddrType  addrType,
                OUT PoolId *  poolId) ;


/** ============================================================================
 *  @func   POOL_writeback
 *
 *  @desc   This function write backs the content of the buffer to peer's
 *
 *  @arg    poolId
 *              Pool Identification number.
 *  @arg    buf
 *             Pointer to the buffer to be invalidated.
 *  @arg    size
 *              Size of buffer to be freed.
 *
 *  @ret    DSP_SOK
 *              Operation completed successfully.
 *          DSP_EINVALIDARG
 *              Invalid argument.
 *          DSP_EMEMORY
 *              Memory error.
 *          DSP_EFAIL
 *              General failure.
 *
 *  @enter  Pool ID must be less than maximum allowed value.
 *          buf must be a valid pointer.
 *          size must be greater than 0.
 *
 *  @leave  None.
 *
 *  @see    POOL_invalidate ()
 *  ============================================================================
 */
EXPORT_API
DSP_STATUS
POOL_writeback (IN PoolId poolId, IN Pvoid buf, IN Uint32 size) ;


/** ============================================================================
 *  @func   POOL_invalidate
 *
 *  @desc   This function invalidates the content of the buffer.
 *
 *  @arg    poolId
 *              Pool Identification number.
 *  @arg    buf
 *             Pointer to the buffer to be invalidated.
 *  @arg    size
 *              Size of buffer to be freed.
 *
 *  @ret    DSP_SOK
 *              Operation completed successfully.
 *          DSP_EINVALIDARG
 *              Invalid argument.
 *          DSP_EMEMORY
 *              Memory error.
 *          DSP_EFAIL
 *              General failure.
 *
 *  @enter  Pool ID must be less than maximum allowed value.
 *          buf must be a valid pointer.
 *          size must be greater than 0.
 *
 *  @leave  None.
 *
 *  @see    POOL_writeback ()
 *  ============================================================================
 */
EXPORT_API
DSP_STATUS
POOL_invalidate (IN PoolId poolId, IN Pvoid buf, IN Uint32 size) ;


/** ============================================================================
 *  @deprecated The deprecated API POOL_Open has been replaced
 *              with POOL_open.
 *              This has been done to follow DSP/BIOS codinf guidelines and
 *              have a uniform naming convention for the API's on both GPP
 *              as well as DSP.
 *
 *  ============================================================================
 */
#define POOL_Open                  POOL_open

/** ============================================================================
 *  @deprecated The deprecated API POOL_Close has been replaced
 *              with POOL_close.
 *              This has been done to follow DSP/BIOS codinf guidelines and
 *              have a uniform naming convention for the API's on both GPP
 *              as well as DSP.
 *
 *  ============================================================================
 */
#define POOL_Close                 POOL_close

/** ============================================================================
 *  @deprecated The deprecated API POOL_Alloc has been replaced
 *              with POOL_alloc.
 *              This has been done to follow DSP/BIOS codinf guidelines and
 *              have a uniform naming convention for the API's on both GPP
 *              as well as DSP.
 *
 *  ============================================================================
 */
#define POOL_Alloc                 POOL_alloc

/** ============================================================================
 *  @deprecated The deprecated API POOL_Free has been replaced
 *              with POOL_free.
 *              This has been done to follow DSP/BIOS codinf guidelines and
 *              have a uniform naming convention for the API's on both GPP
 *              as well as DSP.
 *
 *  ============================================================================
 */
#define POOL_Free                  POOL_free

/** ============================================================================
 *  @deprecated The deprecated API POOL_TranslateAddr has been replaced
 *              with POOL_translateAddr.
 *              This has been done to follow DSP/BIOS codinf guidelines and
 *              have a uniform naming convention for the API's on both GPP
 *              as well as DSP.
 *
 *  ============================================================================
 */
#define POOL_TranslateAddr         POOL_translateAddr


#if defined (__cplusplus)
}
#endif


#endif /* !defined (POOL_H) */

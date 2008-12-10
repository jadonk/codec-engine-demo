/** ============================================================================
 *  @file   drvdefs.h
 *
 *  @path   $(DSPLINK)/gpp/inc/sys/Linux/
 *
 *  @desc   Linux module driver interface file.
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


#if !defined (DRV_PMGR_H)
#define DRV_PMGR_H


#if defined (__cplusplus)
extern "C" {
#endif /* defined (__cplusplus) */


/*  ----------------------------------- DSP/BIOS LINK Headers       */
#include <dsplink.h>
#include <_dsplink.h>
#include <procdefs.h>
#include <linkcfgdefs.h>
#include <_idm_usr.h>
#if defined (POOL_COMPONENT)
#include <pooldefs.h>
#endif /* if defined (POOL_COMPONENT) */
#if defined (MSGQ_COMPONENT)
#include <msgqdefs.h>
#endif /* if defined (MSGQ_COMPONENT) */
#if defined (CHNL_COMPONENT)
#include <chnldefs.h>
#endif /* if defined (CHNL_COMPONENT) */
#if defined (RINGIO_COMPONENT)
#include <_ringiodefs.h>
#include <ringiodefs.h>
#endif /* if defined (RINGIO_COMPONENT) */
#if defined (MPCS_COMPONENT)
#include <mpcsdefs.h>
#endif /* if defined (MPCS_COMPONENT) */
#if defined (MPLIST_COMPONENT)
#include <mplistdefs.h>
#endif /* if defined (MPLIST_COMPONENT) */

/*  ----------------------------------- Profiling                   */
#if defined (DDSP_PROFILE)
#include <profile.h>
#endif /* #if defined (DDSP_PROFILE) */


/*  ============================================================================
 *  @const  BASE_CMD
 *
 *  @desc   Base command id to be used for trap/ioctl.
 *  ============================================================================
 */
#define BASE_CMD                           0x6B00

/*  ============================================================================
 *  @macro  CMD_PROC_XXXX
 *
 *  @desc   Command ids for PROC functions.
 *  ============================================================================
 */
#define PROC_BASE_CMD                      (BASE_CMD + 0x100)
#define CMD_PROC_SETUP                     (PROC_BASE_CMD + 1)
#define CMD_PROC_DESTROY                   (PROC_BASE_CMD + 2)
#define CMD_PROC_START                     (PROC_BASE_CMD + 3)
#define CMD_PROC_STOP                      (PROC_BASE_CMD + 4)
#define CMD_PROC_LOAD                      (PROC_BASE_CMD + 5)
#define CMD_PROC_LOADSECTION               (PROC_BASE_CMD + 6)
#define CMD_PROC_DETACH                    (PROC_BASE_CMD + 7)
#define CMD_PROC_ATTACH                    (PROC_BASE_CMD + 8)
#define CMD_PROC_GETSTATE                  (PROC_BASE_CMD + 9)
#define CMD_PROC_CONTROL                   (PROC_BASE_CMD + 10)
#define CMD_PROC_READ                      (PROC_BASE_CMD + 11)
#define CMD_PROC_WRITE                     (PROC_BASE_CMD + 12)
#define CMD_PROC_GETSYMBOLADDRESS          (PROC_BASE_CMD + 13)
#define CMD_PROC_ISLASTDESTROY             (PROC_BASE_CMD + 14)
#define CMD_PROC_ISLASTDETACH              (PROC_BASE_CMD + 15)

#if defined (DDSP_PROFILE)
#define CMD_PROC_INSTRUMENT                (PROC_BASE_CMD + 16)
#endif

#if defined (DDSP_DEBUG)
#define CMD_PROC_DEBUG                     (PROC_BASE_CMD + 17)
#endif

#define CMD_PROC_CLEANUP                   (PROC_BASE_CMD + 18)
#define CMD_PROC_ADDRTRANSLATE             (PROC_BASE_CMD + 19)


#if defined (CHNL_COMPONENT)
/*  ============================================================================
 *  @macro  CMD_CHNL_XXXX
 *
 *  @desc   Command ids for CHNL functions.
 *  ============================================================================
 */
#define CHNL_BASE_CMD                      (BASE_CMD + 0x200)
#define CMD_CHNL_CREATE                    (CHNL_BASE_CMD + 1)
#define CMD_CHNL_DELETE                    (CHNL_BASE_CMD + 2)
#define CMD_CHNL_ISSUE                     (CHNL_BASE_CMD + 3)
#define CMD_CHNL_RECLAIM                   (CHNL_BASE_CMD + 4)
#define CMD_CHNL_ALLOCATEBUFFER            (CHNL_BASE_CMD + 5)
#define CMD_CHNL_FREEBUFFER                (CHNL_BASE_CMD + 6)
#define CMD_CHNL_IDLE                      (CHNL_BASE_CMD + 7)
#define CMD_CHNL_FLUSH                     (CHNL_BASE_CMD + 8)
#define CMD_CHNL_CONTROL                   (CHNL_BASE_CMD + 9)


#if defined (DDSP_PROFILE)
#define CMD_CHNL_INSTRUMENT                (CHNL_BASE_CMD + 10)
#endif /* if defined (DDSP_PROFILE) */


#if defined (DDSP_DEBUG)
#define CMD_CHNL_DEBUG                     (CHNL_BASE_CMD + 11)
#endif /* if defined (DDSP_DEBUG) */
#endif /* if defined (CHNL_COMPONENT) */


/*  ============================================================================
 *  @macro  CMD_DRV_XXXX
 *
 *  @desc   Command ids for DRV specific calls.
 *  ============================================================================
 */
#define DRV_BASE_CMD                       (BASE_CMD + 0x300)
#if defined (CHNL_COMPONENT)
#define CMD_DRV_GETCHNLMAPTABLE_ADDRESS    (DRV_BASE_CMD + 1)
#endif /* if defined (CHNL_COMPONENT) */


#if defined (MSGQ_COMPONENT)
/*  ============================================================================
 *  @macro  CMD_MSGQ_XXXX
 *
 *  @desc   Command ids for CHNL functions.
 *  ============================================================================
 */
#define MSGQ_BASE_CMD                      (BASE_CMD + 0x400)
#define CMD_MSGQ_TRANSPORTOPEN             (MSGQ_BASE_CMD + 1)
#define CMD_MSGQ_TRANSPORTCLOSE            (MSGQ_BASE_CMD + 2)
#define CMD_MSGQ_OPEN                      (MSGQ_BASE_CMD + 3)
#define CMD_MSGQ_CLOSE                     (MSGQ_BASE_CMD + 4)
#define CMD_MSGQ_LOCATE                    (MSGQ_BASE_CMD + 5)
#define CMD_MSGQ_LOCATEASYNC               (MSGQ_BASE_CMD + 6)
#define CMD_MSGQ_RELEASE                   (MSGQ_BASE_CMD + 7)
#define CMD_MSGQ_ALLOC                     (MSGQ_BASE_CMD + 8)
#define CMD_MSGQ_FREE                      (MSGQ_BASE_CMD + 9)
#define CMD_MSGQ_PUT                       (MSGQ_BASE_CMD + 10)
#define CMD_MSGQ_GET                       (MSGQ_BASE_CMD + 11)
#define CMD_MSGQ_SETERRORHANDLER           (MSGQ_BASE_CMD + 12)
#define CMD_MSGQ_COUNT                     (MSGQ_BASE_CMD + 13)


#if defined (DDSP_PROFILE)
#define CMD_MSGQ_INSTRUMENT                (MSGQ_BASE_CMD + 14)
#endif /* if defined (DDSP_PROFILE) */


#if defined (DDSP_DEBUG)
#define CMD_MSGQ_DEBUG                     (MSGQ_BASE_CMD + 15)
#endif /* if defined (DDSP_DEBUG) */


#endif /* if defined (MSGQ_COMPONENT) */

/*  ============================================================================
 *  @macro  CMD_POOL_XXXX
 *
 *  @desc   Command ids for POOL.
 *  ============================================================================
 */
#define POOL_BASE_CMD                      (BASE_CMD + 0x600)
#define CMD_POOL_OPEN                      (POOL_BASE_CMD + 1)
#define CMD_POOL_CLOSE                     (POOL_BASE_CMD + 2)
#define CMD_POOL_ALLOC                     (POOL_BASE_CMD + 3)
#define CMD_POOL_FREE                      (POOL_BASE_CMD + 4)
#define CMD_POOL_TRANSLATEADDR             (POOL_BASE_CMD + 5)
#define CMD_POOL_RECONFIGURE               (POOL_BASE_CMD + 6)
#define CMD_POOL_WRITEBACK                 (POOL_BASE_CMD + 7)
#define CMD_POOL_INVALIDATE                (POOL_BASE_CMD + 8)

#if defined (MPCS_COMPONENT)
/*  ============================================================================
 *  @macro  CMD_MPCS_XXXX
 *
 *  @desc   Command ids for MPCS.
 *  ============================================================================
 */
#define MPCS_BASE_CMD                      (BASE_CMD + 0x700)
#define CMD_MPCS_MAPREGION                 (MPCS_BASE_CMD + 1)
#define CMD_MPCS_UNMAPREGION               (MPCS_BASE_CMD + 2)
#endif /* if defined (MPCS_COMPONENT) */

/*  ============================================================================
 *  @macro  CMD_NOTIFY_XXXX
 *
 *  @desc   Command ids for NOTIFY.
 *  ============================================================================
 */
#define NOTIFY_BASE_CMD                    (BASE_CMD + 0x800)
#define CMD_NOTIFY_INITIALIZE              (NOTIFY_BASE_CMD + 1)
#define CMD_NOTIFY_FINALIZE                (NOTIFY_BASE_CMD + 2)
#define CMD_NOTIFY_REGISTER                (NOTIFY_BASE_CMD + 3)
#define CMD_NOTIFY_UNREGISTER              (NOTIFY_BASE_CMD + 4)
#define CMD_NOTIFY_NOTIFY                  (NOTIFY_BASE_CMD + 5)

#if defined (DDSP_PROFILE)
#define CMD_NOTIFY_INSTRUMENT              (NOTIFY_BASE_CMD + 6)
#endif

/*  ============================================================================
 *  @macro  CMD_RINGIO_XXXX
 *
 *  @desc   Command ids for RINGIO.
 *  ============================================================================
 */
#define RINGIO_BASE_CMD                    (BASE_CMD + 0x810)
#define CMD_RINGIO_MAPREGION               (RINGIO_BASE_CMD + 1)
#define CMD_RINGIO_UNMAPREGION             (RINGIO_BASE_CMD + 2)

/*  ============================================================================
 *  @macro  CMD_MPLIST_XXXX
 *
 *  @desc   Command ids for MPLIST.
 *  ============================================================================
 */
#define MPLIST_BASE_CMD                    (BASE_CMD + 0x820)
#define CMD_MPLIST_MAPREGION               (MPLIST_BASE_CMD + 1)
#define CMD_MPLIST_UNMAPREGION             (MPLIST_BASE_CMD + 2)

/*  ============================================================================
 *  @macro  CMD_IDM_XXXX
 *
 *  @desc   Command ids for IDM component.
 *  ============================================================================
 */
#define IDM_BASE_CMD                       (BASE_CMD + 0x850)
#define CMD_IDM_INIT                       (IDM_BASE_CMD + 1)
#define CMD_IDM_EXIT                       (IDM_BASE_CMD + 2)
#define CMD_IDM_CREATE                     (IDM_BASE_CMD + 3)
#define CMD_IDM_DELETE                     (IDM_BASE_CMD + 4)
#define CMD_IDM_ACQUIREID                  (IDM_BASE_CMD + 5)
#define CMD_IDM_RELEASEID                  (IDM_BASE_CMD + 6)

/** ============================================================================
 *  @macro  DRV_INITIALIZE
 *
 *  @desc   OS dependent definition of initialization function.
 *  ============================================================================
 */
#define DRV_INITIALIZE(handle)         DRV_Initialize (handle, NULL)

/** ============================================================================
 *  @macro  DRV_FINALIZE
 *
 *  @desc   OS dependent definition of finalization function.
 *  ============================================================================
 */
#define DRV_FINALIZE(handle)           DRV_Finalize (handle, NULL)

/** ============================================================================
 *  @macro  DRV_INVOKE
 *
 *  @desc   OS dependent definition to call functions through ioctl's.
 *  ============================================================================
 */
#define DRV_INVOKE(handle,cmd,arg1)    DRV_Invoke (handle, cmd, arg1, NULL)


/** ============================================================================
 *  @name   CMD_Args
 *
 *  @desc   Union defining arguments to be passed to ioctl calls. For the
 *          explanation of individual field please see the corresponding APIs.

 *  @field  apiStatus
 *              Status returned by this API.
 *          apiArgs
 *              Union representing arguments for different APIs.
 *  ============================================================================
 */
typedef struct CMD_Args_tag {
    DSP_STATUS apiStatus ;
    union {
        struct {
            LINKCFG_Object * linkCfg ;
        } procSetupArgs ;

        struct {
            Char8 dummy ;
        } procDestroyArgs ;

        struct {
            ProcessorId     procId ;
        } procStartArgs ;

        struct {
            ProcessorId     procId ;
        } procStopArgs ;

        struct {
            ProcessorId     procId     ;
            Char8 *         symbolName ;
            Uint32 *        dspAddr    ;
        } procGetSymbolAddressArgs ;

        struct {
            ProcessorId     procId ;
            PROC_Attrs *    attr   ;
        } procAttachArgs ;

        struct {
            ProcessorId    procId ;
        } procDetachArgs ;

        struct {
            ProcessorId    procId    ;
            Char8 *        imagePath ;
            Uint32         argc      ;
            Char8 **       argv      ;
        } procLoadArgs ;

        struct {
            ProcessorId    procId   ;
            Uint32         dspAddr  ;
            Uint32         numBytes ;
            Pvoid          buffer   ;
        } procReadArgs ;

        struct {
            ProcessorId    procId   ;
            Uint32         dspAddr  ;
            Uint32         numBytes ;
            Pvoid          buffer   ;
        } procWriteArgs ;

        struct {
            ProcessorId     procId    ;
            PROC_State *    procState ;
        } procGetStateArgs ;

        struct {
            ProcessorId     procId ;
            Int32           cmd    ;
            Pvoid           arg    ;
        } procControlArgs ;

        struct {
            ProcessorId     procId    ;
            Char8 *         imagePath ;
            Uint32          sectID    ;
        } procLoadSectionArgs ;

        struct {
            Bool            lastDestroy ;
        } procIsLastDestroyArgs ;

        struct {
            ProcessorId     procId     ;
            Bool            lastDetach ;
        } procIsLastDetachArgs ;

#if defined (DDSP_PROFILE)
        struct {
            ProcessorId        procId    ;
            PROC_Instrument *  procStats ;
        } procInstrumentArgs ;
#endif

#if defined (DDSP_DEBUG)
        struct {
            ProcessorId       procId ;
        } procDebugArgs ;
#endif

        struct {
            ProcessorId     procId  ;
            Uint32          bufAddr ;
            Uint32 *        physAddr ;
        } procAddrTranslateArgs ;

#if defined (CHNL_COMPONENT)
        struct {
            ProcessorId     procId ;
            ChannelId       chnlId ;
            ChannelAttrs *  attrs  ;
        } chnlCreateArgs ;

        struct {
            ProcessorId     procId ;
            ChannelId       chnlId ;
        } chnlDeleteArgs ;

        struct {
            ProcessorId     procId ;
            ChannelId       chnlId ;
            ChannelIOInfo * ioReq  ;
        } chnlIssueArgs ;

        struct {
            ProcessorId     procId  ;
            ChannelId       chnlId  ;
            Uint32          timeout ;
            ChannelIOInfo * ioReq   ;
        } chnlReclaimArgs ;

        struct {
            ProcessorId     procId   ;
            ChannelId       chnlId   ;
            Char8 **        bufArray ;
            Uint32          size     ;
            Uint32          numBufs  ;
        } chnlAllocateBufferArgs ;

        struct {
            ProcessorId     procId   ;
            ChannelId       chnlId   ;
            Char8 **        bufArray ;
            Uint32          numBufs  ;
        } chnlFreeBufferArgs ;

        struct {
            ProcessorId     procId ;
            ChannelId       chnlId ;
        } chnlFlushArgs ;

        struct {
            ProcessorId     procId ;
            ChannelId       chnlId ;
        } chnlIdleArgs ;

        struct {
            ProcessorId     procId ;
            ChannelId       chnlId ;
            Int32           cmd    ;
            Pvoid           arg    ;
        } chnlControlArgs ;

#if defined (DDSP_PROFILE)
        struct {
            ProcessorId       procId    ;
            ChannelId         chnlId    ;
            CHNL_Instrument * chnlStats ;
        } chnlInstrumentArgs ;
#endif

#if defined (DDSP_DEBUG)
        struct {
            ProcessorId       procId ;
            ChannelId         chnlId ;
        } chnlDebugArgs ;
#endif
#endif /* if defined (CHNL_COMPONENT) */

        struct {
            Void * phyAddr ;
        } drvPhyAddrArgs ;

#if defined (MSGQ_COMPONENT)
        struct {
            ProcessorId procId ;
            Pvoid       attrs ;
        } msgqTransportOpenArgs ;

        struct {
            ProcessorId procId ;
        } msgqTransportCloseArgs ;

        struct {
            Pstr         queueName ;
            MSGQ_Queue * msgqQueue ;
            MSGQ_Attrs * attrs ;
        } msgqOpenArgs ;

        struct {
            MSGQ_Queue   msgqQueue ;
        } msgqCloseArgs ;

        struct {
            Pstr                 queueName ;
            MSGQ_Queue *         msgqQueue ;
            MSGQ_LocateAttrs *   attrs ;
        } msgqLocateArgs ;

        struct {
            Pstr                     queueName ;
            MSGQ_Queue               replyQueue ;
            MSGQ_LocateAsyncAttrs *  attrs ;
        } msgqLocateAsyncArgs ;

        struct {
            MSGQ_Queue   msgqQueue ;
        } msgqReleaseArgs ;

        struct {
            PoolId      poolId ;
            Uint16      size ;
            Uint32      msgAddr ;
        } msgqAllocArgs ;

        struct {
            MSGQ_Msg     msg ;
        } msgqFreeArgs ;

        struct {
            MSGQ_Queue   msgqQueue ;
            MSGQ_Msg     msg ;
        } msgqPutArgs ;

        struct {
            Uint32      poolId ;
            MSGQ_Queue  msgqQueue ;
            Uint32      timeout ;
            Uint32      msgAddr ;
        } msgqGetArgs ;

        struct {
            MSGQ_Queue  errorQueue ;
            PoolId      poolId  ;
        } msgqSetErrorHandlerArgs ;

        struct {
            MSGQ_Queue  msgqQueue ;
            Uint16 *    count  ;
        } msgqCountArgs ;

#if defined (DDSP_PROFILE)
        struct {
            MSGQ_Queue          msgqQueue ;
            MSGQ_Instrument *   retVal ;
        } msgqInstrumentArgs ;
#endif /* if defined (DDSP_PROFILE) */

#if defined (DDSP_DEBUG)
        struct {
            MSGQ_Queue msgqQueue ;
        } msgqDebugArgs ;
#endif /* if defined (DDSP_DEBUG) */
#endif /* if defined (MSGQ_COMPONENT) */

        struct {
            PoolId poolId ;
            Pvoid  params ;
        } poolOpenArgs ;

        struct {
            PoolId poolId ;
        } poolCloseArgs ;

#if defined (POOL_COMPONENT)
        struct {
            PoolId  poolId ;
            Uint32  size ;
            Pvoid * bufPtr ;
        } poolAllocArgs ;

        struct {
            PoolId  poolId ;
            Uint32  size ;
            Pvoid   bufPtr ;
        } poolFreeArgs ;

        struct {
            PoolId           poolId ;
            Pvoid *          dstAddr ;
            AddrType         dstAddrType ;
            Pvoid            srcAddr ;
            AddrType         srcAddrType ;
        } poolTranslateAddrArgs ;

        struct {
            PoolId  poolId ;
            Uint32  size ;
            Pvoid   bufPtr ;
        } poolWBArgs ;

        struct {
            PoolId  poolId ;
            Uint32  size ;
            Pvoid   bufPtr ;
        } poolInvArgs ;
#endif /* #if defined (POOL_COMPONENT) */

#if defined (RINGIO_COMPONENT)
        struct {
            RingIO_MemInfo ringioRegionArgs ;
        } ringIoArgs ;
#endif /* if defined (RINGIO_COMPONENT) */

#if defined (MPLIST_COMPONENT)
        struct {
            MPLIST_MemInfo mplistRegionArgs ;
        } mplistArgs ;
#endif /* if defined (MPLIST_COMPONENT) */

#if defined (MPCS_COMPONENT)
        struct {
            MPCS_MemInfo  mpcsRegionArgs ;
        } mpcsMapArgs ;
#endif /* if defined (MPCS_COMPONENT) */

#if defined (NOTIFY_COMPONENT)
        struct {
            ProcessorId dspId ;
        } notifyInitializeArgs ;

        struct {
            ProcessorId dspId ;
        } notifyFinalizeArgs ;

        struct {
            ProcessorId dspId ;
            Uint32      ipsId ;
            Uint32      eventNo ;
            Pvoid       fnNotifyCbck ;
            Pvoid       cbckArg ;
        } notifyRegisterArgs ;

        struct {
            ProcessorId dspId ;
            Uint32      ipsId ;
            Uint32      eventNo ;
            Pvoid       fnNotifyCbck ;
            Pvoid       cbckArg ;
        } notifyUnregisterArgs ;

        struct {
            ProcessorId dspId ;
            Uint32      ipsId ;
            Uint32      eventNo ;
            Uint32      payload ;
        } notifyNotifyArgs ;
#endif /* #if defined (NOTIFY_COMPONENT) */

#if defined (DDSP_PROFILE)
        struct {
            ProcessorId       dspId    ;
            Uint32            ipsId    ;
            IPS_Instrument *  ipsStats ;
        } ipsInstrumentArgs ;
#endif

        struct {
            Uint32      key ;
            IDM_Attrs * attrs ;
        } idmCreateArgs ;

        struct {
            Uint32      key ;
        } idmDeleteArgs ;

        struct {
            Uint32      key ;
            Pstr        idKey ;
            Uint32 *    id ;
        } idmAcquireIdArgs ;

        struct {
            Uint32      key ;
            Uint32      id ;
        } idmReleaseIdArgs ;
    } apiArgs ;
} CMD_Args ;


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */


#endif /* !define (DRV_PMGR_H) */

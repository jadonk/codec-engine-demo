/** ============================================================================
 *  @file   gpptypes.h
 *
 *  @path   $(DSPLINK)/gpp/inc/usr/
 *
 *  @desc   Defines the type system for DSP/BIOS Link
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


#if !defined (GPPTYPES_H)
#define GPPTYPES_H


#if defined (__cplusplus)
extern "C" {
#endif /* defined (__cplusplus) */

#if defined  xdc_target__
#include <xdc/std.h>
#endif

/** ============================================================================
 *  @macro  IN/OUT/OPTIONAL/CONST
 *
 *  @desc   Argument specification syntax
 *  ============================================================================
 */
#define IN                              /* The argument is INPUT  only */
#define OUT                             /* The argument is OUTPUT only */
#define OPT                             /* The argument is OPTIONAL    */
#define CONST   const

/** ============================================================================
 *  @macro  USES
 *
 *  @desc   Empty macro to indicate header file dependency
 *  ============================================================================
 */
#define USES(filename)


/** ============================================================================
 *  @macro  Data types
 *
 *  @desc   Basic data types
 *  ============================================================================
 */
#if defined  xdc_target__
#else
typedef signed char         Int8 ;      /*  8 bit value */
#endif


#if defined  xdc_target__
#else
typedef signed short int    Int16 ;     /* 16 bit value */
#endif
#if defined  xdc_target__
#else
typedef signed long  int    Int32 ;     /* 32 bit value */
#endif

#if defined  xdc_target__
#else
typedef unsigned char       Uint8 ;     /*  8 bit value */
#endif
#if defined  xdc_target__
#else
typedef unsigned short int  Uint16 ;    /* 16 bit value */
#endif
#if defined  xdc_target__
#else
typedef unsigned long  int  Uint32 ;    /* 32 bit value */
#endif

typedef float               Real32 ;    /* 32 bit value */
typedef double              Real64 ;    /* 64 bit value */

#if defined  xdc_target__
#else
typedef short int           Bool ;      /* 16 bit value */
#endif

typedef char                Char8 ;     /*  8 bit value */
typedef short               Char16 ;    /* 16 bit value */

typedef unsigned char       Uchar8 ;    /*  8 bit value */
typedef unsigned short      Uchar16 ;   /* 16 bit value */

/* TBD resolve this with hal_psc.c */
#if defined  xdc_target__
#else
typedef int                 Int ;
#endif

#if defined  xdc_target__
#else
#define Void                void
#endif
typedef void *              Pvoid ;

typedef Char8 *             Pstr ;
typedef Uchar8 *            Pustr ;


/** ============================================================================
 *  @const  TRUE/FALSE
 *
 *  @desc   Boolean constants
 *  ============================================================================
 */
#if !defined (FALSE)
#define FALSE   0u
#endif

#if !defined (TRUE)
#define TRUE    1u
#endif


/** ============================================================================
 *  @const  NULL
 *
 *  @desc   Definition is language specific
 *  ============================================================================
 */
#if !defined (NULL)

#if defined (__cplusplus)
#define NULL    0u
#else  /* defined (__cplusplus) */
#define NULL ((void *)0)
#endif /* defined (__cplusplus) */

#endif /* !defined (NULL) */


/** ============================================================================
 *  @const  NULL_CHAR
 *
 *  @desc   String terminator.
 *  ============================================================================
 */
#define NULL_CHAR '\0'


/** ============================================================================
 *  @macro  REG8/REG16/REG32
 *
 *  @desc   Macros to access register fields.
 *  ============================================================================
 */
#define REG8(A)         (*(volatile Char8  *) (A))
#define REG16(A)        (*(volatile Uint16 *) (A))
#define REG32(A)        (*(volatile Uint32 *) (A))


/** ============================================================================
 *  @macro  DSP/BIOS Link specific types
 *
 *  @desc   These types are used across DSP/BIOS Link.
 *  ============================================================================
 */
typedef Uint32     ProcessorId ;
typedef Uint32     ChannelId ;


/** ============================================================================
 *  @name   PoolId
 *
 *  @desc   This type is used for identifying the different pools used by
 *          DSPLINK.
 *  ============================================================================
 */
typedef Uint16     PoolId ;


/** ============================================================================
 *  @macro  OS Specific standard definitions
 *
 *  @desc   Free for OEMs to add their own generic stuff, if they so desire
 *  ============================================================================
 */
#if defined (OS_WINCE)

#endif  /* defined (OS_WINCE) */


#if defined (OS_NUCLEUS)

#endif  /* defined (OS_NUCLEUS) */


#if defined (OS_LINUX)

#endif  /* defined (OS_LINUX) */


/** ============================================================================
 *  @macro  Calling convention
 *
 *  @desc   Definition of CDECL, DLLIMPORT, DLLEXPORT can be defined by
 *          OEM for his compiler
 *  ============================================================================
 */
#define STATIC          static
#define EXTERN          extern


#if defined (OS_WINCE)
/*  ------------------------------------------- WINCE               */
#define CDECL           
#define DLLIMPORT       __declspec (dllexport)
#define DLLEXPORT       __declspec (dllexport)
/*  ------------------------------------------- WINCE               */
#endif  /* defined (OS_WINCE) */


#if defined (OS_NUCLEUS)
/*  ------------------------------------------- NUCLEUS             */
#define CDECL
#define DLLIMPORT
#define DLLEXPORT
/*  ------------------------------------------- NUCLEUS             */
#endif  /* defined (OS_NUCLEUS) */

#if defined (OS_LINUX)
/*  ------------------------------------------- LINUX               */
#define CDECL
#define DLLIMPORT
#define DLLEXPORT
/*  ------------------------------------------- LINUX               */
#endif  /* defined (OS_LINUX) */


#if defined (OS_PROS)
/*  ------------------------------------------- PROS                */
#define CDECL
#define DLLIMPORT
#define DLLEXPORT
/*  ------------------------------------------- PROS                */
#endif  /* defined (OS_PROS) */

/* Derived calling conventions */
#define NORMAL_API      CDECL
#define IMPORT_API      DLLIMPORT
#define EXPORT_API      DLLEXPORT


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */

#endif  /* !defined (GPPTYPES_H) */

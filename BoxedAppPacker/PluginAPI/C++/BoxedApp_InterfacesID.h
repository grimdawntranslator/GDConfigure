

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon Dec 10 19:38:54 2018
 */
/* Compiler settings for V:\builds\BoxedApp\files\69FFEE22\src\BoxedApp\src\BoxedApp\BoxedApp_Interfaces.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_BoxedApp_Interfaces,0x2015FDBB,0xD11F,0x4ED1,0xB0,0xAC,0xDF,0x6F,0xF7,0x1F,0x91,0x59);


MIDL_DEFINE_GUID(IID, IID_IBxReadonlyRegistryWriter,0xA41EE144,0xF5C0,0x429A,0x8B,0xF7,0xE1,0x38,0xFE,0x20,0x8C,0x19);


MIDL_DEFINE_GUID(IID, IID_IBxRegKeyNode,0xFF182BB8,0x65D4,0x44AE,0xBE,0x4B,0x8E,0xEC,0x82,0xBE,0xC3,0xE4);


MIDL_DEFINE_GUID(IID, IID_IBxRegTree,0xE241201E,0x988D,0x4B6B,0x83,0x63,0x48,0x14,0xF2,0x59,0x51,0x20);


MIDL_DEFINE_GUID(IID, IID_IBxRegValueNode,0x456AC3D8,0x8141,0x442A,0x86,0xA3,0x47,0xD3,0xF4,0x21,0x12,0x8C);


MIDL_DEFINE_GUID(IID, IID_IBxEnumRegKeyNode,0x5E9CB505,0x4B76,0x489D,0xAE,0x2B,0xB9,0xE3,0xED,0xF2,0xF3,0x71);


MIDL_DEFINE_GUID(IID, IID_IBxEnumRegValueNode,0x6BEECF3E,0x27E2,0x4906,0xA9,0x20,0x17,0x49,0x34,0xCA,0x35,0x96);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif




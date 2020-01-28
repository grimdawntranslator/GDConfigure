

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon Dec 10 19:38:52 2018
 */
/* Compiler settings for V:\builds\BoxedApp\files\69FFEE22\src\BoxedApp\src\BoxedAppSDK\BoxedAppSDK_Interfaces.idl:
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

MIDL_DEFINE_GUID(IID, LIBID_BoxedAppSDK_Interfaces,0x4CF2AA85,0x1267,0x404c,0xAA,0x11,0x6A,0x7A,0x4E,0x24,0xBF,0xC1);


MIDL_DEFINE_GUID(IID, IID_IBxFile,0xD6BECAD0,0x5D56,0x4b51,0x82,0x78,0xD6,0x90,0x47,0x4D,0x69,0xFF);


MIDL_DEFINE_GUID(IID, IID_IBxFileHandle,0x236F1640,0xA96D,0x499c,0xAB,0x32,0x66,0xA7,0x02,0x4F,0x19,0x7E);


MIDL_DEFINE_GUID(IID, IID_IBxFileHandle2,0xA13C593D,0x835F,0x429d,0x97,0x19,0xE9,0x40,0x09,0x74,0x21,0xFD);


MIDL_DEFINE_GUID(IID, IID_IBxVirtualEnvironment,0xBFC1EEB2,0x8C8B,0x401A,0xB4,0x8A,0x06,0x8F,0x5D,0x83,0x42,0x30);


MIDL_DEFINE_GUID(IID, IID_IBxFileSandboxConfiguration,0xFE8B13BF,0x9A82,0x4E82,0x9C,0xF5,0xE0,0x9A,0xED,0x5B,0x15,0x75);


MIDL_DEFINE_GUID(IID, IID_IBxPredefinedDirectoriesInfoProvider,0x58A8A730,0xEA69,0x4639,0xBF,0xA3,0xB0,0x4F,0x5A,0x12,0xAD,0x94);


MIDL_DEFINE_GUID(IID, IID_IBxFileSandboxMetaInformation,0x9EBC4E56,0x8CA6,0x4305,0x90,0xCF,0xF9,0x6C,0x73,0x32,0x11,0xEF);


MIDL_DEFINE_GUID(IID, IID_IBxWriteCopyModeManager,0x3982D12E,0x9BC7,0x4FC8,0x80,0xD1,0xD6,0xC9,0x35,0x5F,0x3B,0x2B);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif




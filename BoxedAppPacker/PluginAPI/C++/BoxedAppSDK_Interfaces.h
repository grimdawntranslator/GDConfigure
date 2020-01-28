

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __BoxedAppSDK_Interfaces_h__
#define __BoxedAppSDK_Interfaces_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IBxFile_FWD_DEFINED__
#define __IBxFile_FWD_DEFINED__
typedef interface IBxFile IBxFile;
#endif 	/* __IBxFile_FWD_DEFINED__ */


#ifndef __IBxFileHandle_FWD_DEFINED__
#define __IBxFileHandle_FWD_DEFINED__
typedef interface IBxFileHandle IBxFileHandle;
#endif 	/* __IBxFileHandle_FWD_DEFINED__ */


#ifndef __IBxFileHandle2_FWD_DEFINED__
#define __IBxFileHandle2_FWD_DEFINED__
typedef interface IBxFileHandle2 IBxFileHandle2;
#endif 	/* __IBxFileHandle2_FWD_DEFINED__ */


#ifndef __IBxVirtualEnvironment_FWD_DEFINED__
#define __IBxVirtualEnvironment_FWD_DEFINED__
typedef interface IBxVirtualEnvironment IBxVirtualEnvironment;
#endif 	/* __IBxVirtualEnvironment_FWD_DEFINED__ */


#ifndef __IBxFileSandboxConfiguration_FWD_DEFINED__
#define __IBxFileSandboxConfiguration_FWD_DEFINED__
typedef interface IBxFileSandboxConfiguration IBxFileSandboxConfiguration;
#endif 	/* __IBxFileSandboxConfiguration_FWD_DEFINED__ */


#ifndef __IBxPredefinedDirectoriesInfoProvider_FWD_DEFINED__
#define __IBxPredefinedDirectoriesInfoProvider_FWD_DEFINED__
typedef interface IBxPredefinedDirectoriesInfoProvider IBxPredefinedDirectoriesInfoProvider;
#endif 	/* __IBxPredefinedDirectoriesInfoProvider_FWD_DEFINED__ */


#ifndef __IBxFileSandboxMetaInformation_FWD_DEFINED__
#define __IBxFileSandboxMetaInformation_FWD_DEFINED__
typedef interface IBxFileSandboxMetaInformation IBxFileSandboxMetaInformation;
#endif 	/* __IBxFileSandboxMetaInformation_FWD_DEFINED__ */


#ifndef __IBxWriteCopyModeManager_FWD_DEFINED__
#define __IBxWriteCopyModeManager_FWD_DEFINED__
typedef interface IBxWriteCopyModeManager IBxWriteCopyModeManager;
#endif 	/* __IBxWriteCopyModeManager_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "BoxedApp_Interfaces.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_BoxedAppSDK_Interfaces_0000_0000 */
/* [local] */ 

#pragma once
typedef 
enum BxEnumPredefinedDirectory
    {	BxEnumPredefinedDirectory_None	= 0,
	BxEnumPredefinedDirectory_First	= BxEnumPredefinedDirectory_None,
	BxEnumPredefinedDirectory_Root	= ( BxEnumPredefinedDirectory_First + 1 ) ,
	BxEnumPredefinedDirectory_ExeDir	= ( BxEnumPredefinedDirectory_Root + 1 ) ,
	BxEnumPredefinedDirectory_SystemDrive	= ( BxEnumPredefinedDirectory_ExeDir + 1 ) ,
	BxEnumPredefinedDirectory_Windows	= ( BxEnumPredefinedDirectory_SystemDrive + 1 ) ,
	BxEnumPredefinedDirectory_System32_32Bit	= ( BxEnumPredefinedDirectory_Windows + 1 ) ,
	BxEnumPredefinedDirectory_System32_64Bit	= ( BxEnumPredefinedDirectory_System32_32Bit + 1 ) ,
	BxEnumPredefinedDirectory_ProgramFiles_32Bit	= ( BxEnumPredefinedDirectory_System32_64Bit + 1 ) ,
	BxEnumPredefinedDirectory_ProgramFiles_32Bit_Common	= ( BxEnumPredefinedDirectory_ProgramFiles_32Bit + 1 ) ,
	BxEnumPredefinedDirectory_ProgramFiles_64Bit	= ( BxEnumPredefinedDirectory_ProgramFiles_32Bit_Common + 1 ) ,
	BxEnumPredefinedDirectory_ProgramFiles_64Bit_Common	= ( BxEnumPredefinedDirectory_ProgramFiles_64Bit + 1 ) ,
	BxEnumPredefinedDirectory_UserProfile	= ( BxEnumPredefinedDirectory_ProgramFiles_64Bit_Common + 1 ) ,
	BxEnumPredefinedDirectory_UserProfile_AppData	= ( BxEnumPredefinedDirectory_UserProfile + 1 ) ,
	BxEnumPredefinedDirectory_UserProfile_Desktop	= ( BxEnumPredefinedDirectory_UserProfile_AppData + 1 ) ,
	BxEnumPredefinedDirectory_UserProfile_Documents	= ( BxEnumPredefinedDirectory_UserProfile_Desktop + 1 ) ,
	BxEnumPredefinedDirectory_UserProfile_Music	= ( BxEnumPredefinedDirectory_UserProfile_Documents + 1 ) ,
	BxEnumPredefinedDirectory_UserProfile_Pictures	= ( BxEnumPredefinedDirectory_UserProfile_Music + 1 ) ,
	BxEnumPredefinedDirectory_UserProfile_Video	= ( BxEnumPredefinedDirectory_UserProfile_Pictures + 1 ) ,
	BxEnumPredefinedDirectory_UserProfile_Favorites	= ( BxEnumPredefinedDirectory_UserProfile_Video + 1 ) ,
	BxEnumPredefinedDirectory_UserProfile_Templates	= ( BxEnumPredefinedDirectory_UserProfile_Favorites + 1 ) ,
	BxEnumPredefinedDirectory_UserProfile_Cookies	= ( BxEnumPredefinedDirectory_UserProfile_Templates + 1 ) ,
	BxEnumPredefinedDirectory_UserProfile_LocalAppData	= ( BxEnumPredefinedDirectory_UserProfile_Cookies + 1 ) ,
	BxEnumPredefinedDirectory_UserProfile_StartMenu	= ( BxEnumPredefinedDirectory_UserProfile_LocalAppData + 1 ) ,
	BxEnumPredefinedDirectory_UserProfile_StartMenu_Programs	= ( BxEnumPredefinedDirectory_UserProfile_StartMenu + 1 ) ,
	BxEnumPredefinedDirectory_UserProfile_StartMenu_Programs_Startup	= ( BxEnumPredefinedDirectory_UserProfile_StartMenu_Programs + 1 ) ,
	BxEnumPredefinedDirectory_AllUsers	= ( BxEnumPredefinedDirectory_UserProfile_StartMenu_Programs_Startup + 1 ) ,
	BxEnumPredefinedDirectory_AllUsers_AppData	= ( BxEnumPredefinedDirectory_AllUsers + 1 ) ,
	BxEnumPredefinedDirectory_AllUsers_Desktop	= ( BxEnumPredefinedDirectory_AllUsers_AppData + 1 ) ,
	BxEnumPredefinedDirectory_AllUsers_Documents	= ( BxEnumPredefinedDirectory_AllUsers_Desktop + 1 ) ,
	BxEnumPredefinedDirectory_AllUsers_Music	= ( BxEnumPredefinedDirectory_AllUsers_Documents + 1 ) ,
	BxEnumPredefinedDirectory_AllUsers_Pictures	= ( BxEnumPredefinedDirectory_AllUsers_Music + 1 ) ,
	BxEnumPredefinedDirectory_AllUsers_Video	= ( BxEnumPredefinedDirectory_AllUsers_Pictures + 1 ) ,
	BxEnumPredefinedDirectory_AllUsers_Favorites	= ( BxEnumPredefinedDirectory_AllUsers_Video + 1 ) ,
	BxEnumPredefinedDirectory_AllUsers_Templates	= ( BxEnumPredefinedDirectory_AllUsers_Favorites + 1 ) ,
	BxEnumPredefinedDirectory_AllUsers_StartMenu	= ( BxEnumPredefinedDirectory_AllUsers_Templates + 1 ) ,
	BxEnumPredefinedDirectory_AllUsers_StartMenu_Programs	= ( BxEnumPredefinedDirectory_AllUsers_StartMenu + 1 ) ,
	BxEnumPredefinedDirectory_AllUsers_StartMenu_Programs_Startup	= ( BxEnumPredefinedDirectory_AllUsers_StartMenu_Programs + 1 ) ,
	BxEnumPredefinedDirectory_Count	= ( BxEnumPredefinedDirectory_AllUsers_StartMenu_Programs_Startup + 1 ) 
    } 	BxEnumPredefinedDirectory;



extern RPC_IF_HANDLE __MIDL_itf_BoxedAppSDK_Interfaces_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_BoxedAppSDK_Interfaces_0000_0000_v0_0_s_ifspec;


#ifndef __BoxedAppSDK_Interfaces_LIBRARY_DEFINED__
#define __BoxedAppSDK_Interfaces_LIBRARY_DEFINED__

/* library BoxedAppSDK_Interfaces */
/* [helpstring][version][uuid] */ 




typedef struct _SBxFileProp
    {
    DWORD m_dwSizeOfStruct;
    LPOLESTR m_szName;
    LARGE_INTEGER m_nSize;
    DWORD m_dwAttributes;
    FILETIME m_CreationTime;
    FILETIME m_LastWriteTime;
    FILETIME m_LastAccessTime;
    FILETIME m_ChangeTime;
    } 	SBxFileProp;

typedef struct _SBxStreamProp
    {
    DWORD m_dwSizeOfStruct;
    LPOLESTR m_szName;
    LARGE_INTEGER m_nSize;
    } 	SBxStreamProp;

typedef 
enum _BxWriteCopyModeScope
    {	BxWriteCopyModeScope_ThreadLocal	= 0,
	BxWriteCopyModeScope_ProcessWide	= ( BxWriteCopyModeScope_ThreadLocal + 1 ) 
    } 	BxWriteCopyModeScope;

typedef 
enum BxEnumApiLayerFlags
    {	BxEnumApiLayerFlags_None	= 0,
	BxEnumApiLayerFlags_Readonly	= 1,
	BxEnumApiLayerFlags_DefaultRegistryLayer	= 2,
	BxEnumApiLayerFlags_DefaultFileSystemLayer	= 4
    } 	BxEnumApiLayerFlags;


EXTERN_C const IID LIBID_BoxedAppSDK_Interfaces;

#ifndef __IBxFile_INTERFACE_DEFINED__
#define __IBxFile_INTERFACE_DEFINED__

/* interface IBxFile */
/* [object][uuid] */ 


EXTERN_C const IID IID_IBxFile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D6BECAD0-5D56-4b51-8278-D690474D69FF")
    IBxFile : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE createFile( 
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [in] */ ULONG DesiredAccess,
            /* [in] */ ULONG Attributes,
            /* [in] */ ULONG ShareAccess,
            /* [in] */ ULONG CreateOptions,
            /* [out] */ IBxFileHandle **ppHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE openFile( 
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [in] */ ULONG DesiredAccess,
            /* [in] */ ULONG ShareAccess,
            /* [in] */ ULONG OpenOptions,
            /* [out] */ IBxFileHandle **ppHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE replaceFile( 
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [in] */ ULONG DesiredAccess,
            /* [in] */ ULONG Attributes,
            /* [in] */ ULONG ShareAccess,
            /* [in] */ ULONG CreateOptions,
            /* [out] */ IBxFileHandle **ppHandle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Attributes( 
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [out] */ DWORD *pdwAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Attributes( 
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [in] */ DWORD dwAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Size( 
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [out] */ PLARGE_INTEGER pnSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_CreationTime( 
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [out] */ FILETIME *ptime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_LastWriteTime( 
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [out] */ FILETIME *ptime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_LastAccessTime( 
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [out] */ FILETIME *ptime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_ChangeTime( 
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [out] */ FILETIME *ptime) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBxFileVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBxFile * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBxFile * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBxFile * This);
        
        HRESULT ( STDMETHODCALLTYPE *createFile )( 
            IBxFile * This,
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [in] */ ULONG DesiredAccess,
            /* [in] */ ULONG Attributes,
            /* [in] */ ULONG ShareAccess,
            /* [in] */ ULONG CreateOptions,
            /* [out] */ IBxFileHandle **ppHandle);
        
        HRESULT ( STDMETHODCALLTYPE *openFile )( 
            IBxFile * This,
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [in] */ ULONG DesiredAccess,
            /* [in] */ ULONG ShareAccess,
            /* [in] */ ULONG OpenOptions,
            /* [out] */ IBxFileHandle **ppHandle);
        
        HRESULT ( STDMETHODCALLTYPE *replaceFile )( 
            IBxFile * This,
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [in] */ ULONG DesiredAccess,
            /* [in] */ ULONG Attributes,
            /* [in] */ ULONG ShareAccess,
            /* [in] */ ULONG CreateOptions,
            /* [out] */ IBxFileHandle **ppHandle);
        
        HRESULT ( STDMETHODCALLTYPE *get_Attributes )( 
            IBxFile * This,
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [out] */ DWORD *pdwAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *put_Attributes )( 
            IBxFile * This,
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [in] */ DWORD dwAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            IBxFile * This,
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [out] */ PLARGE_INTEGER pnSize);
        
        HRESULT ( STDMETHODCALLTYPE *get_CreationTime )( 
            IBxFile * This,
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [out] */ FILETIME *ptime);
        
        HRESULT ( STDMETHODCALLTYPE *get_LastWriteTime )( 
            IBxFile * This,
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [out] */ FILETIME *ptime);
        
        HRESULT ( STDMETHODCALLTYPE *get_LastAccessTime )( 
            IBxFile * This,
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [out] */ FILETIME *ptime);
        
        HRESULT ( STDMETHODCALLTYPE *get_ChangeTime )( 
            IBxFile * This,
            /* [string][unique][in] */ LPCWSTR szRelativePath,
            /* [out] */ FILETIME *ptime);
        
        END_INTERFACE
    } IBxFileVtbl;

    interface IBxFile
    {
        CONST_VTBL struct IBxFileVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBxFile_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBxFile_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBxFile_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBxFile_createFile(This,szRelativePath,DesiredAccess,Attributes,ShareAccess,CreateOptions,ppHandle)	\
    ( (This)->lpVtbl -> createFile(This,szRelativePath,DesiredAccess,Attributes,ShareAccess,CreateOptions,ppHandle) ) 

#define IBxFile_openFile(This,szRelativePath,DesiredAccess,ShareAccess,OpenOptions,ppHandle)	\
    ( (This)->lpVtbl -> openFile(This,szRelativePath,DesiredAccess,ShareAccess,OpenOptions,ppHandle) ) 

#define IBxFile_replaceFile(This,szRelativePath,DesiredAccess,Attributes,ShareAccess,CreateOptions,ppHandle)	\
    ( (This)->lpVtbl -> replaceFile(This,szRelativePath,DesiredAccess,Attributes,ShareAccess,CreateOptions,ppHandle) ) 

#define IBxFile_get_Attributes(This,szRelativePath,pdwAttributes)	\
    ( (This)->lpVtbl -> get_Attributes(This,szRelativePath,pdwAttributes) ) 

#define IBxFile_put_Attributes(This,szRelativePath,dwAttributes)	\
    ( (This)->lpVtbl -> put_Attributes(This,szRelativePath,dwAttributes) ) 

#define IBxFile_get_Size(This,szRelativePath,pnSize)	\
    ( (This)->lpVtbl -> get_Size(This,szRelativePath,pnSize) ) 

#define IBxFile_get_CreationTime(This,szRelativePath,ptime)	\
    ( (This)->lpVtbl -> get_CreationTime(This,szRelativePath,ptime) ) 

#define IBxFile_get_LastWriteTime(This,szRelativePath,ptime)	\
    ( (This)->lpVtbl -> get_LastWriteTime(This,szRelativePath,ptime) ) 

#define IBxFile_get_LastAccessTime(This,szRelativePath,ptime)	\
    ( (This)->lpVtbl -> get_LastAccessTime(This,szRelativePath,ptime) ) 

#define IBxFile_get_ChangeTime(This,szRelativePath,ptime)	\
    ( (This)->lpVtbl -> get_ChangeTime(This,szRelativePath,ptime) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBxFile_INTERFACE_DEFINED__ */


#ifndef __IBxFileHandle_INTERFACE_DEFINED__
#define __IBxFileHandle_INTERFACE_DEFINED__

/* interface IBxFileHandle */
/* [object][uuid] */ 


EXTERN_C const IID IID_IBxFileHandle;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("236F1640-A96D-499c-AB32-66A7024F197E")
    IBxFileHandle : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_Stream( 
            /* [out] */ LPSTREAM *ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Attributes( 
            /* [out] */ DWORD *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Attributes( 
            /* [in] */ DWORD newValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_DeleteOnClose( 
            /* [out] */ BOOL *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_DeleteOnClose( 
            /* [in] */ BOOL newValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_CreationTime( 
            /* [out] */ FILETIME *ptime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_CreationTime( 
            /* [in] */ FILETIME time) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_LastWriteTime( 
            /* [out] */ FILETIME *ptime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_LastWriteTime( 
            /* [in] */ FILETIME time) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_LastAccessTime( 
            /* [out] */ FILETIME *ptime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_LastAccessTime( 
            /* [in] */ FILETIME time) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_ChangeTime( 
            /* [out] */ FILETIME *ptime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_ChangeTime( 
            /* [in] */ FILETIME time) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE queryStreamInfo( 
            /* [in] */ ULONG nRequested,
            /* [length_is][size_is][out] */ SBxStreamProp *pProp,
            /* [out] */ ULONG *pnFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_NextFile( 
            /* [in] */ BOOL bRestart,
            /* [out][in] */ SBxFileProp *pProp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE rename( 
            /* [string][unique][in] */ LPCWSTR szNewRelativePath,
            /* [in] */ BOOL bReplaceIfExists) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBxFileHandleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBxFileHandle * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBxFileHandle * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBxFileHandle * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_Stream )( 
            IBxFileHandle * This,
            /* [out] */ LPSTREAM *ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *get_Attributes )( 
            IBxFileHandle * This,
            /* [out] */ DWORD *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *put_Attributes )( 
            IBxFileHandle * This,
            /* [in] */ DWORD newValue);
        
        HRESULT ( STDMETHODCALLTYPE *get_DeleteOnClose )( 
            IBxFileHandle * This,
            /* [out] */ BOOL *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *put_DeleteOnClose )( 
            IBxFileHandle * This,
            /* [in] */ BOOL newValue);
        
        HRESULT ( STDMETHODCALLTYPE *get_CreationTime )( 
            IBxFileHandle * This,
            /* [out] */ FILETIME *ptime);
        
        HRESULT ( STDMETHODCALLTYPE *put_CreationTime )( 
            IBxFileHandle * This,
            /* [in] */ FILETIME time);
        
        HRESULT ( STDMETHODCALLTYPE *get_LastWriteTime )( 
            IBxFileHandle * This,
            /* [out] */ FILETIME *ptime);
        
        HRESULT ( STDMETHODCALLTYPE *put_LastWriteTime )( 
            IBxFileHandle * This,
            /* [in] */ FILETIME time);
        
        HRESULT ( STDMETHODCALLTYPE *get_LastAccessTime )( 
            IBxFileHandle * This,
            /* [out] */ FILETIME *ptime);
        
        HRESULT ( STDMETHODCALLTYPE *put_LastAccessTime )( 
            IBxFileHandle * This,
            /* [in] */ FILETIME time);
        
        HRESULT ( STDMETHODCALLTYPE *get_ChangeTime )( 
            IBxFileHandle * This,
            /* [out] */ FILETIME *ptime);
        
        HRESULT ( STDMETHODCALLTYPE *put_ChangeTime )( 
            IBxFileHandle * This,
            /* [in] */ FILETIME time);
        
        HRESULT ( STDMETHODCALLTYPE *queryStreamInfo )( 
            IBxFileHandle * This,
            /* [in] */ ULONG nRequested,
            /* [length_is][size_is][out] */ SBxStreamProp *pProp,
            /* [out] */ ULONG *pnFetched);
        
        HRESULT ( STDMETHODCALLTYPE *get_NextFile )( 
            IBxFileHandle * This,
            /* [in] */ BOOL bRestart,
            /* [out][in] */ SBxFileProp *pProp);
        
        HRESULT ( STDMETHODCALLTYPE *rename )( 
            IBxFileHandle * This,
            /* [string][unique][in] */ LPCWSTR szNewRelativePath,
            /* [in] */ BOOL bReplaceIfExists);
        
        END_INTERFACE
    } IBxFileHandleVtbl;

    interface IBxFileHandle
    {
        CONST_VTBL struct IBxFileHandleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBxFileHandle_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBxFileHandle_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBxFileHandle_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBxFileHandle_get_Stream(This,ppStream)	\
    ( (This)->lpVtbl -> get_Stream(This,ppStream) ) 

#define IBxFileHandle_get_Attributes(This,pValue)	\
    ( (This)->lpVtbl -> get_Attributes(This,pValue) ) 

#define IBxFileHandle_put_Attributes(This,newValue)	\
    ( (This)->lpVtbl -> put_Attributes(This,newValue) ) 

#define IBxFileHandle_get_DeleteOnClose(This,pValue)	\
    ( (This)->lpVtbl -> get_DeleteOnClose(This,pValue) ) 

#define IBxFileHandle_put_DeleteOnClose(This,newValue)	\
    ( (This)->lpVtbl -> put_DeleteOnClose(This,newValue) ) 

#define IBxFileHandle_get_CreationTime(This,ptime)	\
    ( (This)->lpVtbl -> get_CreationTime(This,ptime) ) 

#define IBxFileHandle_put_CreationTime(This,time)	\
    ( (This)->lpVtbl -> put_CreationTime(This,time) ) 

#define IBxFileHandle_get_LastWriteTime(This,ptime)	\
    ( (This)->lpVtbl -> get_LastWriteTime(This,ptime) ) 

#define IBxFileHandle_put_LastWriteTime(This,time)	\
    ( (This)->lpVtbl -> put_LastWriteTime(This,time) ) 

#define IBxFileHandle_get_LastAccessTime(This,ptime)	\
    ( (This)->lpVtbl -> get_LastAccessTime(This,ptime) ) 

#define IBxFileHandle_put_LastAccessTime(This,time)	\
    ( (This)->lpVtbl -> put_LastAccessTime(This,time) ) 

#define IBxFileHandle_get_ChangeTime(This,ptime)	\
    ( (This)->lpVtbl -> get_ChangeTime(This,ptime) ) 

#define IBxFileHandle_put_ChangeTime(This,time)	\
    ( (This)->lpVtbl -> put_ChangeTime(This,time) ) 

#define IBxFileHandle_queryStreamInfo(This,nRequested,pProp,pnFetched)	\
    ( (This)->lpVtbl -> queryStreamInfo(This,nRequested,pProp,pnFetched) ) 

#define IBxFileHandle_get_NextFile(This,bRestart,pProp)	\
    ( (This)->lpVtbl -> get_NextFile(This,bRestart,pProp) ) 

#define IBxFileHandle_rename(This,szNewRelativePath,bReplaceIfExists)	\
    ( (This)->lpVtbl -> rename(This,szNewRelativePath,bReplaceIfExists) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBxFileHandle_INTERFACE_DEFINED__ */


#ifndef __IBxFileHandle2_INTERFACE_DEFINED__
#define __IBxFileHandle2_INTERFACE_DEFINED__

/* interface IBxFileHandle2 */
/* [object][uuid] */ 


EXTERN_C const IID IID_IBxFileHandle2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A13C593D-835F-429d-9719-E940097421FD")
    IBxFileHandle2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE onNewHandle( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE onCloseHandle( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBxFileHandle2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBxFileHandle2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBxFileHandle2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBxFileHandle2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *onNewHandle )( 
            IBxFileHandle2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *onCloseHandle )( 
            IBxFileHandle2 * This);
        
        END_INTERFACE
    } IBxFileHandle2Vtbl;

    interface IBxFileHandle2
    {
        CONST_VTBL struct IBxFileHandle2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBxFileHandle2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBxFileHandle2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBxFileHandle2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBxFileHandle2_onNewHandle(This)	\
    ( (This)->lpVtbl -> onNewHandle(This) ) 

#define IBxFileHandle2_onCloseHandle(This)	\
    ( (This)->lpVtbl -> onCloseHandle(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBxFileHandle2_INTERFACE_DEFINED__ */


#ifndef __IBxVirtualEnvironment_INTERFACE_DEFINED__
#define __IBxVirtualEnvironment_INTERFACE_DEFINED__

/* interface IBxVirtualEnvironment */
/* [object][uuid] */ 


EXTERN_C const IID IID_IBxVirtualEnvironment;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BFC1EEB2-8C8B-401A-B48A-068F5D834230")
    IBxVirtualEnvironment : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddLayer( 
            /* [in] */ IUnknown *layer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddReadonlyLayer( 
            /* [in] */ IUnknown *readonlyLayer,
            /* [in] */ IUnknown *writableLayer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDefaultRegistryLayer( 
            /* [in] */ IUnknown *layer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBxVirtualEnvironmentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBxVirtualEnvironment * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBxVirtualEnvironment * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBxVirtualEnvironment * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddLayer )( 
            IBxVirtualEnvironment * This,
            /* [in] */ IUnknown *layer);
        
        HRESULT ( STDMETHODCALLTYPE *AddReadonlyLayer )( 
            IBxVirtualEnvironment * This,
            /* [in] */ IUnknown *readonlyLayer,
            /* [in] */ IUnknown *writableLayer);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IBxVirtualEnvironment * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetDefaultRegistryLayer )( 
            IBxVirtualEnvironment * This,
            /* [in] */ IUnknown *layer);
        
        END_INTERFACE
    } IBxVirtualEnvironmentVtbl;

    interface IBxVirtualEnvironment
    {
        CONST_VTBL struct IBxVirtualEnvironmentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBxVirtualEnvironment_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBxVirtualEnvironment_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBxVirtualEnvironment_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBxVirtualEnvironment_AddLayer(This,layer)	\
    ( (This)->lpVtbl -> AddLayer(This,layer) ) 

#define IBxVirtualEnvironment_AddReadonlyLayer(This,readonlyLayer,writableLayer)	\
    ( (This)->lpVtbl -> AddReadonlyLayer(This,readonlyLayer,writableLayer) ) 

#define IBxVirtualEnvironment_Start(This)	\
    ( (This)->lpVtbl -> Start(This) ) 

#define IBxVirtualEnvironment_SetDefaultRegistryLayer(This,layer)	\
    ( (This)->lpVtbl -> SetDefaultRegistryLayer(This,layer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBxVirtualEnvironment_INTERFACE_DEFINED__ */


#ifndef __IBxFileSandboxConfiguration_INTERFACE_DEFINED__
#define __IBxFileSandboxConfiguration_INTERFACE_DEFINED__

/* interface IBxFileSandboxConfiguration */
/* [object][uuid] */ 


EXTERN_C const IID IID_IBxFileSandboxConfiguration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE8B13BF-9A82-4E82-9CF5-E09AED5B1575")
    IBxFileSandboxConfiguration : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE put_Isolation( 
            /* [in] */ LPCWSTR path,
            /* [in] */ BxIsolationMode isolationMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Isolation( 
            /* [in] */ LPCWSTR path,
            /* [retval][out] */ BxIsolationMode *isolationModePtr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFromFile( 
            /* [in] */ LPCWSTR path) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveToFile( 
            /* [in] */ LPCWSTR path) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBxFileSandboxConfigurationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBxFileSandboxConfiguration * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBxFileSandboxConfiguration * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBxFileSandboxConfiguration * This);
        
        HRESULT ( STDMETHODCALLTYPE *put_Isolation )( 
            IBxFileSandboxConfiguration * This,
            /* [in] */ LPCWSTR path,
            /* [in] */ BxIsolationMode isolationMode);
        
        HRESULT ( STDMETHODCALLTYPE *get_Isolation )( 
            IBxFileSandboxConfiguration * This,
            /* [in] */ LPCWSTR path,
            /* [retval][out] */ BxIsolationMode *isolationModePtr);
        
        HRESULT ( STDMETHODCALLTYPE *LoadFromFile )( 
            IBxFileSandboxConfiguration * This,
            /* [in] */ LPCWSTR path);
        
        HRESULT ( STDMETHODCALLTYPE *SaveToFile )( 
            IBxFileSandboxConfiguration * This,
            /* [in] */ LPCWSTR path);
        
        END_INTERFACE
    } IBxFileSandboxConfigurationVtbl;

    interface IBxFileSandboxConfiguration
    {
        CONST_VTBL struct IBxFileSandboxConfigurationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBxFileSandboxConfiguration_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBxFileSandboxConfiguration_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBxFileSandboxConfiguration_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBxFileSandboxConfiguration_put_Isolation(This,path,isolationMode)	\
    ( (This)->lpVtbl -> put_Isolation(This,path,isolationMode) ) 

#define IBxFileSandboxConfiguration_get_Isolation(This,path,isolationModePtr)	\
    ( (This)->lpVtbl -> get_Isolation(This,path,isolationModePtr) ) 

#define IBxFileSandboxConfiguration_LoadFromFile(This,path)	\
    ( (This)->lpVtbl -> LoadFromFile(This,path) ) 

#define IBxFileSandboxConfiguration_SaveToFile(This,path)	\
    ( (This)->lpVtbl -> SaveToFile(This,path) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBxFileSandboxConfiguration_INTERFACE_DEFINED__ */


#ifndef __IBxPredefinedDirectoriesInfoProvider_INTERFACE_DEFINED__
#define __IBxPredefinedDirectoriesInfoProvider_INTERFACE_DEFINED__

/* interface IBxPredefinedDirectoriesInfoProvider */
/* [object][uuid] */ 


EXTERN_C const IID IID_IBxPredefinedDirectoriesInfoProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("58A8A730-EA69-4639-BFA3-B04F5A12AD94")
    IBxPredefinedDirectoriesInfoProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPredefinedDirectoryName( 
            /* [in] */ BxEnumPredefinedDirectory dir_id,
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPredefinedDirectoryId( 
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ BxEnumPredefinedDirectory *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPredefinedDirectoryPathById( 
            /* [in] */ BxEnumPredefinedDirectory dir_id,
            /* [retval][out] */ BSTR *pbstrPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPredefinedDirectoryPathByName( 
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ BSTR *pbstrPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPathVariabledForm( 
            /* [in] */ BSTR bstrPath,
            /* [retval][out] */ BSTR *pbstrVariabledForm) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPathVariabledFormEx( 
            /* [in] */ BSTR bstrPath,
            /* [in] */ WCHAR chLeftBracket,
            /* [in] */ WCHAR chRightBracket,
            /* [retval][out] */ BSTR *pbstrVariabledForm) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ParsePath( 
            /* [in] */ BSTR bstrPath,
            /* [out] */ BSTR *bstrPredefinedDirectoryName,
            /* [out] */ BSTR *pbstrRelativePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVariabledForm( 
            /* [in] */ BSTR str,
            /* [retval][out] */ BSTR *pbstrVariabledForm) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBxPredefinedDirectoriesInfoProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBxPredefinedDirectoriesInfoProvider * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBxPredefinedDirectoriesInfoProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBxPredefinedDirectoriesInfoProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPredefinedDirectoryName )( 
            IBxPredefinedDirectoriesInfoProvider * This,
            /* [in] */ BxEnumPredefinedDirectory dir_id,
            /* [retval][out] */ BSTR *pbstrName);
        
        HRESULT ( STDMETHODCALLTYPE *GetPredefinedDirectoryId )( 
            IBxPredefinedDirectoriesInfoProvider * This,
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ BxEnumPredefinedDirectory *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetPredefinedDirectoryPathById )( 
            IBxPredefinedDirectoriesInfoProvider * This,
            /* [in] */ BxEnumPredefinedDirectory dir_id,
            /* [retval][out] */ BSTR *pbstrPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetPredefinedDirectoryPathByName )( 
            IBxPredefinedDirectoriesInfoProvider * This,
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ BSTR *pbstrPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetPathVariabledForm )( 
            IBxPredefinedDirectoriesInfoProvider * This,
            /* [in] */ BSTR bstrPath,
            /* [retval][out] */ BSTR *pbstrVariabledForm);
        
        HRESULT ( STDMETHODCALLTYPE *GetPathVariabledFormEx )( 
            IBxPredefinedDirectoriesInfoProvider * This,
            /* [in] */ BSTR bstrPath,
            /* [in] */ WCHAR chLeftBracket,
            /* [in] */ WCHAR chRightBracket,
            /* [retval][out] */ BSTR *pbstrVariabledForm);
        
        HRESULT ( STDMETHODCALLTYPE *ParsePath )( 
            IBxPredefinedDirectoriesInfoProvider * This,
            /* [in] */ BSTR bstrPath,
            /* [out] */ BSTR *bstrPredefinedDirectoryName,
            /* [out] */ BSTR *pbstrRelativePath);
        
        HRESULT ( STDMETHODCALLTYPE *GetVariabledForm )( 
            IBxPredefinedDirectoriesInfoProvider * This,
            /* [in] */ BSTR str,
            /* [retval][out] */ BSTR *pbstrVariabledForm);
        
        END_INTERFACE
    } IBxPredefinedDirectoriesInfoProviderVtbl;

    interface IBxPredefinedDirectoriesInfoProvider
    {
        CONST_VTBL struct IBxPredefinedDirectoriesInfoProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBxPredefinedDirectoriesInfoProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBxPredefinedDirectoriesInfoProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBxPredefinedDirectoriesInfoProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBxPredefinedDirectoriesInfoProvider_GetPredefinedDirectoryName(This,dir_id,pbstrName)	\
    ( (This)->lpVtbl -> GetPredefinedDirectoryName(This,dir_id,pbstrName) ) 

#define IBxPredefinedDirectoriesInfoProvider_GetPredefinedDirectoryId(This,bstrName,pId)	\
    ( (This)->lpVtbl -> GetPredefinedDirectoryId(This,bstrName,pId) ) 

#define IBxPredefinedDirectoriesInfoProvider_GetPredefinedDirectoryPathById(This,dir_id,pbstrPath)	\
    ( (This)->lpVtbl -> GetPredefinedDirectoryPathById(This,dir_id,pbstrPath) ) 

#define IBxPredefinedDirectoriesInfoProvider_GetPredefinedDirectoryPathByName(This,bstrName,pbstrPath)	\
    ( (This)->lpVtbl -> GetPredefinedDirectoryPathByName(This,bstrName,pbstrPath) ) 

#define IBxPredefinedDirectoriesInfoProvider_GetPathVariabledForm(This,bstrPath,pbstrVariabledForm)	\
    ( (This)->lpVtbl -> GetPathVariabledForm(This,bstrPath,pbstrVariabledForm) ) 

#define IBxPredefinedDirectoriesInfoProvider_GetPathVariabledFormEx(This,bstrPath,chLeftBracket,chRightBracket,pbstrVariabledForm)	\
    ( (This)->lpVtbl -> GetPathVariabledFormEx(This,bstrPath,chLeftBracket,chRightBracket,pbstrVariabledForm) ) 

#define IBxPredefinedDirectoriesInfoProvider_ParsePath(This,bstrPath,bstrPredefinedDirectoryName,pbstrRelativePath)	\
    ( (This)->lpVtbl -> ParsePath(This,bstrPath,bstrPredefinedDirectoryName,pbstrRelativePath) ) 

#define IBxPredefinedDirectoriesInfoProvider_GetVariabledForm(This,str,pbstrVariabledForm)	\
    ( (This)->lpVtbl -> GetVariabledForm(This,str,pbstrVariabledForm) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBxPredefinedDirectoriesInfoProvider_INTERFACE_DEFINED__ */


#ifndef __IBxFileSandboxMetaInformation_INTERFACE_DEFINED__
#define __IBxFileSandboxMetaInformation_INTERFACE_DEFINED__

/* interface IBxFileSandboxMetaInformation */
/* [object][uuid] */ 


EXTERN_C const IID IID_IBxFileSandboxMetaInformation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9EBC4E56-8CA6-4305-90CF-F96C733211EF")
    IBxFileSandboxMetaInformation : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_Base( 
            /* [retval][out] */ BSTR *basePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Deleted( 
            /* [in] */ LPCWSTR relativeSandboxPath,
            /* [in] */ BOOL isDeleted) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Deleted( 
            /* [in] */ LPCWSTR relativeSandboxPath,
            /* [retval][out] */ BOOL *isDeleted) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBxFileSandboxMetaInformationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBxFileSandboxMetaInformation * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBxFileSandboxMetaInformation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBxFileSandboxMetaInformation * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_Base )( 
            IBxFileSandboxMetaInformation * This,
            /* [retval][out] */ BSTR *basePath);
        
        HRESULT ( STDMETHODCALLTYPE *put_Deleted )( 
            IBxFileSandboxMetaInformation * This,
            /* [in] */ LPCWSTR relativeSandboxPath,
            /* [in] */ BOOL isDeleted);
        
        HRESULT ( STDMETHODCALLTYPE *get_Deleted )( 
            IBxFileSandboxMetaInformation * This,
            /* [in] */ LPCWSTR relativeSandboxPath,
            /* [retval][out] */ BOOL *isDeleted);
        
        END_INTERFACE
    } IBxFileSandboxMetaInformationVtbl;

    interface IBxFileSandboxMetaInformation
    {
        CONST_VTBL struct IBxFileSandboxMetaInformationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBxFileSandboxMetaInformation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBxFileSandboxMetaInformation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBxFileSandboxMetaInformation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBxFileSandboxMetaInformation_get_Base(This,basePath)	\
    ( (This)->lpVtbl -> get_Base(This,basePath) ) 

#define IBxFileSandboxMetaInformation_put_Deleted(This,relativeSandboxPath,isDeleted)	\
    ( (This)->lpVtbl -> put_Deleted(This,relativeSandboxPath,isDeleted) ) 

#define IBxFileSandboxMetaInformation_get_Deleted(This,relativeSandboxPath,isDeleted)	\
    ( (This)->lpVtbl -> get_Deleted(This,relativeSandboxPath,isDeleted) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBxFileSandboxMetaInformation_INTERFACE_DEFINED__ */


#ifndef __IBxWriteCopyModeManager_INTERFACE_DEFINED__
#define __IBxWriteCopyModeManager_INTERFACE_DEFINED__

/* interface IBxWriteCopyModeManager */
/* [object][uuid] */ 


EXTERN_C const IID IID_IBxWriteCopyModeManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3982D12E-9BC7-4FC8-80D1-D6C9355F3B2B")
    IBxWriteCopyModeManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnableWriteCopyMode( 
            /* [in] */ BxWriteCopyModeScope scope,
            /* [in] */ BOOL enable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsWriteCopyModeEnabled( 
            /* [retval][out] */ BOOL *enabled) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBxWriteCopyModeManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBxWriteCopyModeManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBxWriteCopyModeManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBxWriteCopyModeManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnableWriteCopyMode )( 
            IBxWriteCopyModeManager * This,
            /* [in] */ BxWriteCopyModeScope scope,
            /* [in] */ BOOL enable);
        
        HRESULT ( STDMETHODCALLTYPE *IsWriteCopyModeEnabled )( 
            IBxWriteCopyModeManager * This,
            /* [retval][out] */ BOOL *enabled);
        
        END_INTERFACE
    } IBxWriteCopyModeManagerVtbl;

    interface IBxWriteCopyModeManager
    {
        CONST_VTBL struct IBxWriteCopyModeManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBxWriteCopyModeManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBxWriteCopyModeManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBxWriteCopyModeManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBxWriteCopyModeManager_EnableWriteCopyMode(This,scope,enable)	\
    ( (This)->lpVtbl -> EnableWriteCopyMode(This,scope,enable) ) 

#define IBxWriteCopyModeManager_IsWriteCopyModeEnabled(This,enabled)	\
    ( (This)->lpVtbl -> IsWriteCopyModeEnabled(This,enabled) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBxWriteCopyModeManager_INTERFACE_DEFINED__ */

#endif /* __BoxedAppSDK_Interfaces_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



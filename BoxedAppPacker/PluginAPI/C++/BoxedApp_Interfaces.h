

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __BoxedApp_Interfaces_h__
#define __BoxedApp_Interfaces_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IBxReadonlyRegistryWriter_FWD_DEFINED__
#define __IBxReadonlyRegistryWriter_FWD_DEFINED__
typedef interface IBxReadonlyRegistryWriter IBxReadonlyRegistryWriter;
#endif 	/* __IBxReadonlyRegistryWriter_FWD_DEFINED__ */


#ifndef __IBxRegKeyNode_FWD_DEFINED__
#define __IBxRegKeyNode_FWD_DEFINED__
typedef interface IBxRegKeyNode IBxRegKeyNode;
#endif 	/* __IBxRegKeyNode_FWD_DEFINED__ */


#ifndef __IBxRegTree_FWD_DEFINED__
#define __IBxRegTree_FWD_DEFINED__
typedef interface IBxRegTree IBxRegTree;
#endif 	/* __IBxRegTree_FWD_DEFINED__ */


#ifndef __IBxRegValueNode_FWD_DEFINED__
#define __IBxRegValueNode_FWD_DEFINED__
typedef interface IBxRegValueNode IBxRegValueNode;
#endif 	/* __IBxRegValueNode_FWD_DEFINED__ */


#ifndef __IBxEnumRegKeyNode_FWD_DEFINED__
#define __IBxEnumRegKeyNode_FWD_DEFINED__
typedef interface IBxEnumRegKeyNode IBxEnumRegKeyNode;
#endif 	/* __IBxEnumRegKeyNode_FWD_DEFINED__ */


#ifndef __IBxEnumRegValueNode_FWD_DEFINED__
#define __IBxEnumRegValueNode_FWD_DEFINED__
typedef interface IBxEnumRegValueNode IBxEnumRegValueNode;
#endif 	/* __IBxEnumRegValueNode_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __BoxedApp_Interfaces_LIBRARY_DEFINED__
#define __BoxedApp_Interfaces_LIBRARY_DEFINED__

/* library BoxedApp_Interfaces */
/* [helpstring][version][uuid] */ 

#pragma once
typedef 
enum BxEnumPredefinedKey
    {	BxEnumPredefinedKey_None	= 0,
	BxEnumPredefinedKey_First	= BxEnumPredefinedKey_None,
	BxEnumPredefinedKey_Root	= ( BxEnumPredefinedKey_First + 1 ) ,
	BxEnumPredefinedKey_HKEY_CURRENT_USER	= ( BxEnumPredefinedKey_Root + 1 ) ,
	BxEnumPredefinedKey_HKEY_LOCAL_MACHINE	= ( BxEnumPredefinedKey_HKEY_CURRENT_USER + 1 ) ,
	BxEnumPredefinedKey_HKEY_CURRENT_USER_Software	= ( BxEnumPredefinedKey_HKEY_LOCAL_MACHINE + 1 ) ,
	BxEnumPredefinedKey_HKEY_CURRENT_USER_Software_Classes	= ( BxEnumPredefinedKey_HKEY_CURRENT_USER_Software + 1 ) ,
	BxEnumPredefinedKey_HKEY_CURRENT_USER_Software_Classes_Wow6432Node	= ( BxEnumPredefinedKey_HKEY_CURRENT_USER_Software_Classes + 1 ) ,
	BxEnumPredefinedKey_HKEY_LOCAL_MACHINE_Software	= ( BxEnumPredefinedKey_HKEY_CURRENT_USER_Software_Classes_Wow6432Node + 1 ) ,
	BxEnumPredefinedKey_HKEY_LOCAL_MACHINE_Software_Wow6432Node	= ( BxEnumPredefinedKey_HKEY_LOCAL_MACHINE_Software + 1 ) ,
	BxEnumPredefinedKey_HKEY_LOCAL_MACHINE_Software_Classes	= ( BxEnumPredefinedKey_HKEY_LOCAL_MACHINE_Software_Wow6432Node + 1 ) ,
	BxEnumPredefinedKey_HKEY_LOCAL_MACHINE_Software_Classes_Wow6432Node	= ( BxEnumPredefinedKey_HKEY_LOCAL_MACHINE_Software_Classes + 1 ) ,
	BxEnumPredefinedKey_Count	= ( BxEnumPredefinedKey_HKEY_LOCAL_MACHINE_Software_Classes_Wow6432Node + 1 ) 
    } 	BxEnumPredefinedKey;







typedef 
enum _BxIsolationMode
    {	BxIsolationMode_None	= 0,
	BxIsolationMode_Merged	= ( BxIsolationMode_None + 1 ) ,
	BxIsolationMode_WriteCopy	= ( BxIsolationMode_Merged + 1 ) ,
	BxIsolationMode_Full	= ( BxIsolationMode_WriteCopy + 1 ) 
    } 	BxIsolationMode;

typedef 
enum _BxEnumNodeKind
    {	BxEnumNodeKind_All	= 0,
	BxEnumNodeKind_Visible	= ( BxEnumNodeKind_All + 1 ) 
    } 	BxEnumNodeKind;

typedef struct _SBxKeyNodeInformation
    {
    LARGE_INTEGER _lastWriteTime;
    DWORD _totalSubKeyCount;
    DWORD _visibleSubKeyCount;
    DWORD _maxSubKeyNameLen;
    DWORD _maxSubKeyClassLen;
    DWORD _totalValueCount;
    DWORD _visibleValueCount;
    DWORD _maxValueNameLen;
    DWORD _maxValueDataLen;
    } 	SBxKeyNodeInformation;


EXTERN_C const IID LIBID_BoxedApp_Interfaces;

#ifndef __IBxReadonlyRegistryWriter_INTERFACE_DEFINED__
#define __IBxReadonlyRegistryWriter_INTERFACE_DEFINED__

/* interface IBxReadonlyRegistryWriter */
/* [object][uuid] */ 


EXTERN_C const IID IID_IBxReadonlyRegistryWriter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A41EE144-F5C0-429A-8BF7-E138FE208C19")
    IBxReadonlyRegistryWriter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginWriteKey( 
            /* [in] */ LPCWSTR name,
            /* [in] */ LPCWSTR lpClass,
            /* [in] */ BOOL virtuallyDeleted,
            /* [in] */ PLARGE_INTEGER lastWriteTime,
            /* [in] */ BxIsolationMode isolationMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteValue( 
            /* [in] */ LPCWSTR name,
            /* [in] */ DWORD type,
            /* [in] */ PVOID data,
            /* [in] */ DWORD dataSize,
            /* [in] */ BOOL virtuallyDeleted,
            /* [in] */ BOOL useVariables) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndWriteKey( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Finish( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBxReadonlyRegistryWriterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBxReadonlyRegistryWriter * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBxReadonlyRegistryWriter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBxReadonlyRegistryWriter * This);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IBxReadonlyRegistryWriter * This);
        
        HRESULT ( STDMETHODCALLTYPE *BeginWriteKey )( 
            IBxReadonlyRegistryWriter * This,
            /* [in] */ LPCWSTR name,
            /* [in] */ LPCWSTR lpClass,
            /* [in] */ BOOL virtuallyDeleted,
            /* [in] */ PLARGE_INTEGER lastWriteTime,
            /* [in] */ BxIsolationMode isolationMode);
        
        HRESULT ( STDMETHODCALLTYPE *WriteValue )( 
            IBxReadonlyRegistryWriter * This,
            /* [in] */ LPCWSTR name,
            /* [in] */ DWORD type,
            /* [in] */ PVOID data,
            /* [in] */ DWORD dataSize,
            /* [in] */ BOOL virtuallyDeleted,
            /* [in] */ BOOL useVariables);
        
        HRESULT ( STDMETHODCALLTYPE *EndWriteKey )( 
            IBxReadonlyRegistryWriter * This);
        
        HRESULT ( STDMETHODCALLTYPE *Finish )( 
            IBxReadonlyRegistryWriter * This);
        
        END_INTERFACE
    } IBxReadonlyRegistryWriterVtbl;

    interface IBxReadonlyRegistryWriter
    {
        CONST_VTBL struct IBxReadonlyRegistryWriterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBxReadonlyRegistryWriter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBxReadonlyRegistryWriter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBxReadonlyRegistryWriter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBxReadonlyRegistryWriter_Start(This)	\
    ( (This)->lpVtbl -> Start(This) ) 

#define IBxReadonlyRegistryWriter_BeginWriteKey(This,name,lpClass,virtuallyDeleted,lastWriteTime,isolationMode)	\
    ( (This)->lpVtbl -> BeginWriteKey(This,name,lpClass,virtuallyDeleted,lastWriteTime,isolationMode) ) 

#define IBxReadonlyRegistryWriter_WriteValue(This,name,type,data,dataSize,virtuallyDeleted,useVariables)	\
    ( (This)->lpVtbl -> WriteValue(This,name,type,data,dataSize,virtuallyDeleted,useVariables) ) 

#define IBxReadonlyRegistryWriter_EndWriteKey(This)	\
    ( (This)->lpVtbl -> EndWriteKey(This) ) 

#define IBxReadonlyRegistryWriter_Finish(This)	\
    ( (This)->lpVtbl -> Finish(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBxReadonlyRegistryWriter_INTERFACE_DEFINED__ */


#ifndef __IBxRegKeyNode_INTERFACE_DEFINED__
#define __IBxRegKeyNode_INTERFACE_DEFINED__

/* interface IBxRegKeyNode */
/* [object][uuid] */ 


EXTERN_C const IID IID_IBxRegKeyNode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FF182BB8-65D4-44AE-BE4B-8EEC82BEC3E4")
    IBxRegKeyNode : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Equals( 
            IBxRegKeyNode *otherKeyNode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_NameLength( 
            DWORD *nameLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Name( 
            WCHAR *nameBuffer,
            DWORD nameBufferLength,
            DWORD *writtenCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Parent( 
            IBxRegKeyNode **parentNodePtr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_ClassLength( 
            DWORD *classLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Class( 
            WCHAR *classBuffer,
            DWORD classBufferLength,
            DWORD *writtenCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_IsVirtuallyDeleted( 
            BOOL value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_IsVirtuallyDeleted( 
            BOOL *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_IsDeleted( 
            BOOL *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_LastWriteTime( 
            LARGE_INTEGER *pnTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_LastWriteTime( 
            LARGE_INTEGER *pnTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_IsolationMode( 
            BxIsolationMode *isolationMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_IsolationMode( 
            BxIsolationMode isolationMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Info( 
            SBxKeyNodeInformation *keyNodeInformation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Remove( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Rename( 
            LPCWSTR newName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddKey( 
            IBxRegKeyNode *keyNode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindKey( 
            LPCWSTR name,
            IBxRegKeyNode **keyNodePtr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveKey( 
            LPCWSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumKeys( 
            BxEnumNodeKind nodeKind,
            IBxEnumRegKeyNode **enumKeysPtr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_KeyCount( 
            BxEnumNodeKind nodeKind,
            DWORD *count) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddValue( 
            IBxRegValueNode *valueNode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindValue( 
            LPCWSTR name,
            IBxRegValueNode **nodePtr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveValue( 
            LPCWSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumValues( 
            BxEnumNodeKind nodeKind,
            IBxEnumRegValueNode **enumValuesPtr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_ValueCount( 
            BxEnumNodeKind nodeKind,
            DWORD *count) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Flush( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PredefinedKeyType( 
            BxEnumPredefinedKey *predefinedKey) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBxRegKeyNodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBxRegKeyNode * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBxRegKeyNode * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBxRegKeyNode * This);
        
        HRESULT ( STDMETHODCALLTYPE *Equals )( 
            IBxRegKeyNode * This,
            IBxRegKeyNode *otherKeyNode);
        
        HRESULT ( STDMETHODCALLTYPE *get_NameLength )( 
            IBxRegKeyNode * This,
            DWORD *nameLength);
        
        HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IBxRegKeyNode * This,
            WCHAR *nameBuffer,
            DWORD nameBufferLength,
            DWORD *writtenCount);
        
        HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IBxRegKeyNode * This,
            IBxRegKeyNode **parentNodePtr);
        
        HRESULT ( STDMETHODCALLTYPE *get_ClassLength )( 
            IBxRegKeyNode * This,
            DWORD *classLength);
        
        HRESULT ( STDMETHODCALLTYPE *get_Class )( 
            IBxRegKeyNode * This,
            WCHAR *classBuffer,
            DWORD classBufferLength,
            DWORD *writtenCount);
        
        HRESULT ( STDMETHODCALLTYPE *put_IsVirtuallyDeleted )( 
            IBxRegKeyNode * This,
            BOOL value);
        
        HRESULT ( STDMETHODCALLTYPE *get_IsVirtuallyDeleted )( 
            IBxRegKeyNode * This,
            BOOL *value);
        
        HRESULT ( STDMETHODCALLTYPE *get_IsDeleted )( 
            IBxRegKeyNode * This,
            BOOL *value);
        
        HRESULT ( STDMETHODCALLTYPE *get_LastWriteTime )( 
            IBxRegKeyNode * This,
            LARGE_INTEGER *pnTime);
        
        HRESULT ( STDMETHODCALLTYPE *put_LastWriteTime )( 
            IBxRegKeyNode * This,
            LARGE_INTEGER *pnTime);
        
        HRESULT ( STDMETHODCALLTYPE *get_IsolationMode )( 
            IBxRegKeyNode * This,
            BxIsolationMode *isolationMode);
        
        HRESULT ( STDMETHODCALLTYPE *put_IsolationMode )( 
            IBxRegKeyNode * This,
            BxIsolationMode isolationMode);
        
        HRESULT ( STDMETHODCALLTYPE *get_Info )( 
            IBxRegKeyNode * This,
            SBxKeyNodeInformation *keyNodeInformation);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IBxRegKeyNode * This);
        
        HRESULT ( STDMETHODCALLTYPE *Rename )( 
            IBxRegKeyNode * This,
            LPCWSTR newName);
        
        HRESULT ( STDMETHODCALLTYPE *AddKey )( 
            IBxRegKeyNode * This,
            IBxRegKeyNode *keyNode);
        
        HRESULT ( STDMETHODCALLTYPE *FindKey )( 
            IBxRegKeyNode * This,
            LPCWSTR name,
            IBxRegKeyNode **keyNodePtr);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveKey )( 
            IBxRegKeyNode * This,
            LPCWSTR name);
        
        HRESULT ( STDMETHODCALLTYPE *EnumKeys )( 
            IBxRegKeyNode * This,
            BxEnumNodeKind nodeKind,
            IBxEnumRegKeyNode **enumKeysPtr);
        
        HRESULT ( STDMETHODCALLTYPE *get_KeyCount )( 
            IBxRegKeyNode * This,
            BxEnumNodeKind nodeKind,
            DWORD *count);
        
        HRESULT ( STDMETHODCALLTYPE *AddValue )( 
            IBxRegKeyNode * This,
            IBxRegValueNode *valueNode);
        
        HRESULT ( STDMETHODCALLTYPE *FindValue )( 
            IBxRegKeyNode * This,
            LPCWSTR name,
            IBxRegValueNode **nodePtr);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveValue )( 
            IBxRegKeyNode * This,
            LPCWSTR name);
        
        HRESULT ( STDMETHODCALLTYPE *EnumValues )( 
            IBxRegKeyNode * This,
            BxEnumNodeKind nodeKind,
            IBxEnumRegValueNode **enumValuesPtr);
        
        HRESULT ( STDMETHODCALLTYPE *get_ValueCount )( 
            IBxRegKeyNode * This,
            BxEnumNodeKind nodeKind,
            DWORD *count);
        
        HRESULT ( STDMETHODCALLTYPE *Flush )( 
            IBxRegKeyNode * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_PredefinedKeyType )( 
            IBxRegKeyNode * This,
            BxEnumPredefinedKey *predefinedKey);
        
        END_INTERFACE
    } IBxRegKeyNodeVtbl;

    interface IBxRegKeyNode
    {
        CONST_VTBL struct IBxRegKeyNodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBxRegKeyNode_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBxRegKeyNode_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBxRegKeyNode_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBxRegKeyNode_Equals(This,otherKeyNode)	\
    ( (This)->lpVtbl -> Equals(This,otherKeyNode) ) 

#define IBxRegKeyNode_get_NameLength(This,nameLength)	\
    ( (This)->lpVtbl -> get_NameLength(This,nameLength) ) 

#define IBxRegKeyNode_get_Name(This,nameBuffer,nameBufferLength,writtenCount)	\
    ( (This)->lpVtbl -> get_Name(This,nameBuffer,nameBufferLength,writtenCount) ) 

#define IBxRegKeyNode_get_Parent(This,parentNodePtr)	\
    ( (This)->lpVtbl -> get_Parent(This,parentNodePtr) ) 

#define IBxRegKeyNode_get_ClassLength(This,classLength)	\
    ( (This)->lpVtbl -> get_ClassLength(This,classLength) ) 

#define IBxRegKeyNode_get_Class(This,classBuffer,classBufferLength,writtenCount)	\
    ( (This)->lpVtbl -> get_Class(This,classBuffer,classBufferLength,writtenCount) ) 

#define IBxRegKeyNode_put_IsVirtuallyDeleted(This,value)	\
    ( (This)->lpVtbl -> put_IsVirtuallyDeleted(This,value) ) 

#define IBxRegKeyNode_get_IsVirtuallyDeleted(This,value)	\
    ( (This)->lpVtbl -> get_IsVirtuallyDeleted(This,value) ) 

#define IBxRegKeyNode_get_IsDeleted(This,value)	\
    ( (This)->lpVtbl -> get_IsDeleted(This,value) ) 

#define IBxRegKeyNode_get_LastWriteTime(This,pnTime)	\
    ( (This)->lpVtbl -> get_LastWriteTime(This,pnTime) ) 

#define IBxRegKeyNode_put_LastWriteTime(This,pnTime)	\
    ( (This)->lpVtbl -> put_LastWriteTime(This,pnTime) ) 

#define IBxRegKeyNode_get_IsolationMode(This,isolationMode)	\
    ( (This)->lpVtbl -> get_IsolationMode(This,isolationMode) ) 

#define IBxRegKeyNode_put_IsolationMode(This,isolationMode)	\
    ( (This)->lpVtbl -> put_IsolationMode(This,isolationMode) ) 

#define IBxRegKeyNode_get_Info(This,keyNodeInformation)	\
    ( (This)->lpVtbl -> get_Info(This,keyNodeInformation) ) 

#define IBxRegKeyNode_Remove(This)	\
    ( (This)->lpVtbl -> Remove(This) ) 

#define IBxRegKeyNode_Rename(This,newName)	\
    ( (This)->lpVtbl -> Rename(This,newName) ) 

#define IBxRegKeyNode_AddKey(This,keyNode)	\
    ( (This)->lpVtbl -> AddKey(This,keyNode) ) 

#define IBxRegKeyNode_FindKey(This,name,keyNodePtr)	\
    ( (This)->lpVtbl -> FindKey(This,name,keyNodePtr) ) 

#define IBxRegKeyNode_RemoveKey(This,name)	\
    ( (This)->lpVtbl -> RemoveKey(This,name) ) 

#define IBxRegKeyNode_EnumKeys(This,nodeKind,enumKeysPtr)	\
    ( (This)->lpVtbl -> EnumKeys(This,nodeKind,enumKeysPtr) ) 

#define IBxRegKeyNode_get_KeyCount(This,nodeKind,count)	\
    ( (This)->lpVtbl -> get_KeyCount(This,nodeKind,count) ) 

#define IBxRegKeyNode_AddValue(This,valueNode)	\
    ( (This)->lpVtbl -> AddValue(This,valueNode) ) 

#define IBxRegKeyNode_FindValue(This,name,nodePtr)	\
    ( (This)->lpVtbl -> FindValue(This,name,nodePtr) ) 

#define IBxRegKeyNode_RemoveValue(This,name)	\
    ( (This)->lpVtbl -> RemoveValue(This,name) ) 

#define IBxRegKeyNode_EnumValues(This,nodeKind,enumValuesPtr)	\
    ( (This)->lpVtbl -> EnumValues(This,nodeKind,enumValuesPtr) ) 

#define IBxRegKeyNode_get_ValueCount(This,nodeKind,count)	\
    ( (This)->lpVtbl -> get_ValueCount(This,nodeKind,count) ) 

#define IBxRegKeyNode_Flush(This)	\
    ( (This)->lpVtbl -> Flush(This) ) 

#define IBxRegKeyNode_get_PredefinedKeyType(This,predefinedKey)	\
    ( (This)->lpVtbl -> get_PredefinedKeyType(This,predefinedKey) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBxRegKeyNode_INTERFACE_DEFINED__ */


#ifndef __IBxRegTree_INTERFACE_DEFINED__
#define __IBxRegTree_INTERFACE_DEFINED__

/* interface IBxRegTree */
/* [object][uuid] */ 


EXTERN_C const IID IID_IBxRegTree;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E241201E-988D-4B6B-8363-4814F2595120")
    IBxRegTree : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Lock( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unlock( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PredefinedKey( 
            BxEnumPredefinedKey predefinedKey,
            IBxRegKeyNode **nodePtr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateKeyNode( 
            IBxRegKeyNode *parentNode,
            LPCWSTR name,
            LPCWSTR className,
            BxIsolationMode isolationMode,
            IBxRegKeyNode **newNodePtr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateValueNode( 
            IBxRegKeyNode *parentNode,
            LPCWSTR name,
            ULONG type,
            PVOID data,
            ULONG dataLength,
            IBxRegValueNode **newValueNodePtr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateVirtuallyDeletedValueNode( 
            IBxRegKeyNode *parentNode,
            LPCWSTR name,
            IBxRegValueNode **newValueNodePtr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBxRegTreeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBxRegTree * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBxRegTree * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBxRegTree * This);
        
        HRESULT ( STDMETHODCALLTYPE *Lock )( 
            IBxRegTree * This);
        
        HRESULT ( STDMETHODCALLTYPE *Unlock )( 
            IBxRegTree * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_PredefinedKey )( 
            IBxRegTree * This,
            BxEnumPredefinedKey predefinedKey,
            IBxRegKeyNode **nodePtr);
        
        HRESULT ( STDMETHODCALLTYPE *CreateKeyNode )( 
            IBxRegTree * This,
            IBxRegKeyNode *parentNode,
            LPCWSTR name,
            LPCWSTR className,
            BxIsolationMode isolationMode,
            IBxRegKeyNode **newNodePtr);
        
        HRESULT ( STDMETHODCALLTYPE *CreateValueNode )( 
            IBxRegTree * This,
            IBxRegKeyNode *parentNode,
            LPCWSTR name,
            ULONG type,
            PVOID data,
            ULONG dataLength,
            IBxRegValueNode **newValueNodePtr);
        
        HRESULT ( STDMETHODCALLTYPE *CreateVirtuallyDeletedValueNode )( 
            IBxRegTree * This,
            IBxRegKeyNode *parentNode,
            LPCWSTR name,
            IBxRegValueNode **newValueNodePtr);
        
        END_INTERFACE
    } IBxRegTreeVtbl;

    interface IBxRegTree
    {
        CONST_VTBL struct IBxRegTreeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBxRegTree_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBxRegTree_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBxRegTree_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBxRegTree_Lock(This)	\
    ( (This)->lpVtbl -> Lock(This) ) 

#define IBxRegTree_Unlock(This)	\
    ( (This)->lpVtbl -> Unlock(This) ) 

#define IBxRegTree_get_PredefinedKey(This,predefinedKey,nodePtr)	\
    ( (This)->lpVtbl -> get_PredefinedKey(This,predefinedKey,nodePtr) ) 

#define IBxRegTree_CreateKeyNode(This,parentNode,name,className,isolationMode,newNodePtr)	\
    ( (This)->lpVtbl -> CreateKeyNode(This,parentNode,name,className,isolationMode,newNodePtr) ) 

#define IBxRegTree_CreateValueNode(This,parentNode,name,type,data,dataLength,newValueNodePtr)	\
    ( (This)->lpVtbl -> CreateValueNode(This,parentNode,name,type,data,dataLength,newValueNodePtr) ) 

#define IBxRegTree_CreateVirtuallyDeletedValueNode(This,parentNode,name,newValueNodePtr)	\
    ( (This)->lpVtbl -> CreateVirtuallyDeletedValueNode(This,parentNode,name,newValueNodePtr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBxRegTree_INTERFACE_DEFINED__ */


#ifndef __IBxRegValueNode_INTERFACE_DEFINED__
#define __IBxRegValueNode_INTERFACE_DEFINED__

/* interface IBxRegValueNode */
/* [object][uuid] */ 


EXTERN_C const IID IID_IBxRegValueNode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("456AC3D8-8141-442A-86A3-47D3F421128C")
    IBxRegValueNode : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Equals( 
            IBxRegValueNode *otherNode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Parent( 
            IBxRegKeyNode **parentNodePtr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_NameLength( 
            DWORD *nameLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Name( 
            WCHAR *nameBuffer,
            DWORD nameBufferLength,
            DWORD *writtenCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_IsVirtuallyDeleted( 
            BOOL value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_IsVirtuallyDeleted( 
            BOOL *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_IsDeleted( 
            BOOL *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Type( 
            ULONG *type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_DataLength( 
            ULONG *dataLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Data( 
            PVOID bufferPtr,
            ULONG bufferSize,
            ULONG *writtenBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Data( 
            ULONG type,
            PVOID data,
            ULONG dataLength) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBxRegValueNodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBxRegValueNode * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBxRegValueNode * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBxRegValueNode * This);
        
        HRESULT ( STDMETHODCALLTYPE *Equals )( 
            IBxRegValueNode * This,
            IBxRegValueNode *otherNode);
        
        HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IBxRegValueNode * This,
            IBxRegKeyNode **parentNodePtr);
        
        HRESULT ( STDMETHODCALLTYPE *get_NameLength )( 
            IBxRegValueNode * This,
            DWORD *nameLength);
        
        HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IBxRegValueNode * This,
            WCHAR *nameBuffer,
            DWORD nameBufferLength,
            DWORD *writtenCount);
        
        HRESULT ( STDMETHODCALLTYPE *put_IsVirtuallyDeleted )( 
            IBxRegValueNode * This,
            BOOL value);
        
        HRESULT ( STDMETHODCALLTYPE *get_IsVirtuallyDeleted )( 
            IBxRegValueNode * This,
            BOOL *value);
        
        HRESULT ( STDMETHODCALLTYPE *get_IsDeleted )( 
            IBxRegValueNode * This,
            BOOL *value);
        
        HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IBxRegValueNode * This,
            ULONG *type);
        
        HRESULT ( STDMETHODCALLTYPE *get_DataLength )( 
            IBxRegValueNode * This,
            ULONG *dataLength);
        
        HRESULT ( STDMETHODCALLTYPE *get_Data )( 
            IBxRegValueNode * This,
            PVOID bufferPtr,
            ULONG bufferSize,
            ULONG *writtenBytes);
        
        HRESULT ( STDMETHODCALLTYPE *put_Data )( 
            IBxRegValueNode * This,
            ULONG type,
            PVOID data,
            ULONG dataLength);
        
        END_INTERFACE
    } IBxRegValueNodeVtbl;

    interface IBxRegValueNode
    {
        CONST_VTBL struct IBxRegValueNodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBxRegValueNode_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBxRegValueNode_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBxRegValueNode_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBxRegValueNode_Equals(This,otherNode)	\
    ( (This)->lpVtbl -> Equals(This,otherNode) ) 

#define IBxRegValueNode_get_Parent(This,parentNodePtr)	\
    ( (This)->lpVtbl -> get_Parent(This,parentNodePtr) ) 

#define IBxRegValueNode_get_NameLength(This,nameLength)	\
    ( (This)->lpVtbl -> get_NameLength(This,nameLength) ) 

#define IBxRegValueNode_get_Name(This,nameBuffer,nameBufferLength,writtenCount)	\
    ( (This)->lpVtbl -> get_Name(This,nameBuffer,nameBufferLength,writtenCount) ) 

#define IBxRegValueNode_put_IsVirtuallyDeleted(This,value)	\
    ( (This)->lpVtbl -> put_IsVirtuallyDeleted(This,value) ) 

#define IBxRegValueNode_get_IsVirtuallyDeleted(This,value)	\
    ( (This)->lpVtbl -> get_IsVirtuallyDeleted(This,value) ) 

#define IBxRegValueNode_get_IsDeleted(This,value)	\
    ( (This)->lpVtbl -> get_IsDeleted(This,value) ) 

#define IBxRegValueNode_get_Type(This,type)	\
    ( (This)->lpVtbl -> get_Type(This,type) ) 

#define IBxRegValueNode_get_DataLength(This,dataLength)	\
    ( (This)->lpVtbl -> get_DataLength(This,dataLength) ) 

#define IBxRegValueNode_get_Data(This,bufferPtr,bufferSize,writtenBytes)	\
    ( (This)->lpVtbl -> get_Data(This,bufferPtr,bufferSize,writtenBytes) ) 

#define IBxRegValueNode_put_Data(This,type,data,dataLength)	\
    ( (This)->lpVtbl -> put_Data(This,type,data,dataLength) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBxRegValueNode_INTERFACE_DEFINED__ */


#ifndef __IBxEnumRegKeyNode_INTERFACE_DEFINED__
#define __IBxEnumRegKeyNode_INTERFACE_DEFINED__

/* interface IBxEnumRegKeyNode */
/* [object][uuid] */ 


EXTERN_C const IID IID_IBxEnumRegKeyNode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5E9CB505-4B76-489D-AE2B-B9E3EDF2F371")
    IBxEnumRegKeyNode : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNext( 
            IBxRegKeyNode **keyNodePtr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPrev( 
            IBxRegKeyNode **keyNodePtr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBxEnumRegKeyNodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBxEnumRegKeyNode * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBxEnumRegKeyNode * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBxEnumRegKeyNode * This);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IBxEnumRegKeyNode * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetNext )( 
            IBxEnumRegKeyNode * This,
            IBxRegKeyNode **keyNodePtr);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrev )( 
            IBxEnumRegKeyNode * This,
            IBxRegKeyNode **keyNodePtr);
        
        END_INTERFACE
    } IBxEnumRegKeyNodeVtbl;

    interface IBxEnumRegKeyNode
    {
        CONST_VTBL struct IBxEnumRegKeyNodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBxEnumRegKeyNode_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBxEnumRegKeyNode_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBxEnumRegKeyNode_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBxEnumRegKeyNode_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IBxEnumRegKeyNode_GetNext(This,keyNodePtr)	\
    ( (This)->lpVtbl -> GetNext(This,keyNodePtr) ) 

#define IBxEnumRegKeyNode_GetPrev(This,keyNodePtr)	\
    ( (This)->lpVtbl -> GetPrev(This,keyNodePtr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBxEnumRegKeyNode_INTERFACE_DEFINED__ */


#ifndef __IBxEnumRegValueNode_INTERFACE_DEFINED__
#define __IBxEnumRegValueNode_INTERFACE_DEFINED__

/* interface IBxEnumRegValueNode */
/* [object][uuid] */ 


EXTERN_C const IID IID_IBxEnumRegValueNode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6BEECF3E-27E2-4906-A920-174934CA3596")
    IBxEnumRegValueNode : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNext( 
            IBxRegValueNode **valueNodePtr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPrev( 
            IBxRegValueNode **valueNodePtr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBxEnumRegValueNodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBxEnumRegValueNode * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBxEnumRegValueNode * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBxEnumRegValueNode * This);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IBxEnumRegValueNode * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetNext )( 
            IBxEnumRegValueNode * This,
            IBxRegValueNode **valueNodePtr);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrev )( 
            IBxEnumRegValueNode * This,
            IBxRegValueNode **valueNodePtr);
        
        END_INTERFACE
    } IBxEnumRegValueNodeVtbl;

    interface IBxEnumRegValueNode
    {
        CONST_VTBL struct IBxEnumRegValueNodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBxEnumRegValueNode_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBxEnumRegValueNode_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBxEnumRegValueNode_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBxEnumRegValueNode_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IBxEnumRegValueNode_GetNext(This,valueNodePtr)	\
    ( (This)->lpVtbl -> GetNext(This,valueNodePtr) ) 

#define IBxEnumRegValueNode_GetPrev(This,valueNodePtr)	\
    ( (This)->lpVtbl -> GetPrev(This,valueNodePtr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBxEnumRegValueNode_INTERFACE_DEFINED__ */

#endif /* __BoxedApp_Interfaces_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



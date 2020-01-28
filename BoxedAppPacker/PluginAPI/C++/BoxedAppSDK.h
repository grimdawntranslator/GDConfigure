// Copyright (c) Softanics
//
// BoxedApp SDK
//
// Ask your questions here: http://boxedapp.com/support.html
// Our forum: http://boxedapp.com/forum/
// License SDK: http://boxedapp.com/boxedappsdk/order.html
// Online help: http://boxedapp.com/boxedappsdk/help/
//

#ifndef __BOXEDAPPSDK_H__
#define __BOXEDAPPSDK_H__

#define BXAPI __stdcall
#define BOXEDAPPSDKAPI __stdcall

#include <pshpack4.h>

// IStream* declaration
#include <objidl.h>

#ifndef DEF_BOXEDAPPSDK_INTERFACES_NOT_REQUIRED
#include "BoxedAppSDK_Interfaces.h"
#endif // !DEF_BOXEDAPPSDK_INTERFACES_NOT_REQUIRED

#ifdef __cplusplus
extern "C"
{
#endif

// Options
#define DEF_BOXEDAPPSDK_OPTION__ALL_CHANGES_ARE_VIRTUAL                (1) // default: 0 (FALSE)
#define DEF_BOXEDAPPSDK_OPTION__EMBED_BOXEDAPP_IN_CHILD_PROCESSES      (2) // default: 0 (FALSE, don't enable BoxedApp to a new process by default)
#define DEF_BOXEDAPPSDK_OPTION__ENABLE_VIRTUAL_FILE_SYSTEM             (3) // default: 1 (TRUE)
#define DEF_BOXEDAPPSDK_OPTION__RECREATE_VIRTUAL_FILE_AS_VIRTUAL       (4) // default: 1 (TRUE)
#define DEF_BOXEDAPPSDK_OPTION__ENABLE_VIRTUAL_REGISTRY                (5) // default: 1 (TRUE)
#define DEF_BOXEDAPPSDK_OPTION__HIDE_VIRTUAL_FILES_FROM_FILE_DIALOG    (6) // default: 0 (FALSE)
#define DEF_BOXEDAPPSDK_OPTION__EMULATE_OUT_OF_PROC_COM_SERVERS        (7) // default: 0 (FALSE)
#define DEF_BOXEDAPPSDK_OPTION__INHERIT_OPTIONS                        (8) // default: 1 (FALSE)
#define DEF_BOXEDAPPSDK_OPTION__ENABLE_REGISTRY_RMSC_REDIRECTOR        (9) // default: 0 (FALSE)
#define DEF_BOXEDAPPSDK_OPTION__ENABLE_ALL_HOOKS                      (10) // default: 1 (TRUE)
#define DEF_BOXEDAPPSDK_OPTION__NTACCESSCHECK_ALWAYS_RETURNS_SUCCESS  (11) // default: 0 (FALSE)
#define DEF_BOXEDAPPSDK_OPTION__ENABLE_EXPERIMENTAL_IMPORT_PROCESSING (12) // default: 0 (FALSE)
#define DEF_BOXEDAPPSDK_OPTION__FORCE_GENERATE_REAL_STUB_FOR_VIRTUAL_PROCESS (13) // default: 1 (FALSE)

// Startup flags
#define DEF_BOXEDAPPSDK_STARTUP_OPTION__HOOK_ENGINE                    (1) // default: 0 (FALSE)

void WINAPI BoxedAppSDK_PackerStubEntryPoint(HMODULE, PVOID, DWORD);

// Initialization
BOOL BXAPI BoxedAppSDK_Init();
// Internal: initialization by environment id
BOOL BXAPI BoxedAppSDK_InitById(ULONGLONG nEnvId);
// Finalization
void BXAPI BoxedAppSDK_Exit();

/// A structure that is used for EnumBoxedAppSDK_RequestId__RedirectFilePath
struct SBoxedAppSDK__RedirectFilePath
{
    // in
    LPCWSTR m_szPath;

    // out
    BOOL m_bHandled;

    LPWSTR m_szRedirectToPath;
};

// Internal: this function is called by rundll32.exe when this is used as a helper process
void CALLBACK BoxedAppSDK_RunDll32_Callback();

// Enable / disable logging
void BXAPI BoxedAppSDK_EnableDebugLog(BOOL bEnable);

// Log file
void BXAPI BoxedAppSDK_SetLogFileA(LPCSTR szLogFilePath);
void BXAPI BoxedAppSDK_SetLogFileW(LPCWSTR szLogFilePath);

#ifdef UNICODE
#define BoxedAppSDK_SetLogFile BoxedAppSDK_SetLogFileW
#else
#define BoxedAppSDK_SetLogFile BoxedAppSDK_SetLogFileA
#endif // UNICODE

void BXAPI BoxedAppSDK_WriteLogA(LPCSTR szMessage);
void BXAPI BoxedAppSDK_WriteLogW(LPCWSTR szMessage);

#ifdef UNICODE
#define BoxedAppSDK_WriteLog BoxedAppSDK_WriteLogW
#else
#define BoxedAppSDK_WriteLog BoxedAppSDK_WriteLogA
#endif // UNICODE

// Virtual file system

#ifdef UNICODE
#define BoxedAppSDK_CreateVirtualFile BoxedAppSDK_CreateVirtualFileW
#else
#define BoxedAppSDK_CreateVirtualFile BoxedAppSDK_CreateVirtualFileA
#endif // UNICODE

// Create new virtual file
HANDLE BXAPI BoxedAppSDK_CreateVirtualFileA(
    LPCSTR szPath, 
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile
);

HANDLE BXAPI BoxedAppSDK_CreateVirtualFileW(
    LPCWSTR szPath, 
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile
);


#ifdef UNICODE
#define BoxedAppSDK_CreateVirtualDirectory BoxedAppSDK_CreateVirtualDirectoryW
#else
#define BoxedAppSDK_CreateVirtualDirectory BoxedAppSDK_CreateVirtualDirectoryA
#endif // UNICODE

// Create new virtual directory
BOOL BXAPI BoxedAppSDK_CreateVirtualDirectoryA(
    LPCSTR lpPathName, 
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

BOOL BXAPI BoxedAppSDK_CreateVirtualDirectoryW(
    LPCWSTR lpPathName, 
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

#ifdef UNICODE
#define BoxedAppSDK_IsVirtualFile BoxedAppSDK_IsVirtualFileW
#else
#define BoxedAppSDK_IsVirtualFile BoxedAppSDK_IsVirtualFileA
#endif // UNICODE

// Create new virtual directory
BOOL BXAPI BoxedAppSDK_IsVirtualFileA(
    LPCSTR szPath
);

BOOL BXAPI BoxedAppSDK_IsVirtualFileW(
    LPCWSTR szPath
);

// Virtual registry

#ifdef UNICODE
#define BoxedAppSDK_CreateVirtualRegKey BoxedAppSDK_CreateVirtualRegKeyW
#else
#define BoxedAppSDK_CreateVirtualRegKey BoxedAppSDK_CreateVirtualRegKeyA
#endif // UNICODE

LONG BXAPI BoxedAppSDK_CreateVirtualRegKeyA(
    HKEY hKey,
    LPCSTR lpSubKey,
    DWORD Reserved,
    LPCSTR lpClass,
    DWORD dwOptions,
    REGSAM samDesired,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    PHKEY phkResult,
    LPDWORD lpdwDisposition
);

LONG BXAPI BoxedAppSDK_CreateVirtualRegKeyW(
    HKEY hKey,
    LPCWSTR lpSubKey,
    DWORD Reserved,
    LPCWSTR lpClass,
    DWORD dwOptions,
    REGSAM samDesired,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    PHKEY phkResult,
    LPDWORD lpdwDisposition
);

// Isolation mode for registry keys

#ifdef UNICODE
#define BoxedAppSDK_SetRegKeyIsolationMode BoxedAppSDK_SetRegKeyIsolationModeW
#else
#define BoxedAppSDK_SetRegKeyIsolationMode BoxedAppSDK_SetRegKeyIsolationModeA
#endif // UNICODE

#ifndef DEF_BOXEDAPPSDK_INTERFACES_NOT_REQUIRED

/// Sets isolation mode for the key
/// To specify registry view use samDesired (pass KEY_WOW64_32KEY or KEY_WOW64_64KEY), pass zero to don't specify registry view
BOOL BXAPI BoxedAppSDK_SetRegKeyIsolationModeW(HKEY hKey, LPCWSTR lpSubKey, REGSAM samDesired, BxIsolationMode IsolationMode);

/// Sets isolation mode for the key
/// To specify registry view use samDesired (pass KEY_WOW64_32KEY or KEY_WOW64_64KEY), pass zero to don't specify registry view
BOOL BXAPI BoxedAppSDK_SetRegKeyIsolationModeA(HKEY hKey, LPCSTR lpSubKey, REGSAM samDesired, BxIsolationMode IsolationMode);

#ifdef UNICODE
#define BoxedAppSDK_GetRegKeyIsolationMode BoxedAppSDK_GetRegKeyIsolationModeW
#else
#define BoxedAppSDK_GetRegKeyIsolationMode BoxedAppSDK_GetRegKeyIsolationModeA
#endif // UNICODE

/// Gets isolation mode for the key
/// To specify registry view use samDesired (pass KEY_WOW64_32KEY or KEY_WOW64_64KEY), pass zero to don't specify registry view
BxIsolationMode BXAPI BoxedAppSDK_GetRegKeyIsolationModeW(HKEY hKey, LPCWSTR lpSubKey, REGSAM samDesired);

/// Gets isolation mode for the key
/// To specify registry view use samDesired (pass KEY_WOW64_32KEY or KEY_WOW64_64KEY), pass zero to don't specify registry view
BxIsolationMode BXAPI BoxedAppSDK_GetRegKeyIsolationModeA(HKEY hKey, LPCSTR lpSubKey, REGSAM samDesired);

#endif // !DEF_BOXEDAPPSDK_INTERFACES_NOT_REQUIRED

// Removing virtual registry key from the virtual environment

#ifdef UNICODE
#define BoxedAppSDK_DeleteVirtualRegKey BoxedAppSDK_DeleteVirtualRegKeyW
#else
#define BoxedAppSDK_DeleteVirtualRegKey BoxedAppSDK_DeleteVirtualRegKeyA
#endif // UNICODE

LONG BXAPI BoxedAppSDK_DeleteVirtualRegKeyA(HKEY hKey, LPCSTR lpSubKey);
LONG BXAPI BoxedAppSDK_DeleteVirtualRegKeyW(HKEY hKey, LPCWSTR lpSubKey);

LONG BXAPI BoxedAppSDK_DeleteVirtualRegKeyByHandle(HKEY hKey);

void BXAPI BoxedAppSDK_SetContext(LPCSTR szContext);

HRESULT BXAPI BoxedAppSDK_RegisterCOMLibraryInVirtualRegistryA(LPCSTR szPath);
HRESULT BXAPI BoxedAppSDK_RegisterCOMLibraryInVirtualRegistryW(LPCWSTR szPath);

#ifdef UNICODE
#define BoxedAppSDK_RegisterCOMLibraryInVirtualRegistry BoxedAppSDK_RegisterCOMLibraryInVirtualRegistryW
#else
#define BoxedAppSDK_RegisterCOMLibraryInVirtualRegistry BoxedAppSDK_RegisterCOMLibraryInVirtualRegistryA
#endif // UNICODE

void BXAPI BoxedAppSDK_EnableOption(DWORD dwOptionIndex, BOOL bEnable);
BOOL BXAPI BoxedAppSDK_IsOptionEnabled(DWORD dwOptionIndex);

void BXAPI BoxedAppSDK_RemoteProcess_EnableOption(DWORD dwProcessId, DWORD dwOptionIndex, BOOL bEnable);
BOOL BXAPI BoxedAppSDK_RemoteProcess_IsOptionEnabled(DWORD dwProcessId, DWORD dwOptionIndex);

// Set startup flags
void BXAPI BoxedAppSDK_SetStartupFlags(DWORD dwFlags);

typedef enum _ENUM_BOXEDAPPSDK_REQUEST_ID
{
    EnumBoxedAppSDK_RequestId__RegQueryValue = 1, 
    EnumBoxedAppSDK_RequestId__RedirectFilePath = 2
} ENUM_BOXEDAPPSDK_REQUEST_ID;

typedef DWORD (BXAPI *PBOXEDAPPHANDLER)(PVOID Param, ENUM_BOXEDAPPSDK_REQUEST_ID RequestId, PVOID pAdditionalInfo);
DWORD BXAPI BoxedAppSDK_AddHandler(PBOXEDAPPHANDLER pHandler, PVOID Param);
BOOL BXAPI BoxedAppSDK_RemoveHandler(DWORD dwHandlerId);

/// A structure that is used for EnumBoxedAppSDK_RequestId__RegQueryValue
struct SBoxedAppSDK__RegQueryValue
{
    // in
    HKEY m_Root;
    LPCWSTR m_szPath;
    LPCWSTR m_szValue;

    // out
    BOOL m_bHandled;

    DWORD m_dwType;
    PVOID m_pData;
    DWORD m_dwSize;
};

PVOID BXAPI BoxedAppSDK_Alloc(DWORD dwSize);
BOOL BXAPI BoxedAppSDK_Free(PVOID pData);

DWORD BXAPI BoxedAppSDK_DeleteFileFromVirtualFileSystemW(LPCWSTR szPath);
DWORD BXAPI BoxedAppSDK_DeleteFileFromVirtualFileSystemA(LPCSTR szPath);

#ifdef UNICODE
#define BoxedAppSDK_DeleteFileFromVirtualFileSystem BoxedAppSDK_DeleteFileFromVirtualFileSystemW
#else
#define BoxedAppSDK_DeleteFileFromVirtualFileSystem BoxedAppSDK_DeleteFileFromVirtualFileSystemA
#endif // UNICODE

BOOL BXAPI BoxedAppSDK_CreateProcessFromMemoryA(
    LPCVOID pBuffer, 
    DWORD dwSize, 

    LPCSTR lpApplicationName,
    LPSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPCSTR lpCurrentDirectory,
    LPSTARTUPINFOA lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation
);

BOOL BXAPI BoxedAppSDK_CreateProcessFromMemoryW(
    LPCVOID pBuffer, 
    DWORD dwSize, 

    LPCWSTR lpApplicationName,
    LPWSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPCWSTR lpCurrentDirectory,
    LPSTARTUPINFOW lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation
);

#ifdef UNICODE
#define BoxedAppSDK_CreateProcessFromMemory BoxedAppSDK_CreateProcessFromMemoryW
#else
#define BoxedAppSDK_CreateProcessFromMemory BoxedAppSDK_CreateProcessFromMemoryA
#endif // UNICODE

// Set param #0
void BXAPI BoxedAppSDK_SetParam0(LPCWSTR param);

// Create a virtual file based on IStream
HANDLE BXAPI BoxedAppSDK_CreateVirtualFileBasedOnIStreamA(
    LPCSTR szPath, 
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile, 

    LPSTREAM pStream
);

HANDLE BXAPI BoxedAppSDK_CreateVirtualFileBasedOnIStreamW(
    LPCWSTR szPath, 
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile, 

    LPSTREAM pStream
);

#ifdef UNICODE
#define BoxedAppSDK_CreateVirtualFileBasedOnIStream BoxedAppSDK_CreateVirtualFileBasedOnIStreamW
#else
#define BoxedAppSDK_CreateVirtualFileBasedOnIStream BoxedAppSDK_CreateVirtualFileBasedOnIStreamA
#endif // UNICODE

HANDLE BXAPI BoxedAppSDK_CreateVirtualFileBasedOnBufferA(
    LPCSTR szPath, 
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile, 

    PVOID pData, DWORD dwSize
);

HANDLE BXAPI BoxedAppSDK_CreateVirtualFileBasedOnBufferW(
    LPCWSTR szPath, 
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile, 

    PVOID pData, DWORD dwSize
);

#ifdef UNICODE
#define BoxedAppSDK_CreateVirtualFileBasedOnBuffer BoxedAppSDK_CreateVirtualFileBasedOnBufferW
#else
#define BoxedAppSDK_CreateVirtualFileBasedOnBuffer BoxedAppSDK_CreateVirtualFileBasedOnBufferA
#endif // UNICODE

HANDLE BXAPI BoxedAppSDK_CreateVirtualFileOnFilePartW(
    LPCWSTR szPath,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile,

    LPCWSTR szSourcePath,
    DWORD dwOffsetLow,
    DWORD dwOffsetHigh,
    DWORD dwSizeLow,
    DWORD dwSizeHigh);

HANDLE BXAPI BoxedAppSDK_CreateVirtualFileOnFilePartA(
    LPCSTR szPath,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile,

    LPCSTR szSourcePath,
    DWORD dwOffsetLow,
    DWORD dwOffsetHigh,
    DWORD dwSizeLow,
    DWORD dwSizeHigh);

#ifdef UNICODE
#define BoxedAppSDK_CreateVirtualFileOnFilePart BoxedAppSDK_CreateVirtualFileOnFilePartW
#else
#define BoxedAppSDK_CreateVirtualFileOnFilePart BoxedAppSDK_CreateVirtualFileOnFilePartA
#endif // UNICODE

// Get parameter for hooked function
LPVOID BXAPI BoxedAppSDK_GetHookParam();

// Attach BoxedApp SDK to another process
BOOL BXAPI BoxedAppSDK_AttachToProcess(HANDLE hProcess);
// Detach BoxedApp SDK from a process
BOOL BXAPI BoxedAppSDK_DetachFromProcess(HANDLE hProcess);
//
BOOL BXAPI BoxedAppSDK_AddStartupDLLW(LPCWSTR szPath);
//
BOOL BXAPI BoxedAppSDK_AddStartupDLLA(LPCSTR szPath);

#ifdef UNICODE
#define BoxedAppSDK_AddStartupDLL BoxedAppSDK_AddStartupDLLW
#else
#define BoxedAppSDK_AddStartupDLL BoxedAppSDK_AddStartupDLLA
#endif // UNICODE

#ifdef UNICODE
#define BoxedAppSDK_RemoveStartupDLL BoxedAppSDK_RemoveStartupDLLW
#else
#define BoxedAppSDK_RemoveStartupDLL BoxedAppSDK_RemoveStartupDLLA
#endif // UNICODE
BOOL BXAPI BoxedAppSDK_RemoveStartupDLLW(LPCWSTR szPath);
BOOL BXAPI BoxedAppSDK_RemoveStartupDLLA(LPCSTR szPath);


BOOL BXAPI BoxedAppSDK_AddExeToAttachableChildProcExclusionListA(LPCSTR szExeName);

BOOL BXAPI BoxedAppSDK_AddExeToAttachableChildProcExclusionListW(LPCWSTR szExeName);

#ifdef UNICODE
#define BoxedAppSDK_AddExeToAttachableChildProcExclusionList BoxedAppSDK_AddExeToAttachableChildProcExclusionListW
#else
#define BoxedAppSDK_AddExeToAttachableChildProcExclusionList BoxedAppSDK_AddExeToAttachableChildProcExclusionListA
#endif // UNICODE

BOOL BXAPI BoxedAppSDK_RemoveExeFromAttachableChildProcExclusionListA(LPCSTR szExeName);

BOOL BXAPI BoxedAppSDK_RemoveExeFromAttachableChildProcExclusionListW(LPCWSTR szExeName);

#ifdef UNICODE
#define BoxedAppSDK_RemoveExeFromAttachableChildProcExclusionList BoxedAppSDK_RemoveExeFromAttachableChildProcExclusionListW
#else
#define BoxedAppSDK_RemoveExeFromAttachableChildProcExclusionList BoxedAppSDK_RemoveExeFromAttachableChildProcExclusionListA
#endif // UNICODE

BOOL BXAPI BoxedAppSDK_AddExeToAttachableChildProcListA(LPCSTR szExeName);

BOOL BXAPI BoxedAppSDK_AddExeToAttachableChildProcListW(LPCWSTR szExeName);

#ifdef UNICODE
#define BoxedAppSDK_AddExeToAttachableChildProcList BoxedAppSDK_AddExeToAttachableChildProcListW
#else
#define BoxedAppSDK_AddExeToAttachableChildProcList BoxedAppSDK_AddExeToAttachableChildProcListA
#endif // UNICODE

BOOL BXAPI BoxedAppSDK_RemoveExeFromAttachableChildProcListA(LPCSTR szExeName);

BOOL BXAPI BoxedAppSDK_RemoveExeFromAttachableChildProcListW(LPCWSTR szExeName);

#ifdef UNICODE
#define BoxedAppSDK_RemoveExeFromAttachableChildProcList BoxedAppSDK_RemoveExeFromAttachableChildProcListW
#else
#define BoxedAppSDK_RemoveExeFromAttachableChildProcList BoxedAppSDK_RemoveExeFromAttachableChildProcListA
#endif // UNICODE

// Execute .net application
DWORD BXAPI BoxedAppSDK_ExecuteDotNetApplicationW(LPCWSTR szPath, LPCWSTR szArgs);
DWORD BXAPI BoxedAppSDK_ExecuteDotNetApplicationA(LPCSTR szPath, LPCSTR szArgs);

#ifdef UNICODE
#define BoxedAppSDK_ExecuteDotNetApplication BoxedAppSDK_ExecuteDotNetApplicationW
#else
#define BoxedAppSDK_ExecuteDotNetApplication BoxedAppSDK_ExecuteDotNetApplicationA
#endif // UNICODE

// Execute .net application, with or without calling AppDomain.Unload()
// AppDomain.Unload() may hang the process for some time
DWORD BXAPI BoxedAppSDK_ExecuteDotNetApplicationExW(LPCWSTR szPath, LPCWSTR szArgs, BOOL bCallAppDomainUnload);
DWORD BXAPI BoxedAppSDK_ExecuteDotNetApplicationExA(LPCSTR szPath, LPCSTR szArgs, BOOL bCallAppDomainUnload);

#ifdef UNICODE
#define BoxedAppSDK_ExecuteDotNetApplicationEx BoxedAppSDK_ExecuteDotNetApplicationExW
#else
#define BoxedAppSDK_ExecuteDotNetApplicationEx BoxedAppSDK_ExecuteDotNetApplicationExA
#endif // UNICODE

// Internal; don't use
DWORD BXAPI BoxedAppSDK_GetInternalValue(DWORD nValueId, LPVOID buf, DWORD dwSize);

// Function hooking
HANDLE BXAPI BoxedAppSDK_HookFunctionWithParam(PVOID pFunction, PVOID pHook, LPVOID pParam, BOOL bEnable);
HANDLE BXAPI BoxedAppSDK_HookFunction(PVOID pFunction, PVOID pHook, BOOL bEnable);
BOOL BXAPI BoxedAppSDK_SetHookParam(HANDLE pHook, LPVOID pParam);
PVOID BXAPI BoxedAppSDK_GetOriginalFunction(HANDLE hHook);
BOOL BXAPI BoxedAppSDK_EnableHook(HANDLE hHook, BOOL bEnable);
BOOL BXAPI BoxedAppSDK_UnhookFunction(HANDLE hHook);

#ifndef DWORD_PTR
#define DWORD_PTR SIZE_T
#endif // !DWORD_PTR

HMODULE BXAPI BoxedAppSDK_RemoteProcess_LoadLibraryA(DWORD dwProcessId, LPCSTR szPath);
HMODULE BXAPI BoxedAppSDK_RemoteProcess_LoadLibraryW(DWORD dwProcessId, LPCWSTR szPath);

#ifdef UNICODE
#define BoxedAppSDK_RemoteProcess_LoadLibrary BoxedAppSDK_RemoteProcess_LoadLibraryW
#else
#define BoxedAppSDK_RemoteProcess_LoadLibrary BoxedAppSDK_RemoteProcess_LoadLibraryA
#endif // UNICODE

BOOL BXAPI BoxedAppSDK_RemoteProcess_FreeLibrary(DWORD dwProcessId, HMODULE hModule);

DWORD BXAPI BoxedAppSDK_RegisterCOMServerInVirtualRegistryA(LPCSTR szCommandLine);
DWORD BXAPI BoxedAppSDK_RegisterCOMServerInVirtualRegistryW(LPCWSTR szCommandLine);

#ifdef UNICODE
#define BoxedAppSDK_RegisterCOMServerInVirtualRegistry BoxedAppSDK_RegisterCOMServerInVirtualRegistryW
#else
#define BoxedAppSDK_RegisterCOMServerInVirtualRegistry BoxedAppSDK_RegisterCOMServerInVirtualRegistryA
#endif // UNICODE

BOOL BXAPI BoxedAppSDK_IsMainProcess();
BOOL BXAPI BoxedAppSDK_IsVirtualProcessId(DWORD dwProcessId);
BOOL BXAPI BoxedAppSDK_IsAttachedProcessId(DWORD dwProcessId);

typedef BOOL (WINAPI *P_BoxedAppSDK_EnumVirtualRegKeysCallbackA)(HKEY hRootKey, LPCSTR szSubKey, LPARAM lParam);
typedef BOOL (WINAPI *P_BoxedAppSDK_EnumVirtualRegKeysCallbackW)(HKEY hRootKey, LPCWSTR szSubKey, LPARAM lParam);

BOOL BXAPI BoxedAppSDK_EnumVirtualRegKeysA(P_BoxedAppSDK_EnumVirtualRegKeysCallbackA pEnumFunc, LPARAM lParam);
BOOL BXAPI BoxedAppSDK_EnumVirtualRegKeysW(P_BoxedAppSDK_EnumVirtualRegKeysCallbackW pEnumFunc, LPARAM lParam);

#ifdef UNICODE
#define BoxedAppSDK_EnumVirtualRegKeys BoxedAppSDK_EnumVirtualRegKeysW
#define P_BoxedAppSDK_EnumVirtualRegKeysCallback P_BoxedAppSDK_EnumVirtualRegKeysCallbackW
#else
#define BoxedAppSDK_EnumVirtualRegKeys BoxedAppSDK_EnumVirtualRegKeysA
#define P_BoxedAppSDK_EnumVirtualRegKeysCallback P_BoxedAppSDK_EnumVirtualRegKeysCallbackA
#endif // UNICODE

#ifndef DEF_BOXEDAPPSDK_INTERFACES_NOT_REQUIRED

BOOL BXAPI BoxedAppSDK_CreateCustomVirtualDirectoryA(
    LPCSTR lpPathName, 
    IBxFile* pFile, 
    LPSECURITY_ATTRIBUTES lpSecurityAttributes);

BOOL BXAPI BoxedAppSDK_CreateCustomVirtualDirectoryW(
    LPCWSTR lpPathName, 
    IBxFile* pFile, 
    LPSECURITY_ATTRIBUTES lpSecurityAttributes);

#ifdef UNICODE
#define BoxedAppSDK_CreateCustomVirtualDirectory BoxedAppSDK_CreateCustomVirtualDirectoryW
#else
#define BoxedAppSDK_CreateCustomVirtualDirectory BoxedAppSDK_CreateCustomVirtualDirectoryA
#endif // UNICODE

#endif // !DEF_BOXEDAPPSDK_INTERFACES_NOT_REQUIRED

#ifndef DEF_BOXEDAPPSDK_INTERFACES_NOT_REQUIRED

/// Retrieves global file isolation mode
BxIsolationMode BXAPI BoxedAppSDK_GetGlobalFileIsolationMode();

/// Sets global file isolation mode
/// Some file requests (depending on isolation mode) are passed to szDestinationPath
BOOL BXAPI BoxedAppSDK_SetGlobalFileIsolationModeA(BxIsolationMode IsolationMode, LPCSTR szDestinationPath);

/// Sets global file isolation mode
/// Some file requests (depending on isolation mode) are passed to szDestinationPath
BOOL BXAPI BoxedAppSDK_SetGlobalFileIsolationModeW(BxIsolationMode IsolationMode, LPCWSTR szDestinationPath);

#ifdef UNICODE
#define BoxedAppSDK_SetGlobalFileIsolationMode BoxedAppSDK_SetGlobalFileIsolationModeW
#else
#define BoxedAppSDK_SetGlobalFileIsolationMode BoxedAppSDK_SetGlobalFileIsolationModeA
#endif // UNICODE

/// Sets isolation mode for directory / file
/// Some file requests (depending on isolation mode) are passed from szRedirectedPath to szDestinationPath
BOOL BXAPI BoxedAppSDK_SetFileIsolationModeW(BxIsolationMode IsolationMode, LPCWSTR szRedirectedPath, LPCWSTR szDestinationPath);

/// Sets isolation mode for directory / file
/// Some file requests (depending on isolation mode) are passed from szRedirectedPath to szDestinationPath
BOOL BXAPI BoxedAppSDK_SetFileIsolationModeA(BxIsolationMode IsolationMode, LPCSTR szRedirectedPath, LPCSTR szDestinationPath);

#ifdef UNICODE
#define BoxedAppSDK_SetFileIsolationMode BoxedAppSDK_SetFileIsolationModeW
#else
#define BoxedAppSDK_SetFileIsolationMode BoxedAppSDK_SetFileIsolationModeA
#endif // UNICODE

#endif // !DEF_BOXEDAPPSDK_INTERFACES_NOT_REQUIRED

/// Returns whether the handle virtual
BOOL BXAPI BoxedAppSDK_IsVirtualHandle(HANDLE Handle);

// If bxsdk32.dll / bxsdk64.dll can't be loaded, it creates a virtual bxsdk32.dll / bxsdk64.dll, 
// all exports points to the correct code
// Useful when you link BoxedAppSDK statically, but some code (another DLL) needs bxsdk32.dll / bxsdk64.dll
// Also see function BoxedAppSDK_SetVirtualBoxedAppSDKDLLBaseDir
void BXAPI BoxedAppSDK_EmulateBoxedAppSDKDLL();

// Specifies a base directory where virtual bxsdk32.dll / bxsdk64.dll will be placed
// Actually for each process the virtual bxsdk32.dll / bxsdk64.dll is placed into <base dir>\\proces__int64\\
// Virtual bxsdk32.dll / bxsdk64.dll can be created when BoxedAppSDK_EmulateBoxedAppSDKDLL()
// is called, or when new process is begin attached to virtual environment (you know, 
// it's important to have a virtual bxsdk32.dll / bxsdk64.dll if main process uses
// static library of BoxedApp SDK, so real bxsdk32.dll / bxsdk64.dll doesn't exist; but
// attached process should be able to call functions of bxsdk32.dll / bxsdk64.dll -- that's
// the reason)
// It's not required to call this function; boxedapp can use a default value of 
// the directory
// Also see function BoxedAppSDK_EmulateBoxedAppSDKDLL
void BXAPI BoxedAppSDK_SetVirtualBoxedAppSDKDLLBaseDirA(LPCSTR szDir);
void BXAPI BoxedAppSDK_SetVirtualBoxedAppSDKDLLBaseDirW(LPCWSTR szDir);

#ifdef UNICODE
#define BoxedAppSDK_SetVirtualBoxedAppSDKDLLBaseDir BoxedAppSDK_SetVirtualBoxedAppSDKDLLBaseDirW
#else
#define BoxedAppSDK_SetVirtualBoxedAppSDKDLLBaseDir BoxedAppSDK_SetVirtualBoxedAppSDKDLLBaseDirA
#endif // UNICODE

//
// Shared memory API
//

typedef LONGLONG BOXEDAPP_SHARED_PTR;

BOXEDAPP_SHARED_PTR BXAPI BoxedAppSDK_SharedMem_Alloc(int nSize);
void BXAPI BoxedAppSDK_SharedMem_Free(BOXEDAPP_SHARED_PTR shared_ptr);

PVOID BXAPI BoxedAppSDK_SharedMem_Lock(BOXEDAPP_SHARED_PTR shared_ptr);
BOOL BXAPI BoxedAppSDK_SharedMem_Unlock(BOXEDAPP_SHARED_PTR shared_ptr);

HRESULT BXAPI BoxedAppSDK_SharedMem_CreateStreamOnSharedMem(LPSTREAM* ppStream);

BOOL BXAPI BoxedAppSDK_AddStubCandidateA(LPCSTR szStubPath);
BOOL BXAPI BoxedAppSDK_AddStubCandidateW(LPCWSTR szStubPath);

#ifdef UNICODE
#define BoxedAppSDK_AddStubCandidate BoxedAppSDK_AddStubCandidateW
#else
#define BoxedAppSDK_AddStubCandidate BoxedAppSDK_AddStubCandidateA
#endif // UNICODE

BOOL BXAPI BoxedAppSDK_RemoveStubCandidateA(LPCSTR szStubPath);
BOOL BXAPI BoxedAppSDK_RemoveStubCandidateW(LPCWSTR szStubPath);

#ifdef UNICODE
#define BoxedAppSDK_RemoveStubCandidate BoxedAppSDK_RemoveStubCandidateW
#else
#define BoxedAppSDK_RemoveStubCandidate BoxedAppSDK_RemoveStubCandidateA
#endif // UNICODE

BOOL BXAPI BoxedAppSDK_IsVirtualRegValueW(HKEY hKey, LPCWSTR szValueName);
BOOL BXAPI BoxedAppSDK_IsVirtualRegValueA(HKEY hKey, LPCSTR szValueName);

#ifdef UNICODE
#define BoxedAppSDK_IsVirtualRegValue BoxedAppSDK_IsVirtualRegValueW
#else
#define BoxedAppSDK_IsVirtualRegValue BoxedAppSDK_IsVirtualRegValueA
#endif // UNICODE

// Virtual installing of assembly
BOOL BXAPI BoxedAppSDK_InstallAssemblyA(LPCSTR szManifestPath, LPCSTR szPolicyPath);
BOOL BXAPI BoxedAppSDK_InstallAssemblyW(LPCWSTR szManifestPath, LPCWSTR szPolicyPath);

#ifdef UNICODE
#define BoxedAppSDK_InstallAssembly BoxedAppSDK_InstallAssemblyW
#else
#define BoxedAppSDK_InstallAssembly BoxedAppSDK_InstallAssemblyA
#endif // UNICODE

// Specify path to bxsdk32.dll / bxsdk64.dll
// It's useful in the following case: 
// your application statically linked with BoxedApp SDK, so it doesn't require the DLL to work
// if a process that has another bitness should be attached to the virtual environment, BoxedApp SDK
// will try to use bxsdk32.dll (to attach 32 bit process) or bxsdk64.dll (to attach 64 bit process)
// But your application doesn't need the DLLs. To help BoxedApp SDK you could place 
// bxsdk32.dll / bxsdk64.dll somewhere and make BoxedApp SDK uses these paths
// If you just put bxsdk32.dll and bxsdk64.dll to the exe's directory - you don't need to call
// these functions: BoxedApp SDK will find these dlls automatically

BOOL BXAPI BoxedAppSDK_SetBxSdk32DllPathW(LPCWSTR szPath);
BOOL BXAPI BoxedAppSDK_SetBxSdk32DllPathA(LPCSTR szPath);

#ifdef UNICODE
#define BoxedAppSDK_SetBxSdk32DllPath BoxedAppSDK_SetBxSdk32DllPathW
#else
#define BoxedAppSDK_SetBxSdk32DllPath BoxedAppSDK_SetBxSdk32DllPathA
#endif // UNICODE

BOOL BXAPI BoxedAppSDK_SetBxSdk64DllPathW(LPCWSTR szPath);
BOOL BXAPI BoxedAppSDK_SetBxSdk64DllPathA(LPCSTR szPath);

#ifdef UNICODE
#define BoxedAppSDK_SetBxSdk64DllPath BoxedAppSDK_SetBxSdk64DllPathW
#else
#define BoxedAppSDK_SetBxSdk64DllPath BoxedAppSDK_SetBxSdk64DllPathA
#endif // UNICODE

// Specify path to a DLL that redirects call to BoxedApp
// It's useful in the following case: 
// your application statically linked with BoxedApp SDK, so it doesn't require the DLL to work
// if a virtual process must be created with CreateProcessWithLogonW, a special helper process
// based on rundll32.exe is started, and rundll32.exe needs a DLL
// Be default, path to boxedapp sdk dll passed, but you can specify your own dll ("shim")
// that will redirect calls to boxedapp sdk code (statically linked into your dll)

BOOL BXAPI BoxedAppSDK_SetBxSdk32ShimDllPathW(LPCWSTR szPath);
BOOL BXAPI BoxedAppSDK_SetBxSdk32ShimDllPathA(LPCSTR szPath);

#ifdef UNICODE
#define BoxedAppSDK_SetBxSdk32ShimDllPath BoxedAppSDK_SetBxSdk32ShimDllPathW
#else
#define BoxedAppSDK_SetBxSdk32ShimDllPath BoxedAppSDK_SetBxSdk32ShimDllPathA
#endif // UNICODE

BOOL BXAPI BoxedAppSDK_SetBxSdk64ShimDllPathW(LPCWSTR szPath);
BOOL BXAPI BoxedAppSDK_SetBxSdk64ShimDllPathA(LPCSTR szPath);

#ifdef UNICODE
#define BoxedAppSDK_SetBxSdk64ShimDllPath BoxedAppSDK_SetBxSdk64ShimDllPathW
#else
#define BoxedAppSDK_SetBxSdk64ShimDllPath BoxedAppSDK_SetBxSdk64ShimDllPathA
#endif // UNICODE

BOOL BXAPI BoxedAppSDK_SetVirtualVolumeSerialW(LPCWSTR szPath, DWORD nVolumeSerial);
BOOL BXAPI BoxedAppSDK_SetVirtualVolumeSerialA(LPCSTR szPath, DWORD nVolumeSerial);

#ifdef UNICODE
#define BoxedAppSDK_SetVirtualVolumeSerial BoxedAppSDK_SetVirtualVolumeSerialW
#else
#define BoxedAppSDK_SetVirtualVolumeSerial BoxedAppSDK_SetVirtualVolumeSerialA
#endif // UNICODE

BOOL BXAPI BoxedAppSDK_SetVirtualVolumeCreationTimeW(LPCWSTR szPath, FILETIME nVolumeCreationTime);
BOOL BXAPI BoxedAppSDK_SetVirtualVolumeCreationTimeA(LPCSTR szPath, FILETIME nVolumeCreationTime);

#ifdef UNICODE
#define BoxedAppSDK_SetVirtualVolumeCreationTime BoxedAppSDK_SetVirtualVolumeCreationTimeW
#else
#define BoxedAppSDK_SetVirtualVolumeCreationTime BoxedAppSDK_SetVirtualVolumeCreationTimeA
#endif // UNICODE

BOOL BXAPI BoxedAppSDK_SetVirtualVolumeNameW(LPCWSTR szPath, LPCWSTR szVolumeName);
BOOL BXAPI BoxedAppSDK_SetVirtualVolumeNameA(LPCSTR szPath, LPCSTR szVolumeName);

#ifdef UNICODE
#define BoxedAppSDK_SetVirtualVolumeName BoxedAppSDK_SetVirtualVolumeNameW
#else
#define BoxedAppSDK_SetVirtualVolumeName BoxedAppSDK_SetVirtualVolumeNameA
#endif // UNICODE

BOOL BXAPI BoxedAppSDK_SetBxSdkRawData(PVOID pData, DWORD dwSize);

typedef void (WINAPI* P_BoxedAppSDK_IPC_Listener)(PVOID pRequestData, DWORD dwRequestSize);

VOID BXAPI BoxedAppSDK_IPC_AddListenerW(P_BoxedAppSDK_IPC_Listener pListener, LPCWSTR szMessageClass);
VOID BXAPI BoxedAppSDK_IPC_AddListenerA(P_BoxedAppSDK_IPC_Listener pListener, LPCSTR szMessageClass);

#ifdef UNICODE
#define BoxedAppSDK_IPC_AddListener BoxedAppSDK_IPC_AddListenerW
#else
#define BoxedAppSDK_IPC_AddListener BoxedAppSDK_IPC_AddListenerA
#endif // UNICODE

VOID BXAPI BoxedAppSDK_IPC_RemoveListener(P_BoxedAppSDK_IPC_Listener pListener);

BOOL BXAPI BoxedAppSDK_IPC_SendMessageW(LPCWSTR szMessageClass, LPCVOID lpcMessage, DWORD dwMessageSize);
BOOL BXAPI BoxedAppSDK_IPC_SendMessageA(LPCSTR szMessageClass, LPCVOID lpcMessage, DWORD dwMessageSize);

#ifdef UNICODE
#define BoxedAppSDK_IPC_SendMessage BoxedAppSDK_IPC_SendMessageW
#else
#define BoxedAppSDK_IPC_SendMessage BoxedAppSDK_IPC_SendMessageA
#endif // UNICODE

BOOL BXAPI BoxedAppSDK_IPC_SendMessageToProcessW(DWORD dwPid, LPCWSTR szMessageClass, LPCVOID lpcMessage, DWORD dwMessageSize);
BOOL BXAPI BoxedAppSDK_IPC_SendMessageToProcessA(DWORD dwPid, LPCSTR szMessageClass, LPCVOID lpcMessage, DWORD dwMessageSize);

#ifdef UNICODE
#define BoxedAppSDK_IPC_SendMessageToProcess BoxedAppSDK_IPC_SendMessageToProcessW
#else
#define BoxedAppSDK_IPC_SendMessageToProcess BoxedAppSDK_IPC_SendMessageToProcessA
#endif // UNICODE

void BXAPI BoxedAppSDK_EnableDebugStatistics(BOOL bEnable, DWORD nThreadId);

typedef struct _SBxDebugStatistics
{
    ULONGLONG m_nAllocationCount;
} SBxDebugStatistics;

BOOL BXAPI BoxedAppSDK_GetDebugStatistics(SBxDebugStatistics* pInfo);

#ifndef DEF_BOXEDAPPSDK_INTERFACES_NOT_REQUIRED

HRESULT BXAPI BxCreateReadonlyRegistryWriter(IStream* outputStream, IBxReadonlyRegistryWriter** readonlyRegistryWriter);

HRESULT BOXEDAPPSDKAPI BxCreateReadonlyRegistryTree(
    LPCWSTR registryPath,
    DWORD64 dataOffset,
    DWORD dataLength,
    IUnknown* serviceProvider,
    IBxRegTree** treePtr);

HRESULT BOXEDAPPSDKAPI BxCreateRegistryLayerBasedOnIBxRegTree(
    IBxRegTree* tree,
    REFIID iid,
    PVOID* objectPtr);

#endif // !DEF_BOXEDAPPSDK_INTERFACES_NOT_REQUIRED

HRESULT BOXEDAPPSDKAPI BxCreateVirtualEnvironment(REFIID iid, PVOID* objectPtr);
HRESULT BOXEDAPPSDKAPI BxCreateMemoryBasedRegistryLayer(REFIID iid, PVOID* objectPtr);

HRESULT BOXEDAPPSDKAPI BxCreateFileSystemLayerBasedOnSandboxDirectoryW(
    LPCWSTR sandboxDirectoryPath,
    REFIID iid,
    PVOID* objectPtr);

HRESULT BOXEDAPPSDKAPI BxCreateFileSystemLayerBasedOnSandboxDirectoryA(
    LPCSTR sandboxDirectoryPath,
    REFIID iid,
    PVOID* objectPtr);

#ifdef UNICODE
#define BxCreateFileSystemLayerBasedOnSandboxDirectory BxCreateFileSystemLayerBasedOnSandboxDirectoryW
#else
#define BxCreateFileSystemLayerBasedOnSandboxDirectory BxCreateFileSystemLayerBasedOnSandboxDirectoryA
#endif // UNICODE

HRESULT BOXEDAPPSDKAPI BxCreateFileSandboxConfiguration(
    REFIID iid,
    PVOID* objectPtr);

HRESULT BOXEDAPPSDKAPI BxCreatePredefinedDirectoriesInfoProvider(
    REFIID iid,
    PVOID* objectPtr);

#ifdef __cplusplus
}
#endif

#include <poppack.h>

#endif // !__BOXEDAPPSDK_H__

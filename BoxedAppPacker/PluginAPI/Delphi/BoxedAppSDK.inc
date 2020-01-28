// Copyright (c) Softanics

{$IFNDEF BOXEDAPP_PAS_IS_INCLUDED}
unit BoxedAppSDK;
{$ENDIF}

interface

uses Windows, ActiveX;

// Available options, see BoxedAppSDK_EnableOption and BoxedAppSDK_IsOptionEnabled
const DEF_BOXEDAPPSDK_OPTION__ALL_CHANGES_ARE_VIRTUAL = 1; // default: false
const DEF_BOXEDAPPSDK_OPTION__EMBED_BOXEDAPP_IN_CHILD_PROCESSES = 2; // default: false
const DEF_BOXEDAPPSDK_OPTION__ENABLE_VIRTUAL_FILE_SYSTEM = 3; // default: true
const DEF_BOXEDAPPSDK_OPTION__RECREATE_VIRTUAL_FILE_AS_VIRTUAL = 4; // default: 1 (TRUE)
const DEF_BOXEDAPPSDK_OPTION__ENABLE_VIRTUAL_REGISTRY = 5; // default: 1 (TRUE)
const DEF_BOXEDAPPSDK_OPTION__HIDE_VIRTUAL_FILES_FROM_FILE_DIALOG = 6; // default: 0 (FALSE)
const DEF_BOXEDAPPSDK_OPTION__EMULATE_OUT_OF_PROC_COM_SERVERS = 7; // default: 0 (FALSE)
const DEF_BOXEDAPPSDK_OPTION__INHERIT_OPTIONS = 8; // default: 0 (FALSE)

// Startup flags
const DEF_BOXEDAPPSDK_STARTUP_OPTION__HOOK_ENGINE = 1; // default: false

const EnumBoxedAppSDK_RequestId__RegQueryValue = 1;
const EnumBoxedAppSDK_RequestId__RedirectFilePath = 2;

type

TBoxedAppHandler = 
	function(Param: Pointer; RequestId: DWORD; pAdditionalInfo: Pointer): DWORD; stdcall;

SBoxedAppSDK__RedirectFilePath = packed record
	// in
	m_szPath: PWideChar;

	// out
	m_bHandled: DWORD;

	m_szRedirectToPath: PWideChar;
end;
PBoxedAppSDK__RedirectFilePath = ^SBoxedAppSDK__RedirectFilePath;

SBoxedAppSDK__RegQueryValue = packed record
	// in
	m_Root: HKEY;
	m_szPath: PWideChar;
	m_szValue: PWideChar;

	// out
	m_bHandled: DWORD;

	m_dwType: DWORD;
	m_pData: Pointer;
	m_dwSize: DWORD;
end;
PBoxedAppSDK__RegQueryValue = ^SBoxedAppSDK__RegQueryValue;

TBoxedAppSDK_EnumVirtualRegKeysCallbackA = 
	function(hRootKey: HKEY; szSubKey: PAnsiChar; lParam: Cardinal): Boolean; stdcall;
TBoxedAppSDK_EnumVirtualRegKeysCallbackW = 
	function(hRootKey: HKEY; szSubKey: PWideChar; lParam: Cardinal): Boolean; stdcall;
{$IFDEF UNICODE}
TBoxedAppSDK_EnumVirtualRegKeysCallback = TBoxedAppSDK_EnumVirtualRegKeysCallbackW;
{$ELSE}
TBoxedAppSDK_EnumVirtualRegKeysCallback = TBoxedAppSDK_EnumVirtualRegKeysCallbackA;
{$ENDIF}

BOXEDAPP_SHARED_PTR = LargeInt;

function BoxedAppSDK_Init: BOOL; stdcall;
function BoxedAppSDK_Exit: BOOL; stdcall;

procedure BoxedAppSDK_EnableDebugLog(bEnable: BOOL); stdcall;

procedure BoxedAppSDK_SetLogFile(szLogFilePath: PChar); stdcall;
procedure BoxedAppSDK_SetLogFileA(szLogFilePath: PAnsiChar); stdcall;
procedure BoxedAppSDK_SetLogFileW(szLogFilePath: PWideChar); stdcall;

function BoxedAppSDK_CreateVirtualFile(
         lpFileName: PChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle): THandle; stdcall;

function BoxedAppSDK_CreateVirtualFileA(
         lpFileName: PAnsiChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle): THandle; stdcall;

function BoxedAppSDK_CreateVirtualFileW(
         lpFileName: PWideChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle): THandle; stdcall;


function BoxedAppSDK_CreateVirtualDirectory(
         lpPathName: PChar;
         lpSecurityAttributes: PSecurityAttributes): BOOL; stdcall;

function BoxedAppSDK_CreateVirtualDirectoryA(
         lpPathName: PAnsiChar;
         lpSecurityAttributes: PSecurityAttributes): BOOL; stdcall;

function BoxedAppSDK_CreateVirtualDirectoryW(
         lpPathName: PWideChar;
         lpSecurityAttributes: PSecurityAttributes): BOOL; stdcall;


function BoxedAppSDK_CreateVirtualFileBasedOnIStream(
         lpFileName: PChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle;
         pStream: IStream): THandle; stdcall;

function BoxedAppSDK_CreateVirtualFileBasedOnIStreamA(
         lpFileName: PAnsiChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle;
         pStream: IStream): THandle; stdcall;

function BoxedAppSDK_CreateVirtualFileBasedOnIStreamW(
         lpFileName: PWideChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle;
         pStream: IStream): THandle; stdcall;


function BoxedAppSDK_CreateVirtualFileBasedOnBuffer(
         lpFileName: PChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle;
         pData: Pointer;
         dwSize: DWORD): THandle; stdcall;

function BoxedAppSDK_CreateVirtualFileBasedOnBufferA(
         lpFileName: PAnsiChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle;
         pData: Pointer;
         dwSize: DWORD): THandle; stdcall;

function BoxedAppSDK_CreateVirtualFileBasedOnBufferW(
         lpFileName: PWideChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle;
         pData: Pointer; 
         dwSize: DWORD): THandle; stdcall;

function BoxedAppSDK_IsVirtualFile(szPath: PChar): BOOL; stdcall;
function BoxedAppSDK_IsVirtualFileA(szPath: PAnsiChar): BOOL; stdcall;
function BoxedAppSDK_IsVirtualFileW(szPath: PWideChar): BOOL; stdcall;

function BoxedAppSDK_CreateVirtualRegKey(
         hKey: HKEY;
         lpSubKey: PChar;
         Reserved: DWORD;
         lpClass: PChar;
         dwOptions: DWORD;
         samDesired: REGSAM;
         lpSecurityAttributes: PSecurityAttributes;
         var phkResult: HKEY;
         lpdwDisposition: PDWORD): Longint; stdcall;

function BoxedAppSDK_CreateVirtualRegKeyA(
         hKey: HKEY;
         lpSubKey: PAnsiChar;
         Reserved: DWORD;
         lpClass: PAnsiChar;
         dwOptions: DWORD;
         samDesired: REGSAM;
         lpSecurityAttributes: PSecurityAttributes;
         var phkResult: HKEY;
         lpdwDisposition: PDWORD): Longint; stdcall;

function BoxedAppSDK_CreateVirtualRegKeyW(
         hKey: HKEY;
         lpSubKey: PWideChar;
         Reserved: DWORD;
         lpClass: PWideChar;
         dwOptions: DWORD;
         samDesired: REGSAM;
         lpSecurityAttributes: PSecurityAttributes;
         var phkResult: HKEY;
         lpdwDisposition: PDWORD): Longint; stdcall;

function BoxedAppSDK_RegisterCOMLibraryInVirtualRegistry(szPath: PChar): Longint; stdcall;
function BoxedAppSDK_RegisterCOMLibraryInVirtualRegistryA(szPath: PAnsiChar): Longint; stdcall;
function BoxedAppSDK_RegisterCOMLibraryInVirtualRegistryW(szPath: PWideChar): Longint; stdcall;

function BoxedAppSDK_RegisterCOMServerInVirtualRegistry(szCommandLine: PChar): Longint; stdcall;
function BoxedAppSDK_RegisterCOMServerInVirtualRegistryA(szCommandLine: PAnsiChar): Longint; stdcall;
function BoxedAppSDK_RegisterCOMServerInVirtualRegistryW(szCommandLine: PWideChar): Longint; stdcall;

function BoxedAppSDK_SetContext(szContext: PAnsiChar): Longint; stdcall;

function BoxedAppSDK_AddHandler(pHandler: TBoxedAppHandler; Param: Pointer): DWORD; stdcall;
function BoxedAppSDK_RemoveHandler(dwHandlerId: DWORD): DWORD; stdcall;

function BoxedAppSDK_Alloc(dwSize: DWORD): Pointer; stdcall;
function BoxedAppSDK_Free(pData: Pointer): DWORD; stdcall;

function BoxedAppSDK_SharedMem_Alloc(dwSize: DWORD): BOXEDAPP_SHARED_PTR; stdcall;
procedure BoxedAppSDK_SharedMem_Free(shared_ptr: BOXEDAPP_SHARED_PTR); stdcall;
function BoxedAppSDK_SharedMem_Lock(shared_ptr: DWORD): Pointer; stdcall;
function BoxedAppSDK_SharedMem_Unlock(shared_ptr: DWORD): BOOL; stdcall;

procedure BoxedAppSDK_EnableOption(dwOptionIndex: DWORD; bEnable: BOOL); stdcall;
function BoxedAppSDK_IsOptionEnabled(dwOptionIndex: DWORD): BOOL; stdcall;

procedure BoxedAppSDK_RemoteProcess_EnableOption(dwProcessId: DWORD; dwOptionIndex: DWORD; bEnable: BOOL); stdcall;
function BoxedAppSDK_RemoteProcess_IsOptionEnabled(dwProcessId: DWORD; dwOptionIndex: DWORD): BOOL; stdcall;

procedure BoxedAppSDK_SetStartupFlags(dwFlags: DWORD); stdcall;

function BoxedAppSDK_DeleteFileFromVirtualFileSystem(szPath: PChar): Longint; stdcall;
function BoxedAppSDK_DeleteFileFromVirtualFileSystemA(szPath: PAnsiChar): Longint; stdcall;
function BoxedAppSDK_DeleteFileFromVirtualFileSystemW(szPath: PWideChar): Longint; stdcall;

function BoxedAppSDK_CreateProcessFromMemoryA(
	pBuffer: Pointer;
	dwSize: DWORD;

	lpApplicationName: PAnsiChar; 
	lpCommandLine: PAnsiChar;
	lpProcessAttributes, lpThreadAttributes: PSecurityAttributes;
	bInheritHandles: BOOL; 
	dwCreationFlags: DWORD; 
	lpEnvironment: Pointer;
	lpCurrentDirectory: PAnsiChar; 
	const lpStartupInfo: TStartupInfo;
	var lpProcessInformation: TProcessInformation): BOOL; stdcall;
function BoxedAppSDK_CreateProcessFromMemoryW(
	pBuffer: Pointer;
	dwSize: DWORD;

	lpApplicationName: PWideChar; 
	lpCommandLine: PWideChar;
	lpProcessAttributes, lpThreadAttributes: PSecurityAttributes;
	bInheritHandles: BOOL; 
	dwCreationFlags: DWORD; 
	lpEnvironment: Pointer;
	lpCurrentDirectory: PWideChar; 
	const lpStartupInfo: TStartupInfo;
	var lpProcessInformation: TProcessInformation): BOOL; stdcall;
function BoxedAppSDK_CreateProcessFromMemory(
	pBuffer: Pointer;
	dwSize: DWORD;

	lpApplicationName: PChar;
	lpCommandLine: PChar;
	lpProcessAttributes, lpThreadAttributes: PSecurityAttributes;
	bInheritHandles: BOOL; 
	dwCreationFlags: DWORD; 
	lpEnvironment: Pointer;
	lpCurrentDirectory: PChar;
	const lpStartupInfo: TStartupInfo;
	var lpProcessInformation: TProcessInformation): BOOL; stdcall;

function BoxedAppSDK_AttachToProcess(hProcess: THandle): BOOL; stdcall;
function BoxedAppSDK_DetachFromProcess(hProcess: THandle): BOOL; stdcall;

// Internal; don't use
function BoxedAppSDK_GetInternalValue(nValueId: DWORD; buf: Pointer; dwSize: DWORD): DWORD; stdcall;

function BoxedAppSDK_ExecuteDotNetApplication(szPath: PChar; szArgs: PChar): DWORD; stdcall;
function BoxedAppSDK_ExecuteDotNetApplicationA(szPath: PAnsiChar; szArgs: PAnsiChar): DWORD; stdcall;
function BoxedAppSDK_ExecuteDotNetApplicationW(szPath: PWideChar; szArgs: PWideChar): DWORD; stdcall;

function BoxedAppSDK_HookFunction(pFunction: Pointer; pHook: Pointer; bEnable: BOOL): THandle; stdcall;
function BoxedAppSDK_GetOriginalFunction(hHook: THandle): Pointer; stdcall;
function BoxedAppSDK_EnableHook(hHook: THandle; bEnable: BOOL): BOOL; stdcall;
function BoxedAppSDK_UnhookFunction(hHook: THandle): BOOL; stdcall;

function BoxedAppSDK_RemoteProcess_LoadLibrary(dwProcessId: DWORD; szPath: PChar): HMODULE; stdcall;
function BoxedAppSDK_RemoteProcess_LoadLibraryA(dwProcessId: DWORD; szPath: PAnsiChar): HMODULE; stdcall;
function BoxedAppSDK_RemoteProcess_LoadLibraryW(dwProcessId: DWORD; szPath: PWideChar): HMODULE; stdcall;

function BoxedAppSDK_EnumVirtualRegKeys(pEnumFunc: TBoxedAppSDK_EnumVirtualRegKeysCallback; lParam: Cardinal): Boolean; stdcall;
function BoxedAppSDK_EnumVirtualRegKeysA(pEnumFunc: TBoxedAppSDK_EnumVirtualRegKeysCallbackA; lParam: Cardinal): Boolean; stdcall;
function BoxedAppSDK_EnumVirtualRegKeysW(pEnumFunc: TBoxedAppSDK_EnumVirtualRegKeysCallbackW; lParam: Cardinal): Boolean; stdcall;

function BoxedAppSDK_SharedMem_CreateStreamOnSharedMem(var stm: IStream): HResult; stdcall;

function BoxedAppSDK_IsAttachedProcessId(dwProcessId: DWORD): BOOL; stdcall;

function BoxedAppSDK_AddStubCandidate(lpStubPath: PChar): BOOL; stdcall;
function BoxedAppSDK_AddStubCandidateA(lpStubPath: PAnsiChar): BOOL; stdcall;
function BoxedAppSDK_AddStubCandidateW(lpStubPath: PWideChar): BOOL; stdcall;

function BoxedAppSDK_RemoveStubCandidate(lpStubPath: PChar): BOOL; stdcall;
function BoxedAppSDK_RemoveStubCandidateA(lpStubPath: PAnsiChar): BOOL; stdcall;
function BoxedAppSDK_RemoveStubCandidateW(lpStubPath: PWideChar): BOOL; stdcall;

function BoxedAppSDK_SetBxSdkRawData(pData: Pointer; dwSize: DWORD): BOOL; stdcall;

implementation

{$IFNDEF BOXEDAPP_SDK_USE_DLL}
uses
  Classes,
  SysUtils;
{$ENDIF}

{$IFDEF BOXEDAPP_SDK_USE_DLL}
function BoxedAppSDK_Init; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF};
function BoxedAppSDK_Exit; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF};

procedure BoxedAppSDK_EnableDebugLog; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF};

procedure BoxedAppSDK_SetLogFile; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name {$IFDEF UNICODE}'BoxedAppSDK_SetLogFileW'{$ELSE}'BoxedAppSDK_SetLogFileA'{$ENDIF};
procedure BoxedAppSDK_SetLogFileA; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_SetLogFileA';
procedure BoxedAppSDK_SetLogFileW; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_SetLogFileW';

function BoxedAppSDK_CreateVirtualFile; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name {$IFDEF UNICODE}'BoxedAppSDK_CreateVirtualFileW'{$ELSE}'BoxedAppSDK_CreateVirtualFileA'{$ENDIF};
function BoxedAppSDK_CreateVirtualFileA; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_CreateVirtualFileA';
function BoxedAppSDK_CreateVirtualFileW; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_CreateVirtualFileW';

function BoxedAppSDK_CreateVirtualDirectory; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name {$IFDEF UNICODE}'BoxedAppSDK_CreateVirtualDirectoryW'{$ELSE}'BoxedAppSDK_CreateVirtualDirectoryA'{$ENDIF};
function BoxedAppSDK_CreateVirtualDirectoryA; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_CreateVirtualDirectoryA';
function BoxedAppSDK_CreateVirtualDirectoryW; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_CreateVirtualDirectoryW';

function BoxedAppSDK_CreateVirtualFileBasedOnIStream; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name {$IFDEF UNICODE}'BoxedAppSDK_CreateVirtualFileBasedOnIStreamW'{$ELSE}'BoxedAppSDK_CreateVirtualFileBasedOnIStreamA'{$ENDIF};
function BoxedAppSDK_CreateVirtualFileBasedOnIStreamA; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_CreateVirtualFileBasedOnIStreamA';
function BoxedAppSDK_CreateVirtualFileBasedOnIStreamW; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_CreateVirtualFileBasedOnIStreamW';

function BoxedAppSDK_IsVirtualFile; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name {$IFDEF UNICODE}'BoxedAppSDK_IsVirtualFileW'{$ELSE}'BoxedAppSDK_IsVirtualFileA'{$ENDIF};
function BoxedAppSDK_IsVirtualFileA; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_IsVirtualFileA';
function BoxedAppSDK_IsVirtualFileW; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_IsVirtualFileW';

function BoxedAppSDK_CreateVirtualFileBasedOnBuffer; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name {$IFDEF UNICODE}'BoxedAppSDK_CreateVirtualFileBasedOnBufferW'{$ELSE}'BoxedAppSDK_CreateVirtualFileBasedOnBufferA'{$ENDIF};
function BoxedAppSDK_CreateVirtualFileBasedOnBufferA; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_CreateVirtualFileBasedOnBufferA';
function BoxedAppSDK_CreateVirtualFileBasedOnBufferW; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_CreateVirtualFileBasedOnBufferW';

function BoxedAppSDK_CreateVirtualRegKey; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name {$IFDEF UNICODE}'BoxedAppSDK_CreateVirtualRegKeyW'{$ELSE}'BoxedAppSDK_CreateVirtualRegKeyA'{$ENDIF};
function BoxedAppSDK_CreateVirtualRegKeyA; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_CreateVirtualRegKeyA';
function BoxedAppSDK_CreateVirtualRegKeyW; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_CreateVirtualRegKeyW';

function BoxedAppSDK_RegisterCOMLibraryInVirtualRegistry; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name {$IFDEF UNICODE}'BoxedAppSDK_RegisterCOMLibraryInVirtualRegistryW'{$ELSE}'BoxedAppSDK_RegisterCOMLibraryInVirtualRegistryA'{$ENDIF};
function BoxedAppSDK_RegisterCOMLibraryInVirtualRegistryA; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_RegisterCOMLibraryInVirtualRegistryA';
function BoxedAppSDK_RegisterCOMLibraryInVirtualRegistryW; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_RegisterCOMLibraryInVirtualRegistryW';

function BoxedAppSDK_RegisterCOMServerInVirtualRegistry; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name {$IFDEF UNICODE}'BoxedAppSDK_RegisterCOMServerInVirtualRegistryW'{$ELSE}'BoxedAppSDK_RegisterCOMServerInVirtualRegistryA'{$ENDIF};
function BoxedAppSDK_RegisterCOMServerInVirtualRegistryA; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_RegisterCOMServerInVirtualRegistryA';
function BoxedAppSDK_RegisterCOMServerInVirtualRegistryW; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_RegisterCOMServerInVirtualRegistryW';

function BoxedAppSDK_SetContext; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_SetContext';

function BoxedAppSDK_AddHandler; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF};
function BoxedAppSDK_RemoveHandler; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF};

function BoxedAppSDK_Alloc; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF};
function BoxedAppSDK_Free; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF};

function BoxedAppSDK_SharedMem_Alloc; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF};
procedure BoxedAppSDK_SharedMem_Free; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF};
function BoxedAppSDK_SharedMem_Lock; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF};
function BoxedAppSDK_SharedMem_Unlock; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF};

procedure BoxedAppSDK_EnableOption; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF};
function BoxedAppSDK_IsOptionEnabled; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF};

procedure BoxedAppSDK_RemoteProcess_EnableOption; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF};
function BoxedAppSDK_RemoteProcess_IsOptionEnabled; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF};

procedure BoxedAppSDK_SetStartupFlags; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF};

function BoxedAppSDK_DeleteFileFromVirtualFileSystem; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name {$IFDEF UNICODE}'BoxedAppSDK_DeleteFileFromVirtualFileSystemW'{$ELSE}'BoxedAppSDK_DeleteFileFromVirtualFileSystemA'{$ENDIF};
function BoxedAppSDK_DeleteFileFromVirtualFileSystemA; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_DeleteFileFromVirtualFileSystemA';
function BoxedAppSDK_DeleteFileFromVirtualFileSystemW; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_DeleteFileFromVirtualFileSystemW';

function BoxedAppSDK_CreateProcessFromMemoryA; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name {$IFDEF UNICODE}'BoxedAppSDK_CreateProcessFromMemoryW'{$ELSE}'BoxedAppSDK_CreateProcessFromMemoryA'{$ENDIF};
function BoxedAppSDK_CreateProcessFromMemoryW; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_CreateProcessFromMemoryW';
function BoxedAppSDK_CreateProcessFromMemory; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_CreateProcessFromMemory';

function BoxedAppSDK_AttachToProcess; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_AttachToProcess';
function BoxedAppSDK_DetachFromProcess; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_DetachFromProcess';

function BoxedAppSDK_GetInternalValue; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_GetInternalValue';

function BoxedAppSDK_ExecuteDotNetApplication; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name {$IFDEF UNICODE}'BoxedAppSDK_ExecuteDotNetApplicationW'{$ELSE}'BoxedAppSDK_ExecuteDotNetApplicationA'{$ENDIF};
function BoxedAppSDK_ExecuteDotNetApplicationA; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_ExecuteDotNetApplicationA';
function BoxedAppSDK_ExecuteDotNetApplicationW; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_ExecuteDotNetApplicationW';

function BoxedAppSDK_HookFunction; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_HookFunction';
function BoxedAppSDK_GetOriginalFunction; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_GetOriginalFunction';
function BoxedAppSDK_EnableHook; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_EnableHook';
function BoxedAppSDK_UnhookFunction; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_UnhookFunction';

function BoxedAppSDK_RemoteProcess_LoadLibrary; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name {$IFDEF UNICODE}'BoxedAppSDK_RemoteProcess_LoadLibraryW'{$ELSE}'BoxedAppSDK_RemoteProcess_LoadLibraryA'{$ENDIF};
function BoxedAppSDK_RemoteProcess_LoadLibraryA; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_RemoteProcess_LoadLibraryA';
function BoxedAppSDK_RemoteProcess_LoadLibraryW; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_RemoteProcess_LoadLibraryW';

function BoxedAppSDK_EnumVirtualRegKeys; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name {$IFDEF UNICODE}'BoxedAppSDK_EnumVirtualRegKeysW'{$ELSE}'BoxedAppSDK_EnumVirtualRegKeysA'{$ENDIF};
function BoxedAppSDK_EnumVirtualRegKeysA; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_EnumVirtualRegKeysA';
function BoxedAppSDK_EnumVirtualRegKeysW; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_EnumVirtualRegKeysW';

function BoxedAppSDK_SharedMem_CreateStreamOnSharedMem; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF};

function BoxedAppSDK_IsAttachedProcessId; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_IsAttachedProcessId';

function BoxedAppSDK_AddStubCandidate; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name {$IFDEF UNICODE}'BoxedAppSDK_AddStubCandidateW'{$ELSE}'BoxedAppSDK_AddStubCandidateA'{$ENDIF};
function BoxedAppSDK_AddStubCandidateA; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_AddStubCandidateA';
function BoxedAppSDK_AddStubCandidateW; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_AddStubCandidateW';

function BoxedAppSDK_RemoveStubCandidate; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name {$IFDEF UNICODE}'BoxedAppSDK_RemoveStubCandidateW'{$ELSE}'BoxedAppSDK_RemoveStubCandidateA'{$ENDIF};
function BoxedAppSDK_RemoveStubCandidateA; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_RemoveStubCandidateA';
function BoxedAppSDK_RemoveStubCandidateW; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_RemoveStubCandidateW';

function BoxedAppSDK_SetBxSdkRawData; external {$IFNDEF WIN64} 'bxsdk32.dll' {$ELSE} 'bxsdk64.dll' {$ENDIF} name 'BoxedAppSDK_SetBxSdkRawData';
//---------------------------------------------------------------------------------------------
{$ELSE}
//---------------------------------------------------------------------------------------------
//Static linked
//type list
{$IFNDEF WIN64}
type NativeUInt = UInt;
type Size_t = UInt;
type PNativeUInt = ^NativeUInt;
type Int64 = Integer;
{$ENDIF}
type
  TBoxedAppSDK_Init = function : BOOL; stdcall;
  TBoxedAppSDK_Exit = function : BOOL; stdcall;
  TBoxedAppSDK_HookFunction = function (pFunction: Pointer; pHook: Pointer; bEnable: BOOL): THandle; stdcall;
  TBoxedAppSDK_EnableDebugLog = procedure (bEnable: BOOL); stdcall;
  TBoxedAppSDK_SetLogFileA = procedure (szLogFilePath: PAnsiChar); stdcall;
  TBoxedAppSDK_SetLogFileW = procedure (szLogFilePath: PWideChar); stdcall;

  TBoxedAppSDK_CreateVirtualFileA = function (
           lpFileName: PAnsiChar;
           dwDesiredAccess, dwShareMode: Integer;
           lpSecurityAttributes: PSecurityAttributes;
           dwCreationDisposition, dwFlagsAndAttributes: DWORD;
           hTemplateFile: THandle): THandle; stdcall;

  TBoxedAppSDK_CreateVirtualFileW = function (
           lpFileName: PWideChar;
           dwDesiredAccess, dwShareMode: Integer;
           lpSecurityAttributes: PSecurityAttributes;
           dwCreationDisposition, dwFlagsAndAttributes: DWORD;
           hTemplateFile: THandle): THandle; stdcall;

  TBoxedAppSDK_CreateVirtualDirectoryA = function (
           lpPathName: PAnsiChar;
           lpSecurityAttributes: PSecurityAttributes): BOOL; stdcall;

  TBoxedAppSDK_CreateVirtualDirectoryW = function (
           lpPathName: PWideChar;
           lpSecurityAttributes: PSecurityAttributes): BOOL; stdcall;

  TBoxedAppSDK_CreateVirtualFileBasedOnIStreamA = function (
           lpFileName: PAnsiChar;
           dwDesiredAccess, dwShareMode: Integer;
           lpSecurityAttributes: PSecurityAttributes;
           dwCreationDisposition, dwFlagsAndAttributes: DWORD;
           hTemplateFile: THandle;
           pStream: IStream): THandle; stdcall;

  TBoxedAppSDK_CreateVirtualFileBasedOnIStreamW = function (
           lpFileName: PWideChar;
           dwDesiredAccess, dwShareMode: Integer;
           lpSecurityAttributes: PSecurityAttributes;
           dwCreationDisposition, dwFlagsAndAttributes: DWORD;
           hTemplateFile: THandle;
           pStream: IStream): THandle; stdcall;

  TBoxedAppSDK_CreateVirtualFileBasedOnBufferA = function (
           lpFileName: PAnsiChar;
           dwDesiredAccess, dwShareMode: Integer;
           lpSecurityAttributes: PSecurityAttributes;
           dwCreationDisposition, dwFlagsAndAttributes: DWORD;
           hTemplateFile: THandle;
           pData: Pointer;
           dwSize: DWORD): THandle; stdcall;
  TBoxedAppSDK_CreateVirtualFileBasedOnBufferW = function (
           lpFileName: PWideChar;
           dwDesiredAccess, dwShareMode: Integer;
           lpSecurityAttributes: PSecurityAttributes;
           dwCreationDisposition, dwFlagsAndAttributes: DWORD;
           hTemplateFile: THandle;
           pData: Pointer;
           dwSize: DWORD): THandle; stdcall;
TBoxedAppSDK_IsVirtualFileA = function (szPath: PAnsiChar): BOOL; stdcall;
TBoxedAppSDK_IsVirtualFileW = function (szPath: PWideChar): BOOL; stdcall;
TBoxedAppSDK_CreateVirtualRegKeyA = function (
         hKey: HKEY;
         lpSubKey: PAnsiChar;
         Reserved: DWORD;
         lpClass: PAnsiChar;
         dwOptions: DWORD;
         samDesired: REGSAM;
         lpSecurityAttributes: PSecurityAttributes;
         var phkResult: HKEY;
         lpdwDisposition: PDWORD): Longint; stdcall;
TBoxedAppSDK_CreateVirtualRegKeyW = function (
         hKey: HKEY;
         lpSubKey: PWideChar;
         Reserved: DWORD;
         lpClass: PWideChar;
         dwOptions: DWORD;
         samDesired: REGSAM;
         lpSecurityAttributes: PSecurityAttributes;
         var phkResult: HKEY;
         lpdwDisposition: PDWORD): Longint; stdcall;
TBoxedAppSDK_RegisterCOMLibraryInVirtualRegistryA = function (szPath: PAnsiChar): Longint; stdcall;
TBoxedAppSDK_RegisterCOMLibraryInVirtualRegistryW = function (szPath: PWideChar): Longint; stdcall;
TBoxedAppSDK_RegisterCOMServerInVirtualRegistryA = function (szCommandLine: PAnsiChar): Longint; stdcall;
TBoxedAppSDK_RegisterCOMServerInVirtualRegistryW = function (szCommandLine: PWideChar): Longint; stdcall;
TBoxedAppSDK_SetContext = function (szContext: PAnsiChar): Longint; stdcall;
TBoxedAppSDK_AddHandler = function (pHandler: TBoxedAppHandler; Param: Pointer): DWORD; stdcall;
TBoxedAppSDK_RemoveHandler = function (dwHandlerId: DWORD): DWORD; stdcall;
TBoxedAppSDK_Alloc = function (dwSize: DWORD): Pointer; stdcall;
TBoxedAppSDK_Free = function (pData: Pointer): DWORD; stdcall;
TBoxedAppSDK_SharedMem_Alloc = function (dwSize: DWORD): BOXEDAPP_SHARED_PTR; stdcall;
TBoxedAppSDK_SharedMem_Free = procedure (shared_ptr: BOXEDAPP_SHARED_PTR); stdcall;
TBoxedAppSDK_SharedMem_Lock = function (shared_ptr: DWORD): Pointer; stdcall;
TBoxedAppSDK_SharedMem_Unlock = function (shared_ptr: DWORD): BOOL; stdcall;
TBoxedAppSDK_EnableOption = procedure (dwOptionIndex: DWORD; bEnable: BOOL); stdcall;
TBoxedAppSDK_IsOptionEnabled = function (dwOptionIndex: DWORD): BOOL; stdcall;
TBoxedAppSDK_RemoteProcess_EnableOption = procedure (dwProcessId: DWORD; dwOptionIndex: DWORD; bEnable: BOOL); stdcall;
TBoxedAppSDK_RemoteProcess_IsOptionEnabled = function (dwProcessId: DWORD; dwOptionIndex: DWORD): BOOL; stdcall;
TBoxedAppSDK_SetStartupFlags = procedure (dwFlags: DWORD); stdcall;

TBoxedAppSDK_DeleteFileFromVirtualFileSystemA = function (szPath: PAnsiChar): Longint; stdcall;
TBoxedAppSDK_DeleteFileFromVirtualFileSystemW = function (szPath: PWideChar): Longint; stdcall;

TBoxedAppSDK_CreateProcessFromMemoryA = function (
	pBuffer: Pointer;
	dwSize: DWORD;

	lpApplicationName: PAnsiChar;
	lpCommandLine: PAnsiChar;
	lpProcessAttributes, lpThreadAttributes: PSecurityAttributes;
	bInheritHandles: BOOL;
	dwCreationFlags: DWORD;
	lpEnvironment: Pointer;
	lpCurrentDirectory: PAnsiChar;
	const lpStartupInfo: TStartupInfo;
	var lpProcessInformation: TProcessInformation): BOOL; stdcall;
TBoxedAppSDK_CreateProcessFromMemoryW = function (
	pBuffer: Pointer;
	dwSize: DWORD;

	lpApplicationName: PWideChar;
	lpCommandLine: PWideChar;
	lpProcessAttributes, lpThreadAttributes: PSecurityAttributes;
	bInheritHandles: BOOL;
	dwCreationFlags: DWORD;
	lpEnvironment: Pointer;
	lpCurrentDirectory: PWideChar;
	const lpStartupInfo: TStartupInfo;
	var lpProcessInformation: TProcessInformation): BOOL; stdcall;
TBoxedAppSDK_AttachToProcess = function (hProcess: THandle): BOOL; stdcall;
TBoxedAppSDK_DetachFromProcess = function (hProcess: THandle): BOOL; stdcall;
TBoxedAppSDK_GetInternalValue = function (nValueId: DWORD; buf: Pointer; dwSize: DWORD): DWORD; stdcall;

TBoxedAppSDK_ExecuteDotNetApplicationA = function (szPath: PAnsiChar; szArgs: PAnsiChar): DWORD; stdcall;
TBoxedAppSDK_ExecuteDotNetApplicationW = function (szPath: PWideChar; szArgs: PWideChar): DWORD; stdcall;

TBoxedAppSDK_GetOriginalFunction = function (hHook: THandle): Pointer; stdcall;
TBoxedAppSDK_EnableHook = function (hHook: THandle; bEnable: BOOL): BOOL; stdcall;
TBoxedAppSDK_UnhookFunction = function (hHook: THandle): BOOL; stdcall;

TBoxedAppSDK_RemoteProcess_LoadLibraryA = function (dwProcessId: DWORD; szPath: PAnsiChar): HMODULE; stdcall;
TBoxedAppSDK_RemoteProcess_LoadLibraryW = function (dwProcessId: DWORD; szPath: PWideChar): HMODULE; stdcall;

TBoxedAppSDK_EnumVirtualRegKeysA = function (pEnumFunc: TBoxedAppSDK_EnumVirtualRegKeysCallbackA; lParam: Cardinal): Boolean; stdcall;
TBoxedAppSDK_EnumVirtualRegKeysW = function (pEnumFunc: TBoxedAppSDK_EnumVirtualRegKeysCallbackW; lParam: Cardinal): Boolean; stdcall;
TBoxedAppSDK_SharedMem_CreateStreamOnSharedMem = function (var stm: IStream): HResult; stdcall;
TBoxedAppSDK_IsAttachedProcessId = function (dwProcessId: DWORD): BOOL; stdcall;

TBoxedAppSDK_AddStubCandidateA = function (lpStubPath: PAnsiChar): BOOL; stdcall;
TBoxedAppSDK_AddStubCandidateW = function (lpStubPath: PWideChar): BOOL; stdcall;

TBoxedAppSDK_RemoveStubCandidateA = function (lpStubPath: PAnsiChar): BOOL; stdcall;
TBoxedAppSDK_RemoveStubCandidateW = function (lpStubPath: PWideChar): BOOL; stdcall;

TBoxedAppSDK_SetBxSdkRawData = function (pData: Pointer; dwSize: DWORD): BOOL; stdcall;

var
  {$IFDEF WIN32}
  {$I 'BoxedAppSDK_DLL32_Content.inc'}
  {$ELSE}
    {$IFDEF WIN64}
      {$I 'BoxedAppSDK_DLL64_Content.inc'}
    {$ENDIF}
  {$ENDIF}
  hLib: Pointer;
  RealBoxedAppSDK_Init: TBoxedAppSDK_Init;
  RealBoxedAppSDK_Exit: TBoxedAppSDK_Exit;

  RealBoxedAppSDK_EnableDebugLog: TBoxedAppSDK_EnableDebugLog;
  RealBoxedAppSDK_SetLogFileA: TBoxedAppSDK_SetLogFileA;
  RealBoxedAppSDK_SetLogFileW: TBoxedAppSDK_SetLogFileW;
  RealBoxedAppSDK_CreateVirtualFileA: TBoxedAppSDK_CreateVirtualFileA;
  RealBoxedAppSDK_CreateVirtualFileW: TBoxedAppSDK_CreateVirtualFileW;
  RealBoxedAppSDK_CreateVirtualDirectoryA: TBoxedAppSDK_CreateVirtualDirectoryA;
  RealBoxedAppSDK_CreateVirtualDirectoryW: TBoxedAppSDK_CreateVirtualDirectoryW;
  RealBoxedAppSDK_CreateVirtualFileBasedOnIStreamA: TBoxedAppSDK_CreateVirtualFileBasedOnIStreamA;
  RealBoxedAppSDK_CreateVirtualFileBasedOnIStreamW: TBoxedAppSDK_CreateVirtualFileBasedOnIStreamW;
  RealBoxedAppSDK_CreateVirtualFileBasedOnBufferA: TBoxedAppSDK_CreateVirtualFileBasedOnBufferA;

  RealBoxedAppSDK_CreateVirtualFileBasedOnBufferW: TBoxedAppSDK_CreateVirtualFileBasedOnBufferW;
  RealBoxedAppSDK_IsVirtualFileA: TBoxedAppSDK_IsVirtualFileA;
  RealBoxedAppSDK_IsVirtualFileW: TBoxedAppSDK_IsVirtualFileW;
  RealBoxedAppSDK_CreateVirtualRegKeyA: TBoxedAppSDK_CreateVirtualRegKeyA;
  RealBoxedAppSDK_CreateVirtualRegKeyW: TBoxedAppSDK_CreateVirtualRegKeyW;
  RealBoxedAppSDK_RegisterCOMLibraryInVirtualRegistryA: TBoxedAppSDK_RegisterCOMLibraryInVirtualRegistryA;
  RealBoxedAppSDK_RegisterCOMLibraryInVirtualRegistryW: TBoxedAppSDK_RegisterCOMLibraryInVirtualRegistryW;
  RealBoxedAppSDK_RegisterCOMServerInVirtualRegistryA: TBoxedAppSDK_RegisterCOMServerInVirtualRegistryA;
  RealBoxedAppSDK_RegisterCOMServerInVirtualRegistryW: TBoxedAppSDK_RegisterCOMServerInVirtualRegistryW;
  RealBoxedAppSDK_SetContext: TBoxedAppSDK_SetContext;
  RealBoxedAppSDK_AddHandler: TBoxedAppSDK_AddHandler;
  RealBoxedAppSDK_RemoveHandler: TBoxedAppSDK_RemoveHandler;
  RealBoxedAppSDK_Alloc: TBoxedAppSDK_Alloc;
  RealBoxedAppSDK_Free: TBoxedAppSDK_Free;
  RealBoxedAppSDK_SharedMem_Alloc: TBoxedAppSDK_SharedMem_Alloc;
  RealBoxedAppSDK_SharedMem_Free: TBoxedAppSDK_SharedMem_Free;
  RealBoxedAppSDK_SharedMem_Lock: TBoxedAppSDK_SharedMem_Lock;
  RealBoxedAppSDK_SharedMem_Unlock: TBoxedAppSDK_SharedMem_Unlock;
  RealBoxedAppSDK_EnableOption: TBoxedAppSDK_EnableOption;
  RealBoxedAppSDK_IsOptionEnabled: TBoxedAppSDK_IsOptionEnabled;
  RealBoxedAppSDK_RemoteProcess_EnableOption: TBoxedAppSDK_RemoteProcess_EnableOption;
  RealBoxedAppSDK_RemoteProcess_IsOptionEnabled: TBoxedAppSDK_RemoteProcess_IsOptionEnabled;
  RealBoxedAppSDK_SetStartupFlags: TBoxedAppSDK_SetStartupFlags;
  RealBoxedAppSDK_DeleteFileFromVirtualFileSystemA: TBoxedAppSDK_DeleteFileFromVirtualFileSystemA;
  RealBoxedAppSDK_DeleteFileFromVirtualFileSystemW: TBoxedAppSDK_DeleteFileFromVirtualFileSystemW;
  RealBoxedAppSDK_CreateProcessFromMemoryA: TBoxedAppSDK_CreateProcessFromMemoryA;
  RealBoxedAppSDK_CreateProcessFromMemoryW: TBoxedAppSDK_CreateProcessFromMemoryW;
  RealBoxedAppSDK_AttachToProcess: TBoxedAppSDK_AttachToProcess;
  RealBoxedAppSDK_DetachFromProcess: TBoxedAppSDK_DetachFromProcess;
  RealBoxedAppSDK_GetInternalValue: TBoxedAppSDK_GetInternalValue;
  RealBoxedAppSDK_ExecuteDotNetApplicationA: TBoxedAppSDK_ExecuteDotNetApplicationA;
  RealBoxedAppSDK_ExecuteDotNetApplicationW: TBoxedAppSDK_ExecuteDotNetApplicationW;
  RealBoxedAppSDK_HookFunction: TBoxedAppSDK_HookFunction;
  RealBoxedAppSDK_GetOriginalFunction: TBoxedAppSDK_GetOriginalFunction;
  RealBoxedAppSDK_EnableHook: TBoxedAppSDK_EnableHook;
  RealBoxedAppSDK_UnhookFunction: TBoxedAppSDK_UnhookFunction;
  RealBoxedAppSDK_RemoteProcess_LoadLibraryA: TBoxedAppSDK_RemoteProcess_LoadLibraryA;
  RealBoxedAppSDK_RemoteProcess_LoadLibraryW: TBoxedAppSDK_RemoteProcess_LoadLibraryW;
  RealBoxedAppSDK_EnumVirtualRegKeysA: TBoxedAppSDK_EnumVirtualRegKeysA;
  RealBoxedAppSDK_EnumVirtualRegKeysW: TBoxedAppSDK_EnumVirtualRegKeysW;
  RealBoxedAppSDK_SharedMem_CreateStreamOnSharedMem: TBoxedAppSDK_SharedMem_CreateStreamOnSharedMem;
  RealBoxedAppSDK_IsAttachedProcessId: TBoxedAppSDK_IsAttachedProcessId;
  RealBoxedAppSDK_AddStubCandidateA: TBoxedAppSDK_AddStubCandidateA;
  RealBoxedAppSDK_AddStubCandidateW: TBoxedAppSDK_AddStubCandidateW;
  RealBoxedAppSDK_RemoveStubCandidateA: TBoxedAppSDK_RemoveStubCandidateA;
  RealBoxedAppSDK_RemoveStubCandidateW: TBoxedAppSDK_RemoveStubCandidateW;
  RealBoxedAppSDK_SetBxSdkRawData: TBoxedAppSDK_SetBxSdkRawData;

//------------------------------------------------------------------------------
//Internal MemLoader functions
//------------------------------------------------------------------------------

// This structures only for x86
{$IFNDEF WIN64}
const
IMAGE_SIZEOF_SHORT_NAME            = 8;
IMAGE_NUMBEROF_DIRECTORY_ENTRIES   = 16;
IMAGE_ORDINAL_FLAG32               = $80000000;
 
type IMAGE_IMPORT_BY_NAME = packed record
     Hint : WORD;
     Name : packed array[0..0] of Char;
end;
type PIMAGE_IMPORT_BY_NAME = ^IMAGE_IMPORT_BY_NAME;

type IMAGE_IMPORT_DESCRIPTOR = packed record
   Characteristics: Cardinal;
   TimeDateStamp: Cardinal;
   ForwarderChain: Cardinal;
   Name: Cardinal;
   FirstThunk: Cardinal;
end;
type PIMAGE_IMPORT_DESCRIPTOR = ^IMAGE_IMPORT_DESCRIPTOR;

type IMAGE_DATA_DIRECTORY = packed record
    VirtualAddress  : DWORD;
    Size            : DWORD;
end;

type IMAGE_EXPORT_DIRECTORY = packed record
      Characteristics: DWord;
      TimeDateStamp: DWord;
      MajorVersion: Word;
      MinorVersion: Word;
      Name: DWord;
      Base: DWord;

      NumberOfFunctions: DWord;
      NumberOfNames: DWord;
      AddressOfFunctions: DWord;
      AddressOfNames: DWord;
      AddressOfNameOrdinals: DWord;
end;

type TISHMisc = packed record
case Integer of 
0: (PhysicalAddress: DWORD);
1: (VirtualSize: DWORD);
end;

type IMAGE_SECTION_HEADER = packed record
    Name     : packed array [0..IMAGE_SIZEOF_SHORT_NAME-1] of Byte;
    Misc     : TISHMisc ;//PhysicalAddress : DWORD; // or VirtualSize (union);
    VirtualAddress  : DWORD;
    SizeOfRawData   : DWORD;
    PointerToRawData : DWORD;
    PointerToRelocations : DWORD;
    PointerToLinenumbers : DWORD;
    NumberOfRelocations : WORD;
    NumberOfLinenumbers : WORD;
    Characteristics : DWORD;
  end;  

  IMAGE_OPTIONAL_HEADER = packed record
   { Standard fields. }
    Magic           : WORD;
    MajorLinkerVersion : Byte;
    MinorLinkerVersion : Byte;
    SizeOfCode      : DWORD;
    SizeOfInitializedData : DWORD;
    SizeOfUninitializedData : DWORD;
    AddressOfEntryPoint : DWORD;
    BaseOfCode      : DWORD;
    BaseOfData      : DWORD;
   { NT additional fields. }
    ImageBase       : DWORD;
    SectionAlignment : DWORD;
    FileAlignment   : DWORD;
    MajorOperatingSystemVersion : WORD;
    MinorOperatingSystemVersion : WORD;
    MajorImageVersion : WORD;
    MinorImageVersion : WORD;
    MajorSubsystemVersion : WORD;
    MinorSubsystemVersion : WORD;
    Reserved1       : DWORD;
    SizeOfImage     : DWORD;
    SizeOfHeaders   : DWORD;
    CheckSum        : DWORD;
    Subsystem       : WORD;
    DllCharacteristics : WORD;
    SizeOfStackReserve : DWORD;
    SizeOfStackCommit : DWORD;
    SizeOfHeapReserve : DWORD;
    SizeOfHeapCommit : DWORD;
    LoaderFlags     : DWORD;
    NumberOfRvaAndSizes : DWORD;
    DataDirectory: packed array[0..IMAGE_NUMBEROF_DIRECTORY_ENTRIES-1] of
		IMAGE_DATA_DIRECTORY;
  end;  

IMAGE_FILE_HEADER = packed record
    Machine              : WORD;
    NumberOfSections     : WORD;
    TimeDateStamp        : DWORD;
    PointerToSymbolTable : DWORD;
    NumberOfSymbols      : DWORD;
    SizeOfOptionalHeader : WORD;
    Characteristics      : WORD;
  end;
  
IMAGE_NT_HEADERS = packed record
  Signature       : DWORD;
  FileHeader      : IMAGE_FILE_HEADER;
  OptionalHeader  : IMAGE_OPTIONAL_HEADER;
end;
{$ENDIF}
type PIMAGE_NT_HEADERS = ^IMAGE_NT_HEADERS;
type PIMAGE_FILE_HEADER = ^IMAGE_FILE_HEADER;
type PIMAGE_OPTIONAL_HEADER = ^IMAGE_OPTIONAL_HEADER;
type PIMAGE_SECTION_HEADER = ^IMAGE_SECTION_HEADER;
type PIMAGE_DATA_DIRECTORY = ^IMAGE_DATA_DIRECTORY;

type
  TDWORDArray = array[0..9999999] of Cardinal;
type
  TWORDArray = array[0..99999999] of WORD;
type PWORDArray = ^TWORDArray;
type PDWORDArray = ^TDWORDArray;

type IMAGE_DOS_HEADER = packed record     // DOS .EXE header
    e_magic: WORD;                     // Magic number
    e_cblp: WORD;                      // Bytes on last page of file
    e_cp: WORD;                        // Pages in file
    e_crlc: WORD;                      // Relocations
    e_cparhdr: WORD;                   // Size of header in paragraphs
    e_minalloc: WORD;                  // Minimum extra paragraphs needed
    e_maxalloc: WORD;                  // Maximum extra paragraphs needed
    e_ss: WORD;                        // Initial (relative) SS value
    e_sp: WORD;                        // Initial SP value
    e_csum: WORD;                      // Checksum
    e_ip: WORD;                        // Initial IP value
    e_cs: WORD;                        // Initial (relative) CS value
    e_lfarlc: WORD;                    // File address of relocation table
    e_ovno: WORD;                      // Overlay number
    e_res: array[0..3] of WORD;        // Reserved words
    e_oemid: WORD;                     // OEM identifier (for e_oeminfo)
    e_oeminfo: WORD;                   // OEM information; e_oemid specific
    e_res2: array[0..9] of WORD;       // Reserved words
    e_lfanew: Cardinal;                // File address of new exe header
end;
type
  PIMAGE_DOS_HEADER = ^IMAGE_DOS_HEADER;

type
IMAGE_BASE_RELOCATION  = packed record
    VirtualAddress: Cardinal;
    SizeOfBlock: Cardinal;
//  WORD    TypeOffset[1];
end;
type
  PIMAGE_BASE_RELOCATION = ^IMAGE_BASE_RELOCATION;
type
  PIMAGE_EXPORT_DIRECTORY = ^IMAGE_EXPORT_DIRECTORY;

type
  DLLMAIN = function(hinstDLL: Pointer; fdwReason: Cardinal; lpvReserved: Pointer): Integer; stdcall;
type
  PDLLMAIN = ^DLLMAIN;

//---------------------------------------------------------------------------
//Internal_CopyMemory
//---------------------------------------------------------------------------
type
  TMemCpy = procedure(Destination: Pointer; Source: Pointer; Count: NativeUInt);cdecl;
type
  PMemCpy = ^TMemCpy;
procedure Internal_CopyMemory(Destination: Pointer; Source: Pointer; Count: NativeUInt); //was UInt64
var
  MemCpy: TMemCpy;
begin
    MemCpy := nil;
    //typedef void (__cdecl *P_memcpy)(LPVOID Destination, LPCVOID Source, SIZE_T Count);
    //static P_memcpy pmemcpy = NULL;
    if (nil = @MemCpy) then
    begin
        MemCpy := TMemCpy(GetProcAddress(GetModuleHandleA('ntdll.dll'), 'memcpy'));
    end;

    MemCpy(Destination, Source, Count);
end;
//---------------------------------------------------------------------------
//Internal_ZeroMemory
//---------------------------------------------------------------------------
type
  TZeroMem = procedure(What: Pointer; Count: NativeUInt);stdcall;
procedure Internal_ZeroMemory(What: Pointer; Count: NativeUInt); //was UInt64
var
  ZeroMem: TZeroMem;
begin
    ZeroMem := nil;
    if (nil = @ZeroMem) then
        ZeroMem := TZeroMem(GetProcAddress(GetModuleHandleA('kernel32.dll'), 'RtlZeroMemory'));

    ZeroMem(What, Count);
end;

{$IFDEF WIN64}
function AddToPointer(source: Pointer;value: Cardinal) : Pointer;overload;
begin
  Result := Pointer(NativeUInt(source) + NativeUInt(value));//Int64
end;
{$ENDIF}

function AddToPointer(source: Pointer;value: NativeUInt) : Pointer;{$IFDEF WIN64}overload;{$ENDIF}
begin
  Result := Pointer(NativeUInt(source) + value);
end;

function DecPointer(source: Pointer;value: Pointer) : NativeUInt;
begin
  Result := NativeUInt(source) - NativeUInt(value);
end;

function DecPointerInt(source: Pointer;value: NativeUInt) : NativeUInt;
begin
  Result := NativeUInt(source) - NativeUInt(value);
end;

function min(a: Integer; b: Integer): Integer;
begin
  if (a<b) then
    Result := a
  else
    Result := b;
end;

//------------------------------------------------------------------------------
//Internal_Load
//------------------------------------------------------------------------------
function Internal_Load(pData: Pointer) : Pointer;
var
  pPtr: Pointer;
  pImageNTHeaders: PIMAGE_NT_HEADERS;
  intSectionIndex: Integer;
  intImageBaseDelta: Size_t;
  intRelocationInfoSize: UInt;
  pImageBaseRelocations,pReloc: PIMAGE_BASE_RELOCATION;
  pImports,pImport: PIMAGE_IMPORT_DESCRIPTOR;
  pDllMain: DLLMAIN;
  pImageBase: Pointer;

  pImageSectionHeader: PIMAGE_SECTION_HEADER;
  intVirtualSectionSize: Integer;
  intRawSectionSize: Integer;
  pSectionBase: Pointer;

  intRelocCount: Integer;
  pwRelocInfo: PWORD;
  intRelocIndex: Integer;

  magic: PNativeUInt;//rename

  lpszLibName: LPSTR;
  hLib: HMODULE;
  lpPRVA_Import: PNativeUInt;//UInt, not PNativeUInt!
  lpszFunctionName: LPSTR;
begin

  pPtr := pData;

  pPtr := Pointer(Int64(pPtr) + Int64(PIMAGE_DOS_HEADER(pPtr).e_lfanew));
  pImageNTHeaders := PIMAGE_NT_HEADERS(pPtr);

  // Alloc memory for library
  pImageBase := VirtualAlloc(nil, pImageNTHeaders^.OptionalHeader.SizeOfImage, MEM_COMMIT, PAGE_EXECUTE_READWRITE);

  // Copy headers
  Internal_CopyMemory(pImageBase, pData, pImageNTHeaders^.OptionalHeader.SizeOfHeaders);

  // Set pPtr to section table
  pPtr := AddToPointer(pPtr,sizeof(pImageNTHeaders.Signature) + sizeof(pImageNTHeaders.FileHeader) + pImageNTHeaders.FileHeader.SizeOfOptionalHeader);

  for intSectionIndex := 0 to pImageNTHeaders.FileHeader.NumberOfSections-1 do
  begin
    pImageSectionHeader := PIMAGE_SECTION_HEADER(AddToPointer(pPtr,intSectionIndex*sizeof(IMAGE_SECTION_HEADER)));

    //
    intVirtualSectionSize := pImageSectionHeader.Misc.VirtualSize;  //PhysicalAddress new code
    //
    intRawSectionSize := pImageSectionHeader.SizeOfRawData;

    pSectionBase := AddToPointer(pImageBase,pImageSectionHeader.VirtualAddress);

    Internal_ZeroMemory(pSectionBase, intVirtualSectionSize);

    Internal_CopyMemory(pSectionBase,
                        AddToPointer(pData,pImageSectionHeader.PointerToRawData),
                        // Sometimes 0 == intRawSectionSize, for example, when the section has uninitialized data
                        min(intVirtualSectionSize, intRawSectionSize));
  end;
  // Relocations

  // Difference between bases
  intImageBaseDelta := DecPointerInt(pImageBase,pImageNTHeaders.OptionalHeader.ImageBase);

  intRelocationInfoSize :=
        pImageNTHeaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size;

    pImageBaseRelocations :=
        PIMAGE_BASE_RELOCATION(AddToPointer(pImageBase,
                                pImageNTHeaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress));

    pReloc := pImageBaseRelocations;

    while DecPointer(pReloc,pImageBaseRelocations) < intRelocationInfoSize do
    begin
        // Number of relocs into current block
        intRelocCount := (pReloc.SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) Div sizeof(WORD);

        pwRelocInfo := PWORD(AddToPointer(pReloc,sizeof(IMAGE_BASE_RELOCATION)));

        for intRelocIndex := 0 to intRelocCount-1 do
        begin
            if (pwRelocInfo^ and $f000) <> 0 then
            begin
              magic := PNativeUInt(AddToPointer(pImageBase,pReloc.VirtualAddress+(pwRelocInfo^ and $0fff)));
              magic^ := NativeUInt(magic^ + intImageBaseDelta);
              //*(char* *)((char*)pImageBase + pReloc->VirtualAddress + (pwRelocInfo^ and $0fff)) += intImageBaseDelta;
            end;

            Inc(pwRelocInfo);
        end;

        pReloc := PIMAGE_BASE_RELOCATION(pwRelocInfo);
    end;

    // Import table
    pImports :=
    PIMAGE_IMPORT_DESCRIPTOR(AddToPointer(pImageBase,
                            pImageNTHeaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress));

    pImport := pImports;

    while 0 <> pImport.Name do
    begin
        // DLL Name
        lpszLibName := LPSTR(AddToPointer(pImageBase,pImport.Name));

        // Load library
        hLib := LoadLibraryA(lpszLibName);

        if 0 = pImport.TimeDateStamp then
          lpPRVA_Import := AddToPointer(pImageBase,pImport.FirstThunk)
        else
          lpPRVA_Import := AddToPointer(pImageBase,pImport.Characteristics);  //new code

        while lpPRVA_Import^ <> 0 do
        begin
            // Get function name

            if (PDWORD(lpPRVA_Import)^ and IMAGE_ORDINAL_FLAG32) <> 0 then
                // Importing by number (ordinal)
                // Ordinal is in the loword
                lpszFunctionName := LPSTR(PDWORD(lpPRVA_Import)^ and $ffff)
            else
                // Importing by name
                lpszFunctionName := LPSTR(@PIMAGE_IMPORT_BY_NAME(AddToPointer(pImageBase,PUInt(lpPRVA_Import)^)).Name[0]);

            // Get function address
            lpPRVA_Import^ := NativeUInt(GetProcAddress(hLib, lpszFunctionName));

            Inc(lpPRVA_Import);
        end;
        Inc(pImport);
    end;

    FlushInstructionCache(GetCurrentProcess(), pImageBase, pImageNTHeaders.OptionalHeader.SizeOfImage);
    if 0 <> pImageNTHeaders.OptionalHeader.AddressOfEntryPoint then
    begin
        // Entry point
        pDllMain := DLLMAIN(AddToPointer(pImageBase,pImageNTHeaders.OptionalHeader.AddressOfEntryPoint));

        if nil <> @pDllMain then
        begin
            pDllMain(Pointer(pImageBase), DLL_PROCESS_ATTACH, nil);
            pDllMain(Pointer(pImageBase), DLL_THREAD_ATTACH, nil);
        end;
    end;
    Result := Pointer(pImageBase);
end;

//------------------------------------------------------------------------------
//Internal_GetProcAddress
//------------------------------------------------------------------------------

function Internal_GetProcAddress(hModule: Pointer; lpProcName: PAnsiChar) : Pointer;
var
  pImageNTHeaders: PIMAGE_NT_HEADERS;
  pExports: PIMAGE_EXPORT_DIRECTORY;
  dwExportedSymbolIndex: Cardinal;
  pPtr: Pointer;
  dwVirtualAddressOfName: Cardinal;
  lpszName: PAnsiChar;
  wIndex: WORD;
  dwVirtualAddressOfAddressOfProc: Cardinal;
begin
  Result := nil;
  if nil <> hModule then
  begin
    pPtr := hModule;

    pPtr := Pointer(Int64(pPtr) + Int64(PIMAGE_DOS_HEADER(pPtr).e_lfanew));
    pImageNTHeaders := PIMAGE_NT_HEADERS(pPtr);

    // export table
    pExports := PIMAGE_EXPORT_DIRECTORY(AddToPointer(hModule,
                                                    pImageNTHeaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress));
    for dwExportedSymbolIndex := 0 to pExports.NumberOfNames-1 do
    begin
      // Cycle on exported by names
      dwVirtualAddressOfName := PDWORDArray(AddToPointer(hModule,pExports.AddressOfNames))[dwExportedSymbolIndex];
      lpszName := LPSTR(AddToPointer(hModule,dwVirtualAddressOfName));

      if lstrcmpA(lpszName, lpProcName) = 0 then // Function found!
      begin
        // Index
        wIndex :=
            PWORDArray(AddToPointer(hModule,pExports.AddressOfNameOrdinals))[dwExportedSymbolIndex];//new code

        dwVirtualAddressOfAddressOfProc :=
            PDWORDArray(AddToPointer(hModule,pExports.AddressOfFunctions))[wIndex];

        Result := AddToPointer(hModule,dwVirtualAddressOfAddressOfProc);
      end;
    end;
  end
end;
//------------------------------------------------------------------------------
//Internal_Unload
//------------------------------------------------------------------------------
procedure Internal_Unload(hModule: Pointer);
var
pImageBase: Pointer;
pPtr: Pointer;
pImageNTHeaders: PIMAGE_NT_HEADERS;
pDllMain: DLLMAIN;
begin
    if nil <> hModule then
    begin
      pImageBase := hModule;

      pPtr := Pointer(hModule);
      pPtr := Pointer(Int64(pPtr) + Int64(PIMAGE_DOS_HEADER(pPtr).e_lfanew));

      pImageNTHeaders := PIMAGE_NT_HEADERS(pPtr);

      pDllMain := DLLMAIN(AddToPointer(pImageBase,pImageNTHeaders.OptionalHeader.AddressOfEntryPoint));

      if nil <> @pDllMain then
      begin
          pDllMain(pImageBase, DLL_THREAD_DETACH, nil);
          pDllMain(pImageBase, DLL_PROCESS_DETACH, nil);
      end;
      VirtualFree(hModule, 0, MEM_RELEASE);
    end;
end;

//------------------------------------------------------------------------------
//Functions from bxsdk32.dll / bxsdk64.dll
//------------------------------------------------------------------------------

function BoxedAppSDK_LoadDLL: BOOL;
begin
  if hLib = nil then
  begin
    hLib := Internal_Load(Pointer(@dll[0]));

    if hLib = nil then
    begin
      //raise Exception.Create('An error occured during Internal_Load call!');
      Result := FALSE;
      exit;
    end;

    @RealBoxedAppSDK_Init := Internal_GetProcAddress(hLib, 'BoxedAppSDK_Init');
    @RealBoxedAppSDK_Exit := Internal_GetProcAddress(hLib, 'BoxedAppSDK_Exit');

    @RealBoxedAppSDK_EnableDebugLog := Internal_GetProcAddress(hLib, 'BoxedAppSDK_EnableDebugLog');
    @RealBoxedAppSDK_SetLogFileA := Internal_GetProcAddress(hLib, 'BoxedAppSDK_SetLogFileA');
    @RealBoxedAppSDK_SetLogFileW := Internal_GetProcAddress(hLib, 'BoxedAppSDK_SetLogFileW');
    @RealBoxedAppSDK_CreateVirtualFileA := Internal_GetProcAddress(hLib, 'BoxedAppSDK_CreateVirtualFileA');
    @RealBoxedAppSDK_CreateVirtualFileW := Internal_GetProcAddress(hLib, 'BoxedAppSDK_CreateVirtualFileW');
    @RealBoxedAppSDK_CreateVirtualDirectoryA := Internal_GetProcAddress(hLib, 'BoxedAppSDK_CreateVirtualDirectoryA');
    @RealBoxedAppSDK_CreateVirtualDirectoryW := Internal_GetProcAddress(hLib, 'BoxedAppSDK_CreateVirtualDirectoryW');
    @RealBoxedAppSDK_CreateVirtualFileBasedOnIStreamA := Internal_GetProcAddress(hLib, 'BoxedAppSDK_CreateVirtualFileBasedOnIStreamA');
    @RealBoxedAppSDK_CreateVirtualFileBasedOnIStreamW := Internal_GetProcAddress(hLib, 'BoxedAppSDK_CreateVirtualFileBasedOnIStreamW');
    @RealBoxedAppSDK_CreateVirtualFileBasedOnBufferA := Internal_GetProcAddress(hLib, 'BoxedAppSDK_CreateVirtualFileBasedOnBufferA');

    @RealBoxedAppSDK_CreateVirtualFileBasedOnBufferW := Internal_GetProcAddress(hLib, 'BoxedAppSDK_CreateVirtualFileBasedOnBufferW');
    @RealBoxedAppSDK_IsVirtualFileA := Internal_GetProcAddress(hLib, 'BoxedAppSDK_IsVirtualFileA');
    @RealBoxedAppSDK_IsVirtualFileW := Internal_GetProcAddress(hLib, 'BoxedAppSDK_IsVirtualFileW');
    @RealBoxedAppSDK_CreateVirtualRegKeyA := Internal_GetProcAddress(hLib, 'BoxedAppSDK_CreateVirtualRegKeyA');
    @RealBoxedAppSDK_CreateVirtualRegKeyW := Internal_GetProcAddress(hLib, 'BoxedAppSDK_CreateVirtualRegKeyW');
    @RealBoxedAppSDK_RegisterCOMLibraryInVirtualRegistryA := Internal_GetProcAddress(hLib, 'BoxedAppSDK_RegisterCOMLibraryInVirtualRegistryA');
    @RealBoxedAppSDK_RegisterCOMLibraryInVirtualRegistryW := Internal_GetProcAddress(hLib, 'BoxedAppSDK_RegisterCOMLibraryInVirtualRegistryW');
    @RealBoxedAppSDK_RegisterCOMServerInVirtualRegistryA := Internal_GetProcAddress(hLib, 'BoxedAppSDK_RegisterCOMServerInVirtualRegistryA');
    @RealBoxedAppSDK_RegisterCOMServerInVirtualRegistryW := Internal_GetProcAddress(hLib, 'BoxedAppSDK_RegisterCOMServerInVirtualRegistryW');
    @RealBoxedAppSDK_SetContext := Internal_GetProcAddress(hLib, 'BoxedAppSDK_SetContext');
    @RealBoxedAppSDK_AddHandler := Internal_GetProcAddress(hLib, 'BoxedAppSDK_AddHandler');
    @RealBoxedAppSDK_RemoveHandler := Internal_GetProcAddress(hLib, 'BoxedAppSDK_RemoveHandler');
    @RealBoxedAppSDK_Alloc := Internal_GetProcAddress(hLib, 'BoxedAppSDK_Alloc');
    @RealBoxedAppSDK_Free := Internal_GetProcAddress(hLib, 'BoxedAppSDK_Free');
    @RealBoxedAppSDK_SharedMem_Alloc := Internal_GetProcAddress(hLib, 'BoxedAppSDK_SharedMem_Alloc');
    @RealBoxedAppSDK_SharedMem_Free := Internal_GetProcAddress(hLib, 'BoxedAppSDK_SharedMem_Free');
    @RealBoxedAppSDK_SharedMem_Lock := Internal_GetProcAddress(hLib, 'BoxedAppSDK_SharedMem_Lock');
    @RealBoxedAppSDK_SharedMem_Unlock := Internal_GetProcAddress(hLib, 'BoxedAppSDK_SharedMem_Unlock');
    @RealBoxedAppSDK_EnableOption := Internal_GetProcAddress(hLib, 'BoxedAppSDK_EnableOption');
    @RealBoxedAppSDK_IsOptionEnabled := Internal_GetProcAddress(hLib, 'BoxedAppSDK_IsOptionEnabled');
    @RealBoxedAppSDK_RemoteProcess_EnableOption := Internal_GetProcAddress(hLib, 'BoxedAppSDK_RemoteProcess_EnableOption');
    @RealBoxedAppSDK_RemoteProcess_IsOptionEnabled := Internal_GetProcAddress(hLib, 'BoxedAppSDK_RemoteProcess_IsOptionEnabled');
    @RealBoxedAppSDK_SetStartupFlags := Internal_GetProcAddress(hLib, 'BoxedAppSDK_SetStartupFlags');
    @RealBoxedAppSDK_DeleteFileFromVirtualFileSystemA := Internal_GetProcAddress(hLib, 'BoxedAppSDK_DeleteFileFromVirtualFileSystemA');
    @RealBoxedAppSDK_DeleteFileFromVirtualFileSystemW := Internal_GetProcAddress(hLib, 'BoxedAppSDK_DeleteFileFromVirtualFileSystemW');
    @RealBoxedAppSDK_CreateProcessFromMemoryA := Internal_GetProcAddress(hLib, 'BoxedAppSDK_CreateProcessFromMemoryA');
    @RealBoxedAppSDK_CreateProcessFromMemoryW := Internal_GetProcAddress(hLib, 'BoxedAppSDK_CreateProcessFromMemoryW');
    @RealBoxedAppSDK_AttachToProcess := Internal_GetProcAddress(hLib, 'BoxedAppSDK_AttachToProcess');
    @RealBoxedAppSDK_DetachFromProcess := Internal_GetProcAddress(hLib, 'BoxedAppSDK_DetachFromProcess');
    @RealBoxedAppSDK_GetInternalValue := Internal_GetProcAddress(hLib, 'BoxedAppSDK_GetInternalValue');
    @RealBoxedAppSDK_ExecuteDotNetApplicationA := Internal_GetProcAddress(hLib, 'BoxedAppSDK_ExecuteDotNetApplicationA');
    @RealBoxedAppSDK_ExecuteDotNetApplicationW := Internal_GetProcAddress(hLib, 'BoxedAppSDK_ExecuteDotNetApplicationW');
    @RealBoxedAppSDK_HookFunction := Internal_GetProcAddress(hLib, 'BoxedAppSDK_HookFunction');
    @RealBoxedAppSDK_GetOriginalFunction := Internal_GetProcAddress(hLib, 'BoxedAppSDK_GetOriginalFunction');
    @RealBoxedAppSDK_EnableHook := Internal_GetProcAddress(hLib, 'BoxedAppSDK_EnableHook');
    @RealBoxedAppSDK_UnhookFunction := Internal_GetProcAddress(hLib, 'BoxedAppSDK_UnhookFunction');
    @RealBoxedAppSDK_RemoteProcess_LoadLibraryA := Internal_GetProcAddress(hLib, 'BoxedAppSDK_RemoteProcess_LoadLibraryA');
    @RealBoxedAppSDK_RemoteProcess_LoadLibraryW := Internal_GetProcAddress(hLib, 'BoxedAppSDK_RemoteProcess_LoadLibraryW');
    @RealBoxedAppSDK_EnumVirtualRegKeysA := Internal_GetProcAddress(hLib, 'BoxedAppSDK_EnumVirtualRegKeysA');
    @RealBoxedAppSDK_EnumVirtualRegKeysW := Internal_GetProcAddress(hLib, 'BoxedAppSDK_EnumVirtualRegKeysW');
    @RealBoxedAppSDK_SharedMem_CreateStreamOnSharedMem := Internal_GetProcAddress(hLib, 'BoxedAppSDK_SharedMem_CreateStreamOnSharedMem');
    @RealBoxedAppSDK_IsAttachedProcessId := Internal_GetProcAddress(hLib, 'BoxedAppSDK_IsAttachedProcessId');
    @RealBoxedAppSDK_AddStubCandidateA := Internal_GetProcAddress(hLib, 'BoxedAppSDK_AddStubCandidateA');
    @RealBoxedAppSDK_AddStubCandidateW := Internal_GetProcAddress(hLib, 'BoxedAppSDK_AddStubCandidateW');
    @RealBoxedAppSDK_RemoveStubCandidateA := Internal_GetProcAddress(hLib, 'BoxedAppSDK_RemoveStubCandidateA');
    @RealBoxedAppSDK_RemoveStubCandidateW := Internal_GetProcAddress(hLib, 'BoxedAppSDK_RemoveStubCandidateW');
    @RealBoxedAppSDK_SetBxSdkRawData := Internal_GetProcAddress(hLib, 'BoxedAppSDK_SetBxSdkRawData');

    RealBoxedAppSDK_SetBxSdkRawData(Pointer(@dll[0]), sizeof(dll));
  end;

  Result := TRUE;
end;

procedure BoxedAppSDK_EnableDebugLog(bEnable: BOOL); stdcall
begin
  RealBoxedAppSDK_EnableDebugLog(bEnable);
end;

procedure BoxedAppSDK_SetLogFile(szLogFilePath: PChar); stdcall;
begin
  {$IFDEF UNICODE}
  RealBoxedAppSDK_SetLogFileW(szLogFilePath);
  {$ELSE}
  RealBoxedAppSDK_SetLogFileA(szLogFilePath);
  {$ENDIF}
end;

procedure BoxedAppSDK_SetLogFileA(szLogFilePath: PAnsiChar); stdcall;
begin
  RealBoxedAppSDK_SetLogFileA(szLogFilePath);
end;

procedure BoxedAppSDK_SetLogFileW(szLogFilePath: PWideChar); stdcall;
begin
  RealBoxedAppSDK_SetLogFileW(szLogFilePath);
end;

function BoxedAppSDK_CreateVirtualFile(
         lpFileName: PChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle): THandle; stdcall;
begin

  {$IFDEF UNICODE}
  Result := RealBoxedAppSDK_CreateVirtualFileW(lpFileName,dwDesiredAccess,dwShareMode,
                                              lpSecurityAttributes,dwCreationDisposition,
                                              dwFlagsAndAttributes,hTemplateFile);
  {$ELSE}
  Result := RealBoxedAppSDK_CreateVirtualFileA(lpFileName,dwDesiredAccess,dwShareMode,
                                              lpSecurityAttributes,dwCreationDisposition,
                                              dwFlagsAndAttributes,hTemplateFile);
  {$ENDIF}

end;

function BoxedAppSDK_CreateVirtualFileA(
         lpFileName: PAnsiChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle): THandle; stdcall;
begin
    Result := RealBoxedAppSDK_CreateVirtualFileA(lpFileName,dwDesiredAccess,dwShareMode,
                                              lpSecurityAttributes,dwCreationDisposition,
                                              dwFlagsAndAttributes,hTemplateFile);
end;

function BoxedAppSDK_CreateVirtualFileW(
         lpFileName: PWideChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle): THandle; stdcall;
begin
    Result := RealBoxedAppSDK_CreateVirtualFileW(lpFileName,dwDesiredAccess,dwShareMode,
                                              lpSecurityAttributes,dwCreationDisposition,
                                              dwFlagsAndAttributes,hTemplateFile);
end;

function BoxedAppSDK_CreateVirtualDirectory(
         lpPathName: PChar;
         lpSecurityAttributes: PSecurityAttributes): BOOL; stdcall;
begin
  {$IFDEF UNICODE}
    Result := RealBoxedAppSDK_CreateVirtualDirectoryW(lpPathName,lpSecurityAttributes);
  {$ELSE}
    Result := RealBoxedAppSDK_CreateVirtualDirectoryA(lpPathName,lpSecurityAttributes);
  {$ENDIF}

end;

function BoxedAppSDK_CreateVirtualDirectoryA(
         lpPathName: PAnsiChar;
         lpSecurityAttributes: PSecurityAttributes): BOOL; stdcall;
begin
    Result := RealBoxedAppSDK_CreateVirtualDirectoryA(lpPathName,lpSecurityAttributes);
end;

function BoxedAppSDK_CreateVirtualDirectoryW(
         lpPathName: PWideChar;
         lpSecurityAttributes: PSecurityAttributes): BOOL; stdcall;
begin
    Result := RealBoxedAppSDK_CreateVirtualDirectoryW(lpPathName,lpSecurityAttributes);
end;


function BoxedAppSDK_CreateVirtualFileBasedOnIStream(
         lpFileName: PChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle;
         pStream: IStream): THandle; stdcall;
begin
  {$IFDEF UNICODE}
  Result := RealBoxedAppSDK_CreateVirtualFileBasedOnIStreamW(lpFileName,dwDesiredAccess,
                  dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes,
                  hTemplateFile, pStream);
  {$ELSE}
  Result := RealBoxedAppSDK_CreateVirtualFileBasedOnIStreamA(lpFileName,dwDesiredAccess,
                  dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes,
                  hTemplateFile, pStream);
  {$ENDIF}

end;

function BoxedAppSDK_CreateVirtualFileBasedOnIStreamA(
         lpFileName: PAnsiChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle;
         pStream: IStream): THandle; stdcall;
begin
  Result := RealBoxedAppSDK_CreateVirtualFileBasedOnIStreamA(lpFileName,dwDesiredAccess,
                  dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes,
                  hTemplateFile, pStream);
end;

function BoxedAppSDK_CreateVirtualFileBasedOnIStreamW(
         lpFileName: PWideChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle;
         pStream: IStream): THandle; stdcall;
begin
    Result := RealBoxedAppSDK_CreateVirtualFileBasedOnIStreamW(lpFileName,dwDesiredAccess,
                  dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes,
                  hTemplateFile, pStream);
end;

function BoxedAppSDK_CreateVirtualFileBasedOnBuffer(
         lpFileName: PChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle;
         pData: Pointer;
         dwSize: DWORD): THandle; stdcall;
begin
  {$IFDEF UNICODE}
  Result := RealBoxedAppSDK_CreateVirtualFileBasedOnBufferW(lpFileName,
              dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition,
              dwFlagsAndAttributes, hTemplateFile, pData, dwSize);
  {$ELSE}
  Result := RealBoxedAppSDK_CreateVirtualFileBasedOnBufferA(lpFileName,
              dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition,
              dwFlagsAndAttributes, hTemplateFile, pData, dwSize);
  {$ENDIF}

end;

function BoxedAppSDK_CreateVirtualFileBasedOnBufferA(
         lpFileName: PAnsiChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle;
         pData: Pointer;
         dwSize: DWORD): THandle; stdcall;
begin
    Result := RealBoxedAppSDK_CreateVirtualFileBasedOnBufferA(lpFileName,
              dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition,
              dwFlagsAndAttributes, hTemplateFile, pData, dwSize);
end;

function BoxedAppSDK_CreateVirtualFileBasedOnBufferW(
         lpFileName: PWideChar;
         dwDesiredAccess, dwShareMode: Integer;
         lpSecurityAttributes: PSecurityAttributes;
         dwCreationDisposition, dwFlagsAndAttributes: DWORD;
         hTemplateFile: THandle;
         pData: Pointer;
         dwSize: DWORD): THandle; stdcall;
begin
    Result := RealBoxedAppSDK_CreateVirtualFileBasedOnBufferW(lpFileName,
              dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition,
              dwFlagsAndAttributes, hTemplateFile, pData, dwSize);
end;

function BoxedAppSDK_IsVirtualFile(szPath: PChar): BOOL; stdcall;
begin
  {$IFDEF UNICODE}
    Result := RealBoxedAppSDK_IsVirtualFileW(szPath);
  {$ELSE}
    Result := RealBoxedAppSDK_IsVirtualFileA(szPath);
  {$ENDIF}
end;

function BoxedAppSDK_IsVirtualFileA(szPath: PAnsiChar): BOOL; stdcall;
begin
  Result := RealBoxedAppSDK_IsVirtualFileA(szPath);
end;

function BoxedAppSDK_IsVirtualFileW(szPath: PWideChar): BOOL; stdcall;
begin
  Result := RealBoxedAppSDK_IsVirtualFileW(szPath);
end;

function BoxedAppSDK_CreateVirtualRegKey(
         hKey: HKEY;
         lpSubKey: PChar;
         Reserved: DWORD;
         lpClass: pChar;
         dwOptions: DWORD;
         samDesired: REGSAM;
         lpSecurityAttributes: PSecurityAttributes;
         var phkResult: HKEY;
         lpdwDisposition: PDWORD): Longint; stdcall;
begin
  {$IFDEF UNICODE}
  Result := RealBoxedAppSDK_CreateVirtualRegKeyW(hKey, lpSubKey,
              Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes,
              phkResult, lpdwDisposition);
  {$ELSE}
  Result := RealBoxedAppSDK_CreateVirtualRegKeyA(hKey, lpSubKey,
              Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes,
              phkResult, lpdwDisposition);
  {$ENDIF}

end;

function BoxedAppSDK_CreateVirtualRegKeyA(
         hKey: HKEY;
         lpSubKey: PAnsiChar;
         Reserved: DWORD;
         lpClass: PAnsiChar;
         dwOptions: DWORD;
         samDesired: REGSAM;
         lpSecurityAttributes: PSecurityAttributes;
         var phkResult: HKEY;
         lpdwDisposition: PDWORD): Longint; stdcall;
begin
  Result := RealBoxedAppSDK_CreateVirtualRegKeyA(hKey, lpSubKey,
              Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes,
              phkResult, lpdwDisposition);
end;

function BoxedAppSDK_CreateVirtualRegKeyW(
         hKey: HKEY;
         lpSubKey: PWideChar;
         Reserved: DWORD;
         lpClass: PWideChar;
         dwOptions: DWORD;
         samDesired: REGSAM;
         lpSecurityAttributes: PSecurityAttributes;
         var phkResult: HKEY;
         lpdwDisposition: PDWORD): Longint; stdcall;
begin
    Result := RealBoxedAppSDK_CreateVirtualRegKeyW(hKey, lpSubKey,
              Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes,
              phkResult, lpdwDisposition);
end;

function BoxedAppSDK_RegisterCOMLibraryInVirtualRegistry(szPath: PChar): Longint; stdcall;
begin
  {$IFDEF UNICODE}
    Result := RealBoxedAppSDK_RegisterCOMLibraryInVirtualRegistryW(szPath);
  {$ELSE}
    Result := RealBoxedAppSDK_RegisterCOMLibraryInVirtualRegistryA(szPath);
  {$ENDIF}

end;
function BoxedAppSDK_RegisterCOMLibraryInVirtualRegistryA(szPath: PAnsiChar): Longint; stdcall;
begin
    Result := RealBoxedAppSDK_RegisterCOMLibraryInVirtualRegistryA(szPath);
end;
function BoxedAppSDK_RegisterCOMLibraryInVirtualRegistryW(szPath: PWideChar): Longint; stdcall;
begin
    Result := RealBoxedAppSDK_RegisterCOMLibraryInVirtualRegistryW(szPath);
end;

function BoxedAppSDK_RegisterCOMServerInVirtualRegistry(szCommandLine: PChar): Longint; stdcall;
begin
  {$IFDEF UNICODE}
    Result := RealBoxedAppSDK_RegisterCOMServerInVirtualRegistryW(szCommandLine);
  {$ELSE}
    Result := RealBoxedAppSDK_RegisterCOMServerInVirtualRegistryA(szCommandLine);
  {$ENDIF}

end;
function BoxedAppSDK_RegisterCOMServerInVirtualRegistryA(szCommandLine: PAnsiChar): Longint; stdcall;
begin
    Result := RealBoxedAppSDK_RegisterCOMServerInVirtualRegistryA(szCommandLine);
end;
function BoxedAppSDK_RegisterCOMServerInVirtualRegistryW(szCommandLine: PWideChar): Longint; stdcall;
begin
    Result := RealBoxedAppSDK_RegisterCOMServerInVirtualRegistryW(szCommandLine);
end;

function BoxedAppSDK_SetContext(szContext: PAnsiChar): Longint; stdcall;
begin
  BoxedAppSDK_LoadDLL;

  Result := RealBoxedAppSDK_SetContext(szContext);
end;

function BoxedAppSDK_AddHandler(pHandler: TBoxedAppHandler; Param: Pointer): DWORD; stdcall;
begin
  Result := RealBoxedAppSDK_AddHandler(pHandler, Param);
end;
function BoxedAppSDK_RemoveHandler(dwHandlerId: DWORD): DWORD; stdcall;
begin
  Result := RealBoxedAppSDK_RemoveHandler(dwHandlerId);
end;

function BoxedAppSDK_Alloc(dwSize: DWORD): Pointer; stdcall;
begin
  Result := RealBoxedAppSDK_Alloc(dwSize);
end;
function BoxedAppSDK_Free(pData: Pointer): DWORD; stdcall;
begin
  Result := RealBoxedAppSDK_Free(pData);
end;

function BoxedAppSDK_SharedMem_Alloc(dwSize: DWORD): BOXEDAPP_SHARED_PTR; stdcall;
begin
  Result := RealBoxedAppSDK_SharedMem_Alloc(dwSize);
end;
procedure BoxedAppSDK_SharedMem_Free(shared_ptr: BOXEDAPP_SHARED_PTR); stdcall;
begin
  RealBoxedAppSDK_SharedMem_Free(shared_ptr);
end;
function BoxedAppSDK_SharedMem_Lock(shared_ptr: DWORD): Pointer; stdcall;
begin
  Result := RealBoxedAppSDK_SharedMem_Lock(shared_ptr);
end;
function BoxedAppSDK_SharedMem_Unlock(shared_ptr: DWORD): BOOL; stdcall;
begin
  Result := RealBoxedAppSDK_SharedMem_Unlock(shared_ptr);
end;

procedure BoxedAppSDK_EnableOption(dwOptionIndex: DWORD; bEnable: BOOL); stdcall;
begin
  RealBoxedAppSDK_EnableOption(dwOptionIndex, bEnable);
end;
function BoxedAppSDK_IsOptionEnabled(dwOptionIndex: DWORD): BOOL; stdcall;
begin
  Result := RealBoxedAppSDK_IsOptionEnabled(dwOptionIndex);
end;

procedure BoxedAppSDK_RemoteProcess_EnableOption(dwProcessId: DWORD; dwOptionIndex: DWORD; bEnable: BOOL); stdcall;
begin
  RealBoxedAppSDK_RemoteProcess_EnableOption(dwProcessId, dwOptionIndex, bEnable);
end;
function BoxedAppSDK_RemoteProcess_IsOptionEnabled(dwProcessId: DWORD; dwOptionIndex: DWORD): BOOL; stdcall;
begin
  Result := RealBoxedAppSDK_RemoteProcess_IsOptionEnabled(dwProcessId, dwOptionIndex);
end;

procedure BoxedAppSDK_SetStartupFlags(dwFlags: DWORD); stdcall;
begin
  RealBoxedAppSDK_SetStartupFlags(dwFlags);
end;

function BoxedAppSDK_DeleteFileFromVirtualFileSystem(szPath: PChar): Longint; stdcall;
begin
  {$IFDEF UNICODE}
    Result := RealBoxedAppSDK_DeleteFileFromVirtualFileSystemW(szPath);
  {$ELSE}
    Result := RealBoxedAppSDK_DeleteFileFromVirtualFileSystemA(szPath);
  {$ENDIF}
end;
function BoxedAppSDK_DeleteFileFromVirtualFileSystemA(szPath: PAnsiChar): Longint; stdcall;
begin
  Result := RealBoxedAppSDK_DeleteFileFromVirtualFileSystemA(szPath)
end;
function BoxedAppSDK_DeleteFileFromVirtualFileSystemW(szPath: PWideChar): Longint; stdcall;
begin
  Result := RealBoxedAppSDK_DeleteFileFromVirtualFileSystemW(szPath)
end;

function BoxedAppSDK_CreateProcessFromMemoryA(
	pBuffer: Pointer;
	dwSize: DWORD;

	lpApplicationName: PAnsiChar;
	lpCommandLine: PAnsiChar;
	lpProcessAttributes, lpThreadAttributes: PSecurityAttributes;
	bInheritHandles: BOOL;
	dwCreationFlags: DWORD;
	lpEnvironment: Pointer;
	lpCurrentDirectory: PAnsiChar;
	const lpStartupInfo: TStartupInfo;
	var lpProcessInformation: TProcessInformation): BOOL; stdcall;
begin
  Result := RealBoxedAppSDK_CreateProcessFromMemoryA(pBuffer, dwSize, lpApplicationName,
              lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
              dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
end;
function BoxedAppSDK_CreateProcessFromMemoryW(
	pBuffer: Pointer;
	dwSize: DWORD;

	lpApplicationName: PWideChar;
	lpCommandLine: PWideChar;
	lpProcessAttributes, lpThreadAttributes: PSecurityAttributes;
	bInheritHandles: BOOL;
	dwCreationFlags: DWORD;
	lpEnvironment: Pointer;
	lpCurrentDirectory: PWideChar;
	const lpStartupInfo: TStartupInfo;
	var lpProcessInformation: TProcessInformation): BOOL; stdcall;
begin
    Result := RealBoxedAppSDK_CreateProcessFromMemoryW(pBuffer, dwSize, lpApplicationName,
              lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
              dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
end;

function BoxedAppSDK_CreateProcessFromMemory(
	pBuffer: Pointer;
	dwSize: DWORD;

	lpApplicationName: PChar;
	lpCommandLine: PChar;
	lpProcessAttributes, lpThreadAttributes: PSecurityAttributes;
	bInheritHandles: BOOL;
	dwCreationFlags: DWORD;
	lpEnvironment: Pointer;
	lpCurrentDirectory: PChar;
	const lpStartupInfo: TStartupInfo;
	var lpProcessInformation: TProcessInformation): BOOL; stdcall;
begin
  {$IFDEF UNICODE}
    Result := RealBoxedAppSDK_CreateProcessFromMemoryW(pBuffer, dwSize, lpApplicationName,
              lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
              dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
  {$ELSE}
    Result := RealBoxedAppSDK_CreateProcessFromMemoryA(pBuffer, dwSize, lpApplicationName,
              lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
              dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
  {$ENDIF}
end;

function BoxedAppSDK_AttachToProcess(hProcess: THandle): BOOL; stdcall;
begin
  Result := RealBoxedAppSDK_AttachToProcess(hProcess);
end;
function BoxedAppSDK_DetachFromProcess(hProcess: THandle): BOOL; stdcall;
begin
  Result := RealBoxedAppSDK_DetachFromProcess(hProcess);
end;

// Internal; don't use
function BoxedAppSDK_GetInternalValue(nValueId: DWORD; buf: Pointer; dwSize: DWORD): DWORD; stdcall;
begin
  Result := RealBoxedAppSDK_GetInternalValue(nValueId, buf, dwSize);
end;

function BoxedAppSDK_ExecuteDotNetApplication(szPath: PChar; szArgs: PChar): DWORD; stdcall;
begin
  {$IFDEF UNICODE}
    Result := RealBoxedAppSDK_ExecuteDotNetApplicationW(szPath, szArgs);
  {$ELSE}
    Result := RealBoxedAppSDK_ExecuteDotNetApplicationA(szPath, szArgs);
  {$ENDIF}
end;
function BoxedAppSDK_ExecuteDotNetApplicationA(szPath: PAnsiChar; szArgs: PAnsiChar): DWORD; stdcall;
begin
    Result := RealBoxedAppSDK_ExecuteDotNetApplicationA(szPath, szArgs);
end;
function BoxedAppSDK_ExecuteDotNetApplicationW(szPath: PWideChar; szArgs: PWideChar): DWORD; stdcall;
begin
    Result := RealBoxedAppSDK_ExecuteDotNetApplicationW(szPath, szArgs);
end;

function BoxedAppSDK_HookFunction(pFunction: Pointer; pHook: Pointer; bEnable: BOOL): THandle; stdcall;
begin
  Result := RealBoxedAppSDK_HookFunction(pFunction, pHook, bEnable);
end;

function BoxedAppSDK_GetOriginalFunction(hHook: THandle): Pointer; stdcall;
begin
  Result := RealBoxedAppSDK_GetOriginalFunction(hHook);
end;

function BoxedAppSDK_EnableHook(hHook: THandle; bEnable: BOOL): BOOL; stdcall;
begin
  Result := RealBoxedAppSDK_EnableHook(hHook, bEnable);
end;
function BoxedAppSDK_UnhookFunction(hHook: THandle): BOOL; stdcall;
begin
  Result := RealBoxedAppSDK_UnhookFunction(hHook);
end;

function BoxedAppSDK_RemoteProcess_LoadLibrary(dwProcessId: DWORD; szPath: PChar): HMODULE; stdcall;
begin
  {$IFDEF UNICODE}
    Result := RealBoxedAppSDK_RemoteProcess_LoadLibraryW(dwProcessId, szPath);
  {$ELSE}
    Result := RealBoxedAppSDK_RemoteProcess_LoadLibraryA(dwProcessId, szPath);
  {$ENDIF}
end;
function BoxedAppSDK_RemoteProcess_LoadLibraryA(dwProcessId: DWORD; szPath: PAnsiChar): HMODULE; stdcall;
begin
    Result := RealBoxedAppSDK_RemoteProcess_LoadLibraryA(dwProcessId, szPath);
end;
function BoxedAppSDK_RemoteProcess_LoadLibraryW(dwProcessId: DWORD; szPath: PWideChar): HMODULE; stdcall;
begin
    Result := RealBoxedAppSDK_RemoteProcess_LoadLibraryW(dwProcessId, szPath);
end;

function BoxedAppSDK_EnumVirtualRegKeys(pEnumFunc: TBoxedAppSDK_EnumVirtualRegKeysCallback; lParam: Cardinal): Boolean; stdcall;
begin
  {$IFDEF UNICODE}
    Result := RealBoxedAppSDK_EnumVirtualRegKeysW(pEnumFunc,lParam);
  {$ELSE}
    Result := RealBoxedAppSDK_EnumVirtualRegKeysA(pEnumFunc,lParam);
  {$ENDIF}
end;
function BoxedAppSDK_EnumVirtualRegKeysA(pEnumFunc: TBoxedAppSDK_EnumVirtualRegKeysCallbackA; lParam: Cardinal): Boolean; stdcall;
begin
    Result := RealBoxedAppSDK_EnumVirtualRegKeysA(pEnumFunc,lParam);
end;
function BoxedAppSDK_EnumVirtualRegKeysW(pEnumFunc: TBoxedAppSDK_EnumVirtualRegKeysCallbackW; lParam: Cardinal): Boolean; stdcall;
begin
    Result := RealBoxedAppSDK_EnumVirtualRegKeysW(pEnumFunc,lParam);
end;

function BoxedAppSDK_SharedMem_CreateStreamOnSharedMem(var stm: IStream): HResult; stdcall;
begin
  Result := RealBoxedAppSDK_SharedMem_CreateStreamOnSharedMem(stm);
end;

function BoxedAppSDK_IsAttachedProcessId(dwProcessId: DWORD): BOOL; stdcall;
begin
  Result := RealBoxedAppSDK_IsAttachedProcessId(dwProcessId);
end;

function BoxedAppSDK_AddStubCandidate(lpStubPath: PChar): BOOL; stdcall;
begin
  {$IFDEF UNICODE}
    Result := RealBoxedAppSDK_AddStubCandidateW(lpStubPath);
  {$ELSE}
    Result := RealBoxedAppSDK_AddStubCandidateA(lpStubPath);
  {$ENDIF}
end;
function BoxedAppSDK_AddStubCandidateA(lpStubPath: PAnsiChar): BOOL; stdcall;
begin
    Result := RealBoxedAppSDK_AddStubCandidateA(lpStubPath);
end;
function BoxedAppSDK_AddStubCandidateW(lpStubPath: PWideChar): BOOL; stdcall;
begin
    Result := RealBoxedAppSDK_AddStubCandidateW(lpStubPath);
end;

function BoxedAppSDK_RemoveStubCandidate(lpStubPath: PChar): BOOL; stdcall;
begin
  {$IFDEF UNICODE}
    Result := RealBoxedAppSDK_RemoveStubCandidateW(lpStubPath);
  {$ELSE}
    Result := RealBoxedAppSDK_RemoveStubCandidateA(lpStubPath);
  {$ENDIF}
end;
function BoxedAppSDK_RemoveStubCandidateA(lpStubPath: PAnsiChar): BOOL; stdcall;
begin
    Result := RealBoxedAppSDK_RemoveStubCandidateA(lpStubPath);
end;
function BoxedAppSDK_RemoveStubCandidateW(lpStubPath: PWideChar): BOOL; stdcall;
begin
    Result := RealBoxedAppSDK_RemoveStubCandidateW(lpStubPath);
end;

function BoxedAppSDK_SetBxSdkRawData(pData: Pointer; dwSize: DWORD): BOOL; stdcall;
begin
    Result := RealBoxedAppSDK_SetBxSdkRawData(pData, dwSize);
end;

function BoxedAppSDK_Init;
begin
   BoxedAppSDK_LoadDLL;

   Result := RealBoxedAppSDK_Init();
end;

function BoxedAppSDK_Exit;
begin
  //call original function
  Result := RealBoxedAppSDK_Exit();
  if hLib <> nil then
  begin
    Internal_Unload(hLib);
    hLib := nil;
  end;
end;

begin
  hLib := nil;
{$ENDIF}

end.
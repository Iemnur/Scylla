#pragma once

#include <windows.h>

const int SCY_ERROR_SUCCESS = 0;
const int SCY_ERROR_PROCOPEN = -1;
const int SCY_ERROR_IATWRITE = -2;
const int SCY_ERROR_IATSEARCH = -3;
const int SCY_ERROR_IATNOTFOUND = -4;
const int SCY_ERROR_PIDNOTFOUND = -5;


typedef struct _GUI_DLL_PARAMETER {
	DWORD dwProcessId;
	HINSTANCE mod;
	DWORD_PTR entrypoint;
} GUI_DLL_PARAMETER, *PGUI_DLL_PARAMETER;

int InitializeGui(HINSTANCE hInstance, LPARAM param);


//function to export in DLL

BOOL DumpProcessW(const WCHAR * fileToDump, DWORD_PTR imagebase, DWORD_PTR entrypoint, const WCHAR * fileResult);

BOOL WINAPI ScyllaDumpCurrentProcessW(const WCHAR * fileToDump, DWORD_PTR imagebase, DWORD_PTR entrypoint, const WCHAR * fileResult);
BOOL WINAPI ScyllaDumpCurrentProcessA(const char * fileToDump, DWORD_PTR imagebase, DWORD_PTR entrypoint, const char * fileResult);

BOOL WINAPI ScyllaDumpProcessW(DWORD_PTR pid, const WCHAR * fileToDump, DWORD_PTR imagebase, DWORD_PTR entrypoint, const WCHAR * fileResult);
BOOL WINAPI ScyllaDumpProcessA(DWORD_PTR pid, const char * fileToDump, DWORD_PTR imagebase, DWORD_PTR entrypoint, const char * fileResult);

BOOL WINAPI ScyllaRebuildFileW(const WCHAR * fileToRebuild, BOOL removeDosStub, BOOL updatePeHeaderChecksum, BOOL createBackup);
BOOL WINAPI ScyllaRebuildFileA(const char * fileToRebuild, BOOL removeDosStub, BOOL updatePeHeaderChecksum, BOOL createBackup);

const WCHAR * WINAPI ScyllaVersionInformationW();
const char * WINAPI ScyllaVersionInformationA();
DWORD WINAPI ScyllaVersionInformationDword();

int WINAPI ScyllaStartGui(DWORD dwProcessId, HINSTANCE mod);

int WINAPI ScyllaIatSearch(DWORD dwProcessId, DWORD_PTR * iatStart, DWORD * iatSize, DWORD_PTR searchStart, BOOL advancedSearch);
int WINAPI ScyllaIatFixAutoW(DWORD dwProcessId, DWORD_PTR iatAddr,
                             DWORD iatSize, BOOL createNewIat,
                             const WCHAR* dumpFile, const WCHAR* iatFixFile);

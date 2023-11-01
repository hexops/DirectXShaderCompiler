//===- WinIncludes.h --------------------------------------------*- C++ -*-===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// WinIncludes.h                                                             //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// This file is distributed under the University of Illinois Open Source     //
// License. See LICENSE.TXT for details.                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#pragma once

#if defined(_MSC_VER) || defined(_WIN32)

// mingw-w64 tends to define it as 0x0502 in its headers.
#undef _WIN32_WINNT
#undef _WIN32_IE

// Require at least Windows 7 (Updated from XP)
#define _WIN32_WINNT 0x0601
#define _WIN32_IE 0x0800 // MinGW at it again.

#define NOATOM 1
#define NOGDICAPMASKS 1
#define NOMETAFILE 1
#ifndef NOMINMAX
#define NOMINMAX 1
#endif
#define NOOPENFILE 1
#define NORASTEROPS 1
#define NOSCROLL 1
#define NOSOUND 1
#define NOSYSMETRICS 1
#define NOWH 1
#define NOCOMM 1
#define NOKANJI 1
#define NOCRYPT 1
#define NOMCX 1
#define WIN32_LEAN_AND_MEAN 1
#define VC_EXTRALEAN 1
#define NONAMELESSSTRUCT 1

// Map these errors to equivalent errnos.
#define ERROR_NOT_CAPABLE EPERM
#define ERROR_UNHANDLED_EXCEPTION EBADF

#include <ObjIdl.h>
#ifndef __clang__ // Zig
#include <atlbase.h> // atlbase.h needs to come before strsafe.h
#endif // __clang__ // Zig
#include <intsafe.h>
#ifdef __clang__ // Zig
#define STRSAFE_NO_DEPRECATE
#endif // __clang__ // Zig
#include <strsafe.h>
#include <unknwn.h>
#include <windows.h>

#include "dxc/config.h"

// Support older atlbase.h if needed
#ifndef _ATL_DECLSPEC_ALLOCATOR
#define _ATL_DECLSPEC_ALLOCATOR
#endif

#ifndef __clang__ // Zig
/// Swap two ComPtr classes.
template <class T> void swap(CComHeapPtr<T> &a, CComHeapPtr<T> &b) {
  T *c(a.m_pData);
  a.m_pData = b.m_pData;
  b.m_pData = c;
}
#endif // __clang__ // Zig

#ifdef __clang__ // Zig
#define STRSAFE_NO_DEPRECATE
#define _Maybenull_
#define __in_range(x, y)
#define __in_ecount_opt(e)
#define Int32ToUInt32 IntToUInt
#define UInt32Add UIntAdd
#define Int32ToUInt32 IntToUInt
#define ATLASSERT assert

#define OutputDebugStringW(msg) fputws(msg, stderr)

#define OutputDebugStringA(msg) fputs(msg, stderr)
#define OutputDebugFormatA(...) fprintf(stderr, __VA_ARGS__)

// Event Tracing for Windows (ETW) provides application programmers the ability
// to start and stop event tracing sessions, instrument an application to
// provide trace events, and consume trace events.
#define DxcEtw_DXCompilerCreateInstance_Start()
#define DxcEtw_DXCompilerCreateInstance_Stop(hr)
#define DxcEtw_DXCompilerCompile_Start()
#define DxcEtw_DXCompilerCompile_Stop(hr)
#define DxcEtw_DXCompilerDisassemble_Start()
#define DxcEtw_DXCompilerDisassemble_Stop(hr)
#define DxcEtw_DXCompilerPreprocess_Start()
#define DxcEtw_DXCompilerPreprocess_Stop(hr)
#define DxcEtw_DxcValidation_Start()
#define DxcEtw_DxcValidation_Stop(hr)

#define DxcEtw_DXCompilerInitialization_Start()
#define DxcEtw_DXCompilerInitialization_Stop(e)
#define EventRegisterMicrosoft_Windows_DXCompiler_API()
#define EventUnregisterMicrosoft_Windows_DXCompiler_API()

#define D3D_NAME_STENCIL_REF ((D3D_NAME)69)
#define D3D_NAME_INNER_COVERAGE	((D3D_NAME)70)

#define D3D_SHADER_REQUIRES_DOUBLES                                                         0x00000001
#define D3D_SHADER_REQUIRES_EARLY_DEPTH_STENCIL                                             0x00000002
#define D3D_SHADER_REQUIRES_UAVS_AT_EVERY_STAGE                                             0x00000004
#define D3D_SHADER_REQUIRES_64_UAVS                                                         0x00000008
#define D3D_SHADER_REQUIRES_MINIMUM_PRECISION                                               0x00000010
#define D3D_SHADER_REQUIRES_11_1_DOUBLE_EXTENSIONS                                          0x00000020
#define D3D_SHADER_REQUIRES_11_1_SHADER_EXTENSIONS                                          0x00000040
#define D3D_SHADER_REQUIRES_LEVEL_9_COMPARISON_FILTERING                                    0x00000080
#define D3D_SHADER_REQUIRES_TILED_RESOURCES                                                 0x00000100
#define D3D_SHADER_REQUIRES_STENCIL_REF                                                     0x00000200
#define D3D_SHADER_REQUIRES_INNER_COVERAGE                                                  0x00000400
#define D3D_SHADER_REQUIRES_TYPED_UAV_LOAD_ADDITIONAL_FORMATS                               0x00000800
#define D3D_SHADER_REQUIRES_ROVS                                                            0x00001000
#define D3D_SHADER_REQUIRES_VIEWPORT_AND_RT_ARRAY_INDEX_FROM_ANY_SHADER_FEEDING_RASTERIZER  0x00002000
#define D3D_SHADER_REQUIRES_WAVE_OPS                                                        0x00004000
#define D3D_SHADER_REQUIRES_INT64_OPS                                                       0x00008000
#define D3D_SHADER_REQUIRES_VIEW_ID                                                         0x00010000
#define D3D_SHADER_REQUIRES_BARYCENTRICS                                                    0x00020000
#define D3D_SHADER_REQUIRES_NATIVE_16BIT_OPS                                                0x00040000
#define D3D_SHADER_REQUIRES_SHADING_RATE                                                    0x00080000
#define D3D_SHADER_REQUIRES_RAYTRACING_TIER_1_1                                             0x00100000
#define D3D_SHADER_REQUIRES_SAMPLER_FEEDBACK                                                0x00200000
#define D3D_SHADER_REQUIRES_ATOMIC_INT64_ON_TYPED_RESOURCE                                  0x00400000
#define D3D_SHADER_REQUIRES_ATOMIC_INT64_ON_GROUP_SHARED                                    0x00800000
#define D3D_SHADER_REQUIRES_DERIVATIVES_IN_MESH_AND_AMPLIFICATION_SHADERS                   0x01000000
#define D3D_SHADER_REQUIRES_RESOURCE_DESCRIPTOR_HEAP_INDEXING                               0x02000000
#define D3D_SHADER_REQUIRES_SAMPLER_DESCRIPTOR_HEAP_INDEXING                                0x04000000
#define D3D_SHADER_REQUIRES_WAVE_MMA                                                        0x08000000
#define D3D_SHADER_REQUIRES_ATOMIC_INT64_ON_DESCRIPTOR_HEAP_RESOURCE                        0x10000000
#define D3D_SHADER_FEATURE_ADVANCED_TEXTURE_OPS                                             0x20000000
#define D3D_SHADER_FEATURE_WRITEABLE_MSAA_TEXTURES                                          0x40000000

// HRESULT StringCchPrintfA(char *dst, size_t dstSize, const char *format, ...);
// HRESULT UIntAdd(UINT uAugend, UINT uAddend, UINT *puResult);
// HRESULT IntToUInt(int in, UINT *out);
// HRESULT SizeTToInt(size_t in, INT *out);
HRESULT UInt32Mult(UINT a, UINT b, UINT *out);

// int strnicmp(const char *str1, const char *str2, size_t count);
// int _stricmp(const char *str1, const char *str2);
// int _wcsicmp(const wchar_t *str1, const wchar_t *str2);
// int _wcsnicmp(const wchar_t *str1, const wchar_t *str2, size_t n);
// int wsprintf(wchar_t *wcs, const wchar_t *fmt, ...);
// unsigned char _BitScanForward(unsigned long *Index, unsigned long Mask);

// HANDLE CreateFile2(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode,
//                    DWORD dwCreationDisposition, void *pCreateExParams);

// HANDLE CreateFileW(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode,
//                    void *lpSecurityAttributes, DWORD dwCreationDisposition,
//                    DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);

// BOOL GetFileSizeEx(HANDLE hFile, PLARGE_INTEGER lpFileSize);

// BOOL ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead,
//               LPDWORD lpNumberOfBytesRead, void *lpOverlapped);
// BOOL WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite,
//                LPDWORD lpNumberOfBytesWritten, void *lpOverlapped);

// BOOL CloseHandle(HANDLE hObject);

// // Windows-specific heap functions
// HANDLE HeapCreate(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize);
// BOOL HeapDestroy(HANDLE heap);
// LPVOID HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T nBytes);
// LPVOID HeapReAlloc(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem, SIZE_T dwBytes);
// BOOL HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem);
// SIZE_T HeapSize(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem);
// HANDLE GetProcessHeap();

//===--------------------- HRESULT Related Macros -------------------------===//

#define E_BOUNDS (HRESULT)0x8000000B
#define E_NOT_VALID_STATE (HRESULT)0x8007139F

#define DXC_FAILED(hr) (((HRESULT)(hr)) < 0)

//===--------------------- COM Pointer Types ------------------------------===//
#ifdef __cplusplus
#include <atomic>
#include <cassert>
#include <climits>
#include <cstring>
#include <cwchar>
#include <fstream>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <string>
#include <typeindex>
#include <typeinfo>
#include <vector>
#endif // __cplusplus

class CAllocator {
public:
  static void *Reallocate(void *p, size_t nBytes) throw();
  static void *Allocate(size_t nBytes) throw();
  static void Free(void *p) throw();
};

template <class T> class CComPtrBase {
protected:
  CComPtrBase() throw() { p = nullptr; }
  CComPtrBase(T *lp) throw() {
    p = lp;
    if (p != nullptr)
      p->AddRef();
  }
  void Swap(CComPtrBase &other) {
    T *pTemp = p;
    p = other.p;
    other.p = pTemp;
  }

public:
  ~CComPtrBase() throw() {
    if (p) {
      p->Release();
      p = nullptr;
    }
  }
  operator T *() const throw() { return p; }
  T &operator*() const { return *p; }
  T *operator->() const { return p; }
  T **operator&() throw() {
    assert(p == nullptr);
    return &p;
  }
  bool operator!() const throw() { return (p == nullptr); }
  bool operator<(T *pT) const throw() { return p < pT; }
  bool operator!=(T *pT) const { return !operator==(pT); }
  bool operator==(T *pT) const throw() { return p == pT; }

  // Release the interface and set to nullptr
  void Release() throw() {
    T *pTemp = p;
    if (pTemp) {
      p = nullptr;
      pTemp->Release();
    }
  }

  // Attach to an existing interface (does not AddRef)
  void Attach(T *p2) throw() {
    if (p) {
      ULONG ref = p->Release();
      (void)(ref);
      // Attaching to the same object only works if duplicate references are
      // being coalesced.  Otherwise re-attaching will cause the pointer to be
      // released and may cause a crash on a subsequent dereference.
      assert(ref != 0 || p2 != p);
    }
    p = p2;
  }

  // Detach the interface (does not Release)
  T *Detach() throw() {
    T *pt = p;
    p = nullptr;
    return pt;
  }

  HRESULT CopyTo(T **ppT) throw() {
    assert(ppT != nullptr);
    if (ppT == nullptr)
      return E_POINTER;
    *ppT = p;
    if (p)
      p->AddRef();
    return S_OK;
  }

  template <class Q> HRESULT QueryInterface(Q **pp) const throw() {
    assert(pp != nullptr);
    return p->QueryInterface(__uuidof(Q), (void **)pp);
  }

  T *p;
};

template <class T> class CComPtr : public CComPtrBase<T> {
public:
  CComPtr() throw() {}
  CComPtr(T *lp) throw() : CComPtrBase<T>(lp) {}
  CComPtr(const CComPtr<T> &lp) throw() : CComPtrBase<T>(lp.p) {}
  T *operator=(T *lp) throw() {
    if (*this != lp) {
      CComPtr(lp).Swap(*this);
    }
    return *this;
  }

  inline bool IsEqualObject(IUnknown *pOther) throw() {
    if (this->p == nullptr && pOther == nullptr)
      return true; // They are both NULL objects

    if (this->p == nullptr || pOther == nullptr)
      return false; // One is NULL the other is not

    CComPtr<IUnknown> punk1;
    CComPtr<IUnknown> punk2;
    this->p->QueryInterface(__uuidof(IUnknown), (void **)&punk1);
    pOther->QueryInterface(__uuidof(IUnknown), (void **)&punk2);
    return punk1 == punk2;
  }

  void ComPtrAssign(IUnknown **pp, IUnknown *lp, REFIID riid) {
    IUnknown *pTemp = *pp; // takes ownership
    if (lp == nullptr || FAILED(lp->QueryInterface(riid, (void **)pp)))
      *pp = nullptr;
    if (pTemp)
      pTemp->Release();
  }

  template <typename Q> T *operator=(const CComPtr<Q> &lp) throw() {
    if (!this->IsEqualObject(lp)) {
      ComPtrAssign((IUnknown **)&this->p, lp, __uuidof(T));
    }
    return *this;
  }

  // NOTE: This conversion constructor is not part of the official CComPtr spec;
  // however, it is needed to convert CComPtr<Q> to CComPtr<T> where T derives
  // from Q on Clang. MSVC compiles this conversion as first a call to
  // CComPtr<Q>::operator T*, followed by CComPtr<T>(T*), but Clang fails to
  // compile with error: no viable conversion from 'CComPtr<Q>' to 'CComPtr<T>'.
  template <typename Q>
  CComPtr(const CComPtr<Q> &lp) throw() : CComPtrBase<T>(lp.p) {}

  T *operator=(const CComPtr<T> &lp) throw() {
    if (*this != lp) {
      CComPtr(lp).Swap(*this);
    }
    return *this;
  }

  CComPtr(CComPtr<T> &&lp) throw() : CComPtrBase<T>() { lp.Swap(*this); }

  T *operator=(CComPtr<T> &&lp) throw() {
    if (*this != lp) {
      CComPtr(static_cast<CComPtr &&>(lp)).Swap(*this);
    }
    return *this;
  }
};

template <class T> class CSimpleArray : public std::vector<T> {
public:
  bool Add(const T &t) {
    this->push_back(t);
    return true;
  }
  int GetSize() { return this->size(); }
  T *GetData() { return this->data(); }
  void RemoveAll() { this->clear(); }
};

template <class T, class Allocator = CAllocator> class CHeapPtrBase {
protected:
  CHeapPtrBase() throw() : m_pData(NULL) {}
  CHeapPtrBase(CHeapPtrBase<T, Allocator> &p) throw() {
    m_pData = p.Detach(); // Transfer ownership
  }
  explicit CHeapPtrBase(T *pData) throw() : m_pData(pData) {}

public:
  ~CHeapPtrBase() throw() { Free(); }

protected:
  CHeapPtrBase<T, Allocator> &operator=(CHeapPtrBase<T, Allocator> &p) throw() {
    if (m_pData != p.m_pData)
      Attach(p.Detach()); // Transfer ownership
    return *this;
  }

public:
  operator T *() const throw() { return m_pData; }
  T *operator->() const throw() {
    assert(m_pData != NULL);
    return m_pData;
  }

  T **operator&() throw() {
    assert(m_pData == NULL);
    return &m_pData;
  }

  // Allocate a buffer with the given number of bytes
  bool AllocateBytes(size_t nBytes) throw() {
    assert(m_pData == NULL);
    m_pData = static_cast<T *>(Allocator::Allocate(nBytes * sizeof(char)));
    if (m_pData == NULL)
      return false;

    return true;
  }

  // Attach to an existing pointer (takes ownership)
  void Attach(T *pData) throw() {
    Allocator::Free(m_pData);
    m_pData = pData;
  }

  // Detach the pointer (releases ownership)
  T *Detach() throw() {
    T *pTemp = m_pData;
    m_pData = NULL;
    return pTemp;
  }

  // Free the memory pointed to, and set the pointer to NULL
  void Free() throw() {
    Allocator::Free(m_pData);
    m_pData = NULL;
  }

  // Reallocate the buffer to hold a given number of bytes
  bool ReallocateBytes(size_t nBytes) throw() {
    T *pNew;
    pNew =
        static_cast<T *>(Allocator::Reallocate(m_pData, nBytes * sizeof(char)));
    if (pNew == NULL)
      return false;
    m_pData = pNew;

    return true;
  }

public:
  T *m_pData;
};

template <typename T, class Allocator = CAllocator>
class CHeapPtr : public CHeapPtrBase<T, Allocator> {
public:
  CHeapPtr() throw() {}
  CHeapPtr(CHeapPtr<T, Allocator> &p) throw() : CHeapPtrBase<T, Allocator>(p) {}
  explicit CHeapPtr(T *p) throw() : CHeapPtrBase<T, Allocator>(p) {}
  CHeapPtr<T> &operator=(CHeapPtr<T, Allocator> &p) throw() {
    CHeapPtrBase<T, Allocator>::operator=(p);
    return *this;
  }

  // Allocate a buffer with the given number of elements
  bool Allocate(size_t nElements = 1) throw() {
    size_t nBytes = nElements * sizeof(T);
    return this->AllocateBytes(nBytes);
  }

  // Reallocate the buffer to hold a given number of elements
  bool Reallocate(size_t nElements) throw() {
    size_t nBytes = nElements * sizeof(T);
    return this->ReallocateBytes(nBytes);
  }
};

#define CComHeapPtr CHeapPtr

//===--------------------- UTF-8 Related Types ----------------------------===//

// Code Page
#define CP_ACP 0
#define CP_UTF8 65001 // UTF-8 translation.

// Convert Windows codepage value to locale string
const char *CPToLocale(uint32_t CodePage);

// The t_nBufferLength parameter is part of the published interface, but not
// used here.
template <int t_nBufferLength = 128> class CW2AEX {
public:
  CW2AEX(LPCWSTR psz, UINT nCodePage = CP_UTF8) {
    const char *locale = CPToLocale(nCodePage);
    if (locale == nullptr) {
      // Current Implementation only supports CP_UTF8, and CP_ACP
      assert(false && "CW2AEX implementation for Linux only handles "
                      "UTF8 and ACP code pages");
      return;
    }

    if (!psz) {
      m_psz = NULL;
      return;
    }

    locale = setlocale(LC_ALL, locale);
    int len = (wcslen(psz) + 1) * 4;
    m_psz = new char[len];
    std::wcstombs(m_psz, psz, len);
    setlocale(LC_ALL, locale);
  }

  ~CW2AEX() { delete[] m_psz; }

  operator LPSTR() const { return m_psz; }

  char *m_psz;
};
typedef CW2AEX<> CW2A;

// The t_nBufferLength parameter is part of the published interface, but not
// used here.
template <int t_nBufferLength = 128> class CA2WEX {
public:
  CA2WEX(LPCSTR psz, UINT nCodePage = CP_UTF8) {
    const char *locale = CPToLocale(nCodePage);
    if (locale == nullptr) {
      // Current Implementation only supports CP_UTF8, and CP_ACP
      assert(false && "CA2WEX implementation for Linux only handles "
                      "UTF8 and ACP code pages");
      return;
    }

    if (!psz) {
      m_psz = NULL;
      return;
    }

    locale = setlocale(LC_ALL, locale);
    int len = strlen(psz) + 1;
    m_psz = new wchar_t[len];
    std::mbstowcs(m_psz, psz, len);
    setlocale(LC_ALL, locale);
  }

  ~CA2WEX() { delete[] m_psz; }

  operator LPWSTR() const { return m_psz; }

  wchar_t *m_psz;
};

typedef CA2WEX<> CA2W;

//===--------- File IO Related Types ----------------===//

class CHandle {
public:
  CHandle(HANDLE h);
  ~CHandle();
  operator HANDLE() const throw();

private:
  HANDLE m_h;
};

/////////////////////////////////////////////////////////////////////////////
// CComBSTR

class CComBSTR {
public:
  BSTR m_str;
  CComBSTR() : m_str(nullptr){};
  CComBSTR(int nSize, LPCWSTR sz);
  ~CComBSTR() throw() { SysFreeString(m_str); }

  operator BSTR() const throw() { return m_str; }

  bool operator==(const CComBSTR &bstrSrc) const throw();

  BSTR *operator&() throw() { return &m_str; }

  BSTR Detach() throw() {
    BSTR s = m_str;
    m_str = NULL;
    return s;
  }
};


#endif // __clang__ // Zig
#else // defined(_MSC_VER) || defined(_WIN32)

#include "dxc/WinAdapter.h"

#ifdef __cplusplus
#if !defined(DEFINE_ENUM_FLAG_OPERATORS)
// Define operator overloads to enable bit operations on enum values that are
// used to define flags. Use DEFINE_ENUM_FLAG_OPERATORS(YOUR_TYPE) to enable
// these operators on YOUR_TYPE.
extern "C++" {
template <size_t S> struct _ENUM_FLAG_INTEGER_FOR_SIZE;

template <> struct _ENUM_FLAG_INTEGER_FOR_SIZE<1> { typedef int8_t type; };

template <> struct _ENUM_FLAG_INTEGER_FOR_SIZE<2> { typedef int16_t type; };

template <> struct _ENUM_FLAG_INTEGER_FOR_SIZE<4> { typedef int32_t type; };

// used as an approximation of std::underlying_type<T>
template <class T> struct _ENUM_FLAG_SIZED_INTEGER {
  typedef typename _ENUM_FLAG_INTEGER_FOR_SIZE<sizeof(T)>::type type;
};
}
#define DEFINE_ENUM_FLAG_OPERATORS(ENUMTYPE)                                   \
  extern "C++" {                                                               \
  inline ENUMTYPE operator|(ENUMTYPE a, ENUMTYPE b) {                          \
    return ENUMTYPE(((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)a) |            \
                    ((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b));            \
  }                                                                            \
  inline ENUMTYPE &operator|=(ENUMTYPE &a, ENUMTYPE b) {                       \
    return (ENUMTYPE &)(((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type &)a) |=     \
                        ((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b));        \
  }                                                                            \
  inline ENUMTYPE operator&(ENUMTYPE a, ENUMTYPE b) {                          \
    return ENUMTYPE(((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)a) &            \
                    ((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b));            \
  }                                                                            \
  inline ENUMTYPE &operator&=(ENUMTYPE &a, ENUMTYPE b) {                       \
    return (ENUMTYPE &)(((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type &)a) &=     \
                        ((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b));        \
  }                                                                            \
  inline ENUMTYPE operator~(ENUMTYPE a) {                                      \
    return ENUMTYPE(~((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)a));           \
  }                                                                            \
  inline ENUMTYPE operator^(ENUMTYPE a, ENUMTYPE b) {                          \
    return ENUMTYPE(((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)a) ^            \
                    ((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b));            \
  }                                                                            \
  inline ENUMTYPE &operator^=(ENUMTYPE &a, ENUMTYPE b) {                       \
    return (ENUMTYPE &)(((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type &)a) ^=     \
                        ((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b));        \
  }                                                                            \
  }
#endif // !defined(DEFINE_ENUM_FLAG_OPERATORS)
#else
#define DEFINE_ENUM_FLAG_OPERATORS(ENUMTYPE) // NOP, C allows these operators.
#endif

#endif // defined(_MSC_VER) || defined(_WIN32)

/// DxcCoGetMalloc
#if defined(_WIN32) && !defined(DXC_DISABLE_ALLOCATOR_OVERRIDES)

#define DxcCoGetMalloc CoGetMalloc

#else // defined(_WIN32) && !defined(DXC_DISABLE_ALLOCATOR_OVERRIDES)

#ifndef _WIN32
struct IMalloc;
#endif

HRESULT DxcCoGetMalloc(DWORD dwMemContext, IMalloc **ppMalloc);

#endif // defined(_WIN32) && !defined(DXC_DISABLE_ALLOCATOR_OVERRIDES)

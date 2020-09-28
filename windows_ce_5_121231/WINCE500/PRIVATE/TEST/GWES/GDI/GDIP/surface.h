//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//
// This source code is licensed under Microsoft Shared Source License
// Version 1.0 for Windows CE.
// For a copy of the license visit http://go.microsoft.com/fwlink/?LinkId=3223.
//
#include "handles.h"
#include "testsuite.h"
#include "bencheng.h"

#ifndef SURFACE_H
#define SURFACE_H

class CSurface
{
    public:
        CSurface(CSection * Section) : m_SectionList(Section), m_DC(NULL), m_tsDCNameArray(NULL),
                                                    m_nBitDepth(NULL), m_nIndex(0), m_nMaxIndex(0)
                        { g_pCOtakLog->Log(OTAK_VERBOSE, TEXT("In CSurface overloaded constructor.")); }
        CSurface() {}
        ~CSurface() { g_pCOtakLog->Log(OTAK_VERBOSE, TEXT("In CSurface Destructor.")); }

        BOOL Initialize(TestSuiteInfo *tsi, TSTRING ts, TSTRING tsDefault = TEXT("Primary"));
        BOOL PreRun(TestInfo *);
        BOOL PostRun();
        BOOL Cleanup();
        HDC GetSurface();

    private:
        // attached brush list, with the name of the brush and the current index
        // dest dc list with the name of the dc and the current index
        CSection *m_SectionList;
        HDC *m_DC;
        TSTRING *m_tsDCNameArray;
        TSTRING m_tsDeviceName;
        UINT *m_nBitDepth;
        int m_nIndex, m_nMaxIndex;
};

#endif


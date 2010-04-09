/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: Used for execute a single case.
*
*/

#ifndef CASERUNNER_H_
#define CASERUNNER_H_

#include <e32std.h>
#include <e32base.h>
#include <e32cons.h>
#include "executor.h"

class CCaseRunner : public CActive
    {
public:
    static CCaseRunner* NewL(CExecutor* executor, TTestInfo& aTestInfo );
    ~CCaseRunner();

private:
    CCaseRunner(CExecutor* executor, TTestInfo& aTestInfo);
    void ContructL();
    
public: //public method
    TInt RunTestsL();
    void StartTestL();

public: //implement CActive
    void RunL();
    void DoCancel();
    TInt RunError(TInt aError);
    
private:
    CExecutor* iExecutor;
    RTestEngine iTestEngine;
    RTestCase iTestCase;
    TTestInfo iTestInfo;
    TTestInfoPckg iTestInfoPckg;
    TFullTestResult iFullTestResult;
    TFullTestResultPckg iFullTestResultPckg;
    
    };

#endif /* CASERUNNER_H_ */

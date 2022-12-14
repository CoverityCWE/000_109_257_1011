/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__wchar_t_console_67a.c
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: console Read input from the console
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define MAX_LOOP 10000

#ifndef _WIN32
#include <wchar.h>
#endif

typedef struct _CWE606_Unchecked_Loop_Condition__wchar_t_console_67_structType
{
    wchar_t * structFirst;
} CWE606_Unchecked_Loop_Condition__wchar_t_console_67_structType;

#ifndef OMITBAD

/* bad function declaration */
void CWE606_Unchecked_Loop_Condition__wchar_t_console_67b_badSink(CWE606_Unchecked_Loop_Condition__wchar_t_console_67_structType myStruct);

void CWE606_Unchecked_Loop_Condition__wchar_t_console_67_bad()
{
    wchar_t * data;
    CWE606_Unchecked_Loop_Condition__wchar_t_console_67_structType myStruct;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    {
        /* Read input from the console */
        size_t dataLen = wcslen(data);
        /* if there is room in data, read into it from the console */
        if (100-dataLen > 1)
        {
            /* POTENTIAL FLAW: Read data from the console */
            if (fgetws(data+dataLen, (int)(100-dataLen), stdin) != NULL)//SLIVER_SOURCE
            {
                /* The next few lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                dataLen = wcslen(data);
                if (dataLen > 0 && data[dataLen-1] == L'\n')
                {
                    data[dataLen-1] = L'\0';
                }
            }
            else
            {
                printLine("fgetws() failed");
                /* Restore NUL terminator if fgetws fails */
                data[dataLen] = L'\0';
            }
        }
    }
    myStruct.structFirst = data;
    CWE606_Unchecked_Loop_Condition__wchar_t_console_67b_badSink(myStruct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE606_Unchecked_Loop_Condition__wchar_t_console_67b_goodG2BSink(CWE606_Unchecked_Loop_Condition__wchar_t_console_67_structType myStruct);

static void goodG2B()
{
    wchar_t * data;
    CWE606_Unchecked_Loop_Condition__wchar_t_console_67_structType myStruct;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* FIX: Set data to a number less than MAX_LOOP */
    wcscpy(data, L"15");
    myStruct.structFirst = data;
    CWE606_Unchecked_Loop_Condition__wchar_t_console_67b_goodG2BSink(myStruct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE606_Unchecked_Loop_Condition__wchar_t_console_67b_goodB2GSink(CWE606_Unchecked_Loop_Condition__wchar_t_console_67_structType myStruct);

static void goodB2G()
{
    wchar_t * data;
    CWE606_Unchecked_Loop_Condition__wchar_t_console_67_structType myStruct;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    {
        /* Read input from the console */
        size_t dataLen = wcslen(data);
        /* if there is room in data, read into it from the console */
        if (100-dataLen > 1)
        {
            /* POTENTIAL FLAW: Read data from the console */
            if (fgetws(data+dataLen, (int)(100-dataLen), stdin) != NULL)//SLIVER_SOURCE
            {
                /* The next few lines remove the carriage return from the string that is
                 * inserted by fgetws() */
                dataLen = wcslen(data);
                if (dataLen > 0 && data[dataLen-1] == L'\n')
                {
                    data[dataLen-1] = L'\0';
                }
            }
            else
            {
                printLine("fgetws() failed");
                /* Restore NUL terminator if fgetws fails */
                data[dataLen] = L'\0';
            }
        }
    }
    myStruct.structFirst = data;
    CWE606_Unchecked_Loop_Condition__wchar_t_console_67b_goodB2GSink(myStruct);
}

void CWE606_Unchecked_Loop_Condition__wchar_t_console_67_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE606_Unchecked_Loop_Condition__wchar_t_console_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE606_Unchecked_Loop_Condition__wchar_t_console_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif


//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_console_67a.c:49--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_console_67b.c:42 YES
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_console_67a.c:49--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_console_67b.c:66 NO
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_console_67a.c:49--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_console_67b.c:88 NO
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_console_67a.c:106--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_console_67b.c:42 NO
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_console_67a.c:106--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_console_67b.c:66 NO
//SLIVER_SOURCE:CWE606_Unchecked_Loop_Condition__wchar_t_console_67a.c:106--->SLIVER_SINK:CWE606_Unchecked_Loop_Condition__wchar_t_console_67b.c:88 YES

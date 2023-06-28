//
// Created by 48782 on 06.06.2023.
//

#ifndef JOURNAL_CORE_H
#define JOURNAL_CORE_H

#ifdef JR_WINDOWS_PLATFORM
    #ifdef JR_DLL
        #define JR_API __declspec(dllexport)
    #else
        #define JR_API __declspec(dllimport)
    #endif
#else
    #error "Platform not supported"
#endif
#endif //JOURNAL_CORE_H

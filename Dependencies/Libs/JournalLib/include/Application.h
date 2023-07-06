//
// Created by 48782 on 06.06.2023.
//

#ifndef JOURNAL_APPLICATION_H
#define JOURNAL_APPLICATION_H
#include "Core.h"

namespace Journal{
    class JR_API Application {
    public:
        Application() = default;
        virtual ~Application() = default;

        void Run();
    };

    //to be defined in client
    Application* CreateApplication();
}

#endif //JOURNAL_APPLICATION_H

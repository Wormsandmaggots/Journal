//
// Created by 48782 on 06.07.2023.
//

#ifndef JOURNAL_ENTRYPOINT_H
#define JOURNAL_ENTRYPOINT_H
#ifdef JR_WINDOWS_PLATFORM

extern Journal::Application* Journal::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Journal::CreateApplication();
    app->Run();

    delete app;
    return 0;
}

#endif
#endif //JOURNAL_ENTRYPOINT_H
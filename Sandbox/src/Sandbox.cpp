#include "Journal.h"

namespace Journal {
    void Print();
}

class Sandbox : public Journal::Application {
public:
    Sandbox() = default;
    virtual ~Sandbox() = default;
};

Journal::Application *Journal::CreateApplication(){
    return new Sandbox();
}

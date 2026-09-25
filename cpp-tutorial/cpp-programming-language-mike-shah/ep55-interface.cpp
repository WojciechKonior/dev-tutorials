#include <iostream>
#include <string>

class IRenderer {
public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
};

class OpenGL: public IRenderer {
public:
    virtual void Update() override {
        std::cout << "OpenGL::Update\n";
    }
    virtual void Draw() override {
        std::cout << "OpenGL::Draw\n";
    }
};

class Vulcan: public IRenderer {
public:
    virtual void Update() override {
        std::cout << "Vulcan::Update\n";
    }
    virtual void Draw() override {
        std::cout << "Vulcan::Draw\n";
    }
};

int main() {
    IRenderer* myRenderer = new OpenGL;
    myRenderer->Update();
    myRenderer->Draw();
    delete myRenderer;

    myRenderer = new Vulcan;
    myRenderer->Update();
    myRenderer->Draw();

    return 0;
}

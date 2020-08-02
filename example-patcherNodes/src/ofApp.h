#pragma once

#include "ofMain.h"

#include "ofxImGuiSimple.h"

#include "imnodes.h"

//#include "hello.cpp"
//#include "save_load.cpp"
#include "color_node_editor.cpp"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void exit();

    ofFloatColor backgroundColor;
    float floatValue;
    bool b;

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    ofxImGuiSimple gui;
    ImFont* font1;
    ImFont* font2;
    ImFont* font3;

    //example::HelloWorldNodeEditor example;
//    example::SaveLoadEditor example;
    example::ColorNodeEditor example;

    void drawTest()
    {
        ImGui::Text("Hello, world!");
        ImGui::ColorEdit3("Background Color", (float*)&backgroundColor);

        ImGui::PushFont(font2);
        ImGui::Text("Hello!");
        ImGui::PopFont();

        ImGui::SliderFloat("Float", &floatValue, 0.0f, 1.0f);

        ImGui::PushFont(font3);
        if (ImGui::Checkbox("Demo Window", &b))
            if (b) ImGui::ShowDemoWindow();
        ImGui::PopFont();
    }

    void drawTest2()
    {
        ImGui::Begin("simple node editor");

        imnodes::BeginNodeEditor();
        imnodes::BeginNode(1);

        imnodes::BeginNodeTitleBar();
        ImGui::TextUnformatted("simple node :)");
        imnodes::EndNodeTitleBar();

        imnodes::BeginInputAttribute(2);
        ImGui::Text("input");
        imnodes::EndInputAttribute();

        imnodes::BeginOutputAttribute(3);
        ImGui::Indent(40);
        ImGui::Text("output");
        imnodes::EndOutputAttribute();

        imnodes::EndNode();
        imnodes::EndNodeEditor();

        ImGui::End();
    }
};

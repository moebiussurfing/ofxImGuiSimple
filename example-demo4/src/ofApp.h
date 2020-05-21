#pragma once

#include "ofMain.h"
#include "ofxImGuiSimple.h"

//# include "Application.h"
#include "imgui_node_editor.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void exit();
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);

    ofxImGuiSimple gui;

    void show()
    {

    }

};


    namespace ed = ax::NodeEditor;

    static ed::EditorContext* g_Context = nullptr;

    void Application_Initialize()
    {
        g_Context = ed::CreateEditor();
    }

    void Application_Finalize()
    {
        ed::DestroyEditor(g_Context);
    }

    void Application_Frame()
    {
        ed::SetCurrentEditor(g_Context);

        ed::Begin("My Editor");

        int uniqueId = 1;

        // Start drawing nodes.
        ed::BeginNode(uniqueId++);
        ImGui::Text("Node A");
        ed::BeginPin(uniqueId++, ed::PinKind::Input);
        ImGui::Text("-> In");
        ed::EndPin();
        ImGui::SameLine();
        ed::BeginPin(uniqueId++, ed::PinKind::Output);
        ImGui::Text("Out ->");
        ed::EndPin();
        ed::EndNode();

        ed::End();
    }




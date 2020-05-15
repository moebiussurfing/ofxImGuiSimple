#pragma once

#include "ofMain.h"
#include "ofxImGuiSimple.h"
#include "ImNodes.h"
#include "ImNodesEz.h"
//#include "sample.cpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    
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


    void drawBasic()
    {
        static ImNodes::CanvasState canvas;

        if (ImGui::Begin("ImNodes", nullptr, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse))
        {
            ImNodes::BeginCanvas(&canvas);

            struct Node
            {
                ImVec2 pos{};
                bool selected{};
                ImNodes::Ez::SlotInfo inputs[1];
                ImNodes::Ez::SlotInfo outputs[1];
            };

            //        static Node nodes[3] = {
            //            {{50, 100}, false, {{"In", 1}}, {{"Out", 1}}},
            //            {{250, 50}, false, {{"In", 1}}, {{"Out", 1}}},
            //            {{250, 100}, false, {{"In", 1}}, {{"Out", 1}}},
            //        };

            static Node nodes[3] ;

            nodes[0].pos = ImVec2(50, 100);
            nodes[0].inputs[0].title = "In";
            nodes[0].inputs[0].kind = 1;
            nodes[0].outputs[0].title = "Out";
            nodes[0].outputs[0].kind = 1;
            nodes[0].selected = false;

            nodes[1].pos = ImVec2(250, 50);
            nodes[1].inputs[0].title = "In";
            nodes[1].inputs[0].kind = 1;
            nodes[1].outputs[0].title = "Out";
            nodes[1].outputs[0].kind = 1;
            nodes[1].selected = false;

            nodes[2].pos = ImVec2(250, 100);
            nodes[2].inputs[0].title = "In";
            nodes[2].inputs[0].kind = 1;
            nodes[2].outputs[0].title = "Out";
            nodes[2].outputs[0].kind = 1;
            nodes[2].selected = false;

            for (Node& node : nodes)
            {
                if (ImNodes::Ez::BeginNode(&node, "Node Title", &node.pos, &node.selected))
                {
                    ImNodes::Ez::InputSlots(node.inputs, 1);
                    ImNodes::Ez::OutputSlots(node.outputs, 1);
                    ImNodes::Ez::EndNode();
                }
            }

            ImNodes::Connection(&nodes[1], "In", &nodes[0], "Out");
            ImNodes::Connection(&nodes[2], "In", &nodes[0], "Out");

            ImNodes::EndCanvas();
        }
        ImGui::End();


    }
};

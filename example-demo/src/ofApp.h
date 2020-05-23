#pragma once

#include "ofMain.h"
#include "ofxImGuiSimple.h"
#include "imnodes.h"

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

//    void show()
//    {
//        ImGui::Begin("simple node editor");
//
//        imnodes::BeginNodeEditor();
//        imnodes::BeginNode(1);
//
//        imnodes::BeginNodeTitleBar();
//        ImGui::TextUnformatted("simple node :)");
//        imnodes::EndNodeTitleBar();
//
//        imnodes::BeginInputAttribute(2);
//        ImGui::Text("input");
//        imnodes::EndAttribute();
//
//        imnodes::BeginOutputAttribute(3);
//        ImGui::Indent(40);
//        ImGui::Text("output");
//        imnodes::EndAttribute();
//
//        imnodes::EndNode();
//        imnodes::EndNodeEditor();
//
//        ImGui::End();
//    }
};

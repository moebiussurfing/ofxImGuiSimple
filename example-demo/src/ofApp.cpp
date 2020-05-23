#include "ofApp.h"
#include "imgui.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(25);

    gui.setup();

//    imnodes::Initialize();
    imnodes::Initialize();
imnodes::SetNodeGridSpacePos(1, ImVec2(200.0f, 200.0f));

}

//--------------------------------------------------------------
void ofApp::exit(){
    // elsewhere in the code...
    imnodes::Shutdown();
//    ImGui::DestroyContext();
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.begin();


    ImGui::ShowDemoWindow();


    ImGui::Begin("node editor");


    imnodes::BeginNodeEditor();
    //---------------


    const int hardcoded_node_id = 100;
    imnodes::BeginNode(hardcoded_node_id);

    imnodes::BeginNodeTitleBar();
    ImGui::TextUnformatted("output node");
    imnodes::EndNodeTitleBar();

    imnodes::BeginInputAttribute(101);
    ImGui::Text("input101");
    imnodes::EndAttribute();

    imnodes::BeginInputAttribute(102);
    ImGui::Text("input102");
    imnodes::EndAttribute();

    imnodes::BeginOutputAttribute(111);
    ImGui::Indent(40);
    ImGui::Text("output111");
    imnodes::EndAttribute();

    imnodes::BeginOutputAttribute(112);
    ImGui::Indent(40);
    ImGui::Text("output112");
    imnodes::EndAttribute();

    imnodes::EndNode();



    imnodes::BeginNode(200);

    imnodes::BeginNodeTitleBar();
    ImGui::TextUnformatted("simple node :)");
    imnodes::EndNodeTitleBar();

    imnodes::BeginInputAttribute(201);
    ImGui::Text("input201");
    imnodes::EndAttribute();

    imnodes::BeginInputAttribute(202);
    ImGui::Text("input202");
    imnodes::EndAttribute();

    imnodes::BeginOutputAttribute(211);
    ImGui::Indent(40);
    ImGui::Text("output211");
    imnodes::EndAttribute();

    imnodes::BeginOutputAttribute(212);
    ImGui::Indent(40);
    ImGui::Text("output212");
    imnodes::EndAttribute();

    imnodes::BeginOutputAttribute(213);
    ImGui::Indent(40);
    ImGui::Text("output213");
    imnodes::EndAttribute();

    imnodes::BeginOutputAttribute(214);
    ImGui::Indent(40);
    ImGui::Text("output214");
    imnodes::EndAttribute();

    imnodes::EndNode();

    //---------------
    imnodes::EndNodeEditor();

    ImGui::End();


    //-------------

//    show();


    
    gui.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

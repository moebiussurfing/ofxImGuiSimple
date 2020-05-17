#include "ofApp.h"
#include "imgui.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(25);

    gui.setup();

        imnodes::Initialize();

//    imnodes::Initialize();
//    imnodes::SetNodeGridSpacePos(1, ImVec2(200.0f, 200.0f));


    example.load();
//    example.SaveLoadEditor::
}

//--------------------------------------------------------------
void ofApp::exit(){

    example.save();


    // elsewhere in the code...
    imnodes::Shutdown();
    ImGui::DestroyContext();
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.begin();



    example.show();


//    example::NodeEditorShow();

//    ImGui::ShowDemoWindow();
//
//
//    ImGui::Begin("node editor");
//
//    const int hardcoded_node_id = 11;
//
//    imnodes::BeginNodeEditor();
//    //---------------
//
//
//    imnodes::BeginNode(hardcoded_node_id);
//
//    imnodes::BeginNodeTitleBar();
//    ImGui::TextUnformatted("output node");
//    imnodes::EndNodeTitleBar();
//
//    const int output_attr_id = 22;
//    imnodes::BeginOutputAttribute(output_attr_id);
//    // in between Begin|EndAttribute calls, you can call ImGui
//    // UI functions
//    ImGui::Text("output pin");
//    imnodes::EndAttribute();
//
//    imnodes::EndNode();
//
//
//
//    imnodes::BeginNode(1);
//
//    imnodes::BeginNodeTitleBar();
//    ImGui::TextUnformatted("simple node :)");
//    imnodes::EndNodeTitleBar();
//
//    imnodes::BeginInputAttribute(2);
//    ImGui::Text("input");
//    imnodes::EndAttribute();
//
//    imnodes::BeginOutputAttribute(3);
//    ImGui::Indent(40);
//    ImGui::Text("output");
//    imnodes::EndAttribute();
//
//    imnodes::EndNode();
//
//    //---------------
//    imnodes::EndNodeEditor();
//
//    ImGui::End();


    //-------------

//    show();


    
    gui.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
if(key=='s')
{
    example.doLog();
    example.save();
}
    if(key=='l')
    {
        example.load();
    }
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

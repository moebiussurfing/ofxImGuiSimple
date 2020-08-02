#include "ofApp.h"
#include "imgui.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(25);

//    params.add(enable);
    params.add(value1);
//    params.add(value2);
//    params.add(value3);

    gui.setup();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.begin();

    constructGui();
    

    //    draw2();


    //    if (ImGui::DockBuilderGetNode(ImGui::GetID("MyDockspace")) == NULL)
    //    {
    //        ImGuiID dockspace_id = ImGui::GetID("MyDockspace");
    //        ImGuiViewport* viewport = ImGui::GetMainViewport();
    //        ImGui::DockBuilderRemoveNode(dockspace_id); // Clear out existing layout
    //        ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_None); // Add empty node
    //
    //        ImGuiID dock_main_id = dockspace_id; // This variable will track the document node, however we are not using it here as we aren't docking anything into it.
    //        ImGuiID dock_id_left = ImGui::DockBuilderSplitNode(dock_main_id, ImGuiDir_Left, 0.20f, NULL, &dock_main_id);
    //        ImGuiID dock_id_right = ImGui::DockBuilderSplitNode(dock_main_id, ImGuiDir_Right, 0.20f, NULL, &dock_main_id);
    //        ImGuiID dock_id_bottom = ImGui::DockBuilderSplitNode(dock_main_id, ImGuiDir_Down, 0.20f, NULL, &dock_main_id);
    //
    //        ImGui::DockBuilderDockWindow("James_1", dock_id_left);
    //        ImGui::DockBuilderDockWindow("James_2", dock_main_id);
    //        ImGui::DockBuilderDockWindow("James_3", dock_id_right);
    //        ImGui::DockBuilderDockWindow("James_4", dock_id_bottom);
    //        ImGui::DockBuilderFinish(dockspace_id);
    //    }

    //    ImGui::ShowUserGuide();

    //    ImGui::ShowDemoWindow();

    //    ImGui::ShowViewportThumbnails();


    //    drawBasic();



    gui.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key==' ')
    {

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

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(25);

    gui.setup();

    //--

    //Change font in ofxImGui/ImGui
    //https://forum.openframeworks.cc/t/change-font-in-ofximgui/28841
    ImGuiIO& io = ImGui::GetIO();
    ImFontConfig config;
    config.OversampleH = 3;
    config.OversampleV = 1;
    config.GlyphExtraSpacing.x = 1.0f;

    const char* myPath;
    string inputPath;

    inputPath = ofFilePath::getAbsolutePath("fonts/malgun_console.ttf");
    myPath = inputPath.c_str();
    font1 = io.Fonts->AddFontFromFileTTF(myPath, 15.0f, &config);

    inputPath = ofFilePath::getAbsolutePath("fonts/msjh_boot.ttf");
    myPath = inputPath.c_str();
    font2 = io.Fonts->AddFontFromFileTTF(myPath, 20.0f, &config);

    inputPath = ofFilePath::getAbsolutePath("fonts/msyh_console.ttf");
    myPath = inputPath.c_str();
    font3 = io.Fonts->AddFontFromFileTTF(myPath, 20.0f, &config);

    //--

    ImGui::CreateContext();
    imnodes::Initialize();

    example::NodeEditorInitialize();

    //    imnodes::SetNodeGridSpacePos(1, ImVec2(200.0f, 200.0f));

    //    example.load();
    //    example.SaveLoadEditor::
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.begin();
    {

        drawTest();

        example::NodeEditorShow();
        
//        ImGui::Begin("node editor");
//        {
////            imnodes::BeginNodeEditor();
////            imnodes::EndNodeEditor();
////            ImGui::Dummy(ImVec2(80.0f, 45.0f));
////
////            drawTest2();
//        }
//        ImGui::End();

        //--

        // combo with fonts added to ImGui
        ImGuiIO& io = ImGui::GetIO();
        ImFont* font_current = ImGui::GetFont();
        if (ImGui::BeginCombo("Fonts", font_current->GetDebugName())) {
            for (auto font : io.Fonts->Fonts) {
                if (ImGui::Selectable(font->GetDebugName(), font == font_current)) {
                    io.FontDefault = font;
                }
            }
            ImGui::EndCombo();
        }
    }
    gui.end();
}

//--------------------------------------------------------------
void ofApp::exit(){
    //    example.save();
    // elsewhere in the code...

    example::NodeEditorShutdown();

    imnodes::Shutdown();
    ImGui::DestroyContext();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    example::color_editor.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
 example::color_editor.keyReleased(key);
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

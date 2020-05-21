#include "ofApp.h"
#include "imgui.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(25);

    gui.setup();

//    Application_Initialize();

    g_Context = ed::CreateEditor();

//    ed::Config config;
//    config.SettingsFile = "Simple.json";
//    g_Context = ed::CreateEditor(&config);
}

//--------------------------------------------------------------
void ofApp::exit(){

ed::DestroyEditor(g_Context);

}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.begin();


    {


        



    }


    gui.end();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}


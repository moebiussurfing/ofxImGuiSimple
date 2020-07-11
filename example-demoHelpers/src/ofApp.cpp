#include "ofApp.h"
#include "imgui.h"
#include "Helpers.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);

	gui.setup();

	params.setName("myOfParameterGroup");
	params.add(shapeType.set("shape", 1, 1, 2));
	params.add(numShapes.set("num squares", 1, 1, 24));
	params.add(separation.set("separation", 5, 1, 100));
	params.add(shapeSide.set("square side", 50, 5, 200));
	paramsNested.setName("style");
	paramsNested.add(fill.set("fill", false));
	paramsNested.add(color.set("color", ofColor(0, 0), ofColor(0, 0), ofColor(1, 1)));
	paramsNested.add(lineWidth.set("lineWidth", 1, 0.1, 10));
	params.add(paramsNested);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofVec2f pos(100, 100);

	gui.begin();
	{
		auto mainSettings = ofxImGui::Settings();
		mainSettings.windowPos = pos;
		ImGui::SetNextWindowPos(ofVec2f(pos.x, pos.y));

		ofxImGui::AddParameter(fill);
		ofxImGui::AddParameter(numShapes);

		ofxImGui::AddGroup(params, mainSettings);
	}
	gui.end();
}

//--------------------------------------------------------------
void ofApp::exit() {

	//gui.ex
}
	
//ImGui::ShowDemoWindow();

//string _name = "name";
//bool _collapse = true;
//if (ofxImGui::BeginWindow(_name, mainSettings, _collapse))
//{
//	ofxImGui::AddGroup(params, mainSettings);
//	
//	if (ImGui::TreeNode("TEST Helpers"))
//	{
//		ofxImGui::AddParameter(numShapes);
//		ofxImGui::AddGroup(params, mainSettings);
//		ImGui::TreePop();
//	}
//}
//ofxImGui::EndWindow(mainSettings);
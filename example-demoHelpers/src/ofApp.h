#pragma once

#include "ofMain.h"

#include "ofxImGuiSimple.h"

#include "Helpers.h"
#include "imgui.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void draw();
	void exit();

	ofxImGui::ofxImGuiSimple gui;

	ofParameterGroup params;
	ofParameterGroup paramsNested;
	ofParameter<bool> fill;
	ofParameter<float> lineWidth;
	ofParameter<ofFloatColor> color;
	ofParameter<int> shapeType;
	ofParameter<int> numShapes;
	ofParameter<int> separation;
	ofParameter<int> shapeSide;

	float floatValue;

	bool b;


};

#pragma once

#include "ofMain.h"
#include "ofxImGuiSimple.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void draw();
	void exit();

	ofxImGuiSimple gui;

	ofParameterGroup params;
	ofParameterGroup paramsNested;
	ofParameter<bool> fill;
	ofParameter<float> lineWidth;
	ofParameter<ofFloatColor> color;
	ofParameter<int> shapeType;
	ofParameter<int> numShapes;
	ofParameter<int> separation;
	ofParameter<int> shapeSide;
};

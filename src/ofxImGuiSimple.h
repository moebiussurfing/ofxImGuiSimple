//
//  ofxImGuiSimple.h
//  example-basic
//
//  Created by Eduard Frigola Bagué on 06/04/2020.
//

#ifndef ofxImGuiSimple_h
#define ofxImGuiSimple_h

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_opengl2.h"
#include <stdio.h>

class ofAppBaseWindow;

//TODO:
namespace ofxImGui {

	class ofxImGuiSimple {
	public:
		ofxImGuiSimple() {};
		~ofxImGuiSimple() {};

		void setup(ofAppBaseWindow* win = nullptr);

		void begin();
		void end();

		void draw() {};

	private:
		bool isProgramableRenderer;


		//TODO:
		//void exit(ofEventArgs& args);
		//bool mousePressed[5] = { false };
		ImGuiContext* context;
	};
}

#endif /* ofxImGuiSimple_h */

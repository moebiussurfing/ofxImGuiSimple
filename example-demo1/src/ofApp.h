#pragma once

#include "ofMain.h"
#include "ofxImGuiSimple.h"
#include "imnodes.h"

//#include "save_load.cpp"
#include "color_node_editor.cpp"

class ofApp : public ofBaseApp{

public:

//    example::SaveLoadEditor example;
    
    example::ColorNodeEditor example;

    void setup();
    void update();
    void draw();
    void exit();
    void keyPressed(int key);

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
//
//    void show3()
//    {
//        ImGui::Begin("simple node editor");
//
//        // calling this function creates an empty workspace for the nodes
//        imnodes::BeginNodeEditor();
//
//        imnodes::BeginNode(11);
//
//        imnodes::Style& style = imnodes::GetStyle();
//        style.colors[imnodes::ColorStyle_TitleBar] = IM_COL32(232, 27, 86, 255);
//        style.colors[imnodes::ColorStyle_TitleBarSelected] = IM_COL32(241, 108, 146, 255);
//
////        // set the titlebar color of an individual node
////        imnodes::PushColorStyle(
////                                imnodes::ColorStyle_TitleBar, IM_COL32(200, 109, 0, 255));
////        imnodes::PushColorStyle(
////                                imnodes::ColorStyle_TitleBarSelected, IM_COL32(200, 148, 0, 255));
//
//
//
//        imnodes::BeginNodeTitleBar();
//        ImGui::TextUnformatted("simple node");
//        imnodes::EndNodeTitleBar();
//
//
//
////        imnodes::Name("simple node"); // give the node a name in the title bar
//
//        for (int i = 1; i<=8; i++)
//        {
//            imnodes::BeginInputAttribute(i);
//            string str = "input "+ofToString(i);
//            ImGui::Text(str.c_str());
//            imnodes::EndAttribute();
//        }
//
//        imnodes::BeginOutputAttribute(33);
//        ImGui::Indent(40);  // Push the text label to the right side.
//
//        // At the moment UI elements dont't get
//        // aligned automatically within the nodes.
//        ImGui::Text("output");
//        imnodes::EndAttribute();
//
//
//
////        imnodes::PopColorStyle();
////        imnodes::PopColorStyle();
//
//
//
//        imnodes::EndNode();
//        imnodes::EndNodeEditor();
//
//        ImGui::End();
//    }


//    void show2()
//    {
//        const float node_width = 150.f;
//        imnodes::BeginNode(node.production_fn_node);
//
//        imnodes::BeginNodeTitleBar();
//        ImGui::TextUnformatted("Repeat split");
//        imnodes::EndNodeTitleBar();
//
//        imnodes::BeginInputAttribute(node.predecessor_node);
//        ImGui::Text("predecessor");
//        imnodes::EndAttribute();
//
//        ImGui::BeginGroup();
//        {
//            // This is the first attribute without a pin! 👇
//            // axis_label_widget() just calls ImGui::RadioButton()
//            axis_label_widget(
//                              "dir", grammar.node(node.production_fn_node).body.repeat_split.direction);
//        }
//        {
//            // And here's the second attribute without a pin 👇
//            const float label_width = ImGui::CalcTextSize("count").x;
//            ImGui::Text("count");
//            ImGui::SameLine();
//            ImGui::PushItemWidth(node_width - label_width - 2.f * node_padding);
//            ImGui::DragInt(
//                           "##hidelabel",
//                           &grammar.node(node.production_fn_node).body.repeat_split.num_splits,
//                           0.2f, // speed
//                           1,    // min value
//                           20);  // max value
//            ImGui::PopItemWidth();
//        }
//        ImGui::EndGroup();
//        if (ImGui::IsItemActive())
//        {
//            node_modified = node.production_fn_node;
//        }
//
//        {
//            const float label_width = ImGui::CalcTextSize("successors").x;
//            imnodes::BeginOutputAttribute(node.successor_nodes[0]);
//            ImGui::Indent(node_padding + node_width - label_width);
//            ImGui::Text("successors");
//            imnodes::EndAttribute();
//        }
//
//        imnodes::EndNode();
//    }

};

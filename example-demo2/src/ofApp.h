#pragma once

#include "ofMain.h"
#include "ofxImGuiSimple.h"
#include "ImNodes.h"
#include "ImNodesEz.h"
//#include "sample.cpp"

class ofApp : public ofBaseApp{
    
public:
//    sample mySample;


    bool expanded = true;
    ofRectangle guiRect{100,100,200,400};

    ofParameterGroup params{"params"};
    ofParameter<bool> enable{"enable", false};
    ofParameter<float> value1{"value1", 0.5,0,1};
    ofParameter<float> value2{"value2", 0.5,0,1};
    ofParameter<float> value3{"value3", 0.5,0,1};

    ofParameterGroup getParameters(){return params;};

    bool constructGui(){
        string moduleName = getParameters().getName();
//        ImGui::BeginGroup(); // Lock horizontal position

        bool deleteModule = false;

        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(ImColor(0, 0, 0,0)));

        if(ImGui::ArrowButton("expand", expanded ? ImGuiDir_Down : ImGuiDir_Right)){
            expanded = !expanded;
        }
        ImGui::PopStyleColor();

        ImGui::SameLine();
        ImGui::Text("%s", moduleName.c_str());

        ImGui::SameLine(guiRect.width - 30);
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(ImColor(220,220,220,255)));
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(ImColor(0, 0, 0,0)));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(ImColor(0, 0, 0,0)));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(ImColor(0, 0, 0,0)));

        if (ImGui::Button("x"))
        {
            ImGui::OpenPopup("Delete?");
        }
        ImGui::PopStyleColor(4);

//        if (ImGui::BeginPopupModal("Delete?", NULL, ImGuiWindowFlags_AlwaysAutoResize))
//        {
//            ImGui::Text("%s", (moduleName + "\n").c_str());
//            ImGui::Separator();
//
//            if (ImGui::Button("OK", ImVec2(120,0)) || ImGui::IsKeyDown(ImGui::GetKeyIndex(ImGuiKey_Enter))) {
//                ImGui::CloseCurrentPopup();
//                deleteModule = true;
//            }
//            ImGui::SetItemDefaultFocus();
//            ImGui::SameLine();
//            if (ImGui::Button("Cancel", ImVec2(120,0))) { ImGui::CloseCurrentPopup(); }
//            ImGui::EndPopup();
//        }

//        if(expanded){
//
            ImGui::Spacing();

            auto startPos = ImGui::GetCursorScreenPos();

//            for(int i=0 ; i<getParameters().size(); i++){
//                ofAbstractParameter &absParam = static_cast<ofAbstractParameter&>(getParameters().get(i));

//                ofxOceanodeAbstractParameter &absParam = static_cast<ofxOceanodeAbstractParameter&>(getParameters().get(i));

//                string uniqueId = absParam.getName();
//                ImGui::PushID(uniqueId.c_str());

//                if(absParam.valueType() == typeid(std::function<void()>).name()){
//                    absParam.cast<std::function<void()>>().getParameter().get()();
//                }else
//                {

//                    ImGui::Text("%s", uniqueId.c_str());
//
//                    ImGui::SetItemAllowOverlap();
//                    ImGui::SameLine(-1);
//                    ImGui::InvisibleButton(("##InvBut_" + uniqueId).c_str(), ImVec2(51, ImGui::GetFrameHeight())); //Used to check later behaviours
//
//                    int drag = 0;
//                    bool resetValue = false;
//                    if(ImGui::IsItemActive() && ImGui::IsMouseDragging(0, 0.1f)){
//                        drag = ImGui::GetIO().MouseDelta.x;
//                    }
//                    if(ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)){
//                        resetValue = true;
//                    }else if(ImGui::IsItemClicked(1)){
//                        ImGui::OpenPopup("Param Popup");
//                    }
//
//
//                    ImGui::SameLine(60);
//                    ImGui::SetNextItemWidth(150);

                    string hiddenUniqueId = "##" + uniqueId;
//                    ImGui::PushStyleColor(ImGuiCol_SliderGrab,ImVec4(node.getColor()*0.5f));
//                    ImGui::PushStyleColor(ImGuiCol_SliderGrabActive,ImVec4(node.getColor()*0.5f));
//                    ImGui::PushStyleColor(ImGuiCol_PlotHistogram,ImVec4(node.getColor()*0.5f));
//                    ImGui::PushStyleColor(ImGuiCol_Button,ImVec4(node.getColor()*.25f));
//                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered,ImVec4(node.getColor()*.50f));
//                    ImGui::PushStyleColor(ImGuiCol_ButtonActive,ImVec4(node.getColor()*.75f));


                    // PARAM FLOAT
                    ///////////////
//                    if(absParam.valueType() == typeid(float).name())
                    {
//                        auto tempCast = absParam.cast<float>();

//                        if(drag != 0){
//                            if(ImGui::GetIO().KeyShift) absParam.cast<float>().applyPrecisionDrag(drag);
//                            else if(ImGui::GetIO().KeyAlt) absParam.cast<float>().applySpeedDrag(drag);
//                            else absParam.cast<float>().applyNormalDrag(drag);
//                        }
//
//                        if(resetValue){
//                            tempCast = absParam.cast<float>().getDefaultValue();
//                        }
//
//                        ImGui::SliderFloat(hiddenUniqueId.c_str(), (float *)&tempCast.get(), tempCast.getMin(), tempCast.getMax(), "%.4f");
//
//                        //TODO: Implement better this hack
//                        // Maybe discard and reset value when not presed enter??
//                        if(ImGui::IsItemDeactivated() || (ImGui::IsMouseDown(0) && ImGui::IsItemEdited()) ){
//                            tempCast = ofClamp(tempCast, tempCast.getMin(), tempCast.getMax());
//                        }
//                        if(ImGui::IsItemHovered() && ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Space))){
//                            tempCast = tempCast;
//                        }
//                    }

        //                    // PARAM VECTOR < FLOAT >
//                    /////////////////////////
//                    else if(absParam.valueType() == typeid(vector<float>).name())
//                    {
//                        auto tempCast = absParam.cast<vector<float>>().getParameter();
//                        if(tempCast->size() == 1)
//                        {
//                            if(drag != 0){
//                                if(ImGui::GetIO().KeyShift) absParam.cast<vector<float>>().applyPrecisionDrag(drag);
//                                else if(ImGui::GetIO().KeyAlt) absParam.cast<vector<float>>().applySpeedDrag(drag);
//                                else absParam.cast<vector<float>>().applyNormalDrag(drag);
//                            }
//
//                            if(resetValue){
//                                tempCast = absParam.cast<vector<float>>().getDefaultValue();
//                            }
//
//                            ImGui::SliderFloat(hiddenUniqueId.c_str(),
//                                               (float *)&tempCast->at(0),
//                                               tempCast.getMin()[0],
//                                               tempCast.getMax()[0], "%.4f");
//
//                            if(ImGui::IsItemDeactivated() || (ImGui::IsMouseDown(0) && ImGui::IsItemEdited())){
//                                tempCast = vector<float>(1, ofClamp(tempCast->at(0), tempCast.getMin()[0], tempCast.getMax()[0]));
//                            }
//                        }else{
//                            ImGui::PlotHistogram(hiddenUniqueId.c_str(), tempCast->data(), tempCast->size(), 0, NULL, tempCast.getMin()[0], tempCast.getMax()[0]);
//                        }
//                        if(ImGui::IsItemHovered() && ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Space))){
//                            tempCast = tempCast;
//                        }
//                    }
//                    // PARAM INT
//                    /////////////
//                    else if(absParam.valueType() == typeid(int).name())
//                    {
//                        auto tempCast = absParam.cast<int>().getParameter();
//                        if(absParam.cast<int>().getDropdownOptions().size() == 0)
//                        {
//                            if(drag != 0){
//                                if(ImGui::GetIO().KeyShift) absParam.cast<int>().applyPrecisionDrag(drag);
//                                else if(ImGui::GetIO().KeyAlt) absParam.cast<int>().applySpeedDrag(drag);
//                                else absParam.cast<int>().applyNormalDrag(drag);
//                            }
//
//                            if(resetValue){
//                                tempCast = absParam.cast<int>().getDefaultValue();
//                            }
//
//                            ImGui::SliderInt(hiddenUniqueId.c_str(), (int *)&tempCast.get(),tempCast.getMin(),tempCast.getMax());
//
//                            if(ImGui::IsItemDeactivated() || (ImGui::IsMouseDown(0) && ImGui::IsItemEdited()))
//                                tempCast = tempCast;
//                            if(ImGui::IsItemHovered() && ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Space)))
//                                tempCast = tempCast;
//
//                        }else{
//                            auto vector_getter = [](void* vec, int idx, const char** out_text)
//                            {
//                                auto& vector = *static_cast<std::vector<std::string>*>(vec);
//                                if (idx < 0 || idx >= static_cast<int>(vector.size())) { return false; }
//                                *out_text = vector.at(idx).c_str();
//                                return true;
//                            };
//
//                            vector<string> options = absParam.cast<int>().getDropdownOptions();
//                            if(ImGui::Combo(hiddenUniqueId.c_str(), (int*)&tempCast.get(), vector_getter, static_cast<void*>(&options), options.size()))
//                                tempCast = ofClamp(tempCast, tempCast.getMin(), tempCast.getMax());
//
//                            if(ImGui::IsItemHovered() && ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Space)))
//                                tempCast = tempCast;
//
//                        }
//                    }
//                    // PARAM VECTOR < INT >
//                    /////////////////////////
//                    else if(absParam.valueType() == typeid(vector<int>).name())
//                    {
//                        auto tempCast = absParam.cast<vector<int>>().getParameter();
//                        if(tempCast->size() == 1)
//                        {
//                            if(drag != 0){
//                                if(ImGui::GetIO().KeyShift) absParam.cast<vector<int>>().applyPrecisionDrag(drag);
//                                else if(ImGui::GetIO().KeyAlt) absParam.cast<vector<int>>().applySpeedDrag(drag);
//                                else absParam.cast<vector<int>>().applyNormalDrag(drag);
//                            }
//
//                            if(resetValue){
//                                tempCast = absParam.cast<vector<int>>().getDefaultValue();
//                            }
//
//                            ImGui::SliderInt(hiddenUniqueId.c_str(), (int *)&tempCast->at(0),tempCast.getMin()[0],tempCast.getMax()[0]);
//
//                            if(ImGui::IsItemDeactivated() || (ImGui::IsMouseDown(0) && ImGui::IsItemEdited())){
//                                tempCast = vector<int>(1, ofClamp(tempCast->at(0), tempCast.getMin()[0], tempCast.getMax()[0]));
//                            }
//                        }
//                        else{
//                            std::vector<float> floatVec(tempCast.get().begin(), tempCast.get().end());
//                            ImGui::PlotHistogram(hiddenUniqueId.c_str(), floatVec.data(), tempCast->size(), 0, NULL, tempCast.getMin()[0], tempCast.getMax()[0]);
//                        }
//                        if(ImGui::IsItemHovered() && ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Space)))
//                            tempCast = tempCast;
//                    }
//                    // PARAM BOOL
//                    /////////////
//                    else if(absParam.valueType() == typeid(bool).name()){
//                        auto tempCast = absParam.cast<bool>().getParameter();
//
//                        if(drag != 0){
//                            absParam.cast<bool>().applyNormalDrag(drag);
//                        }
//
//                        if (ImGui::Checkbox(hiddenUniqueId.c_str(), (bool *)&tempCast.get()))
//                        {
//                            tempCast = tempCast;
//                        }
//                        if(ImGui::IsItemHovered() && ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Space))){
//                            tempCast = !tempCast;
//                        }
//                        // PARAM VOID
//                        /////////////
//                    }else if(absParam.valueType() == typeid(void).name()){
//                        auto tempCast = absParam.cast<void>().getParameter();
//                        if (ImGui::Button(hiddenUniqueId.c_str(), ImVec2(ImGui::GetFrameHeight(), 0)))
//                        {
//                            tempCast.trigger();
//                        }
//                        if(ImGui::IsItemHovered() && ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Space))){
//                            tempCast.trigger();
//                        }
//                        // PARAM STRING
//                        ///////////////
//                    }else if(absParam.valueType() == typeid(string).name()){
//                        auto tempCast = absParam.cast<string>().getParameter();
//                        char * cString = new char[256];
//                        strcpy(cString, tempCast.get().c_str());
//                        auto result = false;
//                        if (ImGui::InputText(hiddenUniqueId.c_str(), cString, 256, ImGuiInputTextFlags_EnterReturnsTrue))
//                        {
//                            tempCast = cString;
//                        }
//                        delete[] cString;
//                        // PARAM CHAR
//                        /////////////
//                    }else if(absParam.valueType() == typeid(char).name()){
//                        ImGui::Dummy(ImVec2(ImGui::GetFrameHeight(), ImGui::GetFrameHeight()));
//                        // PARAM COLOR
//                        //////////////
//                    }else if(absParam.type() == typeid(ofParameter<ofColor>).name()){
//                        auto tempCast = absParam.cast<ofColor>().getParameter();
//                        if(drag != 0){
//                            if(ImGui::GetIO().KeyShift) absParam.cast<ofColor>().applyPrecisionDrag(drag);
//                            else if(ImGui::GetIO().KeyAlt) absParam.cast<ofColor>().applySpeedDrag(drag);
//                            else absParam.cast<ofColor>().applyNormalDrag(drag);
//                        }
//
//                        ofFloatColor floatColor(tempCast.get());
//
//                        if (ImGui::ColorEdit3(hiddenUniqueId.c_str(), &floatColor.r))
//                        {
//                            tempCast = ofColor(floatColor);
//                        }
//                        if(ImGui::IsItemHovered() && ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Space))){
//                            tempCast = tempCast;
//                        }
//                        //PARAM FLOAT COLOR
//                        ///////////////////
//                    }else if(absParam.valueType() == typeid(ofFloatColor).name()){
//                        auto tempCast = absParam.cast<ofFloatColor>().getParameter();
//
//                        if(drag != 0){
//                            if(ImGui::GetIO().KeyShift) absParam.cast<ofFloatColor>().applyPrecisionDrag(drag);
//                            else if(ImGui::GetIO().KeyAlt) absParam.cast<ofFloatColor>().applySpeedDrag(drag);
//                            else absParam.cast<ofFloatColor>().applyNormalDrag(drag);
//                        }
//
//                        if (ImGui::ColorEdit3(hiddenUniqueId.c_str(), (float*)&tempCast.get().r))
//                        {
//                            tempCast = tempCast;
//                        }
//                        if(ImGui::IsItemHovered() && ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Space))){
//                            tempCast = tempCast;
//                        }
//                    }
//                    // UNKNOWN PARAM
//                    ////////////////
//                    else
//                    {
//                        ImGui::Dummy(ImVec2(ImGui::GetFrameHeight(), ImGui::GetFrameHeight()));
//                    }
//
//                    if(ImGui::IsItemClicked(1)){
//                        ImGui::OpenPopup("Param Popup");
//                    }
//
//                    if(ImGui::BeginPopup("Param Popup")){
//                        ImGui::Separator();
//                        if(!absParam.isScoped()){ //Param is not scoped
//                            if(ImGui::Selectable("Add to Scope")){
//                                ofxOceanodeScope::getInstance()->addParameter(&absParam,getColor());
//                            }
//                        }else{
//                            if(ImGui::Selectable("Remove from Scope")){
//                                ofxOceanodeScope::getInstance()->removeParameter(&absParam);
//                            }
//                        }
//                        ImGui::Separator();
//                        if(true){ //Param is not timelined
//                            if(ImGui::Selectable("Add to Timeline")){
//
//                            }
//                        }else{
//                            if(ImGui::Selectable("Remove from Timeline")){
//
//                            }
//                        }
//#ifdef OFXOCEANODE_USE_MIDI
//                        ImGui::Separator();
//                        if(ImGui::Selectable("Bind MIDI")){
//                            container.createMidiBinding(absParam);
//                        }
//                        if(ImGui::Selectable("Unbind last MIDI")){
//                            container.removeLastMidiBinding(absParam);
//                        }
//#endif
//#ifdef OFXOCEANODE_USE_OSC
//                        ImGui::Separator();
//                        ImGui::Text("OSC Address: %s/%s", getParameters().getEscapedName().c_str(), absParam.getEscapedName().c_str());
//#endif
//                        ImGui::Separator();
//                        ImGui::EndPopup();
//                    }
//
//                    inputPositions[uniqueId] = glm::vec2(0, ImGui::GetItemRectMin().y + ImGui::GetItemRectSize().y/2);
//                    outputPositions[uniqueId] = glm::vec2(0, ImGui::GetItemRectMin().y + ImGui::GetItemRectSize().y/2);
//
//                    ImGui::PopStyleColor(6);
//                }
//                ImGui::PopID();
//            } //endFor
//        }else{}

//        ImGui::EndGroup();
//        if(expanded){
//            for(auto &inPos : inputPositions){
//                inPos.second.x = ImGui::GetItemRectMin().x;
//            }
//            for(auto &outPos : outputPositions){
//                outPos.second.x = ImGui::GetItemRectMax().x;
//            }
//        }else{
//            auto numParams = getParameters().size();
//            for(int i=0 ; i < numParams; i++){
//                ofAbstractParameter &absParam = getParameters().get(i);
//                string uniqueId = absParam.getName();
//                float yPos = numParams == 1 ? ImGui::GetItemRectSize().y / 2 : ImGui::GetItemRectSize().y * ((float)i/(numParams-1));
//                inputPositions[uniqueId] = glm::vec2(ImGui::GetItemRectMin().x, ImGui::GetItemRectMin().y + yPos);
//                outputPositions[uniqueId] = glm::vec2(ImGui::GetItemRectMax().x, ImGui::GetItemRectMin().y + yPos);
//            }
        }
//        if(deleteModule){
//            node.deleteSelf();
//            return false;
//        }
        return true;
    }





    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxImGuiSimple gui;


    void drawBasic()
    {
        static ImNodes::CanvasState canvas;

        if (ImGui::Begin("ImNodes", nullptr, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse))
        {
            ImNodes::BeginCanvas(&canvas);

            struct Node
            {
                ImVec2 pos{};
                bool selected{};
                ImNodes::Ez::SlotInfo inputs[1];
                ImNodes::Ez::SlotInfo outputs[1];
            };

            //        static Node nodes[3] = {
            //            {{50, 100}, false, {{"In", 1}}, {{"Out", 1}}},
            //            {{250, 50}, false, {{"In", 1}}, {{"Out", 1}}},
            //            {{250, 100}, false, {{"In", 1}}, {{"Out", 1}}},
            //        };

            static Node nodes[4] ;

            nodes[0].pos = ImVec2(50, 100);
            nodes[0].inputs[0].title = "In";
            nodes[0].inputs[0].kind = 1;
            nodes[0].outputs[0].title = "Out";
            nodes[0].outputs[0].kind = 1;
            nodes[0].selected = false;

            nodes[1].pos = ImVec2(250, 50);
            nodes[1].inputs[0].title = "In";
            nodes[1].inputs[0].kind = 1;
            nodes[1].outputs[0].title = "Out";
            nodes[1].outputs[0].kind = 1;
            nodes[1].selected = false;

            nodes[2].pos = ImVec2(250, 100);
            nodes[2].inputs[0].title = "In";
            nodes[2].inputs[0].kind = 1;
            nodes[2].outputs[0].title = "Out";
            nodes[2].outputs[0].kind = 1;
            nodes[2].selected = false;

            nodes[3].pos = ImVec2(250, 300);
            nodes[3].inputs[0].title = "In";
            nodes[3].inputs[0].kind = 1;
            nodes[3].outputs[0].title = "Out";
            nodes[3].outputs[0].kind = 1;
            nodes[3].selected = false;

            for (Node& node : nodes)
            {
                if (ImNodes::Ez::BeginNode(&node, "Node Title", &node.pos, &node.selected))
                {
                    ImNodes::Ez::InputSlots(node.inputs, 1);
                    ImNodes::Ez::OutputSlots(node.outputs, 1);
                    ImNodes::Ez::EndNode();
                }
            }

            ImNodes::Connection(&nodes[1], "In", &nodes[0], "Out");
            ImNodes::Connection(&nodes[2], "In", &nodes[0], "Out");

            ImNodes::EndCanvas();
        }
        ImGui::End();
    }







    /// A structure defining a connection between two slots of two nodes.
    struct Connection
    {
        /// `id` that was passed to BeginNode() of input node.
        void* input_node = nullptr;
        /// Descriptor of input slot.
        const char* input_slot = nullptr;
        /// `id` that was passed to BeginNode() of output node.
        void* output_node = nullptr;
        /// Descriptor of output slot.
        const char* output_slot = nullptr;

        bool operator==(const Connection& other) const
        {
            return input_node == other.input_node &&
            input_slot == other.input_slot &&
            output_node == other.output_node &&
            output_slot == other.output_slot;
        }

        bool operator!=(const Connection& other) const
        {
            return !operator ==(other);
        }
    };

    enum NodeSlotTypes
    {
        NodeSlotPosition = 1,   // ID can not be 0
        NodeSlotRotation,
        NodeSlotMatrix,
    };

    /// A structure holding node state.
    struct MyNode
    {
        /// Title which will be displayed at the center-top of the node.
        const char* title = nullptr;
        /// Flag indicating that node is selected by the user.
        bool selected = false;
        /// Node position on the canvas.
        ImVec2 pos{};
        /// List of node connections.
        std::vector<Connection> connections{};
        /// A list of input slots current node has.
        std::vector<ImNodes::Ez::SlotInfo> input_slots{};
        /// A list of output slots current node has.
        std::vector<ImNodes::Ez::SlotInfo> output_slots{};

        explicit MyNode(const char* title,
                        const std::vector<ImNodes::Ez::SlotInfo>&& input_slots,
                        const std::vector<ImNodes::Ez::SlotInfo>&& output_slots)
        {
            this->title = title;
            this->input_slots = input_slots;
            this->output_slots = output_slots;
        }

        /// Deletes connection from this node.
        void DeleteConnection(const Connection& connection)
        {
            for (auto it = connections.begin(); it != connections.end(); ++it)
            {
                if (connection == *it)
                {
                    connections.erase(it);
                    break;
                }
            }
        }
    };


//
//    /// Deletes connection from this node.
//    void PrintConnection()
//    {
//        for (auto con: connections)
//        {
//            con.
//        }
//    }


    std::map<std::string, MyNode*(*)()> available_nodes{
        {"Compose", []() -> MyNode* { return new MyNode("Compose", {
            {"Position", NodeSlotPosition}, {"Rotation", NodeSlotRotation}  // Input slots
        }, {
            {"Matrix", NodeSlotMatrix}                                      // Output slots
        }); }},

        {"Decompose", []() -> MyNode* { return new MyNode("Decompose", {
            {"Matrix", NodeSlotMatrix}                                      // Input slots
        }, {
            {"Position", NodeSlotPosition}, {"Rotation", NodeSlotRotation}  // Output slots
        }); }},
    };
    std::vector<MyNode*> nodes;


    void draw2()
    {
        // Canvas must be created after ImGui initializes, because constructor accesses ImGui style to configure default colors.
        static ImNodes::CanvasState canvas{};

        const ImGuiStyle& style = ImGui::GetStyle();
        if (ImGui::Begin("ImNodes", nullptr, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse))
        {
            // We probably need to keep some state, like positions of nodes/slots for rendering connections.
            ImNodes::BeginCanvas(&canvas);
            for (auto it = nodes.begin(); it != nodes.end();)
            {
                MyNode* node = *it;

                // Start rendering node
                if (ImNodes::Ez::BeginNode(node, node->title, &node->pos, &node->selected))
                {
                    // Render input nodes first (order is important)
                    ImNodes::Ez::InputSlots(node->input_slots.data(), node->input_slots.size());

                    // Custom node content may go here
                    ImGui::Text("Content of %s", node->title);

                    // Render output nodes first (order is important)
                    ImNodes::Ez::OutputSlots(node->output_slots.data(), node->output_slots.size());

                    // Store new connections when they are created
                    Connection new_connection;
                    if (ImNodes::GetNewConnection(&new_connection.input_node, &new_connection.input_slot,
                                                  &new_connection.output_node, &new_connection.output_slot))
                    {
                        ((MyNode*) new_connection.input_node)->connections.push_back(new_connection);
                        ((MyNode*) new_connection.output_node)->connections.push_back(new_connection);



//                        new_connection.input_node->
                    }

                    // Render output connections of this node
                    for (const Connection& connection : node->connections)
                    {
                        // Node contains all it's connections (both from output and to input slots). This means that multiple
                        // nodes will have same connection. We render only output connections and ensure that each connection
                        // will be rendered once.
                        if (connection.output_node != node)
                            continue;

                        if (!ImNodes::Connection(connection.input_node, connection.input_slot, connection.output_node,
                                                 connection.output_slot))
                        {
                            // Remove deleted connections
                            ((MyNode*) connection.input_node)->DeleteConnection(connection);
                            ((MyNode*) connection.output_node)->DeleteConnection(connection);
                        }
                    }
                }
                // Node rendering is done. This call will render node background based on size of content inside node.
                ImNodes::Ez::EndNode();

                if (node->selected && ImGui::IsKeyPressedMap(ImGuiKey_Delete))
                {
                    // Deletion order is critical: first we delete connections to us
                    for (auto& connection : node->connections)
                    {
                        if (connection.output_node == node)
                        {
                            ((MyNode*) connection.input_node)->DeleteConnection(connection);
                        }
                        else
                        {
                            ((MyNode*) connection.output_node)->DeleteConnection(connection);
                        }
                    }
                    // Then we delete our own connections, so we don't corrupt the list
                    node->connections.clear();

                    delete node;
                    it = nodes.erase(it);
                }
                else
                    ++it;
            }

            const ImGuiIO& io = ImGui::GetIO();
            if (ImGui::IsMouseReleased(1) && ImGui::IsWindowHovered() && !ImGui::IsMouseDragging(1))
            {
                ImGui::FocusWindow(ImGui::GetCurrentWindow());
                ImGui::OpenPopup("NodesContextMenu");
            }

            if (ImGui::BeginPopup("NodesContextMenu"))
            {
                for (const auto& desc : available_nodes)
                {
                    if (ImGui::MenuItem(desc.first.c_str()))
                    {
                        nodes.push_back(desc.second());
                        ImNodes::AutoPositionNode(nodes.back());
                    }
                }
                ImGui::Separator();
                if (ImGui::MenuItem("Reset Zoom"))
                    canvas.zoom = 1;

                if (ImGui::IsAnyMouseDown() && !ImGui::IsWindowHovered())
                    ImGui::CloseCurrentPopup();
                ImGui::EndPopup();
            }

            ImNodes::EndCanvas();
        }
        ImGui::End();

    }


    
};

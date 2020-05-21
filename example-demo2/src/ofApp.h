#pragma once

#include "ofMain.h"
#include "ofxImGuiSimple.h"
#include "ImNodes.h"
#include "ImNodesEz.h"
//#include "sample.cpp"

class ofApp : public ofBaseApp{
    
public:
//    sample mySample;

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

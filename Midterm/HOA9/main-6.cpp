#include <iostream>
#include <vector>
#include <string>

struct TreeNode {
    char val;
    std::vector<TreeNode*> children;

    TreeNode(char data) : val(data) {}
};

// Helper function to add a child
void addChild(TreeNode* parent, TreeNode* child) {
    if (parent != nullptr && child != nullptr) {
        parent->children.push_back(child);
    }
}

//Traversal function
void preOrder(TreeNode* root) {
    if (!root) return;
    std::cout << root->val << " ";
    for (TreeNode* child : root->children) {
        preOrder(child);
    }
}

void postOrder(TreeNode* root) {
    if (!root) return;
    for (TreeNode* child : root->children) {
        postOrder(child);
    }
    std::cout << root->val << " ";
}

void inOrder(TreeNode* root) {
    if (!root) return;
    if (root->children.empty()) {
        std::cout << root->val << " ";
        return;
    }
    // Traverse first child
    inOrder(root->children[0]);
    // Visit current node
    std::cout << root->val << " ";
    // Traverse remaining children
    for (size_t i = 1; i < root->children.size(); i++) {
        inOrder(root->children[i]);
    }
}

//Search Helper Functions & findData
bool searchPreOrder(TreeNode* root, char key) {
    if (!root) return false;
    if (root->val == key) return true;
    for (TreeNode* child : root->children) {
        if (searchPreOrder(child, key)) return true;
    }
    return false;
}

bool searchPostOrder(TreeNode* root, char key) {
    if (!root) return false;
    for (TreeNode* child : root->children) {
        if (searchPostOrder(child, key)) return true;
    }
    if (root->val == key) return true;
    return false;
}

bool searchInOrder(TreeNode* root, char key) {
    if (!root) return false;
    if (root->children.empty()) return root->val == key;
    if (searchInOrder(root->children[0], key)) return true;
    if (root->val == key) return true;
    for (size_t i = 1; i < root->children.size(); i++) {
        if (searchInOrder(root->children[i], key)) return true;
    }
    return false;
}

void findData(int choice, char key, TreeNode* root) {
    bool found = false;
    switch (choice) {
        case 1: found = searchPreOrder(root, key); break;
        case 2: found = searchPostOrder(root, key); break;
        case 3: found = searchInOrder(root, key); break;
        default: break;
    }
    if (found) {
        std::cout << key << " was found!\n";
    }
}


int main() {
    // Level 0 (Root)
    TreeNode* nodeA = new TreeNode('A');

    // Level 1
    TreeNode* nodeB = new TreeNode('B');
    TreeNode* nodeC = new TreeNode('C');
    TreeNode* nodeD = new TreeNode('D');
    TreeNode* nodeE = new TreeNode('E');
    TreeNode* nodeF = new TreeNode('F');
    TreeNode* nodeG = new TreeNode('G');

    addChild(nodeA, nodeB);
    addChild(nodeA, nodeC);
    addChild(nodeA, nodeD);
    addChild(nodeA, nodeE);
    addChild(nodeA, nodeF);
    addChild(nodeA, nodeG);

    // Level 2 & 3
    TreeNode* nodeH = new TreeNode('H');
    addChild(nodeD, nodeH);

    TreeNode* nodeI = new TreeNode('I');
    TreeNode* nodeJ = new TreeNode('J');
    addChild(nodeE, nodeI);
    addChild(nodeE, nodeJ);

    TreeNode* nodeP = new TreeNode('P');
    TreeNode* nodeQ = new TreeNode('Q');
    addChild(nodeJ, nodeP);
    addChild(nodeJ, nodeQ);

    TreeNode* nodeK = new TreeNode('K');
    TreeNode* nodeL = new TreeNode('L');
    TreeNode* nodeM = new TreeNode('M');
    addChild(nodeF, nodeK);
    addChild(nodeF, nodeL);
    addChild(nodeF, nodeM);

    TreeNode* nodeN = new TreeNode('N');
    addChild(nodeG, nodeN);

    std::cout << "General Tree initialized successfully.\n";

    // Printing traversals to console
    std::cout << "Pre-order:  ";
    preOrder(nodeA);
    std::cout << "\n";

    std::cout << "Post-order: ";
    postOrder(nodeA);
    std::cout << "\n";

    std::cout << "In-order:   ";
    inOrder(nodeA);
    std::cout << "\n";

    //findData Demonstrations
    std::cout << "findData Execution\n";
    findData(1, 'J', nodeA); // Choice 1: Pre-order
    findData(2, 'Q', nodeA); // Choice 2: Post-order
    findData(3, 'Z', nodeA); // Choice 3: Non-existent key (no print)

    //Insert Node 'O' under Node 'G'
    std::cout << "Insert 'O' under 'G' & Test\n";
    TreeNode* nodeO = new TreeNode('O');
    addChild(nodeG, nodeO);

    // Search for newly inserted node 'O' using In-order
    findData(3, 'O', nodeA);

    // Verify placement in traversal
    std::cout << "Updated Pre-order: ";
    preOrder(nodeA);

    return 0;
}
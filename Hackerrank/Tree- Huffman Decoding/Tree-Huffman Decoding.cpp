
// Function to decode the string
void decode_huff(node * root, string s) {
    node* temp = root;
    for (char c : s) {
        temp = c == '0' ? temp->left : temp->right;
        if (temp->data) {
            // found a new character in the decoded string
            cout << temp->data;
            //  move the temp pointer to the root again
            temp = root;
        }
    }
}

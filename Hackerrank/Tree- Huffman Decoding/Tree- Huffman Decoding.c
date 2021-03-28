
//C program for Tree- Huffman Decoding

/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root, string s) {
    //create a new node temp
   node* temp = root;
    for (char c : s) {
        //if c is 0 then temp->left else temp->right
        temp = c == '0' ? temp->left : temp->right;
        if (temp->data) {
            //print result
            cout << temp->data;
            temp = root;
        }
    }
}


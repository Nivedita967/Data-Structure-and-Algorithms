public void decode(String S, Node root)
{
    // create a StringBuilder (mutable String)
    StringBuilder output = new StringBuilder();
    // copy root node to c
    Node c = root;
    for (int i = 0; i < S.length(); i++) {
        // if S.charAt(i) == '1' then c = c.right else c = c.left
        c = S.charAt(i) == '1' ? c.right : c.left;
        // if c is leaf node
        if (c.left == null && c.right == null) {
            // found a new character in the decoded string: append data of c to the output
            output.append(c.data);
            //  move the current pointer to the root again
            c = root;
        }
    }
    // Print the output
    System.out.print(output);
}

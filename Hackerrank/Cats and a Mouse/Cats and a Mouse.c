char* catAndMouse(int x, int y, int z) {
    int a = x - z;                           // Calculating length to be travelled by both the cats
    int b = y - z;
    if (a < 0) a *= -1;                      // Converting length to positive if it is negative
    if (b < 0) b *= -1;
    if (a == b) return "Mouse C";            // Printing result
    else if (a > b) return "Cat B";
    else return "Cat A";
}
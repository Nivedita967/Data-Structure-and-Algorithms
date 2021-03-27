static String catAndMouse(int x, int y, int z) {
        //uses ternary operator -- shorter version of if-else statement
        //simply compare the values and return the answer
        return Math.abs(x-z)<Math.abs(y-z) ? "Cat A" : 
            Math.abs(y-z)<Math.abs(x-z) ? "Cat B" : "Mouse C";

    }
// ----- ----- Class 1: DemoTranslation ----- -----

import java.util.Scanner;
import java.util.stream.Stream;

public class DemoTranslation {
	public final static int MAX_HEIGHT = 41;

	public static int getVolume(Box b) {
		return b.getLength() * b.getWidth() * b.getHeight(); //calculate volume
	}

	public static boolean isLowerThanMaxHeight(Box b) {
		/**
		 * Return 1 if the box's height is lower than MAX_HEIGHT and 0 otherwise
		 */
		if(b.getHeight() < MAX_HEIGHT) {
			return true;
		} else {
			return false;
		}
	}

	public static void main(String[] args) {
		int n;
		n = STDIN_SCANNER.nextInt(); //take input

		Box[] boxes = Stream.generate(() -> new Box()).limit(n).toArray(Box[]::new);
		for(int i = 0; i < n; i++) { //take input for height,length and width
			boxes[i].setLength(STDIN_SCANNER.nextInt());
			boxes[i].setWidth(STDIN_SCANNER.nextInt());
			boxes[i].setHeight(STDIN_SCANNER.nextInt());
		}
		for(int i = 0; i < n; i++) {
			if(isLowerThanMaxHeight(boxes[i])) {
				System.out.println(getVolume(boxes[i]));
			}
		}
	}

	public final static Scanner STDIN_SCANNER = new Scanner(System.in);
}


// ----- ----- Class 2: Box ----- -----

import com.mtsystems.coot.IntContainer;
import com.mtsystems.coot.NativeClass;

public class Box extends NativeClass {
	private final IntContainer length = new IntContainer(this, 1);

	private final IntContainer width = new IntContainer(this, 1);

	private final IntContainer height = new IntContainer(this, 1);

	public int getLength() {
		return length.get();
	}

	public int setLength(int newLength) {
		return length.set(newLength);
	}

	public int getWidth() {
		return width.get();
	}

	public int setWidth(int newWidth) {
		return width.set(newWidth);
	}

	public int getHeight() {
		return height.get();
	}

	public int setHeight(int newHeight) {
		return height.set(newHeight);
	}
}
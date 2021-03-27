import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // driver code already given on hackerrank platform
    static class SinglyLinkedListNode {
        public int data;
        public SinglyLinkedListNode next;

        public SinglyLinkedListNode(int nodeData) {
            this.data = nodeData;
            this.next = null;
        }
    }

    static class SinglyLinkedList {
        public SinglyLinkedListNode head;
        public SinglyLinkedListNode tail;

        public SinglyLinkedList() {
            this.head = null;
            this.tail = null;
        }

        public void insertNode(int nodeData) {
            SinglyLinkedListNode node = new SinglyLinkedListNode(nodeData);

            if (this.head == null) {
                this.head = node;
            } else {
                this.tail.next = node;
            }

            this.tail = node;
        }
    }

    public static void printSinglyLinkedList(SinglyLinkedListNode node, String sep, BufferedWriter bufferedWriter) throws IOException {
        while (node != null) {
            bufferedWriter.write(String.valueOf(node.data));

            node = node.next;

            if (node != null) {
                bufferedWriter.write(sep);
            }
        }
    }

    // Complete the hasCycle function below.

    /*
     * For your reference:
     *
     * SinglyLinkedListNode {
     *     int data;
     *     SinglyLinkedListNode next;
     * }
     *
     */

    static boolean hasCycle(SinglyLinkedListNode head) {

        // using two pointer method : slow pointer(ptr1) & fast pointer(ptr2)
        SinglyLinkedListNode ptr1=head;
        SinglyLinkedListNode ptr2=head;

        // if at some point my slow pointer and fast pointer becomes the same , we can say cycle exists else the cycle don't exist
        while(ptr1!=null && ptr2!=null && ptr1.next!=null){
            ptr1=ptr1.next.next;
            ptr2=ptr2.next;
            if(ptr1==ptr2){
                return true;
            }
        }
        return false;
    }

    private static final Scanner scanner = new Scanner(System.in);
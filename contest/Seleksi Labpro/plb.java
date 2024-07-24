import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class Util {
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd (b, a % b);
        }
    }
}

class LinkedList {
    private Node head;

    public void addFirst(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    public void addLast(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
    }

    public void delete(int data) {
        if (head == null) return;

        if (head.data == data) {
            head = head.next;
            return;
        }

        Node current = head;
        while (current.next != null && current.next.data != data) {
            current = current.next;
        }

        if (current.next != null) {
            current.next = current.next.next;
        }
    }

    public void printList() {
        Node current = head;
        System.out.print("[");
        while (current != null) {
            System.out.print(current.data);
            current = current.next;
            if (current != null) {
                System.out.print(", ");
            }
        }
        System.out.print("]");
    }
}

public class plb {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        LinkedList list = new LinkedList();
        List<Integer> arr = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int curr = input.nextInt();
            arr.add(curr);
        }

        list.addFirst(arr.get(n - 1));

        for (int i = n - 2; i >= 0; i--) {
            int fpb = Util.gcd(arr.get(i), arr.get(i + 1));
            list.addFirst(fpb);
            list.addFirst(arr.get(i));
        }

        list.printList();
        input.close();
    }
}
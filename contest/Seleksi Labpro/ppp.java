import java.util.Scanner;

class Node {
    int data;
    Node next;
    Node prev;

    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class CircularLinkedList {
    private Node head;

    public void addFirst(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            head.next = head;
            head.prev = head;
        } else {
            Node tail = head.prev;
            newNode.next = head;
            newNode.prev = tail;
            head.prev = newNode;
            tail.next = newNode;
            head = newNode;
        }
    }

    public void addLast(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            head.next = head;
            head.prev = head;
        } else {
            Node tail = head.prev;
            newNode.next = head;
            newNode.prev = tail;
            tail.next = newNode;
            head.prev = newNode;
        }
    }

    public boolean isEmpty() {
        return head == null;
    }

    public boolean isOneElmt() {
        return head.next == head && head.prev == head;
    }

    public void putar(int n, int k) {
        Node curr = head;

        while (!isOneElmt()) {
            for (int i = 0; i < k - 1; i++) {
                curr = curr.next;
            }
            Node prev = curr.prev;
            Node next = curr.next;
            prev.next = next;
            next.prev = prev;
            System.out.println(curr.data);
            curr = next;
            head = curr;
        }

        System.out.println("Survivor: " + curr.data);
    }
}

public class ppp {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int k = input.nextInt();

        CircularLinkedList list = new CircularLinkedList();
        for (int i = 1; i <= n; i++) {
            list.addLast(i);
        }
        list.putar(n, k);

        input.close();
    }
}

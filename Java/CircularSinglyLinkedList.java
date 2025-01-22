public class CircularSinglyLinkedList {
    Node tail;

    CircularSinglyLinkedList(){
        tail= null;
    }

    public boolean isEmpty(){
        return tail == null;
    }

    public int Size(){
        int cnt = 0;
        Node tmp = tail.Next;
        do{
            cnt++;
            tmp = tmp.Next;
        }while(tmp != tail.Next);
        return cnt;
    };

    public void addToHead(int value){
        Node newNode = new Node(value);
        if(tail != null) {
            newNode.Next = tail.Next;
            tail.Next = newNode;
        }
        else{
            newNode.Next = newNode;
            tail = newNode;

        }
    }

    public void addToTail(int value){
        Node newNode = new Node(value);
        if(!isEmpty()){
            newNode.Next = tail.Next;
            tail.Next = newNode;
            tail = newNode;
        }
        else{
            newNode.Next = newNode;
            tail = newNode;
        }
    };

    public void addToPosition(int value , int pos){
        if(pos <= 1) {
            addToHead(value);
            return;
        }

        if(pos > this.Size()) {
            addToTail(value);
            return;
        }

        int cnt = 1;
        Node tmp = tail.Next;
        while(tmp != tail && cnt < pos -1){
            tmp = tmp.Next;
            cnt++;
        }
        tmp.Next = new Node(value,tmp.Next,null);
        /*
        * Node n = new Node(value);
        * n.Next = tmp.next;
        * tmp.next = n;
        * */


    }

    public void deleteFromHead(){
        tail.Next = tail.Next.Next;
    }

    public void deleteFromTail(){
        Node tmp = tail.Next;
        while(tmp.Next != tail){
            tmp = tmp.Next;
        }
        tmp.Next = tail.Next;
        tail = tmp;
    }

    public void deletePosistion(int pos){
        if(pos <= 1) {
            deleteFromHead();
            return;
        }

        if(pos > this.Size()){
            deleteFromTail();
            return;
        }

        Node tmp = tail.Next;
        int cnt = 1;
        while(tmp != tail && cnt < pos -1){
            tmp = tmp.Next;
            cnt++;
        }
        tmp.Next = tmp.Next.Next;
    }

    public void Reverse(){
        if(!isEmpty()) {
            Node prev = null;
            Node current = tail.Next;
            Node next;

            do {
                next = current.Next;
                current.Next = prev;
                prev = current;
                current = next;
            } while (current != tail.Next);
            tail.Next = prev;
            tail = current;

        }
    }

    public void Print(){
        Node tmp = tail.Next;
        do{
            System.out.println(tmp.value);
            tmp = tmp.Next;
        }while(tmp != tail.Next);
    }
}

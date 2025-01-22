public class SinglyLinkedList {
    private Node head;
    private Node tail;

    SinglyLinkedList(){
        head =null;
        tail = null;
    }
    public Node GetHead(){return this.head;}
    public Node GetTail(){return this.tail;}
    public void addToHead(Object value){
        Node newNode = new Node(value);
        if(head != null) {
            newNode.Next = head;
            head = newNode;
        }
        else{
            head = tail=newNode;
        }
    };

    public void addToTail(Object value){
        Node newNode = new Node(value);
        if(tail != null){
            tail.Next = newNode;
            tail = newNode;
        }
        else {
            tail = head = newNode;
        }
    };
    public boolean ISEmpty(){
        return head == null;
    }
    public boolean IsInList(Object value){
        Node tmp = head;
        while(tmp != null){
            if(tmp.value.equals(value))
                return true;
            tmp = tmp.Next;
        }
        return false;
    };
    public int Size(){
        int cnt = 0;
        Node tmp = head;
        while(tmp != null){
            cnt++;
            tmp = tmp.Next;
        }
        return cnt;
    };
    public void deleteFromHead(){
        if(!ISEmpty()){
            if(head ==tail) head = tail = null;
            else head = head.Next;
        }
    };
    public void deleteFromTail(){
        if(!ISEmpty()){
            if(head ==tail) head = tail = null;
            else {
                Node temp = head;
                while(temp.Next != tail){
                    temp =temp.Next;
                }
                tail = temp;
                tail.Next = null;
            }
        }
    };
    public void deleteNode(Object value) throws Exception {
        if(!ISEmpty()){
            if(head == tail && head.value.equals(value)) {
                head = tail = null;
                return;
            }

            if(head.value.equals(value)) {
                deleteFromHead();
                return;
            }

            Node tmp = head;
            while (tmp.Next != null && !tmp.Next.value.equals(value) )
                tmp = tmp.Next;
            if(tmp.Next != null) tmp.Next = tmp.Next.Next;
            else throw new Exception("Null Ptr Exception,element not found");
        }
    };

    public void Insert(Object value ,  int position) throws Exception {
        if(position <= 1) {
            addToHead(value);
            return;
        }
        else if(position > this.Size()+1 ){
            addToTail(value);
            return;
        }

        Node tmp = head;
        Node n = new Node(value);

        int idx = 1;
        while( idx < position -1 && tmp != null){
            tmp = tmp.Next;
            idx++;
        }
        if(tmp != null){
            n.Next = tmp.Next;
            tmp.Next = n;
        }
        else throw new Exception("Null Ptr Exception , Value is invalid or missing");

    }

    public void reverse() {
        Node prev = null;
        Node current = head; 
        Node next = null;

        while (current != null) {
            next = current.Next;
            current.Next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }
    public void Print(){
        Node tmp =head;
        while(tmp != null){
            System.out.println(tmp.value);
            tmp = tmp.Next;
        }
    };

}

public class DoublyLinkedList {
    private Node Head;
    private Node tail;

    DoublyLinkedList(){
        Head = null ; tail = null;
    }

    public boolean isEmpty(){
        return Head == null;
    }
    public void AddToTail(Object value){
        Node n = new Node(value,null,tail);
        if(!isEmpty()){
            tail = n;
            tail.Previous.Next = tail;
            /*
             Node n = new Node(value);

            * n.Previous = tail;
            * tail.next = n;
            * tail = n;
            * */
        }
        else Head = tail = n;
    }
    public int Size(){
        int cnt = 0;
        Node tmp = Head;
        while(tmp != null){
            cnt++;
            tmp = tmp.Next;
        }
        return cnt;
    };
    public void AddToHead(Object value){
        Node n = new Node(value,Head,null);
        if(!isEmpty()){
            Head = n;
            Head.Next.Previous = Head;
            /*
            Node n = new Node(value);
            n.next = head;
            n.Previous = null;
            head.Previous = n;
            head = n;
            * */
        }
        else Head = tail = n;
    }

    public void AddToPosition(Object value , int pos) throws Exception {
        if(pos <= 1) {
            this.AddToHead(value);
            return;
        }

        if(pos >= this.Size()){
            this.AddToTail(value);
            return;
        }
        int cnt = 1;
        Node tmp = Head;
        while(tmp != null && cnt < pos -1){
            tmp = tmp.Next;
            cnt++;
        }
        Node n = new Node(value,tmp.Next,tmp);
        tmp.Next.Previous = n;
        tmp.Next = n;

    }

    public void DeleteFromTail(){
        if(!isEmpty()){
            if(Head == tail){
                Head = tail = null;
                return;
            }
//            tail = tail.Previous;
//            tail.Next = null;
            tail.Previous.Next = null;
        }
    }

    public void DeleteFromHead(){
        Head = Head.Next;
        Head.Previous = null;
    }

    public void DeleteFromPosition(int pos){
        if(pos <= 1) {
            DeleteFromHead();
            return;
        }

        if(pos >= this.Size()){
            DeleteFromTail();
            return;
        }

        Node tmp = Head;
        int cnt = 1;
        while(tmp != null && cnt < pos -1){
            tmp = tmp.Next;
            cnt++;
        }
        tmp.Next.Next.Previous = tmp;
        tmp.Next = tmp.Next.Next;
    }

    public void Reverse(){
        // Tow-Pointers approach O(n/2)
        int l =0, r = 0;
        Node L = Head , R = tail;
        while(l<=r){
            Object tmp = L.value;
            L.value = R.value;
            R.value = tmp;
            l++;
            r--;
            L = L.Next;
            R = R.Previous;
        }
    }

    public void Print(){
        Node tmp =Head;
        while(tmp != null){
            System.out.println(tmp.value);
            tmp = tmp.Next;
        }
    }
}

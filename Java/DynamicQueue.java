public class DynamicQueue {
    Node Front , Rear;
    int size;

    DynamicQueue(){
        Front = Rear = null;
        size = 0;
    }

    public boolean isEmpty(){
        return Front == null;
    }
    public void Enqueue(Object value){
        Node n = new Node(value);
        size++;
        if(!isEmpty()){
            Rear.Next = n;
            Rear = n;
            return;
        }
        Front = Rear = n;
    }

    public void Dequeue() throws Exception {
        size--;
        if(!isEmpty()){
            Front = Front.Next;
            return;
        }
        throw new Exception("Sigmentation Fault: Queue is Empty");

    }

    public Object Front() throws Exception{
        if(!isEmpty()) return Front.value;

        throw new Exception("Sigmentation Fault: Queue is Empty");
    }

    public int size(){return this.size;}


}

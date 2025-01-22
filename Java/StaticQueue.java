public class StaticQueue {
    private Object arr[];
    private int front;
    private int rear;
    private int size;
    private int cap;

    StaticQueue(int cap){
        this.cap = cap;
        front =0;rear=-1;
        size=0;
        arr = new Object[cap];
    }

    public boolean isFull(){
        return size == cap;
    }
    public boolean isEmpty(){return rear==-1;}
    public void Enqueue(Object value) throws Exception {
        if(!isFull()) {
            size++;
            arr[++rear] = value;
            return;
        }
        throw new Exception("Queue OverFlow");
    }

    public void Dequeue() throws Exception{
        if(!isEmpty()){
            
        }
    }
}

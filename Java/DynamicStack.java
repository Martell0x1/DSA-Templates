public class DynamicStack extends SinglyLinkedList{
    private int count;
    public DynamicStack(){count=-1;}

    public boolean isEmpty() {return count==-1;}
    public int size(){return count+1;}
    public void push(Object v){
        addToHead(v);
        count++;
    }
    public void pop(){
        if(!isEmpty()){
            deleteFromHead();
            count--;
        }
    }

    public Object top(){
        return super.GetHead().value;
    }


}

import java.util.Vector;

public class MinHeap {
    private Vector<Integer> heap;
    MinHeap(){
        heap = new Vector<>();
    }
    private int Parent(int pos){
        return pos == 0 ? -1: (pos-1)/2;
    }
    private int Left(int pos){
        int p = 2* pos +1;
        return p>= heap.size() ? -1:p;
    }
    private int Right(int pos){
        int p = 2*pos+2;
        return p >= heap.size() ? -1:p;
    }
    private void HeapifyUp(int pos){
        if(pos == 0 || heap.get(Parent(pos)) < heap.get(pos))
            return;
        int tmp = heap.get(Parent(pos));
        heap.set(Parent(pos),heap.get(pos));
        heap.set(pos,tmp);

        HeapifyUp(Parent(pos));
    }
    private void HeapifyDown(int pos){
       int leftChild =Left(pos);
       if(leftChild == -1 ) return;
       int rightChild = Right(pos);

       if(rightChild != -1 && heap.get(rightChild) < heap.get(leftChild))
           leftChild = rightChild;

       if(heap.get(pos) > heap.get(leftChild)){
           int tmp = heap.get(pos);
           heap.set(pos,heap.get(leftChild));
           heap.set(leftChild,tmp);
           HeapifyDown(leftChild);
       }
    }
    public void Push(int value){
        heap.add(value);
        HeapifyUp(heap.size()-1);
    }
    public void Pop(){
        if(!heap.isEmpty()){
            heap.set(0,heap.getLast());
            heap.removeLast();
            HeapifyDown(0);
        }
    }
    public boolean isEmpty(){
        return heap.isEmpty();
    }
    public int Top(){
        return heap.size() > 0 ? heap.get(0):-1;
    }
}

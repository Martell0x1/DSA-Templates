public class Node {
     Object value;
     Node Next;
     Node Previous;

    Node(){
        value = 0;Next=null;Previous=null;
    }
    Node(Object value ,  Node n , Node p){
        this.value =value;
        this.Next =n;
        this.Previous = p;
    }

    Node(Object value){
        this.value = value;
        Next = null;
        Previous = null;
    }
}

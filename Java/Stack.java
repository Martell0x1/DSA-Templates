public class Stack {
    int top = -1;
    int s = 0;
    Object[] arr;

    Stack(int s){
        this.s = s;
        this.arr = new Object[s];

    }
    public boolean isEmpty(){
        return top == -1;
    }
    public void push(Object value){
        if(top != s+1)
            arr[++top] = value;
    }

    public Object top(){
        return (!isEmpty())? arr[top]:-1 ;
    }

    public void pop(){
        if(!isEmpty())
            top--;
    }

    public void print(){
        for(int x = top ; x>= 0 ; x--) System.out.println(arr[x]);
    }


    public int size(){return top+1;}

}

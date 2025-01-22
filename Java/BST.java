public class BST {
    TNode root;
    DynamicQueue visited ;
    BST(){
        this.root = null;
        visited = new DynamicQueue();
    }

    private void visit(TNode node) {
        visited.Enqueue(node.data);
    }

    private Boolean isLeaf(TNode node){
        return node.left == null && node.right == null;
    }
    public void inorder(TNode node){
        if(node.left != null) inorder(node.left);
        visit(node);
        if(node.right != null) inorder(node.right);
    }
    public void preorder(TNode node){
        visit(node);
        if(node.left != null) inorder(node.left);
        if(node.right != null) inorder(node.right);
    }

    public void postorder(TNode node){
        if(node.left != null) inorder(node.left);
        if(node.right != null) inorder(node.right);
        visit(node);
    }

    public int size(TNode node){
        if(node == null) return 0;
        else if(isLeaf(node)) return 1;
        else if ( node.left == null ) { return (1+size(node.right)); }
        else if ( node.right == null) { return (1+size(node.left)); }
        return 1+size(node.left) + size(node.right);
    }

    public int hieght(TNode node){
        if(node == null) return -1;
        else if(isLeaf(node)) return 1;
        else if ( node.left == null ) { return (1+hieght(node.right)); }
        else if ( node.right == null) { return (1+hieght(node.left)); }

        return Math.max(hieght(node.left),hieght(node.right))+1;
    }

    public boolean find(Object value){
        TNode tmp = root;
        while(tmp != null){
            int cmp = ((Comparable) value).compareTo(tmp.data);
            if(cmp <0) tmp = tmp.left; // value < data
            else if(cmp >0) tmp=tmp.right; // value > data
            else return true; // value == data
        }
        return false;
    }

    public void insert(Object value){
        TNode tmp = root;
        TNode newNode = new TNode(value);
        TNode Parent = null;

        if(tmp == null){
            root = newNode;
            return;
        }
        while(tmp != null){
            Parent = tmp;
            int cmp = ((Comparable) value).compareTo(tmp.data);
            if(cmp <0) tmp = tmp.left;
            else if(cmp > 0) tmp = tmp.right;
            else return;
        }
        int cmp = ((Comparable) value).compareTo(Parent.data);
        if(cmp < 0) Parent.left=newNode;
        else Parent.right = newNode;
    }

    public void delete(Object value){
        TNode tmp = root;
        TNode parent = null;
        TNode node = new TNode(value);
        boolean ok = find(node);
        if(ok){
        }
        else throw new RuntimeException("Fuck you");

    }

    

}

import java.util.ArrayList;

class Main {
    public static void main(String[] args) throws Exception {
        int[] arr = {5,6,7,2,3,0};
        Sortings.MergeSort(arr,0,arr.length-1);
        for(int x : arr) System.out.println(x);
    }
}

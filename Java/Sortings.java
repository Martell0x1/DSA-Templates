public class Sortings {
    public static void SelectionSort(int arr[]){
        for(int x = 0 ; x < arr.length -1 ; x++){
            int min = x;
            for(int c = x+1 ; c < arr.length ; c++){
                if(arr[min] > arr[c]) min=c;
            }
            if(min != x) {
                arr[min] = arr[min] ^ arr[x];
                arr[x] = arr[min] ^ arr[x];
                arr[min] = arr[min] ^ arr[x];
                /*
                a = 3, b = 4
                * a = a^b (011 ^ 100) = (111) = ===> a= 7
                  b = a ^ b (111 ^ 100) = (011) ====> b = 3
                  a = a^ b (111 ^ 011) = (100) =====> a = 4
                *
                * */
            }
        }
    }

    public static void SelectionSort_TowPointers(int[] arr, char T){
        int l , r;
        l  = (T=='A'?0:arr.length-1) ;
        r = (T == 'A' ? arr.length-1:0);
        while(l < r){
            int min = l , ma = r;
            for(int x = l ; x <=r;x++){
                if(arr[min] > arr[x]) min = x;
                if(arr[ma] < arr[x]) ma = x;
            }
            // sawp min with left , swap max with left
            if(min != l){
                arr[min] = arr[min] ^ arr[l];
                arr[l] = arr[min] ^ arr[l];
                arr[min] = arr[min] ^ arr[l];
            }
            if(ma != r){
                arr[ma] = arr[ma] ^ arr[r];
                arr[r] = arr[ma] ^ arr[r];
                arr[ma] = arr[ma] ^ arr[r];
            }
            l++;
            r--;

        }
    }

    public static void BobbleSort(int[] arr){
        for(int x = 0 ; x < arr.length-1;x++){
            for(int c = x+1;c<arr.length;c++){
                if(arr[x] > arr[c]){
                    if(arr[x] != arr[c]){
                        arr[x] = arr[x] ^ arr[c];
                        arr[c] = arr[x] ^ arr[c];
                        arr[x] = arr[x] ^ arr[c];
                    }
                }
            }
        }
    }

    private static int Partition(int[] arr , int i , int j){
        int pivit = i;
        while(true){
            while(arr[pivit] <= arr[j] && pivit != j){
                j--;
            }
            if(pivit == j) break;
            else if(arr[pivit] > arr[j]){
                int tmp =arr[j];
                arr[j] = arr[pivit];
                arr[pivit] = tmp;
                pivit = j;
            }
            while(arr[pivit]>=arr[i] && pivit !=i) i++;
            if(pivit == i) break;
            else if(arr[pivit] <arr[i]){
                int tmp =arr[i];
                arr[i] = arr[pivit];
                arr[pivit] = tmp;
                pivit = i;
            }
        }
        return pivit;
    }
    public static void QiuckSort(int[] arr , int i , int j){
        if(i>=j) return;
        int pivit = Partition(arr,i,j);
        QiuckSort(arr,i,pivit-1);
        QiuckSort(arr,pivit+1,j);

    }
    public static void Merge(int[] arr,int Begin , int Mid , int End){
        int n1 = Mid - Begin + 1;
        int n2 = End - Mid;
        int[] arr1 = new int[n1];
        int[] arr2 = new int[n2];

        for(int x = 0  ;x < n1 ; x++){
            arr1[x] = arr[Begin +x];
        }

        for(int x = 0  ;x < n2 ; x++){
            arr2[x] = arr[Mid +1 +x];
        }

        int La =0,Lb = 0 , C = Begin;
        while(La < n1 && Lb < n2){
            if(arr1[La] <= arr2[Lb])
                arr[C++] = arr1[La++];
            else arr[C++] =arr2[Lb++];
        }
        while(La < n1)
            arr[C++] = arr1[La++];
        while(Lb < n2)
            arr[C++] = arr2[Lb++];
    }
    public static void MergeSort(int[] arr , int Begin , int End){
        if(Begin >= End) return;
        int mid = (End + Begin) >> 1;
        MergeSort(arr,Begin,mid);
        MergeSort(arr,mid+1,End);
        Merge(arr,Begin,mid,End);
    }
}

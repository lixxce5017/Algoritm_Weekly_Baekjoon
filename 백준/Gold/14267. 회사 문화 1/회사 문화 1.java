import java.io.*;
import java.util.*;

public class Main {

    static List<Integer>[] A;
    static boolean[] visited;
    static int[] value;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        A = new ArrayList[n + 1];
        visited = new boolean[n + 1];
        value = new int[n + 1];
        for (int i = 1; i < n + 1; i++) {
            A[i] = new ArrayList<>();
        }
        int root = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i < n + 1; i++) {
            int now = Integer.parseInt(st.nextToken());
            if (now == -1) {
                root = i;
            } else {
                A[now].add(i);
                A[i].add(now);
            }
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());

            value[s] += e;
        }
        
        DFS(root);
        for (int i = 1; i < n + 1; i++) {
            System.out.print(value[i]+" ");
        }
    }

    static void DFS(int x) {
        if (visited[x]) {
            return;
        }
        visited[x] = true;
        for (int now : A[x]) {
            if (!visited[now]) {
                value[now] += value[x];
                DFS(now);
            }
        }
    }
}

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    static int[][] arr;
    static int[][][]dp;
    static boolean[][] visited;
    static int n, m, ans;
    static int[] mx = {0,1,-1};
    static int[] my = {1, 0, 0};
    static final int MIN_VALUE = Integer.MIN_VALUE + 100_000_000;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] split = br.readLine().split(" ");
        n = Integer.parseInt(split[0]);
        m = Integer.parseInt(split[1]);
        arr = new int[n + 2][m + 2];
        dp = new int[n + 2][m + 2][3];
        visited = new boolean[n + 2][m + 2];

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = MIN_VALUE;
                }
            }
        }

        for (int i = 1; i < n + 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j < m + 1; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }




        System.out.println(DFS(1, 1,0));

    }

    static int DFS(int sty, int stx,int idx) {

        if (sty == n && stx == m) {
            return arr[n][m];
        }

        if(dp[sty][stx][idx]!=MIN_VALUE)
        {
            return dp[sty][stx][idx];
        }
        int maxx = MIN_VALUE;
        for (int i = 0; i < 3; i++) {
            int dx = stx + mx[i];
            int dy = sty + my[i];
            // 왼쪽에서 왔는데 오른쪽으로 돌아가거나
            // 오른쪽에서 왔는데 왼쪾으로 돌아가는거면 패스
            if ((idx == 1 && i == 2) || (idx == 2 && i == 1))
                continue;
            if(dx>=1&&dx<=m&&dy>=1&&dy<=n){
                    maxx = Integer.max(DFS(dy, dx, i), maxx);
            }
        }


        dp[sty][stx][idx]=maxx+arr[sty][stx];
        visited[sty][stx]=false;
        return dp[sty][stx][idx];
    }
}

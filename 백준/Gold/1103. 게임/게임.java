import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int n,m,ans;
    static int[] dr = {1, 0, -1, 0};
    static int[] dc = {0, 1, 0, -1};
    static char[][] arr;
    static int[][] dp;
    static boolean[][] visited;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] split = br.readLine().split(" ");
        n = Integer.parseInt(split[0]);
        m = Integer.parseInt(split[1]);

        arr = new char[n][m];
        visited = new boolean[n][m];
        dp = new int[n][m];

        for (int i = 0; i < n; i++) {
            char[] charArray = br.readLine().toCharArray();
            for (int j = 0; j < m; j++) {
                arr[i][j] = charArray[j];
            }
        }

        visited[0][0]=true;
        DFS(0, 0,1);
        System.out.println(ans);
    }

    static void DFS(int y, int x,int cnt) {
        if(cnt>ans) ans=cnt;
        dp[y][x] = cnt;
        for (int i = 0; i < 4; i++) {
            int dx = x + dr[i] * (arr[y][x]-'0');
            int dy = y + dc[i] * (arr[y][x]-'0');
            if (dy < 0 || dy >= n || dx < 0 || dx >= m) continue;
            if(arr[dy][dx] == 'H') {
                continue;
            }
            if (dp[dy][dx] >cnt) continue;
            if (visited[dy][dx]) {
                System.out.println(-1);
                System.exit(0);
            }


            visited[dy][dx] = true;
            DFS(dy, dx,cnt+1);
            visited[dy][dx] = false;

        }
    }
}

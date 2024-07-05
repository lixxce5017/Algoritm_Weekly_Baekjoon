import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n,m, time, ans=Integer.MAX_VALUE, cnt;
    static boolean check;
    static int[] dr = {1, 0, -1, 0};
    static int[] dc = {0, 1, 0, -1};
    static int[][] arr;
    static int ecnt=0;
    static boolean[][] visited;
    static Queue<XY> queue;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] split = br.readLine().split(" ");
        n = Integer.parseInt(split[0]);
        m = Integer.parseInt(split[1]);

        arr = new int[n][m];
        visited = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if(arr[i][j]==1)
                    ecnt++;
            }
        }
        BFS();
        if(time==1)
        {
            System.out.println(time);
            System.out.println(ecnt);
        }
        else
        {
            System.out.println(time);
            System.out.println(ans);   
        }
    }


    static void TEST() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(arr[i][j]==1) {
                    cnt++;
                    check = false;
                }
            }
        }
    }

    static void SELECT(int x, int y) {
        queue = new LinkedList<>();
        queue.add(new XY(x,y));
        visited[x][y]=true;
        while (!queue.isEmpty()) {
            XY poll = queue.poll();

            for (int i = 0; i < 4; i++) {
                int dx = poll.x + dr[i];
                int dy = poll.y + dc[i];
                if(dx<0||dx>=n||dy<0||dy>=m) continue;
                if(visited[dx][dy]) continue;
                if (arr[dx][dy] == 0) {
                    queue.add(new XY(dx, dy));
                    visited[dx][dy] = true;
                }else if (arr[dx][dy]==1) {
                    arr[dx][dy] +=1;
                    visited[dx][dy] = true;
                }

            }
        }
    }

    static void BFS(){
        while (true) {
            check = true;
            cnt=0;
            time++;
            SELECT(0, 0);
            TEST();
            if (check) break;

            visited = new boolean[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(arr[i][j]>=2) arr[i][j] = 0;
                }
            }
            if (cnt != 0) ans = Math.min(ans, cnt);
        }

    }


    static class XY{
        int x,y;

        public XY(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}

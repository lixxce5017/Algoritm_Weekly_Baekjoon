import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int n, m, vNum,empty, ans=Integer.MAX_VALUE;
    static int[][] arr;
    static int[] dr = {1, 0, -1, 0};
    static int[] dc = {0, 1, 0, -1};
    static boolean[] selected;
    static boolean[][] visited;
    static Queue<XY> que;
    static List<XY> virus;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        virus = new ArrayList<>();
        arr = new int[n][n];
        visited = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 2) {
                    vNum++;
                    virus.add(new XY(i, j, 0));
                } else if (arr[i][j] == 0) {
                    empty++;
                }
            }
        }
        selected = new boolean[vNum];
        DFS(0, 0);
        if (ans == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }
    }

    static void DFS(int idx, int num) {
        if (num == m) {
            ans=Math.min(ans,BFS());
            visited = new boolean[n][n];
            return;
        }
        for (int i = idx; i < vNum; i++) {
            if (!selected[i]) {
                selected[i] = true;
                DFS(i, num + 1);
                selected[i] = false;
            }
        }
    }

    static int BFS() {
        que = new LinkedList<>();
        for (int i = 0; i < vNum; i++) {
            if (selected[i]) {
                que.add(virus.get(i));
            }
        }

        int cnt=0;
        while (!que.isEmpty()) {
            XY poll = que.poll();
            visited[poll.y][poll.x] = true;
            if (arr[poll.y][poll.x] == 0) {
                cnt++;
            }
            if (cnt == empty) {
                return poll.cnt;
            }

            for (int i = 0; i < 4; i++) {
                int x = poll.x + dr[i];
                int y = poll.y + dc[i];
                if(x<0||x>=n||y<0||y>=n) continue;
                if(arr[y][x]==1) continue;
                if (!visited[y][x]) {
                    visited[y][x] = true;
                    que.add(new XY(y, x, poll.cnt + 1));
                }
            }
        }

        return Integer.MAX_VALUE;
    }

    static class XY {
        int x,y,cnt;

        XY(int y, int x, int cnt) {
            this.y = y;
            this.x = x;
            this.cnt = cnt;
        }
    }

}

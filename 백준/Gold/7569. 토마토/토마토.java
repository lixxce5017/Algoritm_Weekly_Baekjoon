import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[][][] arr;
    static int[] dr = {1, 0, -1, 0, 0, 0};
    static int[] dc = {0, 1, 0, -1, 0, 0};
    static int[] dh = {0, 0, 0, 0, 1, -1};
    static boolean[][][] visited;
    static int n,m, h, good, bad, ans, cnt,result;
    static List<XYZ> goodT;
    static Queue<XYZ> que;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());

        arr = new int[h][m][n];
        visited = new boolean[h][m][n];
        goodT = new ArrayList<>();

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < m; j++) {
                st = new StringTokenizer(br.readLine());
                for (int k = 0; k < n; k++) {
                    arr[i][j][k] = Integer.parseInt(st.nextToken());
                    if (arr[i][j][k] == 1) {
                        good++;
                        goodT.add(new XYZ(i, j, k,0));
                    }
                    if (arr[i][j][k] == 0) {
                        bad++;
                    }
                }
            }
        }
   BFS();
 
    for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
					if (arr[k][i][j] == 0) {
						System.out.println(-1);
						return;
					}
					if (result < arr[k][i][j]) {
						result = arr[k][i][j];
					}
			}
		}
	}
	System.out.println(result-1);

    }

    static void BFS() {
        que = new LinkedList<>();
        for (int i = 0; i < good; i++) {
            que.offer(goodT.get(i));
            visited[goodT.get(i).z][goodT.get(i).y][goodT.get(i).x] = true;
        }

        while (!que.isEmpty()) {
            XYZ pop = que.poll();

            for (int i = 0; i < 6; i++) {
                int x = pop.x + dr[i];
                int y = pop.y + dc[i];
                int z = pop.z + dh[i];
                
                if(x<0||x>=n||y<0||y>=m||z<0||z>=h) continue;
                if (arr[z][y][x]==0) {
                    visited[z][y][x] = true;
                    arr[z][y][x]=arr[pop.z][pop.y][pop.x]+1;
                    que.offer(new XYZ(z, y, x, pop.cnt + 1));
                }
            }
        }

}

    static class XYZ {
        int x,y, z,cnt;

        XYZ(int z, int y, int x, int cnt) {
            this.z = z;
            this.y = y;
            this.x = x;
            this.cnt = cnt;
        }
    }
}

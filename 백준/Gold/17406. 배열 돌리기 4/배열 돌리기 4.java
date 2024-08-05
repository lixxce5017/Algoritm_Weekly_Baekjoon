import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int n,m, k, ans=Integer.MAX_VALUE;
    static int[][] arr;
    static boolean[] selected;
    static List<XY> rotate;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        arr = new int[n][m];


        for (int i = 0; i < n; i++) {
            StringTokenizer st1 = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st1.nextToken());
            }
        }
        rotate = new ArrayList<>();

        for (int i = 0; i < k; i++) {
            StringTokenizer st1 = new StringTokenizer(br.readLine());
            rotate.add(new XY(Integer.parseInt(st1.nextToken())-1, Integer.parseInt(st1.nextToken())-1, Integer.parseInt(st1.nextToken())));
        }

        selected = new boolean[rotate.size()];


        recur(0);
        System.out.println(ans);
    }

    static void recur(int cnt) {
        if (cnt == k) {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 0; j < m; j++) {
                    sum += arr[i][j];
                }
                ans = Math.min(ans, sum);
            }
            return;
        }


        for (int i = 0; i < rotate.size(); i++) {
            if(!selected[i]) {
                int[][] copy = new int[n][m];
                for (int j = 0; j <n ; j++) {
                    copy[j] = arr[j].clone();
                }
                selected[i] = true;
                rarr(i);
                recur(cnt + 1);

                for (int j = 0; j < n; j++) {
                    arr[j] = copy[j].clone();
                }
                selected[i] = false;
            }
        }
    }

    static void rarr(int idx) {
        XY l = rotate.get(idx);

        for (int p = 0; p < l.s; p++) {
            int top = l.r - l.s + p;
            int left = l.c - l.s + p;
            int bottom = l.r + l.s - p;
            int right = l.c + l.s - p;

            int tmp = arr[top][left];

            //하
            for (int i = left + 1; i <= right; i++) {
                tmp = swap(tmp, top, i);
            }
            for (int i = top + 1; i <= bottom; i++) {
                tmp = swap(tmp, i, right);
            }
            //우
            for (int i = right-1; i >=left; i--) {
                tmp = swap(tmp, bottom, i);
            }
            //상
            for (int i = bottom-1; i >=top; i--) {
                tmp = swap(tmp, i, left);
            }
            //좌


        }

    }

    static int swap(int k, int y, int x) {
        int tmp = arr[y][x];
        arr[y][x] = k;
        return tmp;
    }

    static class XY{
        int r, c, s;

        XY(int r, int c, int s) {
            this.r = r;
            this.c = c;
            this.s = s;
        }
    }
}

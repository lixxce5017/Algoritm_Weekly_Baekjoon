import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static Queue<X> queue;
    static boolean[] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        visited = new boolean[100001];
        int x = sc.nextInt();
        int y = sc.nextInt();

        BFS(x,y);
    }

    static void BFS(int x, int y) {
        queue = new LinkedList<>();
        visited[x] = true;
        queue.add(new X(x, 0));
        while (!queue.isEmpty()) {
            X poll = queue.poll();
            int cnt = poll.cnt;
            if(poll.x==y)  System.out.println(cnt);

            if (poll.x+1<=100000&&!visited[poll.x+1]) {
                visited[poll.x+1]=true;
                queue.add(new X(poll.x+1, cnt + 1));
            }

            if (poll.x-1>=0&&!visited[poll.x-1]) {
                visited[poll.x-1]=true;
                queue.add(new X(poll.x-1, cnt + 1));
            }

            if (poll.x*2<=100000&&!visited[poll.x*2]) {
                visited[poll.x*2]=true;
                queue.add(new X(poll.x*2, cnt + 1));
            }
        }

    }

    static class X {
        int x, cnt;

        public X(int x, int cnt) {
            this.x = x;
            this.cnt = cnt;
        }
    }

}



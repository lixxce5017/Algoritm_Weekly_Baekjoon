import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


class Main{

    static int N;
    static int [][] ability;
    static boolean [] visited;
    static ArrayList<Integer> result;
     static int Min = Integer.MAX_VALUE;
    public static void main(String []args) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        ability=new int[N+1][N+1];
        visited=new boolean[N+1];
        result=new ArrayList<>();
        for(int i=1;i<N+1;i++)
        {
            st=new StringTokenizer(br.readLine()," ");
            for(int j=1;j<N+1;j++)
            {
                ability[i][j]=Integer.parseInt(st.nextToken());
            }
        }
        backtrack(0,new ArrayList<>(),1);
        Collections.sort(result);
        System.out.println(Min);

    }
    static void backtrack(int depth,ArrayList<Integer>selectedNums,int idx)
    {
        if(depth==N/2)
        {

            ArrayList<Integer>Link=new ArrayList<>();
            ArrayList<Integer>Start=new ArrayList<>();
            for(int i=1;i<N+1;i++)
            {
                if(visited[i]==false)
                {
                    Link.add(i);
                }
                else 
                {
                    Start.add(i);
                }
            }
            WhatisAbility(Link,Start);
            return;
        }
        for(int i=idx;i<N+1;i++)
        {
            if(!visited[i])
            {
                visited[i]=true;
                ArrayList<Integer>list=new ArrayList<>(selectedNums);
                list.add(i);
                backtrack(depth+1,list,i+1);
                visited[i]=false;
            }
        }
    }
    static void WhatisAbility(ArrayList<Integer>Link,ArrayList<Integer>Start)
    {
        int start_ability=0;
        int link_ability=0;
        for(int i=0;i<Start.size();i++) {
            for(int j=0;j<Start.size();j++)
            {
                start_ability+=ability[Start.get(i)][Start.get(j)];
            }
        }
        for(int i=0;i<Link.size();i++) {
            for(int j=0;j<Link.size();j++)
            {
                link_ability+=ability[Link.get(i)][Link.get(j)];
            }
        }

      int val = Math.abs(link_ability - start_ability);
         if (val == 0) {
             System.out.println(val);
             System.exit(0);
         }
    
         Min = Math.min(val, Min);
         return;
    }
}
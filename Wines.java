/*
Imagine you have a collection of N wines placed next to each other on a shelf. For simplicity, let's number the wines from left to right as they are standing on the shelf with integers from 1 to N, respectively. The price of the i-th wine is pi (prices of different wines can be different).

Because the wines get better every year, supposing today is the year 1, on year y the price of the i-th wine will be y*pi, i.e. y-times the value that current year.

You want to sell all the wines you have, but you want to sell exactly one wine per year, starting on this year. One more constraint - on each year you are allowed to sell only either the leftmost or the rightmost wine on the shelf and you are not allowed to reorder the wines on the shelf (i.e. they must stay in the same order as they are in the beginning).

You want to find out, what is the maximum profit you can get, if you sell the wines in optimal order.

So for example, if the prices of the wines are (in the order as they are placed on the shelf, from left to right): p1=1, p2=4, p3=2, p4=3
The optimal solution would be to sell the wines in the order p1, p4, p3, p2 for a total profit 1*1 + 3*2 + 2*3 + 4*4 = 29
*/

import java.lang.Math;
import java.util.Arrays;
import java.util.Scanner;

class Wines{
	private static int N;
	private static int[] p;
	private static int[][] cache; // used to reduce redundant calculations
	
	static int profit(int left, int right){
		if(left > right)
			return 0;
		if(cache[left][right] != -1)
			return cache[left][right];
		int year = N - (right-left+1) + 1; 
    	return cache[left][right] = Math.max(profit(left+1, right)+ year*p[left],
			  								 profit(left, right-1)+ year*p[right]);
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		p = new int[N];
		cache = new int[N][N];
		for(int i=0; i<N; i++)
			p[i] = sc.nextInt();
		for(int[] x : cache)
			Arrays.fill(x,-1);
		System.out.println(profit(0,N-1));		
	}
}

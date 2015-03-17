import java.util.*;

public class SharksDinner {
	public int minSurvivors(int[] size,int[] speed,int[] intel) {
		int n = size.length;
		for (int i = 0; i < n; i++)
		  for (int j = i + 1; j < n; j++) if (size[i] <= size[j] && speed[i] <= speed[j] && intel[i] <= intel[j]) {
		  	int t = size[i];  size[i] = size[j];  size[j] = t;
		  	t = speed[i];  speed[i] = speed[j];  speed[j] = t;
		  	t = intel[i];  intel[i] = intel[j];  intel[j] = t;
		  }

		int start = 2 * n,end = 2 * n + 1;
		int[][] cap = new int[end + 1][end + 1];
		for (int i = 0; i < n; i++) cap[start][i] = 2;
		for (int i = 0; i < n; i++) cap[i + n][end] = 1;
		for (int i = 0; i < n; i++)
		  for (int j = i + 1; j < n; j++)
		    if (size[i] >= size[j] && speed[i] >= speed[j] && intel[i] >= intel[j]) cap[i][n + j] = 1;

		int edible = 0;
		while (true) {
			int[] trace = new int[end + 1];
			for (int i = 0; i <= end; i++) trace[i] = -1;
			trace[start] = -2;

			int[] queue = new int[end + 1];
			int front = 0,rear = 1;
			queue[0] = start;
			while (front < rear) {
				int u = queue[front];
				front++;
				for (int v = 0; v <= end; v++) if (cap[u][v] > 0 && trace[v] == -1) {
					trace[v] = u;
					queue[rear++] = v;
				}
			}
			if (trace[end] == -1) return n - edible;
			for (int i = 0; i < end; i++) if (trace[i] != -1 && cap[i][end] > 0) {
				int add = cap[i][end];
				for (int v = i,u = trace[v]; v != start; v = u,u = trace[v]) add = Math.min(add,cap[u][v]);
				if (add <= 0) continue;
				edible += add;
				cap[i][end] -= add;
				cap[end][i] += add;
				for (int v = i,u = trace[v]; v != start; v = u,u = trace[v]) {
					cap[u][v] -= add;
					cap[v][u] += add;
				}
			}
		}
	}
};

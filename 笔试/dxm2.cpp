//public class Main {
//
//	public static void main(String[] args) {
//		Scanner sc = new Scanner(System.in);
//		int x = sc.nextInt();
//		int y = sc.nextInt();
//		int n = sc.nextInt();
//		Point end = new Point(x, y);
//		Set<Point> stones = new HashSet<>();
//		for (int i = 0; i < n; i++) {
//			stones.add(new Point(sc.nextInt(), sc.nextInt()));
//		}
//		Set<Point> his = new HashSet<>();
//		LinkedList<Point> queue = new LinkedList<>();
//		queue.add(new Point(0, 0));
//		int path = 0;
//
//		while (!queue.isEmpty()) {
//			int size = queue.size();
//			while (size > 0) {
//				Point p = queue.poll();
//				if (p.equals(end)) {
//					System.out.println(path);
//					return;
//				}
//				size--;
//				Point left = new Point(p.x - 11, p.y);
//				if (!stones.contains(left) && !his.contains(left)) {
//					queue.offer(left);
//				}
//				Point right = new Point(p.x + 1, p.y);
//				if (!stones.contains(right) && !his.contains(right)) {
//					queue.offer(right);
//				}
//				Point down = new Point(p.x, p.y - 1);
//				if (!stones.contains(down) && !his.contains(down)) {
//					queue.offer(down);
//				}
//				Point up = new Point(p.x, p.y + 1);
//				if (!stones.contains(up) && !his.contains(up)) {
//					queue.offer(up);
//				}
//				his.add(p);
//			}
//			path++;
//		}
//	}
//
//}
//
//class Point {
//	int x;
//	int y;
//
//	public Point(int x, int y) {
//		this.x = x;
//		this.y = y;
//	}
//
//	@Override
//		public boolean equals(Object o) {
//		if (this == o) return true;
//		if (o == null || getClass() != o.getClass()) return false;
//		Point point = (Point)o;
//		return x == point.x &&
//			y == point.y;
//	}
//
//	@Override
//		public int hashCode() {
//		return Objects.hash(x, y);
//	}
//}

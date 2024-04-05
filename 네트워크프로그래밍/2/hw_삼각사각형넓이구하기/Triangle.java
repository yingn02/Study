public class Triangle extends Shape{
	private double t_area;
	
	public void print() {
		System.out.println("** 삼각형 **");
	}
	
	public void area(double a, double b) {
		t_area = a * b * 1/2;
		System.out.println("넓이 = " + t_area);
	}
}

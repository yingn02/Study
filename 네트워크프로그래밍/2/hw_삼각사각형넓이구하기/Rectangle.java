public class Rectangle extends Shape{
	private double r_area;
	
	public void print() {
		System.out.println("** 사각형 **");
	}
	
	public void area(double a, double b) {
		r_area = a * b;
		System.out.println("넓이 = " + r_area);
	}
}

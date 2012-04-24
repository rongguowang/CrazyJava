package org.crazyjava.sample;

public class ATypeName {

	public static void main(String[] args) {
		ATypeName a = new ATypeName();
		DataOnly data = a.new DataOnly();
		data.i = 47;
		data.d = 1.1;
		data.b = false;
		System.out.println(" i = " + data.i);
		System.out.println(" d = " + data.d);
		System.out.println(" b = " + data.b);
		
		Storage s = a.new Storage();
		byte b = (byte)s.storage("learn some thing");
		System.out.println(" b = " + b);
		
		Incrementable.increment();
		System.out.println(" i = " + Incrementable.StaticTest.i);
		Incrementable in = new Incrementable();
		in.printStatic();
		in.increment(new Incrementable.StaticTest());
		in.printStatic();
		in.decrement(new Incrementable.StaticTest());
		in.printStatic();
	}
	
	class DataOnly {
		int i;
		Double d;
		boolean b;
	}
	
	private class Storage {
		public int storage(String s) {
			return s.length() * 2;
		}
	}
	

	private static class Incrementable {
		StaticTest st1 = new StaticTest();
		StaticTest st2 = new StaticTest();
		static void increment() {
			StaticTest.i++;
		}
		
		void printStatic() {
			System.out.println(st1.i);
			System.out.println(st2.i);
		}
		private static class StaticTest {
			static int i = 47;
		}
		
		void increment(StaticTest st) {
			st.i++;
		}
		
		void decrement(StaticTest st) {
			st.i--;
		}
	}
}

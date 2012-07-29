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
        byte b = (byte) s.storage("learn some thing");
        System.out.println(" b = " + b);

        Incrementable.increment();
        System.out.println(" i = " + Incrementable.StaticTest.i);
        Incrementable in = new Incrementable();
        in.printStatic();
        in.increment(new Incrementable.StaticTest());
        in.printStatic();
        in.decrement(new Incrementable.StaticTest());
        in.printStatic();

        AutoChange auto = a.new AutoChange();
        auto.autoChangeTest();

        for ( int i = 0; i < args.length; i++) {
            System.out.println("args[" + i + "] = " + args[i]);
        }

        AllTheColorsOfTheRainBow rainBow = a.new AllTheColorsOfTheRainBow();
        rainBow.chagneTheColorOfTheRainBow(1);
        System.out.println("rainBow.anIntegerRepresentingColors = " + rainBow.getColorOfTheRainBow());
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

    private class AutoChange {
        public AutoChange() {
        }

        public void autoChangeTest() {
            boolean a = true;
            Boolean b = new Boolean(false);
            a = b;
            System.out.println("a = " + a);
            b = true;
            System.out.println("b = " + b);

            Character ch = new Character('a');
            char c = 'c';
            System.out.println("ch = " + ch);
            System.out.println("c = " + c);
            c = ch;
            ch = 'b';
            System.out.println("ch = " + ch);
            System.out.println("c = " + c);
            byte ba = 127;
            Byte bc = new Byte((byte) -1);
            System.out.println("ba = " + ba);
            System.out.println("bc = " + bc);
            ba = bc;
            System.out.println("ba = " + ba);
        }
    }

    class AllTheColorsOfTheRainBow {
        private int anIntegerRepresentingColors = 0;
        private void chagneTheColorOfTheRainBow(int newColor) {
            anIntegerRepresentingColors = newColor;
        }
        public int getColorOfTheRainBow() {
            return anIntegerRepresentingColors;
        }
    }
}

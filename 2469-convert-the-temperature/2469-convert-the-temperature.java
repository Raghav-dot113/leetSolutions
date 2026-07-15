class Solution {
    public double[] convertTemperature(double temp) {
        double[] arr = new double[2];
        arr[0] = temp + 273.15;
        arr[1] = temp * 1.80 + 32.00;
        return arr;
    }
}
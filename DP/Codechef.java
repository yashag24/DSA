import java.util.*;
import java.lang.*;
import java.io.*;

public class Codechef
{
    public static int getMaxEfficiency(int[] arrivalTime) {
        // Sorting the array: O(n log n)
        Arrays.sort(arrivalTime);
        
        int maxEfficiency = Integer.MIN_VALUE;
        int n = arrivalTime.length;
        
        int left = 0;
        
        // Sliding window approach: O(n)
        for (int right = 0; right < n; right++) {
            int timeActive = arrivalTime[right] - arrivalTime[left];
            int testCases = right - left + 1;
            int efficiency = testCases - timeActive;
            maxEfficiency = Math.max(maxEfficiency, efficiency);
            
            while (left < right && timeActive > testCases - 1) {
                left++;
                timeActive = arrivalTime[right] - arrivalTime[left];
                testCases = right - left + 1;
                efficiency = testCases - timeActive; 
                maxEfficiency = Math.max(maxEfficiency, efficiency); 
            }
        }
        
        return maxEfficiency;
    }

    public static void main(String[] args) {
        // Example input
        int[] arrivalTimes = {8, 10, 12, 5, 6, 5, 7, 6, 10}; 
        
        // Calculate maximum efficiency
        int result = getMaxEfficiency(arrivalTimes);
        
        // Print result
        System.out.println("Maximum efficiency: " + result);
    }
}

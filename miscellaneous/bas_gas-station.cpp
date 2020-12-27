/*
 * https://leetcode.com/problems/gas-station/
 */

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    for (int i=0; i<n; i++){
        int needed = 0;
        bool start = false;
        for (int j=i; j<n; j++){
            if (j==i && start)
                return i;
            needed += gas[j] - cost[j];
            if (needed < 0)
                break;
            if (j+1 == n)
                j = -1;
            start = true;
        }
    }
    return -1;
}


// Kadane's algorithm - O(n)

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    int fuel = 0;
    for (int i=0; i<n; i++){
        fuel += gas[i] - cost[i];
    }
    if (fuel < 0)
        return -1;

    int index = 0;
    int gasUsed = 0;
    for (int i=0; i<n; i++){
        if (gasUsed < 0){
            gasUsed = 0;
            index = i;
        }
        gasUsed += gas[i] - cost[i];
    }
    return index;
}

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        auto helper = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            int total_days = 0;
            for (int i = 0; i < month - 1; ++i) {
                total_days += days_in_month[i];
            }
            total_days += day;
            return total_days;
        };

        int arrive_alice = helper(arriveAlice);
        int leave_alice = helper(leaveAlice);
        int arrive_bob = helper(arriveBob);
        int leave_bob = helper(leaveBob);

        int start = max(arrive_alice, arrive_bob);
        int end = min(leave_alice, leave_bob);

        return max(0, end - start + 1);
    }
};
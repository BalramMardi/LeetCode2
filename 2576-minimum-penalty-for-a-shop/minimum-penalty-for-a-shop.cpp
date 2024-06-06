class Solution {
public:
    int bestClosingTime(string customers) {
        
        int res=-1, pen=0, maxx=0;
        for(int i=0;i<customers.length();i++){
            if(customers[i]=='Y'){
                pen++;
            }
            else{
                pen--;
            }
            if(pen>maxx){
                maxx = pen;
                res = i;
            }
        }

        return ++res;

    }
};
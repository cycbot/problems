class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if(numerator == 0)return "0";
        string res;
        if(numerator < 0 ^ denominator < 0)res+='-';
        long long n = abs(numerator);
        long long d = abs(denominator);
        res+=to_string(n/d);
        if(n%d==0)return res;
        res+='.';

        unordered_map<int,int> map;
        for(long long r=n%d;r;r%=d){

            if(map.count(r)>0){
                res.insert(map[r],1,'(');
                res+=')';
                break;
            }

            map[r]=res.size();
            r*=10;
            res+=to_string(r/d);
        }
        return res;

    }
};

class Q1281 {
public:
    int subtractProductAndSum(int n) {
        int plus = 0;
        int mult = 1;
        while (n) {
            int quo = n % 10;
            n = n / 10;
            plus += quo;
            mult *= quo;
        }
        return mult - plus;
    }
};
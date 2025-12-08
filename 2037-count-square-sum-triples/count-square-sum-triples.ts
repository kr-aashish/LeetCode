function countTriples(n: number): number {
    let count = 0;
    for (let a = 1; a <= n; a++) {
        for (let b = 1; b <= n; b++) {
            for (let c = 1; c <= n; c++) {
                if (a * a + b * b == c * c) {
                    count++;
                }
            }
        }
    }
    return count;
};
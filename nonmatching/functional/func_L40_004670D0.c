/* functional: high. Small state machine on a global state word: state 0 sets field 9 to -1; 1-3 go to state 7 with field 1 cleared; 4 goes to state 6 with field 1 = 4 - field 1; 5 goes to state 6 with field 1 cleared; others do nothing. The 0x18 bytes of junk words at the function start (stores through a zero register, stack bumps) are skipped as retail never executes them meaningfully; the compiler emits a compare chain instead of the jump table. */
extern int D_L40_003BF020[];

void func_L40_004670D0(void) {
    int t;

    switch (D_L40_003BF020[0]) {
    case 0:
        D_L40_003BF020[9] = -1;
        return;
    case 1:
    case 2:
    case 3:
        D_L40_003BF020[0] = 7;
        D_L40_003BF020[1] = 0;
        break;
    case 4:
        t = D_L40_003BF020[1];
        D_L40_003BF020[0] = 6;
        D_L40_003BF020[1] = 4 - t;
        return;
    case 5:
        D_L40_003BF020[0] = 6;
        D_L40_003BF020[1] = 0;
        break;
    default:
        break;
    }
}

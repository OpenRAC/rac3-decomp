/* func_L39_004FBED8: near miss (p2 w2): 2 diff, arg-shuffle scheduling only (retail does 2 moves before addiu $sp).
   Tried int/ptr/float param types, return int, 5th param. Callee func_L39_0050A8D8(0,a0,a1,a2,a3).
   Left: scheduler-order research. */
extern void func_L39_0050A8D8(int, int, int, int, int);
void func_L39_004FBED8(int a0, int a1, int a2, int a3) {
    func_L39_0050A8D8(0, a0, a1, a2, a3);
}

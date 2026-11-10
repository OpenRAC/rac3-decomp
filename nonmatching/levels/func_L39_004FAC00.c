/* Near miss, ported from rac4-decomp's func_L00_00536A10 (cross-game near pair). NEAR: SIBCALL (j func_004BEF28 tail call) */
extern void func_L39_004F9A88(s32);
extern void func_L39_004FA4E8(s32);
extern void func_L39_004BEF28(void *);

void func_L39_004FAC00(s32 *arg0) {
    if (arg0 != 0) {
        func_L39_004F9A88(arg0[1]);
        func_L39_004FA4E8(arg0[2]);
        func_L39_004BEF28(arg0);
    }
}

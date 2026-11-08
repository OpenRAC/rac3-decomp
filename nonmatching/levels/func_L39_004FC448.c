/* Near miss, ported from rac4-decomp's func_L00_00538258 (cross-game near pair). NEAR: SIBCALL (ld regs; j func_L39_004BEF28; addiu $sp) and 16-byte save slots; not attempted */
s32 func_L00_004FAD28(void *);
s32 func_L39_004FC1A0(s32);

void func_L39_004FC448(void *arg0) {
    s32 var_s0;
    s32 var_s1;
    var_s1 = 0xB;
    var_s0 = arg0 + 4;
    do {
        var_s1 -= 1;
        func_L39_004FC1A0(var_s0);
        var_s0 += 0x14;
    } while (var_s1 >= 0);
    if ((*(s32 *)((u8 *)(arg0) + 0x108)) & 1) {
        func_L00_004FAD28(arg0);
    }
}
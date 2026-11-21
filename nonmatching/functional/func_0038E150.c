/* functional: high. Draft checked against PAL asm: all six globals (3 table loads, 2 stores at gp-0x6D78/-0x6D74 = D_001D5B38/3C, index at gp-0x72C8 = D_001D55E8), strides 4 and 64. Uses the file context's declarations (D_001D55C0/C8 scalars, D_001D55C4_0038E150). Near miss only in address-formation form. */
void func_0038E150(s32 index) {
    D_001D55C0 = D_001D55D0[index];
    D_001D55C4_0038E150 = D_001D55D8[index];
    D_001D55C8 = D_001D55E0[index];
    D_001D5B38 = D_0031CF50 + index * 64;
    D_001D5B3C = D_0031CFD0 + index * 64;
    D_001D55E8 = index;
}

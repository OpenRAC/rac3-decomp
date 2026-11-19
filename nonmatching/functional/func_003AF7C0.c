/* functional: high. US draft verified: 10 args forwarded in order (4 + t0-t3 registers, then 3 stack slots 0x0/0x8/0x10 incl. lbu a9); only codegen differs. */
extern s32 D_001D5C78;
extern void func_003AC590();
void func_003AF7C0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, u8 a9) {
    if (D_001D5C78 != 0) {
        func_003AC590(D_001D5C78 + 0x1FCA8, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }
}

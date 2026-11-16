/* func_0038E150 (PAL frontbin, src/frontbin/38E0A8.c, flags -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division -mno-split-addresses). Started from the US draft (rac3-uya-decomp
   func_00389920), which reached retail only with register pins and empty asm barriers (not allowed).
   Near miss, plain C below: 29 diff in its file's context, 2026-11-16.
   - Retail builds each table's full address (`lui`/`addiu`), adds `index << 2`, then loads at
     offset 0, all three bases before the loads. With this file's -mno-split-addresses gcc folds the
     table into the load (`lui; addu; lw %lo`) for `T[index]` and for byte-offset arithmetic alike
     (3 wordings, same code). Split addresses (--mode S, not this file's flags) are no closer (28).
   - The three stores go through `lui $at` (unsized names, one per word): those already come out right.
   The leftover declarations above the INCLUDE_ASM in the file are the US draft's. */
/* localdecomp:start func_0038E150 */
extern s32 D_001D55C0[];
extern s32 D_001D55C4_0038E150[];
extern s32 D_001D55C8[];
extern s32 D_001D55D0[];
extern s32 D_001D55D8[];
extern s32 D_001D55E0[];
extern u8 D_0031CF50[];
extern u8 D_0031CFD0[];
extern u8 *D_001D5B38;
extern u8 *D_001D5B3C;
extern s32 D_001D55E8;
void func_0038E150(s32 index) {
    D_001D55C0[0] = D_001D55D0[index];
    D_001D55C4_0038E150[0] = D_001D55D8[index];
    D_001D55C8[0] = D_001D55E0[index];
    D_001D5B38 = D_0031CF50 + index * 64;
    D_001D5B3C = D_0031CFD0 + index * 64;
    D_001D55E8 = index;
}
/* localdecomp:end func_0038E150 */

/* Resolved on 2026-11-15: current C is integrated in src/levels/07_annihilation_nation/L07_003C0710.c and the full PAL level build prints MATCH. This saved draft is retained as historical evidence. Passing the entry kind in both branches resolves the annulled-branch residual; the zero-arm callee has an unused kind parameter. */
/* Level 7 near miss: 1 instruction. Retail has `bnez $a0`; this C has
   `bnel $a0,$zero` (annulled). The trade-off is stable: loading the entry kind
   inside the taken block gives flag $a0 + bnel; hoisting it gives bnez but the
   flag moves to $v1. Not linked; owning flags unchanged. No VU0. */
typedef struct {
    u8 pad0[0x30];
    s32 f30;
    u8 pad34[4];
    u8 b38;
    u8 pad39[2];
    u8 b3B;
} S_003C0F40;

typedef struct {
    u8 b0;
    u8 pad1;
    s16 h2;
    u8 pad4[0x20];
} E_003C0F40;

extern E_003C0F40 D_L07_002BC920_003C0F40[];
extern void func_003C0E08(u8 *a);
extern void func_003C0E58(u8 *a, s32 flag);
extern void func_004585D0(s32, s32);
extern void func_004589E0(void);
extern void func_004FF178(s32, s32);

void func_L07_003C0F40(u8 *arg0) {
    S_003C0F40 *p = *(S_003C0F40 **)(arg0 + 0x68);
    E_003C0F40 *e = &D_L07_002BC920_003C0F40[p->b38];

    if (e->b0 == 0) {
        func_003C0E08(arg0);
    } else {
        s32 k = e->h2;
        func_003C0E58(arg0, k);
    }
    func_004585D0(0, 0);
    func_004589E0();
    p->f30 = 0;
    p->b3B = 0;
    func_004FF178(0, 1);
}

/* func_L01_003B6458: NEAR 4 diff (regalloc only: retail idx in a1, gp load in v0; ours v0/v1)
   file src/levels/shared/L01_003B1F50.c, 10 places, w1 p2w2. Tried operand order, casts, field-chain forms.
   Struct: a0->0x68->0x6C idx; gp 0x376C base ptr; vtable fn at +8 / +0xC of callee result. */
typedef struct { char pad[8]; s32 (*f8)(u8 *); void (*fC)(u8 *); } Vt;
extern Vt *func_L01_00326D98(void *);
extern u8 *D_L01_001E001C_003B6458 __attribute__((section(".sdata")));
typedef struct { char pad[0x68]; u8 *p68; } A;
void func_L01_003B6458(A *a0)
{
    s32 idx;
    u8 *p;
    Vt *v;
    idx = *(s32 *)(a0->p68 + 0x6C);
    if (idx != -1) {
        p = (u8 *)(idx << 8) + (s32)D_L01_001E001C_003B6458;
        v = func_L01_00326D98(a0);
        if (v->f8(p) == 0)
            v->fC(p);
    }
}

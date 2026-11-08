/* Near miss, ported from rac4-decomp's func_L00_005523E0 (cross-game near pair). NEAR: 10 diff: retail frame 0x30 (s1 at 0x10, ra 0x20, restores ra,s1,s0) vs our 0x20; logic otherwise equal */
typedef struct { char pad0[8]; s32 f8; char pad[0xC4]; s32 fD0; } S_5165D0;
s32 func_L39_00517888(void *);

s32 func_L39_005165D0(S_5165D0 *p) {
    s32 old = p->f8;
    s32 r = func_L39_00517888(&p->f8);
    if (r == 0 && old != p->f8) {
        p->fD0 = old;
    }
    return r;
}

/* US draft of func_003BCA50 (rac3-uya-decomp func_003BC978, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003BCA50 */
typedef struct { s32 off; s32 sz; } E_3B71B8;
typedef struct { u8 pad0[0x68]; s32 f68; s32 f6C; u8 pad70[0x20]; s32 f90[0x44]; } S_225780_3B71B8;
typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x60]; s32 tbl[1]; } H_3B71B8;
typedef struct { u8 pad0[0xC]; s32 fC; s32 f10; u8 *f14; H_3B71B8 *f18; } S_227600_3B71B8;
extern S_225780_3B71B8 D_00225700_003BCA50;
extern S_227600_3B71B8 D_00227580;
extern s32 D_001DA058;
extern void func_0038CF58();
void func_003BCA50(s32 a) {
    H_3B71B8 *h;
    u8 *e;
    E_3B71B8 *p;
    s32 i;
    s32 b;
    S_227600_3B71B8 *s;
    func_0038CF58(&D_00225700_003BCA50, 0, 0x1E0);
    s = &D_00227580;
    D_00225700_003BCA50.f68 = s->fC + D_001DA058;
    D_00225700_003BCA50.f6C = s->f10 + D_001DA058;
    h = s->f18;
    e = (u8 *)h + h->f8 + h->tbl[a];
    b = (s32)e + 0x800;
    p = (E_3B71B8 *)e;
    for (i = 0; i < 0x44 && p->sz != 0; i++, p++) {
        D_00225700_003BCA50.f90[i] = b + p->off;
    }
}
/* localdecomp:end func_003BCA50 */

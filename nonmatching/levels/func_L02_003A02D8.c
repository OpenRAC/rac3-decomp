/* func_L02_003A02D8: 8 diff with the file's flags plus @ps2as (check.py --flags= --as ps2as; the other blocks of L02_003A0158.c still match with @ps2as on the file's flag line: blockcheck 21 checks, 0 failures; the same 8 at levels 2, 3 and 7). Only the first twelve prologue instructions differ: retail orders the saves and entry moves sd $s1, sd $s2, move $s1, sd $s0, move $s2, addiu $s0 (the shared &obj->f10) where this C has sd $s1, sd $s0, move $s1, sd $s2, addiu $s0, move $s2. Round 10 fixes: the non-gp table pointer is a scalar pointer alias with a 16-byte size hint (an array of pointers makes gcc keep the address in $s2: 83 to 33), one `return 1` after the `if (v->f1A != 0xFF)` (33 to 11), and v->f4 read in place of a local i (11 to 8). Alias name per the <name>_<function address> rule. Declaration order of the locals, u32 flag: no change */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; u8 pad10[8]; u8 f18; u8 pad19; u8 f1A; u8 f1B; s32 f1C; u128_t f20; } V_3A02D8;
typedef struct { u8 pad0[0xDC]; s32 fDC; u8 padE0[0x20]; u128_t f100; u8 pad110[0x10]; u8 *f120; } X_3A02D8;
typedef struct { u8 pad0[0x10]; u128_t f10; u8 pad20[0x48]; X_3A02D8 *f68; u8 pad6C[0x100 - 0x6C]; } M_3A02D8;
typedef struct { u8 pad0[0x10]; u128_t f10; u8 f20; u8 pad21[0x43 - 0x21]; u8 f43; u8 pad44[0x68 - 0x44]; V_3A02D8 *f68; u8 pad6C[0x95 - 0x6C]; u8 f95; } O_3A02D8;
extern M39E3B8 *D_L02_001DE99C_g;
extern M39E3B8 *D_L02_001DE99C_003A02D8;
__asm__(".extern D_L02_001DE99C_003A02D8, 16");
extern u8 D_001A4C60[];
extern u8 D_L02_001E1300[];
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_0033D178(void *);

s32 func_L02_003A02D8(O_3A02D8 *obj, s32 flag) {
    V_3A02D8 *v;
    M_3A02D8 *m;
    X_3A02D8 *x;
    s32 i;
    if (func_0038CF38(&obj->f10, D_001A4C60) < 3.0f) return 0;
    if (func_0038CF38(&obj->f10, D_L02_001E1300) < 3.0f) return 0;
    v = obj->f68;
    if (v->f1A == 0xFF || v->f1B < v->f1A) {
        v->f18 = flag & 1;
        if (obj->f20 != 1) return 0;
        if (obj->f95 != 1) return 0;
        if (func_L01_0033D178(D_L02_001DE99C_003A02D8 + v->f0) == 0) return 0;
        if (v->f4 != -1) {
            if (func_L01_0033D178(D_L02_001DE99C_g + v->f4) == 0) return 0;
        }
        m = (M_3A02D8 *)(D_L02_001DE99C_003A02D8 + (v->f18 ? v->f4 : v->f0));
        m->f10 = obj->f10;
        x = m->f68;
        x->fDC = 0;
        i = v->f1C;
        if (i >= 0) {
            x->f120 = (u8 *)D_L02_001DE99C_g + (i << 8);
            x->f100 = v->f20;
        }
        v->f8 = 0;
        v->fC = 0;
        if (obj->f43 != 1) func_003C3A10((O_003A0200 *)obj, 1, 0, 0);
        func_L01_004450F0((O_003A0200 *)obj, 1, 2);
        if (v->f1A != 0xFF) {
            v->f1B++;
        }
        return 1;
    }
    return 0;
}

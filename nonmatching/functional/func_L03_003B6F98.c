/* functional: high. Taken from the in-tree PAL port draft (nonmatching/levels/func_L03_003B6F98.c, 34 diff words), re-checked against the PAL asm: gp slots DEA64-DEA84, alpha step h96*5, -1 clamp. Same as func_L03_003B6180 spin block. */
/* localdecomp:start func_L03_003B6F98 */
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; f32 f3C; } S_3B5390;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_3B5390 *st; u8 p6C[0x96 - 0x6C]; u16 h96; } O_3B5390;

extern f32 func_003C4138(void *, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L03_003B6DF8(void *, s32, s32, s32, f32, f32, f32);

extern f32 D_001DEA6C_sda;
__asm__(".extern D_001DEA6C_sda, 4");
extern f32 D_001DEA64_sda;
__asm__(".extern D_001DEA64_sda, 4");
extern f32 D_001DEA68_sda;
__asm__(".extern D_001DEA68_sda, 4");
extern u32 D_001DEA74_sda;
__asm__(".extern D_001DEA74_sda, 4");
extern u32 D_001DEA78_sda;
__asm__(".extern D_001DEA78_sda, 4");
extern s32 D_001DEA7C_sda;
__asm__(".extern D_001DEA7C_sda, 4");
extern s32 D_001DEA80_sda;
__asm__(".extern D_001DEA80_sda, 4");
extern f32 D_001DEA84_sda;
__asm__(".extern D_001DEA84_sda, 4");

void func_L03_003B6F98(O_3B5390 *o) {
    S_3B5390 *st;
    f32 ang;
    u32 a;
    u32 b;
    s32 al;

    st = o->st;
    if (func_003C4138(&st->f38, st->f3C, D_001DEA6C_sda) == 0.0f) {
        if (st->f3C == D_001DEA64_sda) {
            st->f3C = D_001DEA68_sda;
        } else {
            st->f3C = D_001DEA64_sda;
        }
    }
    ang = func_0038DAB8(0.0f, st->f34 * 0.017453292f);
    if (o->b20 == 6) {
        a = D_001DEA74_sda;
        b = D_001DEA78_sda;
        al = (a >> 24) - (o->h96 * 5);
        if (al < 0) {
            al = 0;
        }
        a = (al << 24) | (a & 0xFF0000) | (a & 0xFF00) | (a & 0xFF);
        al = (b >> 24) - (o->h96 * 5);
        if (al < 0) {
            al = 0;
        }
        b = (al << 24) | (b & 0xFF0000) | (b & 0xFF00) | (b & 0xFF);
        func_L03_003B6DF8(o, D_001DEA80_sda, b, 1, st->f38, D_001DEA84_sda, -ang);
        func_L03_003B6DF8(o, D_001DEA7C_sda, a, 1, st->f38, D_001DEA84_sda, ang);
    } else {
        func_L03_003B6DF8(o, D_001DEA80_sda, D_001DEA78_sda, 1, st->f38, D_001DEA84_sda, -ang);
        func_L03_003B6DF8(o, D_001DEA7C_sda, D_001DEA74_sda, 1, st->f38, D_001DEA84_sda, ang);
    }
    st->f34 = st->f34 + 1.0f;
    if (st->f34 > 359.0f) {
        st->f34 = 0.0f;
    } else if (st->f34 < 0.0f) {
        st->f34 = 359.0f;
    }
}
/* localdecomp:end func_L03_003B6F98 */

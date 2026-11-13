/* func_L19_003CF930: 4 diff in L19_003CDD90.c (-mvu0-use-vf0-vf2 @ps2as): only the order of the two strength-reduced loop pointers (&d->e[i] and &d->e[i].pos). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CF930;
typedef struct { u8 pad[0x10]; V4_3CF930 pos; u8 pad2[0x90]; } E_3CF930;
typedef struct { u8 pad[4]; s32 x4; s32 x8; u8 pad2[0x34]; E_3CF930 e[4]; u8 pad3[0x300 - 0x40 - 4 * 0xB0]; u8 x300[4]; } D_3CF930;
extern u8 D_001A4C60[];
extern f32 func_0038CF00(void *, void *);
extern s32 func_0038DC20(void *, f32);
extern void func_L01_0040C948(void *, void *);
extern s32 func_00382468(s32);
extern void func_L19_003CF7B8(void *, s32, s32, s32, s32, f32, f32);

void func_L19_003CF930(u8 *obj) {
    D_3CF930 *d = *(D_3CF930 **)(obj + 0x68);
    V4_3CF930 p;
    V4_3CF930 q;
    V4_3CF930 r;
    f32 dist;
    s32 i;
    s32 n;
    s32 lvl;

    p = *(V4_3CF930 *)(obj + 0x10);
    p.w = 0.05f;
    dist = func_0038CF00(obj + 0x10, D_001A4C60);
    for (i = 0; i < d->x8; i++) {
        q = d->e[i].pos;
        q.w = 1.0f;
        if (func_0038DC20(&q, 64.0f) >= 0 || func_0038DC20(&p, 64.0f) >= 0)
            func_L01_0040C948(&d->e[i], d->x300);
        n = 0xF;
        lvl = 1;
        if (dist >= 10.0f) {
            n = 0xA;
            lvl = 2;
        } else if (dist >= 20.0f) {
            n = 5;
            lvl = 3;
        } else if (dist >= 30.0f) {
            n = 1;
            lvl = 4;
        } else if (dist > 35.0f) {
            lvl = 0;
        }
        if (lvl == 1 || (lvl > 0 && func_00382468(lvl) == 0)) {
            r = d->e[i].pos;
            func_L19_003CF7B8(&r, (n * 5 + 2) / 6, d->x4, (n * 5 + 2) / 6, -1, 0.5f, 1.0f);
        }
    }
}

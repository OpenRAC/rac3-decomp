/* Near miss of func_00385400 with its file's own flags: tools/check.py reports 144 diff
   (the version it replaces: 179).
*/

/* func_00385400 (boot_elf). Matched with the file's own flags
   (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division).

   The four screen constants (0x1D4BC8, 0x1D4BCC, 0x1D4BD0, 0x1D4BD4) are
   reached with lui/lo in retail, so they are read through their addresses
   instead of through a $gp-sized global (see docs/wiki/Matching-Patterns.md,
   "Globals: gp vs lui"). */

/* localdecomp:start func_00385400 */
typedef struct { u8 p0[0x10]; u8 pos[0x10]; u8 b20; } O_380D48;
typedef struct {
    O_380D48 *obj; s32 state; f32 f8; s32 pC;
    s16 h10[16]; s16 h30[16]; s32 c50[16]; f32 f90[16]; f32 fD0[16];
} S_380D48;
extern S_380D48 D_00222900;
extern f32 func_0038D2E0(void *, void *);
extern void func_00386488(f32 *, void *);
extern long func_00389978(s32);
extern void func_0038B8B0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
void func_00385400(void) {
    f32 scr[2];
    f32 ctr[2];
    f32 d[2];
    f32 o[2];
    f32 p[2];
    f32 dist, a, b, c, half, h;
    s32 i, size, w, col;
    long tex;
    if (D_00222900.state != 1 || (D_00222900.obj->b20 & 0x80)) {
        D_00222900.state = 0;
        return;
    }
    if (D_00222900.f8 <= 0.0f) return;
    dist = func_0038D2E0(D_00222480, D_00222900.obj->pos);
    ctr[1] = (f32)*(s32 *)0x001D4BCC;
    ctr[0] = (f32)*(s32 *)0x001D4BC8;
    func_00386488(scr, D_00222900.obj->pos);
    scr[0] = (scr[0] - (f32)*(s32 *)0x001D4BD0) * 0.0625f;
    scr[1] = (scr[1] - (f32)*(s32 *)0x001D4BD4) * 0.0625f;
    d[0] = ctr[0] - scr[0];
    d[1] = ctr[1] - scr[1];
    for (i = 0; i < 16; i++) {
        tex = func_00389978(D_00222900.h30[i] + 6);
        o[0] = d[0] * D_00222900.f90[i];
        o[1] = d[1] * D_00222900.f90[i];
        p[0] = ctr[0] + o[0];
        p[1] = ctr[1] + o[1];
        size = 0x40;
        if (i != 0) size = 0x20;
        a = dist - 5.0f;
        if (a > 1.0f) a = 1.0f;
        else if (a < 0.0f) a = 0.0f;
        b = __builtin_fabsf(d[0]) / ctr[0] * -5.0f + 5.5f;
        if (b > 1.0f) b = 1.0f;
        else if (b < 0.0f) b = 0.0f;
        c = __builtin_fabsf(d[1]) / ctr[1] * -5.0f + 5.5f;
        if (c > 1.0f) c = 1.0f;
        else if (c < 0.0f) c = 0.0f;
        a *= b * c;
        h = (f32)D_00222900.h10[i];
        col = D_00222900.c50[i] & 0xFFFFFF;
        w = (s32)((f32)size * D_00222900.fD0[i]);
        half = (f32)(w >> 1);
        func_0038B8B0((s32)(p[0] - half), (s32)(p[1] - half), w, w, 0, 0, size, size,
                      ((s32)(a * h) << 24) | col, tex);
    }
    D_00222900.f8 = 0.0f;
}
/* localdecomp:end func_00385400 */

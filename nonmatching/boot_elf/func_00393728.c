/* Near miss of func_00393728 with its file's own flags: tools/check.py reports 57 diff
   (the version it replaces: 61).
*/

/* US draft of func_00393728 (rac3-uya-decomp func_00393668, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_00393728 */
typedef struct { s32 f0; s32 f4; u8 p8[0x18]; s32 f20; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; u8 p3C[0x28]; s32 f64; s32 f68; u8 p6C[4]; s32 f70; u8 p74[8]; s32 f7C; u8 p80[0x10]; } S_EB;
extern S_EB D_00331AE0_00393728[];
extern s32 D_001D5B94_00393728;
extern s32 D_001D9E88_00393728;
extern s32 D_001D9E88_00393728x[];
extern void func_00393830();
s32 func_00393728(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g) {
    S_EB *s = &D_00331AE0_00393728[a & 0xF];
    s32 m = a & 0xFFF0;
    s32 n;
    if (*(s32 *)0x1D5B94 == 5 && (a & 0xF) != 2 && (a & 0xF) != 0) return 0;
    if (s->f2C != f || s->f28 != g || s->f20 != b || s->f24 != m || s->f30 != c || s->f34 != d || s->f38 != e) {
        s->f2C = f;
        s->f28 = g;
        s->f20 = b;
        s->f30 = c;
        s->f34 = d;
        s->f38 = e;
        n = D_001D9E88_00393728;
        s->f64 = n;
        D_001D9E88_00393728x[0] = n + 1;
        s->f68 = 1;
        s->f24 = m;
        s->f7C = 0;
        s->f70 = 0;
        if (m & s->f4 & 0x20) func_00393830(s);
    }
    return s->f64;
}
/* localdecomp:end func_00393728 */

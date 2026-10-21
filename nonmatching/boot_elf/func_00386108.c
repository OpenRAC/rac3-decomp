/* US draft of func_00386108 (rac3-uya-decomp func_003860E0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00386108 */
typedef struct { u8 p0[0x20]; u8 b20; } H_381A50;
typedef struct { u8 p0[0x10]; f32 f10; u8 p14[0xC]; H_381A50 *f20; u8 b24; u8 b25; u8 p26[0xA]; f32 f30, f34; u8 p38[8]; } E_381A50;
typedef struct { E_381A50 e[14]; s32 n; } T_381A50;
extern T_381A50 D_00224BC0_00386108;
extern s32 D_001A71A4_00386108[];
extern s32 D_001D5B98;
extern s32 D_001D4BC0_00386108, D_001D4BC4_00386108, D_001D4BD0_00386108, D_001D4BD4_00386108;
extern void func_00385A98(void);
extern void func_00386488(f32 *, void *);
extern void func_00385778(void *, f32, f32);
void func_00386108(s32 a) {
    f32 v[2];
    s32 i;
    E_381A50 *p;
    if (D_001A71A4_00386108[0] == 0x74) {
        D_00224BC0_00386108.n = 0;
        return;
    }
    func_00385A98();
    if (D_00224BC0_00386108.n == 0) return;
    for (i = 0; i < D_00224BC0_00386108.n; i++) {
        p = &D_00224BC0_00386108.e[i];
        if (p->b25 != a || p->f20 == 0 || p->f20->b20 == 0xFE || p->f20->b20 == 0xFD) continue;
        if (p->b24 != 0) {
            func_00386488(v, p);
            v[0] = (v[0] - (f32)D_001D4BD0_00386108) * 0.0625f;
            v[1] = (v[1] - (f32)D_001D4BD4_00386108) * 0.0625f;
        } else {
            v[0] = (f32)D_001D4BC0_00386108 * p->f30;
            v[1] = (f32)D_001D4BC4_00386108 * p->f34;
        }
        if (D_001D5B98 != 0) p->f10 *= 0.75f;
        func_00385778(p, v[0], v[1]);
    }
    if (D_001D5B98 == 0) D_00224BC0_00386108.n = 0;
}
/* localdecomp:end func_00386108 */

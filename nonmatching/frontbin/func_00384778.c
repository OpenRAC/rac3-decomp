/* US draft of func_00384778 (rac3-uya-decomp func_003804A0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00384778 */
typedef struct { f32 x, y, z, w; } V_3804A0;
typedef union { u128_t q; V_3804A0 v; } Q_3804A0;
typedef struct { Q_3804A0 q0; u8 pad10[0x40]; u8 *f50; u8 pad54[0x3FC]; s32 f450; u8 pad454[0xC]; } E_3804A0;
extern E_3804A0 D_00222480_00384778[];
extern s32 D_001D5B94;
extern u128_t D_00227660[];
extern s32 func_003D3CB0();
extern s32 func_003D5630(void);
extern f32 func_003C3EC8_00384778(void *, s32);
void func_00384778(s32 idx) {
    E_3804A0 *e = &D_00222480_00384778[idx];
    Q_3804A0 a, b;
    s32 i;
    if (*(s16 *)(e->f50 + 0x86) == 6 || D_001D5B94 != 0) {
        e->f450 = 0;
        return;
    }
    a.q = e->q0.q;
    b.q = e->q0.q;
    b.v.z -= 0.75f;
    a.v.z += 0.75f;
    i = 0;
    while (i < 6 && func_003D3CB0(&a, &b, 0x12, 0, 0)) {
        if (func_003D5630() == 0) {
            f32 r = func_003C3EC8_00384778(D_00227660, 0);
            if (D_00222480_00384778[idx].q0.v.z < r + 0.04f) {
                D_00222480_00384778[idx].f450 = 1;
            } else {
                D_00222480_00384778[idx].f450 = 0;
            }
            return;
        }
        i++;
        a.q = D_00227660[0];
        a.v.z -= 0.01f;
    }
}
/* localdecomp:end func_00384778 */

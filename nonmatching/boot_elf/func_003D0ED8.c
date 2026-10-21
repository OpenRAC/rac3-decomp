/* US draft of func_003D0ED8 (rac3-uya-decomp func_003D0D70, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003D0ED8 */
typedef int u128_3CB5B0 __attribute__((mode(TI)));
typedef struct { u8 p0[0x350]; f32 f350, f354, f358; s32 x35C; } L_3CB5B0;
typedef struct { u8 p0[0x10]; u128_3CB5B0 q10; } B_3CB5B0;
typedef struct { u8 p0[0x10]; s32 state; u8 p1[0xC]; u128_3CB5B0 q20; } E_3CB5B0;
__asm__(".extern D_001D9310, 8");
extern s32 D_001D9310[2];
extern f32 D_00222418[];
extern u8 D_002FF200[];
extern B_3CB5B0 D_002FF600[];
extern E_3CB5B0 D_002FF700[];
extern void func_0038DE98(f32, f32);
extern f32 func_0038D478(f32);
extern f32 func_0038D490(f32);
extern f32 func_0038D2E0(void *, void *);
extern void func_003D1070(void *);
extern void func_003D1188(void *);
void func_003D0ED8(void) {
    L_3CB5B0 *l;
    f32 r;
    s32 i;
    *(u128_3CB5B0 *)(D_002FF200 + 0x340) = *(u128_3CB5B0 *)D_001D9310;
    r = ((f32 (*)(f32, f32))func_0038DE98)(D_00222418[0], -0.8f);
    l = (L_3CB5B0 *)D_002FF200;
    l->f350 = func_0038D478(r) * 0.866f;
    l->f354 = func_0038D490(r) * 0.866f;
    l->f358 = -0.5f;
    l->x35C = 0;
    for (i = 0; i < 8; i++) {
        B_3CB5B0 *b = &D_002FF600[i];
        E_3CB5B0 *e = &D_002FF700[i];
        if (e->state != 0) {
            if (1.0f < func_0038D2E0(&b->q10, &e->q20) ||
                1.0f < fabsf(*(f32 *)((u8 *)b + 0x1C) - *(f32 *)((u8 *)e + 0x2C))) {
                e->q20 = b->q10;
                if (e->state == 1) {
                    func_003D1070((void *)i);
                    e->state = 2;
                } else if (e->state == 2) {
                    func_003D1188((void *)i);
                }
            }
        }
    }
}
/* localdecomp:end func_003D0ED8 */

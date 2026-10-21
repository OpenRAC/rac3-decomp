/* US draft of func_00382CB8 (rac3-uya-decomp func_00382CC0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00382CB8 */
typedef struct { u8 pad[0x424]; f32 f424; f32 f428; f32 f42C; f32 f430; f32 f434; u8 b438; u8 b439; s16 h43A; f32 f43C; f32 f440; u8 pad2[0x1C]; } E_0037E630;
extern E_0037E630 D_00222480_00382CB8[];
extern f32 D_002259B0[];
extern void func_00383038(f32 *, f32, f32, f32, f32, f32);
extern s32 func_0038CEE0(void *);
extern f32 func_0038D478(f32);
extern f32 func_0038D490(f32);
extern f32 func_003C3FA0(f32, f32, f32);
extern void func_003877A0();
void func_00382CB8(s32 idx) {
    E_0037E630 *e = &D_00222480_00382CB8[idx];
    f32 a; f32 b; f32 v;
    if (e->b439 == 1) {
        switch (e->b438) {
        case 0:
            e->b439 = 0;
            e->f428 = e->f424;
            break;
        case 3:
            v = ((f32 (*)(f32 *, f32, f32, f32, f32, f32))func_00383038)(&e->f424 - 1, e->f428, e->f424, e->f42C, e->f430, e->f434);
            e->f428 = v;
            { f32 d = v - e->f424, r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(d)); if (r < 0.0001f) e->b439 = 0; }
            break;
        case 1:
            if (func_0038CEE0(&e->h43A) != 0) e->b439 = 0;
            { f32 t = (f32)e->h43A * e->f43C; e->f428 = e->f424 + (e->f440 - e->f424) * t; }
            break;
        case 2:
            if (func_0038CEE0(&e->h43A) != 0) e->b439 = 0;
            e->f428 = func_003C3FA0(e->f424, e->f440, (f32)e->h43A * e->f43C);
            break;
        }
        a = e->f428 * 0.5f;
        b = func_0038D490(a);
        D_002259B0[0] = b / func_0038D478(a);
        func_003877A0();
    }
}
/* localdecomp:end func_00382CB8 */

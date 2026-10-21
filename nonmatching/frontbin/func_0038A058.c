/* Near miss of func_0038A058 with its file's own flags: tools/check.py reports 61 diff
   (the US draft it started from: 114).
   What differs: Two things still differ from retail. (1) The last constant of the struct
   (s.f88, value 0x8000000044): retail builds it at run time as `ori $a1,$zero,0x8000 ; dsll
   $a1,$a1,24 ; ori $a1,$a1,0x44`, i.e. a 64-bit shift of 0x8000 by 24; our gcc folds any
   constant 64-bit shift and then synthesises the folded value in the "high word" form `addiu
   $a1,$zero,0x80 ; dsll32 $a1,$a1,0 ; ori $a1,$a1,0x44` (the same value, different
   instructions). `(0x8000UL << 24)
*/

/* PAL candidate for func_0038A058 (frontbin, file src/frontbin/382380.c).
   Changes against the US draft:
   - the loop counter global is read as an unsized array element, so gcc
     addresses it with lui/lw instead of $gp;
   - the last constant is built as a shift, like retail does. */

/* localdecomp:start func_0038A058 */
typedef struct { f32 x, y, z, w; } V_385980;
typedef union { u128_t q; V_385980 v; } Q_385980;
typedef struct { f32 x, y, u, v; } T_385980;
typedef struct { Q_385980 v[4]; s32 col[4]; f32 uv[4][2]; long f70, f78, f80, f88; } S_385980;
extern long func_00389598(s32);
extern void func_003D2DA0();
__asm__(".extern D_001D5900, 8");
extern s32 D_001D5900[2];
extern s32 D_001D9C40[];
extern s32 D_001D9C40_0038A058a[];
extern Q_385980 D_00227010[];
void func_0038A058(void) {
    S_385980 s;
    Q_385980 t;
    s32 i, j, k;
    f32 dot, w;
    if (D_001D9C40[0] == 0) return;
    s.f78 = func_00389598(0);
    s.f80 = 0xFF9000000260UL;
    s.f70 = 5;
    s.f88 = 0x8000000000UL | 0x44;
    for (j = 0; j < 4; j++) {
        s.uv[j][0] = ((T_385980 *)D_001D5900)[j].u;
        s.uv[j][1] = ((T_385980 *)D_001D5900)[j].v;
        s.col[j] = 0x40808080;
    }
    for (i = 0; i < D_001D9C40_0038A058a[0]; i++) {
        t.q = D_00227010[i * 2].q;
        func_0038CF68((s32)&t, (s32)&t, 1.0f);
        w = ((Q_385980 *)((u8 *)D_00227010 + i * 32 - 16))->v.w;
        for (k = 0; k < 4; k++) {
            T_385980 *src = &((T_385980 *)D_001D5900)[k];
            dot = src->x * t.v.x + src->y * t.v.y;
            s.v[k].q = ((Q_385980 *)((u8 *)D_00227010 + i * 32 - 16))->q;
            s.v[k].v.x += (src->x - t.v.x * dot) * w;
            s.v[k].v.y += (src->y - t.v.y * dot) * w;
            s.v[k].v.z -= t.v.z * dot * w;
        }
        func_003D2DA0(&s, 0, 0);
    }
}
/* localdecomp:end func_0038A058 */

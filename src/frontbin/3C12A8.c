#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0038CC88_00391678(void *, void *, s32) __asm__("func_0038CC88");
extern void func_003BC768();
extern void func_003BDF40();
extern void func_003C0CA0();
extern void func_003C12A8();
/* --- end of declarations from other files --- */


typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BBD98;
typedef int Q_3BBD98 __attribute__((mode(TI)));
typedef struct {
    V_3BBD98 l0;
    V_3BBD98 v[4];
    u32 col[4];
    u8 pk[0x20];
    unsigned long g[4];
    V_3BBD98 a0, b0, c0, d0, e0, f0, o100, c110, v120, v130, v140;
} L_3BBD98;
/* PAL candidate for func_003C1490 (frontbin). The US draft called func_003A26D0;
   in PAL that callee is func_003A7AF8 (src/frontbin/3A53E8.c). */
/* localdecomp:start func_003C12A8 */
/* the copy of func_003C1660 */
#include "vu0.h"
extern void func_0038CF68(s32, s32, f32);
extern u8 D_00222400[];
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003C12A8;
typedef int Q_003C12A8 __attribute__((mode(TI)));
typedef struct {
    V_003C12A8 l0;
    V_003C12A8 v[4];
    u32 col[4];
    u8 pk[0x20];
    unsigned long g[4];
    V_003C12A8 a0,b0,c0,d0,e0,f0,o100,c110,v120,v130,v140;
} L_003C12A8;
extern u8 D_002D2008_003C12A8[];
typedef struct { u8 pad[0x54]; u8 *moby; } G_003C12A8;
extern G_003C12A8 D_00225700_003C12A8;
extern V_003C12A8 D_001D8FD0_003C12A8[] __attribute__((section(".sdata")));
extern u8 D_001D9010_003C12A8[] __attribute__((section(".sdata")));
__asm__(".extern D_001D8FD0_003C12A8, 4");
__asm__(".extern D_001D9010_003C12A8, 4");
void func_003C12A8(u8 *moby)
{
    extern void func_003BC670_003C12A8(s32, void *);
    extern void func_0038CD28_003C12A8(void *, void *, s32);
    extern void func_003A9440_003C12A8(s32, unsigned long);
    extern void func_0038CF68(s32, s32, f32);
    extern void func_0038CE90_003C12A8(void *, void *, void *);
    extern void func_0038CE20_a003C12A8(f32 *, void *, f32) __asm__("func_0038CE20");
    extern void func_0038D028_003C12A8();
    extern void func_003D2DA0_003C12A8();
    extern void func_003C1490(u8 *);
    L_003C12A8 s;
    s32 i;
    u8 *g = D_002D2008_003C12A8;
    if (g[0x51] != 0) {
        func_003BC670_003C12A8(*(s32 *)g, g + 8);
        s.l0 = *(V_003C12A8 *)(moby + 0x10);
        s.g[1] = *(unsigned long *)(g + 8);
        s.g[2] = 0xFF9000000260UL;
        s.g[3] = (0x8000UL << 24) | 0x44;
        s.g[0] = 0;
        func_0038CD28_003C12A8(s.pk, D_001D9010_003C12A8, 0x20);
        func_003A9440_003C12A8(0x47, 0x5360B);
        vec_sub_ba(&s.v120, &D_00222400[0], &s.l0);
        func_0038CF68((s32)&s.v120, (s32)&s.v120, 1.0f);
        s.v130.x = 0;
        s.v130.y = 0;
        s.v130.z = -1.0f;
        s.v130.w = 0;
        func_0038CE90_003C12A8(&s.v140, &s.v130, &s.v120);
        s.b0 = s.v120;
        s.c0 = s.v140;
        s.a0 = s.v130;
        s.e0 = s.v140;
        s.f0 = s.v120;
        func_0038CE20_a003C12A8((f32 *)&s.o100, &s.a0, -1.0f);
        s.c110 = s.l0;
        for (i = 0; i < 4; i++) {
            s.col[i] = 0x80808080;
            func_0038CE20_a003C12A8((f32 *)&s.v[i], &D_001D8FD0_003C12A8[i], 25.0f);
            func_0038D028_003C12A8(&s.v[i], &s.v[i], &s.e0);
        }
        func_003D2DA0_003C12A8(s.v, 0, 0);
        func_003A9440_003C12A8(0x47, 0x5360B);
    }
    func_003C1490(D_00225700_003C12A8.moby);
}
/* localdecomp:end func_003C12A8 */

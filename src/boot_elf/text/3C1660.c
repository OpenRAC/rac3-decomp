#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0038D200(f32 *, void *, f32);
void func_003C1660();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003C1660 */
#include "vu0.h"
extern void func_0038D348(s32, s32, f32);
extern u8 D_00222400[];
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003C1660;
typedef int Q_003C1660 __attribute__((mode(TI)));
typedef struct {
    V_003C1660 l0;
    V_003C1660 v[4];
    u32 col[4];
    u8 pk[0x20];
    unsigned long g[4];
    V_003C1660 a0,b0,c0,d0,e0,f0,o100,c110,v120,v130,v140;
} L_003C1660;
extern u8 D_002D2008_003C1660[];
typedef struct { u8 pad[0x54]; u8 *moby; } G_003C1660;
extern G_003C1660 D_00225700_003C1660;
extern V_003C1660 D_001D8FD0_003C1660[] __attribute__((section(".sdata")));
extern u8 D_001D9010_003C1660[] __attribute__((section(".sdata")));
__asm__(".extern D_001D8FD0_003C1660, 4");
__asm__(".extern D_001D9010_003C1660, 4");
void func_003C1660(u8 *moby)
{
    extern void func_003BCA28_003C1558(s32, void *);
    extern void func_0038D108_003C1558(void *, void *, s32);
    extern void func_003A97F8_003C1558(s32, unsigned long);
    extern void func_0038D348(s32, s32, f32);
    extern void func_0038D270_003C1558(void *, void *, void *);
    extern void func_0038D200(f32 *, void *, f32);
    extern void func_0038D408_003C1558();
    extern void func_003D3158_003C1558();
    extern void func_003C1848(u8 *);
    L_003C1660 s;
    s32 i;
    u8 *g = D_002D2008_003C1660;
    if (g[0x51] != 0) {
        func_003BCA28_003C1558(*(s32 *)g, g + 8);
        s.l0 = *(V_003C1660 *)(moby + 0x10);
        s.g[1] = *(unsigned long *)(g + 8);
        s.g[2] = 0xFF9000000260UL;
        s.g[3] = (0x8000UL << 24) | 0x44;
        s.g[0] = 0;
        func_0038D108_003C1558(s.pk, D_001D9010_003C1660, 0x20);
        func_003A97F8_003C1558(0x47, 0x5360B);
        vec_sub_ba(&s.v120, &D_00222400[0], &s.l0);
        func_0038D348((s32)&s.v120, (s32)&s.v120, 1.0f);
        s.v130.x = 0;
        s.v130.y = 0;
        s.v130.z = -1.0f;
        s.v130.w = 0;
        func_0038D270_003C1558(&s.v140, &s.v130, &s.v120);
        s.b0 = s.v120;
        s.c0 = s.v140;
        s.a0 = s.v130;
        s.e0 = s.v140;
        s.f0 = s.v120;
        func_0038D200((f32 *)&s.o100, &s.a0, -1.0f);
        s.c110 = s.l0;
        for (i = 0; i < 4; i++) {
            s.col[i] = 0x80808080;
            func_0038D200((f32 *)&s.v[i], &D_001D8FD0_003C1660[i], 25.0f);
            func_0038D408_003C1558(&s.v[i], &s.v[i], &s.e0);
        }
        func_003D3158_003C1558(s.v, 0, 0);
        func_003A97F8_003C1558(0x47, 0x5360B);
    }
    func_003C1848(D_00225700_003C1660.moby);
}
/* localdecomp:end func_003C1660 */

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
extern u8 D_002D2008_003C1558[];
extern u8 D_00225700_003C1558[];
extern V_3BBD98 D_00222400_003C1558;
extern u8 D_1D8FD0_003C1558[8];
extern u8 D_1D9010_003C1558[8];
extern void func_003BCA28_003C1558(s32, void *);
extern void func_0038D108_003C1558(void *, void *, s32);
extern void func_003A97F8_003C1558(s32, unsigned long);
extern void func_0038D348_003C1558(void *, void *, f32);
extern void func_0038D270_003C1558(void *, void *, void *);
extern void func_0038D200_003C1558(void *, void *, f32);
extern void func_0038D408_003C1558(void *, void *, void *);
extern void func_003D3158_003C1558();
extern void func_003C1848_003C1558(void *);
extern void func_003A6B90(void *);
extern void func_003A8850();

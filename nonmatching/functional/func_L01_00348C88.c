/* functional: high. Near miss (40 words) in VU0/float scheduling only; same reads, writes, calls and return values. */
/* localdecomp:start func_L01_00348C88 */
#include "vu0.h"
typedef struct { vu0_q a,b; vu0_v4 c; vu0_q d,e; s16 active,timer; f32 u,v; s32 tail; } Row_00348C88;
__asm__(".extern D_001DD35C_sda, 4");
__asm__(".extern D_001DD394_sda, 4");
__asm__(".extern D_001DD370_sda, 4");
extern f32 D_001DD35C_sda __attribute__((section(".sdata")));
extern f32 D_001DD394_sda __attribute__((section(".sdata")));
extern f32 D_001DD370_sda __attribute__((section(".sdata")));
s32 func_L01_00348C88(u8 *self) {
    extern char *func_L01_00457480(s32, s32);
    extern Info *func_L01_004574B0(s32, s32);
    extern s32 func_0038CB00(void *);
    extern void func_0038CF68(void *, void *, f32);
    u8 *p = *(u8 **)(self + 0x68);
    Row_00348C88 *rows;
    vu0_v4 v;
    rows = (Row_00348C88 *)(func_L01_00457480(0xC04, *(s16 *)(p + 0x1A)) + func_L01_004574B0(0xC04, *(s16 *)(p + 0x1A))->unk0);
    if (!rows[*(s16 *)(p + 0x18)].active) return 0;
    if (func_0038CB00(&rows[*(s16 *)(p + 0x18)].timer)) {
        rows[*(s16 *)(p + 0x18)].active = 0;
        return 0;
    }
    rows[*(s16 *)(p + 0x18)].c = *(vu0_v4 *)(self + 0x10);
    rows[*(s16 *)(p + 0x18)].u += D_001DD35C_sda;
    if (rows[*(s16 *)(p + 0x18)].u >= 4.0f) rows[*(s16 *)(p + 0x18)].u -= 4.0f;
    rows[*(s16 *)(p + 0x18)].v += D_001DD394_sda;
    if (rows[*(s16 *)(p + 0x18)].v >= 4.0f) rows[*(s16 *)(p + 0x18)].v -= 4.0f;
    func_0038CF68(&v, p, D_001DD370_sda * 0.020000001415610313f);
    {
        vu0_q *dst = &rows[*(s16 *)(p + 0x18)].a;
        __asm__("lqc2 vf2, %2\n\tlqc2 vf1, %1\n\tvadd.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(*dst) : "m"(*dst), "m"(v) : "vf1", "vf2");
    }
    {
        vu0_q *dst = &rows[*(s16 *)(p + 0x18)].b;
        __asm__("lqc2 vf2, %2\n\tlqc2 vf1, %1\n\tvadd.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(*dst) : "m"(*dst), "m"(v) : "vf1", "vf2");
    }
    return 1;
}
/* localdecomp:end func_L01_00348C88 */

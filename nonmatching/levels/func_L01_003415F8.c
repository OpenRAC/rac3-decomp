/* func_L01_003415F8 (Claude wave 14 r64, 2026-11-28). Replaces the earlier draft of this function (Codex wave 10 near miss). */
/* PAL near miss: shield_charger_fire. 1 word differs with the file's flags (wave 14 r64, 2026-11-28; the
 * round 14 draft had 2). This attempt assigns z (obj+0xE0) before y (obj+0xD0), retail's order of the two
 * addiu after the func_0038D308 call, and copies D_L01_001E1900[0] through z: the extra use raises z's
 * global-alloc priority above y's again, so z gets $s4 and y $s5 as in retail. What still differs: that
 * copy loads lq 0($s4) where retail has lq 0xE0($s2) (retail's z has a single use). With z first and the
 * copy through obj+0xE0 the priorities flip (lreg: z 2 refs over 30 insns, y 3 refs over 43) and the two
 * $s registers swap (5 words). Tried without closing it: an explicit obj+0xC0 variable in any order,
 * obj+0xD0/obj+0xE0 instead of y/z at single uses, z in the vector add, struct/array/symbol forms of the
 * D_L01_001E1900 copies, vectors + 60 instead of sum.
 */
#include "common.h"
/* localdecomp:start func_L01_003415F8 */
#include "vu0.h"
__asm__(".extern D_L01_001DD298, 4");
extern s32 D_L01_001DD298;
__asm__(".extern D_L01_001DD260, 4");
extern f32 D_L01_001DD260;
__asm__(".extern D_L01_001E19D4, 4");
extern f32 D_L01_001E19D4;
extern u8 D_L01_001FE62C[];
extern s32 D_L01_001FD180[];
extern vu0_q D_001A4C60;
extern s32 D_L01_001E1940[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1950[] __attribute__((section(".sdata")));
extern s16 D_L01_001E1990[] __attribute__((section(".sdata")));
extern vu0_v4 D_L01_00278F80[][20];
extern vu0_v4 D_L01_001E1900[] __attribute__((section(".sdata")));
extern vu0_q D_L01_001E1910;
extern vu0_q D_L01_001E1920;
extern vu0_v4 D_L01_001E1930;
typedef struct {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[0xF];
    u8 alpha;
    u8 pad31[3];
    u16 flags;
    u8 pad36[0x32];
    u8 *vars;
} Moby_003415F8;
u8 *func_L01_003415F8(s32 kind) {
    extern s32 func_L01_005118D0(s32, s32);
    extern void func_003A4FF8(void *, s32, s32, void *, s32);
    extern u8 *func_003C24B0(s32, s32);
    extern void func_0038D308(void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_L01_004C93E0(s32);
    extern f32 func_L01_004C93D8(void);
    extern void func_003A52A0(s32, s32, void *);
    u8 *obj, *p;
    s32 i;
    s32 j, k, n, t;
    void *y, *z;
    vu0_v4 *vectors, *sum;
    s16 *small;
    s32 *counts;
    s32 class_id;
    if (D_L01_001DD298) {
        func_003A4FF8(*(u8 **)((u8 *)D_L01_001FD180[D_L01_001FE62C[0]] + 0x28) + 0x80, 0, 0, &D_001A4C60, 0x400);
        return 0;
    } else if (!func_L01_005118D0(0x16, 1)) {
        func_003A4FF8(*(u8 **)((u8 *)D_L01_001FD180[D_L01_001FE62C[0]] + 0x28), 0, 0, &D_001A4C60, 0x400);
        return 0;
    }
    class_id = (kind >= 4) ? 0x1192 : 0xA5C;
    obj = func_003C24B0(class_id, 0x80);
    if (obj) {
        p = ((Moby_003415F8 *)obj)->vars;
        D_L01_001DD298 = (s32)obj;
        ((Moby_003415F8 *)obj)->flags |= 0x41;
        ((Moby_003415F8 *)obj)->alpha = 0xFF;
        ((Moby_003415F8 *)obj)->state = 1;
        func_0038D308(obj + 0xC0, obj + 0xF0);
        z = obj + 0xE0;
        y = obj + 0xD0;
        for (i = 3; i >= 0; i--) D_L01_001E1940[i] = 0;
        vectors = &D_L01_00278F80[0][0];
        sum = vectors + 60;
        small = (s16 *)(p + 0x18);
        func_0038CF68(vectors, obj + 0xC0, D_L01_001DD260);
        counts = (s32 *)(p + 0x20);
        *(vu0_q *)&D_L01_001E1900[0] = *(vu0_q *)z;
        func_0038CF68(vectors + 20, y, D_L01_001DD260);
        *(vu0_q *)&D_L01_001E1900[1] = *(vu0_q *)(obj + 0xC0);
        func_0038CF68(vectors + 40, z, D_L01_001DD260);
        *(vu0_q *)&D_L01_001E1900[2] = *(vu0_q *)(obj + 0xD0);
        vec_add_ba(sum, obj + 0xC0, obj + 0xE0);
        func_0038CF68(sum, sum, D_L01_001DD260);
        func_0038CE90(&D_L01_001E1900[3], sum, y);
        for (j=7; j>=0; j--) D_L01_001E1950[j] = 0;
        for (k=4; k>=0; k--) D_L01_001E1990[k] = 0;
        D_L01_001E19D4 = 1.0f;
        func_L01_004C93E0(kind);
        *(f32 *)p = func_L01_004C93D8();
        *(vu0_q *)(obj + 0x10) = D_001A4C60;
        *(s32 *)(p + 0xC) = -1;
        *(s32 *)(p + 0x10) = 0;
        *(s32 *)(p + 0x14) = 0x19;
        for (n=3; n>=0; n--) small[n] = 0;
        for (t=3; t>=0; t--) counts[t] = 0;
        func_003A52A0(1, 0, obj);
    }
    return obj;
}
/* localdecomp:end func_L01_003415F8 */

/* PAL near miss: shield_charger_fire. 2 words differ with the file's flags (round 14, 2026-11-24;
 * was 51 for haiku-w4's draft). Only the two addiu after the func_0038D308 call are swapped: retail
 * computes obj+0xE0 (into $s4) before obj+0xD0 (into $s5). Assigning z before y gives retail's order
 * but swaps the registers (5 words): z's longer live range drops its global-alloc priority below y's.
 * Moving the y/z declarations, renaming, or using z in the vector add or the D_L01_001E1900[0] copy
 * (1 word, but lq 0($s4) where retail has lq 0xE0($s2)) don't close it.
 * What closed the gap: the moby fields through a struct (Moby_003415F8) in the order vars, D298,
 * flags, alpha, state (a 120-order sweep: only this one, with struct fields, keeps retail's store
 * order and $a0 for 0xFF); D_L01_001E1900[0..3] as one sdata array (was three symbols);
 * D_L01_001E1940/1950/1990[i] with the arrays' real bases (the draft cleared from 0x1E194C + 0xC);
 * D_L01_001FE62C and D_L01_001FD180 without a known size (gcc splits the address, as retail does);
 * the three vars stores in the order 0xC, 0x10, 0x14; func_0038CF68/func_0038CE90 declared in the
 * block (they are declared only in later blocks of the file); the file's D_L01_ names for the $gp
 * globals.
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
        y = obj + 0xD0;
        z = obj + 0xE0;
        for (i = 3; i >= 0; i--) D_L01_001E1940[i] = 0;
        vectors = &D_L01_00278F80[0][0];
        sum = vectors + 60;
        small = (s16 *)(p + 0x18);
        func_0038CF68(vectors, obj + 0xC0, D_L01_001DD260);
        counts = (s32 *)(p + 0x20);
        *(vu0_q *)&D_L01_001E1900[0] = *(vu0_q *)(obj + 0xE0);
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

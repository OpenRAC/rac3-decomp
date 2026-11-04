#include "common.h"

typedef struct {
    s32 v[10];
} S_003FF4E8;

typedef struct WeightTap_00400390 {
    u8 row;
    u8 col;
    s16 weight;
} WeightTap_00400390;

INCLUDE_ASM("asm/levels", func_L01_003FE908);

INCLUDE_ASM("asm/levels", func_L01_003FE938);

INCLUDE_ASM("asm/levels", func_L01_003FEA00);

INCLUDE_ASM("asm/levels", func_L01_003FEA68);

INCLUDE_ASM("asm/levels", func_L01_003FF240);

INCLUDE_ASM("asm/levels", func_L01_003FF4E8);

INCLUDE_ASM("asm/levels", func_L01_003FF570);

INCLUDE_ASM("asm/levels", func_L01_003FF9F0);

INCLUDE_ASM("asm/levels", func_L01_003FFC88);

INCLUDE_ASM("asm/levels", func_L01_003FFED0);

/* localdecomp:start func_L01_004000C0 */
typedef struct {
    s32 value;          
    s32 key;            
    char pad08[8];
} Rec_2e36f8;
extern s32 D_L01_001E64C0[];

/* from rac2-decomp's func_L00_002E36F8, renamed */
s32 func_L01_004000C0(s32 key)
{
    Rec_2e36f8 *entry;
    s32 count = D_L01_001E64C0[4];
    s32 i;
    if (count > 0) {
        i = 0;
        entry = (Rec_2e36f8 *)D_L01_001E64C0[3];
        do {
            if (entry->key == key)
                return entry->value;
            entry++;
            i++;
        } while (i < count);
    }
    return 0;
}
/* localdecomp:end func_L01_004000C0 */

INCLUDE_ASM("asm/levels", func_L01_00400100);

INCLUDE_ASM("asm/levels", func_L01_00400160);

/* localdecomp:start func_L01_004001C8 */
void func_0038CAD0(void *);
extern u8 D_L01_001E64EC[];

void func_L01_004001C8(void) {
    func_0038CAD0(D_L01_001E64EC);
}
/* localdecomp:end func_L01_004001C8 */

INCLUDE_ASM("asm/levels", func_L01_004001E8);

INCLUDE_ASM("asm/levels", func_L01_00400280);

/* localdecomp:start func_L01_00400368 */
/* from rac2-decomp's func_L00_002E3A68, renamed */
s32 func_L01_00400368(f32 a,f32 b,f32 t) {
 f32 difference=b-a;
 f32 squared=t*t;
 a=a*t;
 difference=difference*squared;
 a=a+difference;
 return (s32)a;
}
/* localdecomp:end func_L01_00400368 */

/* localdecomp:start func_L01_00400390 */
extern u8 D_00142692[];
extern WeightTap_00400390 D_L01_002C0160[][16][10];
extern s32 D_1C5290[][16];

s32 func_L01_00400390(s32 a0, s32 a1) {
    WeightTap_00400390 *tap;
    s32 sum;
    s32 n;

    if (D_00142692[0] != 0) {
        return 0;
    }
    if (a0 >= 30) {
        return 0;
    }
    if (a1 >= 16) {
        return 0;
    }
    tap = D_L01_002C0160[a0][a1];
    sum = 0;
    for (n = 9; n >= 0; n--) {
        sum += tap->weight * D_1C5290[tap->row][tap->col];
        tap++;
    }
    return sum;
}
/* localdecomp:end func_L01_00400390 */

/* localdecomp:start func_L01_00400430 */
extern u8 D_00142692[];
extern s32 D_001D545C;
extern s32 func_L01_00400390(s32 a0, s32 a1);
s32 func_L01_00400430(s32 a0) {
    u8 s = D_00142692[0];
    s32 v;
    if (s != 0) {
        return 3;
    }
    v = 3 - func_L01_00400390(D_001D545C, a0) / 100;
    if (s < v) {
        return v;
    }
    return 1;
}
/* localdecomp:end func_L01_00400430 */

INCLUDE_ASM("asm/levels", func_L01_00400490);

INCLUDE_ASM("asm/levels", func_L01_004004F8);

/* localdecomp:start func_L01_004006C8 */
extern u8 D_1BBE90[][1024];

s32 func_L01_004006C8(u8 *a0, s32 a1, s32 a2) {
    s32 c = D_1BBE90[*(s32 *)0x1D545C][a2 >> 1];

    return (a0[(a2 & 1) ? ((c >> 4) & 7) : (c & 7)] * a1) / 100;
}
/* localdecomp:end func_L01_004006C8 */

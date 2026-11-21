/* NEAR MISS (50 diff): jump table and case bodies right (5-entry table via 'case 3: case 4: return 0'). Differs: retail picks the table row as base+idx*8 then lw 0x6188(row) (no constant folding into the symbol) and branches (beql) for the 4/1 state instead of movz; retail also loads the s16 flag into v1. Needs Row_004A28C8 from func_L01_004A28C8's block in src/levels/shared/L01_004A28C8.c. */
#include "common.h"
typedef struct { s32 a, b; } Row2_004A2E88;
typedef struct { u8 p0[0x6188]; s32 a, b; } RowB_004A2E88;
typedef struct { u8 p0[0x4954]; s32 f4954; u8 p1[0x6188 - 0x4958]; Row2_004A2E88 f6188[1]; } Big_004A2E88;
typedef struct { u8 p0[0x2C]; s32 f2C; } Tab_004A2E88;
extern s32 D_L01_001D96F0;
__asm__(".extern D_L01_001D96F0, 4");
extern u32 *D_L01_001D96E8;
__asm__(".extern D_L01_001D96E8, 4");
extern Row_004A28C8 *D_L01_001D96CC;
__asm__(".extern D_L01_001D96CC, 4");
extern s32 D_L01_001D96D0;
__asm__(".extern D_L01_001D96D0, 4");
extern s16 D_001CCFD4;
extern u8 D_00143A07;
extern Big_004A2E88 D_00160C40;
extern Tab_004A2E88 D_L01_002E5F30;
extern s32 func_0045FD90(u32 *, s32, s32);
extern void func_L01_004A2FC0(void);

s32 func_L01_004A2E88(void) {
    u32 *a;
    u32 *p;
    s32 i;
    s32 n;
    s32 next;
    switch (D_L01_001D96F0) {
    case 0:
        if (D_001CCFD4 != 0) {
            return 1;
        }
        {
            RowB_004A2E88 *r = (RowB_004A2E88 *)((u8 *)&D_00160C40 + D_00143A07 * 8);
            D_L01_001D96F0 = 4;
            if (func_0045FD90(D_L01_001D96E8, r->a + D_00160C40.f4954, r->b) != 0) {
                D_L01_001D96F0 = 1;
            }
            return 1;
        }
        break;
    case 1:
        if (D_001CCFD4 != 0) {
            return 1;
        }
        a = D_L01_001D96E8;
        n = *a >> 4;
        i = 0;
        D_L01_001D96CC = D_L01_001DFCC0;
        D_L01_001D96D0 = D_L01_002E5F30.f2C;
        D_L01_001DFCC0 = (Row_004A28C8 *)a;
        D_L01_002E5F30.f2C = n;
        if (n != 0) {
            p = a;
            do {
                *p = *p + (u32)a;
                i++;
                p += 4;
            } while (i < D_L01_002E5F30.f2C);
        }
        next = 2;
        break;
    case 2:
        func_L01_004A2FC0();
        D_L01_001D96F0 = 3;
        return 0;
    case 3:
    case 4:
        return 0;
    }
    D_L01_001D96F0 = next;
    return 1;
}

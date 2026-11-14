#include "common.h"

/* declared by functions of L40_00490F48.c, which this file was cut from */
extern void func_L40_00491270(void);
extern void func_L40_004913B8(void);

/* localdecomp:start func_L40_00491270 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00491270;

typedef struct {
    V4_00491270 pos;
    u8 pad10[0x10];
    s16 h20[8];
    u8 pad30[0x30];
} S_00491270;

extern s32 D_L40_00248628;
extern S_00491270 D_L40_002926E0[];
extern void func_L40_00491A38(V4_00491270 *, u32, f32);
extern void func_L40_00491768(V4_00491270 *, V4_00491270 *, u32, f32);

void func_L40_00491270(void) {
    V4_00491270 a;
    V4_00491270 b;
    s32 i;
    s32 j;

    for (i = 0; i < D_L40_00248628; i++) {
        a = D_L40_002926E0[i].pos;
        a.z += 0.05f;
        func_L40_00491A38(&a, 0x6000FF00, 0.4f);
        for (j = 0; j < 8; j++) {
            if (D_L40_002926E0[i].h20[j] >= i) {
                b = D_L40_002926E0[D_L40_002926E0[i].h20[j]].pos;
                b.z += 0.05f;
                func_L40_00491768(&a, &b, 0x60008000, 0.2f);
            }
        }
    }
}
/* localdecomp:end func_L40_00491270 */

/* localdecomp:start func_L40_004913B8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_004913B8;
typedef struct { V_004913B8 a; V_004913B8 b; u8 pad[0x20]; } E_004913B8;
extern E_004913B8 D_L40_002986E0[];
extern s32 D_L40_0024862C;

void func_L40_004913B8(void) {
    s32 i;

    for (i = 0; i < D_L40_0024862C; i++) {
        V_004913B8 a = D_L40_002986E0[i].a;
        V_004913B8 b = D_L40_002986E0[i].b;
        a.z += 0.05f;
        b.z += 0.05f;
        func_L40_00491768((V4_00491270 *)&a, (V4_00491270 *)&b, 0x600000FF, 0.4f);
    }
}
/* localdecomp:end func_L40_004913B8 */

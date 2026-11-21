#include "common.h"

typedef struct {
    u8 pad[0x34];
    u16 h34;
    u8 pad36[0x32];
    s32 *w68;
} Moby_003B3CC0;
typedef struct {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[0x1C - 0x14];
    s32 w1C;
    u8 pad20[0x30 - 0x20];
    s32 w30;
} S_3B4CC0b;
typedef struct {
    u8 pad0[0x68];
    S_3B4CC0b *p68;
} S_3B4CC0;
typedef int u128_3B5048 __attribute__((mode(TI)));
typedef struct { u8 p0[0x10]; s32 w10; u8 p14[0x30]; u16 h44; } C_3B5048;
typedef struct { u8 p0[0x81]; u8 b81; u16 h82; } V_3B5048;
typedef struct {
    u8 p0[0x10]; u128_3B5048 pos; u8 b20; u8 b21; u8 p22[2]; C_3B5048 *w24; u8 p28[8];
    u8 b30; u8 b31; u16 h32; u16 h34; u8 p36[0x32]; V_3B5048 *w68; u8 p6C[0x13]; u8 b7F; u8 p80[0x15]; u8 b95;
    u8 p96[2]; s32 w98; u8 p9C[0x24]; u8 vC0[0x30]; u128_3B5048 vF0;
} M_3B5048;
typedef struct { f32 f0; s16 h4; } A_3B5048;
typedef struct { s16 h0; s16 h2; u8 b4; u8 b5; u8 b6; u8 p7[0x13]; u8 b1A; u8 p1B[0x1D]; s16 h38; } B_3B5048;
typedef struct { u8 p0[8]; void *w8; } E_3B5048;
typedef struct Obj_003B51A0 {
    u8 pad[0x24];
    s32 w24;
    u8 pad28[0x3C];
    void (*fn64)(struct Obj_003B51A0 *);
} Obj_003B51A0;
typedef void (*Fn_003B52B0)(u8 *, s32);

extern void func_L01_004450F0(s32, s32, s32);
extern u8 *D_L01_001E001C;
extern void func_L01_003B3368(u8 *a0);
extern u8 *func_L01_003B3430(u8 *a0);
extern u8 *D_L01_001E0100[];
extern void func_L01_004F50C8(u8 *, u8 *, s32, s32);
extern void func_L01_003EE650(s32);
extern s32 func_L01_003B3548(u8 *);

/* localdecomp:start func_L01_003B64F0 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003B64F0;
typedef struct {
    u8 p0[0x10];
    V4_003B64F0 pos;
} Mob_003B64F0;
typedef struct {
    s32 w0;
    s32 group;
    s32 one;
    u8 pC[0x5C - 0xC];
    s32 random;
    s32 used;
    s32 used2;
    u8 p68[0xB0 - 0x68];
    s32 oneIdx;
    s32 count;
    s32 count2;
    u8 pBC[0xC8 - 0xBC];
    s32 nGroups;
    u8 pCC[4];
    s32 groups[4];
    s32 singles[8];
    s32 sizes[8];
} S_003B64F0;

extern s16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C_003B64F0;
__asm__(".extern D_L01_001E001C_003B64F0, 16");
extern s32 func_00382468(s32);
extern s32 func_L01_003FB640(void *, f32, s32, void *);

static __inline__ u8 *MobyFromHandle_003B64F0(s32 h) {
    return D_L01_001E001C_003B64F0 + ((h & 0x7FFF) << 8);
}

u8 *func_L01_003B64F0(u8 *a0, f32 r, f32 radius, s32 *out) {
    S_003B64F0 *s = (S_003B64F0 *)a0;
    f32 ratio;
    s32 idx;
    s32 i;
    u8 *m;

    if (s->used == 0) {
        ratio = 0.0f;
    } else if (s->used2 == 0) {
        ratio = 1.0f;
    } else {
        ratio = (f32)s->used / (f32)(s->used + s->used2);
    }
    if ((ratio == 0.0f && 0.0f < r) || ratio <= r) {
        if (out != 0) {
            *out = -1;
        }
        if (s->random != 0) {
            idx = func_00382468(s->count);
        } else {
            idx = s->used % s->count;
        }
        for (i = 0; i < s->count; i++) {
            V4_003B64F0 v;
            if (idx == s->oneIdx) {
                m = D_L01_001E001C_003B64F0 + (s->one << 8);
            } else {
                m = MobyFromHandle_003B64F0(*(u16 *)((u8 *)D_L01_0021DE20[s->group] + (idx << 1)));
            }
            v = ((Mob_003B64F0 *)m)->pos;
            v.z += radius;
            if (radius == 0.0f || func_L01_003FB640(&v, radius, 1, 0) == 0) {
                s->used++;
                return m;
            }
            idx = (idx + 1) % s->count;
        }
    } else {
        if (out != 0) {
            *out = 0;
        }
        if (s->random != 0) {
            idx = func_00382468(s->count2);
        } else {
            idx = s->used2 % s->count2;
        }
        m = 0;
        for (i = 0; i < s->count; i++) {
            s32 k = idx;
            s32 j;
            for (j = 0; j < s->nGroups; j++) {
                if (k < s->sizes[j]) {
                    m = MobyFromHandle_003B64F0(*(u16 *)((u8 *)D_L01_0021DE20[s->groups[j]] + (k << 1)));
                    break;
                }
                k -= s->sizes[j];
            }
            if (j == s->nGroups) {
                m = D_L01_001E001C_003B64F0 + (s->singles[k] << 8);
                if (out != 0) {
                    *out = k;
                }
            } else if (out != 0) {
                *out = j;
            }
            if (func_L01_003FB640(m + 0x10, radius, 1, 0) == 0) {
                s->used2++;
                return m;
            }
            idx = (idx + 1) % s->count2;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003B64F0 */

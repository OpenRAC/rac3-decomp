/* near miss (level 3, Starship Phoenix): 7 differences, two scheduling groups: in the 0x40 branch retail emits a2=0, a0=4, a1=0 and then the sw of 2 into D_L03_001DF514, the C emits a0, the store, a1, a2; and for the last two calls retail has `move a0,s0` before the jal and `move a1,v0` in the delay slot, the C the reverse; reordering, typed arguments, K&R and a temp for the hash result tried */
#include "common.h"

/* localdecomp:start func_L03_0032FE70 */
typedef struct S_0032FE70b { u8 pad00[0xFF]; u8 fFF; f32 f100; u8 pad104[0x112 - 0x104]; u8 f112; } S_0032FE70b;
typedef struct S_0032FE70a { u8 pad00[0x68]; S_0032FE70b *f68; } S_0032FE70a;
typedef struct S_0032FE70c { u8 pad00[0x1C4]; s32 f1C4; } S_0032FE70c;
extern S_0032FE70c *D_001D52FC_0032FE70;
extern S_0032FE70c *D_001D52FC_sda;
__asm__(".extern D_001D52FC_sda, 4");
extern S_0032FE70a *D_001DD104_sda;
__asm__(".extern D_001DD104_sda, 4");
extern u8 D_001DD108_sda;
__asm__(".extern D_001DD108_sda, 1");
extern u8 D_001DD109_sda;
__asm__(".extern D_001DD109_sda, 1");
extern s32 D_L03_001DF514;
extern void func_L01_004450F0_0032FE70();
extern void func_003A2CD8_0032FE70();
extern void func_003A5348_0032FE70(s32, s32, s32);
extern void func_L03_00330140_0032FE70();
extern void func_L03_0032CFE8_0032FE70();
extern void func_L01_00516558_0032FE70(s32, f32 *, f32 *);
extern void func_L01_00516470_0032FE70(s32, f32, f32);
extern s32 func_0038DBD8_0032FE70(s32, s32, f32);
extern void func_L01_005170B8_0032FE70(s32, s32);
s32 func_L03_0032FE70(void) {
    S_0032FE70a *a = D_001DD104_sda;
    S_0032FE70b *b = a->f68;
    s32 ret = 0;
    f32 f, g, x[2];
    s32 id, h;
    if (D_001D52FC_0032FE70->f1C4 & 0x10) {
        D_L03_001DF514 = 2;
        ret = 1;
        func_L01_004450F0_0032FE70(a, 12, -1);
        func_003A2CD8_0032FE70(D_001D52FC_sda);
    }
    if (D_001D52FC_0032FE70->f1C4 & 0x1000) {
        if (D_001DD109_sda != 0) {
            func_003A5348_0032FE70(3, 0, 0);
            D_001DD109_sda--;
            if (D_001DD109_sda < D_001DD108_sda) D_001DD108_sda--;
            func_L03_00330140_0032FE70(a);
            func_003A2CD8_0032FE70(D_001D52FC_sda);
        }
    } else if (D_001D52FC_0032FE70->f1C4 & 0x4000) {
        if (D_001DD109_sda < b->f112 - 1) {
            func_003A5348_0032FE70(3, 0, 0);
            D_001DD109_sda++;
            if (D_001DD109_sda - D_001DD108_sda >= 5) D_001DD108_sda = D_001DD108_sda + 1;
            func_L03_00330140_0032FE70(a);
            func_003A2CD8_0032FE70(D_001D52FC_sda);
        }
    } else if (D_001D52FC_0032FE70->f1C4 & 0x40) {
        D_L03_001DF514 = 2;
        ret = 1;
        func_003A5348_0032FE70(4, 0, 0);
        func_L03_0032CFE8_0032FE70(a, b->fFF);
        func_003A2CD8_0032FE70(D_001D52FC_sda);
    }
    g = b->f100 + 0.060000002f;
    b->f100 = g;
    if (g > 2.0f) b->f100 = g - 2.0f;
    id = 0x470000 + (D_001DD109_sda - D_001DD108_sda) + 0x24;
    func_L01_00516558_0032FE70(id, &x[0], &x[1]);
    func_L01_00516470_0032FE70(0x470023, x[0], x[1]);
    f = b->f100;
    func_L01_005170B8_0032FE70(id, func_0038DBD8_0032FE70(0x66D6EEFA, 0x80FFFFFF, f <= 1.0f ? f : 2.0f - f));
    return ret;
}
/* localdecomp:end func_L03_0032FE70 */

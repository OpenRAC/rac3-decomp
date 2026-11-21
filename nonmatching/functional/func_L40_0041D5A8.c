/* functional: medium. Ported from the NTSC-U draft and checked against the PAL asm: callee names via map.tsv, PAL data (D_L40_00241120/00241640/0024845C/00249840/00357260, D_001A5CD8 for the NTSC D_001A5E58); immediates and call list equal; 131 words differ (register allocation, $a3 alias of st+0x20). D_001A5CD8 is lui-addressed in retail (declare unsized if it must byte-match). */

#include "vu0.h"

/* localdecomp:start func_L40_0041D5A8 */
typedef struct {
    u8 pad0[0x38];
    u8 b38[8];
    u8 pad40[0x1F4 - 0x40];
    s32 w1F4;
    f32 f1F8[2];
    u8 pad200[0x20C - 0x200];
    u8 *p20C;
} T_41CD40;

typedef struct {
    u8 pad0[0x196];
    s8 b196;
} H_41CD40;

typedef struct {
    u8 pad0[0x2548];
    s32 w2548;
} E_41CD40;

__asm__(".extern D_L40_00241120, 16");
extern s32 *D_L40_00241120;
__asm__(".extern D_L40_00249840, 16");
extern s32 D_L40_00249840[];
extern T_41CD40 D_L40_00357260;
extern H_41CD40 *D_L40_00241640;
__asm__(".extern D_L40_0024845C, 16");
extern u8 *D_L40_0024845C;
extern u8 *D_L40_0024845C;
__asm__(".extern D_L40_0024845C, 4");
extern s32 D_001A5CD8;
extern void func_L39_00662B18(void *, void *, s32);
extern E_41CD40 *func_L39_0061BF38(s32);
extern void func_L39_00648960(void *, s32);
extern s32 func_L39_005F3488(s32, s32, void *, s32);
extern void func_L39_0055D948(s32, s32);
extern void func_L40_00422358(void *, s32);
extern void func_L40_0041D4B8(void *, s32, s32);
extern void func_L40_0041DC00(void *, s32);
extern void func_L40_00489BC0(void *, void *, s32);

void func_L40_0041D5A8(u8 *o, u32 *msg) {
    u8 *st = *(u8 **)(o + 0x68);
    s32 x;
    s32 y;
    s32 s2;
    s32 s4;
    s32 i;
    s32 cnt;
    s32 mine;
    s32 other;
    s32 j;
    s32 *arr;
    s32 id;
    E_41CD40 *e;

    if ((msg[0] & 0xF) == 0) {
        s4 = 1;
        s2 = -1;
        if (*(s32 *)(st + 0x2C) >= 0) {
            s2 = *(s32 *)(D_L40_00357260.p20C + *(s32 *)(st + 0x2C) * 4 + 0xA8);
        }
        *(s32 *)(st + 0x20) = 0;
        *(s32 *)(st + 0x24) = msg[1];
        func_L39_00662B18(msg, &x, 4);
        func_L39_00662B18(msg, &y, 4);
        if ((u32)x < 2) {
            D_L40_00249840[x]++;
        }
        i = 0;
        if (*D_L40_00241120 > 0) {
            do {
                e = func_L39_0061BF38(i);
                if (e->w2548 == x) {
                    func_L39_00648960(e, 0xA);
                    s4 = 2;
                } else if (e->w2548 == s2) {
                    func_L39_00648960(e, 0x1C);
                }
                i++;
            } while (i < *D_L40_00241120);
        }
        func_L39_005F3488(s4, 0x110, o, 0x1C2F);
        if ((u32)y < 8) {
            D_L40_00357260.b38[y]++;
        }
        id = *(s32 *)(st + 0x2C);
        if (id >= 0) {
            *(s32 *)(D_L40_00357260.p20C + id * 4 + 0xA8) = x;
            mine = 0;
            other = 0;
            arr = (s32 *)(D_L40_00357260.p20C + 0xA8);
            for (j = 7; j >= 0; j--) {
                if (*arr == x) {
                    mine++;
                } else if (*arr == (x + 1) % 2) {
                    other++;
                }
                arr++;
            }
            if (D_L40_00241640->b196 != 0) {
                D_L40_00357260.f1F8[x] = (f32)mine / (f32)D_L40_00357260.w1F4;
                D_L40_00357260.f1F8[(x + 1) % 2] = (f32)other / (f32)D_L40_00357260.w1F4;
            }
        }
        id = *(s32 *)(st + 0x3C);
        if (id >= 0) {
            u8 *p = *(u8 **)(D_L40_0024845C + (id << 8) + 0x68);
            if (x == 0) {
                *(s32 *)p = 0;
            } else {
                *(f32 *)p = 1.0f;
            }
        }
        func_L39_0055D948(*(s32 *)(st + 0x34), x);
        id = *(s32 *)(st + 0x38);
        if (id >= 0) {
            if (((msg[0] >> 10) & 7) == D_001A5CD8) {
                func_L40_00422358(D_L40_0024845C + (id << 8), x);
            }
        }
        func_L40_0041D4B8(o, x, 0);
        func_L40_0041DC00(o, 1);
        func_L40_00489BC0(o, st + 0x40, -1);
    }
}
/* localdecomp:end func_L40_0041D5A8 */

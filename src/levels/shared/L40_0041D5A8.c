#include "common.h"

/* localdecomp:start func_L40_0041D5A8 */
typedef struct { u8 pad[0xA8]; s32 a[8]; } T_0041D5A8;
typedef struct { u8 pad0[0x38]; u8 b38[8]; u8 pad40[0x1F4 - 0x40]; s32 n1F4; f32 f1F8[2]; u8 pad200[0xC]; T_0041D5A8 *p20C; } S_0041D5A8;
typedef struct { u8 pad[0x68]; f32 *p68; u8 rest[0x94]; } M_0041D5A8;
extern S_0041D5A8 D_L40_00357260;
extern s32 D_L40_00249840[2];
__asm__(".extern D_L40_00249840, 16");
extern u8 *D_L40_00241640;
__asm__(".extern D_L40_00241640, 16");
extern u8 *D_L40_0024845C;
__asm__(".extern D_L40_0024845C, 16");
extern M_0041D5A8 *D_L40_0024845C_0041D5A8;
extern s32 *D_00241120;
extern s32 D_001A5CD8[];
typedef struct { s32 a; s32 b; } W_0041D5A8;
typedef struct { u8 pad0[0x20]; W_0041D5A8 w; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; u8 f40[1]; } V_0041D5A8;
extern void func_L39_00662B18(void *, void *, s32);
extern u8 *func_L39_0061BF38(s32);
extern void func_L39_00648960(void *, s32);
extern void func_L39_005F3488(s32, s32, void *, s32);
extern void func_L39_0055D948(s32, s32);
extern void func_L40_00422358(void *, s32);
extern void func_L40_0041D4B8(void *, s32, s32);
extern void func_L40_0041DC00(void *, s32);
extern void func_L40_00489BC0(void *, void *, s32);

void func_L40_0041D5A8(u8 *moby, u32 *a1) {
    V_0041D5A8 *v;
    W_0041D5A8 *w;
    s32 buf[2];
    s32 kind;
    s32 prev;
    s32 i;
    u8 *p;
    f32 *q;

    v = *(V_0041D5A8 **)(moby + 0x68);
    w = &v->w;
    if ((*a1 & 0xF) == 0) {
        kind = 1;
        prev = -1;
        if (v->f2C >= 0) {
            prev = D_L40_00357260.p20C->a[v->f2C];
        }
        w->a = 0;
        w->b = a1[1];
        func_L39_00662B18(a1, &buf[0], 4);
        func_L39_00662B18(a1, &buf[1], 4);
        if ((u32)buf[0] < 2) {
            D_L40_00249840[buf[0]]++;
        }
        for (i = 0; i < *D_00241120; i++) {
            p = func_L39_0061BF38(i);
            if (*(s32 *)(p + 0x2548) == buf[0]) {
                func_L39_00648960(p, 10);
                kind = 2;
            } else if (*(s32 *)(p + 0x2548) == prev) {
                func_L39_00648960(p, 0x1C);
            }
        }
        func_L39_005F3488(kind, 0x110, moby, 0x1C2F);
        if ((u32)buf[1] < 8) {
            D_L40_00357260.b38[buf[1]]++;
        }
        if (v->f2C >= 0) {
            s32 cnt = 0;
            s32 other = 0;
            s32 k;
            s32 cur;
            D_L40_00357260.p20C->a[v->f2C] = buf[0];
            cur = buf[0];
            for (k = 0; k < 8; k++) {
                if (D_L40_00357260.p20C->a[k] == cur) {
                    cnt++;
                } else if (D_L40_00357260.p20C->a[k] == (cur + 1) % 2) {
                    other++;
                }
            }
            if (((s8 *)D_L40_00241640)[0x196] != 0) {
                D_L40_00357260.f1F8[buf[0]] = (f32)cnt / (f32)D_L40_00357260.n1F4;
                D_L40_00357260.f1F8[(buf[0] + 1) % 2] = (f32)other / (f32)D_L40_00357260.n1F4;
            }
        }
        if (v->f3C >= 0) {
            q = D_L40_0024845C_0041D5A8[v->f3C].p68;
            if (buf[0] == 0) {
                *q = 0.0f;
            } else {
                *q = 1.0f;
            }
        }
        func_L39_0055D948(v->f34, buf[0]);
        if (v->f38 >= 0 && ((*a1 >> 10) & 7) == D_001A5CD8[0]) {
            func_L40_00422358(D_L40_0024845C + (v->f38 << 8), buf[0]);
        }
        func_L40_0041D4B8(moby, buf[0], 0);
        func_L40_0041DC00(moby, 1);
        func_L40_00489BC0(moby, v->f40, -1);
    }
}
/* localdecomp:end func_L40_0041D5A8 */

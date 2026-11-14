#include "common.h"

typedef struct S_Foo_0032D228 {
    u8 pad0[0xF2];
    u16 f2;
    u8 f4;
    u8 pad1[0x108 - 0xF5];
    s32 f108;
} S_Foo_0032D228;

typedef struct S_0032D598 {
    u8 pad[0xB4];
    s32 cnt[16];
} S_0032D598;

typedef struct { u8 pad0[0x30]; u8 b30[0x40]; u8 b70[0x10]; } Ent_32CF78;
typedef struct { u8 pad0[0x68]; struct { u8 pad[0xD0]; s32 idx; } *p68; } Obj_32CF78;

/* declared by functions of L03_0032CED0.c, which this file was cut from */
extern s32 func_L03_0032D348(void *p, s32 i);

/* localdecomp:start func_L03_0032D348 */
typedef struct S_0032D348 {
    char pad[0xA8];
    s32 idx[3];
    s32 cnt[16];
} S_0032D348;
extern u16 *D_L03_0021C620[];
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern s32 D_L03_001DF9D8;
extern char D_L03_001A4C60[];
void *func_L03_0032F6A8();
f32 func_0038CF38();
void func_L03_0032D640(void *arg0, void *arg1);
s32 func_L03_0032D598(void *arg0, u8 *arg1);

s32 func_L03_0032D348(void *a, s32 c) {
    S_0032D348 *o = *(S_0032D348 **)((char *)a + 0x68);
    s32 flag = o->cnt[c] < 1;
    s32 r = 0;
    u8 *far = 0, *near = 0;
    f32 mx = -1.0f, mn = 10000000.0f;
    u16 *cur = D_L03_0021C620[o->idx[c]];
    while ((o->idx[c] & 0xFF) != 0xFF && D_L03_001DF9D8 >= o->idx[c] && cur != 0 &&
           ((s16)cur[-1] >= 0 || cur == D_L03_0021C620[o->idx[c]])) {
        u8 *buf = D_L03_001DF99C + ((*cur & 0x7FFF) << 8);
        u8 *q;
        f32 d;
        if (buf == 0) break;
        if (buf[0x20] >= 4) {
            q = func_L03_0032F6A8(buf);
            if (q[0x1D] == c) {
                r = 1;
                if (q[0x1C] != 3) {
                    d = func_0038CF38(buf + 0x10, D_L03_001A4C60);
                    if (d < mn) { near = buf; mn = d; }
                    if (flag && q[0x1C] == r && mx < d) { far = buf; mx = d; }
                }
            }
        }
        cur++;
    }
    if (near != 0) {
        u8 *q = func_L03_0032F6A8(near);
        if (q[0x1C] != 1) {
            if (far != 0) func_L03_0032D640(a, far);
            func_L03_0032D598(a, near);
        }
    }
    return r;
}
/* localdecomp:end func_L03_0032D348 */

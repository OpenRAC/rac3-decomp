#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_00323000 */
typedef struct { u8 pad[0x10]; vu0_v4 x10; u8 pad2[0xE0]; } N_323000;
typedef struct { u8 pad[0x30]; vu0_v4 v; u8 pad2[0x40]; } P_323000;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    vu0_v4 x10;
    vu0_v4 x20;
    u8 x30, x31, x32, x33;
    u8 pad34[0x10];
    s32 x44;
    s32 x48;
    u8 pad4C[0x24];
    vu0_v4 x70;
    vu0_v4 x80;
    s32 x90;
    s32 x94;
    s32 x98;
    s32 x9C;
} V_323000;
__asm__(".extern D_L19_001DF71C, 4");
__asm__(".extern D_L19_001DF800, 4");
extern N_323000 *D_L19_001DF71C;
extern P_323000 *D_L19_001DF800;
extern s32 D_00142668[];
extern u8 *D_L19_001E8E58[];
extern u8 D_001A30B0[];
extern u8 D_L19_001D66F0[8];
extern char D_L19_001D64E0[] __attribute__((section(".sdata")));
extern void func_003C2880(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C7DD8(void *);
extern void func_L01_0040C7A0(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, u8 *);
extern u8 *func_L01_0046B458(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);
extern void func_L01_0040C8A0(void *, void *);
extern void func_L01_00404A10(void *, void *);
extern int func_L19_00323398(char *a);
extern s32 func_0038CAD0(void *);
extern s32 func_L19_003D0130(s32 a);
extern s32 func_L03_00433C70(void *, void *, void *, s32, s32, s32, s32, f32, f32);

void func_L19_00323000(u8 *obj) {
    V_323000 *v = *(V_323000 **)(obj + 0x68);
    vu0_v4 m;
    u8 *s;

    switch (obj[0x20]) {
    case 0:
        if (v->x0 != -1)
            v->x10 = D_L19_001DF71C[v->x0].x10;
        else if (v->x8 != -1)
            v->x10 = D_L19_001DF800[v->x8].v;
        else
            v->x10 = *(vu0_v4 *)(obj + 0x10);
        if (v->x4 != -1)
            v->x20 = D_L19_001DF71C[v->x4].x10;
        else if (v->xC != -1)
            v->x20 = D_L19_001DF800[v->xC].v;
        else {
            func_003C2880(obj);
            return;
        }
        vec_add_ba(&m, &v->x10, &v->x20);
        func_0038CE20(&m, &m, 0.5f);
        *(vu0_v4 *)(obj + 0x10) = m;
        func_003C7DD8(obj);
        obj[0x31] = 0;
        *(u16 *)(obj + 0x34) |= 1;
        v->x90 = -1;
        v->x70 = v->x10;
        v->x80 = v->x20;
        v->x98 = (v->x33 << 24) | (v->x32 << 16) | (v->x31 << 8) | v->x30;
        v->x9C = (v->x33 << 24) | (v->x32 << 16) | (v->x31 << 8) | v->x30;
        v->x94 = -1;
        func_L01_0040C7A0(&v->x70, D_L19_001D64E0);
        func_L01_004450F0(obj, 1, -1);
        break;
    case 1:
        if (v->x44 == -1 || (s = D_001A30B0 + (v->x44 << 7), *(u8 **)(s + 0xDC) != obj) || s[0xD0] == 0)
            v->x44 = func_003A52A0(0, 4, obj);
        func_L01_0046B458((u8 *)&v->x10, 1, 1.0f, 1.0f, (v->x33 << 24) | (v->x32 << 16) | (v->x31 << 8) | v->x30,
                          0, 0, D_L19_001D66F0, 0.0f, 0);
        func_L01_0046B458((u8 *)&v->x20, 1, 1.0f, 1.0f, (v->x33 << 24) | (v->x32 << 16) | (v->x31 << 8) | v->x30,
                          0, 0, D_L19_001D66F0, 0.0f, 0);
        func_L01_0040C8A0(&v->x70, D_L19_001D64E0);
        func_L01_00404A10(func_L19_00323398, obj);
        func_0038CAD0(&v->x48);
        if (func_L03_00433C70(obj, &v->x10, &v->x20, 0x410001, 0, 1, 0,
                              (f32)func_L19_003D0130(D_00142668[0] / 5 + 1), 1.0f) != 0
            && D_L19_001E8E58[0] != 0 && v->x48 <= 0) {
            func_003A52A0(1, 0, obj);
            v->x48 = 0x11;
        }
        break;
    }
}
/* localdecomp:end func_L19_00323000 */

/* localdecomp:start func_L19_00323398 */
extern int func_L01_0040C948(void *, void *);
extern char D_L19_001D64E0[] __attribute__((section(".sdata")));
int func_L19_00323398(char *a)
{
    return func_L01_0040C948(*(char **)(a + 0x68) + 0x70, D_L19_001D64E0);
}
/* localdecomp:end func_L19_00323398 */

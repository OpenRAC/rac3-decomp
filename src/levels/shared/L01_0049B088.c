#include "common.h"

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x5628 - 0x4958];
    u8 fX[1];
} S_func_00496AB0;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
} E_496DC0;
typedef struct {
    s32 id;
    s32 pad[3];
} Ent_497BC8;
typedef struct { s32 a; s32 b; s32 c; s32 d; } Ent_00497C30;

/* declared by functions of L01_00499C80.c, which this file was cut from */
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_L01_00517918(s32);
extern void func_003A2750(s32);
extern void *func_003B42F8(s32);
extern void func_003BB468(s32);

/* localdecomp:start func_L01_0049B088 */
#include "vu0.h"

typedef int u128_0049B088 __attribute__((mode(TI)));
typedef struct {
    s32 id;
    s32 idx;
    s32 flag;
    s32 pad;
} Ent_0049B088;
extern f32 D_L01_001D93FC;
extern f32 D_L01_001D93F4;
extern f32 D_L01_001DC0E8;
extern f32 D_L01_001DC0EC;
extern u8 D_L01_001E7580[];
extern s32 D_L01_001D9384;
__asm__(".extern D_L01_001D9384, 4");
extern s32 D_L01_001D9380;
__asm__(".extern D_L01_001D9380, 4");
extern u8 *D_L01_001D9340[2];
__asm__(".extern D_L01_001D9340, 8");
extern u8 D_L01_001D93B0[8];
__asm__(".extern D_L01_001D93B0, 8");
extern u8 D_L01_001D93A0[8];
__asm__(".extern D_L01_001D93A0, 8");
extern u8 D_L01_001D9390[8];
__asm__(".extern D_L01_001D9390, 8");
extern f32 D_L01_001D93C8;
__asm__(".extern D_L01_001D93C8, 4");
extern f32 D_L01_001D93CC;
__asm__(".extern D_L01_001D93CC, 4");
extern s32 D_L01_001DFB94;
extern Ent_0049B088 D_L01_002EBDE8[];
extern u8 D_001426E0[];
extern u8 D_L01_001E29C0[];
extern u8 D_L01_001E2A40[];
extern void func_L01_0047E520(void);
extern void func_00392868(int, int);
extern u8 *func_003C24B0(s32, s32);
extern void func_003C25D8(u8 *, s32);
extern unsigned long func_003C6F90(u8 *, u32, u32, u32, u32);
extern void func_0038D308(u8 *, u8 *);
extern void func_00387218(void);
extern void func_0038CC88(void *, void *, s32);
extern void func_003861F0(void);
extern void func_003873C0(void);
extern void func_003C36C0(void);
extern void func_003C3638(void);
extern void func_003C3660(void);
extern void func_003C2DC0(void);
extern void func_00387F68(void);
extern void func_003A9500(s32, s32, s32, s32);
extern void func_003C6FE0(u8 *);
extern void func_003C7C38(u8 *);
extern void func_003C3780(u8 *, s32);
extern void func_003C3690(void);
extern void func_003C3800(void);
extern void func_003A9C70(u32);
extern void func_003A92F0(s32);
extern void func_003C31B0(void);

void func_L01_0049B088(void) {
    u8 *g;
    u8 *g2;
    f32 save;
    f32 h;
    f32 c;
    s32 b;
    s32 a;
    u8 *o;
    u8 *obj;
    f32 f;

    func_L01_0047E520();
    h = D_L01_001D93FC * 0.5f;
    c = D_L01_001D93F4;
    g = D_L01_001E7580;
    save = *(f32 *)(g + 0xB0);
    b = (s32)(D_L01_001DC0EC * (c - h) + 2.0f);
    a = (s32)(D_L01_001DC0EC * (c + h) - 3.0f);
    if (D_L01_001D9384 < 0) {
        return;
    }
    if (D_001426E0[D_L01_002EBDE8[D_L01_001D9384].idx] == 0) {
        return;
    }
    func_00392868((s32)D_L01_001DC0E8, (s32)D_L01_001DC0EC);
    if (D_L01_001D9340[D_L01_001D9384] == 0) {
        o = func_003C24B0(D_L01_002EBDE8[D_L01_001D9384].id, 0);
        if (o != 0) {
            func_003C25D8(o, D_L01_002EBDE8[D_L01_001D9384].id);
            *(s16 *)(o + 0x32) = 0xC0;
            func_003C6F90(o, 0x5669E, 0, 0, 0);
            *(u128_0049B088 *)(o + 0x10) = *(u128_0049B088 *)D_L01_001D93B0;
        }
        D_L01_001D9340[D_L01_001D9384] = o;
    }
    if (D_L01_001D9380 != D_L01_001D9384) {
        obj = D_L01_001D9340[D_L01_001D9384];
        if (obj != 0) {
            if (D_L01_002EBDE8[D_L01_001D9384].flag == 0) {
                qzero(obj + 0xF0);
                *(f32 *)(obj + 0xF0) = 3.1415927f;
                *(f32 *)(obj + 0xF4) = 1.5707964f;
                f = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * D_L01_001D93C8;
            } else {
                qzero(obj + 0xF0);
                f = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * D_L01_001D93CC * D_L01_001D93C8;
            }
            *(f32 *)(obj + 0x2C) = f;
            func_003C7C38(obj);
            D_L01_001D9380 = D_L01_001D9384;
        }
    }
    g2 = D_L01_001E7580;
    func_0038D308(D_L01_001E29C0 + 0x20, D_L01_001D9390);
    D_L01_001DFB94 = 0;
    func_00387218();
    *(u128_0049B088 *)D_L01_001E2A40 = *(u128_0049B088 *)(D_L01_001E29C0);
    *(u128_0049B088 *)(D_L01_001E2A40 + 0x10) = *(u128_0049B088 *)(D_L01_001E29C0 + 0x10);
    func_0038CC88(D_L01_001E2A40 + 0x380, D_L01_001E29C0 + 0x20, 0x30);
    func_003861F0();
    *(f32 *)(g2 + 0xB0) = 0.62f;
    func_003873C0();
    func_003C36C0();
    func_003C3638();
    func_003C3660();
    *(u128_0049B088 *)(D_L01_001E29C0) = *(u128_0049B088 *)D_L01_001D93A0;
    func_003861F0();
    func_003C2DC0();
    func_00387F68();
    func_003A9500(0, (s32)D_L01_001DC0E8, b, a);
    func_003C6FE0(D_L01_001D9340[D_L01_001D9384]);
    func_003C7C38(D_L01_001D9340[D_L01_001D9384]);
    func_003C3780(D_L01_001D9340[D_L01_001D9384], 1);
    func_003C3690();
    func_003C3800();
    func_003A9C70(0x2080000);
    func_003A9500(0, (s32)D_L01_001DC0E8 - 1, 0, (s32)D_L01_001DC0EC - 1);
    func_003A92F0(16);
    func_003C31B0();
    *(f32 *)(g2 + 0xB0) = save;
    func_003873C0();
}
/* localdecomp:end func_L01_0049B088 */

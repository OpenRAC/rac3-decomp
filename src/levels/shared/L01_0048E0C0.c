#include "common.h"

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 w12;
} E_488750;
typedef struct VT_00489FA8 { u8 p0[12]; void (*f12)(void *); } VT_00489FA8;
typedef struct O_00489FA8 { u8 p0[4]; VT_00489FA8 *vt; } O_00489FA8;
typedef struct Obj_0048B530 Obj_0048B530;
typedef struct {
    void *pad0[3];
    void (*fn)(Obj_0048B530 *);
} ObjVtbl_0048B530;
struct Obj_0048B530 {
    s32 pad0;
    ObjVtbl_0048B530 *vtbl;
};
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F30 - 0x4958];
    u8 f6F30[1];
} S_48D030;
typedef struct Obj Obj;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj *);
} ObjVt;
struct Obj {
    s32 pad;
    ObjVt *vt;
};
typedef struct {
    s32 w0;
    void (*fn)(u32);
    s32 w8;
} E_0048D0C8;
typedef struct { u8 b[16]; } V16_48DCD8;

/* declared by functions of L01_0048B738.c, which this file was cut from */
extern char *func_00381FF0(s32 id);
extern void func_L01_00516D60(s32 id, s32 v);
extern u8 *D_001D52FC[] __attribute__((section(".sdata")));
extern s32 func_003A5348(s32, s32, s32);
extern O_00489FA8 *func_003B42F8(s32);
extern s32 D_L01_001D8C30;
extern s32 D_L01_001D8C84;
extern s32 D_L01_001D8C78;
extern s32 D_L01_001D8C7C;
extern void func_L01_0048D970(void);
extern s32 D_L01_001E0958[] __attribute__((section(".sdata")));
extern f32 D_L01_001D8C98;
extern f32 D_L01_001D8CA4;
extern f32 D_L01_001D8CA8;
extern s32 func_L01_00516470(s32, f32, f32);

/* localdecomp:start func_L01_0048E0C0 */
typedef struct {
    u8 p0[0x4954];
    s32 f4954;
    u8 p4958[0x5950 - 0x4958];
    u8 f5950[0x7080 - 0x5950];
    u8 f7080[8];
} S_0048E0C0;

extern void func_L01_00437548(void);
extern void func_0039EF28(void);
extern void func_L01_0048D940(void);
extern u8 func_L01_00437540(void);
extern void func_L01_0048D970(void);
extern char *func_00381FF0(s32 id);
extern s32 func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, char *, s32, s32, s32, s32, f32);
extern s32 func_L01_0047DB60(void);
extern s32 func_003E8FE8(s32, char *, s32, f32, f32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_003E8630(s32, s32);
extern void func_L01_00518D40_0048E0C0(s32);
extern void func_L01_00518590(s32, s32, s32);
extern s32 func_003E9138(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_003E8898(s32, f32, f32);
extern s32 func_L01_00518010(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_003E9358(s32, void *, s32, f32, f32, f32, f32, f32);
extern void func_L01_00517BF8(s32, s32, s32, s32, s32, s32);
extern void func_L01_00517DB8(s32, s32, s32, f32);
extern void func_L01_00518670(s32, s32, s32);
extern s32 func_003E8A08(s32, s32, s32);
extern void func_L01_00516D60(s32 id, s32 v);
extern s32 func_L01_005168F0(s32, f32);
extern void *func_003BB3A8(s32);
extern O_00489FA8 *func_003B42F8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern s32 func_003E8710(s32, s32);
extern s32 func_003E7AC8(s32, s32);
extern void func_L01_00516B90(s32, s32, s32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8A58(s32, s32, s32, s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E87B8(s32, s32, s32);

__asm__(".extern D_L01_001D8C80, 4");
__asm__(".extern D_L01_001D8C30, 4");
__asm__(".extern D_L01_001D8C84, 4");
__asm__(".extern D_L01_001D8C88, 4");
__asm__(".extern D_L01_001D8C8C, 4");
__asm__(".extern D_L01_001D8C90, 4");
__asm__(".extern D_L01_001D8C94, 4");
__asm__(".extern D_L01_001D8CA4, 4");
__asm__(".extern D_L01_001D8CA8, 4");
__asm__(".extern D_L01_001D8CC0, 4");
__asm__(".extern D_L01_001D8CC4, 4");
__asm__(".extern D_L01_001D8CC8, 4");
__asm__(".extern D_L01_001D8CE4, 4");
__asm__(".extern D_L01_001D8CE8, 4");
__asm__(".extern D_L01_001D8CF0, 4");
__asm__(".extern D_L01_001D8CF8, 4");
__asm__(".extern D_L01_001D8CF4, 16");
__asm__(".extern D_L01_001D8CFC, 16");
extern s32 D_L01_001D8C80;
extern s32 D_L01_001D8C30;
extern s32 D_L01_001D8C84;
extern s32 D_L01_001D8C88;
extern s32 D_L01_001D8C8C;
extern s32 D_L01_001D8C90;
extern s32 D_L01_001D8C94;
extern f32 D_L01_001D8CA4;
extern f32 D_L01_001D8CA8;
extern f32 D_L01_001D8CC0;
extern f32 D_L01_001D8CC4;
extern f32 D_L01_001D8CC8;
extern f32 D_L01_001D8CE4;
extern f32 D_L01_001D8CE8;
extern f32 D_L01_001D8CF0;
extern f32 D_L01_001D8CF8;
extern f32 D_L01_001D8CF4;
extern f32 D_L01_001D8CFC;
extern u8 D_L01_001D8D00[];
extern u8 D_L01_002BCB00[];
extern S_0048E0C0 D_00160C40_0048E0C0;

void func_L01_0048E0C0(void) {
    s32 i;
    s32 t;
    s32 a;
    s32 b;

    func_L01_00437548();
    func_0039EF28();
    D_L01_001D8C80 = 0;
    func_L01_0048D940();
    if (func_L01_00437540() != 0) {
        func_L01_0048D970();
        func_L01_00437548();
    }
    func_003B9298(0x10, 0xD000B, 0xD0002, 0xD0003, 0xD0004, 0xD0000, 0xD0001, 0xD0005, 0xD0008, func_00381FF0(0x174), 0xD0006, 0, 0xD0007, 0xCD5, 8.5f);
    if (D_L01_001D8C30 == 0) {
        if (func_L01_0047DB60() != 2) {
            func_003E8FE8(0xD000A, func_00381FF0(0x1B81), 0x8066CCFF, 0.97f, 0.5f, 1.0f, 1.0f);
            func_003E7F20(0xD000A, 1);
            func_003E8630(0xD000B, 0xD000A);
        }
    }
    func_L01_00518D40_0048E0C0(0x160000);
    func_L01_00518D40_0048E0C0(0x160002);
    func_L01_00518590(0x160000, 1, 1);
    func_003E9138(0x160008, 0x332299DE, 0.5f, 0.5f, 0.8f, 0.05f, 0);
    func_003E8630(0x160000, 0x160008);
    for (i = 0; i < 4; i++) {
        func_003E8FE8(0x160011 + i, func_00381FF0(*(s32 *)(D_L01_001D8C84 + i * 20)), 0x8066CCFF, D_L01_001D8CA8, D_L01_001D8CA4, 1.0f, 1.0f);
        func_003E8898(0x160011 + i, 0.8f, 0.8f);
        func_L01_00518010(0x160011 + i, 1);
        func_003E8630(0x160000, 0x160011 + i);
        func_L01_00516AA0(0x160011 + i, 0x40, 1);
        func_003E9138(0x160016 + i, 0x332299DE, D_L01_001D8CA8, D_L01_001D8CA4, 0.77500004f, 0.006667f, 0);
        func_003E8630(0x160000, 0x160016 + i);
    }
    func_003E9358(0x160003, D_L01_002BCB00, 0x8066CCFF, D_L01_001D8CF0, D_L01_001D8CF4, D_L01_001D8CF8, D_L01_001D8CFC, 1.0f);
    func_L01_00516AA0(0x160003, 0x40, 1);
    func_L01_00517BF8(0x160003, 1, 1, 1, 0, 0);
    func_L01_00517DB8(0x160003, 0x64, 0, 0.0005f);
    func_003E7F20(0x160003, 1);
    func_003E9358(0x160006, D_L01_001D8D00, 0x8066CCFF, D_L01_001D8CE4, D_L01_001D8CE8, D_L01_001D8CF8, 0.061332f, 0.9f);
    func_L01_00516AA0(0x160006, 0x40, 1);
    func_L01_00518670(0x160006, 1, 1);
    func_003E8A08(0x160002, 0x160003, 0x160006);
    func_003E9138(0x16000F, 0x332299DE, 0.322916f, 0.359167f, 0.432999f, 0.006667f, 0);
    func_003E8630(0x160002, 0x16000F);
    func_003E9138(0x160009, 0x706EC8FF, D_L01_001D8CC0, D_L01_001D8CC4, 0.035f, 0.043076925f, 0x7569);
    func_L01_00516D60(0x160009, 0);
    func_L01_005168F0(0x160009, 4.712389f);
    func_L01_00516AA0(0x160009, 0x40, 1);
    func_003E9138(0x16000A, 0x706EC8FF, D_L01_001D8CC0, D_L01_001D8CC8, 0.035f, 0.043076925f, 0x7569);
    func_L01_005168F0(0x16000A, 1.5707964f);
    func_L01_00516AA0(0x16000A, 0x40, 1);
    func_L01_00516D60(0x16000A, 0);
    func_003E8A08(0x160000, 0x160009, 0x16000A);
    a = (s32)func_003BB3A8(0);
    b = (s32)func_003BB3A8(0);
    D_L01_001D8C88 = b;
    D_L01_001D8C8C = (a + 0xF) & 0xFFFFFFF0;
    func_003B4528(func_003B42F8(0), D_L01_001D8C8C, D_L01_001D8C88, D_00160C40_0048E0C0.f4954, (s32)D_00160C40_0048E0C0.f5950);
    t = (s32)func_003BB3A8(0);
    D_L01_001D8C90 = t;
    D_L01_001D8C94 = (t + 0x8C0F) & 0xFFFFFFF0;
    func_003B4528(func_003B42F8(1), D_L01_001D8C90, D_L01_001D8C94, D_00160C40_0048E0C0.f4954, (s32)D_00160C40_0048E0C0.f7080);
    func_003E9138(0x160004, 0x80808080, 0.742f, 0.437f, 0.3399f, 0.3415f, 0);
    func_003E8710(0x160004, (s32)func_003B42F8(0));
    func_003E8630(0x160002, 0x160004);
    func_003E9138(0x160010, 0x80808080, 0.5025f, 0.195f, 0.8175f, 0.10576f, 0);
    func_003E8710(0x160010, (s32)func_003B42F8(1));
    func_L01_00516AA0(0x160010, 0x8000, 1);
    func_003E8630(0x160002, 0x160010);
    func_003E8FE8(0x160007, 0, 0xC066CCFF, 0.89f, 0.22f, 1.0f, 1.0f);
    func_003E7F20(0x160007, 1);
    func_003E7AC8(0x160007, 1);
    func_L01_00516B90(0x160007, 2, 3);
    func_003E8630(0x160002, 0x160007);
    func_003E9270(0x16000D, 0x332299DE, 0.5f, 0.195f, 0.825f, 0.1145f, 0.0035f, 0.006f);
    func_003E9270(0x16000B, 0x332299DE, 0.3245f, 0.43433f, 0.475f, 0.352f, 0.0035f, 0.006f);
    func_003E9270(0x16000C, 0x332299DE, 0.74f, 0.43433f, 0.34425f, 0.352f, 0.0035f, 0.006f);
    func_003E9270(0x16000E, 0x332299DE, 0.5f, 0.739f, 0.825f, 0.246f, 0.0035f, 0.006f);
    func_003E8A58(0x160002, 0x16000B, 0x16000C, 0x16000E, 0x16000D);
    func_003E8348(0x11, 0x160000);
    func_003E8348(0x12, 0x160002);
    func_L01_00516D60(0x160004, 0);
    func_003E87B8(0x160004, 1, 8);
}
/* localdecomp:end func_L01_0048E0C0 */

/* localdecomp:start func_L01_0048EA10 */
extern s32 D_L01_001E092C;
__asm__(".extern D_L01_001E092C, 4");
extern f32 D_L01_001D8CA4;
__asm__(".extern D_L01_001D8CA4, 4");
extern f32 D_L01_001D8C98;
__asm__(".extern D_L01_001D8C98, 4");
extern f32 D_L01_001E0928;
__asm__(".extern D_L01_001E0928, 4");
extern s32 D_L01_001E0934;
__asm__(".extern D_L01_001E0934, 4");
extern f32 D_L01_001E0930;
__asm__(".extern D_L01_001E0930, 4");
extern s32 D_L01_001D8C80;
__asm__(".extern D_L01_001D8C80, 4");
extern s32 D_L01_001D8C7C;
__asm__(".extern D_L01_001D8C7C, 4");
extern s32 D_L01_001D8C78;
__asm__(".extern D_L01_001D8C78, 4");
extern f32 D_L01_001D8CA8;
__asm__(".extern D_L01_001D8CA8, 4");
extern u8 *D_L01_001D52FC_0048EA10;
extern s32 D_L01_001E0954;
extern s32 D_L01_001E0958_0048EA10;
extern s32 func_003A5348(s32, s32, s32);
extern void func_003BB590(s32);
extern s32 func_L01_00516470(s32, f32, f32);

void func_L01_0048EA10(void) {
    s32 flags;

    if (D_L01_001E092C == 0) {
        D_L01_001E0928 = D_L01_001D8CA4 + D_L01_001D8C98 + 0.002f;
        D_L01_001E092C = 1;
    }
    if (D_L01_001E0934 == 0) {
        D_L01_001E0930 = D_L01_001D8C98 + 0.03846154f;
        D_L01_001E0934 = 1;
    }
    flags = *(s32 *)(D_L01_001D52FC_0048EA10 + 0x1C4);
    if (flags & 0x1000) {
        func_003A5348(3, 0, 0);
        D_L01_001E0954 = 0x11;
        D_L01_001D8C80--;
        if (D_L01_001D8C80 < 0) {
            D_L01_001D8C80 = 0;
            if (D_L01_001D8C7C - 1 >= 0) {
                D_L01_001E0958_0048EA10 = 2;
            }
        }
    } else if (flags & 0x4000) {
        if (D_L01_001D8C80 < D_L01_001D8C78 - 1) {
            func_003A5348(3, 0, 0);
            D_L01_001E0954 = 0x11;
            D_L01_001D8C80++;
            if (D_L01_001D8C80 >= 3) {
                D_L01_001D8C80 = 2;
                if (D_L01_001D8C7C + 1 <= D_L01_001D8C78 - 3) {
                    D_L01_001E0958_0048EA10 = 1;
                }
            }
        }
    }
    func_L01_00516470(0x160008, D_L01_001D8CA8, D_L01_001E0928 + (f32)D_L01_001D8C80 * D_L01_001E0930);
    func_003BB590(0x160008);
}
/* localdecomp:end func_L01_0048EA10 */

#include "common.h"

typedef struct {
    int f0;
    char pad[64];
} S_002EA318;
typedef struct {
    s32 idx;
    u8 pad[0x40];
} S_482AE0;
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
    u8 pad0[56];
    u16 x38;
    u8 pad3A[182];
} Entry_00483CD8;
typedef struct Obj_484598 Obj_484598;
typedef struct {
    u8 pad[12];
    void (*fn)(Obj_484598 *);
} Vt_484598;
struct Obj_484598 {
    u8 pad[4];
    Vt_484598 *vt;
};
typedef struct { u8 pad[0x38]; u16 h38; u8 pad3A[0xF0 - 0x3A]; } E_4848A8;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[0x82];
    u16 x8A;
    u8 pad8C[0x64];
} E_4858E8;
typedef struct {
    u8 pad[56];
    u16 unk38;
    u8 pad2[182];
} S_002C5640;
typedef struct {
    u8 pad0[56];
    u16 f56;
    u8 pad58[182];
} Entry_00485FF8;
typedef struct {
    s32 id;
    u8 flag;
    u8 pad[0xAB];
} Ent4876B0;
typedef struct {
    s32 obj;
    u8 pad[81];
    char name[91];
} Slot_00487740;
typedef struct VObj_487AC0 VObj_487AC0;
typedef struct {
    u8 pad[12];
    void (*fn)(VObj_487AC0 *self);
} VTbl_487AC0;
struct VObj_487AC0 {
    s32 pad;
    VTbl_487AC0 *vtbl;
};

/* declared by functions of L01_004838A0.c, which this file was cut from */
extern void func_L01_00517748(s32);
extern s32 func_L01_0047EBE0(void);

/* localdecomp:start func_L01_00483928 */
typedef struct {
    s32 id;
    s32 text;
    s32 pad[2];
} Item_00483928;

__asm__(".extern D_L01_001D84E4, 4");
__asm__(".extern D_L01_001D84E8, 4");
__asm__(".extern D_L01_001D84EC, 4");
__asm__(".extern D_L01_001D84F0, 4");
__asm__(".extern D_L01_001D84F4, 4");
__asm__(".extern D_L01_001D84F8, 4");
__asm__(".extern D_L01_001D84FC, 4");
__asm__(".extern D_L01_001D8500, 4");
__asm__(".extern D_L01_001D84B0_00483928, 8");
__asm__(".extern D_L01_001E06F0, 8");
extern f32 D_L01_001D84E4;
extern f32 D_L01_001D84E8;
extern f32 D_L01_001D84EC;
extern f32 D_L01_001D84F0;
extern f32 D_L01_001D84F4;
extern f32 D_L01_001D84F8;
extern f32 D_L01_001D84FC;
extern f32 D_L01_001D8500;
extern Item_00483928 D_L01_001D84B0[] __attribute__((section(".sdata")));
extern Item_00483928 D_L01_001D84B0_00483928[] __attribute__((section(".sdata")));
extern char D_L01_001E06F0[] __attribute__((section(".sdata")));
extern u8 D_00143950[];

extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_00516B90(s32, s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_003B5060(s32);
extern s32 func_003E8B98(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern int func_0011B868();
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00518110(s32, s32, s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);

void func_L01_00483928(void) {
    u8 *s;
    u32 i;
    s32 j;
    s32 k;
    f32 h;

    func_003E9138(0x100000, 0x80808080, 0, D_L01_001D84F4 + 0.5f, D_L01_001D84F8 + 0.5f, D_L01_001D84E4, D_L01_001D84E4);
    func_L01_00516B90(0x100000, 2, 2);
    func_L01_00517190(0x100000, 0xED93);
    func_003E9138(0x100001, 0x80808080, 0, 0.5f - D_L01_001D84F4, D_L01_001D84F8 + 0.5f, -D_L01_001D84E4, D_L01_001D84E4);
    func_L01_00516B90(0x100001, 2, 2);
    func_L01_00517190(0x100001, 0xED93);
    func_003E9138(0x100002, 0x80808080, 0, D_L01_001D84F4 + 0.5f, 0.5f - D_L01_001D84F8, D_L01_001D84E4, -D_L01_001D84E4);
    func_L01_00516B90(0x100002, 2, 2);
    func_L01_00517190(0x100002, 0xED93);
    func_003E9138(0x100003, 0x80808080, 0, 0.5f - D_L01_001D84F4, 0.5f - D_L01_001D84F8, -D_L01_001D84E4, -D_L01_001D84E4);
    func_L01_00516B90(0x100003, 2, 2);
    func_L01_00517190(0x100003, 0xED93);
    func_003E9138(0xD0028, 0x36808080, 0, 0.5f, 0.5f, D_L01_001D84EC, D_L01_001D84E8);
    func_L01_00516B90(0xD0028, 3, 3);
    func_003E9138(0x100004, 0x80808080, 0, 0.5f, 0.5f, D_L01_001D84FC * D_L01_001D84E4, D_L01_001D8500 * D_L01_001D84E4);
    func_L01_00516B90(0x100004, 3, 3);
    func_L01_00517190(0x100004, 0xED89);
    func_003B5060(0xD000B);
    func_003E8B98(0xD000B, 0x100004, 0x100000, 0x100001, 0x100002, 0x100003, 0xD0028);
    func_003E8348(0x10, 0xD000B);

    s = (u8 *)func_00381FF0(D_L01_001D84B0[2].text);
    func_003E8FE8(0xD000C, func_00381FF0(D_L01_001D84B0[0].text), 0x8066CCFF, 0.0f, 0.0f, 1.0f, 1.0f);
    func_003E8FE8(0xD000D, func_00381FF0(D_L01_001D84B0[1].text), 0x8066CCFF, 0.0f, 0.0f, 1.0f, 1.0f);
    j = 0;
    for (i = 0; i < func_0011B868(s); i++) {
        if (s[i] != 0x12 && s[i] != ':') {
            D_L01_001E06F0[j++] = s[i];
        }
    }
    D_L01_001E06F0[j] = 0;
    func_003E8FE8(0xD000E, (s32)D_L01_001E06F0, 0x8066CCFF, 0.0f, 0.0f, 1.0f, 1.0f);
    func_L01_00516AA0(0xD000C, 0x40, 1);
    func_L01_00516AA0(0xD000D, 0x40, 1);
    func_L01_00516AA0(0xD000E, 0x40, 1);
    func_003B5060(0xD0025);
    func_L01_00518110(0xD0025, 0xD000C, 0xD000D, 0xD000E);
    func_003E8348(0x11, 0xD0025);

    h = D_L01_001D84F0 * 2.0f;
    for (k = 0; k < 3; k++) {
        func_L01_00516470(D_L01_001D84B0_00483928[k].id, 0.5f, 0.5f - h * 0.5f + h * (f32)k * 0.5f);
        if (D_00143950[0xB7] >= 2) {
            func_L01_00517538(D_L01_001D84B0_00483928[k].id, 0.7f, 0.8f);
        }
    }
}
/* localdecomp:end func_L01_00483928 */

INCLUDE_ASM("asm/levels", func_L01_00483DD8);

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
extern s32 func_L01_00517190(s32, s32);
extern void func_L01_00516470(s32 a0, f32 a1, f32 a2);
extern void func_L01_00516AA0(s32, s32, s32);
extern Obj *func_003B42F8(s32);
extern void func_L01_00516470(s32, f32, f32);
extern s32 func_00381FF0(s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern s32 D_L01_001D8844;
extern s32 D_L01_001D87A0[2];
extern s32 D_L01_001D87C0[2];

/* localdecomp:start func_L01_00488248 */
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
} S_160C40_00488248;
typedef struct {
    u8 pad0[0xFC];
    u16 hFC;
    u8 padFE[2];
    u32 w100;
    u32 w104;
} S_1A7C10_00488248;
extern S_160C40_00488248 D_00160C40_00488248;
extern S_1A7C10_00488248 D_001A7C10;
extern s32 D_001D4C38;
extern s32 D_001D545C;
extern s32 D_001D4C60;
extern s32 D_001D4C80;
__asm__(".extern D_001D4C60, 32");
__asm__(".extern D_001D4C80, 32");
extern s32 D_L01_001D8840;
extern s32 D_L01_001D8844;
extern s32 D_L01_001D88D8;
extern s32 D_L01_001D88DC;
extern s32 D_L01_001D88E0;
extern s32 D_L01_001D88E4;
extern s32 D_L01_001D88E8;
extern s32 D_L01_001D87A0[2];
extern s32 D_L01_001D87C0[2];
extern char D_L01_001D87E0[8];
extern char D_L01_001D87F8[] __attribute__((section(".sdata")));
extern char D_L01_001D8818[] __attribute__((section(".sdata")));
extern char D_L01_001D89B8[8];
extern char D_L01_001D89C0[8];
extern char D_L01_001D89C8[];
extern char D_L01_002EAAA8[];
extern f32 D_L01_001D884C, D_L01_001D8850, D_L01_001D8854, D_L01_001D8858;
extern f32 D_L01_001D885C, D_L01_001D8860, D_L01_001D8864, D_L01_001D8868;
extern f32 D_L01_001D886C, D_L01_001D8870, D_L01_001D8874, D_L01_001D8878;
extern f32 D_L01_001D887C, D_L01_001D8880, D_L01_001D8884, D_L01_001D8888;
extern f32 D_L01_001D888C;
extern f32 D_L01_001D88A0, D_L01_001D88A4, D_L01_001D88A8, D_L01_001D88AC;
extern f32 D_L01_001D88C0, D_L01_001D88C4, D_L01_001D88C8, D_L01_001D88CC;
extern f32 D_L01_001D88D0, D_L01_001D88D4;
extern f32 D_L01_001D8910, D_L01_001D8914, D_L01_001D8918, D_L01_001D891C;
extern f32 D_L01_001D8920, D_L01_001D8924, D_L01_001D8928, D_L01_001D892C;
extern f32 D_L01_001D8930, D_L01_001D8934, D_L01_001D8938, D_L01_001D893C;
extern f32 D_L01_001D8940, D_L01_001D8944, D_L01_001D8948, D_L01_001D894C;
extern f32 D_L01_001D8950, D_L01_001D8954, D_L01_001D8958, D_L01_001D895C;
extern f32 D_L01_001D8960, D_L01_001D8964, D_L01_001D8968, D_L01_001D896C;
extern f32 D_L01_001D8970, D_L01_001D8974, D_L01_001D8978, D_L01_001D897C;
extern f32 D_L01_001D8980, D_L01_001D8984, D_L01_001D8988, D_L01_001D898C;
extern f32 D_L01_001D8990, D_L01_001D8994, D_L01_001D8998, D_L01_001D899C;
extern f32 D_L01_001D89A0, D_L01_001D89A4, D_L01_001D89A8, D_L01_001D89AC;
extern f32 D_L01_001D89B0;

__asm__(".extern D_L01_001D87A0, 8");
__asm__(".extern D_L01_001D87C0, 8");
__asm__(".extern D_L01_001D87E0, 8");
__asm__(".extern D_L01_001D87F8, 8");
__asm__(".extern D_L01_001D8818, 8");
__asm__(".extern D_L01_001D8840, 4");
__asm__(".extern D_L01_001D8844, 4");
__asm__(".extern D_L01_001D884C, 4");
__asm__(".extern D_L01_001D8850, 4");
__asm__(".extern D_L01_001D8854, 4");
__asm__(".extern D_L01_001D8858, 4");
__asm__(".extern D_L01_001D885C, 4");
__asm__(".extern D_L01_001D8860, 4");
__asm__(".extern D_L01_001D8864, 4");
__asm__(".extern D_L01_001D8868, 4");
__asm__(".extern D_L01_001D886C, 4");
__asm__(".extern D_L01_001D8870, 4");
__asm__(".extern D_L01_001D8874, 4");
__asm__(".extern D_L01_001D8878, 4");
__asm__(".extern D_L01_001D887C, 4");
__asm__(".extern D_L01_001D8880, 4");
__asm__(".extern D_L01_001D8884, 4");
__asm__(".extern D_L01_001D8888, 4");
__asm__(".extern D_L01_001D888C, 4");
__asm__(".extern D_L01_001D88A0, 4");
__asm__(".extern D_L01_001D88A4, 4");
__asm__(".extern D_L01_001D88A8, 4");
__asm__(".extern D_L01_001D88AC, 4");
__asm__(".extern D_L01_001D88C0, 4");
__asm__(".extern D_L01_001D88C4, 4");
__asm__(".extern D_L01_001D88C8, 4");
__asm__(".extern D_L01_001D88CC, 4");
__asm__(".extern D_L01_001D88D0, 4");
__asm__(".extern D_L01_001D88D4, 4");
__asm__(".extern D_L01_001D88D8, 4");
__asm__(".extern D_L01_001D88DC, 4");
__asm__(".extern D_L01_001D88E0, 4");
__asm__(".extern D_L01_001D88E4, 4");
__asm__(".extern D_L01_001D88E8, 4");
__asm__(".extern D_L01_001D8910, 4");
__asm__(".extern D_L01_001D8914, 4");
__asm__(".extern D_L01_001D8918, 4");
__asm__(".extern D_L01_001D891C, 4");
__asm__(".extern D_L01_001D8920, 4");
__asm__(".extern D_L01_001D8924, 4");
__asm__(".extern D_L01_001D8928, 4");
__asm__(".extern D_L01_001D892C, 4");
__asm__(".extern D_L01_001D8930, 4");
__asm__(".extern D_L01_001D8934, 4");
__asm__(".extern D_L01_001D8938, 4");
__asm__(".extern D_L01_001D893C, 4");
__asm__(".extern D_L01_001D8940, 4");
__asm__(".extern D_L01_001D8944, 4");
__asm__(".extern D_L01_001D8948, 4");
__asm__(".extern D_L01_001D894C, 4");
__asm__(".extern D_L01_001D8950, 4");
__asm__(".extern D_L01_001D8954, 4");
__asm__(".extern D_L01_001D8958, 4");
__asm__(".extern D_L01_001D895C, 4");
__asm__(".extern D_L01_001D8960, 4");
__asm__(".extern D_L01_001D8964, 4");
__asm__(".extern D_L01_001D8968, 4");
__asm__(".extern D_L01_001D896C, 4");
__asm__(".extern D_L01_001D8970, 4");
__asm__(".extern D_L01_001D8974, 4");
__asm__(".extern D_L01_001D8978, 4");
__asm__(".extern D_L01_001D897C, 4");
__asm__(".extern D_L01_001D8980, 4");
__asm__(".extern D_L01_001D8984, 4");
__asm__(".extern D_L01_001D8988, 4");
__asm__(".extern D_L01_001D898C, 4");
__asm__(".extern D_L01_001D8990, 4");
__asm__(".extern D_L01_001D8994, 4");
__asm__(".extern D_L01_001D8998, 4");
__asm__(".extern D_L01_001D899C, 4");
__asm__(".extern D_L01_001D89A0, 4");
__asm__(".extern D_L01_001D89A4, 4");
__asm__(".extern D_L01_001D89A8, 4");
__asm__(".extern D_L01_001D89AC, 4");
__asm__(".extern D_L01_001D89B0, 4");
__asm__(".extern D_L01_001D89B8, 8");
__asm__(".extern D_L01_001D89C0, 8");

extern void func_L01_00487F08(void);
extern void func_L01_00487F50(s32 *a, s32 *b);
extern u8 *func_L01_004881F0(u8 *a0, s32 a1, s32 a2);
extern u8 *func_L01_00488220(u8 *a0, s32 a1, s32 a2);
extern void *func_003BB3A8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_003B5060(s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DB48(f32);
extern void func_L01_00516728(s32, f32, f32);
extern void func_L01_00516B90(s32, s32, s32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_L01_00517340(s32, s32, s32, s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8710(s32, s32);
extern s32 func_003E87B8(s32, s32, s32);
extern s32 func_003E8A08(s32, s32, s32);
extern s32 func_L01_00518110(s32, s32, s32, s32);
extern s32 func_003E8AE8(s32, s32, s32, s32, s32, s32);
extern s32 func_L01_00518480(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00518D40_00488248(s32);
extern s32 func_L01_00516D60(s32, s32);

void func_L01_00488248(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 m;
    f32 dx, dy, dw, dh;
    f32 a;
    f32 x;
    f32 y;
    S_1A7C10_00488248 *p;
    u32 t;

    func_L01_00487F08();
    D_L01_001D88E0 = -1;
    D_L01_001D88E4 = -1;
    D_L01_001D88E8 = -1;
    D_L01_001D88D8 = (s32)func_003BB3A8(0);
    D_L01_001D88DC = (s32)func_003BB3A8(0);
    func_003B4528(func_003B42F8(0), D_L01_001D88D8, D_L01_001D88DC, D_00160C40_00488248.f4954, (s32)&D_00160C40_00488248 + 0x6C70);
    func_L01_00518D40_00488248(0x190014);
    func_003B9298(0x10, 0xD000B, 0xD0002, 0xD0003, 0xD0004, 0xD0000, 0xD0001, 0xD0005,
        0xD0008, func_00381FF0(0x104), 0xD0006, 0x124, 0xD0007, 0xCD5, 9.75f);
    func_003E8FE8(0xD0009, func_00381FF0(0x1B80), 0x8066CCFF, 0.035f, 0.5f, 1.0f, 1.0f);
    func_003E7F20(0xD0009, 1);
    func_003E8FE8(0xD000A, func_00381FF0(0x1B81), 0x8066CCFF, 0.97f, 0.5f, 1.0f, 1.0f);
    func_003E7F20(0xD000A, 1);
    func_003E8A08(0xD000B, 0xD0009, 0xD000A);
    D_L01_001D8840 = 0x190010;
    func_003B5060(0x190006);
    func_003E9138(0x190011, 0x332299DE, 0, D_L01_001D8918, D_L01_001D891C, D_L01_001D8920, D_L01_001D8924);
    func_003E9138(0x190013, 0x332299DE, 0, D_L01_001D8918, D_L01_001D891C + 0.0480799973f, D_L01_001D8920, D_L01_001D8924);
    func_003E9270(0x190010, 0x332299DE, D_L01_001D8928, D_L01_001D892C, D_L01_001D8930, D_L01_001D8934, D_L01_001D8874, D_L01_001D8878);
    func_003E8FE8(0x190007, (s32)D_L01_001D87E0, 0x8066CCFF, D_L01_001D8918, D_L01_001D8914, 1.0f, 1.0f);
    func_003E8FE8(0x190008, (s32)D_L01_001D87F8, 0x8066CCFF, 0.5f, 0.93f, 0.9f, 0.9f);
    func_003E8FE8(0x190000, (s32)D_L01_002EAAA8, 0x8066CCFF, D_L01_001D8918, D_L01_001D8910, 1.0f, 1.0f);
    func_003E8FE8(0x19000B, (s32)D_L01_001D8818, 0x8066CCFF, D_L01_001D8918, D_L01_001D8858, 1.0f, 1.0f);
    func_003E9270(0x19000A, 0x332299DE, D_L01_001D8918, D_L01_001D8854, D_L01_001D884C, D_L01_001D8850, D_L01_001D8874, D_L01_001D8878);
    func_003E9270(0x19000C, 0x332299DE, D_L01_001D8938, D_L01_001D893C, D_L01_001D8940, D_L01_001D8944, D_L01_001D8874, D_L01_001D8878);
    func_003E9270(0x19000D, 0x332299DE, D_L01_001D8948, D_L01_001D894C, D_L01_001D8950, D_L01_001D8954, D_L01_001D8874, D_L01_001D8878);
    func_003E9138(0x190009, 0x332299DE, 0, D_L01_001D8918 - D_L01_001D884C * 0.5f + 0.0035f, D_L01_001D8854, D_L01_001D884C - 0.007f, D_L01_001D8850);
    func_L01_00517340(0x190009, 0x60336600, 0x6095C862, 0x60336600, 0x6095C862);
    func_L01_00516B90(0x190009, 1, 3);
    func_003E8EF0(0x19000E, 0x37, 0x332299DE, 0.5f, 0.5f, D_L01_001D887C, D_L01_001D8880, 0.0f);
    func_003E9270(0x19000F, 0x332299DE, 0.5f, 0.5f, D_L01_001D886C, D_L01_001D8870, D_L01_001D8874, D_L01_001D8878);
    func_L01_00516AA0(0x190007, 0x40, 1);
    func_L01_00516AA0(0x190008, 0x40, 1);
    func_L01_00516AA0(0x190000, 0x40, 1);
    func_003E8AE8(0x190006, 0x190010, 0x190011, 0x190009, 0x19000A, 0x190013);
    func_L01_00518480(0x190006, 0x190007, 0x190008, 0x190000, 0x19000E, 0x19000F, 0x19000B, 0x19000C, 0x19000D);
    func_L01_00516470(0x19000E, 0.1f, 0.1f);
    func_003E8348(0x13, 0x190006);

    for (i = 0; i < 4; i++) {
        func_L01_00518D40_00488248(0x190015 + i);
        func_L01_00518D40_00488248(0x190019 + i);
        func_L01_00518D40_00488248(0x19001D + i);
        func_L01_00518110(0x190014, 0x190019 + i, 0x19001D + i, 0x190015 + i);
        for (j = 0; j < 5; j++) {
            s32 id1;
            s32 id2;
            s32 id3;

            id1 = ((s32 (*)(s32, s32, s32))func_L01_004881F0)(0x190025, j, i);
            func_003E8EF0(id1, 0x37, 0x332299DE, D_L01_001D8884 + (f32)j * D_L01_001D885C, D_L01_001D8888 + (f32)i * D_L01_001D8860, D_L01_001D887C, D_L01_001D8880, 0.0f);
            func_003E8630(0x190019 + i, id1);
            id2 = ((s32 (*)(s32, s32, s32))func_L01_004881F0)(0x190039, j, i);
            func_003E9138(id2, 0x706EC8FF, 0, D_L01_001D8884 + (f32)j * D_L01_001D885C + 0.001953f, D_L01_001D8888 + (f32)i * D_L01_001D8860 - D_L01_001D888C, D_L01_001D88D0, D_L01_001D88D4);
            func_003E8630(0x190015 + i, id2);
            id3 = ((s32 (*)(s32, s32, s32))func_L01_004881F0)(0x19004D, j, i);
            dx = 0.0f;
            dy = 0.0f;
            dw = 0.0f;
            dh = 0.0f;
            if (j > 0 && j < 4) {
                dx = -0.0009765f;
                dw = 0.001953f;
            }
            if (i == 1) {
                dy = 0.002404f;
            } else if (i == 3) {
                dy = 0.001202f;
                dh = -0.002404f;
            }
            func_003E9138(id3, 0x706EC8FF, 0, D_L01_001D88C4 + (f32)j * D_L01_001D885C + dx, D_L01_001D88C0 + (f32)i * D_L01_001D8860 + dy, D_L01_001D88C8 + dw, D_L01_001D88CC + dh);
            func_L01_00516B90(id3, 1, 3);
            func_L01_00517340(id3, 0x60336600, 0x6095C862, 0x60336600, 0x6095C862);
            func_003E8630(0x19001D + i, id3);
        }
    }
    for (k = 0; k < 2; k++) {
        func_L01_00518D40_00488248(0x190021 + k);
        func_003E8630(0x190014, 0x190021 + k);
        for (l = 0; l < 4; l++) {
            s32 box;
            s32 frame;

            box = ((s32 (*)(s32, s32, s32))func_L01_00488220)(0x190061, l, k);
            func_003E9270(box, 0x332299DE, D_L01_001D88A8 + (f32)l * D_L01_001D8864, D_L01_001D88AC + (f32)k * D_L01_001D8868, D_L01_001D886C, D_L01_001D8870, D_L01_001D8874, D_L01_001D8878);
            frame = ((s32 (*)(s32, s32, s32))func_L01_00488220)(0x190069, l, k);
            func_003E9138(frame, 0x706EC8FF, 0, D_L01_001D88A8 + (f32)l * D_L01_001D8864, D_L01_001D88AC + (f32)k * D_L01_001D8868, D_L01_001D88A0, D_L01_001D88A4);
            func_003E8A08(0x190021 + k, box, frame);
        }
    }
    func_003E8348(0x11, 0x190014);
    func_L01_00518D40_00488248(0x190023);
    func_003E8EF0(0x190001, 0x2A, 0x332299DE, D_L01_001D8964 + D_L01_001D897C, D_L01_001D8968 + D_L01_001D8980, D_L01_001D895C, D_L01_001D8960, 0.0f);
    func_003E8630(0x190023, 0x190001);
    func_L01_00518D40_00488248(0x190024);
    func_003E9138(0x190083, 0x80FFFFFF, 0, D_L01_001D8964 + D_L01_001D897C, D_L01_001D8968 + D_L01_001D8980, D_L01_001D896C * 0.07f * D_L01_001D8978, D_L01_001D896C * 0.08615385f * D_L01_001D8978);
    func_003E9270(0x190003, 0x332299DE, D_L01_001D8994, D_L01_001D8998, D_L01_001D899C, D_L01_001D89A0, D_L01_001D89A4, D_L01_001D89A8);
    func_003E9138(0x190002, 0x80808080, 0, D_L01_001D8984, D_L01_001D8988, D_L01_001D898C, D_L01_001D8990);
    func_003E8710(0x190002, (s32)func_003B42F8(0));
    func_003E87B8(0x190002, 1, 8);
    func_L01_00517190(0x190002, 0);
    func_L01_00516D60(0x190002, 0);
    func_L01_00518110(0x190024, 0x190002, 0x190003, 0x190083);
    D_L01_001D8844 = 0;
    for (m = 0; m < 8; m++) {
        a = (f32)m * 0.785398f;
        x = D_L01_001D89AC + D_L01_001D896C * D_L01_001D8970 * D_L01_001D8958 * func_0038D0B0(func_0038DB48(a));
        y = D_L01_001D89B0 - D_L01_001D896C * D_L01_001D8974 * D_L01_001D8958 * func_0038D098(func_0038DB48(a));
        func_003E9138(0x19007B + m, 0x706EC8FF, 0, D_L01_001D8964 + x, D_L01_001D8968 + y,
            D_L01_001D896C * 0.07f, D_L01_001D896C * 0.08615385f);
        func_003E8630(0x190024, 0x19007B + m);
    }
    func_003E8A08(0x190014, 0x190023, 0x190024);
    func_L01_00487F50(&D_001D4C60, D_L01_001D87A0);
    func_L01_00487F50(&D_001D4C80, D_L01_001D87C0);
    func_003E8FE8(0x190004, (s32)D_L01_001D89B8, 0x8066CCFF, 0.550376f, 0.178252f, 1.0f, 1.0f);
    func_003E8FE8(0x190005, (s32)D_L01_001D89C0, 0x8066CCFF, 0.88269f, 0.178252f, 1.0f, 1.0f);
    func_003E8A08(0x190006, 0x190004, 0x190005);
    func_003E7F20(0x190007, 1);
    func_003E7F20(0x190000, 1);
    func_003E7F20(0x19000B, 1);
    func_L01_00516AA0(0x19000B, 0x40, 1);
    func_003E7F20(0x190008, 0);
    func_L01_00516AA0(0x190004, 0x40, 1);
    func_L01_00516AA0(0x190005, 0x40, 1);
    func_L01_00516728(0x190007, 0.005f, 0.005f);
    func_L01_00516728(0x190008, 0.005f, 0.005f);
    func_0011B2E8(D_L01_001D87F8, D_L01_001D89C8, func_00381FF0(0x17E1));
    p = &D_001A7C10;
    if (p->hFC < 0xFFFF) {
        p->hFC++;
    }
    t = (D_001D4C38 * 5 + 2) / 6;
    if (p->w100 < t) {
        p->w100 = t;
    }
    p->w104 = p->w104 | (1 << D_001D545C) | 0x80000000;
}
/* localdecomp:end func_L01_00488248 */

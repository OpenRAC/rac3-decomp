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
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

/* localdecomp:start func_L01_004910C0 */
extern void func_L01_0048FBF0(void);
extern void func_L01_00490370_004910C0(void);
extern void func_L01_00490050(void *);
extern void func_L01_004903B0_004910C0(void);
extern void func_L01_004903D0_004910C0(void);
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
extern s32 D_L01_001E0998;
extern s32 D_L01_001E09B8;
extern s32 D_L01_001E09D8;
extern s32 D_L01_001E09F8;
extern s32 D_L01_001E0980[2];
extern s32 D_L01_001E09A0[2];
extern s32 D_L01_001E09C0[2];
extern s32 D_L01_001E09E0[2];
extern V16_48DCD8 D_L01_001D8DD8[];
s32 func_L01_004910C0(s32 idx) {
    V16_48DCD8 v;
    if (D_L01_001E0998 == 0) {
        func_003E6FA0(D_L01_001E0980, (s32)func_L01_0048FBF0, (s32)func_L01_00490370_004910C0, (s32)func_L01_00490050, (s32)func_L01_004903B0_004910C0, (s32)func_L01_004903D0_004910C0);
        D_L01_001E0998 = 1;
    }
    if (D_L01_001E09B8 == 0) {
        func_003E6FA0(D_L01_001E09A0, (s32)func_L01_0048FBF0, (s32)func_L01_00490370_004910C0, (s32)func_L01_00490050, (s32)func_L01_004903B0_004910C0, (s32)func_L01_004903D0_004910C0);
        D_L01_001E09B8 = 1;
    }
    if (D_L01_001E09D8 == 0) {
        func_003E6FA0(D_L01_001E09C0, (s32)func_L01_0048FBF0, (s32)func_L01_00490370_004910C0, (s32)func_L01_00490050, (s32)func_L01_004903B0_004910C0, (s32)func_L01_004903D0_004910C0);
        D_L01_001E09D8 = 1;
    }
    if (D_L01_001E09F8 == 0) {
        func_003E6FA0(D_L01_001E09E0, (s32)func_L01_0048FBF0, (s32)func_L01_00490370_004910C0, (s32)func_L01_00490050, (s32)func_L01_004903B0_004910C0, (s32)func_L01_004903D0_004910C0);
        D_L01_001E09F8 = 1;
    }
    v = D_L01_001D8DD8[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_L01_004910C0 */

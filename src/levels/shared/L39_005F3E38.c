#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005F3E38);

/* localdecomp:start func_L39_005F3E58 */
typedef struct S_005F3E58 {
    u8 pad0[0x228];
    f32 f228;
    f32 f22C;
    u8 pad230[8];
    f32 f238;
    f32 f23C;
    u8 pad240[0x10];
    s32 w250;
    s32 w254;
    s32 w258;
} S_005F3E58;

typedef struct { u8 pad[0x90]; s32 slots[6]; } T_005F3E58;
extern s32 D_L39_0024BB40;
extern s32 D_L39_00240288;
extern s32 D_L39_002412DC;
extern s32 D_L39_0024BB6C;
extern u8 D_00225660[];
extern u8 D_001FE020[];
extern S_005F3E58 D_L39_0025D6C0;
extern u8 D_L39_0024BA64;
extern u8 D_L39_0024BA65;
extern u8 D_L39_0024BA66;
extern f32 D_L39_0024BA68;
extern f32 D_L39_0024BA6C;
extern f32 D_L39_0024BA70;
extern f32 D_L39_0024BA74;
extern char D_L39_00269500[];

extern s32 func_L39_0060BE00(void);
extern void func_L39_0058A5D0(s32);
extern void func_001264E0(s32);
extern void func_00194BC8(s32, s32, s32, s32, s32);
extern void func_00194670(void);
extern s32 func_00193590(void);
extern void func_L39_005F3948(void);
extern void func_L39_005C1E10(void);
extern void func_00193B80(s32);
extern void func_00193B50(void);
extern void func_00392260(s32, s32, s32);
extern void func_00194F58(s32, char *);
extern void func_00139E08(s32);
extern void func_L39_005A61D8(void);
extern void func_L39_005A5010(void);
extern void func_001959F8(void);
extern s32 func_L39_005A4058(void);
extern s32 func_00194B88(s32);
extern s32 func_00194A38(s32);
extern void func_L39_005FD6F8(void);

void func_L39_005F3E58(void) {
    s32 i;

    if (func_L39_0060BE00() != 0) {
        return;
    }
    if (D_L39_0024BB40 != 0x27) {
        func_L39_0058A5D0(5);
    }
    D_L39_00240288 = 0;
    D_L39_002412DC = D_L39_0024BB40;
    func_001264E0(0);
    func_00194BC8(2, 0, 0, 0, 0);
    func_00194670();
    func_00193590();
    func_L39_005F3948();
    func_L39_005C1E10();
    D_00225660[7] = 1;
    for (i = 0; i < 6; i++) {
        if (((T_005F3E58 *)D_001FE020)->slots[i] != 0) {
            func_00193B80(((T_005F3E58 *)D_001FE020)->slots[i]);
            func_00193B50();
            D_L39_0024BB6C = 0;
            ((T_005F3E58 *)D_001FE020)->slots[i] = 0;
        }
    }
    D_L39_0025D6C0.w258 = 0x10;
    D_L39_0025D6C0.w250 = 0;
    D_L39_0025D6C0.w254 = 0;
    D_L39_0025D6C0.f228 = 0;
    D_L39_0025D6C0.f22C = 524288.0f;
    D_L39_0025D6C0.f238 = 255.0f;
    D_L39_0025D6C0.f23C = 128.0f;
    D_L39_0024BA64 = D_L39_0025D6C0.w250;
    D_L39_0024BA65 = D_L39_0025D6C0.w254;
    D_L39_0024BA66 = D_L39_0025D6C0.w258;
    D_L39_0024BA68 = D_L39_0025D6C0.f228;
    D_L39_0024BA6C = 524288.0f;
    D_L39_0024BA70 = 255.0f;
    D_L39_0024BA74 = 128.0f;
    func_00392260(0, 0, 0);
    func_00194F58(D_L39_002412DC, D_L39_00269500);
    D_00225660[7] = 1;
    do {
        func_001264E0(0);
        func_00139E08(0);
        func_L39_005A61D8();
        func_L39_005A5010();
        func_001959F8();
    } while (func_L39_005A4058() == 0);
    func_001264E0(0);
    func_00139E08(0);
    func_L39_005A61D8();
    func_L39_005A5010();
    func_001959F8();
    while (func_00193590() != 0) {
    }
    func_00193B50();
    func_00194B88(0);
    func_00194A38(0);
    func_00194A38(0);
    D_00225660[7] = 0;
    func_L39_005FD6F8();
}
/* localdecomp:end func_L39_005F3E58 */

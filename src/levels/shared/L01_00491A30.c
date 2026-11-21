#include "common.h"

typedef struct {
    s32 pad[3];
    s32 val;
} S_48DA70;
typedef struct { u8 b[16]; } V16_48DCD8;
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6EC0 - 0x4958];
    u8 fX[1];
} S_func_0048E5D8;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} E_002EB338;
typedef struct {
    s32 w0;
    u8 b4;
    u8 pad5[3];
    void (*fn)(void);
    s32 wC;
} S_48F880e;
typedef struct {
    u8 pad0[0x1C4];
    s32 w1C4;
} S_48F880;

/* localdecomp:start func_L01_00491A30 */
extern s32 D_L01_001D8DE8[2];
extern s32 func_L01_00517688(void);
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern void func_L01_00517918_00491A30(s32);
extern void func_L01_00491E28(void);
extern void func_003A2750(s32);
extern void func_003B9890(void);

void func_L01_00491A30(void) {
    s32 i;

    i = func_L01_00517688();
    D_L01_001D8DE8[i] = func_003B9C58(func_003B9BD0(func_L01_00517688()));
    func_L01_00517918_00491A30(16);
    func_L01_00517918_00491A30(17);
    func_L01_00517918_00491A30(20);
    func_L01_00491E28();
    func_003A2750(1);
    func_003B9890();
}
/* localdecomp:end func_L01_00491A30 */

/* localdecomp:start func_L01_00491AB0 */
extern void func_L01_0047E4B8_00491AB0();

void func_L01_00491AB0(void) {
    func_L01_0047E4B8_00491AB0();
}
/* localdecomp:end func_L01_00491AB0 */

/* localdecomp:start func_L01_00491AD0 */
extern void func_L01_0047E520_00491AD0();

void func_L01_00491AD0(void) {
    func_L01_0047E520_00491AD0();
}
/* localdecomp:end func_L01_00491AD0 */

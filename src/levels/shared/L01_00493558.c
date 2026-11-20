#include "common.h"

typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
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
typedef struct O_490778 O_490778;
typedef struct {
    u8 pad0[12];
    void (*fn)(O_490778 *);
} V_490778;
struct O_490778 {
    u8 pad0[4];
    V_490778 *vt;
};

/* declared by functions of L01_00492C80.c, which this file was cut from */
extern void func_003A5348(s32 a0, s32 a1, s32 a2);
extern void func_L01_00517748(s32 a0);

/* localdecomp:start func_L01_00493558 */
extern void func_003A5348(s32, s32, s32);
extern s32 func_L01_00480AB8(void);
extern void func_L01_00517748(s32);
extern s32 func_L01_00492870(void);
extern void func_L01_00516090_00493558(s32);
void func_L01_00493558(void) {
    func_003A5348(4, 0, 0);
    func_L01_00517748(func_L01_00480AB8());
    func_L01_00516090_00493558(func_L01_00492870());
}
/* localdecomp:end func_L01_00493558 */

/* localdecomp:start func_L01_004935A0 */
extern void func_003A5348(s32, s32, s32);
extern s32 func_L01_00494018(void);
extern void func_L01_00517748(s32);
extern s32 func_L01_00492870(void);
extern void func_L01_00516090_004935A0(s32);
void func_L01_004935A0(void) {
    func_003A5348(4, 0, 0);
    func_L01_00517748(func_L01_00494018());
    func_L01_00516090_004935A0(func_L01_00492870());
}
/* localdecomp:end func_L01_004935A0 */

/* localdecomp:start func_L01_004935E8 */
extern void func_L01_0047DAD0(s32 a0);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32 a0);
extern s32 func_L01_00492870(void);
extern void func_L01_00516090_004935E8(s32 a0);
extern void func_003A5348(s32 a0, s32 a1, s32 a2);
void func_L01_004935E8(void) {
    func_L01_0047DAD0(5);
    func_L01_00517748(func_L01_0047EBE0());
    func_L01_00516090_004935E8(func_L01_00492870());
    func_003A5348(4, 0, 0);
}
/* localdecomp:end func_L01_004935E8 */

/* localdecomp:start func_L01_00493638 */
extern void func_003A5348(s32, s32, s32);
extern s32 func_L01_0049B550(void);
extern void func_L01_00517748(s32);
extern s32 func_L01_00492870(void);
extern void func_L01_00516090_00493638(s32);
void func_L01_00493638(void) {
    func_003A5348(4, 0, 0);
    func_L01_00517748(func_L01_0049B550());
    func_L01_00516090_00493638(func_L01_00492870());
}
/* localdecomp:end func_L01_00493638 */

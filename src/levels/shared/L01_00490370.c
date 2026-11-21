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
extern void func_003A2750(s32);

/* localdecomp:start func_L01_00490370 */
extern void func_L01_00517918_00490370(s32);
extern void func_L01_00490930(void);
extern void func_003A2750(s32);

void func_L01_00490370(void) {
    func_L01_00517918_00490370(16);
    func_L01_00517918_00490370(17);
    func_L01_00517918_00490370(20);
    func_L01_00490930();
    func_003A2750(1);
}
/* localdecomp:end func_L01_00490370 */

/* localdecomp:start func_L01_004903B0 */
extern void func_L01_0047E4B8_004903B0();

void func_L01_004903B0(void) {
    func_L01_0047E4B8_004903B0();
}
/* localdecomp:end func_L01_004903B0 */

/* localdecomp:start func_L01_004903D0 */
extern void func_L01_0047E520_004903D0();

void func_L01_004903D0(void) {
    func_L01_0047E520_004903D0();
}
/* localdecomp:end func_L01_004903D0 */

#include "common.h"

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x7058 - 0x4958];
    u8 fX[1];
} S_func_00498868;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_498978;
typedef struct { u8 pad0[0x1C4]; s32 w1C4; } S_0049C950;
extern S_0049C950 *D_001D52FC[] __attribute__((section(".sdata")));

/* declared by functions of L01_0049BE80.c, which this file was cut from */
extern void func_L01_0049C9A0();
extern void func_L01_0049C950();

/* localdecomp:start func_L01_0049C950 */
extern s32 func_L01_00498610(s32);
extern void func_L01_004990A8(s32 a, s32 b);
extern void func_L01_0049D200(void);
extern void func_L01_0049D190(void *p);

void func_L01_0049C950(void *p) {
    func_L01_004990A8(func_L01_00498610(0), D_001D52FC[0]->w1C4);
    func_L01_0049D200();
    func_L01_0049D190(p);
}
/* localdecomp:end func_L01_0049C950 */

/* localdecomp:start func_L01_0049C9A0 */
extern s32 func_L01_00517918();
extern s32 D_L01_001D946C;
extern void func_L01_0049D150(void);
extern s32 func_003A2750(s32);
void func_L01_0049C9A0(void) {
    func_L01_00517918(0x10);
    func_L01_00517918(0x11);
    if (D_L01_001D946C != 0) {
        func_L01_00517918(0x14);
    }
    func_L01_0049D150();
    func_003A2750(1);
}
/* localdecomp:end func_L01_0049C9A0 */

/* localdecomp:start func_L01_0049C9E8 */
extern void func_L01_0047E4B8_0049C9E8();

void func_L01_0049C9E8(void) {
    func_L01_0047E4B8_0049C9E8();
}
/* localdecomp:end func_L01_0049C9E8 */

/* localdecomp:start func_L01_0049CA08 */
extern void func_L01_0047E520_0049CA08();

void func_L01_0049CA08(void) {
    func_L01_0047E520_0049CA08();
}
/* localdecomp:end func_L01_0049CA08 */

INCLUDE_ASM("asm/levels", func_L01_0049CA28);

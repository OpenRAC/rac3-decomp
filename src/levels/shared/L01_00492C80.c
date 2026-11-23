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

/* localdecomp:start func_L01_00492C80 */
extern void func_L01_00517918(s32);
extern void func_L01_00493038_00492C80(void);
extern void func_003A2750(s32);

void func_L01_00492C80(void) {
    func_L01_00517918(16);
    func_L01_00517918(17);
    func_L01_00517918(20);
    func_L01_00493038_00492C80();
    func_003A2750(1);
}
/* localdecomp:end func_L01_00492C80 */

/* localdecomp:start func_L01_00492CC0 */
extern void func_L01_0047E4B8_00492CC0();

void func_L01_00492CC0(void) {
    func_L01_0047E4B8_00492CC0();
}
/* localdecomp:end func_L01_00492CC0 */

/* localdecomp:start func_L01_00492CE0 */
extern void func_L01_0047E520_00492CE0();

void func_L01_00492CE0(void) {
    func_L01_0047E520_00492CE0();
}
/* localdecomp:end func_L01_00492CE0 */

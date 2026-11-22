#include "common.h"

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F78 - 0x4958];
    u8 f6F78[1];
} S_499898;
typedef struct Obj Obj;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj *);
} ObjVt;
struct Obj {
    s32 pad;
    ObjVt *vt;
};
typedef struct { s32 w0; s32 w4; s32 w8; u8 padC[0x18 - 0xC]; } E_4999A0;

/* localdecomp:start func_L01_0049D9E8 */
extern s32 D_L01_001D94C0;
extern s32 D_L01_001D94CC;
extern s32 D_L01_001D94D0;
extern s32 D_L01_001D94D4;
extern void func_L01_0049E228(void);
extern void func_L01_0049E380(void);
extern s32 func_L01_0049E408(void);
extern s32 func_L01_0049E4B0(void);
extern void func_L01_0049E558(void);

void func_L01_0049D9E8(void) {
    s32 t;

    switch (D_L01_001D94C0) {
    case 0:
        func_L01_0049E228();
        func_L01_0049E380();
        break;
    case 1:
        if (func_L01_0049E408() == 0) {
            t = D_L01_001D94D0;
            D_L01_001D94D0 = D_L01_001D94CC;
            D_L01_001D94CC = D_L01_001D94D4;
            D_L01_001D94D4 = t;
            D_L01_001D94C0 = 0;
            func_L01_0049E558();
        }
        break;
    case 2:
        if (func_L01_0049E4B0() == 0) {
            t = D_L01_001D94D4;
            D_L01_001D94D4 = D_L01_001D94CC;
            D_L01_001D94CC = D_L01_001D94D0;
            D_L01_001D94D0 = t;
            D_L01_001D94C0 = 0;
            func_L01_0049E558();
        }
        break;
    }
}
/* localdecomp:end func_L01_0049D9E8 */

/* localdecomp:start func_L01_0049DAB8 */
extern void func_L01_00517918(int);
extern void func_L01_0049E1E8(void);
extern void func_003A2750(int);

void func_L01_0049DAB8(void) {
    func_L01_00517918(16);
    func_L01_00517918(17);
    func_L01_0049E1E8();
    func_003A2750(1);
}
/* localdecomp:end func_L01_0049DAB8 */

/* localdecomp:start func_L01_0049DAF0 */
extern void func_L01_0047E4B8_0049DAF0();

void func_L01_0049DAF0(void) {
    func_L01_0047E4B8_0049DAF0();
}
/* localdecomp:end func_L01_0049DAF0 */

/* localdecomp:start func_L01_0049DB10 */
extern void func_L01_0047E520_0049DB10();

void func_L01_0049DB10(void) {
    func_L01_0047E520_0049DB10();
}
/* localdecomp:end func_L01_0049DB10 */

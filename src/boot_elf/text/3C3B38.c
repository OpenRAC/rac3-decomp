#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void func_003C3C18(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C3C18();
extern int func_003C3C98();
/* --- end of declarations from other files --- */

/* declarations of 3C3280.c's earlier functions (tools/port_from_us.py) */
typedef struct { f32 x, y, z, w; } V4_3BDAC8;
typedef struct { f32 m[12]; V4_3BDAC8 v; } M_3BDAC8;
typedef int Q_3BDAC8 __attribute__((mode(TI)));
extern void func_003CA858();
extern void func_0038D200(f32 *, void *, f32);
extern void func_0038D950();
extern void func_0038DA20();
extern int D_001DA050_003C3478;
extern int D_001DA490_003C3478;
extern s32 D_001D4BB0_003C3478;
extern void func_003CB408();
extern void func_003A99D0();
typedef struct { s16 a; s16 b; } T_BDC90;
typedef struct { u8 c[0xC]; s32 fC; } E_BDC90;
typedef struct { u8 p0[0x20]; E_BDC90 *f20; } O_BDC90;
extern s32 D_002DDFF0[];
extern O_BDC90 *D_002DA740[];
extern T_BDC90 D_002DD830[];
extern int D_001DA4E4_003C3640;
extern s32 D_001DA4E0;
extern s32 D_001D9D34_003C3640;
extern s32 D_001D5BA8_003C3640;
extern void func_003D1AC0();
extern void func_003D1768();
typedef struct { u8 pB_[0xB]; u8 bB; u8 pC[0x14]; s32 f20; } T_3BDEA8;
typedef struct { u8 p0[0x24]; T_3BDEA8 *f24; } O_3BDEA8;
extern u8 *D_001DA530;
extern u8 D_002FC1A0[];
extern u8 D_00380120[];
extern u8 D_001D7830[];
extern void func_0038D108();
extern u8 D_00380250[];
extern s32 D_001D9D30;
extern s32 D_001D9D38;
extern void func_11F0A0(s32);
extern void func_0038D108(u32 *, s32, s32);
extern void func_003CB6B8();
extern void func_0038CF58();
extern void func_0038D108();
extern u8 D_002DA380[];
extern void func_0038D108();
extern u8 D_002DA380[];
extern void func_003A9348(void *);
extern u8 D_002FC1A0[];
extern void func_003A96F0();
extern void func_003A97F8(s32, unsigned long);
extern u8 D_00110790[];
extern u8 D_00100080[];
extern u16 D_00110780[];
extern s32 D_001D9D1C_003C3A78;
extern s32 D_001DA050_003C3A78;
extern s32 D_001D9D38_003C3A78;
extern s32 D_001D9D30_003C3A78;
extern s32 D_001DA490_003C3A78;
extern u8 *D_001DA530_003C3A78;
extern s32 D_001DA054_003C3A78;
extern s32 D_001DA498_003C3A78;
extern s32 D_001DA4E4_003C3A78;

/* localdecomp:start func_003C3B38 */
extern void *D_001DA498_003C3B38;
extern void func_003A97F8(s32, unsigned long);
extern void func_11F0A0(s32);
extern void func_003C3A48(void);
extern void *func_003CB798(s32, void *, s32, s32);
extern void func_003C3A18(void);
void func_003C3B38(s32 a0, s32 a1) {
    func_003A97F8(0x47, 0x5360B);
    func_11F0A0(0);
    func_003C3A48();
    D_001DA498_003C3B38 = func_003CB798(a0, D_001DA498_003C3B38, a1, 0);
    func_003C3A18();
    D_001DA498_003C3B38 = (u8 *)D_001DA498_003C3B38 - 0x10;
}
/* localdecomp:end func_003C3B38 */

extern void func_003C3478(void);
extern void func_003C39A8(void);
extern void func_003C3640(void);
extern void func_003C3780(void);
extern s32 D_001DA4E4[];
extern u8 *D_001DA530;
extern u8 D_002FC1A0[];
/* localdecomp:start func_003C3BB8 */
void func_003C3BB8(void) {
    s32 t;
    func_003C3478();
    func_003C39A8();
    t = D_001DA4E4[0];
    if (t != 0) {
        func_003C3640();
    }
    t = D_001DA530 > D_002FC1A0;
    if (t) {
        func_003C3780();
    }
}
/* localdecomp:end func_003C3BB8 */

/* localdecomp:start func_003C3C18 */
extern void func_003C39F0();
extern void func_003C3A78();
extern void func_003C3BB8();
s32 func_003CB798_003C3C18(s32, s32, s32, s32);      /* extern */
extern s32 D_001DA498;
extern s32 D_001DA49C;
extern s32 D_001DA4D4;

void func_003C3C18(void) {
    s32 var_a3;

    func_003C3A78();
    func_003C39F0();
    var_a3 = 1;
    if (D_001DA4D4 != 0) {
        D_001DA4D4 = 0;
        var_a3 = 3;
    }
    D_001DA498 = func_003CB798_003C3C18(D_001DA49C, D_001DA498, -1, var_a3);
    func_003C3BB8();
}
/* localdecomp:end func_003C3C18 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C3C78);

/* localdecomp:start func_003C3C98 */
extern int D_001DA49C;
extern int D_001DA4A4;
int func_003C3C98(void) {
    unsigned char *current = (unsigned char *)(*(volatile int *)&D_001DA49C);
    unsigned char *end = (unsigned char *)(*(volatile int *)&D_001DA4A4);
    int result = (int)end;

    if (current != end) {
        do {
            result = *(int *)(current + 0x24);
            current += 0x100;
        } while (current != end);
    }
    return result;
}
/* localdecomp:end func_003C3C98 */

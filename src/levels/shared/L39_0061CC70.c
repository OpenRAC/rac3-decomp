#include "common.h"

/* localdecomp:start func_L39_0061CC70 */
__asm__(".extern D_L39_00242A00, 16");
__asm__(".extern D_L39_00241640, 16");
__asm__(".extern D_L39_00241120, 16");
typedef struct { u8 p0[4]; s32 f4; u8 p8[0x161]; u8 f169; u8 p16A[6]; s32 f170; u8 p174[0x661]; u8 f7D5[8]; u8 f7DD[8][16]; } S_0061CC70;
typedef struct { u8 p0[0x14]; struct { u8 p0[0xC]; void (*fC)(void *); } *f14; u8 p18[0x4500 - 0x18]; } E_0061CC70;
extern S_0061CC70 D_001A5CD0;
extern u8 D_001DA700_sda;
extern u8 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern struct { u8 p[0x178]; s32 f178; } *D_L39_00241640;
extern s32 *D_L39_00241120;
extern E_0061CC70 D_L39_002FB000[];
extern s32 D_L39_00242A00;
extern void func_L39_0066B7C8(void);
extern void func_L01_00486960(void);
extern void func_L39_0061C2A8(void);
extern void func_L39_0057CEB0(void);
extern void func_L39_00662748(void);
extern void func_L39_0066AFA0(void);
extern void func_L39_0066EAA8(void);
extern void func_L39_0061E330(void);
extern void func_L39_0061D628(void);
extern void func_L39_00670438(void);
extern void func_L39_00674398(void);
extern void func_L39_006703B0(void *);
extern s32 func_L39_0061BF68(u8 *);
extern void func_L39_00666160(u8 *);
extern void func_L39_0066BE40(void);

void func_L39_0061CC70(void) {
    s32 i;
    s32 j;
    s32 n;
    s32 k;
    long skip;
    E_0061CC70 *e;
    u8 **q;
    u8 **ids;

    skip = 0;
    if (D_001A5CD0.f170 == 0) { s32 t = D_001A5CD0.f4 == 0; skip = t; }
    if (skip & 0xFF) return;
    ids = D_L39_0024CE20;
    if (D_001DA700_sda == 0) {
        n = 0;
        for (j = 0; j < 8; j++) {
            if (ids[j] != 0) n++;
        }
        if (n == D_L39_00241640->f178) {
            func_L39_0066B7C8();
            D_001DA700_sda = 1;
        }
    }
    if (D_001A5CD0.f169 != 0) {
        func_L01_00486960();
        D_001A5CD0.f169 = 0;
    }
    func_L39_0061C2A8();
    func_L39_0057CEB0();
    func_L39_00662748();
    func_L39_0066AFA0();
    for (i = 0; i < *D_L39_00241120; i++) {
        e = D_L39_002FB000 + i;
        e->f14->fC(e);
    }
    func_L39_0066EAA8();
    func_L39_0061E330();
    func_L39_0061D628();
    func_L39_00670438();
    if (D_L39_00242A00 != 0) func_L39_00674398();
    for (k = 0, q = ids; k < 8; q++, k++) {
        if (D_001A5CD0.f7D5[k] == 1) {
            D_001A5CD0.f7D5[k] = 2;
            func_L39_006703B0(D_001A5CD0.f7DD[k]);
        }
        if (*q != 0) {
            if (func_L39_0061BF68(*q) < 0) func_L39_00666160(*q);
        }
    }
    if (D_001DA700_sda != 0) func_L39_0066BE40();
}
/* localdecomp:end func_L39_0061CC70 */

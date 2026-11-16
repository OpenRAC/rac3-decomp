#include "common.h"

/* NTSC-U counterpart of func_L39_0061CC70 (src/levels/shared/L39_0061CC70.c) */
/* localdecomp:start func_L39_0061A4F8 */
__asm__(".extern D_L39_00242B80, 16");
__asm__(".extern D_L39_002417C0, 16");
__asm__(".extern D_L39_002412A0, 16");
typedef struct { u8 p0[4]; s32 f4; u8 p8[0x161]; u8 f169; u8 p16A[6]; s32 f170; u8 p174[0x661]; u8 f7D5[8]; u8 f7DD[8][16]; } S_0061CC70;
typedef struct { u8 p0[0x14]; struct { u8 p0[0xC]; void (*fC)(void *); } *f14; u8 p18[0x4500 - 0x18]; } E_0061CC70;
extern S_0061CC70 D_001A5E50;
extern u8 D_001DA700_sda_0061A4F8;
extern u8 *D_L39_0024CF20[] __attribute__((section(".sdata")));
extern struct { u8 p[0x178]; s32 f178; } *D_L39_002417C0;
extern s32 *D_L39_002412A0;
extern E_0061CC70 D_L39_002FB100[];
extern s32 D_L39_00242B80;
extern void func_L39_00668EC0(void);
extern void func_L01_00483100(void);
extern void func_L39_00619B30(void);
extern void func_L39_0057BF08(void);
extern void func_L39_0065FE70(void);
extern void func_L39_00668698(void);
extern void func_L39_0066C158(void);
extern void func_L39_0061BBB8(void);
extern void func_L39_0061AEB0(void);
extern void func_L39_0066DAE8(void);
extern void func_L39_00671A50(void);
extern void func_L39_0066DA60(void *);
extern s32 func_L39_006197F0(u8 *);
extern void func_L39_00663888(u8 *);
extern void func_L39_00669538(void);

void func_L39_0061A4F8(void) {
    s32 i;
    s32 j;
    s32 n;
    s32 k;
    long skip;
    E_0061CC70 *e;
    u8 **q;
    u8 **ids;

    skip = 0;
    if (D_001A5E50.f170 == 0) { s32 t = D_001A5E50.f4 == 0; skip = t; }
    if (skip & 0xFF) return;
    ids = D_L39_0024CF20;
    if (D_001DA700_sda_0061A4F8 == 0) {
        n = 0;
        for (j = 0; j < 8; j++) {
            if (ids[j] != 0) n++;
        }
        if (n == D_L39_002417C0->f178) {
            func_L39_00668EC0();
            D_001DA700_sda_0061A4F8 = 1;
        }
    }
    if (D_001A5E50.f169 != 0) {
        func_L01_00483100();
        D_001A5E50.f169 = 0;
    }
    func_L39_00619B30();
    func_L39_0057BF08();
    func_L39_0065FE70();
    func_L39_00668698();
    for (i = 0; i < *D_L39_002412A0; i++) {
        e = D_L39_002FB100 + i;
        e->f14->fC(e);
    }
    func_L39_0066C158();
    func_L39_0061BBB8();
    func_L39_0061AEB0();
    func_L39_0066DAE8();
    if (D_L39_00242B80 != 0) func_L39_00671A50();
    for (k = 0, q = ids; k < 8; q++, k++) {
        if (D_001A5E50.f7D5[k] == 1) {
            D_001A5E50.f7D5[k] = 2;
            func_L39_0066DA60(D_001A5E50.f7DD[k]);
        }
        if (*q != 0) {
            if (func_L39_006197F0(*q) < 0) func_L39_00663888(*q);
        }
    }
    if (D_001DA700_sda_0061A4F8 != 0) func_L39_00669538();
}
/* localdecomp:end func_L39_0061A4F8 */

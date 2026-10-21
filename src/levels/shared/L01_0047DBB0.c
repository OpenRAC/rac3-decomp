#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[32];
    s32 src;
    u8 pad36[96];
    s32 mode;
} S_47A458;
typedef struct {
    s32 pad[3];
    s32 a[4];
} S_47A608;
typedef struct { s32 x0; s32 x4; s32 next; s32 arr[4]; } Struct002E9FD8;
typedef struct {
    s32 state;
    u8 pad4[24];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    u8 pad2C[68];
    u8 unk70;
} S_002E9FD8;
typedef struct {
    u8 pad0[112];
    u8 x70;
    u8 pad71[3];
    s32 x74;
} S_0047B230;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8[2];
} T_0047B230;

INCLUDE_ASM("asm/levels", func_L01_0047DBB0);

/* localdecomp:start func_L01_0047DCB8 */


extern S_47A458 D_L01_002E9F98;
extern s32 D_L01_001DF948;
extern s32 D_001D4BC4;
extern s32 D_001D4BB4;
extern void func_003A92F0(s32);
extern void func_0012C908(s32);
extern void func_0012CB88(void *, s16, s32, s32, s32, s32, s32, s32);
extern void func_0011F0A0(s32);
extern void func_0012CE48(void *, s32);
extern void func_0012A9F0(s32, s32);

void func_L01_0047DCB8(void) {
    s128 buf[7];
    s32 size;
    s32 dst;
    s32 src;

    func_003A92F0(1);
    func_0012C908(0);
    D_L01_001DF948++;
    size = D_001D4BC4 * 1536;
    src = D_L01_002E9F98.src;
    dst = D_001D4BB4;
    if (D_L01_002E9F98.mode >= 2) {
        dst = 0x3FB000 - size;
    }
    for (; size >= 0; size -= 16384) {
        func_0012CB88(buf, dst >> 8, 1, 0, 0, 0, 64, 64);
        dst += 16384;
        func_0011F0A0(0);
        func_0012CE48(buf, src);
        src += 16384;
        func_0012A9F0(0, 0);
    }
    D_L01_002E9F98.mode = 0;
}
/* localdecomp:end func_L01_0047DCB8 */

LINKER_REMNANT("asm/levels", func_L01_0047DDC0);

INCLUDE_ASM("asm/levels", func_L01_0047DDC8);

/* localdecomp:start func_L01_0047DE68 */
extern S_47A458 D_L01_002E9F98;
extern void func_0038CB78(s32, s32, s32);
void func_L01_0047DE68(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        func_0038CB78((*(S_47A608 *)&D_L01_002E9F98).a[i], 0, 2048);
    }
}
/* localdecomp:end func_L01_0047DE68 */

/* localdecomp:start func_L01_0047DEC0 */
extern S_47A458 D_L01_002E9F98;
extern void func_L01_0047DE68(void);
void func_L01_0047DEC0(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        (*(Struct002E9FD8 *)&D_L01_002E9F98).arr[i] = (*(Struct002E9FD8 *)&D_L01_002E9F98).next;
        (*(Struct002E9FD8 *)&D_L01_002E9F98).next += 2048;
    }
    func_L01_0047DE68();
}
/* localdecomp:end func_L01_0047DEC0 */

INCLUDE_ASM("asm/levels", func_L01_0047DF10);

INCLUDE_ASM("asm/levels", func_L01_0047DF40);

INCLUDE_ASM("asm/levels", func_L01_0047E330);

/* localdecomp:start func_L01_0047E490 */
extern u8 D_L01_002EA00A[];

void func_L01_0047E490(void) {
    D_L01_002EA00A[0] = 1;
}
/* localdecomp:end func_L01_0047E490 */

/* localdecomp:start func_L01_0047E4A0 */
extern u8 D_L01_002EA00A[];
u8 func_L01_0047E4A0(void) {
    return D_L01_002EA00A[0];
}
/* localdecomp:end func_L01_0047E4A0 */

INCLUDE_ASM("asm/levels", func_L01_0047E4B0);

INCLUDE_ASM("asm/levels", func_L01_0047E4B8);

/* localdecomp:start func_L01_0047E4C0 */
extern void *D_L01_002E9FB8[];
extern s32 D_L01_001D6694;
extern s32 D_001A1ED4[];
extern s32 D_001D4BC4;
extern void func_L01_004C6030(void *a0, s32 a1, s32 a2);
extern void func_0038AE20(s32 a0, s32 a1, s32 a2, s32 a3);
void func_L01_0047E4C0(void) {
    void *p = D_L01_002E9FB8[0];
    if (p != 0 && D_L01_001D6694 == 3) {
        func_L01_004C6030(p, D_001A1ED4[0], D_001D4BC4 << 11);
        func_0038AE20(0, 0, 0, 96);
    }
}
/* localdecomp:end func_L01_0047E4C0 */

/* localdecomp:start func_L01_0047E520 */
extern void func_003B98A0();
extern void func_L01_0047EDB8_0047E520();

 
void func_L01_0047E520(void) {
    func_L01_0047EDB8_0047E520();
    func_003B98A0();
}
/* localdecomp:end func_L01_0047E520 */

/* localdecomp:start func_L01_0047E548 */
extern void func_L01_0047E4B8_0047E548();
 
void func_L01_0047E548(void) {
    func_L01_0047E4B8_0047E548();
}
/* localdecomp:end func_L01_0047E548 */

/* localdecomp:start func_L01_0047E568 */
extern S_47A458 D_L01_002E9F98;

extern s32 D_L01_001D6690;
extern s32 D_L01_001D6694;
extern u8 D_L01_001D672E;
extern void func_L01_0047DBB0(s32);
extern void func_003A9050(void);
extern void func_L01_0047DF10(void);
extern void func_0013C1D0(s32);
extern s32 func_L01_0041A4C0(void);
extern void func_003A1D00(void);
extern void func_0013B620(void);
extern void func_003A4288(void);
extern void func_L01_004606A8(s32);
extern void func_L01_0041A008(s32);
extern void func_003A5348(s32, s32, s32);
extern void func_L01_0047DAC8(void);

void func_L01_0047E568(void)
{
    if ((u32)(((S_002E9FD8 *)&D_L01_002E9F98)[0].state - 20) < 2) {
        func_L01_0047DBB0(1);
    }
    func_003A9050();
    ((S_002E9FD8 *)&D_L01_002E9F98)[0].unk24 = 0;
    ((S_002E9FD8 *)&D_L01_002E9F98)[0].unk28 = 0;
    func_L01_0047DF10();
    ((S_002E9FD8 *)&D_L01_002E9F98)[0].unk1C = 0;
    if (((S_002E9FD8 *)&D_L01_002E9F98)[0].unk70 == 0 || (u32)(((S_002E9FD8 *)&D_L01_002E9F98)[0].state - 20) >= 2) {
        ((S_002E9FD8 *)&D_L01_002E9F98)[0].unk20 = 0;
    }
    if (D_L01_001D6690 != 5 && D_L01_001D6694 != 5) {
        func_0013C1D0(77);
    }
    if (func_L01_0041A4C0() == 0 && D_L01_001D6690 != 5 && D_L01_001D6694 != 5) {
        func_003A1D00();
    }
    func_0013B620();
    func_003A4288();
    func_L01_004606A8(0);
    D_L01_001D672E = 0;
    func_L01_0041A008(0);
    if (D_L01_001D6690 == 0) {
        func_003A5348(20, 0, 0);
    }
    func_L01_0047DAC8();
}
/* localdecomp:end func_L01_0047E568 */

INCLUDE_ASM("asm/levels", func_L01_0047E680);

INCLUDE_ASM("asm/levels", func_L01_0047E738);

INCLUDE_ASM("asm/levels", func_L01_0047E7C8);

INCLUDE_ASM("asm/levels", func_L01_0047E7D0);

INCLUDE_ASM("asm/levels", func_L01_0047E908);

/* localdecomp:start func_L01_0047EA90 */
extern S_47A458 D_L01_002E9F98;


extern u8 D_L01_002E9FC4[];
extern u8 D_L01_002E9FE8[];
extern T_0047B230 D_L01_001E15E0;

extern T_0047B230 *func_003E6C08(void);
extern void *func_003E6DE8(T_0047B230 *);
extern void func_L01_00514DD0(void *, s32, s32);
extern void func_L01_00479280(void);
extern void func_L01_0047B420(void);
extern void func_L01_0047B990(void);
extern void func_L01_00514750(void *);
extern void func_L01_0047E908(void);

void func_L01_0047EA90(void) {
    void *q;
    s32 i;

    if ((*(S_0047B230 *)&D_L01_002E9F98).x70 == 0 && (*(S_0047B230 *)&D_L01_002E9F98).x74 != 5) {
        q = func_003E6DE8(D_L01_001E15E0.x4 != 0 ? &D_L01_001E15E0 : func_003E6C08());
        for (i = 0; i < 35; i++) {
            if (q != 0) {
                func_L01_00514DD0(q, i, D_L01_002E9FC4[i]);
            }
        }
        if ((*(S_0047B230 *)&D_L01_002E9F98).x74 != 10) {
            func_L01_00479280();
            func_L01_0047B420();
            func_L01_0047B990();
        }
    }
    func_L01_00514750(D_L01_002E9FE8);
    func_L01_0047E908();
}
/* localdecomp:end func_L01_0047EA90 */

INCLUDE_ASM("asm/levels", func_L01_0047EB88);

INCLUDE_ASM("asm/levels", func_L01_0047EBE0);

INCLUDE_ASM("asm/levels", func_L01_0047EC38);

/* localdecomp:start func_L01_0047EC88 */
extern void func_L01_0047ECB8_0047EC88();
extern void func_L01_0047ECB0_0047EC88();

 
void func_L01_0047EC88(void) {
    func_L01_0047ECB0_0047EC88();
    func_L01_0047ECB8_0047EC88();
}
/* localdecomp:end func_L01_0047EC88 */

INCLUDE_ASM("asm/levels", func_L01_0047ECB0);

INCLUDE_ASM("asm/levels", func_L01_0047ECB8);

INCLUDE_ASM("asm/levels", func_L01_0047ECC0);

INCLUDE_ASM("asm/levels", func_L01_0047EDB0);

INCLUDE_ASM("asm/levels", func_L01_0047EDB8);

INCLUDE_ASM("asm/levels", func_L01_0047EDC0);

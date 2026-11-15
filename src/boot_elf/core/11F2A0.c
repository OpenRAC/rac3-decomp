#include "common.h"
#include "cpu.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_0011F5A8();
extern s32 func_0011F5A0();
extern s32 func_0011F468();
extern s32 func_0011F4F0();
extern s32 func_0011F5C8(s32, s32);
extern s32 func_0011F5C0(void);
extern s32 func_0011F3E8();
/* --- end of declarations from other files --- */

/* localdecomp:start func_0011F2A0 */
extern s32 D_0013DBE8;
/* Candidate for func_0011F2A0 (boot_elf, PAL retail).
 *
 * Retail reaches the global through lui/%lo, not through $gp:
 *   lui  $v0, %hi(D_0013DBE8)
 *   jr   $ra
 *   sw   $zero, %lo(D_0013DBE8)($v0)
 * With -G8 a sized scalar is small data and gcc emits "sw $zero, off($gp)".
 * An unsized array is never small data, so the global is reached through an
 * alias symbol at the same address (the plain name stays a sized scalar for
 * the rest of the file).
 */

extern s32 D_0013DBE8_0011F2A0[];

void func_0011F2A0(void) {
    D_0013DBE8_0011F2A0[0] = 0;
}
/* localdecomp:end func_0011F2A0 */

/* localdecomp:start func_0011F2B0 */
extern s32 func_00124920(void);
extern s32 func_00124970(void);

void func_0011F2B0(void)
{
    s32 di;

    di = func_00124920();
    *(volatile u32 *)0x1000F000 = 4;
    CpuSync();
    if (di) {
        func_00124970();
    }
    while (!(*(volatile u32 *)0x1000F000 & 4)) {
    }
    di = func_00124920();
    *(volatile u32 *)0x1000F000 = 4;
    CpuSync();
    if (di) {
        func_00124970();
    }
}
/* localdecomp:end func_0011F2B0 */

/* localdecomp:start func_0011F340 */
extern s32 func_00124920(void);
extern s32 func_00124970(void);
extern void func_0011F190(volatile s32 *flag, volatile long *out);

long func_0011F340(void)
{
    volatile s32 flag;
    volatile long out;
    s32 di;

    flag = 0;
    func_0011F190(&flag, &out);
    di = func_00124920();
    *(volatile u32 *)0x1000F000 = 4;
    CpuSync();
    if (di) {
        func_00124970();
    }
    while ((*(volatile u32 *)0x1000F000 & 4) == 0) {
        if (flag != 0) {
            break;
        }
    }
    di = func_00124920();
    *(volatile u32 *)0x1000F000 = 4;
    CpuSync();
    if (di) {
        func_00124970();
    }
    return out;
}
/* localdecomp:end func_0011F340 */

/* localdecomp:start func_0011F3E8 */
s32 func_0011F3E8(s32 fd, const void *buf, s32 count)
{
    extern s32 func_001204C0(void);
    extern s32 func_00120278(s8 *buf, s32 len);

    if ((u32)(fd - 1) < 2) {
        if (D_0013DBE8 == 0) {
            if (func_001204C0() == 0) {
                return -1;
            }
            D_0013DBE8 = 1;
        }
        return func_00120278((s8 *)buf, count);
    }
    return -1;
}
/* localdecomp:end func_0011F3E8 */

/* localdecomp:start func_0011F468 */
s32 func_0011F468(s32 fd, void *buf, s32 count)
{
    extern s32 func_001204C0(void);
    extern int func_001203F0(char *buf, int n);

    if (fd == 0) {
        if (D_0013DBE8 == 0) {
            if (func_001204C0() == 0) {
                return -1;
            }
            D_0013DBE8 = 1;
        }
        return func_001203F0((char *)buf, count);
    }
    return -1;
}
/* localdecomp:end func_0011F468 */

/* localdecomp:start func_0011F4E0 */
s32 func_0011F4E0(void) {
    return -1;
}
/* localdecomp:end func_0011F4E0 */

/* localdecomp:start func_0011F4E8 */
s32 func_0011F4E8(void) {
    return -1;
}
/* localdecomp:end func_0011F4E8 */

ASM_FUNC("asm/boot_elf/handwritten", func_0011F4F0);

/* localdecomp:start func_0011F5A0 */
s32 func_0011F5A0(void) {
    return 1;
}
/* localdecomp:end func_0011F5A0 */

/* localdecomp:start func_0011F5A8 */
typedef struct { s32 x0; s32 x4; u8 pad[0x40]; long x48; } S_11F5A8;
s32 func_0011F5A8(s32 a, S_11F5A8 *b) {
    b->x4 = 0x2000;
    b->x48 = 0;
    return 0;
}
/* localdecomp:end func_0011F5A8 */

/* localdecomp:start func_0011F5C0 */
s32 func_0011F5C0(void) {
    return 1;
}
/* localdecomp:end func_0011F5C0 */

/* localdecomp:start func_0011F5C8 */
extern void func_00124F20(s32);
s32 func_0011F5C8(s32 a, s32 b) {
    if (a == 1) {
        func_00124F20(b);
    }
    return 0;
}
/* localdecomp:end func_0011F5C8 */

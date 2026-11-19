#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3BB530.c's earlier functions */
extern void func_003BB7B0(s32);
extern s32 func_12C908(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_13B620(void);

LINKER_REMNANT("asm/remnants", func_003BB670);

/* localdecomp:start func_003BB678 */
s32 func_003BB678(void) {
    return 0;
}
/* localdecomp:end func_003BB678 */

/* localdecomp:start func_003BB680 */
typedef struct { s32 f0; s32 f4; } E_3B61A0;
extern E_3B61A0 D_0037FA58[];
extern s32 D_0037FA64[];
extern char D_001D8C40[];
extern char D_001D8C48[];
extern s32 func_00381FF0();
extern void func_11B2E8();
char *func_003BB680(char *buf, s32 n) {
    s32 r;
    s32 x;
    s32 y;
    char *fmt2;
    char *fmt;
    switch (n) {
    case 2:
    case 5:
    case 10:
    case 23:
    case 24:
    case 25:
    case 26:
        r = 0;
        break;
    default:
        r = 1;
        break;
    }
    if (r != 0) {
        fmt = D_001D8C40;
        x = func_00381FF0(0xE2);
        y = func_00381FF0(n > 0 ? D_0037FA58[n % 60].f4 : D_0037FA64[0]);
        func_11B2E8(buf, fmt, x, y);
    } else {
        fmt2 = D_001D8C48;
        y = func_00381FF0(n > 0 ? D_0037FA58[n % 60].f4 : D_0037FA64[0]);
        func_11B2E8(buf, fmt2, y);
    }
    return buf;
}
/* localdecomp:end func_003BB680 */

/* localdecomp:start func_003BB7B0 */
extern u8 D_001D8CB0;
void func_003BB7B0(s32 a) {
    D_001D8CB0 = a;
}
/* localdecomp:end func_003BB7B0 */

/* localdecomp:start func_003BB7B8 */
extern s32 D_001D8CEC;
s32 func_003BB7B8(void) {
    return D_001D8CEC;
}
/* localdecomp:end func_003BB7B8 */

/* localdecomp:start func_003BB7C0 */
extern s32 D_001D8CE8;
s32 func_003BB7C0(void) {
    return D_001D8CE8;
}
/* localdecomp:end func_003BB7C0 */

/* localdecomp:start func_003BB7C8 */
extern void func_13BC30(s32, void *, unsigned long);
extern void func_003A54F0();
extern void func_11F0A0();
void func_003BB7C8(s32 a, s32 *p) {
    s32 m;
    *p = -1;
    func_13BC30(a, func_003A54F0, (u32)p);
    m = -1;
    do {
        func_11F0A0(0);
        func_12C908(0);
        ((s32 (*)(void))func_13B620)();
    } while (*p == m);
}
/* localdecomp:end func_003BB7C8 */

/* localdecomp:start func_003BB838 */
void func_003BB838(s32 a0, long a1) {
    *(s32 *)a1 = a0;
}
/* localdecomp:end func_003BB838 */

extern s32 D_001D8CE0_003BB848;
extern s32 D_001DA1F0_003BB848[1];
extern s32 D_001DA218_003BB848[1];
extern s32 D_001DA240_003BB848[1];
extern void func_13CA20();
extern void func_13CA28();
extern void func_13B620_003BB848();
extern void func_13C0B8(s32, s32, s32, s32, s32, s32, void *, long);
/* localdecomp:start func_003BB848 */
/* from the boot_elf twin func_003BBC00 (src/boot_elf/text/3BB948.c) */
extern void func_003BB838(s32, long);
__asm__(".extern D_001DA218_003BB848, 16");
__asm__(".extern D_001DA240_003BB848, 16");
__asm__(".extern D_001DA1F0_003BB848, 16");
void func_003BB848(s32 index) {
    s32 slot;
    s32 *result;
    if (index >= 0 && index < D_001D8CE0_003BB848) {
        slot = D_001DA218_003BB848[index];
        result = &D_001DA240_003BB848[slot];
        *result = -1;
        func_13CA20();
        func_13C0B8(D_001DA1F0_003BB848[slot], 0, 1024, 0, 0, 0, func_003BB838, (long)result);
        func_13CA28();
        func_13B620_003BB848();
    }
}
/* localdecomp:end func_003BB848 */

/* localdecomp:start func_003BB8F0 */
extern int D_001D8CE0_003BB8F0;
extern int D_001DA218[];
extern int D_001DA240[];
extern void func_13C230(int, int, int);

void func_003BB8F0(float volume, int index) {
    int sound;
    register int offset __asm__("$3");
    register int *indices __asm__("$2");
    register int *sounds __asm__("$4");
    register int invalid __asm__("$5");

    if (index >= 0 && index < D_001D8CE0_003BB8F0) {
        offset = index * 4;
        __asm__ volatile("" : "+r"(offset));
        indices = D_001DA218;
        offset += (int)indices;
        __asm__ volatile("" : "+r"(offset));
        sounds = D_001DA240;
        __asm__ volatile("" : "+r"(sounds));
        sound = sounds[*(int *)offset];
        invalid = -1;
        if (sound != invalid) {
            func_13C230(sound, (int)(volume * 1024.0f), 0);
        }
    }
}
/* localdecomp:end func_003BB8F0 */

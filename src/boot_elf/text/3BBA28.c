#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003BBB68(s32);
extern s32 func_12C908(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_13B620(void);
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/boot_elf/remnants", func_003BBA28);

/* localdecomp:start func_003BBA30 */
s32 func_003BBA30(void) {
    return 0;
}
/* localdecomp:end func_003BBA30 */

/* localdecomp:start func_003BBA38 */
typedef struct { s32 f0; s32 f4; } E_3B61A0;
extern E_3B61A0 D_0037FA58[];
extern s32 D_0037FA64[];
extern char D_001D8C40[];
extern char D_001D8C48[];
extern s32 func_003823D0();
extern void func_11B2E8();
char *func_003BBA38(char *buf, s32 n) {
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
        x = func_003823D0(0xE2);
        y = func_003823D0(n > 0 ? D_0037FA58[n % 60].f4 : D_0037FA64[0]);
        func_11B2E8(buf, fmt, x, y);
    } else {
        fmt2 = D_001D8C48;
        y = func_003823D0(n > 0 ? D_0037FA58[n % 60].f4 : D_0037FA64[0]);
        func_11B2E8(buf, fmt2, y);
    }
    return buf;
}
/* localdecomp:end func_003BBA38 */

/* localdecomp:start func_003BBB68 */
extern u8 D_001D8CB0;
void func_003BBB68(s32 a) {
    D_001D8CB0 = a;
}
/* localdecomp:end func_003BBB68 */

/* localdecomp:start func_003BBB70 */
extern s32 D_001D8CEC;
s32 func_003BBB70(void) {
    return D_001D8CEC;
}
/* localdecomp:end func_003BBB70 */

/* localdecomp:start func_003BBB78 */
extern s32 D_001D8CE8;
s32 func_003BBB78(void) {
    return D_001D8CE8;
}
/* localdecomp:end func_003BBB78 */

/* localdecomp:start func_003BBB80 */
extern void func_13BC30(s32, void *, unsigned long);
extern void func_003A58F0();
extern void func_11F0A0();
void func_003BBB80(s32 a, s32 *p) {
    s32 m;
    *p = -1;
    func_13BC30(a, func_003A58F0, (u32)p);
    m = -1;
    do {
        func_11F0A0(0);
        func_12C908(0);
        ((s32 (*)(void))func_13B620)();
    } while (*p == m);
}
/* localdecomp:end func_003BBB80 */

/* localdecomp:start func_003BBBF0 */
void func_003BBBF0(s32 a0, long a1) {
    *(s32 *)a1 = a0;
}
/* localdecomp:end func_003BBBF0 */

extern s32 D_001D8CE0_003BBC00;
extern s32 D_001DA1F0_003BBC00[1];
extern s32 D_001DA218_003BBC00[1];
extern s32 D_001DA240_003BBC00[1];
extern void func_13CA20();
extern void func_13CA28();
extern void func_13B620_003BBC00();
extern void func_13C0B8(s32, s32, s32, s32, s32, s32, void *, long);
/* localdecomp:start func_003BBC00 */
__asm__(".extern D_001DA218_003BBC00, 16");
__asm__(".extern D_001DA240_003BBC00, 16");
__asm__(".extern D_001DA1F0_003BBC00, 16");
void func_003BBC00(s32 index) {
    extern void func_003BBBF0(s32,long);
    s32 slot;
    s32 *result;
    if(index>=0 && index<D_001D8CE0_003BBC00) {
        slot=D_001DA218_003BBC00[index];
        result=&D_001DA240_003BBC00[slot];
        *result=-1;
        func_13CA20();
        func_13C0B8(D_001DA1F0_003BBC00[slot],0,1024,0,0,0,func_003BBBF0,(long)result);
        func_13CA28();
        func_13B620_003BBC00();
    }
}
/* localdecomp:end func_003BBC00 */

/* localdecomp:start func_003BBCA8 */
extern int D_001D8CE0_003BBCA8;
extern int D_001DA218[];
extern int D_001DA240[];
extern void func_13C230(int, int, int);

void func_003BBCA8(float volume, int index) {
    int sound;
    register int offset __asm__("$3");
    register int *indices __asm__("$2");
    register int *sounds __asm__("$4");
    register int invalid __asm__("$5");

    if (index >= 0 && index < D_001D8CE0_003BBCA8) {
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
/* localdecomp:end func_003BBCA8 */

#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003B2A68();
extern s32 func_003B2B38(void *);
extern void func_003B2B80();
extern s32 func_003B1AB0();
typedef struct { u8 pad[0x14]; s32 w14; u8 pad2[0x28]; s32 w40; } S_ACAA8;
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B2A40 */
s32 func_003B2A40(s32 arg0) {
    func_003B23B8(arg0 + 0x48);
}
/* localdecomp:end func_003B2A40 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003B2A60);

typedef struct { char c[4]; } S4_3AD108;
typedef struct { u8 p0[0x48]; u8 p48[0x60]; s32 fA8; } S_3AD108;
extern S4_3AD108 D_001D8830[];
extern s32 D_001DA0B4_003B2A68;
extern s32 func_003B2E80();
/* localdecomp:start func_003B2A68 */
extern s32 func_003B2958(s32);
extern s32 func_003B2978(s32);
extern void func_003B2408(S_ACAA8 *);
__asm__(".extern D_001DA0B4_003B2A68, 16");

s32 func_003B2A68(u8 *a0)
{
    S4_3AD108 packet[4];
    s32 first_address, first_count, second_address, second_count;
    s32 result;
    packet[0] = D_001D8830[0];
    ((void (*)(u8 *, s32 *, s32 *, s32 *, s32 *))func_003B2958)(a0, &first_address, &first_count, &second_address, &second_count);
    if (first_count + second_count < 4) {
        return 0;
    }
    result = func_003B2E80((first_address & 0x0FFFFFFF) | 0x20000000, first_count,
                            (second_address & 0x0FFFFFFF) | 0x20000000, second_count,
                            packet, 4, 0, 0);
    ((void (*)(s32, s32))func_003B2978)(D_001DA0B4_003B2A68, result);
    func_003B2408((S_ACAA8 *)(a0 + 0x48));
    if (*(s32 *)(a0 + 0xA8) == 0) {
        *(s32 *)(a0 + 0xA8) = 2;
    }
    return 1;
}
/* localdecomp:end func_003B2A68 */

/* localdecomp:start func_003B2B38 */
extern s32 func_00135CF0(void *);
s32 func_003B2B38(void *p) {
    s32 r = 0;
    if (func_003B2A40(p) == 0) r = func_00135CF0(p) != 0;
    return r;
}
/* localdecomp:end func_003B2B38 */

extern void func_003B3010();
extern s32 D_001DA088;
extern s32 *D_001DA088_003B2B80[];
/* localdecomp:start func_003B2B80 */
extern s32 func_003B29F0();
extern s32 func_003B2BE8();
void func_003B2B80(s32 arg0) {
    volatile s32 *p;
    s32 x;
    func_003B1AB0(arg0 + 0x48);
    func_003B3010(D_001DA088);
    func_003B2BE8(arg0);
    p = (volatile s32 *)D_001DA088_003B2B80[0];
    do { x = p[3]; } while (x != 0);
    func_003B29F0(arg0, 3);
}
/* localdecomp:end func_003B2B80 */

/* localdecomp:start func_003B2BE8 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; } S_3AD288;
__asm__(".extern D_001DA088_003B2BE8, 16");
extern S_3AD288 *D_001DA088_003B2BE8;
extern u8 D_001D8850[];
extern u8 D_001D8838[];
extern s32 func_003B30A8();
extern void func_003B0140();
extern s32 func_135C10();
extern s32 func_135CE0();
extern void func_135C60();
extern void func_003B3038();
extern void func_003B0F70();
extern s32 func_003B29E8();
extern void func_11AF48();
extern s32 func_003B03F8();
s32 func_003B2BE8(s32 *a) {
    s32 ret = 1;
    s32 v, h, w, hh;
    while (func_135CE0(a) == 0) {
        if (func_003B29E8(a) == 1) {
            ret = -1;
            func_11AF48(D_001D8838);
            break;
        }
        while ((v = func_003B30A8(D_001DA088)) == 0) {
            func_003B0140();
        }
        if (func_135C10(a, v, 0x340) < 0) {
            func_003B03F8(D_001D8850);
        }
        if (a[2] == 0) {
            S_3AD288 *p;
            hh = a[0];
            w = a[1];
            h = 0;
            p = (S_3AD288 *)D_001DA088;
            if (h < p->x10) {
                do {
                    func_003B0F70(p->x4 + h * 0x27E40 + 0x40, p->x0 + h * 0xD0000, 0, hh, w);
                    func_003B0F70(D_001DA088_003B2BE8->x4 + h * 0x27E40 + 0x13F40, D_001DA088_003B2BE8->x0 + h * 0xD0000, 1, hh, w);
                    h++;
                    p = D_001DA088_003B2BE8;
                } while (h < p->x10);
            }
        }
        func_003B3038(D_001DA088);
        func_003B0140();
    }
    func_135C60(a);
    return ret;
}
/* localdecomp:end func_003B2BE8 */

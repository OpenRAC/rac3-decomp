#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u16 x0; u16 x2; u16 x4; u8 x6; u8 x7; } E_38ED00;
extern E_38ED00 *D_001D9EA4[];
extern s32 func_003963D0();


/* PAL candidate for func_003963D0 (US draft: rac3-uya-decomp func_00391B70).

   PAL differences from the US draft:
   - the retail reads D_001D9EA4 and D_001D9D00 with lui/lw, not through $gp,
     so both globals are declared as arrays (size > 8 / unknown) here;
   - the constant passed to func_00382468 is 0x19, not 0x1E;
   - the value added to its result is 8, not 10. */

/* localdecomp:start func_003963D0 */
extern s32 func_00382468(s32, s32);
typedef struct { s16 f0; u8 b2; u8 p3[9]; s32 fC; } O_391B70;
typedef struct { u16 h0; u16 h2; u16 h4; u8 b6; u8 b7; } E_391B70;
extern s32 D_001D9D00[4];
s32 func_003963D0(O_391B70 *o) {
    E_391B70 *e = (E_391B70 *)((u8 *)D_001D9EA4[0] + o->f0 * 8);
    s32 r = 0;
    if (e->h0 != 0xFFFF) {
        switch (o->b2) {
        case 0:
            r = e->h4;
            break;
        case 1:
            r = e->h4 + ((D_001D9D00[0] - o->fC) / e->b7) % e->h2;
            break;
        case 2: {
            s32 n = e->h2 * 2;
            r = ((D_001D9D00[0] - o->fC) / e->b7) % (n - 2);
            if (r >= e->h2) {
                s32 u = r + 2;
                r = n - u;
            }
            goto add;
        }
        case 3: {
            s32 t = o->fC;
            do {
                if (t < D_001D9D00[0]) {
                    s32 n;
                    r = (D_001D9D00[0] - t) / e->b7;
                    n = e->h2 * 2;
                    if (r < n - 2) {
                        if (r >= e->h2) {
                            s32 u = r + 2;
                            r = n - u;
                        }
                    add:
                        r += e->h4;
                    } else {
                        s32 k;
                        r = e->h4;
                        k = func_00382468(0x19, t) + 8;
                        o->fC = e->h2 * 2 + k;
                    }
                } else {
                    r = *(s32 *)((u8 *)o + 4);
                }
            } while (0);
        }
        }
    }
    *(s32 *)((u8 *)o + 4) = r;
    return r;
}
/* localdecomp:end func_003963D0 */

typedef struct S_391D08 {
    s32 f0;
    s32 f4;
    u8 p8[0xC];
    void (*f14)(struct S_391D08 *);
    u8 p18[0x50];
    s32 f68;
    s32 f6C;
    u8 p70[0xC];
    s32 f7C;
    u8 p80[0x10];
} S_391D08;
extern S_391D08 D_00331AE0_00396568[];
extern s32 D_001D9E8C_00396568;
extern void func_003966D8();
INCLUDE_ASM("asm/nonmatchings/text", func_00396568);

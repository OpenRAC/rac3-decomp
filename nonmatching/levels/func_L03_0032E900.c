/* near miss (level 3, Starship Phoenix): 95 differences, register allocation and loop entry: the frame (0xB0), locals and instructions line up with retail; retail keeps a=$s6, s=$s5, cnt=$s4, n=$s3, i=$s2, list pointer=$s7 and s+0x60=$fp, gcc hoists the D_001A4C60 lui into $fp and the loop gets a redundant entry b + blez; hoisted slots pointer, list pointer and declaration reorders give 102-140 */
#include "common.h"

/* localdecomp:start func_L03_0032E900 */
typedef struct { int p0; u8 *q; char rest[0x20]; } T_0032E900;
extern T_0032E900 D_L03_002AE4D0_0032E900[];
typedef struct { signed char a, b, c; } C3_0032E900;
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern u8 D_001A4C60[];
__asm__(".extern D_001A4C60, 16");
extern int func_00382498(int, int);
extern int func_L03_0032F718(void *, int, int);
extern f32 func_L01_0040E570(void *, void *);
extern int func_L03_0032F7D0(void *, void *);
extern void func_L03_0032E7E8(void *, int, int *, int *, unsigned char *);

void func_L03_0032E900(u8 *a) {
    u8 *s = *(u8 **)(a + 0x68);
    u8 *p;
    C3_0032E900 c;
    C3_0032E900 t;
    unsigned char list[8];
    char vec[16];
    int total, rem, cnt, i, n, k, idx;
    u8 *o;
    n = 0;
    i = 0;
    p = D_L03_002AE4D0_0032E900[s[0xF1]].q + s[0xF0] * 4;
    t.a = p[1]; t.b = p[2]; t.c = p[3];
    c = t;
    total = (u8)c.a + (u8)c.b + (u8)c.c;
    cnt = total / ((total + 4) / 5);
    rem = total % ((total + 4) / 5);
    if (total > 0) {
        f32 lim = 144.0f;
        do {
            idx = func_L03_0032F718(vec, func_00382498(0, 7 - i), i);
            o = D_L03_001DF99C + (*(int *)(s + 0x60 + idx * 4) << 8);
            if (lim < func_L01_0040E570(o + 0x10, D_001A4C60)) {
                if (func_L03_0032F7D0(a, o)) {
                    func_L03_0032E7E8(o, cnt, &rem, &total, (u8 *)&c);
                    i++;
                    goto next;
                }
                list[n] = idx;
                n++;
            }
            i++;
            next:;
        } while (i < 8 && total > 0);
    }
    if (n > 0 && total > 0) {
        k = 0;
        do {
            func_L03_0032E7E8(D_L03_001DF99C + (*(int *)(s + 0x60 + list[k] * 4) << 8), cnt, &rem, &total, (u8 *)&c);
            k++;
        } while (k < n && total > 0);
    }
}
/* localdecomp:end func_L03_0032E900 */

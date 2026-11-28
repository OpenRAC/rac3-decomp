/* func_L01_004BED50 (Claude wave 14 r55, 2026-11-28). First draft kept here. */
/* First draft of func_L01_004BED50 (fresh entry; worker r55, wave 14), from the retail assembly and the
 * native port's functional C. Retail is Ps2EeAs code: every float constant is li.s as lui $at/ori/mtc1,
 * and small-data scalars the compiler addresses as macros come out as lui $at forms (D_L01_001E0FD0,
 * D_L01_001DC0E8, D_L01_001DC104; D_L01_001DC0EC is $gp-relative only where reorg put it in a delay
 * slot). Under its file's GNU-as line those constants and loads cannot match, so the declarations here
 * are written for the line it needs: the existing '-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as'
 * (L01_004BEA70.c). Cut: 0x4BED50-0x4BF4D0 (start and end 8-aligned at every place: file start
 * 0x4BEC88 + 0xC8 / + 0x848); the whole file cannot take the line (tools/check.py --flags @ps2as:
 * func_L01_004BF698 14 diff, func_L01_004BF900 9 diff; the other 18 C functions MATCH).
 * Retail's nops before its four div.s: 0 2 0 0 (NEEDS divs row 'func_L01_004BED50 0 2 0 0').
 * Still differs under @ps2as: retail saves $s0 with sq in a 16-byte slot (frame 0xA0, the loop counter
 * spilled at 0x10); this C uses sd (frame 0x90) and keeps i in a register; register choice in the loop
 * (0x66CCFF rebuilt per iteration in s2 in retail, hoisted here; 0.75f/0.0f in f22/f21 in retail);
 * the double helpers (fptodp/dpcmp/dpsub/dpmul/dptoli at 0x129A18/0x1294B8/0x128F28/0x128F90/0x1295C0)
 * are the compiler's soft-double calls, which this check leaves unresolved. */
#include "common.h"

/* localdecomp:start func_L01_004BED50 */
#include "vu0.h"
typedef struct {
    s32 id;
    u8 b4;
    u8 p5[12];
    u8 b11;
    u8 b12;
    u8 b13;
} E_004BED50;
typedef struct {
    u8 p0[4];
    s32 f4;
    u8 p8[0x64];
    s32 f6C;
    u8 p70[0x10];
    s32 cur;
    u8 p84[0xBC];
    E_004BED50 e[76];
    u8 p730[0x10];
    s32 count;
} L_004BED50;
extern f32 D_L01_001E0FD0;
extern f32 D_L01_001DC0E8;
extern f32 D_L01_001DC0EC;
extern f32 D_L01_001DC104;
__asm__(".extern D_L01_001DAD9C, 4");
__asm__(".extern D_L01_001DADA0, 4");
extern s32 D_L01_001DAD9C;
extern s32 D_L01_001DADA0;
extern s32 D_00143950[];
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
extern u8 D_001425C0[];
extern S_002C5640 D_L01_002C5600[];

void func_L01_004BED50(void) {
    extern void func_003A9500(s32, s32, s32, s32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_L01_00415A58(s32, s32, s32, s32, s32, s32, s32);
    extern s32 func_00396968(s32, s32);
    extern void func_00396E50(s32, s32, s32, s32, s32, u32 *);
    extern char *func_00381FF0(s32);
    extern s32 func_L01_004127C0_004BED50(char *, f32, s32);
    extern void func_0038E150(s32);
    extern void func_0038E7E8(f32, f32, f32, f32, f32, f32, unsigned long, char *, s32, s32, s32, s32);
    u32 cols[4] __attribute__((aligned(16)));
    s32 i;
    s32 y;
    s32 idx;
    s32 v;
    s32 h;
    s32 tex;
    s32 yy;
    s32 a;
    s32 b;
    s32 kind;
    u32 mid;
    s32 w;
    s32 x;
    s32 sc;
    char *s;
    double d;
    f32 fy;
    f32 sy;
    f32 rx;

    func_003A9500(0x3A, 0x1C8, (s32)(D_L01_001E0FD0 * 299.0f + 0.5f),
                  D_00143950[0] ? (s32)(D_L01_001E0FD0 * 361.0f + 0.5f) + 4
                                : (s32)(D_L01_001E0FD0 * 361.0f + 0.5f));
    sc = ((L_004BED50 *)D_L01_002446C0)->f6C;
    if (sc < 0) {
        ((L_004BED50 *)D_L01_002446C0)->f6C = sc + 4;
    } else if (sc > 0) {
        ((L_004BED50 *)D_L01_002446C0)->f6C = sc - 4;
    }
    v = abs_asm(((((L_004BED50 *)D_L01_002446C0)->f4 << 2) & 0x3F) - 0x20);
    h = func_0038DBD8(0x331465B7, 0, 0.8f);
    v += 0x40;
    func_L01_00415A58(0xE5,
                      D_00143950[0] ? (s32)(D_L01_001E0FD0 * 304.0f + 0.5f) + 4
                                    : (s32)(D_L01_001E0FD0 * 304.0f + 0.5f),
                      0x11D,
                      D_00143950[0] ? (s32)(D_L01_001E0FD0 * 360.0f + 0.5f) + 4
                                    : (s32)(D_L01_001E0FD0 * 360.0f + 0.5f),
                      D_001D4BC0, D_001D4BC4, (v * 0x10202) | 0x80000000);
    func_L01_00415A58(0xE7,
                      D_00143950[0] ? (s32)(D_L01_001E0FD0 * 306.0f + 0.5f) + 4
                                    : (s32)(D_L01_001E0FD0 * 306.0f + 0.5f),
                      0x11B,
                      D_00143950[0] ? (s32)(D_L01_001E0FD0 * 359.0f + 0.5f) + 4
                                    : (s32)(D_L01_001E0FD0 * 359.0f + 0.5f),
                      D_001D4BC0, D_001D4BC4, h);
    y = ((L_004BED50 *)D_L01_002446C0)->f6C - 0x2C;
    for (i = -5; i < 7; i++, y += 0x38) {
        idx = ((L_004BED50 *)D_L01_002446C0)->cur + i;
        if (idx < 0 || idx >= ((L_004BED50 *)D_L01_002446C0)->count) {
            continue;
        }
        if (((L_004BED50 *)D_L01_002446C0)->e[idx].b12 != 0) {
            tex = 0xED41;
        } else if (((L_004BED50 *)D_L01_002446C0)->e[idx].b13 != 0) {
            tex = 0x755D;
        } else {
            tex = *(u16 *)((u8 *)&D_L01_002C5600[D_001425C0[((L_004BED50 *)D_L01_002446C0)->e[idx].id]] + 0x38);
        }
        tex = func_00396968(tex, 0);
        yy = y + 2;
        d = (double)(256.0f - (f32)yy);
        if (d < 0) {
            d = -d;
        }
        a = 128 - (s32)(d * 0.75);
        d = (double)(256.0f - (f32)(y + 0x28));
        if (d < 0) {
            d = -d;
        }
        b = 128 - (s32)(d * 0.75);
        if (a < 0) {
            a = 0;
        }
        if (b < 0) {
            b = 0;
        }
        a <<= 24;
        b <<= 24;
        kind = ((L_004BED50 *)D_L01_002446C0)->e[idx].b4 != 0 ? 1 : 5;
        mid = ((a + b) >> 1) & 0xFF000000;
        cols[2] = a | 0x66CCFF;
        cols[3] = b | 0x66CCFF;
        cols[0] = a | 0x66CCFF;
        cols[1] = b | 0x66CCFF;
        func_00396E50(tex, yy, (D_00143950[0] ? kind + 4 : kind) + (s32)(D_L01_001E0FD0 * 308.0f + 0.5f), 0x26,
                      (s32)(D_L01_001E0FD0 * 38.0f + 0.5f), cols);
        if (((L_004BED50 *)D_L01_002446C0)->e[idx].b11 != 0) {
            s = func_00381FF0(0x583);
            w = func_L01_004127C0_004BED50(s, 0.75f, -1);
            func_0038E150(1);
            x = y + D_L01_001DAD9C - (w >> 1);
            yy = (s32)((f32)(D_L01_001DADA0 + 0x134) * D_L01_001E0FD0 + 0.5f);
            rx = (f32)x / D_L01_001DC0E8;
            if (D_00143950[0] != 0) {
                yy += 4;
            }
            sy = D_L01_001DC0EC;
            fy = (f32)yy / sy;
            func_0038E7E8((f32)(s32)(rx * D_L01_001DC0E8), (f32)(s32)((fy - D_L01_001DC104 * 0.75f) * sy), 0.75f,
                          0.8076923f, 0.0f, 0.0f, (u32)(mid | 0x66CCFF), s, -1, 1, 0, 0x80808080);
        } else if (((L_004BED50 *)D_L01_002446C0)->e[idx].b4 == 1) {
            s = func_00381FF0(0x178);
            func_L01_004127C0_004BED50(s, 0.75f, -1);
            func_0038E150(1);
            x = y + D_L01_001DAD9C - 0xF;
            yy = (s32)((f32)(D_L01_001DADA0 + 0x134) * D_L01_001E0FD0 + 0.5f);
            rx = (f32)x / D_L01_001DC0E8;
            yy = D_00143950[0] != 0 ? yy + 2 : yy - 2;
            sy = D_L01_001DC0EC;
            fy = (f32)yy / sy;
            func_0038E7E8((f32)(s32)(rx * D_L01_001DC0E8), (f32)(s32)((fy - D_L01_001DC104 * 0.75f) * sy), 0.75f,
                          0.8076923f, 0.0f, 0.0f, (u32)(mid | 0x66CCFF), s, -1, 1, 0, 0x80808080);
        }
    }
}
/* localdecomp:end func_L01_004BED50 */

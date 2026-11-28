#include "common.h"
#include "cpu.h"

/* localdecomp:start func_L39_0057CEB0 */
typedef struct {
    u8 region;
    u8 kind;
    s16 id;
    s32 pos;
    s32 end1;
    s32 end2;
    u32 crc;
} E_0057CEB0;

typedef struct {
    s32 start;
    s32 end;
} Region_0057CEB0;

typedef struct {
    s32 w0;
    s16 n1;
    s16 n2;
    s32 total1;
    s32 total2;
    Region_0057CEB0 r1[50];
    Region_0057CEB0 r2[50];
} S_0057CEB0;

extern E_0057CEB0 D_L39_0025BB80[];
extern E_0057CEB0 D_L39_0025BCC0[];
extern u8 D_L39_0025BE00[];
extern S_0057CEB0 D_L39_00480D78;
extern u32 D_L39_004810A8[];
extern s32 D_001D6D10_sda;
extern s32 D_001D6D14_sda;
extern s32 D_001D6D1C_sda;
extern s32 D_001D6D20_sda;
extern s32 D_001D6D44_sda;
extern s32 D_001D6D48_sda;
extern s32 func_00129970(void *, s32, void *, s32, s32);

static __inline__ u32 *crc_0057CEB0(u32 *pc, u32 *p, u32 *end) {
    u32 c = *pc;

    for (; p < end; p++) {
        c ^= *p;
        c = (c >> 8) ^ D_L39_004810A8[c & 0xFF];
        c = (c >> 8) ^ D_L39_004810A8[c & 0xFF];
        c = (c >> 8) ^ D_L39_004810A8[c & 0xFF];
        c = (c >> 8) ^ D_L39_004810A8[c & 0xFF];
    }
    *pc = c;
    return p;
}

void func_L39_0057CEB0(void) {
    u8 desc[0x20];
    u32 start;
    s32 elapsed;
    s32 pos;
    s32 lim;
    s32 end;
    u32 *p;

    start = CpuGetCount();
    if (D_001D6D10_sda != D_001D6D14_sda) {
        pos = D_L39_0025BB80[D_001D6D10_sda].pos;
        lim = pos + 0x800;
        if (D_L39_0025BB80[D_001D6D10_sda].kind != 0) {
            if (D_L39_0025BB80[D_001D6D10_sda].end1 >= pos && D_L39_0025BB80[D_001D6D10_sda].end1 < lim) {
                lim = D_L39_0025BB80[D_001D6D10_sda].end1;
            }
            if (D_L39_0025BB80[D_001D6D10_sda].region != 0xFF &&
                D_L39_00480D78.r1[D_L39_0025BB80[D_001D6D10_sda].region].end < lim) {
                s32 size;

                size = D_L39_00480D78.r1[D_L39_0025BB80[D_001D6D10_sda].region].end - (pos & ~3);
                func_00129970(desc, pos & ~3, D_L39_0025BE00, (size + 3) & ~3, 0);
                crc_0057CEB0(&D_L39_0025BB80[D_001D6D10_sda].crc, (u32 *)(D_L39_0025BE00 + (D_L39_0025BB80[D_001D6D10_sda].pos & ~3)), (u32 *)(D_L39_0025BE00 + size));
                D_L39_0025BB80[D_001D6D10_sda].region = (D_L39_0025BB80[D_001D6D10_sda].region + 1) % D_L39_00480D78.n1;
                D_L39_0025BB80[D_001D6D10_sda].pos = D_L39_00480D78.r1[D_L39_0025BB80[D_001D6D10_sda].region].start;
            } else {
                s32 size;

                size = lim - (D_L39_0025BB80[D_001D6D10_sda].pos & ~3);
                func_00129970(desc, D_L39_0025BB80[D_001D6D10_sda].pos & ~3, D_L39_0025BE00, (size + 3) & ~3, 0);
                crc_0057CEB0(&D_L39_0025BB80[D_001D6D10_sda].crc, (u32 *)(D_L39_0025BE00 + (D_L39_0025BB80[D_001D6D10_sda].pos & 3)), (u32 *)(D_L39_0025BE00 + size));
                D_L39_0025BB80[D_001D6D10_sda].pos = lim;
            }
            if (D_L39_0025BB80[D_001D6D10_sda].pos == D_L39_0025BB80[D_001D6D10_sda].end1) {
                D_001D6D10_sda = (D_001D6D10_sda + 1) & 0xF;
            }
        } else {
            if (D_L39_0025BB80[D_001D6D10_sda].end2 >= pos && D_L39_0025BB80[D_001D6D10_sda].end2 < lim) {
                lim = D_L39_0025BB80[D_001D6D10_sda].end2;
            }
            if (D_L39_0025BB80[D_001D6D10_sda].region != 0xFF &&
                (end = D_L39_00480D78.r2[D_L39_0025BB80[D_001D6D10_sda].region].end) < lim) {
                crc_0057CEB0(&D_L39_0025BB80[D_001D6D10_sda].crc, (u32 *)D_L39_0025BB80[D_001D6D10_sda].pos, (u32 *)end);
                D_L39_0025BB80[D_001D6D10_sda].region = (D_L39_0025BB80[D_001D6D10_sda].region + 1) % D_L39_00480D78.n2;
                D_L39_0025BB80[D_001D6D10_sda].pos = D_L39_00480D78.r2[D_L39_0025BB80[D_001D6D10_sda].region].start;
            } else {
                p = crc_0057CEB0(&D_L39_0025BB80[D_001D6D10_sda].crc, (u32 *)D_L39_0025BB80[D_001D6D10_sda].pos, (u32 *)lim);
                D_L39_0025BB80[D_001D6D10_sda].pos = (s32)p;
            }
            if (D_L39_0025BB80[D_001D6D10_sda].pos == D_L39_0025BB80[D_001D6D10_sda].end2) {
                D_001D6D10_sda = (D_001D6D10_sda + 1) & 0xF;
            }
        }
    } else if (D_001D6D1C_sda != D_001D6D20_sda) {
        s32 pos2;
        s32 lim2;
        u32 *p2;

        pos2 = D_L39_0025BCC0[D_001D6D1C_sda].pos;
        lim2 = pos2 + 0x800;
        if (D_L39_0025BCC0[D_001D6D1C_sda].end2 < lim2) {
            lim2 = D_L39_0025BCC0[D_001D6D1C_sda].end2;
        }
        p2 = crc_0057CEB0(&D_L39_0025BCC0[D_001D6D1C_sda].crc, (u32 *)pos2, (u32 *)lim2);
        D_L39_0025BCC0[D_001D6D1C_sda].pos = (s32)p2;
        if (D_L39_0025BCC0[D_001D6D1C_sda].pos == D_L39_0025BCC0[D_001D6D1C_sda].end2) {
            D_001D6D1C_sda = (D_001D6D1C_sda + 1) & 0xF;
        }
    }
    elapsed = CpuGetCount() - start;
    D_001D6D44_sda = elapsed;
    if (D_001D6D48_sda < elapsed) {
        D_001D6D48_sda = elapsed;
    }
}
/* localdecomp:end func_L39_0057CEB0 */

LINKER_REMNANT("asm/levels", func_L39_0057D530);
